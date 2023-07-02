/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 19:11:52 by voszadcs          #+#    #+#             */
/*   Updated: 2023/06/26 17:24:08 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


// void	*do_smth(void *arg)
// {
// 	pthread_mutex_t *lock;

// 	lock = (pthread_mutex_t*)arg;
// 	pthread_mutex_lock(lock);
// 	count++;
// 	printf("Value : %d\n", count);
// 	pthread_mutex_unlock(lock);
// 	//pthread_mutex_destroy(&lock);
	
// 	return (NULL);
// }

int	main(int argc, char *argv[])
{
	t_params	params;

	parse(argc, argv, &params);
	thread_init(&params);
	// pthread_mutex_init(&lock, NULL);

	// philo = malloc(sizeof(pthread_t) * 8);
	// while (i < 8)
	// {
	// 	err = pthread_create(&philo[i], NULL, do_smth, (void *)&lock);
	// 	if (err != 0)
	// 		return (printf("Error: couldnt create thread"), -1);
	// 	i++;
	// }
	// i = 0;
	// while (i < 8)
	// {	
	// 	pthread_join(philo[i], NULL);
	// 	i++;
	// }
	return (0);
}