#include "htab_internal.h"

static void	(*g_entry_del)(void *);

static void	clear_entry_data(void *data)
{
	htab_entry_clear(data, g_entry_del);
}

void	htab_clear(t_htab **htab, void (*del)(void *))
{
	size_t	i;

	if (!htab || !*htab)
		return ;
	g_entry_del = del;
	i = 0;
	while (i < (*htab)->bucket_count)
	{
		dlst_clear(&(*htab)->buckets[i], clear_entry_data);
		i++;
	}
	free((*htab)->buckets);
	free(*htab);
	*htab = NULL;
	g_entry_del = NULL;
}
