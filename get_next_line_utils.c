#include "get_next_line.h"

char	*ft_strchr(const char *str, int ch)
{
	char	*str2;

	if (!str)
		return (NULL);
	str2 = (char *)str;
	while (*str2 != '\0')
	{
		if (*str2 == ch)
			return (str2);
		str2++;
	}
	if (*str2 == ch)
		return (str2);
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	char	*ss1;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
		i++;
	ss1 = (char *)malloc(sizeof(char) * (i + 1));
	if (!ss1)
		return (NULL);
	while (s1[j] != '\0')
	{
		ss1[j] = s1[j];
		j++;
	}
	ss1[j] = '\0';
	return (ss1);
}

int	ft_strlen(char *str)
{
	int	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		ls1;
	int		ls2;
	char	*str;

	ls1 = ft_strlen((char *)s1);
	ls2 = ft_strlen((char *)s2);
	str = (char *)malloc(ls1 + ls2 + 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, ls1 + 1);
	ft_strlcpy(str + ls1, s2, ls2 + 1);
	free((char *)s1);
	return (str);
}

int	ft_strlcpy (char *dst, const char *src, int size)
{
	int	i;

	i = 0;
	if (!src && !dst)
		return (i);
	if (size != 0)
	{
		i = 0;
		while (i < size - 1 && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	i = ft_strlen((char *)src);
	return (i);
}
