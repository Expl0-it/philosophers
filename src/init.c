/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 09:57:07 by mamichal          #+#    #+#             */
/*   Updated: 2024/10/13 16:03:13 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static bool	fork_init(t_table *p_table)
{
	int	i;

	i = 0;
	while (i < p_table->philo_count)
	{
		p_table->forks[i].fork_id = i;
		if (false == handle_mutex(&p_table->forks[i].fork, INIT))
			return (false);
		i++;
	}
	return (true);
}

static void	assign_forks(t_philo *philo, t_fork *forks, int philo_position)
{
	int	philo_count;

	/*
	philo_count = philo->p_table->philo_count;
	philo->r_fork = &forks[philo_position];
	philo->l_fork = &forks[(philo_position + 1) % philo_count];
	*/
	// NOTE: Even odd fork assigment
	// TODO: Change naming to first fork, second fork

	if (0 == philo->id % 2)
	{
		philo->first_fork = &forks[philo_position];
		philo->second_fork = &forks[(philo_position + 1) % philo_count];
	}
	else
	{
		philo->first_fork = &forks[(philo_position + 1) % philo_count];
		philo->second_fork = &forks[philo_position];
	}
}

static bool	philo_init(t_table *p_table)
{
	int		i;
	t_philo	*philo;

	i = 0;
	while (i < p_table->philo_count)
	{
		philo = &p_table->philos[i];
		philo->p_table = p_table;
		philo->id = i;
		philo->full = false;
		philo->meals_eaten = 0;
		philo->p_table = p_table;
		philo->eating = false;
		philo->last_meal = -1;
		assign_forks(philo, p_table->forks, i);
		i++;
	}
	return (true);
}

bool	data_init(t_table *p_table)
{
	p_table->end_flag = false;
	p_table->threads_ready = false;
	if (false == fork_init(p_table))
		return (false);
	if (false == philo_init(p_table))
		return (false);
	if (false == handle_mutex(&p_table->table_mtx, INIT))
		return (false);
	return (true);
}
