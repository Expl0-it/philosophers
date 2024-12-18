/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:48:42 by mamichal          #+#    #+#             */
/*   Updated: 2024/10/20 20:15:11 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_table		table;

	if (false == check_input(argc, argv))
		return (INVALID_ARGS);
	parse(&table, argv);
	if (false == data_init(&table))
	{
		cleanup(&table);
		return (INIT_ERROR);
	}
	if (false == dinner_start(&table))
	{
		cleanup(&table);
		return (DINNER_ERROR);
	}
	cleanup(&table);
	return (OK);
}
