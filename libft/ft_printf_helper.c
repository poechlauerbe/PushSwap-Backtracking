/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpochlau <bpochlau@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:24:29 by bpochlau          #+#    #+#             */
/*   Updated: 2023/09/26 16:46:54 by bpochlau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long	ft_pot(int numb, int pot)
{
	long long	ret;

	ret = numb;
	while (pot-- > 1)
		ret *= numb;
	return (ret);
}

void	ft_printnbr(int nb, int *totlen)
{
	long	temp;

	temp = nb;
	if (nb == 0)
		*totlen += 1;
	else if (nb < 0)
	{
		temp *= -1;
		*totlen += 1;
	}
	while (temp > 0)
	{
		temp /= 10;
		*totlen += 1;
	}
	ft_putnbr_fd(nb, 1);
}

void	ft_printstr(char *s, int *totlen)
{
	unsigned int	i;

	i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		*totlen += 6;
		return ;
	}
	while (s && s[i])
	{
		ft_putchar_fd(s[i], 1);
		i++;
		*totlen += 1;
	}
}
