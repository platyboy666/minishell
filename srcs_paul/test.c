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
			// if (i + j == len)
			// 	return ((char *)(&big[i]));
			j++;
		}
		if (i + j == len)
				return ((char *)(&big[i]));
		// if (i + j == len)//ajout si on cherche "zsh=valeur" "zsh apa" 3  
		// 	return ((char *)(&big[i]));
		i++;
	}
	return (NULL);
}

int main(int argc, char *argv[])
{
	char *s = NULL;

	s = ft_strnstr(argv[1], argv[2], 1);
	if (s)
		printf("%s\n", s);
}