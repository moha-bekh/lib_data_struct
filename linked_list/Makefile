CC		=	cc
FLAGS	=	-Wall -Wextra -Werror -g3

SRC		:=	_dlst_.c\
			_dlst_clear.c\
			_dlst_del.c\
			_dlst_new_node.c\
			_dlst_new.c\
			_dlst_insert_next.c\
			_dlst_insert_prev.c\
			_dlst_pop_front.c\
			_dlst_pop_back.c\
			_dlst_print.c\
			_dlst_push_back.c\
			_dlst_push_front.c\

OBJ		:=	$(SRC:.c=.o)

NAME	=	dlst

all		: $(NAME)

$(NAME)	:	$(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o		:	%.c
	$(CC) $(FLAGS) -c $< -o $@

clean	:
			rm -f $(OBJ)

fclean	: 	clean
			rm -f $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re
