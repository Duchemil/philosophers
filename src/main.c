/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduchemi <lduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:31:26 by lduchemi          #+#    #+#             */
/*   Updated: 2024/03/22 16:13:50 by lduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_input_validity(int argc, char **argv)
{
	int	nb_philo;
	int	t_die;
	int	t_eat;
	int	t_sleep;
	int	nb_must;

	nb_philo = ft_atoi(argv[1]);
	t_die = ft_atoi(argv[2]);
	t_eat = ft_atoi(argv[3]);
	t_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		nb_must = ft_atoi(argv[5]);
	else
		nb_must = 1;
	if (nb_philo <= 0 || t_die <= 0 || t_eat <= 0 || t_sleep <= 0 || (nb_must
			!= -1 && nb_must <= 0))
	{
		printf("Args' numbers aren't correct\n");
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_table			table;
	t_philo			*philos;
	pthread_mutex_t	*forks;

	if (argc == 5 || argc == 6)
	{
		if (check_input_validity(argc, argv) == 1)
			return (1);
		philos = (t_philo *)malloc(sizeof(t_philo) * ft_atoi(argv[1]));
		if (!philos)
			return (1);
		forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
				* ft_atoi(argv[1]));
		if (!forks)
			return (1);
		init_table(&table, philos);
		init_forks(forks, ft_atoi(argv[1]));
		init_philo(philos, &table, forks, argv);
		create_threads(&table, forks);
	}
	free(forks);
	free(philos);
	return (0);
}
