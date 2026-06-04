NAME	=	test_htab

CC		=	cc
HTAB_DIR	=	..
DLST_DIR	=	../../linked_list
INC		=	-I $(HTAB_DIR)/inc -I $(DLST_DIR)/inc
ERR_FLG	=	-Wall -Wextra -Werror -g3

all		:	run

$(NAME)	:	test_htab.c
			$(MAKE) -C $(HTAB_DIR)
			$(CC) $(ERR_FLG) $(INC) test_htab.c $(HTAB_DIR)/libhtab.a \
				$(DLST_DIR)/libdlst.a -o $(NAME)

run		:	$(NAME)
			./$(NAME)

clean	:
			rm -f $(NAME)

fclean	:	clean

re		:	fclean all

.PHONY	:	all run clean fclean re
