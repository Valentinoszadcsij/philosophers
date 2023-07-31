/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 18:34:43 by voszadcs          #+#    #+#             */
/*   Updated: 2023/07/30 12:43:49 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long	time_init(void)
{
	struct timeval	cur_epoch;
	unsigned long	current;

	gettimeofday(&cur_epoch, NULL);
	current = (cur_epoch.tv_usec / 1000 + cur_epoch.tv_sec * 1000);
	return (current);
}

void	sleeping(unsigned long s)
{
	unsigned long	start_msec;

	start_msec = time_init();
    
	while (time_init() - start_msec < s)
		usleep(100);
}

