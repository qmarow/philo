/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmarowak <qmarowak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 14:10:08 by qmarowak          #+#    #+#             */
/*   Updated: 2020/12/21 18:06:45 by qmarowak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		parsing_argument(char **argv, t_data *data)
{
	if ((data->count_philo = ft_atoi(argv[1])) < 1)
		write(1, "Invalid first argument!", 24);
	else if ((data->t_live = ft_atoi(argv[2])) < 0)
		write(1, "Invalid second argument!", 25);
	else if ((data->t_eat = ft_atoi(argv[3])) < 0)
		write(1, "Invalid third argument!", 24);
	else if ((data->t_sleep = ft_atoi(argv[4])) < 0)
		write(1, "Invalid fourth argument!", 25);
	else if ((data->count_eat = ft_atoi(argv[5])) == -1)
		write(1, "Invalid five argument!", 23);
	else
		return (0);
	return (1);
}

int		main(int argc, char **argv)
{
	t_data		*data;

	data = (t_data*)malloc(sizeof(t_data));
	if (argc != 5 && argc != 6)
	{
		write(1, "Wrong number of arguments!", 27);
		free(data);
		return (-1);
	}
	if (parsing_argument(argv, data))
	{
		free(data);
		return (1);
	}
	if (!init_data(data))
		start(data);
	frees(data);
	return (0);
}
