/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:51:07 by mamichal          #+#    #+#             */
/*   Updated: 2024/10/13 15:55:36 by mamichal         ###   ########.fr       */
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
	INVALID_ARGS = 1,
	INIT_ERROR = 2,
}				t_errors;

typedef enum e_thread_code
{
	CREATE,
	JOIN,
	DETACH,
}			t_thread_code;

typedef enum e_mutex_code
{
	INIT,
	LOCK,
	UNLOCK,
	DESTROY,
}			t_mutex_code;

typedef enum e_time_code
{
	SECOND,
	MILLISECOND,
	MICROSECOND,
}			t_time_code;

typedef enum e_philo_status
{
	EATING,
	SLEEPING,
	THINGKING,
	TOOK_1st_FORK,
	TOOK_2nd_FORK,
	DEAD,
}			t_philo_status;

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
	long			last_meal;
	t_fork			*r_fork;
	t_fork			*l_fork;
	t_table			*p_table;
}				t_philo;

struct s_table
{
	int				philo_count;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	int				meals_limit;
	long			time_start;
	bool			end_flag;
	bool			threads_ready;
	pthread_mutex_t	table_mtx;
	pthread_mutex_t	write_mtx;
	t_fork			forks[PHILO_MAX];
	t_philo			philos[PHILO_MAX];
};

// FUNCTION DECLARATIONS

// utils.c
int		ft_atoi(const char *nptr);
bool	handle_mutex(pthread_mutex_t *mutex, t_mutex_code code);
bool	handle_thread(pthread_t *thread, void *(*routine)(void *),
			void *data, t_thread_code code);

// check_input.c
bool	check_input(int argc, char **argv);
void	parse(t_table *p_table, char **argv);

// get_set.c
int		get_int(pthread_mutex_t *mtx, int *source);
bool	set_int(pthread_mutex_t *mtx, int *dest, int value);
bool	get_bool(pthread_mutex_t *mtx, bool *source);
bool	set_bool(pthread_mutex_t *mtx, bool *dest, bool value);
bool	get_end(t_table *table);

// init.c
bool	data_init(t_table *p_table);

// synchro.c
void	wait_threads(t_table *p_table);

// time.c
long	get_time(t_time_code time_code);
void	precise_usleep(long usec, t_table *p_table);

// write.c
bool	write_philo_status(t_philo *philo, t_philo_status status);

#endif
