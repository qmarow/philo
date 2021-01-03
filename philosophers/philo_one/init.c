/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmarowak <qmarowak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 11:55:39 by qmarowak          #+#    #+#             */
/*   Updated: 2020/12/20 13:33:32 by qmarowak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	left_and_right(t_data *data, int i)
{
	if (!(!i || i % 2 == 0))
	{
		data->phil[i]->left_fork = data->phil[i]->number_ph;
		if (i == data->count_philo - 1)
			data->phil[i]->right_fork = 0;
		else
			data->phil[i]->right_fork = data->phil[i]->number_ph + 1;
	}
	else
	{
		data->phil[i]->right_fork = data->phil[i]->number_ph;
		if (i == data->count_philo - 1)
			data->phil[i]->left_fork = 0;
		else
			data->phil[i]->left_fork = data->phil[i]->number_ph + 1;
	}
}

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
	left_and_right(data, i);
	if (pthread_mutex_init(&data->philo_fork[i], NULL))
	{
		write(1, "Failed to initialize mutex!", 27);
		return (1);
	}
	return (0);
}

int		init_data(t_data *data)
{
	int		i;

	i = -1;
	if (!(\
	(data->philo_id = (pthread_t*)malloc(sizeof(pthread_t) * data->count_philo))
	&& (data->phil = (t_philo**)malloc(sizeof(t_philo*) * (data->count_philo)))
	&& (data->philo_fork = \
		(pthread_mutex_t*)malloc(sizeof(pthread_mutex_t) * data->count_philo))
	&& (data->forks = (int*)malloc(sizeof(int) * data->count_philo))))
	{
		write(1, "Memory allocation error!", 25);
		return (1);
	}
	if (pthread_mutex_init(&data->std_out, NULL) ||
	pthread_mutex_init(&data->mutexx, NULL))
	{
		write(1, "Failed to initialize mutex!", 27);
		return (1);
	}
	while (++i < data->count_philo)
		if ((init(data, i)))
			return (1);
	data->count_eat = data->count_philo;
	return (0);
}
