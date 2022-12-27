#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# define BUFFER_SIZE 1

char	*get_next_line(int fd);
int		ft_strlen(char *ptr);
char	*ft_strchr(char *s, int c);
char	*ft_strdup(char *buf);
void	*ft_calloc(size_t count, size_t size);
int		ft_chrcheck(char *s, int c);
char	*ft_substr(char *s, unsigned int start, unsigned int len);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, char *src, size_t dstsize);
void	ft_putstr(char *s);
char	*trim(char *red);
char	*apart_nl(char * red);
void	*ft_memset(void *b, int c, size_t len);

#endif
