# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trusanov <trusanov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/08 09:59:45 by trusanov          #+#    #+#              #
#    Updated: 2023/10/26 14:23:24 by trusanov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror
SOURCES := \
		ft_isascii.c \
		ft_memcpy.c \
		ft_putstr_fd.c \
		ft_strlcat.c \
		ft_strrchr.c \
		ft_atoi.c \
		ft_isdigit.c \
		ft_memmove.c \
		ft_split.c \
		ft_strlcpy.c \
		ft_strtrim.c \
		ft_bzero.c \
		ft_isprint.c \
		ft_memset.c \
		ft_strchr.c \
		ft_strlen.c \
		ft_substr.c \
		ft_calloc.c \
		ft_itoa.c \
		ft_putchar_fd.c \
		ft_strdup.c \
		ft_strmapi.c \
		ft_tolower.c \
		ft_isalnum.c \
		ft_memchr.c \
		ft_putendl_fd.c \
		ft_striteri.c \
		ft_strncmp.c \
		ft_toupper.c \
		ft_isalpha.c \
		ft_memcmp.c \
		ft_putnbr_fd.c \
		ft_strjoin.c \
		ft_strnstr.c \
		ft_printf.c \
		put_dec.c \
		put_ptr.c \
		put_str.c

BONUS_SRC := \
		ft_lstadd_back_bonus.c \
		ft_lstclear_bonus.c \
		ft_lstiter_bonus.c \
		ft_lstmap_bonus.c \
		ft_lstsize_bonus.c \
		ft_lstadd_front_bonus.c \
		ft_lstdelone_bonus.c \
		ft_lstlast_bonus.c \
		ft_lstnew_bonus.c

OBJECTS = $(SOURCES:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)
NAME = libft.a

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rc $(NAME) $(OBJECTS)

bonus: all $(BONUS_OBJ)
	ar r $(NAME) $(BONUS_OBJ)

clean:
	rm -f $(OBJECTS) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
