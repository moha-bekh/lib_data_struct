#include "_dlst_.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

typedef struct s_token
{
    char *value;
    char typ;
    bool flg;

} t_token;

void _print_token(t_token *token)
{
    if (!token)
        return ;
    printf("typ: %c \tflg: %d \tvalue: %s\n", token->typ, token->flg, token->value);
    return ;
}

t_token *_set_token(char *value, char typ, bool flg)
{
    t_token *node;

    node = malloc(sizeof(t_token));
    if (!node)
        return (printf("token alloc failed\n"), NULL);
    *node = (t_token){0};
    if (value)
        node->value = strdup(value);
    node->typ = typ;
    node->flg = flg;
    return (node);
}

void *_clear_token(t_token *token)
{
    if (!token)
        return NULL;
    free(token->value);
    token->value = NULL;
    free(token);
    return (NULL);
}

int main(void)
{
    t_dlst *dlst = NULL;

    dlst = _dlst_push_front(dlst, _set_token("'world!'", '\'', false));
    dlst = _dlst_push_back(dlst, _set_token(">", '>', true));
    dlst = _dlst_push_front(dlst, _set_token("\"hello\"", '"', false));
    dlst = _dlst_push_back(dlst, _set_token("out", 'S', true));
    dlst = _dlst_push_front(dlst, _set_token("echo", 'S', false));
    dlst = _dlst_push_back(dlst, _set_token(";", ';', true));
    dlst = _dlst_insert_next(dlst, dlst->top, _set_token("-n", 'S', true));
    dlst = _dlst_insert_prev(dlst, dlst->bot, _set_token("&&", '&', false));
    dlst = _dlst_insert_prev(dlst, dlst->bot, _set_token("ls", 'S', false));

    _dlst_print(dlst, (void *)_print_token);
    dlst = _dlst_del(dlst, dlst->top->next, (void *)_clear_token);
    printf("\n\n");
    _dlst_print(dlst, (void *)_print_token);

    dlst = _dlst_clear(dlst, (void *)_clear_token);

    return (0);
}
