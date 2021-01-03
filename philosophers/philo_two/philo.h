/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmarowak <qmarowak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 16:32:22 by qmarowak          #+#    #+#             */
/*   Updated: 2020/12/20 16:33:31 by qmarowak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <semaphore.h>
# include <stdio.h>
# include <sys/time.h>
# include <stdlib.h>
# include <sys/types.h>
# include <time.h>
# include <sys/stat.h>
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
	pthread_t		speaker;
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
	int				forkiss;
	pthread_t		*philo_id;
	sem_t			*std_out;
	sem_t			*philo_fork;
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
char				*itoa_write(int num);
void				start(t_data *data);

#endif
