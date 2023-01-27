/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msenipek <tahasenipek@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 21:20:29 by msenipek          #+#    #+#             */
/*   Updated: 2022/06/22 11:52:16 by msenipek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_itoa(int pid)
{
	char	*c;

	c = "0123456789";
	if (pid > 9)
		ft_itoa (pid / 10);
	write (1, &c[pid % 10], 1);
}

void	ft_killer(int sig)
{
	static char	c = 0;
	static int	get_byte = 0;

	if (sig == SIGUSR1)
		c = c | 1;
	if (++get_byte == 8)
	{
		get_byte = 0;
		write (1, &c, 1);
		c = 0;
	}
	else
		c <<= 1;
}

int	main(void)
{
	write (1, "Server Pid:", 13);
	ft_itoa (getpid());
	write (1, "\n", 1);
	signal (SIGUSR1, ft_killer);
	signal (SIGUSR2, ft_killer);
	while (1)
	{
		pause();
	}
	return (0);
}
