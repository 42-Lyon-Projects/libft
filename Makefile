# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbadaire <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/17 17:54:42 by jbadaire          #+#    #+#              #
#    Updated: 2023/01/17 17:54:46 by jbadaire         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME    = libft.a
RM  	= rm -rf
CC 		= cc
FLAGS   = -Wall -Wextra -Werror -g
OBJ_DIRECTORY = ./.obj/
BONUS_DIRECTORY = ./.bonus/
INCLUDE = libft.h

SRCS =             \
	ft_bzero.c     \
	ft_isalnum.c   \
	ft_isalpha.c   \
	ft_isascii.c   \
	ft_isdigit.c   \
	ft_isprint.c   \
	ft_memset.c	   \
	ft_strlen.c	   \
	ft_strlcat.c   \
	ft_tolower.c   \
	ft_toupper.c   \
	ft_strrchr.c   \
	ft_strchr.c    \
	ft_strncmp.c   \
	ft_memchr.c    \
	ft_memcmp.c    \
	ft_strnstr.c   \
	ft_atoi.c	   \
	ft_calloc.c    \
	ft_strdup.c    \
	ft_memcpy.c    \
	ft_memmove.c   \
	ft_strlcpy.c   \
	ft_substr.c    \
	ft_strjoin.c   \
	ft_strtrim.c   \
	ft_split.c     \
	ft_itoa.c      \
	ft_putchar_fd.c\
	ft_putstr_fd.c \
	ft_putendl_fd.c\
	ft_striteri.c\
	ft_strmapi.c\
	ft_putnbr_fd.c

SRCS_BONUS =         \
	ft_lstnew.c      \
	ft_lstadd_front.c\
	ft_lstsize.c     \
	ft_lstlast.c     \
	ft_lstadd_back.c \
	ft_lstdelone.c   \
	ft_lstclear.c    \
	ft_lstiter.c     \
#	ft_lstmap.c

all:        $(NAME)

so: $(all)

OBJS = $(addprefix $(OBJ_DIRECTORY), $(SRCS:.c=.o))

$(NAME): $(OBJ_DIRECTORY) $(OBJS) $(INCLUDE)
	ar -rcs $(NAME) $(OBJS)

$(OBJ_DIRECTORY)%.o:%.c $(INCLUDE)
	$(CC) $(FLAGS) -I. -c $< -o $@

$(OBJ_DIRECTORY):
	mkdir -p $(OBJ_DIRECTORY)

BONUS = $(addprefix $(BONUS_DIRECTORY), $(SRCS_BONUS:.c=.o))

bonus: $(BONUS_DIRECTORY) $(BONUS) $(INCLUDE)
	ar -rcs $(NAME) $(BONUS)

$(BONUS_DIRECTORY)%.o:%.c $(INCLUDE)
	$(CC) $(FLAGS) -I. -c $< -o $@

$(BONUS_DIRECTORY):
	mkdir -p $(BONUS_DIRECTORY)

clean:
	$(RM) $(OBJ_DIRECTORY)

fclean: clean
	$(RM) $(NAME) *.out *.gch *.o .bonus .so

re:	fclean $(NAME)

.PHONY: fclean clean all re
