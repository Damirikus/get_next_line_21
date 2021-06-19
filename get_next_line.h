#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <strings.h>
# include <fcntl.h>

int		get_next_line(int fd, char **line);
char	*ft_strchr(const char *str, int ch);
int		ft_strlen(char *str);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strlcpy (char *dst, const char *src, int size);
char	*ft_strdup(const char *s1);
char	*do_n(char *str);
char	*posle_n(char *ostatok);
int		pol(char **line1, char **ostatok1);
int		sos(char **line);
#endif
