/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduchemi <lduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:31:26 by lduchemi          #+#    #+#             */
/*   Updated: 2024/02/16 14:29:13 by lduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// void	initializeTable(t_table *table, int nb_philo, int t_die, int t_eat,
// 		int t_sleep)
// {
// 	int	i;

// 	i = 0;
// 	table->philos= malloc(nb_philo * sizeof(t_philo));
// 	if (!table->philos)
// 		return ;
// 	table->t_die = t_die;
// 	table->t_eat = t_eat;
// 	table->t_sleep = t_sleep;
// 	table->nb_philosophers = nb_philo;
// 	while (i < table->nb_philosophers)
// 	{
// 		table->philosopher[i].is_eating = 0;
// 		table->philosopher[i].is_sleeping = 0;
// 		table->philosopher[i].is_thinking = 0;
// 		table->philosopher[i].is_dead = 0;
// 		table->philosopher[i].last_ate = 0;
// 		i++;
// 	}
// }

void	*threadFunction(void *arg)
{
	long				i;
	pthread_mutex_t	printMutexx;
	long long		timestamp;

	i = (long) arg;
	pthread_mutex_init(&printMutexx, NULL);
	timestamp = getCurrentTimeMillis();
	pthread_mutex_lock(&printMutexx);
	printf("[%lld ms] - %ld is eating\n", timestamp, i);
	pthread_mutex_unlock(&printMutexx);
	pthread_mutex_destroy(&printMutexx);
	return (NULL);
}

// void	ft_threads(t_table *table)
// {
// 	pthread_t	*threads;
// 	long	i;

// 	i = 1;
// 	threads = malloc(table->nb_philosophers * sizeof(pthread_t));
// 	if (!threads)
// 		return ;
// 	pthread_mutex_init(&table->printMutex, NULL);
// 	while (i <= table->nb_philosophers)
// 	{
// 		if (pthread_create(&threads[i - 1], NULL, threadFunction,
// 				(void *)i) != 0)
// 			return (free(threads));
// 		pthread_mutex_lock(&table->printMutex);
// 		i++;
// 		pthread_mutex_unlock(&table->printMutex);
// 		usleep(500);
// 	}
// 	i = 1;
// 	while (i <= table->nb_philosophers)
// 	{
// 		if (pthread_join(threads[i - 1], NULL) != 0)
// 			printf("Error joining thread %ld\n", i);
// 		pthread_mutex_lock(&table->printMutex);
// 		i++;
// 		pthread_mutex_unlock(&table->printMutex);
// 	}
// 	printf("Main: All threads have finished\n");
// 	pthread_mutex_destroy(&table->printMutex);
// 	free(threads);
// }

int	main(int argc, char **argv)
{
	int		i;
	t_table	*table;

	i = 1;
	if (argc == 5 || argc == 6)
	{
		while (argv[i])
		{
			if (ft_int(argv[i]) != 0 || ft_atoi(argv[i]) < 0)
				return (1);
			init_philo();
			i++;
		}
		ft_threads(&table);
	}
	else
		return (1);
	// free(table.philosopher);
	return (0);
}
