#include "htab_internal.h"

size_t	htab_size(const t_htab *htab)
{
	if (!htab)
		return (0);
	return (htab->size);
}

size_t	htab_bucket_count(const t_htab *htab)
{
	if (!htab)
		return (0);
	return (htab->bucket_count);
}

double	htab_load_factor(const t_htab *htab)
{
	if (!htab || !htab->bucket_count)
		return (0.0);
	return ((double)htab->size / (double)htab->bucket_count);
}
