/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:17:45 by voszadcs          #+#    #+#             */
/*   Updated: 2023/07/11 12:34:58 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "philo.h"
#include "philo.h"

long int	time_init(void)
{
	struct timeval	cur_epoch;
	long int		zero;

	gettimeofday(&cur_epoch, NULL);
	zero = (cur_epoch.tv_usec / 1000 + cur_epoch.tv_sec * 1000);
	return (zero);
}

void	sleeping(int s)
{
	long int	target;
	long int	start_usec;
	target = (long)s * 1000;
	start_usec = (long)time_init() * 1000;
	while(((long)time_init() * 1000 - start_usec) <= target)
	{
		usleep(1);
	}
}

// int main()
// {
// 	long int time = time_init();
// 	printf("%ld\n", time);
// 	return (0);
// }