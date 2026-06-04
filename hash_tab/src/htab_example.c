#include "htab.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct s_entity
{
	int	x;
}	t_entity;

static t_entity	*entity_new(int x)
{
	t_entity	*entity;

	entity = malloc(sizeof(t_entity));
	if (!entity)
		return (NULL);
	entity->x = x;
	return (entity);
}

static void	entity_clear(void *data)
{
	free(data);
}

int	main(void)
{
	t_htab		*htab;
	t_entity	*entity;

	htab = htab_new(16);
	if (!htab)
		return (1);
	htab_set(htab, "value", entity_new(10), entity_clear);
	htab_set(htab, "other", entity_new(42), entity_clear);
	entity = htab_get(htab, "value");
	if (entity)
		printf("value: %d\n", entity->x);
	printf("size: %zu, load: %.2f\n", htab_size(htab),
		htab_load_factor(htab));
	htab_clear(&htab, entity_clear);
	return (0);
}
