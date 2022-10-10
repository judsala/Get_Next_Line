/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdantas- <jdantas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:02:05 by jdantas-          #+#    #+#             */
/*   Updated: 2022/10/10 13:47:34 by jdantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(char *s);
char	*finder(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*set_buffer(int fd, char *buffer);
char	*get_line(char *s);
char	*next_line(char *buffer);
char	*get_next_line(int fd);

#endif
