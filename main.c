/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhrypko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 11:50:03 by ikhrypko          #+#    #+#             */
/*   Updated: 2019/03/12 11:50:04 by ikhrypko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main(int ac, char **av)
{
	char	*line;

	line = NULL;
	alloc_p();
	if (ac > 1)
		parse_opt(ac, av);
	while (get_next_line(0, &line) > 0)
	{
		valid(line);
		array_writ(g_fil, line);
		ft_writ(line);
	}
	if (!g_start || !g_end)
		errorchik("Error Missing start/end", 0);
	bfs();
	!g_opt.q ? print_file() : 0;
	move_ants();
	show();
	system("leaks -q lem-in");
}
