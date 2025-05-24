/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorodrig <gorodrig@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 08:40:21 by gorodrig          #+#    #+#             */
/*   Updated: 2024/08/04 11:44:08 by gorodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(char *str);
char	*ft_append(char *s1, char *s2);
char	*find_newline(char *readed);
char	*ft_new_line(char *readed);
char	*ft_fd_reader(int fd, char *readed);
char	*get_next_line(int fd);
char	*ft_return_rest(char *readed);

#endif
