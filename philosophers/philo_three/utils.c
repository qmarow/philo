/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmarowak <qmarowak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 11:42:27 by qmarowak          #+#    #+#             */
/*   Updated: 2020/12/21 19:54:05 by qmarowak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_time(size_t t)
{
	size_t	s;
	size_t	e;

	s = get_time();
	while (1)
	{
		e = get_time();
		if (e - s >= t)
			return ;
		usleep(100);
	}
}

char	*ft_strdup(const char *src)
{
	char	*str;
	int		i;

	i = -1;
	str = (char*)malloc(sizeof(char) * (ft_strlen((char*)src) + 1));
	if (!str)
		return (NULL);
	while (*((char*)src + ++i) != '\0')
		*(str + i) = *(src + i);
	*(str + i) = '\0';
	return (str);
}

char	*ft_strjoin(char *s1, char *s2, int flag)
{
	char	*str;
	int		i;
	int		a;

	i = -1;
	a = -1;
	if (!s1 || !s2)
		return (NULL);
	str = (char*)malloc(sizeof(char) *
	(ft_strlen((char*)s1) + ft_strlen((char*)s2) + 1));
	if (!str)
		return (NULL);
	while (*(s1 + ++i) != '\0')
		*(str + i) = *(s1 + i);
	while (*(s2 + ++a) != '\0')
		*(str + i++) = *(s2 + a);
	*(str + i) = '\0';
	if (flag == 1 || flag == 3)
		free(s1);
	if (flag == 2 || flag == 3)
		free(s2);
	return (str);
}

void	message_output(char *mage, t_philo *ph)
{
	sem_wait(ph->data->std_out);
	ph->message = ft_strjoin(" ", itoa_write(get_time() - ph->start_time), 2);
	ph->message = ft_strjoin(ph->message, " ", 1);
	ph->message = ft_strjoin(ph->message, itoa_write(ph->number_ph + 1), 3);
	ph->message = ft_strjoin(ph->message, mage, 1);
	ph->message = ft_strjoin(ph->message, "\n", 1);
	write(1, ph->message, ft_strlen(ph->message));
	free(ph->message);
	ph->message = NULL;
	sem_post(ph->data->std_out);
}
