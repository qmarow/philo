/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmarowak <qmarowak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 11:33:44 by qmarowak          #+#    #+#             */
/*   Updated: 2020/12/20 19:15:09 by qmarowak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	reaper_of_death(t_data *data, int i)
{
	while (1)
	{
		while (++i < data->count_philo)
		{
			data->phil[i]->time_death = get_time();
			if (data->phil[i]->time_death - data->phil[i]->begining_life \
			> \
			data->phil[i]->data->t_live \
			&& data->phil[i]->count_eat)
			{
				message_output(" died", data->phil[i]);
				pthread_mutex_lock(&data->std_out);
				return ;
			}
			else if (!data->count_eat)
			{
				pthread_mutex_lock(&data->std_out);
				return ;
			}
			usleep(50);
		}
		i = -1;
	}
}

void	start_even_ph(t_data *data, int i)
{
	while (++i < data->count_philo)
	{
		if (!i || i % 2 == 0)
		{
			pthread_create(&data->philo_id[i], NULL, &simulation, \
											(void*)data->phil[i]);
		}
	}
	i = -1;
	while (++i < data->count_philo)
	{
		if (!i || i % 2 == 0)
		{
			pthread_detach(data->philo_id[i]);
		}
	}
}

void	start_uneven_ph(t_data *data, int i)
{
	while (++i < data->count_philo)
	{
		if (i % 2 != 0)
		{
			pthread_create(&data->philo_id[i], NULL, &simulation, \
											(void*)data->phil[i]);
		}
	}
	i = -1;
	while (++i < data->count_philo)
	{
		if (i % 2 != 0)
		{
			pthread_detach(data->philo_id[i]);
		}
	}
}

void	start(t_data *data)
{
	start_even_ph(data, -1);
	usleep(100);
	start_uneven_ph(data, -1);
	reaper_of_death(data, -1);
}
