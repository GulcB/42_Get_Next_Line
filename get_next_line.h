/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:17:33 by gbodur            #+#    #+#             */
/*   Updated: 2024/11/19 21:23:46 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_read_file(int fd, char *keep);
char	*ft_extract_line(char *keep);
char	*ft_delete_read(char *keep);
void	ft_get_strncpy(char *dst, const char *src, int n);
size_t	ft_get_strlen(const char *s);
char	*ft_get_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char *s1, char *s2);

#endif