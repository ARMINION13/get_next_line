/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 19:42:34 by rgirondo          #+#    #+#             */
/*   Updated: 2020/01/29 18:33:58 by rgirondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	unsigned int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*str;

	i = 0;
	while (s[i] != 0)
		i++;
	if (!(str = malloc(i + 1)))
		return (0);
	i = 0;
	if (str != 0)
	{
		while (s[i] != 0)
		{
			str[i] = s[i];
			i++;
		}
		str[i] = 0;
	}
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;

	i = 0;
	if (s1 && s2)
	{
		str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
		if (!str)
			return (NULL);
		while (*s1)
			str[i++] = *s1++;
		while (*s2)
			str[i++] = *s2++;
		str[i] = '\0';
		return (str);
	}
	return (0);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char *ptr;

	ptr = (unsigned char*)s;
	while (n-- > 0)
		*(ptr++) = 0;
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;

	i = 0;
	if (s)
	{
		if (!(str = malloc((len + 1) * sizeof(char))))
			return (NULL);
		ft_bzero(str, len);
		if (start <= ft_strlen(s))
		{
			while (i < len && s[i])
			{
				str[i] = s[i + start];
				i++;
			}
		}
		if (i < len + 1)
			str[i] = '\0';
		return (str);
	}
	return (0);
}
