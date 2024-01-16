/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduchemi <lduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:31:26 by lduchemi          #+#    #+#             */
/*   Updated: 2024/01/16 16:31:20 by lduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"


int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc == 2)
	{
		while (argv[i])
		{
			if (ft_int(argv[i]) != 0 || ft_atoi(argv[i]) < 0)
				return (1);
			i++;
		}
		ft_threads(ft_atoi(argv[1]));
	}
	else
		return (1);
	return (0);
}

long long	getCurrentTimeMillis(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((long long)(tv.tv_usec) / 1000);
}

void	*threadFunction(void *arg)
{
	pthread_mutex_t	printMutex = PTHREAD_MUTEX_INITIALIZER;
	long		threadNumber;
	long long	timestamp;

	threadNumber = (long)arg;
	timestamp = getCurrentTimeMillis();
	pthread_mutex_lock(&printMutex);
	printf("[%lld ms] Philospher %ld is eating\n", timestamp, threadNumber);
	pthread_mutex_unlock(&printMutex);
	return NULL;
}

void	ft_threads(long nb)
{
	pthread_t	*threads;
	long		i;

	i = 1;
	threads = malloc(nb * sizeof(pthread_t));
	if (!threads)
		return ;
	while (i <= nb)
	{
		if (pthread_create(&threads[i - 1], NULL, threadFunction,
				(void *)i) != 0)
			return (free(threads));
		i++;
	}
	i = 1;
	while (i <= nb)
	{
		if (pthread_join(threads[i - 1], NULL) != 0)
			printf("Error joining thread %ld\n", i);
		i++;
	}
	printf("Main: All threads have finished\n");
	free(threads);
}
