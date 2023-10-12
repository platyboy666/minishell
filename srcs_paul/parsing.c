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

int	how_much_cmd(char *line)
{
	int nb_of_cmd;
	int	i;
	int	quote;

	quote = 0;
	i = 0;
	nb_of_cmd = 1;
	while(line && line[i])
	{
		if (line[i] == 34 || line[i] == 39) //quote et dquote
		{
			if (quote == 0)//quote == 0 quand hors de quote
				quote = line[i];//quote devient quote ou dquote
			else if (quote == line[i])//verifie si la quote actuel est le meme type que celle du debut
				quote = 0;//on est plus entre des quotes
		}
		else if ((line[i] == '|' || line[i] == '>' || line[i] == '<') && !quote)//gere pas les || et << et >>
		{
			if ((line[i] == '>' && line[i + 1] == '>' ) || (line[i] == '<' && line[i + 1] == '<'))
				i ++;
			nb_of_cmd ++;
		}
		i ++;
	}
	printf("nb_of_cmd :%d\n\n", nb_of_cmd);
	return (nb_of_cmd);
}

int	char_b_metachar(char *get_line)//retourne cmb de char avant le premier metachar interpreter, strlen si aucun
{
	// char	*line;
	// int		char_befor_metachar;
	int		i;
	int		quote;
	int		how_much_quote;

	how_much_quote = 0;
	quote = 0;
	i = 0;
	while(get_line[i])
	{
		if (get_line[i] == 34 || get_line[i] == 39) //quote et dquote
		{
			if (quote == 0)//quote == 0 quand hors de quote
			{
				// how_much_quote ++;	
				quote = get_line[i];//quote devient quote ou dquote
			}
			else if (quote == get_line[i])//verifie si la quote actuel est le meme type que celle du debut
			{
				// how_much_quote ++;
				quote = 0;//on est plus entre des quotes
			}
		}
		else if ((get_line[i] == '|' || get_line[i] == '>' || get_line[i] == '<') && !quote)
			break;
		i ++;
	}
	// printf("there is %d char befor metachar\n", i);
	return (i - how_much_quote);
	// line = ft_malloc(sizeof(char) * i, ALLOC);
	// return (line);
}

char	*fill_cmd_line(char *get_line, char *cmd_line)//remplis la ligne de commande et renvoie un pointeur apres le prochain metachar de get_line
{
	int	i;
	int	quote;
	int	char_befor_metachar;
	char	c;

	char_befor_metachar = char_b_metachar(get_line);
	quote = 0;
	i = 0;
	// printf("line will be max:%d long\n", char_befor_metachar);
	while (char_befor_metachar > 0)//*get_line && (*get_line == 34 && quote == 34) && (*get_line == 39 && quote == 39)
	{
		if (*get_line == 34 || *get_line == 39) //quote et dquote
		{
			if (quote == 0)//quote == 0 quand hors de quote
				quote = *get_line;//quote devient quote ou dquote
			else if (quote == *get_line)//verifie si la quote actuel est le meme type que celle du debut
				quote = 0;//on est plus entre des quotes
			else if (*get_line != quote)// quote dans quote
			{
				cmd_line[i] = *get_line;
				i ++;
			}
		}
		else
		{
			cmd_line[i] = *get_line;
			i ++;
		}
		get_line ++;
		char_befor_metachar --;
	}
	c = *get_line;
	get_line ++;
	printf("get_line first char is %c\n", *get_line);
	if (c == *get_line)
		get_line ++;
	return (get_line);
}

t_data	*parsing(char *get_line, t_env *env)
{
	char	**cmd_line;
	t_data	*data;
	int		line;
	int		ch;
	int		nb_of_cmd;

	data = ft_malloc(sizeof(t_data *), ALLOC);
	line = 0;
	ch = 0;
	nb_of_cmd = how_much_cmd(get_line);
	data->cmd_lines = ft_malloc(sizeof(char *) * nb_of_cmd, ALLOC);
	while (line < nb_of_cmd)
	{
		printf("cmd_line[%d] is malloc for %d char \n", line, char_b_metachar(get_line));
		data->cmd_lines[line] = ft_malloc(sizeof(char) * char_b_metachar(get_line), ALLOC);//alloue la ligne jusqu'au premier metachar
		ft_bzero(data->cmd_lines[line], char_b_metachar(get_line));
		get_line = fill_cmd_line(get_line, data->cmd_lines[line]);//renvoi pointeur apres metachar
		printf("%d line is :%s\n", line, data->cmd_lines[line]);
		printf("what left of get_line is :%s\n\n", get_line);
		line ++;
	}
	return (data);
	// return (cmd_line);
}

/*int	pl_lenght(char *line)
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
}*/