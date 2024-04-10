/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpochlau <bpochlau@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 11:18:49 by bpochlau          #+#    #+#             */
/*   Updated: 2023/09/15 12:14:38 by bpochlau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (dest == NULL && src == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		((unsigned char *) dest)[i] = ((unsigned char *) src)[i];
		i++;
	}
	return (dest);
}

// int main (void)
// {
// 	char src[20] = "the alpaka is cool";
// 	char dest[20] = "\0";
// 	char *ptr;
// 	int n = 10;
// 	ptr = ft_memcpy(dest, src, n);
// 	printf("$%s$\n", ptr);
// 	ptr = memcpy(dest, src, n);
// 	printf("$%s$\n", ptr);
// }
