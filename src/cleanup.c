/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 18:47:48 by mamichal          #+#    #+#             */
/*   Updated: 2024/10/20 18:58:00 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	cleanup(t_table *p_table)
{
	t_philo	*philo;
	int		i;

	i = 0;
	while (i < p_table->philo_count)
	{
		philo = &p_table->philos[i];
		handle_mutex(&philo->philo_mtx, DESTROY);
		handle_mutex(&p_table->forks[i].fork, DESTROY);
		i++;
	}
	handle_mutex(&p_table->write_mtx, DESTROY);
	handle_mutex(&p_table->table_mtx, DESTROY);
}
