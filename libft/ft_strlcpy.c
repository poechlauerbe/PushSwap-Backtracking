/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpochlau <bpochlau@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 16:37:34 by bpochlau          #+#    #+#             */
/*   Updated: 2023/09/15 14:24:05 by bpochlau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <bsd/string.h>
#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	if (size == 0)
		return (ft_strlen((char *) src));
	i = 0;
	while (src[i] && size > 1)
	{
		dest[i] = src[i];
		i++;
		size--;
	}
	dest[i] = '\0';
	i = ft_strlen((char *)src);
	return (i);
}

// int main(void)
// {
// 	char *src;
// 	char dest[10];
// 	unsigned int n;
// 	unsigned int i;

// 	src = "12345678901234567890";
// // buffer size is number in dest[], should print 1 less because of \0
// 	n = 0;

// 	i = ft_strlcpy(dest, src, n);
// 	printf("Src-Length: %d\n", i);
// 	i = 0;
// 	while(dest[i] && n != 0)
// 	{
// 		printf("%c", dest[i]);
// 		i++;
// 		n--;
// 	}
// 	printf("$%s$\n", src);
// 	printf("$%s$\n", dest);
// }
