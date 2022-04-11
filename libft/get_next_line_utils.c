/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 15:29:07 by jrasser           #+#    #+#             */
/*   Updated: 2022/04/11 21:24:47 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strconcat(char *line, char *buffer)
{
	size_t	i;
	size_t	j;
	char	*new_str;

	new_str = malloc(sizeof(char) * (ft_strlen(line) + ft_strlen(buffer)) + 1);
	if (new_str == NULL)
		return (NULL);
	i = 0;
	while (line && line[i])
	{
		new_str[i] = line[i];
		i++;
	}
	if (line)
		free(line);
	j = 0;
	while (buffer && buffer[j] && buffer[j] != '\n')
		new_str[i++] = buffer[j++];
	if (buffer[j] == '\n')
		new_str[i++] = buffer[j++];
	new_str[i] = '\0';
	return (new_str);
}

char	*update_buffer(char *buffer)
{
	long	i;
	long	j;
	char	*tmp;

	i = 0;
	while (buffer[i] != '\n' && i < BUFFER_SIZE)
		i++;
	tmp = malloc(sizeof(char) * (BUFFER_SIZE - i + 1));
	if (tmp == NULL)
		return (NULL);
	i++;
	j = 0;
	while (i < BUFFER_SIZE && buffer[i])
		tmp[j++] = buffer[i++];
	tmp[j] = '\0';
	free(buffer);
	if (tmp[0] == '\0')
	{
		free(tmp);
		return (NULL);
	}
	return (tmp);
}

int	ft_check_buffer_empty(char **buffer, int fd)
{
	size_t	i;
	size_t	len;
	int		is_empty;
	int		ret;

	is_empty = 1;
	ret = 1;
	len = ft_strlen(*buffer);
	i = 0;
	while (i < len && is_empty)
	{
		if (*(buffer)[i] != '\0')
			is_empty = 0;
		i++;
	}
	if (is_empty == 1)
	{
		*buffer = ft_calloc_line(*buffer, BUFFER_SIZE);
		ret = ft_read(fd, *buffer);
		if (ret == 0 || ret == -1)
			free(*buffer);
	}
	return (ret);
}

int	ft_is_buffer_end_line(char *buffer)
{
	unsigned long	i;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		return (1);
	return (0);
}
