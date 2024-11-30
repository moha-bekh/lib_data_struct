#include "_dlst_.h"

t_dlst *_dlst_insert_prev(t_dlst *dlst, t_dlst_node *node, void *ptr)
{
    t_dlst_node *new;

    new = _dlst_new_node();
    if (!new)
        return (dlst);
    if (!dlst)
    {
        dlst = _dlst_new();
        if (!dlst)
            return (free(new), dlst);
        dlst->top = new;
        dlst->bot = new;
    }
    else
    {
        new->next = node;
        new->prev = node->prev;
        if (node->prev)
            node->prev->next = new;
        node->prev = new;
    }
    new->mgr = dlst;
    new->ptr = ptr;
    dlst->len++;
    return (dlst);
}
