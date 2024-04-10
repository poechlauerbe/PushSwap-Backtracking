/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpochlau <bpochlau@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:34:30 by bpochlau          #+#    #+#             */
/*   Updated: 2023/09/15 09:40:14 by bpochlau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_numblen(long num)
{
	int	len;

	len = 0;
	while (num > 0)
	{
		len++;
		num /= 10;
	}
	return (len);
}

int	ft_intneg(long *num)
{
	int		pre;

	pre = 1;
	if (*num < 0)
	{
		pre = -1;
		*num *= -1;
	}
	return (pre);
}

char	*ft_itoa(int n)
{
	long	num;
	char	*ptr;
	int		len;
	int		pre;

	num = n;
	pre = ft_intneg(&num);
	len = ft_numblen(num);
	if (pre == -1 || len == 0)
		len++;
	ptr = malloc (sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);
	ptr[len] = '\0';
	while (len-- > 0)
	{
		if (len == 0 && pre == -1)
			ptr[0] = '-';
		else
		{
			ptr[len] = num % 10 + 48;
			num /= 10;
		}
	}
	return (ptr);
}

// int main (void)
// {
// 	char *str;

// 	str = ft_itoa(-2147483648);
// 	printf("%s\n", str);
// }
