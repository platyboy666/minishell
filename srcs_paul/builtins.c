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

void	cd(char *str)
{
	chdir(str);
}

void	ft_exit(int i)
{
	exit(i);
}

void	echo(char *str, char option)
{
	printf("%s", str);
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
	new_variable->data = 
}
