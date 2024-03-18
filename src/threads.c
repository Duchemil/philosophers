/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduchemi <lduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:00:51 by lduchemi          #+#    #+#             */
/*   Updated: 2024/03/18 17:10:18 by lduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo_steps(void)
{
}

void	create_threads(t_table *table, pthread_mutex_t *forks)
{
	pthread_t	*threads;
	long		i;

	i = 1;
	while (i < table->philos[0].nb_philo)
	{
		if (pthread_create(&table->philos[i].thread, NULL, philo_steps,
					&table->philos[i].thread) != 0)
				return (1); // destroy threads + free
	}
}
