# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile_B                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyunjiki <hyunjiki@student.42gyeongsa      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/28 06:10:41 by hyunjiki          #+#    #+#              #
#    Updated: 2024/04/28 06:15:26 by hyunjiki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Makefile

// 생성할 라이브러리명
NAME	=	libftprintf.a
// 컴파일
CC		=	cc
// 컴파일 플래그
CFLAGS	=	-Wall -Wextra -Werror
// 컴파일할 대상 파일
SRC		=	ft_printf.c ft_putchar.c ft_putstr.c ft_puthex.c ft_putpointer.c ft_itoa.c ft_uitoa.c
// .c 파일을 사용하여 .o 파일 생성
OBJS	=	$(SRC:.c=.o)
// 
all		:	$(NAME)

$(NAME)	: 	$(OBJS)
		ar -rc $(NAME) $(OBJS)

$(OBJS)	:	$(SRC)
		$(CC) $(CFLAGS) -c $(SRC)

clean:
	rm -f $(OBJS)

fclean:		clean
	rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
