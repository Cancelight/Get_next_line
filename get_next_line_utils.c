/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 16:07:26 by bkiziler          #+#    #+#             */
/*   Updated: 2022/12/27 14:08:21 by bkiziler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *ptr)
{
	int count;

	count = 0;
	if(!ptr)
		return (0);
	while (ptr[count] != '\0')
		count++;
	return (count);
}

char	*ft_strchr(char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return (s);
		s++;
	}
	return (0);
}

int	ft_chrcheck(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (1);
		i++;
	}
	if (((char *)s)[i] == (char)c)
		return(1);
	return (0);
}

char	*ft_substr(char *s, unsigned int start, unsigned int len)
{
	char	*ptr;
	unsigned int	i;

	if (!s)
		return (0);
	if (ft_strlen(s) < start)
		return (NULL);
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	i = 0;
	ptr = malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (0);
	ptr[len] = 0;
	while (i < len)
		ptr[i++] = s[start++];
	return (ptr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ptr;
	int i;
	i = -1;

	if (!s1)
	{
		s1 = malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	ptr = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (ptr == NULL)
		return (NULL);
	while(s1 && s1[++i] != '\0')
		ptr[i] = s1[i];
	while(s2 && *s2 != '\0')
		ptr[i++] = *s2++;
	ptr[i] = '\0';
	free(s1);
	return (ptr);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (ptr == NULL)
		return (0);
	ft_memset(ptr, 0, (size * count));
	return (ptr);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	u;
	size_t			i;

	u = c;
	i = 0;
	while (i < len)
	{
		((unsigned char *)b)[i] = u;
		i++;
	}
	return (b);
}
