#include "petit_shell.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!little || little[0] == '\0')
		return ((char *)big);
	while (big[i] && i < len)// && i < len
	{
		j = 0;
		while (big[i + j] == little[j] && (i + j) < len)// && (i + j) < len
		{
			if (little[j + 1] == '\0')
				return ((char *)(&big[i]));
			j++;
		}
		i++;
	}
	return (NULL);
}

int main()
{
	char *s = NULL;
	s = ft_strnstr("popo=tamere", "popo", 5);
	printf("%s\n", s);
}