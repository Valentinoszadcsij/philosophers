/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:17:45 by voszadcs          #+#    #+#             */
/*   Updated: 2023/07/18 01:30:34 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "philo.h"
#include "philo.h"

unsigned long	time_init(void)
{
	struct timeval	cur_epoch;
	unsigned long		current;

	gettimeofday(&cur_epoch, NULL);
	current = (cur_epoch.tv_usec / 1000 + cur_epoch.tv_sec * 1000);
	return (current);
}

int	sleeping(unsigned int s, t_thread_dt *dt)
{
	unsigned long	start_msec;
	start_msec = time_init();
	unsigned long counter;

	counter = 0;
	while((time_init() - start_msec) < s)
	{
		if (dt->main_s->end_threads == 1)
		{
			//printf("INSIDE SLEEPING CHECK PHILO %lu\n", dt->index + 1);
			pthread_mutex_unlock(&dt->main_s->end_mutex);
			pthread_mutex_unlock(dt->main_s->philo[dt->index].fork_l);
			pthread_mutex_unlock(dt->main_s->philo[dt->index].fork_r);
			return (1);
		}
		if (dt->main_s->philo[dt->index].last_meal_time >= dt->main_s->params->time_die && dt->main_s->philo[dt->index].state == THINK)
		{	
			//printf("INSIDE SLEEPING SET PHILO %lu\n Time passed: %lu\n", dt->index + 1, dt->main_s->philo[dt->index].last_meal_time);
			pthread_mutex_lock(&dt->main_s->end_mutex);
			dt->main_s->end_threads = 1;
			pthread_mutex_unlock(&dt->main_s->end_mutex);
			return (1);
		}
		pthread_mutex_lock(&dt->main_s->end_mutex);
		pthread_mutex_unlock(&dt->main_s->end_mutex);
		counter += 10;
		if (counter == 1000)
		{
			counter = 1;
			dt->main_s->philo[dt->index].last_meal_time++;
		}
		usleep(10);
	}
	return (0);
}

// int main()
// {
// 	long int time = time_init();
// 	printf("%ld\n", time);
// 	return (0);
// }