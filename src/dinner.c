/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 18:08:42 by mamichal          #+#    #+#             */
/*   Updated: 2024/10/13 18:10:28 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*philo_routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	wait_threads(philo->p_table);
	// TODO: Set last meal time
	while (false == get_end(philo->p_table))
	{
		if (true == philo->full) // TODO: THread safe
			break ;
		philo_think(philo);
		philo_eat(philo);
		philo_sleep(philo);
	}
	return (NULL);
}

static bool	create_threads(t_table *p_table)
{
	int	i;

	i = 0;
	while (i < p_table->philo_count)
	{
		if (false == handle_thread(&p_table->philos[i].thread, \
				philo_routine, &p_table->philos[i], CREATE))
			return (false);
		i++;
	}
	return (true);
}

static bool	join_threads(t_table *p_table)
{
	int	i;

	i = 0;
	while (i < p_table->philo_count)
	{
		if (false == handle_thread(&p_table->philos[i].thread, \
				NULL, NULL, JOIN))
			return (false);
		i++;
	}
	return (true);
}

bool	dinner_start(t_table *p_table)
{
	if (0 == p_table->meals_limit)
		return (true);
	else if (1 == p_table->meals_limit)
		;// TODO:
	else
	{
		if (false == create_threads(p_table))
			return (false);
		p_table->time_start = get_time(MILLISECOND);
		if (-1 == p_table->time_start)
			return (false);
		set_bool(&p_table->table_mtx, &p_table->threads_ready, true);
		join_threads(p_table);
	}
	return (true);
}
