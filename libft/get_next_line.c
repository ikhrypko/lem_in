/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhrypko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 20:57:42 by ikhrypko          #+#    #+#             */
/*   Updated: 2018/11/23 20:57:44 by ikhrypko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	t_node	*ft_find_fd(t_node **s_list, int fd)
{
	t_node	*head;
	t_node	*tmp;

	if (*s_list == NULL)
	{
		(*s_list) = (t_node*)ft_memalloc(sizeof(t_node));
		(*s_list)->fd = fd;
	}
	head = (*s_list);
	while (*s_list != NULL)
	{
		if ((*s_list)->fd == fd)
			break ;
		if ((*s_list)->next == NULL)
		{
			(*s_list)->next = (t_node*)ft_memalloc(sizeof(t_node));
			(*s_list) = (*s_list)->next;
			(*s_list)->fd = fd;
			break ;
		}
		(*s_list) = (*s_list)->next;
	}
	tmp = (*s_list);
	(*s_list) = head;
	return (tmp);
}

static	char	*ft_join(char *s1, char *s2)
{
	char	*tmp;
	char	*res;

	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	if (!(tmp = ft_memalloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	res = tmp;
	while (*s1)
		*tmp++ = *s1++;
	while (*s2)
		*tmp++ = *s2++;
	*tmp = '\0';
	return (res);
}

static	char	*ft_read_from_buff(t_node *list)
{
	char	*tmp;
	char	*res;

	tmp = ft_memalloc(list->rs + 1);
	res = tmp;
	while (list->i < list->rs)
	{
		if (list->buff[list->i] == '\n')
			break ;
		*tmp++ = list->buff[list->i++];
	}
	return (res);
}

static	void	ft_read(t_node *list, char **line)
{
	char	*tmp;
	char	*tmp1;

	while ((list->rs = read(list->fd, list->buff, BUFF_SIZE)) > 0)
	{
		list->i = 0;
		tmp = ft_read_from_buff(list);
		tmp1 = *line;
		*line = ft_join(*line, tmp);
		free(tmp);
		free(tmp1);
		if (ft_strchr(list->buff, '\n'))
			break ;
	}
}

int				get_next_line(const int fd, char **line)
{
	static t_node	*s_list;
	t_node			*list;
	char			*tmp;

	if ((fd < 0 || !line || BUFF_SIZE < 0))
		return (-1);
	list = ft_find_fd(&s_list, fd);
	*line = ft_strnew(0);
	if (list->i < list->rs)
	{
		list->i++;
		tmp = *line;
		*line = ft_read_from_buff(list);
		free(tmp);
	}
	if (list->i >= list->rs)
		ft_read(list, line);
	if (!list->rs && (!*line || ft_strcmp(*line, "") == 0))
		return (0);
	if (list->rs == -1)
		return (-1);
	return (1);
}
