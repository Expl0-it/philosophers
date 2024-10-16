/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   synchro.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:26:51 by mamichal          #+#    #+#             */
/*   Updated: 2024/10/16 14:08:49 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	wait_threads(t_table *p_table)
{
	while (false == get_bool(&p_table->table_mtx, &p_table->threads_ready))
		;
}

bool	all_threads_active(pthread_mutex_t *mtx, long *nb_threads, \
				int philo_count)
{
	bool	ret;

	ret = false;
	handle_mutex(mtx, LOCK);
	if (*nb_threads == (long)philo_count)
		ret = true;
	handle_mutex(mtx, UNLOCK);
	return (ret);
}
