/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aydemir <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 16:18:13 by aydemir           #+#    #+#             */
/*   Updated: 2022/10/08 16:38:15 by aydemir          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

void	sig_handler(int signal_control, siginfo_t *sa, void *arg);
void	signal_message(int signal);
void	ft_send(int pid, char *str);

#endif
