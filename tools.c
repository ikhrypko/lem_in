/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhrypko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 11:14:41 by ikhrypko          #+#    #+#             */
/*   Updated: 2019/05/08 11:14:43 by ikhrypko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		free_str(char **str)
{
	int i;

	i = -1;
	while (str[++i])
		ft_strdel(&str[i]);
	free(str);
}

int			count_spl(char **str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

t_room		*find_room(t_rooms *r, char *name)
{
	int i;

	i = -1;
	while (++i < r->i)
	{
		if (ft_strcmp(r->rooms[i]->name, name) == 0)
			return (r->rooms[i]);
	}
	return (NULL);
}

int			find_par(char *name)
{
	int i;

	i = -1;
	while (++i < g_q->i)
	{
		if (ft_strcmp(g_q->rooms[i]->name, name) == 0)
			return (i);
	}
	return (0);
}

void		free_vis(void)
{
	int i;

	i = -1;
	while (++i < g_q->i)
	{
		g_q->rooms[i]->vis = '\0';
		g_q->rooms[i]->par = NULL;
	}
	g_q->i = 1;
}
