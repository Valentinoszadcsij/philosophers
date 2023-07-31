#include "philo.h"

void	proc_start(t_data *dt)
{
	pid_t	proc;
	unsigned long	i;

	i = 0;
	dt->start_time = time_init();
	while (i < dt->params->num_philo)
	{
		dt->philo[i].last_meal_time = time_init();
		proc = fork();
		if (proc == 0)
			routine(dt, i);
		else if (proc == -1)
			errors(EXIT_FORK);
		i++;
	}
	proc = waitpid(0, NULL, 0);
	while (proc != -1)
		proc = waitpid(0, NULL, 0);
}