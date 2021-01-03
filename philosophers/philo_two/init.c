/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmarowak <qmarowak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 11:55:39 by qmarowak          #+#    #+#             */
/*   Updated: 2020/12/20 16:27:45 by qmarowak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		init(t_data *data, int i)
{
	if (!(data->phil[i] = (t_philo*)malloc(sizeof(t_philo))))
	{
		write(1, "Memory allocation error!", 25);
		return (1);
	}
	data->phil[i]->number_ph = i;
	data->phil[i]->data = data;
	data->phil[i]->count_eat = data->count_eat;
	data->phil[i]->message = NULL;
	data->forks[i] = 0;
	return (0);
}

int		allocation_and_init(t_data *data)
{
	if (!(\
	(data->philo_id = (pthread_t*)malloc(sizeof(pthread_t) * data->count_philo))
	&& (data->phil = (t_philo**)malloc(sizeof(t_philo*) * (data->count_philo)))
	&& (data->forks = (int*)malloc(sizeof(int) * data->count_philo))))
	{
		write(1, "Memory allocation error!", 25);
		return (1);
	}
	sem_unlink("forks");
	sem_unlink("stdout");
	if (((data->std_out = sem_open("stdout", O_CREAT, 0700, 1)) == SEM_FAILED)
	|| (data->philo_fork = sem_open("forks", O_CREAT, 0700, data->count_philo))
		== SEM_FAILED)
	{
		write(1, "Failed to initialize semaphore!", 32);
		return (1);
	}
	return (0);
}

int		init_data(t_data *data)
{
	int		i;

	i = -1;
	if (allocation_and_init(data))
		return (1);
	while (++i < data->count_philo)
		if (init(data, i))
			return (1);
	data->count_eat = data->count_philo;
	data->forkiss = data->count_philo;
	return (0);
}
