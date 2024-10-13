/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_set_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 16:21:59 by mamichal          #+#    #+#             */
/*   Updated: 2024/10/13 16:39:51 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long	get_long(pthread_mutex_t *mtx, long *source)
{
	long	ret;

	handle_mutex(mtx, LOCK);
	if (NULL != source)
		ret = *source;
	handle_mutex(mtx, UNLOCK);
	return (ret);
}

bool	set_long(pthread_mutex_t *mtx, long *dest, long value)
{
	if (false == handle_mutex(mtx, LOCK))
		return (false);
	if (NULL != dest)
		*dest = value;
	if (false == handle_mutex(mtx, UNLOCK))
		return (false);
	return (true);
}
