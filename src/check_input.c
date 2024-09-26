/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:52:27 by mamichal          #+#    #+#             */
/*   Updated: 2024/09/26 14:01:58 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static bool	check_content(char *arg)
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

bool	check_input(int argc, char **argv)
{
	if (argc != 5 || argc != 6)
		return (write(2, "Ivalid number of arguments\n", 27), false);
	if (ft_atoi(argv[1]) > PHILO_MAX || ft_atoi(argv[1]) <= 0
		|| check_content(argv[1]) == false)
		return (write(2, "Invalid number of philos\n", 25), false);
	if (ft_atoi(argv[2]) <= 0 || check_content(argv[2]) == false)
		return (write(2, "Invalid time to die\n", 21), false);
	if (ft_atoi(argv[3]) <= 0 || check_content(argv[3]) == false)
		return (write(2, "Invalid time to eat\n", 21), false);
	if (ft_atoi(argv[4]) <= 0 || check_content(argv[4]) == false)
		return (write(2, "Invalid time to sleep\n", 23), false);
	if (NULL != argv[5] && (ft_atoi(argv[3]) < 0
			|| check_content(argv[3]) == false))
		return (write(2, "Invalid times philos should eat\n", 32), false);
	return (true);
}
