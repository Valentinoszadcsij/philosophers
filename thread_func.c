/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 23:30:36 by voszadcs          #+#    #+#             */
/*   Updated: 2023/07/11 13:05:32 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*thr_func(void *arg)
{
	t_thread_dt		*dt;
	pthread_mutex_t	*fork_left;
	pthread_mutex_t	*fork_right;
	struct timeval	time;
	int				ind;

	dt = arg;
	ind = dt->index;
	if (ind = dt->main_s->params->num_philo - 1)
	{
		fork_left = &dt->main_s->philo[ind].fork[0];
		fork_right = &dt->main_s->philo[ind].fork[ind];
	}
	else
	{
		fork_left = &dt->main_s->philo[ind].fork[ind + 1];
		fork_right = &dt->main_s->philo[ind].fork[ind];
	}
	while (dt->end_threads == 0)
	{
		gettimeofday(&time, NULL);
		if (dt->main_s->philo[ind].state == EAT)
		{
			printf("Philosofer %d is eating! Time: %ld\n", ind + 1, (time.tv_sec * 1000 + time.tv_usec / 1000) - (dt->main_s
				->start_time));
			sleeping(dt->main_s->params->time_eat);
			dt->main_s->philo[ind].state = THINK;
		}
		else if (dt->main_s->philo[ind].state == THINK)
		{
			printf("Philosofer %d is thinking! Time: %ld\n", ind + 1, (time.tv_sec * 1000 + time.tv_usec / 1000) - (dt->main_s
				->start_time));
			sleeping(dt->main_s->params->time_die);
			dt->main_s->philo[ind].state = EAT;
		}
	}
	return (NULL);
}
