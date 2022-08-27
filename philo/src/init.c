/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenjair <obenjair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 22:32:49 by obenjair          #+#    #+#             */
/*   Updated: 2022/08/27 18:48:59 by obenjair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	convert_arg(t_info *info, int argc, char *argv[])
{
		info->num_of_philo = ft_atoi(argv[1]);
		info->time_to_die = ft_atoi(argv[2]);
		info->time_to_eat = ft_atoi(argv[3]);
		info->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		info->num_of_must_eat = ft_atoi(argv[5]);
}

static int	allocation_philo(t_info *info)
{
	int	i;

	pthread_mutex_init(&info->finish_mutex, NULL);
	if (ft_malloc(&info->philos, sizeof(t_philo) * info->num_of_philo) || \
		ft_malloc(&info->forks, sizeof(pthread_mutex_t) * info->num_of_philo))
		return (printf("Error : you might have error in allocation"));
	i = 0;
	while (i < info->num_of_philo)
	{
		info->philos[i].n = i;
		pthread_mutex_init(&info->forks[i], NULL);
		pthread_mutex_init(&info->philos[i].check_mutex, NULL);
		if (i == 0)
			info->philos[i].left = &info->forks[info->num_of_philo - 1];
		else
		info->philos[i].left = &info->forks[i - 1];
		info->philos[i].right = &info->forks[i];
		info->philos[i].info = info;
		++i;
	}
	return (FT_SUCCESS);
}

int	convert_and_init(t_info *info, int argc, char *argv[])
{
	convert_arg(info, argc, argv);
	if (allocation_philo(info))
		return (FT_ERROR);
	return (FT_SUCCESS);
}
