#include "htab_internal.h"

unsigned long	htab_hash(const char *key)
{
	unsigned long	hash;
	unsigned char	c;

	if (!key)
		return (0);
	hash = 14695981039346656037UL;
	while (*key)
	{
		c = (unsigned char)*key;
		hash ^= c;
		hash *= 1099511628211UL;
		key++;
	}
	return (hash);
}

size_t	htab_index(const t_htab *htab, const char *key)
{
	if (!htab || !htab->bucket_count)
		return (0);
	return (htab_hash(key) % htab->bucket_count);
}
