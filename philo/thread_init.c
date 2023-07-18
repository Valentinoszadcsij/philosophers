/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 17:38:58 by voszadcs          #+#    #+#             */
/*   Updated: 2023/07/18 00:53:32 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

void	philo_init(t_main *main_s)
{
	unsigned long			i;
	t_thread_dt	*thread_dt;

	thread_dt = malloc(sizeof(t_thread_dt) * main_s->params->num_philo);
	pthread_mutex_init(&main_s->end_mutex, NULL);
	i = 0;
	while (i < (main_s->params->num_philo))
	{
		main_s->philo[i].num = i + 1;
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
		if (i % 2 == 0)
		{	
			main_s->philo[i].state = EAT;
		}
		else
		{	
			main_s->philo[i].state = THINK;
			//usleep(10);
		}
		main_s->philo[i].times_eat = 0;
		thread_dt[i].index = i;
		thread_dt[i].main_s = main_s;
		thread_dt[i].main_s->end_threads = 0;
		main_s->start_time = time_init();
		main_s->philo[i].last_meal_time = 0;
		if (pthread_create(&main_s->philo[i].one_ph, NULL, thr_func, &thread_dt[i]) != 0)
		{
			// free(philo);
			// free(params);
			errors(EXIT_THREAD_FAIL);
		}
		i++;
	}
}

void	thread_init(t_params *params)
{
	unsigned long		i;
	t_main	main_s;

	main_s.philo = malloc(sizeof(t_philo) * params->num_philo);
	i = 0;
	main_s.params = params;
	main_s.forks = fork_init(params->num_philo);
	philo_init(&main_s);
	while (i < params->num_philo)
	{	
		pthread_join(main_s.philo[i].one_ph, NULL);
		i++;
	}
}
