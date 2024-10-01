/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:52:27 by mamichal          #+#    #+#             */
/*   Updated: 2024/09/30 10:42:35 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"
#include <bits/pthreadtypes.h>
#include <pthread.h>

/** @brief Convert a string to an integer.
 *
 *  The atoi() function converts the initial portion of the string
 *  pointed to by nptr to int.
 *
 *  @param nptr pointer to a string to be converted.
 *  @return Int converted from a string.
 *	@bug overflow not taken care of
 */
int	ft_atoi(const char *nptr)
{
	int	minus;
	int	num;

	num = 0;
	minus = 1;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			minus *= -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		num = num * 10;
		num += *nptr - 48;
		nptr++;
	}
	return (num * minus);
}

bool	handle_mutex(pthread_mutex_t *mutex, t_thread_code code)
{
	int	mtx_ret;

	mtx_ret = -1;
	if (INIT == code)
		mtx_ret = pthread_mutex_init(mutex, NULL);
	else if (LOCK == code)
		mtx_ret = pthread_mutex_lock(mutex);
	else if (UNLOCK == code)
		mtx_ret = pthread_mutex_unlock(mutex);
	else if (DESTROY)
		mtx_ret = pthread_mutex_destroy(mutex);
	if (0 == mtx_ret)
		return (true);
	return (false);
}

