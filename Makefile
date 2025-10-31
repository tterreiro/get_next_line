# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hde-andr <hde-andr@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/13 13:17:36 by hde-andr          #+#    #+#              #
#    Updated: 2025/10/30 17:35:49 by hde-andr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line

BONUS = 

SRCS = get_next_line.c get_next_line_utils.c

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS:.c=.o)

%.o: %.c
	cc -Wall -Wextra -Werror -D BUFFER_SIZE=n -I. -c $< -o  $@

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

bonus: .bonus

.bonus : $(OBJS) $(BONUS_OBJS)
	ar rc $(NAME) $(OBJS) $(BONUS_OBJS)
	@touch .bonus

clean:
	rm -f $(OBJS) $(BONUS_OBJS) .bonus

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
