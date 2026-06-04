#include "htab_internal.h"

void	*htab_get(const t_htab *htab, const char *key)
{
	t_htab_entry	*entry;

	entry = htab_find_entry(htab, key);
	if (!entry)
		return (NULL);
	return (entry->data);
}
