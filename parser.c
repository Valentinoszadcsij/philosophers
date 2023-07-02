/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 14:02:03 by voszadcs          #+#    #+#             */
/*   Updated: 2023/06/26 22:56:54 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	params_init(int argc, char *argv[], t_params *params)
{
	params->num_philo = ft_atoi(argv[1]);
	params->time_die = ft_atoi(argv[2]);
	params->time_eat = ft_atoi(argv[3]);
	params->time_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		params->must_eat = ft_atoi(argv[5]);
	if (params->must_eat)
		printf("Must eat times: %d\n", params->must_eat);
}

void	parse(int argc, char *argv[], t_params *params)
{
	int	i;
	int	j;

	j = 0;
	i = 1;
	if (argc != 5 && argc != 6)
		errors(EXIT_ARGS);
	while (i < argc)
	{
		while (argv[i][j] != '\0')
		{
			if (ft_isdigit(argv[i][j]) != 0)
				errors(EXIT_ARG_NONDIGIT);
			j++;
		}
		j = 0;
		i++;
	}
	params_init(argc, argv, params);
}
