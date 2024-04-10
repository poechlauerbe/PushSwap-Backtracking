/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpochlau <bpochlau@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:08:37 by bpochlau          #+#    #+#             */
/*   Updated: 2023/09/12 17:31:05 by bpochlau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	nb_length(int nb)
{
	int	count;

	count = 0;
	while (nb)
	{
		count++;
		nb /= 10;
	}
	return (count);
}

void	ft_remainder_calc(int nb, int count, int max_test_flag, int fd)
{
	int	remainder;
	int	digit_array[10];
	int	number_length;

	number_length = count;
	while (count > 0)
	{
		remainder = nb % 10 + max_test_flag;
		nb /= 10;
		count--;
		digit_array[count] = remainder + 48;
		max_test_flag = 0;
	}
	while (count < number_length)
	{
		write(fd, &digit_array[count], 1);
		count++;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	int	count;
	int	max_test_flag;

	max_test_flag = 0;
	if (n == 0)
	{
		write(fd, "0", 1);
	}
	if (n < 0 && n != -2147483648)
	{
		write(fd, "-", 1);
		n = n * -1;
	}
	else if (n < 0)
	{
		write(fd, "-", 1);
		n = (n + 1) * -1;
		max_test_flag = 1;
	}
	count = nb_length(n);
	ft_remainder_calc(n, count, max_test_flag, fd);
}

// int main(void)
// {
// 	ft_putnbr_fd(-2147483648, 1);
// }
