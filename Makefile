# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgritsen <pgritsen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/25 13:16:39 by pgritsen          #+#    #+#              #
#    Updated: 2017/11/25 13:23:28 by pgritsen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	gcc

CFLAGS	=	-Wextra -Werror -Wall

NAME	=	gnl

SRC		=	get_next_line.c test.c

OBJDIR	=	obj

OBJ		=	$(addprefix $(OBJDIR)/, $(SRC:.c=.o))

LIBDIR	=	libft

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJ)
	@make -C $(LIBDIR)
	$(CC) $(CFLAGS) $(SRC) -L $(LIBDIR) -lft -o $(NAME)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(OBJ): $(OBJDIR)/%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make -C $(LIBDIR) clean
	rm -rf $(OBJDIR)

fclean: clean
	@make -C $(LIBDIR) fclean
	rm -rf $(NAME)

re:	fclean all
