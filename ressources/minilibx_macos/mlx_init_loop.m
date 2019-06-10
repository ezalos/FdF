//  mlx_init_loop.m
// By Ol

#import <Cocoa/Cocoa.h>
#import <OpenGL/gl3.h>
#import <AppKit/NSOpenGLView.h>

#include "mlx_int.h"
#include "mlx_new_mlx.h"

#include "font.c"


void	do_loop_hook2(CFRunLoopTimerRef observer, void * info)
{
  ((mlx__t *)info)->loop_hook(((mlx__t *)info)->loop_hook_data);
}


void do_loop_flush(CFRunLoopObserverRef observer, CFRunLoopActivity activity, void * info)
{
  mlx__t	*mlx_;
  mlx_win_list_t *win;

  mlx_ = (mlx__t *)info;
  win = mlx_->win_list;
  while (win)
    {
      if (win->nb_flush > 0 && win->pixmgt)
	{
	  [(id)win->winid selectGLContext];
	  [(id)win->winid mlx_gl_draw];
	  glFlush();
	  win->nb_flush = 0;
	}
      win = win->next;
    }
}




void *mlx_init()
{
  mlx__t	*new_mlx;
  int		bidon;
  int		i;

  if ((new_mlx = malloc(sizeof(*new_mlx))) == NULL)
    return ((void *)0);
  new_mlx->win_list = NULL;
  new_mlx->img_list = NULL;
  new_mlx->loop_hook = NULL;
  new_mlx->loop_hook_data = NULL;
  new_mlx->main_loop_active = 0;

  new_mlx->appid = [NSApplication sharedApplication];

  // super magic trick to detach app from terminal, get menubar & key input events
  for (NSRunningApplication * app in [NSRunningApplication runningApplicationsWithBundleIdentifier:@"com.apple.finder"])
    {
      [app activateWithOptions:NSApplicationActivateIgnoringOtherApps];
      break;
    }
  usleep(100000);
  ProcessSerialNumber psn = { 0, kCurrentProcess };
  (void) TransformProcessType(&psn, kProcessTransformToForegroundApplication);
  usleep(100000);
  [[NSRunningApplication currentApplication] activateWithOptions:NSApplicationActivateIgnoringOtherApps];

  // load font
  new_mlx->font = mlx_new_image(new_mlx, (FONT_WIDTH+2)*95, FONT_HEIGHT);
  i = 0;
  while (i < 4*(FONT_WIDTH+2)*95*FONT_HEIGHT)
    {
      new_mlx->font->buffer[i+0] = font_atlas.pixel_data[i+2];
      new_mlx->font->buffer[i+1] = font_atlas.pixel_data[i+1];
      new_mlx->font->buffer[i+2] = font_atlas.pixel_data[i+0];
      ((unsigned char *)new_mlx->font->buffer)[i+3] = 0xFF-font_atlas.pixel_data[i+3];
      i += 4;
    }

  new_mlx->font->vertexes[2] = FONT_WIDTH;
  new_mlx->font->vertexes[4] = FONT_WIDTH;
  new_mlx->font->vertexes[5] = -FONT_HEIGHT-1;
  new_mlx->font->vertexes[7] = -FONT_HEIGHT-1;

  return ((void *)new_mlx);
}


void mlx_loop(mlx__t *mlx_)
{
  CFRunLoopObserverRef observer;
  CFRunLoopObserverContext ocontext = {.version = 0, .info = mlx_, .retain = NULL, .release = NULL, .copyDescription = NULL};

  mlx_->main_loop_active = 1;

  observer = CFRunLoopObserverCreate(NULL, kCFRunLoopBeforeTimers, true, 0, do_loop_flush, &ocontext);
  CFRunLoopAddObserver(CFRunLoopGetMain(), observer, kCFRunLoopCommonModes);

  //  [[[MlxLoopHookObj alloc] initWith:mlx_] performSelector:@selector(do_loop_hook) withObject:nil afterDelay:0.0];

  [NSApp run];
}


void mlx_pixel_put(mlx__t *mlx_, mlx_win_list_t *win_, int x, int y, int color)
{
  if (!win_->pixmgt)
    return ;
  [(id)(win_->winid) selectGLContext];
  [(id)(win_->winid) pixelPutColor:color X:x Y:y];
  win_->nb_flush ++;
}


void	mlx_int_loop_once()
{
  NSEvent *event;
  NSDate  *thedate;

  thedate = [NSDate dateWithTimeIntervalSinceNow:0.1];
  while (42)
    {
      event = [NSApp nextEventMatchingMask:NSEventMaskAny
		     untilDate:thedate
		     inMode:NSDefaultRunLoopMode
		     dequeue:YES];
      if (event == nil)
	{
	  [thedate release];
	  return ;
	}
      [NSApp sendEvent:event];
      [NSApp updateWindows];
    }
}


int     mlx_do_sync(mlx__t *mlx_)
{
  mlx_win_list_t *win;

  win = mlx_->win_list;
  while (win)
    {
      if (win->pixmgt)
	{
	  [(id)(win->winid) selectGLContext];
	  [(id)(win->winid) mlx_gl_draw];
	  glFlush();
	  if (!mlx_->main_loop_active)
	    mlx_int_loop_once();
	}
      win = win->next;
    }
  return (0);
}


int mlx_loop_hook(mlx__t *mlx_, void (*fct)(void *), void *param)
{
  CFRunLoopTimerContext	tcontext = {0, mlx_, NULL, NULL, NULL};
  CFRunLoopTimerRef	timer;

  if (mlx_->loop_hook != NULL)
    {
      CFRunLoopTimerInvalidate(mlx_->loop_timer);
      [(id)(mlx_->loop_timer) release];
    }

  mlx_->loop_hook = fct;
  mlx_->loop_hook_data = param;

  if (fct)
    {
      timer = CFRunLoopTimerCreate(kCFAllocatorDefault, 0.0, 0.0001, 0, 0, &do_loop_hook2, &tcontext);
      mlx_->loop_timer = timer;
      CFRunLoopAddTimer(CFRunLoopGetMain(), timer, kCFRunLoopCommonModes);
    }

  return (0);
}
