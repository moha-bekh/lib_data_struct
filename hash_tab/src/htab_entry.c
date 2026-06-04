#include "htab_internal.h"

t_htab_entry	*htab_entry_new(const char *key, void *data)
{
	t_htab_entry	*entry;

	if (!key)
		return (NULL);
	entry = malloc(sizeof(t_htab_entry));
	if (!entry)
		return (NULL);
	*entry = (t_htab_entry){0};
	entry->key = htab_strdup(key);
	if (!entry->key)
		return (free(entry), NULL);
	entry->data = data;
	return (entry);
}

void	htab_entry_clear(t_htab_entry *entry, void (*del)(void *))
{
	if (!entry)
		return ;
	free(entry->key);
	if (del && entry->data)
		del(entry->data);
	free(entry);
}
