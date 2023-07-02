/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 17:38:58 by voszadcs          #+#    #+#             */
/*   Updated: 2023/06/29 15:49:25 by voszadcs         ###   ########.fr       */
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

void	philo_init(t_params *params, t_philo *philo)
{
	int		i;

	i = 0;
	while (i < (params->num_philo))
	{
		philo[i].num = i + 1;
		philo[i].state = THINK;
		philo[i].times_eat = 0;
		if (pthread_create(&philo[i].one_ph, NULL, thr_func, &philo[i]) != 0)
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
	t_philo	*philo;

	philo = malloc(sizeof(t_philo) * params->num_philo);
	printf("In thread_init!\n");
	i = 0;
	philo->params = params;
	philo->fork = fork_init(params->num_philo);
	printf("Exit fork_init!\n");
	philo_init(params, philo);
	printf("Exit philo_init!\n");
	while (i < params->num_philo)
	{	
		pthread_join(philo[i].one_ph, NULL);
		i++;
	}
}
