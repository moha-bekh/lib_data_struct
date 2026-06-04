#ifndef HTAB_INTERNAL_H
# define HTAB_INTERNAL_H

# include "dlst.h"
# include "htab.h"
# include <stdlib.h>

typedef struct s_htab_entry
{
	char	*key;
	void	*data;
}	t_htab_entry;

struct s_htab
{
	t_dlst	**buckets;
	size_t	size;
	size_t	bucket_count;
};

t_htab_entry	*htab_entry_new(const char *key, void *data);
void			htab_entry_clear(t_htab_entry *entry, void (*del)(void *));
char			*htab_strdup(const char *src);
int				htab_streq(const char *a, const char *b);
size_t			htab_index(const t_htab *htab, const char *key);
t_htab_entry	*htab_find_entry(const t_htab *htab, const char *key);
t_dlst_node		*htab_find_node(const t_htab *htab, const char *key);

#endif
