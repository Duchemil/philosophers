/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduchemi <lduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:29:52 by lduchemi          #+#    #+#             */
/*   Updated: 2024/01/30 16:12:24 by lduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <fcntl.h>
# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				is_eating;
	int				is_dead;
	int				meals_eaten;
	int				nb_must;
	int				nb_philo;
	size_t			last_ate;
	size_t			start_time;
	size_t				t_die;
	size_t				t_eat;
	size_t				t_sleep;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
}					t_philo;

typedef struct s_table
{
	t_philo			*philos;
	int				dead;
}					t_table;

long int			ft_atoi(const char *str);
int					ft_int(const char *str);
void				initializeTable(t_table *table, int nb_philo, int t_die,
						int t_eat, int t_sleep);
void				ft_threads(t_table *table);
long long			getCurrentTimeMillis(void);

#endif
