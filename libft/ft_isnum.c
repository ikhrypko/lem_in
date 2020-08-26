/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhrypko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 18:21:33 by ikhrypko          #+#    #+#             */
/*   Updated: 2019/04/24 18:21:35 by ikhrypko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isnum(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	if (ft_isdigit(str[0]) || str[0] == '-' || str[0] == '+')
	{
		while (str[++i])
		{
			if (!ft_isdigit(str[i]))
				return (0);
		}
	}
	else
		return (0);
	return (1);
}
