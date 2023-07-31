/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 23:30:36 by voszadcs          #+#    #+#             */
/*   Updated: 2023/07/30 12:40:39 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	message(int i, t_thread_dt *dt)
{
	if (i == 1)
	{
		pthread_mutex_lock(&dt->main_s->print_lock);
		printf("%lu %lu has taken a fork\n", time_init() - dt->main_s
			->start_time, dt->index + 1);
		pthread_mutex_unlock(&dt->main_s->print_lock);
	}
	else if (i == 2)
	{
		pthread_mutex_lock(&dt->main_s->print_lock);
		printf("%lu %lu has taken a fork\n", time_init() - dt->main_s
			->start_time, dt->index + 1);
		printf("%lu %lu is eating\n", time_init() - dt->main_s
			->start_time, dt->index + 1);
		pthread_mutex_unlock(&dt->main_s->print_lock);
	}
}

void	f_eat(t_thread_dt *dt)
{
	pthread_mutex_lock(dt->main_s->philo[dt->index].fork_l);
	if (check_death(dt))
	{	
		pthread_mutex_unlock(dt->main_s->philo[dt->index].fork_l);
		return ;
	}
	message(1, dt);
	pthread_mutex_lock(dt->main_s->philo[dt->index].fork_r);
	if (check_death(dt))
	{	
		pthread_mutex_unlock(dt->main_s->philo[dt->index].fork_l);
		pthread_mutex_unlock(dt->main_s->philo[dt->index].fork_r);
		return ;
	}
	message(2, dt);
	dt->main_s->philo[dt->index].last_meal_time = time_init();
	sleeping(dt->main_s->params->time_eat, dt);
	dt->main_s->philo[dt->index].times_eat++;
	pthread_mutex_unlock(dt->main_s->philo[dt->index].fork_l);
	pthread_mutex_unlock(dt->main_s->philo[dt->index].fork_r);
}

void	f_sleep(t_thread_dt *dt)
{
	pthread_mutex_lock(&dt->main_s->print_lock);
	printf("%lu %lu is sleeping\n", time_init() - (dt->main_s->start_time),
		dt->index + 1);
	pthread_mutex_unlock(&dt->main_s->print_lock);
	sleeping(dt->main_s->params->time_sleep, dt);
}

void	*thr_func(void *arg)
{
	t_thread_dt		*dt;

	dt = arg;
	while (check_death(dt) != 1)
	{
		if (time_init() - dt->main_s->start_time < 10 && dt->index % 2 != 0)
		{	
			pthread_mutex_lock(&dt->main_s->print_lock);
			printf("%lu %lu is thinking\n", time_init() - dt->main_s->start_time,
				dt->index + 1);
			pthread_mutex_unlock(&dt->main_s->print_lock);
			sleeping(dt->main_s->params->time_eat, dt);
		}
		else if (time_init() - dt->main_s->start_time > 10)
		{	
			pthread_mutex_lock(&dt->main_s->print_lock);
			printf("%lu %lu is thinking\n", time_init() - dt->main_s->start_time,
				dt->index + 1);
			pthread_mutex_unlock(&dt->main_s->print_lock);
		}
		f_eat(dt);
		if (!check_death(dt))
			f_sleep(dt);
	}
	return (NULL);
}
