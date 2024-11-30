#include "_dlst_.h"

void _dlst_print(t_dlst *dlst, void (*f)(void *))
{
    t_dlst_node *tmp;

    if (!dlst || !f)
        return ;
    tmp = dlst->top;
    while (tmp)
    {
        f(tmp->ptr);
        tmp = tmp->next;
    }
}
