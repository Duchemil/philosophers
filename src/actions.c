/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduchemi <lduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:06:42 by lduchemi          #+#    #+#             */
/*   Updated: 2024/03/22 16:38:48 by lduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_m(char *str, t_philo *philo)
{
	pthread_mutex_lock(philo->write_mut);
	if (!dead_while(philo))
		printf("%ld - %d %s\n", get_current_time() - philo->start_time,
			philo->id, str);
	pthread_mutex_unlock(philo->write_mut);
}

void	think(t_philo *philo)
{
	print_m("is thinking", philo);
}

void	ft_sleep(t_philo *philo)
{
	if (philo->nb_philo > 1)
		print_m("is sleeping", philo);
	usleep(philo->t_sleep * 1000);
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	print_m("has taken a fork", philo);
	if (philo->nb_philo == 1)
	{
		usleep(philo->t_die * 1000);
		pthread_mutex_unlock(philo->r_fork);
		return ;
	}
	pthread_mutex_lock(philo->l_fork);
	print_m("has taken a fork", philo);
	philo->is_eating = 1;
	print_m("is eating", philo);
	pthread_mutex_lock(philo->eat_mut);
	philo->last_ate = get_current_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->eat_mut);
	usleep(philo->t_eat * 1000);
	philo->is_eating = 0;
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}
