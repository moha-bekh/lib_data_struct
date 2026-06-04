#include "htab_internal.h"

char	*htab_strdup(const char *src)
{
	char	*copy;
	size_t	i;

	if (!src)
		return (NULL);
	i = 0;
	while (src[i])
		i++;
	copy = malloc(sizeof(char) * (i + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (src[i])
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

int	htab_streq(const char *a, const char *b)
{
	size_t	i;

	if (!a || !b)
		return (0);
	i = 0;
	while (a[i] && b[i] && a[i] == b[i])
		i++;
	return (a[i] == b[i]);
}
