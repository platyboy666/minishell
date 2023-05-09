#include "petit_shell.h"

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
		if (line[i] != ' ' || quote != 0 || consecutive_space == NO)
		{
			// consecutive_space = YES;
			lenght ++;
		}
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
	 printf("lenght :%d\n", pl_lenght(line));
	parsed_line = ft_malloc(sizeof(char) * pl_lenght(line), ALLOC);
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
			parsed_line[j] = line[i];
			j ++;
		}
		i ++;
	}
	printf("parsed_line :%s\n", parsed_line);
	return (parsed_line);
}