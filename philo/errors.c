/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 14:06:16 by voszadcs          #+#    #+#             */
/*   Updated: 2023/06/25 22:29:50 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	errors(int errnum)
{
	if (errnum == EXIT_ARGS)
	{
		write(2, "Error: wrong number of arguments\n", 33);
		exit (EXIT_FAILURE);
	}
	if (errnum == EXIT_ARG_NONDIGIT)
	{
		write(2, "Error: non-digit character passed as argument\n", 46);
		exit (EXIT_FAILURE);
	}
	if (errnum == EXIT_THREAD_FAIL)
	{
		write(2, "Error: couldn't create thread\n", 30);
		exit (EXIT_FAILURE);
	}
}
