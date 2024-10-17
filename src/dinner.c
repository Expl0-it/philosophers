/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 18:08:42 by mamichal          #+#    #+#             */
/*   Updated: 2024/10/17 08:33:55 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*lone_philo(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	wait_threads(philo->p_table);
	set_long(&philo->philo_mtx, &philo->last_meal, get_time(MILLISECOND));
	increment_long(&philo->p_table->table_mtx, &philo->p_table->nb_threads_active);
	write_philo_status(philo, THINGKING);
	write_philo_status(philo, TOOK_1_FORK);
	while (false == get_end(philo->p_table))
		;
	return (NULL);
}

void	*philo_routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	wait_threads(philo->p_table);
	set_long(&philo->philo_mtx, &philo->last_meal, get_time(MILLISECOND));
	increment_long(&philo->p_table->table_mtx, &philo->p_table->nb_threads_active);
	while (false == get_end(philo->p_table))
	{
		if (true == philo->full) // TODO: THread safe
		{
			// NOTE: EITHER ONE OR THE OTHER

			//philo_think(philo);
			philo_full(philo);
			break ;
		}
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
	if (false == handle_thread(&p_table->waiter, monitor_dinner, p_table, CREATE))
		return (false);
	if (1 == p_table->meals_limit)
	{
		if (false == handle_thread(&p_table->philos[0].thread, \
				lone_philo, &p_table->philos[0], CREATE))
			return (false);
	}
	else
	{
		if (false == create_threads(p_table))
			return (false);
		p_table->time_start = get_time(MILLISECOND);
		if (-1 == p_table->time_start)
			return (false);
		set_bool(&p_table->table_mtx, &p_table->threads_ready, true);
		join_threads(p_table);
		set_bool(&p_table->table_mtx, &p_table->end_flag, true);
		handle_thread(&p_table->waiter, NULL, NULL, JOIN);
	}
	return (true);
}
