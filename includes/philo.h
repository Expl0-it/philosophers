/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:51:07 by mamichal          #+#    #+#             */
/*   Updated: 2024/10/01 11:47:12 by mamichal         ###   ########.fr       */
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
# define PHILO_MAX 200

// TYPE DECLARATIONS
typedef enum e_errors
{
	OK = 0,
	MALLOC_ERROR = 1,
	INVALID_ARGS = 2,
}				t_errors;

typedef enum e_thread_code
{
	INIT,
	CREATE,
	LOCK,
	UNLOCK,
	JOIN,
	DESTROY,
	DETACH,
}			t_thread_code;

typedef struct s_fork
{
	pthread_mutex_t	fork;
	int				fork_id;
}				t_fork;

typedef struct s_table	t_table;

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				meals_eaten;
	bool			full;
	bool			eating;
	size_t			last_meal;
	t_fork			*r_fork;
	t_fork			*l_fork;
	t_table			*table;
}				t_philo;

struct s_table
{
	int				philo_count;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	int				meals_limit;
	size_t			time_start;
	bool			end_flag;
	t_fork			forks[PHILO_MAX];
	t_philo			philos[PHILO_MAX];
};

// FUNCTION DECLARATIONS

// utils.c
int		ft_atoi(const char *nptr);
bool	handle_mutex(pthread_mutex_t *mutex, t_thread_code code);
bool	handle_thread(pthread_t *thread, void *(*routine)(void *),
			void *data, t_thread_code code);

// check_input.c
bool	check_input(int argc, char **argv);
void	parse(t_table *p_table, char **argv);

#endif
