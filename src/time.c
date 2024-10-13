/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:38:04 by mamichal          #+#    #+#             */
/*   Updated: 2024/10/13 13:33:43 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long	get_time(t_time_code time_code)
{
	struct timeval	tv;

	if (0 != gettimeofday(&tv, NULL))
		return (-1);
	if (SECOND == time_code)
		return (tv.tv_sec + (tv.tv_usec / 1e6));
	else if (MILLISECOND == time_code)
		return ((tv.tv_sec * 1e3) + (tv.tv_usec / 1e3));
	else if (MICROSECOND)
		return ((tv.tv_sec * 1e6) + tv.tv_usec);
	else
		return (-1);
}

void	precise_usleep(long usec, t_table *p_table)
{
	long	start;
	long	elapsed;
	long	remaining;

	start = get_time(MICROSECOND);
	while (get_time(MICROSECOND) - start < usec)
	{
		if (true == get_end(p_table))
			break ;
		elapsed = get_time(MICROSECOND - start);
		remaining = usec - elapsed;
		if (remaining > 1e3)
			usleep(remaining / 2);
		else
			while (get_time(MICROSECOND) - start < usec)
				;
	}
}
