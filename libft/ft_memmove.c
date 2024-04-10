/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpochlau <bpochlau@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:28:20 by bpochlau          #+#    #+#             */
/*   Updated: 2023/09/06 11:14:11 by bpochlau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (src < dest)
	{
		dest = (char *) dest + n - 1;
		src = (char *) src + n - 1;
		while (n-- > 0)
			*(char *) dest-- = *(char *) src--;
	}
	else if (src == dest)
		return (dest);
	else
	{
		i = 0;
		while (i++ < n)
			*(char *) dest++ = *(char *) src++;
		return (dest - n);
	}
	return (dest + 1);
}

// int	main (void)
// {
// 	char sdaswa[20] = "aaaaaaaaaaaaaa";
// 	char src[20] = "This is a test";
// 	char *dest;
// 	int n = 4;
// 	printf("%s\n", sdaswa);
// 	dest = (char *) src + 1;
// 	dest = ft_memmove(dest, src, n);
// 	printf("%s", dest);
// }
