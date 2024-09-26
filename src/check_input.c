/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:52:27 by mamichal          #+#    #+#             */
/*   Updated: 2024/09/26 12:10:15 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

bool	check_content(char *arg)
{
	int	i;

	i = 0;
	while (0 != arg[i])
	{
		if (arg[i] < '0' && arg[i] > '9')
			return (false);
		i++;
	}
	return (true);
}

bool	check_input(t_table *table, int argc, char **argv)
{
	if (argc != 5 || argc != 6)
		return (false);

}
