/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyildiz <seyildiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 17:46:45 by seyildiz          #+#    #+#             */
/*   Updated: 2022/03/10 13:26:13 by seyildiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

unsigned int	ft_strlen(const char *str)
{
	unsigned int	count;

	count = 0;
	if (str[count] != '\0')
	{
		while (str[count] != '\0')
		{
			count++;
		}
	}
	return (count);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int				i;
	int				a;
	char			*array;
	unsigned int	len;

	a = 0;
	i = 0;
	if (s1)
	{
		len = ft_strlen(s1) + ft_strlen(s2) + 1;
		array = (char *)malloc(sizeof(char) * (len));
		if (array == NULL)
			return (NULL);
		while (s1[i] != '\0')
			array[a++] = s1[i++];
		i = 0;
		while (s2[i] != '\0')
		{
			array[a++] = s2[i++];
		}
		array[a] = '\0';
		free (array);
		return (array);
	}
	return (NULL);
}

char	*ft_strchr(const char *str, int c)
{
	int	count;

	count = 0;
	while (str[count] != c)
	{
		if (str[count] == '\0')
		{
			return (NULL);
		}
		count++;
	}
	return ((char *)&str[count]);
}

char	*ft_strdup(const char *str)
{
	int		count;
	int		i;
	char	*s1;

	count = 0;
	i = 0;
	while (str[count] != '\0')
	{
		count++;
	}
	s1 = (char *)malloc(count + 1);
	if (s1 == NULL)
		return (NULL);
	while (i <= count)
	{
		s1[i] = str[i];
		i++;
	}
	return (s1);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*line;
	size_t		count;

	buff = (char *)malloc((sizeof(char)) * (BUFF_SIZE + 1));
	if (!buff)
		return (NULL);
	count = 1;
	if (fd < 0 || BUFF_SIZE <= 0)
		return (0);
	while (!ft_strchr(buff, '\n') && count != 0)
	{
		count = read(fd, buff, BUFF_SIZE);
		if (count == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[count] = '\0';
		line = ft_strjoin(line, buff);
	}
	return (line);
}

int	main (void)
{
	char	*line;
	int		fd;

	fd = open("text.txt", O_RDONLY);
	line = get_next_line(fd);
	fd = open("text.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s\n", line);
}
