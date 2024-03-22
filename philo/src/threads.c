/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduchemi <lduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:00:51 by lduchemi          #+#    #+#             */
/*   Updated: 2024/03/22 17:40:10 by lduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	destroy_f(t_table *table, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&table->dead_mut);
	pthread_mutex_destroy(&table->eat_mut);
	pthread_mutex_destroy(&table->write_mut);
	while (i < table->philos[0].nb_philo)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
}

void	*philo_steps(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		usleep((philo->t_eat + 10) * 1000);
	while (!dead_while(philo))
	{
		if (philo->id % 2 == 0)
			eat2(philo);
		else
			eat(philo);
		ft_sleep(philo);
		think(philo);
	}
	return (arg);
}

void	*checks_philos(void *arg)
{
	t_philo	*philos;

	philos = (t_philo *)arg;
	while (1)
	{
		if (check_if_dead(philos) == 1 || check_if_ate(philos) == 1)
			break ;
		usleep(5000);
	}
	return (arg);
}

int	create_threads(t_table *table, pthread_mutex_t *forks)
{
	pthread_t	checks;
	long		i;

	if (pthread_create(&checks, NULL, &checks_philos, table->philos) != 0)
		destroy_f(table, forks);
	i = 0;
	while (i < table->philos[0].nb_philo)
	{
		if (pthread_create(&table->philos[i].thread, NULL, &philo_steps,
				&table->philos[i]) != 0)
			destroy_f(table, forks);
		i++;
	}
	i = 0;
	if (pthread_join(checks, NULL) != 0)
		destroy_f(table, forks);
	while (i < table->philos[0].nb_philo)
	{
		if (pthread_join(table->philos[i].thread, NULL) != 0)
			destroy_f(table, forks);
		i++;
	}
	return (0);
}
