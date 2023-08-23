/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:13:08 by esalim            #+#    #+#             */
/*   Updated: 2022/11/04 12:04:07 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	1
# endif

char	*get_next_line(int fd);
char	*ft_strjoin(char *stc, char *buff);
char	*ft_strdup(char *s);
char	*ft_strchr(char	*s, int c);
char	*ft_substr(char	*str, unsigned int start, size_t len);

#endif
