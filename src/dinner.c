/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 18:08:42 by mamichal          #+#    #+#             */
/*   Updated: 2024/10/08 11:03:55 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

bool	dinner_start(t_table *p_table)
{
	int	i;

	i = -1;
	if (0 == p_table->meals_limit)
		return (true);
	else if (1 == p_table->meals_limit)
		;// TODO:
	else
	{
		while (++i < p_table->philo_count)
			if (false == handle_thread(p_table->philos[i].thread, \
					philo_routine, &p_table->philos[i], CREATE))
				return (false);
	}
}
