/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:40:07 by mamichal          #+#    #+#             */
/*   Updated: 2024/10/17 08:20:20 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static bool	is_dead(t_philo *philo)
{
	long	elapsed;
	long	time_to_die;

	if (true == get_bool(&philo->philo_mtx, &philo->full))
		return (false);
	elapsed = get_time(MILLISECOND) - \
		get_long(&philo->philo_mtx, &philo->last_meal);
	time_to_die = philo->p_table->time_to_die / 1e3;
	if (elapsed < time_to_die)
		return (false);
	return (true);
}

void	*monitor_dinner(void *data)
{
	t_table	*p_table;
	int		i;

	p_table = (t_table *)data;
	while (false == all_threads_active(&p_table->table_mtx, \
			&p_table->nb_threads_active, p_table->philo_count))
		;
	while (false == get_end(p_table))
	{
		i = 0;
		while (i < p_table->philo_count && false == get_end(p_table))
		{
			if (true == is_dead(&p_table->philos[i]))
			{
				write_philo_status(&p_table->philos[i], DEAD);
				set_bool(&p_table->table_mtx, &p_table->end_flag, true);
			}
			i++;
		}
	}
	return (NULL);
}
