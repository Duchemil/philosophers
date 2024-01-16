/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduchemi <lduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:29:52 by lduchemi          #+#    #+#             */
/*   Updated: 2024/01/16 16:47:13 by lduchemi         ###   ########.fr       */
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
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		nb_must;
}			t_table;

long int	ft_atoi(const char *str);
int			ft_int(const char *str);
void		ft_threads(long nb);

#endif
