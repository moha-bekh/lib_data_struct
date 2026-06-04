#ifndef HTAB_H
# define HTAB_H

# include <stddef.h>

typedef struct s_htab	t_htab;

t_htab		*htab_new(size_t bucket_count);
void		htab_clear(t_htab **htab, void (*del)(void *));

int			htab_set(t_htab *htab, const char *key, void *data,
				void (*del)(void *));
void		*htab_get(const t_htab *htab, const char *key);
int			htab_del(t_htab *htab, const char *key, void (*del)(void *));

size_t		htab_size(const t_htab *htab);
size_t		htab_bucket_count(const t_htab *htab);
double		htab_load_factor(const t_htab *htab);
unsigned long	htab_hash(const char *key);

#endif
