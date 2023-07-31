/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 13:32:41 by voszadcs          #+#    #+#             */
/*   Updated: 2023/07/31 18:25:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define EXIT_ARGS 0
# define EXIT_ARG_NONDIGIT 1
# define EXIT_THREAD_FAIL 2
# define ONE_PHILO 3
# define EXIT_FORK 4

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <semaphore.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/wait.h>

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
	unsigned long	times_ate;
	unsigned long	last_meal_time;
}					t_philo;

typedef struct s_data
{
	t_philo			*philo;
	t_params		*params;
	sem_t			*forks;
	sem_t			*dead;
	int				is_dead;
	unsigned long	start_time;

}					t_data;

void	parse(int argc, char *argv[], t_params *params);
void	errors(int errnum);
int		ft_atoi(const char *str);
int		ft_isdigit(int a);
void	sleeping(unsigned long s);
void	proc_start(t_data *dt);
void    init_structs(t_data *dt);
unsigned long	time_init(void);
void	routine(t_data *dt, unsigned long ind);
int	check_death(t_data *dt, unsigned long ind);
int	controller(t_data *dt, unsigned long ind);



#endif