/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduchemi <lduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:05:51 by lduchemi          #+#    #+#             */
/*   Updated: 2024/03/19 17:38:33 by lduchemi         ###   ########.fr       */
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
		philos[i].dead_mut = &table->dead_mut;
		philos[i].eat_mut = &table->eat_mut;
		philos[i].write_mut = &table->write_mut;
		philos[i].l_fork = &forks[i];
		if (i == 0)
			philos[i].r_fork = &forks[philos[i].nb_philo - 1];
		else
			philos[i].r_fork = &forks[i - 1];
		i++;
	}
}

void	init_input(t_philo *philo, char **argv)
{
	philo->nb_philo = ft_atoi(argv[1]);
	philo->t_die = ft_atoi(argv[2]);
	philo->t_eat = ft_atoi(argv[3]);
	philo->t_sleep = ft_atoi(argv[4]);
	if (argv[5])
		philo->nb_must = ft_atoi(argv[5]);
	else
		philo->nb_must = -1;
}

void	init_table(t_table *table, t_philo *philos)
{
	table->philos = philos;
	table->dead = 0;
	pthread_mutex_init(&table->write_mut, NULL);
	pthread_mutex_init(&table->eat_mut, NULL);
	pthread_mutex_init(&table->dead_mut, NULL);
}

void init_forks(pthread_mutex_t *forks, int philo_nb)
{
	int	i;

	i = 0;
	while (i < philo_nb)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}
