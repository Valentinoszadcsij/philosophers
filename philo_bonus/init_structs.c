#include "philo.h"

t_philo	*philo_init(t_data *dt)
{
	unsigned long	ind;

	ind = 0;
	dt->philo = malloc(sizeof(t_philo) * dt->params->num_philo);
	while (ind < dt->params->num_philo)
	{
		dt->philo[ind].times_ate = 0;
		ind++;
	}
	return (dt->philo);
}

void	init_structs(t_data *dt)
{
	sem_unlink("/fork_sem");
	dt->forks = sem_open("/fork_sem", O_CREAT, 0644, dt->params->num_philo);
	sem_unlink("/sem_dead");
	dt->dead = sem_open("/sem_dead", O_CREAT, 0644, 1);
	dt->is_dead = 0;
	dt->philo = philo_init(dt);
	dt->start_time = time_init();
}