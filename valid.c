/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhrypko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 18:56:07 by ikhrypko          #+#    #+#             */
/*   Updated: 2019/05/15 18:56:08 by ikhrypko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	valid2(int n_str, char *line)
{
	char	**str;

	if (count_spl(str = ft_strsplit(line, '-')) == 2)
		ft_printf("");
	else if ((!ft_strcmp("##start", line) && g_start)
		|| (!ft_strcmp("##end", line) && g_end))
		errorchik("Wrong property(double start/end)", n_str);
	else if (ft_strstr(line, "Here is the number of lines required: ")
		&& !g_req_stat)
		g_req_stat = ft_atoi(line + 39);
	else if (ft_strcmp("##start", line) && ft_strcmp("##end", line) &&
		n_str > 1 && line && line[0] != '#')
		errorchik("Wrong data", n_str);
	free_str(str);
}

void	valid(char *line)
{
	static int	n_str = 0;
	char		**str;

	n_str++;
	if (n_str == 1 && (size_t)ft_get_str_len(ft_atoi(line)) == ft_strlen(line))
		g_ants = ft_atoi(line);
	if (n_str > 1 && (!g_ants || g_ants < 0 || g_ants > INT_MAX))
		errorchik("Wrong ants", n_str - 1);
	if (count_spl(str = ft_strsplit(line, ' ')) == 3)
	{
		if (!str[0] || str[0][0] == 'L' || !str[1] || !str[2] ||
			!ft_isnum(str[1]) || !ft_isnum(str[2]))
			errorchik("Wrong data", n_str);
	}
	else
		valid2(n_str, line);
	free_str(str);
}

int		check_coords(t_room *room)
{
	int i;

	i = -1;
	while (++i < g_rms->i)
	{
		if ((g_rms->rooms[i]->x == room->x && g_rms->rooms[i]->y == room->y)
			|| ft_strcmp(g_rms->rooms[i]->name, room->name) == 0)
			return (0);
	}
	return (1);
}

void	*alloc_arr(int count, int l)
{
	t_wr	*res;

	res = ft_memalloc(l);
	res->ptr = ft_memalloc(sizeof(void*) * count);
	res->length = count;
	return (res);
}

void	array_writ(void *ary, void *ptr)
{
	t_wr	*ary_tmp;
	void	**tmp;

	ary_tmp = ary;
	if (ary_tmp->i >= ary_tmp->length)
	{
		ary_tmp->length *= 3;
		tmp = ft_memalloc(sizeof(void*) * ary_tmp->length);
		ft_memcpy(tmp, ary_tmp->ptr, sizeof(void*) * ary_tmp->i);
		free(ary_tmp->ptr);
		ary_tmp->ptr = tmp;
	}
	ary_tmp->ptr[ary_tmp->i++] = ptr;
}
