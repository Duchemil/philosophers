/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduchemi <lduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:00:51 by lduchemi          #+#    #+#             */
/*   Updated: 2024/03/19 17:39:21 by lduchemi         ###   ########.fr       */
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
	while(i < table->philos[0].nb_philo)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
}

void	*philo_steps(void *arg)
{
	t_philo *philo;
	long time;

	philo = (t_philo *) arg;
	time = philo->start_time;

	pthread_mutex_lock(&philo->write_mut);
	printf("%ld - %d is twerking\n", get_current_time() - time , philo->id);
	pthread_mutex_unlock(&philo->write_mut);
	philo->last_ate = get_current_time();
	return (NULL);
}

int	create_threads(t_table *table, pthread_mutex_t *forks)
{
	long		i;

	i = 0;
	// if (pthread_create(threads, NULL, philo_steps, &table->philos) != 0)
	while (i < table->philos[0].nb_philo)
	{
		if (pthread_create(&table->philos[i].thread, NULL, philo_steps,
					&table->philos[i]) != 0)
				destroy_f(table, forks);
		i++;
	}
	i = 0;
	while (i < table->philos[0].nb_philo)
	{
		if (pthread_join(table->philos[i].thread, NULL) != 0)
			destroy_f(table, forks);
		i++;
	}
	return (0);
}
