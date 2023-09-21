/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aydemir <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 16:16:48 by aydemir           #+#    #+#             */
/*   Updated: 2022/10/08 16:16:50 by aydemir          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
}

void	signal_message(int signal)
{
	if (signal == SIGUSR1)
		write(1, "Mesaj gönderildi", 16);
	exit(0);
}

void	ft_send(int pid, char *str)
{
	int		count;
	char	c;

	count = 8;
	while (*str)
	{
		count = 8;
		c = *(str++);
		while (count--)
		{
			if (c >> count & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
		}
	}
	count = 8;
	while (count--)
	{
		kill(pid, SIGUSR2);
		usleep(100);
	}
}

int	main(int count, char **str)
{
	if (count < 3)
	{
		write(1, "3 karakter girin", 16);
		return (1);
	}
	if (ft_atoi(str[1]) <= 0)
		return (write(1, "pid negatif olamaz", 18));
	signal(SIGUSR1, signal_message);
	ft_send(ft_atoi(str[1]), str[2]);
	while (1)
	{
		pause();
	}
}
