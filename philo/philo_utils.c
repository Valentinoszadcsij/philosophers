/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 18:34:43 by voszadcs          #+#    #+#             */
/*   Updated: 2023/07/24 09:16:49 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long	time_init(void)
{
	struct timeval	cur_epoch;
	unsigned long		current;

	gettimeofday(&cur_epoch, NULL);
	current = (cur_epoch.tv_usec / 1000 + cur_epoch.tv_sec * 1000);
	return (current);
}

void	sleeping(unsigned long s, t_thread_dt *dt)
{
	unsigned long	start_msec;
	start_msec = time_init();

    while (!(check_death(dt) || time_init() - start_msec >= s))
	    usleep(100);
}

int check_death(t_thread_dt *dt)
{
    pthread_mutex_lock(&dt->main_s->end_mutex);
    if (time_init() - dt->main_s->philo[dt->index].last_meal_time >= dt->main_s->params->time_die)
    {       
        dt->main_s->end_threads = 1;
    }
    if (dt->main_s->end_threads == 1)
    {
        pthread_mutex_unlock(&dt->main_s->end_mutex);
        return (1);
    }
    pthread_mutex_unlock(&dt->main_s->end_mutex);
    return (0);
}

int check_times_ate(t_thread_dt *dt)
{
    unsigned long   i;
    unsigned long   total;

    i = 0;
    total = 0;
    while (i < dt->main_s->params->num_philo)
    {
        if (dt->main_s->philo[i].times_eat >= dt->main_s->params->must_eat)
            total++;
		i++;
    }
	if (total == dt->main_s->params->num_philo)
		return (1);
	return (0);
}
