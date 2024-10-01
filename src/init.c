/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 09:57:07 by mamichal          #+#    #+#             */
/*   Updated: 2024/10/01 12:52:26 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static bool	fork_init(t_table *p_table)
{
	int	i;

	i = 0;
	while (i < p_table->philo_count)
	{
		if (false == handle_mutex(&p_table->forks[i].fork, INIT))
			return (false);
		p_table->forks[i].fork_id = i;
		i++;
	}
	return (true);
}

