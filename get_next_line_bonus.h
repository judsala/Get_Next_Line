/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdantas- <jdantas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:26:44 by jdantas-          #+#    #+#             */
/*   Updated: 2022/10/10 15:43:11 by jdantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

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
