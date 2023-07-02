/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:17:45 by voszadcs          #+#    #+#             */
/*   Updated: 2023/06/29 18:43:33 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "philo.h"
#include <stdio.h>
#include <sys/time.h>

long int	time_init(void)
{
	struct timeval	cur_epoch;
	long int		zero;

	gettimeofday(&cur_epoch, NULL);
	zero = (cur_epoch.tv_usec / 1000 + cur_epoch.tv_sec * 1000);
	return (zero);
}

int main()
{
	long int time = time_init();
	printf("%ld\n", time);
	return (0);
}