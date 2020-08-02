
#include "head.h"

void	set_up_palettes(t_color *colors)
{
	colors->size_gradient = 0;
	colors->gradient = NULL;
	colors->louis_grad[0] = palette_dracula();
	colors->louis_grad[1] = palette_sunrise();
	colors->louis_grad[2] = palette_skyline();
	colors->dracula = palette_dracula();
	colors->sunrise = palette_sunrise();
	colors->skyline = palette_skyline();
	colors->gradient = ft_join_gradient(colors->gradient,\
		colors->dracula, colors->size_gradient, LEN_GRAD);
	colors->size_gradient += LEN_GRAD;
	colors->gradient = ft_join_gradient(colors->gradient,\
		colors->sunrise, colors->size_gradient, LEN_GRAD);
	colors->size_gradient += LEN_GRAD;
	colors->gradient = ft_join_gradient(colors->gradient,\
		colors->skyline, colors->size_gradient, LEN_GRAD);
	colors->size_gradient += LEN_GRAD;
}
