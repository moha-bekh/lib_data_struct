NAME	=	libhtab.a

CC		=	cc
DLST_DIR	=	../linked_list
INC		=	-I inc -I $(DLST_DIR)/inc
ERR_FLG	=	-Wall -Wextra -Werror -g3
DEP_FLG	=	-MMD -MP
AR		=	ar -crs

SRC_DIR	:=	src/
OBJ_DIR	:=	obj/

SRC_FLS	:=	\
			htab_clear\
			htab_del\
			htab_entry\
			htab_find\
			htab_get\
			htab_getters\
			htab_hash\
			htab_new\
			htab_set\
			htab_utils\

SRC		:=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FLS)))
OBJ		:=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FLS)))
DEP		:=	$(patsubst %.o, %.d, $(OBJ))

all		:	$(NAME)

$(NAME)	:	$(OBJ)
			$(MAKE) -C $(DLST_DIR)
			$(AR) $@ $^

$(OBJ_DIR)%.o	:	$(SRC_DIR)%.c | obj_dir
			$(CC) $(ERR_FLG) $(INC) $(DEP_FLG) -c $< -o $@

obj_dir	:
			mkdir -p $(OBJ_DIR)

example	:	$(NAME)
			$(CC) $(ERR_FLG) $(INC) src/htab_example.c $(NAME) \
				$(DLST_DIR)/libdlst.a -o htab_example
			./htab_example

clean	:
			rm -rf $(OBJ_DIR) htab_example htab_example.dSYM

fclean	:	clean
			rm -f $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re example

-include $(DEP)
