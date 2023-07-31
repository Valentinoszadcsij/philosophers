/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 14:25:50 by voszadcs          #+#    #+#             */
/*   Updated: 2023/06/24 14:45:36 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int a)
{
	if (a >= 48 && a <= 57)
		return (0);
	else
		return (-1);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		res;
	int		sign;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		else if ((str[i + 1] == '-' || str[i + 1] == '+'))
			return (0);
		i++;
	}
	while (str[i] != '\0' && ft_isdigit(str[i]) == 0)
	{
		res = res * 10 + (str[i] % 48);
		i++;
	}
	return (res * sign);
}