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
		if (i + j == len)//si plusieur valeur sans espace entre
		{	printf("len:%zu\tlittle:%s\n", len, little);
			return ((char *)(&big[i]));
		}i++;
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

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	// printf("i in sttrchr :%d\n", i);
	if (c == '\0')
		return ((char *)s + i);
	return (0);
}

void	cd(char *str)
{
	str = next_word(str);
	chdir(str);//comprend pas comment ca marche
}

void	ft_exit()
{
	ft_malloc(0, FREE);
	exit(1);
}

char	*find_$_sp(char *str)//retourne un pointeur $ ou ' ' plus petit
{
	char	*r;
	char	*i;

	r = find_sp_eof(str);
	i = ft_strchr(str, '$');
	if (r > i)
		return (i);
	return (r);
}

char	*find_$(char *var, t_env *env)//cherche une correspondance a var dans l'env et le print
{
	char *value;

	// printf("cacafnct :%s\n", find_$_sp(var));
	// printf("var :%s\n", var);
	value = NULL;
	while (!value && env->next)
	{
		value = ft_strnstr(env->data, var, find_$_sp(var) - var);//find_sp_eof(var) - var
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
	if (find_$_sp(var) > find_sp_eof(var))//si un espace suis
		return(find_sp_eof(var) - 1);//renvoie a cette espace
	return(find_$_sp(var) - 1);//deux $ sont colle
}

void	echo(char *str, char option, t_env *env)
{
	char	*s; 
	size_t	i;

	i = 0;
	while (str && *str)// strtrim ' ' peut etre
	{
		// printf("str %s\n", str);
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
	char cwd[200];// a precisuer plus tard, faire un malloc, si cwd = null allouer de + en + jusqu'a reussite
	getcwd(cwd, 200);
	// printf("%s\tis %zu letter long\n", cwd, ft_strlen(cwd));
}

void	ft_env(t_env *env)
{
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

t_env	*ft_unset(t_env *env, char *rm_data)
{

}

t_env	*ft_unset(t_env *env, char *rm_data)
{
	t_env	*tmp;
	t_env	*first;

	tmp = NULL;
	first = env;
	rm_data = next_word(rm_data);
	// printf("em_data :%s\n", rm_data);
	while (env->next)
	{
		if (ft_strnstr(env->data, rm_data, find_sp_eof(rm_data) - rm_data))
			break;
		tmp = env;
		env = env->next;
	}
	if (tmp)
	{	printf("tmp; %s\tenv: %s\n", tmp->data, env->data);
		tmp->next = env->next;//pas besoins de free, le gb s'en occupera
	}
	else//si c'est le premier élément de la liste
		first = env->next;
	return (first);
}
