/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmarowak <qmarowak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 11:59:47 by qmarowak          #+#    #+#             */
/*   Updated: 2020/12/17 11:33:06 by qmarowak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	frees(t_data *data)
{
	while (--data->count_philo >= 0)
	{
		free(data->phil[data->count_philo]);
	}
	free(data->forks);
	free(data->phil);
	free(data->philo_id);
	free(data);
}
