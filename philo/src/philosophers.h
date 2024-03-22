/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduchemi <lduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:29:52 by lduchemi          #+#    #+#             */
/*   Updated: 2024/03/22 17:21:04 by lduchemi         ###   ########.fr       */
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
	int				*is_dead;
	int				meals_eaten;
	int				nb_must;
	int				nb_philo;
	size_t			last_ate;
	size_t			start_time;
	size_t			t_die;
	size_t			t_eat;
	size_t			t_sleep;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*write_mut;
	pthread_mutex_t	*eat_mut;
	pthread_mutex_t	*dead_mut;
}					t_philo;

typedef struct s_table
{
	t_philo			*philos;
	pthread_mutex_t	write_mut;
	pthread_mutex_t	eat_mut;
	pthread_mutex_t	dead_mut;
	int				dead;
}					t_table;

long int			ft_atoi(const char *str);
int					ft_int(const char *str);
size_t				get_current_time(void);
int					create_threads(t_table *table, pthread_mutex_t *forks);
void				init_philo(t_philo *philos, t_table *table,
						pthread_mutex_t *forks, char **argv);
void				init_input(t_philo *philo, char **argv);
void				init_table(t_table *table, t_philo *philos);
void				init_forks(pthread_mutex_t *forks, int philo_nb);
void				print_m(char *str, t_philo *philo);
void				think(t_philo *philo);
void				ft_sleep(t_philo *philo);
void				eat(t_philo *philo);
void				eat2(t_philo *philo);
int					dead_while(t_philo *philo);
int					check_if_dead(t_philo *philos);
void				destroy_f(t_table *table, pthread_mutex_t *forks);
int					check_if_ate(t_philo *philos);
#endif
