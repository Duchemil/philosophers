/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduchemi <lduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:49:36 by lduchemi          #+#    #+#             */
/*   Updated: 2024/03/22 17:28:50 by lduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	dead_while(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_mut);
	if (*philo->is_dead == 1)
	{
		pthread_mutex_unlock(philo->dead_mut);
		return (1);
	}
	pthread_mutex_unlock(philo->dead_mut);
	return (0);
}

int	check_last_meal(t_philo *philo)
{
	pthread_mutex_lock(philo->eat_mut);
	if (get_current_time() - philo->last_ate >= philo->t_die
		&& philo->is_eating == 0)
	{
		pthread_mutex_unlock(philo->eat_mut);
		return (1);
	}
	pthread_mutex_unlock(philo->eat_mut);
	return (0);
}

int	check_if_dead(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos[0].nb_philo)
	{
		if (check_last_meal(&philos[i]))
		{
			print_m("died", &philos[i]);
			pthread_mutex_lock(philos[0].dead_mut);
			*philos->is_dead = 1;
			pthread_mutex_unlock(philos[0].dead_mut);
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_if_ate(t_philo *philos)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (philos->nb_must == -1)
		return (0);
	while (i < philos[0].nb_philo)
	{
		pthread_mutex_lock(philos[i].eat_mut);
		if (philos[i].meals_eaten >= philos[i].nb_must)
			j++;
		pthread_mutex_unlock(philos[i].eat_mut);
		i++;
	}
	if (j == philos[0].nb_philo)
	{
		pthread_mutex_lock(philos[0].dead_mut);
		*philos->is_dead = 1;
		pthread_mutex_unlock(philos[0].dead_mut);
		return (1);
	}
	return (0);
}
