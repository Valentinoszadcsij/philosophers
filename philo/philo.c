/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 19:11:52 by voszadcs          #+#    #+#             */
/*   Updated: 2023/07/24 09:17:15 by voszadcs         ###   ########.fr       */
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
	return (0);
}
