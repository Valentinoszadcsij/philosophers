
# What to consider?

1. avoid deadlock
2. avoid any race conditions. If a data needs to be written and read by different processes, then that data has to be protected by mutex:

```c

bool			is_death; // this is the data shared by multiple processes
pthread_mutex_t *death_mutex; // this is the mutex protecting the shared data

pthread_mutex_lock(death_mutex);
if (is_death)
{
	pthread_mutex_unlock(death_mutex);
	return ;
}
pthread_mutex_unlock(death_mutex);

```

3. resource management, if the philosopher is closer to death, it should have a higher piority to take the forks than the other philosopher. This is an optimization so that your program can be performed well enough to pass the evaluation.

# Improvements

## Structs

In struct s_params:

- num_philo: unsigned long
- time: unisigned long

In struct s_philo:

- Each philosopher should have a reference to the 2 forks

## Parsing

- Check if the input is in the range of unsigned int

## Create philo


# Philo's routine

1. get right fork
	- lock the fork
	- print
2. get left fork
	- lock the fork
	- print
3. eat
	- print
	- sleep (/ use your sleep function) input
4. unlock both forks
5. sleeping
	- print
	- sleep (/ use your sleep function) input
6. thinking
	- print
	- sleep (/ use your sleep function) v

# How you check death?

- check it inside philo routine
- use supervisor (aka another thread/parent process to check the is_death varaible of each threads)
