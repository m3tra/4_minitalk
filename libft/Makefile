# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fporto <fporto@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/26 13:26:30 by fporto            #+#    #+#              #
#    Updated: 2021/09/07 19:22:49 by fporto           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
HEAD = libft.h
NAME = libft.a
RM = rm -f
AR = ar rcs

SRCS =	ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isblank.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_islower.c \
		ft_isspace.c \
		ft_isupper.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memset.c \
		ft_memmove.c \
		ft_strncmp.c \
		ft_strlcat.c \
		ft_strnstr.c \
		ft_strlcpy.c \
		ft_strrchr.c \
		ft_strchr.c \
		ft_strlen.c \
		ft_strdup.c \
		ft_toupper.c \
		ft_tolower.c \
		\
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_uitoa.c \
		ft_strmapi.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		\
		ft_abs.c \
		ft_strcat_char.c \
		ft_char_to_str.c \
		ft_isstrdigit.c

BONUS = ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c

OBJS := $(subst .c,.o,${SRCS})
OBJS_BONUS := $(subst .c,.o,${BONUS})

.c.o : $(HEAD)
	$(CC) $(CFLAGS) -I. -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

all:	bonus

bonus: $(OBJS) $(OBJS_BONUS)
	$(AR) $(NAME) $(OBJS) $(OBJS_BONUS)

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME)

re:		fclean all

.PHONY: clean fclean re all bonus
