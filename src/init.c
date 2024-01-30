/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduchemi <lduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:05:51 by lduchemi          #+#    #+#             */
/*   Updated: 2024/01/30 16:12:25 by lduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_philo(t_philo *philos, t_table *table, pthread_mutex_t *forks,
		char **argv)
{
	int	i;

	i = 0;
	while (i < ft_atoi(argv[1]))
	{
		philos[i].id = i + 1;
		philos[i].is_eating = 0;
		philos[i].is_dead = 0;
		philos[i].meals_eaten = 0;
		init_input(&philos[i], argv);
		philos[i].last_ate = get_current_time();
		philos[i].start_time = get_current_time();
	}
}

void	init_input(t_philo *philo, char **argv)
{
	philo->nb_philo = ft_atoi(argv[1]);
	philo->t_die = ft_atoi(argv[2]);
	philo->t_eat = ft_atoi(argv[3]);
	philo->t_sleep = ft_atoi(argv[4]);
	if (argv[5])
		philo->nb_must = (argv[5]);
	else
		philo->nb_must = -1;
}
