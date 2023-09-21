/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aydemir <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 16:12:47 by aydemir           #+#    #+#             */
/*   Updated: 2022/10/08 16:12:50 by aydemir          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_putnbr(unsigned int a)
{
	if (a > 9)
		ft_putnbr(a / 10);
	write(1, &"0123456789"[a % 10], 1);
	return (0);
}

void	using_signal(int signal_control)
{
	static char	str;
	static int	count;

	if (signal_control == SIGUSR1)
		str = str | 1;
	if (++count == 8)
	{
		count = 0;
		if (!str)
			write(1, "\n", 1);
		write(1, &str, 1);
		str = 0;
	}
	else
		str <<= 1;
}

int	main(void)
{
	ft_putnbr(getpid());
	write(1, "\n", 1);
	signal(SIGUSR1, using_signal);
	signal(SIGUSR2, using_signal);
	while (1)
	{
		pause();
	}
}
