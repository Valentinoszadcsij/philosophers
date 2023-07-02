/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 23:30:36 by voszadcs          #+#    #+#             */
/*   Updated: 2023/06/29 16:17:22 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*thr_func(void *arg)
{
	t_philo *philo;
	struct timeval time;
	philo = arg;
	gettimeofday(&time, NULL);
	printf("Philosofer %d is here! Time: %ld\n", philo->num, (time.tv_sec / 1000 + time.tv_sec * 1000));

	return (NULL);
}