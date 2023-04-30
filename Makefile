SRCS			=	main.c \
					algorithm.c \
					lst_utils.c \
					push_and_swap_functs.c \
					rotate_functs.c \
					utils_algorithm.c \

HEADER 		=	ps_wrs.h

SRCS:= $(addprefix sources/,$(SRCS))

OBJS			=	$(SRCS:.c=.o)

CC				=	@gcc
RM				=	@rm -f
CFLAGS			=	-Werror -Wextra -Wall

NAME			=	push_swap

all:			$(NAME) say_hi
				@mv sources/*.o objs/

$(NAME):		${OBJS}
				${CC} ${CFLAGS} $(HEADER) ${OBJS} -o ${NAME}

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)
				
say_hi:
				@echo "\n 	Hi ! Push_swap is ready to be launched. \
				\n\n\n			----- Have fun ! ----- \n\nCommands : make + test100, test500\n							by William Ruet Suquet"

test100:
				@./.testeur_push_swap/tester.sh . 100 10
test500:
				@./.testeur_push_swap/tester.sh . 500 10

re:				fclean all

.PHONY:			all clean fclean re test100 test500 say_hi
