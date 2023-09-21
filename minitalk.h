/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aydemir <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 16:13:38 by aydemir           #+#    #+#             */
/*   Updated: 2022/10/08 16:13:39 by aydemir          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdio.h>

void	ft_send(int pid, char *str);
void	using_signal(int signal_control);
int		ft_atoi(const char *str);

#endif
