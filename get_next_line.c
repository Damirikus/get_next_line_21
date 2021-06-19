#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	int			readf;
	static char	*ostatok;

	if (BUFFER_SIZE <= 0 || !line || fd < 0)
		return (-1);
	readf = read(fd, buf, BUFFER_SIZE);
	while (readf > 0 || ft_strchr(ostatok[fd], '\n'))
	{
		buf[readf] = 0;
		ostatok = ft_strjoin(ostatok, buf);
		if (ft_strchr(ostatok, '\n') != NULL)
			return (pol(line, &ostatok));
		readf = read(fd, buf, BUFFER_SIZE);
	}
	if (readf < 0)
		return (-1);
	if (!ostatok)
		return (sos(line));
	*line = ostatok;
	ostatok = NULL;
	return (0);
}

int	sos(char **line)
{
	*line = ft_strdup("");
	if (*line == NULL)
		return (-1);
	return (0);
}

int	pol(char **line1, char **ostatok1)
{
	*line1 = do_n(*ostatok1);
	if (*line1 == NULL)
		return (-1);
	*ostatok1 = posle_n(*ostatok1);
	if (*ostatok1 == NULL)
		return (-1);
	return (1);
}

char	*do_n(char *str)
{
	int		i;
	int		k;
	char	*src;

	i = 0;
	while (str[i] != '\n')
		i++;
	src = (char *)malloc(i + 1);
	if (!src)
		return (NULL);
	src[i] = 0;
	k = 0;
	while (k < i)
	{
		src[k] = str[k];
		k++;
	}
	return (src);
}

char	*posle_n(char *ost)
{
	char	*ftr;
	int		i;
	int		k;

	i = 0;
	while (ost[i] != '\n')
		i++;
	k = ft_strlen(ost + i + 1);
	ftr = (char *)malloc(k + 1);
	if (!ftr)
	{
		free(ost);
		return (NULL);
	}
	ftr[k] = 0;
	ft_strlcpy(ftr, ost + i + 1, k + 1);
	free(ost);
	return (ftr);
}
