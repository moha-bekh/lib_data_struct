#include "htab_internal.h"

t_htab	*htab_new(size_t bucket_count)
{
	t_htab	*htab;
	size_t	i;

	if (!bucket_count)
		return (NULL);
	htab = malloc(sizeof(t_htab));
	if (!htab)
		return (NULL);
	*htab = (t_htab){0};
	htab->buckets = malloc(sizeof(t_dlst *) * bucket_count);
	if (!htab->buckets)
		return (free(htab), NULL);
	i = 0;
	while (i < bucket_count)
		htab->buckets[i++] = NULL;
	htab->bucket_count = bucket_count;
	return (htab);
}
