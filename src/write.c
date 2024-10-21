/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 13:38:17 by mamichal          #+#    #+#             */
/*   Updated: 2024/10/21 13:06:20 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

bool	write_philo_status(t_philo *philo, t_philo_status status)
{
	long	elapsed;

	if (false == handle_mutex(&philo->p_table->write_mtx, LOCK))
		return (false);
	elapsed = get_time(MILLISECOND) - philo->p_table->time_start;
	if ((TOOK_1_FORK == status || TOOK_2_FORK == status)
		&& false == get_end(philo->p_table))
		printf("%-6ld %d has taken a fork\n", elapsed, philo->id + 1);
	else if (EATING == status && false == get_end(philo->p_table))
		printf("%-6ld %d is eating\n", elapsed, philo->id + 1);
	else if (SLEEPING == status && false == get_end(philo->p_table))
		printf("%-6ld %d is sleeping\n", elapsed, philo->id + 1);
	else if (THINGKING == status && false == get_end(philo->p_table))
		printf("%-6ld %d is thinking\n", elapsed, philo->id + 1);
	else if (DEAD == status && false == get_end(philo->p_table))
		printf("%-6ld %d died\n", elapsed, philo->id + 1);
	else if (FULL == status && false == get_end(philo->p_table))
		printf("%-6ld %d is full\n", elapsed, philo->id + 1);
	if (false == handle_mutex(&philo->p_table->write_mtx, UNLOCK))
		return (false);
	return (true);
}
