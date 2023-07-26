/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 23:30:36 by voszadcs          #+#    #+#             */
/*   Updated: 2023/07/26 16:32:15 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
void	f_eat(t_thread_dt *dt)
{
	pthread_mutex_lock(dt->main_s->philo[dt->index].fork_l);
	if (check_death(dt))
	{	
		pthread_mutex_unlock(dt->main_s->philo[dt->index].fork_l);
		return ;
	}
	pthread_mutex_lock(&dt->main_s->print_lock);
	printf("%ld %lu has taken a fork\n", time_init() - dt->main_s->start_time, dt->index + 1);
	pthread_mutex_unlock(&dt->main_s->print_lock);
	pthread_mutex_lock(dt->main_s->philo[dt->index].fork_r);
	if (check_death(dt))
	{	
		pthread_mutex_unlock(dt->main_s->philo[dt->index].fork_l);
		pthread_mutex_unlock(dt->main_s->philo[dt->index].fork_r);
		return ;
	}
	pthread_mutex_lock(&dt->main_s->print_lock);
	printf("%ld %lu has taken a fork\n", time_init() - dt->main_s->start_time, dt->index + 1);
	printf("%ld %lu is eating\n", time_init() - dt->main_s->start_time, dt->index + 1);
	pthread_mutex_unlock(&dt->main_s->print_lock);
	dt->main_s->philo[dt->index].last_meal_time = time_init();
	sleeping(dt->main_s->params->time_eat, dt);
	dt->main_s->philo[dt->index].times_eat++;
	pthread_mutex_unlock(dt->main_s->philo[dt->index].fork_l);
	pthread_mutex_unlock(dt->main_s->philo[dt->index].fork_r);
}

void	f_sleep(t_thread_dt *dt)
{
	pthread_mutex_lock(&dt->main_s->print_lock);
	printf("%ld %lu is sleeping\n", time_init() - (dt->main_s->start_time), dt->index + 1);
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
			printf("%lu %lu is thinking\n", time_init() - dt->main_s->start_time, dt->index + 1);
			pthread_mutex_unlock(&dt->main_s->print_lock);
			sleeping(dt->main_s->params->time_eat, dt);
		}
		else if (time_init() - dt->main_s->start_time > 10)
		{	
			pthread_mutex_lock(&dt->main_s->print_lock);
			printf("%lu %lu is thinking\n", time_init() - dt->main_s->start_time, dt->index + 1);
			pthread_mutex_unlock(&dt->main_s->print_lock);
		}
		f_eat(dt);
		if (!check_death(dt))
			f_sleep(dt);
	}
	return (NULL);
}
