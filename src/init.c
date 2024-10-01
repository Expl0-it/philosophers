/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 09:57:07 by mamichal          #+#    #+#             */
/*   Updated: 2024/10/01 15:28:29 by mamichal         ###   ########.fr       */
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

static bool	philo_init(t_table *p_table)
{
	int		i;
	t_philo	*philo;

	i = 0;
	while (i < p_table->philo_count)
	{
		philo = &p_table->philos[i];
		philo->id = i;
		philo->full = false;
		philo->meals_eaten = 0;
		philo->p_table = p_table;
		philo->eating = false;
		philo->last_meal = -1;
		// TODO: ASSIGN FORKS
		i++;
	}
}

bool	data_init(t_table *p_table)
{
	p_table->end_flag = false;
	if (false == fork_init(p_table))
		return (false);
	return (true);
}
