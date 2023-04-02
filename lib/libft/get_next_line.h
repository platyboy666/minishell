/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 20:53:52 by claclau           #+#    #+#             */
/*   Updated: 2022/09/12 20:51:10 by claclau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>

char	*get_next_line(int fd);
size_t	ft_strlen2(const char *string);
char	*ft_substr2(char *s, unsigned int start, size_t len);
char	*ft_strjoin2(char *s1, char *s2);
char	*ft_strchr2(const char *s, int c);
char	*ft_strdup2(const char *s);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
#endif
