/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:52:27 by mamichal          #+#    #+#             */
/*   Updated: 2024/09/30 09:59:46 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static bool	check_content(char *arg)
{
	int	i;

	i = 0;
	while (0 != arg[i])
	{
		if (arg[i] < '0' || arg[i] > '9')
			return (false);
		i++;
	}
	return (true);
}

// TODO: check for max int???
bool	check_input(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		return (printf("Ivalid number of arguments\n"), false);
	if (ft_atoi(argv[1]) > PHILO_MAX || ft_atoi(argv[1]) <= 0
		|| check_content(argv[1]) == false)
		return (printf("Invalid number of philos\n"), false);
	if (ft_atoi(argv[2]) <= 0 || check_content(argv[2]) == false)
		return (printf("Invalid time to die\n"), false);
	if (ft_atoi(argv[3]) <= 0 || check_content(argv[3]) == false)
		return (printf("Invalid time to eat\n"), false);
	if (ft_atoi(argv[4]) <= 0 || check_content(argv[4]) == false)
		return (printf("Invalid time to sleep\n"), false);
	if (NULL != argv[5] && (ft_atoi(argv[5]) < 0
			|| false == check_content(argv[5])))
		return (printf("Invalid number of times philos should eat\n"), false);
	return (true);
}

void	parse(t_table *p_table, char **argv)
{
	p_table->philo_count = ft_atoi(argv[1]);
	p_table->time_to_die = ft_atoi(argv[2]) * 1e3;
	p_table->time_to_eat = ft_atoi(argv[3]) * 1e3;
	p_table->time_to_sleep = ft_atoi(argv[4]) * 1e3;
	if (NULL != argv[5])
		p_table->meals_limit = ft_atoi(argv[5]);
	else
		p_table->meals_limit = -1;
}
