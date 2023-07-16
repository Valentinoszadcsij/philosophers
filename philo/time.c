/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:17:45 by voszadcs          #+#    #+#             */
/*   Updated: 2023/07/16 20:19:30 by voszadcs         ###   ########.fr       */
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

void	sleeping(int s, t_thread_dt *dt)
{
	unsigned long	target;
	unsigned long	start_usec;
	target = s * 1000;
	start_usec = time_init() * 1000;
	while((time_init() * 1000 - start_usec) < target)
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
		usleep(10);
	}
}

// int main()
// {
// 	long int time = time_init();
// 	printf("%ld\n", time);
// 	return (0);
// }