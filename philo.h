/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 19:00:07 by voszadcs          #+#    #+#             */
/*   Updated: 2023/07/10 15:05:43 by voszadcs         ###   ########.fr       */
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
# define DEAD 3

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
	int				num;
	int				times_eat;
	int				state;
}					t_philo;

typedef struct s_main
{
	t_params		*params;
	t_philo			*philo;
	int				ready;
	long int		start_time;
}					t_main;

typedef struct s_thread_data
{
	t_main	*main_s;
	int		index;
	int		end_threads;
}			t_thread_dt;

void	parse(int argc, char *argv[], t_params *params);
void	errors(int errnum);
int		ft_atoi(const char *str);
int		ft_isdigit(int a);
void	thread_init(t_params *params);
void	*thr_func(void *arg);
long int	time_init(void);
void	sleeping(int s);

#endif