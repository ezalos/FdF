# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    init.mk                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/12 15:04:16 by ldevelle          #+#    #+#              #
#    Updated: 2020/06/15 18:19:47 by deyaberge        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#It will be the name of your executable
NAME 					=	FdF

TESTEUR					=	test

#Change to 'y' if this project needs to be a library
LIB_PRJCT 				=	n

#These are your basic compilation flags
CFLAGS					=	-Wall -Wextra -Werror\

#USERNAME used for the auteur file
login 					=	ldevelle

DIR_OBJ 				=	./objs/

##########################
##						##
##		 GITHUB			##
##						##
##########################
#Allow to automatically make the first push to the project
github_username			=	ezalos
github_project			=	$(NAME)
GIT_REPO				=	https://github.com/$(github_username)/$(github_project).git
#Do you wish to have to confirm your push in 'make git' ?
GIT_VALID				=	false


##########################
##						##
##		LIBRAIRIES		##
##						##
##########################

LIB_DIR					=	./libft
LIB						=	$(LIB_DIR)/libft.a -lm
LIB						+=	-L /usr/local/lib

##########################
##						##
##		INCLUDES		##
##						##
##########################

HEAD_DIR 				= 	./includes/
HEADERS					=	$(AUTO_HEAD)\
							head.h

HEADERS_DIRECTORIES 	=	-I./$(HEAD_DIR)\
							-I./$(LIB_DIR)/includes\
							-I /usr/local/include/\

UNAME			:=	$(shell uname)

ifeq ($(UNAME),Linux)
HEADERS_DIRECTORIES +=		-lmlx -lGL -lm -lbsd -lX11 -lXext
else
LIB +=						-lmlx -framework OpenGL -framework AppKit
endif

# HEAD_PATH	=	$(HEAD_DIR)/$(HEAD)
