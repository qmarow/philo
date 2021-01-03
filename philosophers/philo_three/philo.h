/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmarowak <qmarowak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 14:47:56 by qmarowak          #+#    #+#             */
/*   Updated: 2020/12/21 19:41:28 by qmarowak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <semaphore.h>
# include <stdio.h>
# include <sys/time.h>
# include <stdlib.h>
# include <time.h>
# include <pthread.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <signal.h>

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
	int				flag;
	char			*message;
	pthread_t		death;
	struct s_data	*data;
}					t_philo;

typedef struct		s_data
{
	int				t_live;
	int				flag;
	int				t_eat;
	int				t_sleep;
	int				count_philo;
	int				count_eat;
	int				*forks;
	pid_t			*philo_id;
	sem_t			*std_out;
	sem_t			*death;
	sem_t			*philo_fork;
	sem_t			*swaiter;
	t_philo			**phil;
}					t_data;

char				*ft_strjoin(char *s1, char *s2, int flag);
char				*ft_strdup(const char *src);
size_t				ft_strlen(char *str);
int					init_data(t_data *data);
int					ft_atoi(char *str);
void				message_output(char *message, t_philo *ph);
size_t				get_time(void);
void				ft_time(size_t t);
void				took_the_forks(t_philo *data);
void				put_the_forks(t_philo *ph);
void				eating(t_philo *ph);
void				frees(t_data *data);
void				sleeping(t_philo *ph);
char				*itoa_write(int num);
int					start(t_data *data);

#endif
