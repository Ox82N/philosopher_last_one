/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenjair <obenjair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 22:33:02 by obenjair          #+#    #+#             */
/*   Updated: 2022/08/27 19:24:27 by obenjair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	time_to_ms(struct timeval now)
{
	long long	ms;

	ms = now.tv_sec * 1000;
	ms += now.tv_usec / 1000;
	return (ms);
}

void	print_philo_msg(t_philo *philo, char *str)
{
	long long		ms;
	struct timeval	now;

	pthread_mutex_lock(&philo->info->finish_mutex);
	gettimeofday(&now, NULL);
	ms = time_to_ms(now) - time_to_ms(philo->info->create_at);
	if (!philo->info->finish)
		printf("%lld\t%d\t %s\n", ms, philo->n + 1, str);
	pthread_mutex_unlock(&philo->info->finish_mutex);
}

int	ft_atoi(const char *str)
{
	unsigned int	result;
	int				i;
	int				signal;

	i = 0;
	signal = 1;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signal *= -1;
			i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		if (result > 2147483647 && signal == 1)
			return (-1);
		if (result > 2147483648 && signal == -1)
			return (0);
		i++;
	}
	return ((int)(result * signal));
}

int ft_malloc(void *dst, size_t size)
{
	*(void **)dst = malloc(size);
	if(*(void **)dst == NULL)
		return (FT_ERROR);
	return (FT_SUCCESS);
}
void	*ft_memset(void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	b;
	unsigned char	*ptr;

	ptr = (unsigned char *)str;
	b = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		ptr[i] = b;
		i++;
	}
	return (str);
}