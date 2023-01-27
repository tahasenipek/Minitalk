/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msenipek <tahasenipek@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 21:19:47 by msenipek          #+#    #+#             */
/*   Updated: 2022/06/22 11:58:25 by msenipek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(char *str)
{
	int	res;

	res = 0;
	while (*str)
		res = (res * 10) + (*str++ - 48);
	return (res);
}

void	ft_handlersig(int pid, char *str)
{
	int				i;
	unsigned char	c;

	while (*str)
	{
		c = *str++;
		i = 128;
		while (i > 0)
		{
			if (c / i == 1)
			{
				kill(pid, SIGUSR1);
				c -= i;
			}
			else
				kill(pid, SIGUSR2);
			usleep(50);
			i /= 2;
		}
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		write(1, "3 argüman olmalı.", 17);
	else
	{
		ft_handlersig(ft_atoi(argv[1]), argv[2]);
		ft_handlersig(ft_atoi(argv[1]), "\n");
	}
}
