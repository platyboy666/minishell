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
		{	//printf("len:%zu\tlittle:%s\n", len, little);
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

char	*find_$_sp(char *str)//retourne un pointeur '$' ou ' ' plus petit
{
	char	*r;
	char	*i;

	r = find_sp_eof(str);
	i = ft_strchr(str, '$');
	if (r > i && i)
		return (i);
	return (r);
}

char	*print_$(char *var, t_env *env)//cherche une correspondance a var dans l'env et le print
{
	char *value;

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
			str = print_$(strchr(str, '$') + 1, env);
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
	printf("%s\tis %zu letter long\n", cwd, ft_strlen(cwd));
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

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	printf("1src :%s\n", src);
	if (dstsize < 1)
		return (ft_strlen(src));
	while (i < dstsize - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	printf("2src :%s\n", src);
	dst[i] = '\0';
	printf("3src :%s\n", src);
	return (ft_strlen(src));
}

t_env	*find_$(char *var, t_env *env)//cherche une correspondance a var dans l'env et le print
{
	char	*str;

	printf("1var :%s\n", var);
	if (ft_strchr(var, '='))
	{printf("2var :%s\n", var);
		ft_strlcpy(str, var, ft_strchr(var, '=') - var + 1);//peut etre chance
	printf("3var :%s\n", var);}
// printf("str :%s\tft_strchr(var, '=') - var :%ld\n", str, ft_strchr(var, '=') - var);//marche pas sais pas pk
	else
		str = ft_strdup(var);
	while (strncmp(env->data, str, ft_strlen(str)) && env->next)//parcour l'env pour trouver correspondence
		env = env->next;
	if (strncmp(env->data, str, ft_strlen(str)) == 0)//a trouver correspondence
		return (env);
	else
		return (NULL);
}

void	ft_export(t_env *env, char *new_data)
{
	t_env	*new_variable;

	if (!strchr(new_data, '='))
		return ;
	// printf("1new_data :%s\n", new_data);
	new_data = next_word(new_data);
	// printf("2new_data :%s\n", new_data);
	new_variable = find_$(new_data, env);
	// printf("3new_data :%s\n", new_data);
	if (new_variable)
		new_variable->data = new_data;
	else
	{
		while (env->next)
			env = env->next;
		new_variable = ft_malloc(sizeof(t_env), ALLOC);

		env->next = new_variable;
		new_variable->data = new_data;
		new_variable->next = NULL;
	}
}

t_env	*ft_unset(t_env *env, char *rm_data)
{
	t_env	*tmp;
	t_env	*first;

	tmp = NULL;
	first = env;
	rm_data = next_word(rm_data);
	while (env->next)
	{//ft_strnstr(env->data, rm_data, find_$_sp(rm_data) - rm_data) && env->data[find_$_sp(rm_data) - rm_data + 1] == '=')
		if (ft_strnstr(env->data, rm_data, find_$_sp(rm_data) - rm_data) && env->data[find_$_sp(rm_data) - rm_data + 1] == '=')
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
