/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:48:42 by mamichal          #+#    #+#             */
/*   Updated: 2024/10/13 17:34:23 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_table		table;
	t_philo		philos[PHILO_MAX];

	if (false == check_input(argc, argv))
		return (INVALID_ARGS);
	parse(&table, argv);
	if (false == data_init(&table))
	{
		// TODO: CLEANUP
		return (INIT_ERROR);
	}
	if (false == dinner_start(&table))
	{
		// TODO: CLEANUP
		return (DINNER_ERROR);
	}
	// TODO: CLEANUP
	return (OK);
}
