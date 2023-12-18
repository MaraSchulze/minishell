# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbock <fbock@student.42heilbronn.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/18 08:57:25 by fbock             #+#    #+#              #
#    Updated: 2023/12/18 17:32:04 by fbock            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= minishell

CC 		:= cc
# CFLAGS 	:= -Wall -Wextra -Werror
DFLAGS 	:= -g3
DNAME 	:= minishell_debug
HEADERS = -I./includes -I ./libs/libft/includes


SRCDIR		:= src
OBJDIR		:= objs
LIBFT 		:= libs/libft/libft.a
LIBFT_DEBUG := libs/libft/libft_debug.a

SRCS 	:= $(SRCDIR)/minishell.c \
$(SRCDIR)/input_handling/input_utils.c \
$(SRCDIR)/parsing/parsing_main.c \
$(SRCDIR)/builtins/cd.c $(SRCDIR)/builtins/echo.c $(SRCDIR)/builtins/export.c $(SRCDIR)/builtins/pwd.c

OBJS	:= $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRCS))
DOBJS   := $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.d.o,$(SRCS))
$(shell mkdir -p $(OBJDIR) $(OBJDIR)/input_handling $(OBJDIR)/parsing $(OBJDIR)/builtins)

all: $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

$(OBJDIR)/%.d.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) $(DFLAGS) $(HEADERS) -c $< -o $@

$(NAME): $(OBJS)
	make -C libs/libft
	$(CC) $(CFLAGS) $(LIBFT) $(HEADERS) $(OBJS) -o $(NAME)

debug: $(DOBJS)
	make -C libs/libft debug
	$(CC) $(CFLAGS) $(DFLAGS) $(LIBFT_DEBUG) $(HEADERS) $(DOBJS) -o $(DNAME)

clean:
	make -C libs/libft clean
	rm -rf $(OBJDIR)

fclean: clean
	make -C libs/libft fclean
	rm -rf $(NAME) $(DNAME)

re: fclean all

.PHONY: all, clean, fclean, re, debug
