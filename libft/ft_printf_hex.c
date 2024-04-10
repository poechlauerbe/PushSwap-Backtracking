/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpochlau <bpochlau@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 16:46:08 by bpochlau          #+#    #+#             */
/*   Updated: 2023/09/26 16:59:05 by bpochlau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexlen(long numb)
{
	int	len;

	len = 0;
	if (numb == 0)
		len = 1;
	while (numb > 0)
	{
		len++;
		numb /= 16;
	}
	return (len);
}

void	ft_printhex(unsigned int numb, char c, int *totlen)
{
	long	temp;
	char	*hexsmall;
	char	*hexbig;
	int		len;

	hexsmall = "0123456789abcdef";
	hexbig = "0123456789ABCDEF";
	len = ft_hexlen(numb);
	while (--len >= 0)
	{
		temp = numb / ft_pot(16, len);
		if (len == 0)
			temp = numb;
		if (c == 'X')
			ft_putchar_fd(hexbig[temp], 1);
		if (c == 'x')
			ft_putchar_fd(hexsmall[temp], 1);
		numb -= temp * ft_pot(16, len);
		*totlen += 1;
	}
}

void	ft_real_add(void *add, int *totlen, char *hexsmall)
{
	unsigned long	hexnumb;
	unsigned long	temp;
	int				len;

	ft_putstr_fd("0x", 1);
	*totlen += 2;
	hexnumb = (unsigned long)add;
	len = 0;
	temp = hexnumb;
	if (hexnumb == 0)
		len = 1;
	while (temp > 0)
	{
		len++;
		temp /= 16;
	}
	while (--len >= 0)
	{
		temp = hexnumb / ft_pot(16, len);
		if (len == 0)
			temp = hexnumb;
		ft_putchar_fd(hexsmall[temp], 1);
		hexnumb -= temp * ft_pot(16, len);
		*totlen += 1;
	}
}

void	ft_print_add(void *add, int *totlen)
{
	char			*hexsmall;

	hexsmall = "0123456789abcdef";
	if (add == NULL)
	{
		ft_putstr_fd("(nil)", 1);
		*totlen += 5;
		return ;
	}
	else
		ft_real_add(add, totlen, hexsmall);
}
