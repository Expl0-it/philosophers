/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 15:50:05 by mamichal          #+#    #+#             */
/*   Updated: 2024/10/13 17:20:25 by mamichal         ###   ########.fr       */
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
	if (false == set_long(&philo->philo_mtx, &philo->last_meal, get_time(MILLISECOND)))
		return (false);
	philo->meals_eaten++;
	if (false == write_philo_status(philo, EATING))
		return (false);
	precise_usleep(philo->p_table->time_to_eat, philo->p_table);
	if (philo->p_table->meals_limit > 0 && philo->meals_eaten > philo->p_table->meals_limit)
		if (false == set_bool(&philo->philo_mtx, &philo->full, true))
			return (false);
	if (false == handle_mutex(&philo->first_fork->fork, UNLOCK)
			|| false == handle_mutex(&philo->second_fork->fork, UNLOCK))
		return (false);
	return (true);
}

bool	philo_think(t_philo *philo)
{
	if (false == write_philo_status(philo, THINGKING))
		return (false);
	return (true);
}
