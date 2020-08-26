/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhrypko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 18:00:57 by ikhrypko          #+#    #+#             */
/*   Updated: 2019/05/10 18:00:59 by ikhrypko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	moove(t_rooms *p)
{
	int		i;

	i = p->i;
	while (i--)
	{
		if (p->rooms[i]->aant)
		{
			if (i + 1 == p->i)
				!g_opt.q ?
			ft_printf("L%d-%s ", p->rooms[i]->aant, g_end->name) : 0;
			else
			{
				p->rooms[i + 1]->aant = p->rooms[i]->aant;
				!g_opt.q ? ft_printf("L%d-%s ", p->rooms[i + 1]->aant,
					p->rooms[i + 1]->name) : 0;
			}
			p->rooms[i]->aant = 0;
		}
	}
}

void	move_ants(void)
{
	int i;
	int j;
	int ant;

	g_sum = 0;
	ant = g_ants;
	i = 0;
	while (1)
	{
		j = -1;
		while (++j < g_path->i)
		{
			if (check_ants(g_path->path[j], 0) >= 0)
				moove(g_path->path[j]);
			if (ant > expr(j) && check_ants(g_path->path[j], 0))
			{
				add_ant(g_path->path[j]->rooms[0]);
				ant--;
			}
		}
		!g_opt.q ? ft_printf("\n") : 0;
		if (i++ && keksus())
			break ;
	}
	g_my_stat = i;
}

int		check_ants(t_rooms *p, int a)
{
	int i;

	i = -1;
	while (++i < p->i)
	{
		if (p->rooms[i]->aant)
			return (i);
	}
	return (a == 1 ? -1 : 1);
}

int		expr(int j)
{
	int		sum;
	int		i;

	sum = 0;
	i = -1;
	while (++i < j)
		sum += g_path->path[j]->i - g_path->path[i]->i;
	return (sum);
}

void	add_ant(t_room *p)
{
	g_sum++;
	p->aant = g_sum;
	!g_opt.q ? ft_printf("L%d-%s ", g_sum, p->name) : 0;
}
