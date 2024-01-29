/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduchemi <lduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:31:26 by lduchemi          #+#    #+#             */
/*   Updated: 2024/01/29 17:19:36 by lduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	int		i;
	t_table	table;

	i = 1;
	if (argc == 5 || argc == 6)
	{
		while (argv[i])
		{
			if (ft_int(argv[i]) != 0 || ft_atoi(argv[i]) < 0)
				return (1);
			i++;
		}
		if (argc == 6)
			table.nb_must = atoi(argv[5]);
		initializeTable(&table, ft_atoi(argv[1]), ft_atoi(argv[2]),
				ft_atoi(argv[3]), ft_atoi(argv[4]));
		ft_threads(&table);
	}
	else
		return (1);
	free(table.philosopher);
	return (0);
}

void	initializeTable(t_table *table, int nb_philo, int t_die, int t_eat,
		int t_sleep)
{
	int	i;

	i = 0;
	table->philosopher = malloc(nb_philo * sizeof(t_philo));
	if (!table->philosopher)
		return ;
	table->t_die = t_die;
	table->t_eat = t_eat;
	table->t_sleep = t_sleep;
	table->nb_philosophers = nb_philo;
	while (i < table->nb_philosophers)
	{
		table->philosopher[i].is_eating = 0;
		table->philosopher[i].is_sleeping = 0;
		table->philosopher[i].is_thinking = 0;
		table->philosopher[i].is_dead = 0;
		table->philosopher[i].last_ate = 0;
		i++;
	}
}

long long	getCurrentTimeMillis(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((long long)(tv.tv_usec) / 100);
}

void	*threadFunction(void *arg)
{
	t_table			*table;

	long long		timestamp;

	table = (t_table *)arg;
	const int i = table->i;
	//pthread_mutex_lock(&table->printMutex);
	// printf("A : %d\n", table->i);
	timestamp = getCurrentTimeMillis();
	while (1)
	{
		printf("%d       [%lld ms] - %d is eating\n", i, timestamp, table->i);

	}//pthread_mutex_unlock(&table->printMutex);
	sleep(1);
	return (NULL);
}

void	ft_threads(t_table *table)
{
	pthread_t	*threads;

	table->i = 1;
	threads = malloc(table->nb_philosophers * sizeof(pthread_t));
	if (!threads)
		return ;
	pthread_mutex_init(&table->printMutex, NULL);
	while (table->i <= table->nb_philosophers)
	{
		// printf("I : %d\n", table->i);
		if (pthread_create(&threads[table->i-1], NULL, threadFunction,
				(void *)table) != 0)
			return (free(threads));
		sleep(3);
		//pthread_mutex_lock(&table->printMutex);
		table->i++;
		//pthread_mutex_unlock(&table->printMutex);
	}
	table->i = 1;
	while (table->i <= table->nb_philosophers)
	{
		if (pthread_join(threads[table->i - 1], NULL) != 0)
			printf("Error joining thread %d\n", table->i);
		//pthread_mutex_lock(&table->printMutex);
		table->i++;
		//pthread_mutex_unlock(&table->printMutex);
	}
	printf("Main: All threads have finished\n");
	pthread_mutex_destroy(&table->printMutex);
	free(threads);
}
