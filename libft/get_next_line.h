/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhrypko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 04:22:51 by ikhrypko          #+#    #+#             */
/*   Updated: 2018/11/26 13:50:58 by ikhrypko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _GET_NEXT_LINE_H
# define _GET_NEXT_LINE_H
# define BUFF_SIZE 1
# include "libft.h"
# include <stdlib.h>
# include <fcntl.h>

typedef	struct		s_node
{
	int				fd;
	int				i;
	int				rs;
	char			buff[(BUFF_SIZE < 0) ? -BUFF_SIZE : BUFF_SIZE];
	struct s_node	*next;
}					t_node;

int					get_next_line(const int fd, char **line);

#endif
