/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmarowak <qmarowak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 14:50:41 by qmarowak          #+#    #+#             */
/*   Updated: 2020/12/20 16:18:06 by qmarowak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*simulation(void *data)
{
	t_philo		*ph;

	ph = (t_philo*)data;
	ph->begining_life = get_time();
	ph->start_time = get_time();
	while (1)
	{
		took_the_forks(ph);
		eating(ph);
		put_the_forks(ph);
		if (ph->count_eat == 0)
		{
			--ph->data->count_eat;
			while (1)
				sleep(1000000);
		}
		sleeping(ph);
	}
}

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
				sem_wait(data->std_out);
				return ;
			}
			else if (!data->count_eat)
			{
				sem_wait(data->std_out);
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
