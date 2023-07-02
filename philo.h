/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 19:00:07 by voszadcs          #+#    #+#             */
/*   Updated: 2023/06/29 15:51:36 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define EXIT_ARGS 0
# define EXIT_ARG_NONDIGIT 1
# define EXIT_THREAD_FAIL 2

//states
# define EAT 0 
# define THINK 1 
# define SLEEP 2  

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_params
{
	int	num_philo;
	int	time_die;
	int	time_eat;
	int	time_sleep;
	int	must_eat;
}	t_params;

typedef struct s_philo
{
	pthread_t		one_ph;
	pthread_mutex_t	*fork;
	t_params		*params;
	int				num;
	int				times_eat;
	int				state;
}					t_philo;

void	parse(int argc, char *argv[], t_params *params);
void	errors(int errnum);
int		ft_atoi(const char *str);
int		ft_isdigit(int a);
void	thread_init(t_params *params);
void	*thr_func(void *arg);

#endif