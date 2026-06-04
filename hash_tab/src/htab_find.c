#include "htab_internal.h"

t_dlst_node	*htab_find_node(const t_htab *htab, const char *key)
{
	t_dlst_node		*node;
	t_htab_entry	*entry;

	if (!htab || !key || !htab->buckets)
		return (NULL);
	node = dlst_head(htab->buckets[htab_index(htab, key)]);
	while (node)
	{
		entry = dlst_data(node);
		if (entry && htab_streq(entry->key, key))
			return (node);
		node = dlst_next(node);
	}
	return (NULL);
}

t_htab_entry	*htab_find_entry(const t_htab *htab, const char *key)
{
	return (dlst_data(htab_find_node(htab, key)));
}
