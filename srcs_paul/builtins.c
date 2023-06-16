#include "petit_shell.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (*s1 == ' ')
		s1 ++;
	while ((s1[i] != '\0') && (s1[i] == s2[i]))
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)//echo
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!little || little[0] == '\0')
		return ((char *)big);
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && (i + j) < len)
		{
			if (little[j + 1] == '\0' || little[j + 1] == ' ')
				return ((char *)(&big[i]));
			j++;
		}
		i++;
	}
	return (NULL);
}

char	*next_word(char *str)//retourne un pointeur au début du prochain mot
{
	while (*str && *str != ' ')
		str ++;
	while (*str && *str == ' ')
		str ++;
	return (str);
}

char	*find_sp_eof(char *str)//retourne un pointeur sur le premier ' ' ou 0 rencontrer
{
	while(*str)
	{
		if (*str == ' ')
			return (str);
		str ++;
	}
	return(str);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return(NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if (c == '\0')
		return ((char *)s + i);
	return (0);
}

void	cd(char *str)
{
	str = next_word(str);
	chdir(str);//comprend pas comment ca marche
}

void	ft_exit(int i)
{
	exit(i);
}

char	*find_$(char *var, t_env *env)//cherche une correspondance au premier mot dans l'env
{
	char *value;

	value = NULL;
	while (!value && env->next)
	{
		value = ft_strnstr(env->data, var, find_sp_eof(var) - var);
		if (!value)
			env = env->next;
		else
		{
			value = ft_strchr(env->data, '=') + 1;
			break;
		}
	}
	if (value)
		printf("%s", value);
	return(find_sp_eof(var) - 1);
}

void	echo(char *str, char option, t_env *env)
{
	char	*s; 
	size_t	i;

	i = 0;
	while (str && *str)// strtrim ' ' peut etre
	{
		if (*str && *str != '$')
			printf("%c", *str);
		else if (*str == '$')
		{
			str = find_$(strchr(str, '$') + 1, env);
		}
		str ++;
	}
	if (option != 'n')
		printf("\n");
}

void	pwd(void)
{
	char cwd[50];// a precisuer plus tard
	printf("%s\n", getcwd(cwd, 50));
}

void	ft_env(t_env *env)
{
	int	i;

	i = 0;
	// printf("%s\n", env->data);
	while (env->next)
	{
		printf("%s\n", env->data);
		env = env->next;
	}
	printf("%s\n", env->data);

}

void	ft_export(t_env *env, char *new_data)//
{
	t_env	*new_variable;

	new_data = next_word(new_data);
	// printf("new_data :%s\n", new_data);
	while (env->next)
		env = env->next;
	new_variable = ft_malloc(sizeof(t_env), ALLOC);

	env->next = new_variable;
	new_variable->data = new_data;
	new_variable->next = NULL;
}

void	ft_unset(t_env *env, char *rm_data)
{
	t_env	*tmp;

	rm_data = next_word(rm_data);
	// printf("em_data :%s\n", rm_data);
	while (env->next)
	{
		if (ft_strnstr(env->data, rm_data, find_sp_eof(rm_data) - rm_data))
			break;
		tmp = env;
		env = env->next;
	}
	tmp->next = env->next;//pas besoins de free, le gb s'en occupera
}
