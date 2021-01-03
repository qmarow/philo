/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmarowak <qmarowak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 12:52:25 by qmarowak          #+#    #+#             */
/*   Updated: 2020/12/20 14:11:31 by qmarowak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <stdlib.h>
# include <sys/types.h>
# include <time.h>
# include <pthread.h>

struct s_data;

typedef	struct		s_philo
{
	int				number_ph;
	long int		begining_life;
	long int		time_death;
	long int		start_time;
	int				count_eat;
	int				left_fork;
	int				right_fork;
	char			*message;
	pthread_t		death;
	struct s_data	*data;
}					t_philo;

typedef struct		s_data
{
	int				t_live;
	int				t_eat;
	int				t_sleep;
	int				count_philo;
	int				count_eat;
	int				*forks;
	pthread_t		*philo_id;
	pthread_mutex_t	std_out;
	pthread_mutex_t	mutexx;
	pthread_mutex_t	*philo_fork;
	t_philo			**phil;
}					t_data;

void				ft_error(char *str, t_data *data);
char				*ft_strdup(const char *src);
size_t				ft_strlen(char *str);
int					init_data(t_data *data);
int					ft_atoi(char *str);
void				message_output(char *message, t_philo *data);
size_t				get_time(void);
void				ft_time(size_t t);
void				took_the_forks(t_philo *ph);
void				put_the_forks(t_philo *ph);
void				eating(t_philo *ph);
void				frees(t_data *data);
void				sleeping(t_philo *ph);
void				*simulation(void *data);
char				*itoa_write(int num);
void				start(t_data *data);

#endif
