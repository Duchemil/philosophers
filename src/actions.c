/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduchemi <lduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:06:42 by lduchemi          #+#    #+#             */
/*   Updated: 2024/03/21 15:46:20 by lduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_m(char *str, t_philo *philo)
{
	pthread_mutex_lock(philo->write_mut);
	printf("%ld - %d %s\n", get_current_time() - philo->start_time , philo->id, str);
	pthread_mutex_unlock(philo->write_mut);
}

void think(t_philo *philo)
{
	print_m("is thinking", philo);
	usleep(philo->t_sleep * 1000);
}

void	ft_sleep(t_philo *philo)
{
	print_m("is sleeping", philo);
	usleep(philo->t_sleep * 1000);
}

void eat(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	print_m("has taken a fork", philo);
	pthread_mutex_lock(philo->l_fork);
	print_m("has taken a fork", philo);
	philo->last_ate = get_current_time() - philo->start_time;
	print_m("is eating", philo);
	usleep(philo->t_eat * 1000);
	philo->nb_must--;
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
	// reset temps manger
	// mange donc peut mourrir de faim pendant qu'il mange
}
