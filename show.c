/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhrypko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 15:43:25 by ikhrypko          #+#    #+#             */
/*   Updated: 2019/05/16 15:43:26 by ikhrypko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	show_rooms(void)
{
	int i;
	int j;

	i = -1;
	while (++i < g_rms->i)
	{
		ft_printf("\e[1;35mRoom %d\n\e[0m", i + 1);
		ft_printf("\e[1;32mName %s  \e[0m", g_rms->rooms[i]->name);
		ft_printf("\e[1;32mx = %d \e[0m", g_rms->rooms[i]->x);
		ft_printf("\e[1;32my = %d  \n\e[0m", g_rms->rooms[i]->y);
		j = -1;
		while (++j < g_rms->rooms[i]->links->i)
			ft_printf("\e[1;36mlink %d > %s  \n\e[0m",
				j + 1, g_rms->rooms[i]->links->rooms[j]->name);
		ft_printf("\n");
	}
}

void	show_path(void)
{
	int i;
	int j;

	i = -1;
	while (++i < g_path->i)
	{
		j = -1;
		ft_printf("\e[1;34mpath %d\e[0m \e[1;37mlength = %d\n\e[0m",
			i + 1, g_path->path[i]->i);
		while (++j < g_path->path[i]->i)
			ft_printf("\e[1;33m%s \e[0m", g_path->path[i]->rooms[j]->name);
		ft_printf("\n--------------------------------------\n");
	}
}

void	show_stat(void)
{
	ft_printf("\n\e[1;32mStart room\n\e[0m");
	ft_printf("\e[1;38mName %s  \e[0m", g_start->name);
	ft_printf("\e[1;38mx = %d \e[0m", g_start->x);
	ft_printf("\e[1;38my = %d  \n\e[0m", g_start->y);
	ft_printf("\n\e[1;31mEnd room\n\e[0m");
	ft_printf("\e[1;38mName %s  \e[0m", g_end->name);
	ft_printf("\e[1;38mx = %d \e[0m", g_end->x);
	ft_printf("\e[1;38my = %d  \n\e[0m", g_end->y);
	ft_printf("\e[1;33m\nMy number of lines = %d\n\e[0m", g_my_stat);
	ft_printf("\e[1;33mRequired number of lines = %d\n\e[0m", g_req_stat);
}

void	show(void)
{
	if (g_opt.r)
		show_rooms();
	if (g_opt.p)
		show_path();
	if (g_opt.s)
		show_stat();
}
