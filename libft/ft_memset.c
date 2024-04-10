/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpochlau <bpochlau@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:37:30 by bpochlau          #+#    #+#             */
/*   Updated: 2023/09/15 12:32:57 by bpochlau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;

	i = 0;
	str = (unsigned char *) s;
	while (i < n)
	{
		str[i] = c;
		i++;
	}
	return (s);
}

// int	main (void)
// {
// 	char str[20] = "This is a test";
// 	int n = 8;
// 	char c = 'o';
// 	ft_memset(str, c, n);
// 	printf("%s", str);
// }
