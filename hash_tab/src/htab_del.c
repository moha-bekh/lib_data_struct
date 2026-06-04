#include "htab_internal.h"

static void	(*g_entry_del)(void *);

static void	clear_entry_data(void *data)
{
	htab_entry_clear(data, g_entry_del);
}

int	htab_del(t_htab *htab, const char *key, void (*del)(void *))
{
	t_dlst_node	*node;
	t_dlst		**bucket;

	if (!htab || !key || !htab->buckets)
		return (0);
	node = htab_find_node(htab, key);
	if (!node)
		return (0);
	g_entry_del = del;
	bucket = &htab->buckets[htab_index(htab, key)];
	if (!dlst_del(bucket, node, clear_entry_data))
		return (g_entry_del = NULL, 0);
	htab->size--;
	g_entry_del = NULL;
	return (1);
}
