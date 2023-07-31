#include "philo.h"

int	check_death(t_data *dt, unsigned long ind)
{
	sem_wait(dt->dead);
	if (time_init() - dt->philo[ind].last_meal_time >= dt->params->time_die)
		dt->is_dead = 1;
	if (dt->is_dead == 1)
	{
		sem_post(dt->dead);
        sem_close(dt->dead);
		return (1);
	}
	sem_post(dt->dead);
    sem_close(dt->dead);
	return (0);
}

int	check_times_ate(t_data *dt)
{
	unsigned long	i;
	unsigned long	total;

	i = 0;
	total = 0;
	while (i < dt->params->num_philo)
	{
		if (dt->philo[i].times_ate >= dt->params->must_eat)
			total++;
		i++;
	}
	if (total == dt->params->num_philo)
		return (1);
	return (0);
}

int	controller(t_data *dt, unsigned long ind)
{
	if (check_death(dt, ind))
	{
		printf("%lu %lu has died\n", time_init() - dt->start_time, ind + 1);
		return (1);
	}
	if (dt->params->must_eat)
	{
		if (check_times_ate(dt))
		{
			sem_wait(dt->dead);
			dt->is_dead = 1;
			sem_post(dt->dead);
            sem_close(dt->dead);
			return (1);
		}
	}
	return (0);
}