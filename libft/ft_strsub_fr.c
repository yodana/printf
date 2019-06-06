#include "libft.h"

char	*ft_strsub_fr(char const *s, unsigned int start, size_t len)
{
	char	*new;

	new = ft_strsub(s, start, len);
    ft_strdel((char**)&s);
	return (new);
}