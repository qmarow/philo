/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmarowak <qmarowak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 11:33:44 by qmarowak          #+#    #+#             */
/*   Updated: 2020/12/21 20:24:28 by qmarowak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_die(t_philo *ph)
{
	ph->message = ft_strjoin(" ", itoa_write(get_time() - ph->start_time), 2);
	ph->message = ft_strjoin(ph->message, " ", 1);
	ph->message = ft_strjoin(ph->message, itoa_write(ph->number_ph + 1), 3);
	ph->message = ft_strjoin(ph->message, " is die", 1);
	ph->message = ft_strjoin(ph->message, "\n", 1);
	write(1, ph->message, ft_strlen(ph->message));
	free(ph->message);
	ph->message = NULL;
}

void	*fun_death(void *data)
{
	t_philo *ph;

	ph = (t_philo*)data;
	while (1)
	{
		ph->time_death = get_time();
		if (ph->time_death - ph->begining_life > ph->data->t_live \
			&& ph->count_eat)
		{
			sem_wait(ph->data->std_out);
			print_die(ph);
			sem_post(ph->data->death);
			exit(0);
		}
		else if (ph->flag == 1 || ph->flag == 2)
		{
			usleep(50);
			if (ph->flag == 1 || ph->flag == 2)
			{
				message_output(" is thinking", ph);
				ph->flag = 0;
			}
		}
		usleep(50);
	}
}

void	simulation(t_philo *data)
{
	data->start_time = get_time();
	data->begining_life = get_time();
	pthread_create(&data->death, NULL, &fun_death, (void*)data);
	pthread_detach(data->death);
	while (1)
	{
		took_the_forks(data);
		eating(data);
		put_the_forks(data);
		if (data->count_eat == 0)
		{
			sem_post(data->data->swaiter);
			exit(0);
		}
		sleeping(data);
	}
}

void	fun_waiter(t_data *data)
{
	while (data->count_philo--)
		sem_wait(data->swaiter);
	sem_post(data->death);
	exit(0);
}

int		start(t_data *data)
{
	pid_t	waiter;
	int		i;
	int		status;

	i = -1;
	data->flag = 0;
	while (++i < data->count_philo)
	{
		data->philo_id[i] = fork();
		if (data->philo_id[i] == 0)
			simulation(data->phil[i]);
	}
	if ((waiter = fork()) == 0)
		fun_waiter(data);
	sem_wait(data->death);
	sem_wait(data->death);
	i = -1;
	kill(waiter, SIGKILL);
	while (++i < data->count_philo)
		kill(data->philo_id[i], SIGKILL);
	return (1);
}
