/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenjair <obenjair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 22:33:14 by obenjair          #+#    #+#             */
/*   Updated: 2022/08/27 18:46:35 by obenjair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	join_free_philo(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->num_of_philo)
	{
		pthread_join(info->philos[i].thread, NULL);
		pthread_mutex_destroy(&info->philos[i++].check_mutex);
	}
	free(info->philos);
	i = 0;
	while (i < info->num_of_philo)
		pthread_mutex_destroy(&info->forks[i++]);
	free(info->forks);
}

static void	create_philosophers(t_info *info)
{
	int	i;
	pthread_t
		thread;

	gettimeofday(&info->create_at, NULL);
	i = 0;
	while (i < info->num_of_philo)
	{
		info->philos[i].last_time_to_eat = info->create_at;
		pthread_create(&info->philos[i].thread, NULL, philo, &info->philos[i]);
		pthread_create(&thread, NULL, monitoreee, &info->philos[i]);
		pthread_detach(thread); /* pthread_detach tells the library to release all of the resources utilised by
								   the pthread once the thread is terminated .*/
		++i;
	}
	if (info->num_of_must_eat != 0)
	{
		pthread_create(&thread, NULL, ft_monitor_eat_philo, info);
		pthread_detach(thread);
	}
}

int	function(int argc, char **argv)
{
	int	i;

	i = 0;
	while (++i < argc)
		if (ft_atoi(argv[i]) < 0)
			return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_info	info;

	//info.die = 1;
	ft_memset(&info, 0, sizeof(info));
	if (argc != 5 && argc != 6)
		return (printf("Wrong argc"));
	if (function(argc, argv))
		return (printf("error\n"));
	if (convert_and_init(&info, argc, argv))
		return (1);
	create_philosophers(&info);
	join_free_philo(&info);
	//system("leaks philo");
	return (0);
}
