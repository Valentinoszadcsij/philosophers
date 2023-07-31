#include "philo.h"

void	eat(t_data *dt, unsigned long ind)
{
	sem_wait(dt->forks);
    printf("%lu %lu took first fork\n", time_init() - dt->start_time, ind + 1);
	sem_wait(dt->forks);
    printf("%lu %lu took second fork\n", time_init() - dt->start_time, ind + 1);
    printf("%lu %lu is eating\n", time_init() - dt->start_time, ind + 1);
    dt->philo[ind].last_meal_time = time_init();
    sleeping(dt->params->time_eat);
    dt->philo[ind].times_ate++;
    sem_post(dt->forks);
    sem_post(dt->forks);
}

void    f_sleep(t_data *dt, unsigned long ind)
{
    printf("%lu %lu is sleeping\n", time_init() - dt->start_time, ind + 1);
}

void	routine(t_data *dt, unsigned long ind)
{
	while (controller(dt, ind) != 1)
	{
        if (time_init() - dt->start_time < 15 && ind % 2 != 0)
        {
            printf("%lu %lu is thinking\n", time_init() - dt->start_time, ind + 1);
            sleeping(dt->params->time_eat);
        }
        else if (time_init() - dt->start_time > 15)
        {
            printf("%lu %lu is thinking\n", time_init() - dt->start_time, ind + 1);
            sleeping(dt->params->time_eat);
        }
		eat(dt, ind);
		if (!controller(dt, ind))
			f_sleep(dt, ind);
	}
    exit(0);
}