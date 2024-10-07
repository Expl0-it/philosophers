/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 08:56:06 by mamichal          #+#    #+#             */
/*   Updated: 2024/10/07 12:34:51 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	get_int(pthread_mutex_t *mtx, int *source)
{
	int	ret;

	handle_mutex(mtx, LOCK);
	if (NULL != source)
		ret = *source;
	handle_mutex(mtx, UNLOCK);
	return (ret);
}

bool	set_int(pthread_mutex_t *mtx, int *dest, int value)
{
	if (false == handle_mutex(mtx, LOCK))
		return (false);
	if (NULL != dest)
		*dest = value;
	if (false == handle_mutex(mtx, UNLOCK))
		return (false);
	return (true);
}

bool	get_bool(pthread_mutex_t *mtx, bool *source)
{
	bool	ret;

	handle_mutex(mtx, LOCK);
	if (NULL != source)
		ret = *source;
	handle_mutex(mtx, UNLOCK);
	return (ret);
}

bool	set_bool(pthread_mutex_t *mtx, bool *dest, bool value)
{
	if (false == handle_mutex(mtx, LOCK))
		return (false);
	if (NULL != dest)
		*dest = value;
	if (false == handle_mutex(mtx, UNLOCK))
		return (false);
	return (true);
}

bool	get_end(t_table *table)
{
	return (get_bool(&table->table_mtx, &table->end_flag));
}
