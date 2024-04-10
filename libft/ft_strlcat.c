/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpochlau <bpochlau@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 17:49:10 by bpochlau          #+#    #+#             */
/*   Updated: 2023/09/15 14:01:34 by bpochlau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	concatenate two strings (str to dest)
	adds \0 at the end
	it will use at most the buffersize - 1
	src does not need to be \0 terminated
	functions return the total length of the string they tried to create.
*/

#include <string.h>
#include <stdio.h>
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	len;
	size_t	len_src;

	len = ft_strlen(dest);
	len_src = ft_strlen((char *)src);
	i = 0;
	if (size == 0 || size <= len)
		return (size + len_src);
	while (src[i] && i + len < size - 1)
	{
		dest[i + len] = src[i];
		i++;
	}
	dest[i + len] = '\0';
	return (len + len_src);
}

// int	main(void)
// {
// 	size_t	val;
// 	size_t i;
// 	char	dest[31] = "12345678901234567890";
// 	char	src[11] = "1234567890\0";
// 	size_t size = 25;
// 	i = 0;
// 	val = ft_strlcat(dest, src, size);
// 	while (dest[i])
// 	{
// 		printf("%c", dest[i]);
// 		i ++;
// 	}
// 	printf("\nCount: %ld", val);
// }
