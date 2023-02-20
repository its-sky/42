/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mincshin <mincshin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:37:50 by mincshin          #+#    #+#             */
/*   Updated: 2023/02/20 16:37:50 by mincshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

int		ft_malloc_buff(char **buffers, int fd);
int		ft_find_nl(char **buffers, int fd, char **result);
int		ft_realloc_buff(char **buffers, int fd, int n, int buff_len);
char	*ft_buffncat(char **result, char *buff, int n, int ft_buffncat);
char	*get_next_line(int fd);
void	ft_free_all(char **buffers, char **result);
int		ft_read_process(char **buffers, int fd, char **result);

#endif
