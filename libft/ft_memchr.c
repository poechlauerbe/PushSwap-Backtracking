/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpochlau <bpochlau@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:01:52 by bpochlau          #+#    #+#             */
/*   Updated: 2023/09/15 11:04:54 by bpochlau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	while (c >= 256)
		c -= 256;
	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == (unsigned char) c)
			return (ptr + i);
		i++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char str[30] = " 0This is my memchr test";
// 	int c = 48;
// 	size_t n = 2;
// 	void *ptr;
// 	ptr = ft_memchr(str, c, n);
// 	printf("Mine:     %p\n", ptr);
// 	ptr = memchr(str, c, n);
// 	printf("Original: %p\n", ptr);
// }
