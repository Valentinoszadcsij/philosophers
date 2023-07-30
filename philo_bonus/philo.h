/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 13:32:41 by voszadcs          #+#    #+#             */
/*   Updated: 2023/07/30 13:33:11 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define EXIT_ARGS 0
# define EXIT_ARG_NONDIGIT 1
# define EXIT_THREAD_FAIL 2
# define ONE_PHILO 3

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_params
{
	unsigned long	num_philo;
	unsigned long	time_die;
	unsigned long	time_eat;
	unsigned long	time_sleep;
	unsigned long	must_eat;
}	t_params;

void	parse(int argc, char *argv[], t_params *params);
void	errors(int errnum);
int		ft_atoi(const char *str);
int		ft_isdigit(int a);


#endif