#include "petit_shell.h"

size_t	ft_strlen(const char *string)
{
	size_t	len;

	len = 0;
	while (string && string[len])
		len++;
	return (len);
}

char	*ft_strdup(const char *s)
{
	size_t	str_len;
	size_t	i;
	char	*dup_str;

	str_len = ft_strlen(s);
	i = 0;
	dup_str = ft_malloc(sizeof(char) * (str_len + 1), ALLOC);
	if (dup_str == NULL)
		return (NULL);
	while (s[i])
	{
		dup_str[i] = s[i];
		i++;
	}
	dup_str[i] = '\0';
	return (dup_str);
}

t_env	*create_env(char **envp)
{
	size_t	index;
	t_env	*first;
	t_env	*env;
	t_env	*new;

	env = ft_malloc(sizeof(t_env), ALLOC);
	env->data = ft_strdup(envp[0]);
	env->next = NULL;
	first = env;//ou stocker env dant un struct
	index = 1;
	// printf("%s\n", env->data);
	while (envp[index])
	{
		new = ft_malloc(sizeof(t_env), ALLOC);
		new->data = ft_strdup(envp[index]);
		// printf("%s\n", new->data);
		new->next = env;
		env->next = new;
		env = new;
		index ++;
	}
	env->next = NULL;
	// printf("%s\n", first->data);
	return (first);
}