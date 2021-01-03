/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmarowak <qmarowak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 11:58:39 by qmarowak          #+#    #+#             */
/*   Updated: 2020/12/21 19:13:32 by qmarowak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	took_the_forks(t_philo *ph)
{
	ph->flag = 1;
	sem_wait(ph->data->philo_fork);
	message_output(" has taken a fork", ph);
	ph->flag = 2;
	sem_wait(ph->data->philo_fork);
	message_output(" has taken a fork", ph);
	ph->flag = 0;
}

void	put_the_forks(t_philo *ph)
{
	sem_post(ph->data->philo_fork);
	sem_post(ph->data->philo_fork);
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
