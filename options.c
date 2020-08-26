/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhrypko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 16:42:10 by ikhrypko          #+#    #+#             */
/*   Updated: 2019/05/16 16:42:11 by ikhrypko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	error_invalid(char str)
{
	if (!ft_strchr(VALID, str))
	{
		ft_printf("lem-in: illegal option -- %c\n", str);
		ft_printf("usage : \n");
		ft_printf("-q quite mode\n");
		ft_printf("-r show rooms, links\n");
		ft_printf("-p show paths\n");
		ft_printf("-s show statistic\n");
		exit(0);
	}
}

void	parse_flags(char *str)
{
	int		i;

	i = 0;
	while ((ft_strchr(VALID, str[++i]) && str[i]))
	{
		(str[i] == 'q') ? g_opt.q = 1 : 0;
		(str[i] == 'r') ? g_opt.r = 1 : 0;
		(str[i] == 'p') ? g_opt.p = 1 : 0;
		(str[i] == 's') ? g_opt.s = 1 : 0;
	}
	error_invalid(str[i]);
}

void	parse_opt(int ac, char **av)
{
	int i;

	i = 1;
	while (i < ac)
	{
		if (av[i][0] == '-')
			parse_flags(av[i++]);
		else
			break ;
	}
}
