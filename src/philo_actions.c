/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 15:50:05 by mamichal          #+#    #+#             */
/*   Updated: 2024/10/27 16:34:50 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

bool	philo_sleep(t_philo *philo)
{
	if (false == write_philo_status(philo, SLEEPING))
		return (false);
	precise_usleep(philo->p_table->time_to_sleep, philo->p_table);
	return (true);
}

bool	philo_eat(t_philo *philo)
{
	if (false == handle_mutex(&philo->first_fork->fork, LOCK)
		|| false == write_philo_status(philo, TOOK_1_FORK))
		return (false);
	if (false == handle_mutex(&philo->second_fork->fork, LOCK)
		|| false == write_philo_status(philo, TOOK_2_FORK))
		return (false);
	if (false == set_long(&philo->philo_mtx, &philo->last_meal, \
			get_time(MILLISECOND)))
		return (false);
	philo->meals_eaten++;
	if (false == write_philo_status(philo, EATING))
		return (false);
	precise_usleep(philo->p_table->time_to_eat, \
			philo->p_table);
	if (philo->p_table->meals_limit > 0 \
		&& philo->meals_eaten >= philo->p_table->meals_limit)
		if (false == set_bool(&philo->philo_mtx, &philo->full, true))
			return (false);
	if (false == handle_mutex(&philo->first_fork->fork, UNLOCK)
		|| false == handle_mutex(&philo->second_fork->fork, UNLOCK))
		return (false);
	return (true);
}

// NOTE: Making the system fair by forcing thinking time when
// there is an odd number of philos
bool	philo_think(t_philo *philo, bool first_time)
{
	long	t_eat;
	long	t_sleep;
	long	t_think;

	if (false == write_philo_status(philo, THINGKING))
		return (false);
	if (0 == philo->p_table->philo_count % 2 || true == first_time)
		return (true);
	t_eat = philo->p_table->time_to_eat;
	t_sleep = philo->p_table->time_to_sleep;
	t_think = (t_eat * 2) - t_sleep;
	if (t_think < 0)
		t_think = 0;
	precise_usleep(t_think * 0.1, philo->p_table);
	return (true);
}

// NOTE: Additional case when philo ate all the meals
bool	philo_full(t_philo *philo)
{
	if (false == write_philo_status(philo, FULL))
		return (false);
	return (true);
}

void	desynchronize(t_philo *philo)
{
	philo_think(philo, true);
	if (philo->id % 2 == 0)
		precise_usleep(1e4, philo->p_table);
}
