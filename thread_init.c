/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 17:38:58 by voszadcs          #+#    #+#             */
/*   Updated: 2023/07/10 03:29:50 by voszadcs         ###   ########.fr       */
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
	int			i;
	t_thread_dt	*thread_dt;

	thread_dt = malloc(sizeof(thread_dt) * main_s->philo->num);
	i = 0;
	while (i < (main_s->params->num_philo))
	{
		main_s->philo[i].num = i + 1;
		if (i % 2 == 0)
			main_s->philo[i].state = EAT;
		else
			main_s->philo[i].state = THINK;
		main_s->philo[i].times_eat = 0;
		main_s->start_time = time_init();
		thread_dt[i].index = i;
		thread_dt[i].main_s = main_s;
		thread_dt[i].end_threads = 0;
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
	int		i;
	t_main	main_s;

	main_s.philo = malloc(sizeof(t_philo) * params->num_philo);
	printf("In thread_init!\n");
	i = 0;
	main_s.params = params;
	main_s.philo->fork = fork_init(params->num_philo);
	printf("Exit fork_init!\n");
	philo_init(&main_s);
	printf("Exit philo_init!\n");
	while (i < params->num_philo)
	{	
		pthread_join(main_s.philo[i].one_ph, NULL);
		i++;
	}
}
