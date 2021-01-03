/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmarowak <qmarowak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 11:45:14 by qmarowak          #+#    #+#             */
/*   Updated: 2020/12/21 20:00:31 by qmarowak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	perevod(char *str, int i, int f)
{
	unsigned long		a;

	a = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		a = a * 10 + str[i] - '0';
		++i;
		if (f == -1 && a > 9223372036854775807)
			return (0);
		if (a > 9223372036854775807 && f)
			return (-1);
	}
	if (str[i] != 0)
		return (-1);
	return ((int)a);
}

int			ft_atoi(char *str)
{
	int i;
	int f;

	i = 0;
	f = 1;
	if (!str)
		return (-2);
	while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n')
	|| (str[i] == '\v') || (str[i] == '\r') || (str[i] == '\f'))
		++i;
	if (str[i] == '+')
		return (perevod(str, ++i, f));
	if (str[i] == '-')
		return (perevod(str, ++i, f * -1) * -1);
	if (str[i] >= '0' && str[i] <= '9')
		return (perevod(str, i, f));
	return (-1);
}

size_t		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

char		*itoa_write(int num)
{
	char	*str;
	int		i;
	int		copy_num;

	copy_num = num;
	i = 0;
	if (num == 0)
		return (ft_strdup("0"));
	while (copy_num && ++i)
		copy_num /= 10;
	if (!(str = (char*)malloc(sizeof(char) * (i + 1))))
		write(1, "Memory allocation error!", 28);
	str[i] = 0;
	while (--i >= 0 && num && ((copy_num = num % 10) || !(copy_num)) \
	&& ((num /= 10) || !(num)))
		str[i] = copy_num + '0';
	return (str);
}

size_t		get_time(void)
{
	static struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}
