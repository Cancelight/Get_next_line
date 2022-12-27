/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 12:11:19 by bkiziler          #+#    #+#             */
/*   Updated: 2022/12/27 19:35:08 by bkiziler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *trim(char *red)
{
	char *temp;
	int len;

	if(ft_chrcheck(red, '\n'))
	{
		len = ft_strlen(red) - ft_strlen(ft_strchr(red, '\n') + 1);
		temp = ft_substr(red, len, ft_strlen(ft_strchr(red, '\n')));
		free(red);
		red = malloc(sizeof(char) * ft_strlen(temp));
		red = ft_substr(temp, 0, ft_strlen(temp));
		free(temp);
	}
	return (red);
}

char	*apart_nl(char * red)
{
	int a ;
	char *stret;

	if (!red)
		return (NULL);
	if (*red)
	{
		a = (ft_strlen(red) - ft_strlen(ft_strchr(red, '\n') + 1));
		stret = ft_substr(red, 0, a);
	}
	free(red);
	return (stret);

}

char	*get_next_line(int fd)
{
	char *str;
	int eof;
	static char *red;

	str = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if(!str || fd < 0 || BUFFER_SIZE <= 0)
		return(0);
	eof = 1;
	while(!ft_chrcheck(str, '\n') && eof)
	{
		eof = read(fd, str, BUFFER_SIZE);
		if(eof == -1)
		{
			free(red);
			free(str);
			return(0);
		}
		str[eof] = '\0';
		red = ft_strjoin(red, str);
	}
	free(str);
	str = apart_nl(red);
	red = trim(red);
	return (str);
}
