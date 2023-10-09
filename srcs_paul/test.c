#include "petit_shell.h"

int	meta_char(char c)
{
	if (c == '|' || c == '>' || c == '<')
		return (1);
}

int	how_much_cmd(char *line)
{
	int nb_of_cmd;
	int	i;
	int	quote;

	quote = 0;
	i = 0;
	nb_of_cmd = 0;
	while(line && line[i])
	{
		if (line[i] == 34 || line[i] == 39) //quote et dquote
		{
			if (quote == 0)
				quote = line[i];
			else if (quote == line[i])
				quote = 0;
		}
		else if ((line[i] == '|' || line[i] == '>' || line[i] == '<') && !quote)
		{
			nb_of_cmd ++;
		}
		i ++;
	}
	return (nb_of_cmd)
}

void	parsing(char *get_line, t_env *env)
{
	char	**cmd_line;
	int		line;
	int		ch;
	int		nb_of_cmd;

	line = 0;
	ch = 0;
	nb_of_cmd = how_much_cmd(get_line);
}