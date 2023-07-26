/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 17:38:58 by voszadcs          #+#    #+#             */
/*   Updated: 2023/07/26 15:17:48 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	main_s_init(t_main *main_s, unsigned long i)
{
	if (i == 0)
	{
		pthread_mutex_init(&main_s->end_mutex, NULL);
		pthread_mutex_init(&main_s->print_lock, NULL);
		main_s->end_threads = 0;
		main_s->start_time = time_init();
	}
	if (i == main_s->params->num_philo - 1)
	{
		main_s->philo[i].fork_r = &main_s->forks[i];
		main_s->philo[i].fork_l = &main_s->forks[0];
	}
	else
	{			
		main_s->philo[i].fork_r = &main_s->forks[i];
		main_s->philo[i].fork_l = &main_s->forks[i + 1];
	}
	main_s->philo[i].times_eat = 0;
	main_s->philo[i].last_meal_time = time_init();
}

int	controller(t_thread_dt *dt)
{
	if (check_death(dt))
	{
		printf("%lu %lu has died\n", time_init() - dt->main_s->start_time, dt->index + 1);
		return (1);
	}
	if (dt->main_s->params->must_eat)
	{
		if (check_times_ate(dt))
		{
			pthread_mutex_lock(&dt->main_s->end_mutex);
			dt->main_s->end_threads = 1;
			pthread_mutex_unlock(&dt->main_s->end_mutex);
			return (1);
		}
	}
	return (0);
}

pthread_mutex_t	*fork_init(int n)
{
	int				i;
	pthread_mutex_t	*fork;

	i = 0;
	fork = malloc(sizeof(pthread_mutex_t) * n);
	while (i < n)
	{
		pthread_mutex_init(&fork[i], NULL);
		i++;
	}
	return (fork);
}

void	philo_init(t_thread_dt *thread_dt)
{
	unsigned long	i;
	
	i = 0;
	while (i < (thread_dt->main_s->params->num_philo))
	{
		thread_dt[i].index = i;
		thread_dt[i].main_s = thread_dt->main_s;
		main_s_init(thread_dt->main_s, i);
		if (pthread_create(&thread_dt->main_s->philo[i].one_ph, NULL, thr_func, &thread_dt[i]) != 0)
		{
			errors(EXIT_THREAD_FAIL);
		}
		i++;
	}
	i = -1;
	while (!controller(&thread_dt[++i]))
	{
		if (i == thread_dt->main_s->params->num_philo - 1)
			i = -1;
	}
}

void	thread_init(t_params *params)
{
	unsigned long			i;
	t_main				main_s;
	t_thread_dt		*thread_dt;

	thread_dt = malloc(sizeof(t_thread_dt) * params->num_philo);
	thread_dt->main_s = &main_s;
	main_s.philo = malloc(sizeof(t_philo) * params->num_philo);
	i = 0;
	main_s.params = params;
	main_s.forks = fork_init(params->num_philo);
	philo_init(thread_dt);
	while (i < params->num_philo)
	{	
		pthread_join(main_s.philo[i].one_ph, NULL);
		i++;
	}
	free(main_s.philo);
	free(thread_dt);
	free(main_s.forks);
}
