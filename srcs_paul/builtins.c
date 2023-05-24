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

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && (i + j) < len)
		{
			if (little[j + 1] == '\0')
				return ((char *)(&big[i]));
			j++;
		}
		i++;
	}
	return (NULL);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
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
	chdir(str);
}

void	ft_exit(int i)
{
	exit(i);
}

char	*find_$(char *var, t_env *env)
{
	char *value;

	value = NULL;
	printf("var :%s\t", var);
	while (!value && env->next)
	{
		value = ft_strnstr(var, env->data, 5);
		if (!value)
			env = env->next;
	}
	printf("find_$ :%s\n", env->data);
	value = ft_strchr(env->data, '=') + 1;
	printf("value :%s\n", value);
	return(value);
}

void	echo(char *str, char option, t_env *env)
{
	char *s = strchr(str, '$');
	find_$(s, env);
	// printf("%s", str);
	if (option != 'n')
		printf("\n");
}

void	pwd(void)
{
	char cwd[20];// a precisuer plus tard
	printf("%s\n", getcwd(cwd, 30));
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

void	ft_export(t_env *env, char *new_data)
{
	t_env	*new_variable;

	while (env->next)
		env = env->next;
	new_variable = ft_malloc(sizeof(t_env), ALLOC);
	env->next = new_variable;
	new_variable->data = new_data;
}
