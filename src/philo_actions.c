/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 15:50:05 by mamichal          #+#    #+#             */
/*   Updated: 2024/10/13 16:39:49 by mamichal         ###   ########.fr       */
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
