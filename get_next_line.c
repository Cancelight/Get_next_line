/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 13:30:44 by bkiziler          #+#    #+#             */
/*   Updated: 2022/12/11 15:31:37 by bkiziler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


char	*get_next_line(int fd)
{
	char *str;
	static char *a;
	char *ret;
	int eof;

	while(eof)
	{
		eof = read(fd, str, BUFFER_SIZE);
		if (ft_chrcheck(str, '\n'))
			a = ft_substr(ft_strchr(str, '\n'), 1, (ft_strlen(ft_strchr(str, '\n') - 1)));
			ret = ft_substr(str, 0, &ft_strchr(str, '\n') - &str);
			free(str);
			return(ret);
	}
}
