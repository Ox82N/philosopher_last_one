/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenjair <obenjair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 22:33:06 by obenjair          #+#    #+#             */
/*   Updated: 2022/08/26 18:21:44 by obenjair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_monitor_eat_philo(void *argv)
{
	t_info	*info;

	info = argv;
	while (!info->finish)
	{
		pthread_mutex_lock(&info->finish_mutex);
		if (info->num_of_times_each_philosopher_must_eat == info->num_of_philo)
			info->finish = 1;
		pthread_mutex_unlock(&info->finish_mutex);
	}
	return (NULL);
}
/* To know the current time in milliseconds with gettimeofday */
/* if ms is bigger than time_to_die print "died" */
void	*monitoreee(void *argv)
{
	t_philo			*philo;
	struct timeval	now;
	long long		ms;

	philo = argv;
	while (!philo->info->finish)
	{
		pthread_mutex_lock(&philo->check_mutex);
		pthread_mutex_lock(&philo->info->finish_mutex);
		gettimeofday(&now, NULL);
		ms = time_to_ms(now) - time_to_ms(philo->last_time_to_eat);
		gettimeofday(&now, NULL);
		if (ms >= philo->info->time_to_die && philo->info->finish == 0)
		{
			printf("%lld\t%d\t %s\n", \
				time_to_ms(now) - time_to_ms(philo->info->create_at), \
				philo->n + 1, "died        ❌");
				exit(0);
		philo->info->finish = 1;
		}
		pthread_mutex_unlock(&philo->info->finish_mutex);
		pthread_mutex_unlock(&philo->check_mutex);
	}
	return (NULL);
}
