/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpochlau <bpochlau@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 16:47:50 by bpochlau          #+#    #+#             */
/*   Updated: 2023/09/18 14:38:46 by bpochlau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The bzero() function erases the data in the n bytes of the memory starting
// at the location pointed to by s, by writing zeros (bytes containing '\0')
// to that area.

#include <stdio.h>
#include <string.h>

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = s;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

// int	main (void)
// {
// 	char str[20] = "This is a string!";
// 	ft_bzero(str, 10);
// 	printf("%c", str[10]);
// }
