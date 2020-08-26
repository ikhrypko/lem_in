/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhrypko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 11:25:14 by ikhrypko          #+#    #+#             */
/*   Updated: 2019/05/08 11:25:16 by ikhrypko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		keksus(void)
{
	int i;

	i = -1;
	while (++i < g_path->i)
	{
		if (check_ants(g_path->path[i], 1) != -1)
			return (0);
	}
	return (1);
}

void	reverse_path(void)
{
	int		i;
	int		j;
	int		count;
	t_room	*tmp;

	i = -1;
	while (++i < g_path->i)
	{
		j = -1;
		count = g_path->path[i]->i;
		while (++j < count--)
		{
			tmp = g_path->path[i]->rooms[j];
			g_path->path[i]->rooms[j] = g_path->path[i]->rooms[count];
			g_path->path[i]->rooms[count] = tmp;
		}
	}
}

void	alloc_p(void)
{
	g_rms = alloc_arr(10, sizeof(t_rooms));
	g_path = alloc_arr(10, sizeof(t_path));
	g_q = alloc_arr(10, sizeof(t_rooms));
	g_fil = alloc_arr(10, sizeof(t_hlp));
}

void	print_file(void)
{
	int i;

	i = -1;
	while (++i < g_fil->i)
		ft_printf("%s\n", g_fil->str[i]);
	ft_printf("\n");
}

void	errorchik(char *str, int a)
{
	if (a)
		ft_printf("\e[1;31mError in line %d %s\n\e[0m", a, str);
	else
		ft_printf("\e[1;31m%s\n\e[0m", str);
	system("leaks -q lem-in");
	exit(1);
}
