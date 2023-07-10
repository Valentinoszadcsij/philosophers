/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 23:30:36 by voszadcs          #+#    #+#             */
/*   Updated: 2023/07/10 15:05:52 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*thr_func(void *arg)
{
	t_thread_dt		*dt;
	struct timeval	time;
	int				ind;

	dt = arg;
	ind = dt->index;
	while (dt->end_threads == 0)
	{
		gettimeofday(&time, NULL);
		if (dt->main_s->philo[ind].state == EAT)
		{
			printf("Philosofer %d is eating! Time: %ld\n", ind + 1, (time.tv_sec * 1000 + time.tv_usec / 1000) - dt->main_s
				->start_time);
			sleeping(dt->main_s->params->time_eat);
			dt->main_s->philo[ind].state = THINK;
		}
		else if (dt->main_s->philo[ind].state == THINK)
		{
			printf("Philosofer %d is thinking! Time: %ld\n", ind + 1, (time.tv_sec * 1000 + time.tv_usec / 1000) - dt->main_s
				->start_time);
			sleeping(dt->main_s->params->time_die);
			dt->main_s->philo[ind].state = EAT;
		}
		// else if (dt->main_s->philo[ind].state == SLEEP)
		// {
		// 	printf("Philosofer %d is thinking! Time: %ld\n", ind + 1, (time.tv_sec * 1000 + time.tv_usec / 1000) - dt->main_s
		// 		->start_time);
		// 	usleep(dt->main_s->philo[ind].params->time_sleep);
		// 	dt->main_s->philo[ind].state = THINK;
		// }
	}
	return (NULL);
}
