/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmarowak <qmarowak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 11:58:39 by qmarowak          #+#    #+#             */
/*   Updated: 2020/12/17 11:33:50 by qmarowak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	took_the_forks(t_philo *ph)
{
	if (!ph->data->forkiss)
	{
		message_output(" is thinking", ph);
	}
	sem_wait(ph->data->philo_fork);
	--ph->data->forkiss;
	message_output(" has taken a fork", ph);
	if (!ph->data->forkiss)
		message_output(" is thinking", ph);
	sem_wait(ph->data->philo_fork);
	--ph->data->forkiss;
	message_output(" has taken a fork", ph);
}

void	put_the_forks(t_philo *ph)
{
	sem_post(ph->data->philo_fork);
	++ph->data->forkiss;
	sem_post(ph->data->philo_fork);
	++ph->data->forkiss;
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
