/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 14:37:34 by pkorsako          #+#    #+#             */
/*   Updated: 2023/03/27 18:38:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "petit_shell.h"

void	free_garbage(t_garbage *alloc_elements)
{
	t_garbage *index;
	int i = 0;

	alloc_elements = alloc_elements->next;
	index = alloc_elements;
	while(alloc_elements)
	{
		index = alloc_elements;
		free(alloc_elements->element);
		alloc_elements = alloc_elements->next;
		free(index);
	}
	
}

t_garbage	upgrade_list(t_garbage *alloc_elements, void *allocated_element)
{
	t_garbage	*new_struct;
	t_garbage	*index;
	
	new_struct = malloc(sizeof(t_garbage));
	if(!new_struct)
		exit(1);
	index = alloc_elements;
	while (index->next)
		index = index->next;
	index->next = new_struct;
	new_struct->element = allocated_element;
	new_struct->next = NULL;
}

void	*g_collector(size_t byte_size, int action)
{
	static t_garbage	alloc_elements;
	void				*allocated_element;
	
	if (action == FREE)
		free_garbage(&alloc_elements);
	else
	{
		allocated_element = malloc(byte_size);
		if (!allocated_element)
			g_collector(0, FREE);
		upgrade_list(&alloc_elements, allocated_element);
		return (allocated_element);
	}
	return (NULL);
}

int main()
{
	char	*str;
	int		*i;
	unsigned long *l;
	
	str = g_collector(sizeof(char) * 11, ALLOC);
	i = g_collector(sizeof(int) * 2, ALLOC);
	l = g_collector(sizeof(unsigned long) * 3, ALLOC);
	strncpy(str, "popopopopo", 11);
	i[0] = 123;
	i[1] = 456;
	l[0] = 1234567890;
	l[1] = 112233445566778899;
	l[2] = 4294967295;
	printf("%s\n", str);
	printf("%d\t%d\n", i[0], i[1]);
	printf("%ld\t%ld\t%ld\n", l[0], l[1], l[2]);
	g_collector(0, FREE);
	return (1);
}