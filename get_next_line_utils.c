int	ft_strlen(char *ptr)
{
	int count;

	while (*ptr != '\0')
	{
		count++;
		ptr++;
	}
	return (count);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (&((char *)s)[i]);
		i++;
	}
	if (((char *)s)[i] == (char)c)
		return (&((char *)s)[i]);
	return (0);
}

char	*ft_strdup(char *buf)
{
	char *ret;

	ret = malloc(sizeof(char) * (ft_strlen(buf) + 1));
	while (buf != NULL)
	{
		*ret = *buf++;
		ret++;
	}
	return (ret);
}

void	*ft_calloc(int count, int size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (ptr == NULL)
		return (0);
	ft_memset(ptr, 0, (size * count));
	return (ptr);
}

int	ft_chrcheck(const char *s, int c)
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
		return (1);
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, unsigned int len)
{
	char	*ptr;
	size_t	i;

	if (!s)
		return (0);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	i = 0;
	ptr = ft_calloc(len + 1, sizeof(char));
	if (!ptr)
		return (NULL);
	ptr[len] = 0;
	while (i < len)
		ptr[i++] = s[start++];
	return (ptr);
}
