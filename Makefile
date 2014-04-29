#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sconso <sconso@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/12 18:13:08 by sconso            #+#    #+#              #
#    Updated: 2014/01/12 23:32:16 by sconso           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ft_select

CC = gcc
CFLAGS = -Wall -Werror -Wextra
DFLAGS = -pedantic -ansi -g -ggdb
INC = -I includes/ -I libft/includes/
LFLAGS = -L libft/ -lft -ltermcap

FILES = ft_printthings.c ft_dlist.c ft_clear.c ft_print.c ft_afflist.c \
		ft_move.c ft_utilities.c ft_search.c ft_keys.c ft_errors.c \
		ft_signal.c ft_termoption.c ft_maths.c ft_select.c ft_main.c \
		ft_skins.c ft_skinsinit.c

SRCDIR = src
OBJDIR = obj

SRC = $(addprefix $(SRCDIR)/, $(FILES))
OBJ = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))

all : $(NAME)

$(NAME) : libft $(OBJDIR) $(OBJ)
		@make -C libft/ all
		@$(CC) $(CFLAGS) $(INC) -o $@ $(OBJ) $(LFLAGS)
		@echo "\033[4;32m$@\033[0m created !"

$(OBJDIR) :
		@/bin/mkdir $(OBJDIR);			\
		for DIR in $(SRCDIR);			\
		do								\
			/bin/mkdir $(OBJDIR)/$$DIR;	\
		done							\

$(addprefix $(OBJDIR)/, %.o) : %.c
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<
	@/bin/echo -n "Creating objects in $(addprefix $(OBJDIR)/, $(SRCDIR)) : "
	@echo "\033[1;33m$(subst $(SRCDIR)/, , $(<:.c=.o))\033[0m"

run : re
		@/usr/bin/clear
		@./$(NAME)

clean :
		@/bin/rm -rf $(OBJDIR) a.out.dSYM
		@/bin/rm -f a.out
		@echo "\033[1;30m$(OBJDIR)\033[0m removed !"

fclean : clean
		@/bin/rm -f $(NAME)
		@echo "\033[1;30m$(NAME)\033[0m removed !"

libft :
		@make -C libft all

libfclean :
		@make -C libft fclean

libre :
		@make -C libft re
		@make re

re : fclean all

debug : CFLAGS += $(DFLAGS)
debug : re

.SILENT :
.PHONY : all clean fclean re
