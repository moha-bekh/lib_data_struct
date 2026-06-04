
DLST = ../linked_list

NAME = _graph_.c

all	:
	cc $(NAME) -I $(DLST)/inc -L $(DLST) -l _dlst_ -g3

val:
	valgrind --leak-check=full --show-leak-kinds=all ./a.out

clean:
	rm -rf *vgcore* a.out
