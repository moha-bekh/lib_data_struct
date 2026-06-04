#include "htab_internal.h"

int	htab_set(t_htab *htab, const char *key, void *data, void (*del)(void *))
{
	t_htab_entry	*entry;
	t_dlst			**bucket;

	if (!htab || !key || !htab->buckets)
		return (0);
	entry = htab_find_entry(htab, key);
	if (entry)
	{
		if (del && entry->data && entry->data != data)
			del(entry->data);
		entry->data = data;
		return (1);
	}
	entry = htab_entry_new(key, data);
	if (!entry)
		return (0);
	bucket = &htab->buckets[htab_index(htab, key)];
	if (!dlst_push_back(bucket, entry))
		return (htab_entry_clear(entry, del), 0);
	htab->size++;
	return (1);
}
