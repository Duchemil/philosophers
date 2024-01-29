/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduchemi <lduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:29:52 by lduchemi          #+#    #+#             */
/*   Updated: 2024/01/29 16:29:12 by lduchemi         ###   ########.fr       */
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
	int		is_eating;
	int		is_sleeping;
	int		is_thinking;
	int		is_dead;
	long	last_ate;
}			t_philo;

typedef struct s_table
{
	t_philo	*philosopher;
	int		nb_philosophers;
	int		t_die;
	int		t_eat;
	int		t_sleep;
	int		nb_must;
	int		i;
	pthread_mutex_t	printMutex;
}			t_table;

long int	ft_atoi(const char *str);
int			ft_int(const char *str);
void		initializeTable(t_table *table, int nb_philo, int t_die, int t_eat,
				int t_sleep);
void		ft_threads(t_table *table);

#endif
