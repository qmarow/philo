/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmarowak <qmarowak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 11:58:39 by qmarowak          #+#    #+#             */
/*   Updated: 2020/12/20 19:12:33 by qmarowak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	took_the_forks(t_philo *ph)
{
	if (ph->data->forks[ph->left_fork] == 1)
		message_output(" is thinking", ph);
	pthread_mutex_lock(&ph->data->philo_fork[ph->left_fork]);
	ph->data->forks[ph->left_fork] = 1;
	message_output("  has taken a fork", ph);
	if (ph->data->forks[ph->right_fork] == 1)
		message_output(" is thinking", ph);
	pthread_mutex_lock(&ph->data->philo_fork[ph->right_fork]);
	ph->data->forks[ph->right_fork] = 1;
	message_output("  has taken a fork", ph);
}

void	put_the_forks(t_philo *ph)
{
	pthread_mutex_unlock(&ph->data->philo_fork[ph->left_fork]);
	ph->data->forks[ph->left_fork] = 0;
	pthread_mutex_unlock(&ph->data->philo_fork[ph->right_fork]);
	ph->data->forks[ph->right_fork] = 0;
}

void	eating(t_philo *ph)
{
	message_output(" is eating", ph);
	ft_time(ph->data->t_eat);
	ph->begining_life = get_time();
	if (ph->count_eat != -2)
		--ph->count_eat;
}

void	sleeping(t_philo *ph)
{
	message_output(" is sleeping", ph);
	ft_time(ph->data->t_sleep);
}

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
				usleep(1000);
		}
		sleeping(ph);
	}
}
