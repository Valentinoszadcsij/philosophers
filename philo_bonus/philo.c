/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 13:31:20 by voszadcs          #+#    #+#             */
/*   Updated: 2023/07/31 15:03:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_params	params;
	t_data		dt;

	parse(argc, argv, &params);
	dt.params = &params;
	init_structs(&dt);
	proc_start(&dt);
	return (0);
}