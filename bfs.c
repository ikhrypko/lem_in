/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhrypko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 19:36:28 by ikhrypko          #+#    #+#             */
/*   Updated: 2019/05/15 19:36:30 by ikhrypko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	filling_q(t_room *a)
{
	int i;

	i = -1;
	a->vis = 'v';
	while (++i < a->links->i)
	{
		if (!a->links->rooms[i]->par && !a->links->rooms[i]->vis &&
			!a->links->rooms[i]->blocked)
		{
			a->links->rooms[i]->par = a;
			array_writ(g_q, a->links->rooms[i]);
		}
	}
}

void	help_bfs(void)
{
	int i;

	i = 0;
	while (++i <= g_ants)
		ft_printf("L%d-%s ", i, g_end->name);
	ft_printf("\n");
	exit(1);
}

void	block_path(int *i)
{
	t_room	*tmp;
	t_room	*room;
	t_rooms	*p;

	p = alloc_arr(5, sizeof(t_rooms));
	room = find_room(g_q, g_end->name);
	if (room->par->type == 's')
		help_bfs();
	while (1)
	{
		if (room->type == 's')
			break ;
		if (room->type != 'e')
		{
			array_writ(p, room);
			room->blocked = 'b';
		}
		tmp = room;
		room = room->par;
	}
	array_writ(g_path, p);
	free_vis();
	*i = -1;
}

void	bfs(void)
{
	int i;

	array_writ(g_q, find_room(g_rms, g_start->name));
	i = -1;
	while (++i < g_q->i)
	{
		filling_q(g_q->rooms[i]);
		if (g_q->rooms[i]->type == 'e')
			block_path(&i);
	}
	if (!g_path->i)
		errorchik("Error No paths were found", 0);
	reverse_path();
}
