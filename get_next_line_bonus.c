/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 18:12:06 by rgirondo          #+#    #+#             */
/*   Updated: 2020/01/29 19:00:06 by rgirondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char			*ft_strchr(const char *str, int c)
{
	char	*ptr;
	int		a;

	ptr = (char *)str;
	a = 0;
	while (ptr[a] != c && ptr[a] != 0)
		a++;
	if (ptr[a] == c)
		return (ptr + a);
	return (NULL);
}

void			operation_null(char **s)
{
	if (*s && **s)
	{
		free(*s);
		*s = NULL;
	}
}

int				maniobra_line(char **s, char **line, int fd)
{
	int		a;
	char	*tmp;

	a = 0;
	while (s[fd][a] != '\n' && s[fd][a] != '\0')
		a++;
	if (s[fd][a] == '\n')
	{
		*line = ft_substr(s[fd], 0, a);
		tmp = ft_strdup(&s[fd][a + 1]);
		free(s[fd]);
		s[fd] = tmp;
	}
	else
	{
		*line = ft_strdup(s[fd]);
		operation_null(&s[fd]);
		return (0);
	}
	return (1);
}

int				returns(char **s, char **line, int count, int fd)
{
	if (count < 0)
		return (-1);
	else if (count == 0 && s[fd] == NULL)
	{
		*line = ft_strdup("");
		operation_null(&s[fd]);
		return (0);
	}
	return (maniobra_line(s, line, fd));
}

int				get_next_line(int fd, char **line)
{
	static char		*s[4096];
	int				count;
	char			buff[BUFFER_SIZE + 1];
	char			*tmp;

	count = 0;
	if (fd < 0 || line == NULL || BUFFER_SIZE == 0)
		return (-1);
	while ((count = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[count] = '\0';
		if (s[fd] == NULL)
			s[fd] = ft_strdup(buff);
		else
		{
			tmp = ft_strjoin(s[fd], buff);
			free(s[fd]);
			s[fd] = tmp;
		}
		if (ft_strchr(s[fd], '\n'))
			break ;
	}
	return (returns(s, line, count, fd));
}
