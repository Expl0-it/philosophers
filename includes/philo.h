/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:51:07 by mamichal          #+#    #+#             */
/*   Updated: 2024/09/25 18:11:39 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

// INCLUDES
//# include "../libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

// static defines
# define PHILO_MAX 300

// TYPE DECLARATIONS
typedef enum e_errors
{
	OK = 0,
	MALLOC_ERROR = 1,
	NOT_ENOUGH_ARGS = 2,
	ERR_ARGS = 3,
}				t_errors;

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				meals_eaten;
	bool			*dead;
	bool			eating;
	size_t			last_meal;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;

}				t_philo;

typedef struct s_table
{
	size_t	time_to_die;
	size_t	time_to_eat;
	size_t	time_to_sleep;
	size_t	time_start;
	int		philos_count;
	int		meal_count;
	bool	dead_flag;
}				t_table;

// FUNCTION DECLARATIONS

#endif
