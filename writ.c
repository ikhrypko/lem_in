/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writ.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhrypko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 19:12:28 by ikhrypko          #+#    #+#             */
/*   Updated: 2019/04/30 19:12:31 by ikhrypko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	writ_links(char *line)
{
	char	**s;
	t_room	*l1;
	t_room	*l2;

	l1 = NULL;
	l2 = NULL;
	s = ft_strsplit(line, '-');
	if (count_spl(s) == 2)
	{
		l1 = find_room(g_rms, s[0]);
		l2 = find_room(g_rms, s[1]);
		if (l1 && l2)
		{
			array_writ(l1->links, l2);
			array_writ(l2->links, l1);
		}
		else
			errorchik("Error room doesn't exists", 0);
	}
	free_str(s);
}

void	writ_type(t_room *room)
{
	if (g_t == 1)
	{
		room->type = 's';
		g_start = ft_memalloc(sizeof(t_room));
		ft_memcpy(g_start, room, sizeof(t_room));
	}
	else if (g_t == 2)
	{
		room->type = 'e';
		g_end = ft_memalloc(sizeof(t_room));
		ft_memcpy(g_end, room, sizeof(t_room));
	}
	else
		room->type = 'm';
	g_t = 0;
}

void	ft_writ(char *line)
{
	char		**str;
	t_room		*room;

	str = ft_strsplit(line, ' ');
	ft_strcmp(line, "##start") == 0 ? g_t = 1 : 0;
	ft_strcmp(line, "##end") == 0 ? g_t = 2 : 0;
	if (count_spl(str) == 3)
	{
		room = ft_memalloc(sizeof(t_room));
		room->name = ft_strdup(str[0]);
		if (ft_isnum(str[1]) && ft_isnum(str[2]))
		{
			room->x = ft_atoi(str[1]);
			room->y = ft_atoi(str[2]);
			if (!check_coords(room))
				errorchik("Error Room with same name/coords already exists", 0);
			writ_type(room);
		}
		room->links = alloc_arr(2, sizeof(t_rooms));
		array_writ(g_rms, room);
	}
	writ_links(line);
	free_str(str);
}
