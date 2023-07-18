/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 23:30:36 by voszadcs          #+#    #+#             */
/*   Updated: 2023/07/18 01:21:13 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
int	f_eat(t_thread_dt *dt)
{
	dt->main_s->philo[dt->index].last_meal_time = 0;
	//printf("LAST MEAL TIME FOR PHILO %lu ==  %lu\n", dt->index + 1, dt->main_s->philo[dt->index].last_meal_time);
	pthread_mutex_lock(dt->main_s->philo[dt->index].fork_l);
	printf("%ld %lu has taken a fork\n", time_init() - dt->main_s->start_time, dt->index + 1);
	pthread_mutex_lock(dt->main_s->philo[dt->index].fork_r);
	printf("%ld %lu has taken a fork\n", time_init() - dt->main_s->start_time, dt->index + 1);
	printf("%ld %lu is eating\n", time_init() - dt->main_s->start_time, dt->index + 1);
	if (sleeping(dt->main_s->params->time_eat, dt) == 1)
		return (1);
	pthread_mutex_unlock(dt->main_s->philo[dt->index].fork_l);
	pthread_mutex_unlock(dt->main_s->philo[dt->index].fork_r);
	dt->main_s->philo[dt->index].state = SLEEP;
	return (0);
}

int	f_sleep(t_thread_dt *dt)
{
	dt->main_s->philo[dt->index].last_meal_time = dt->main_s->params->time_sleep;	
	printf("%ld %lu is sleeping\n", time_init() - (dt->main_s->start_time), dt->index + 1);
	if (sleeping(dt->main_s->params->time_sleep, dt) == 1)
		return (1);
	dt->main_s->philo[dt->index].state = THINK;
	return (0);
}
int	f_think(t_thread_dt *dt)
{
	printf("%ld %lu is thinking\n", time_init() - dt->main_s->start_time, dt->index + 1);
	if (sleeping(dt->main_s->params->time_eat, dt) == 1)
		return (1);
	// if (dt->main_s->end_threads == 1)
	// 	return (pthread_mutex_unlock(&dt->main_s->end_mutex), dt->index + 1);
	// pthread_mutex_unlock(&dt->main_s->end_mutex);
	return (0);
}

void	*thr_func(void *arg)
{
	t_thread_dt		*dt;

	unsigned long check;
	dt = arg;
	while (1)
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
		if (dt->main_s->philo[dt->index].state == EAT)
		{
			if (f_eat(dt) == 1)
				break;
		}
		else if (dt->main_s->philo[dt->index].state == SLEEP)
		{
			if (f_sleep(dt) == 1)
				break;
		}
		else if (dt->main_s->philo[dt->index].state == THINK)
		{
			check = f_think(dt);
			if (check != 0)
			{
				if (check == 1)
					printf("Philosofer %lu has starved to death!\n", dt->index + 1);
				break;
			}
			else
			{	
				//printf("PHILO %lu OUT OF THINKING STATE at %lu\n", dt->index + 1, time_init() - dt->main_s->start_time);
				dt->main_s->philo[dt->index].state = EAT;
			}
		}
	}
	return (NULL);
}
