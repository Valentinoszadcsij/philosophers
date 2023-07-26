/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 19:00:07 by voszadcs          #+#    #+#             */
/*   Updated: 2023/07/26 15:07:17 by voszadcs         ###   ########.fr       */
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

typedef struct s_philo
{
	pthread_t		one_ph;
	pthread_mutex_t	*fork_l;
	pthread_mutex_t	*fork_r;
	unsigned long	times_eat;
	unsigned long	last_meal_time;
}					t_philo;

typedef struct s_main
{
	pthread_mutex_t	*forks;
	t_philo			*philo;
	t_params		*params;
	unsigned long	start_time;
	int				end_threads;
	pthread_mutex_t	end_mutex;
	pthread_mutex_t	print_lock;
}					t_main;

typedef struct s_thread_data
{
	t_main			*main_s;
	unsigned long	index;
}			t_thread_dt;

void	parse(int argc, char *argv[], t_params *params);
void	errors(int errnum);
int		ft_atoi(const char *str);
int		ft_isdigit(int a);
void	thread_init(t_params *params);
void	*thr_func(void *arg);
unsigned long	time_init(void);
void	sleeping(unsigned long s, t_thread_dt *dt);
int check_death(t_thread_dt *dt);
int check_times_ate(t_thread_dt *dt);
void	mem_free(void *arg, int n, int type);


#endif