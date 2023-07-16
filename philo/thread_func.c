/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 23:30:36 by voszadcs          #+#    #+#             */
/*   Updated: 2023/07/16 20:19:09 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
void	f_eat(t_thread_dt *dt, unsigned long cycle_start)
{
	pthread_mutex_lock(dt->main_s->philo[dt->index].fork_l);
	printf("%ld %lu has taken a fork\n", cycle_start - dt->main_s->start_time, dt->index + 1);
	pthread_mutex_lock(dt->main_s->philo[dt->index].fork_r);
	printf("%ld %lu has taken a fork\n", cycle_start - dt->main_s->start_time, dt->index + 1);
	printf("%ld %lu is eating\n", cycle_start - dt->main_s->start_time, dt->index + 1);
	sleeping(dt->main_s->params->time_eat, dt);
	pthread_mutex_unlock(dt->main_s->philo[dt->index].fork_l);
	pthread_mutex_unlock(dt->main_s->philo[dt->index].fork_r);

	dt->main_s->philo[dt->index].state = SLEEP;	
}

void	f_sleep(t_thread_dt *dt, unsigned long cycle_start)
{
	printf("%ld %lu is sleeping\n", cycle_start - (dt->main_s->start_time), dt->index + 1);
	sleeping(dt->main_s->params->time_sleep, dt);
	dt->main_s->philo[dt->index].state = THINK;
}
void	f_think(t_thread_dt *dt, unsigned long cycle_start)
{
	printf("%ld %lu is thinking\n", cycle_start - dt->main_s->start_time, dt->index + 1);
	if (dt->main_s->params->time_die  < dt->main_s->params->time_eat + dt->main_s->params->time_sleep)
	{	
		sleeping(dt->main_s->params->time_die, dt);
		pthread_mutex_lock(&dt->main_s->end_mutex);
		dt->main_s->end_threads = 1;
		pthread_mutex_unlock(&dt->main_s->end_mutex);
		printf("Philosofer %lu has starved to death!\n", dt->index + 1);
	}
	else
	{
		sleeping(dt->main_s->params->time_eat, dt);
		dt->main_s->philo[dt->index].state = EAT;
	}
}

void	*thr_func(void *arg)
{
	t_thread_dt		*dt;
	unsigned long	cycle_start;

	dt = arg;
	while (2)
	{
		pthread_mutex_lock(&dt->main_s->end_mutex);
		if (dt->main_s->end_threads == 1)
		{
			pthread_mutex_unlock(&dt->main_s->end_mutex);
			pthread_mutex_unlock(dt->main_s->philo[dt->index].fork_l);
			pthread_mutex_unlock(dt->main_s->philo[dt->index].fork_r);
			break;
		}
		pthread_mutex_unlock(&dt->main_s->end_mutex);
		cycle_start = time_init();
		if (dt->main_s->philo[dt->index].state == EAT)
			f_eat(dt, cycle_start);
		else if (dt->main_s->philo[dt->index].state == SLEEP)
			f_sleep(dt, cycle_start);
		else if (dt->main_s->philo[dt->index].state == THINK)
			f_think(dt, cycle_start);
	}
	return (NULL);
}
