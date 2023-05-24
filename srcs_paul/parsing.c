#include "petit_shell.h"

void	*ft_memset(void *s, int c, size_t n)
{
	while (n-- != 0)
		((char *)s)[n] = c;
	return (s);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}

int	pl_lenght(char *line)
{
	size_t	lenght;
	size_t	i;
	char	quote;
	int		consecutive_space;

	quote = 0;
	lenght = 0;
	i = 0;
	// consecutive_space = YES;
	while (line[i])
	{
		if (line[i] == '"' || line[i] == 39)
		{
			if (quote == 0)
				quote = line[i];
			else if (quote == line[i])
				quote = 0;
		}
		if (line[i] != ' ' || quote != 0)
		{
			// consecutive_space = YES;
			lenght ++;
		}
		if (i > 0 && line[i] != ' ' && line[i - 1] == ' ')
			lenght ++;
		// else
		// 	consecutive_space = NO;
		i ++;
	}
	return (lenght);
}

char	*remove_extra_space(char *line)
{
	char	*parsed_line;
	size_t	i;
	size_t	j;
	char	quote;

	i = 0;
	j = 0;
	quote = 0;
	parsed_line = NULL;
	// printf("lenght :%d\tft_malloc receive :%ld\n", pl_lenght(line), sizeof(char)*pl_lenght(line));
	parsed_line = ft_malloc(sizeof(char) * pl_lenght(line), ALLOC);
	// printf("parsed line after ft_malloc :%s\n", parsed_line);
	ft_bzero(parsed_line, pl_lenght(line));
	// printf("parsed line after memset :%s\n", parsed_line);
	while (line[i])
	{
		if (line[i] == '"' || line[i] == 39)//gere les quotes
		{
			if (quote == 0)
				quote = line[i];
			else if (quote == line[i])
				quote = 0;
		}
		if (line[i] != ' ' || quote != 0)
		{
			parsed_line[j] = line[i];
			j ++;
		}
		if (i > 0 && line[i] != ' ' && line[i - 1] == ' ' && quote == 0)// gere les espaces dans la string
		{
			parsed_line[j] = parsed_line[j - 1];
			parsed_line[j - 1] = ' ';
			j ++;
		}
		i ++;
	}
	// printf("parsed_line :%s\n", parsed_line);
	return (parsed_line);
}