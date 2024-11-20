/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 21:32:56 by gbodur            #+#    #+#             */
/*   Updated: 2024/11/20 17:25:52 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read_file(int fd, char *keep)
{
	char	*temp;
	int		rd;

	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (NULL);
	rd = 1;
	while (!ft_strchr(keep, '\n') && rd != 0)
	{
		rd = read(fd, temp, BUFFER_SIZE);
		if (rd == -1)
			return (free(temp), free(keep), NULL);
		temp[rd] = '\0';
		keep = ft_strjoin(keep, temp);
		if (!keep)
			return (free(temp), NULL);
	}
	return (free(temp), keep);
}

char	*ft_extract_line(char *keep)
{
	char	*line;
	int		i;
	size_t	len;

	i = 0;
	if (!keep)
		return (NULL);
	while (keep[i] && keep[i] != '\n')
		i++;
	if (keep[i] == '\n')
		len = i + 1;
	else
		len = i;
	line = ft_substr(keep, 0, len);
	return (line);
}

char	*ft_delete_read(char *keep)
{
	char	*rtn;
	int		i;

	i = 0;
	while (keep && keep[i] && keep[i] != '\n')
		i++;
	if (!keep || keep[i] == '\0')
		return (free(keep), NULL);
	i++;
	rtn = ft_substr(keep, i, ft_strlen(keep) - i);
	return (free(keep), rtn);
}

char	*get_next_line(int fd)
{
	static char	*keep[MAX_FD];
	char		*line;

	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	keep[fd] = ft_read_file(fd, keep[fd]);
	if (!keep[fd])
		return (NULL);
	line = ft_extract_line(keep[fd]);
	keep[fd] = ft_delete_read(keep[fd]);
	return (line);
}
