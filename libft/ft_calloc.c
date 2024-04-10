/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpochlau <poechlauerbe@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 12:16:46 by bpochlau          #+#    #+#             */
/*   Updated: 2023/11/08 15:24:34 by bpochlau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	char	*ptr2;
	size_t	i;

	if (nmemb * size > 2147483647)
		return (NULL);
	ptr = malloc (nmemb * size);
	if (!ptr)
		return (NULL);
	i = 0;
	ptr2 = ptr;
	while (i < (nmemb * size))
		ptr2[i++] = '\0';
	return (ptr);
}

// int main(void)
// {
// 	char *ptr;
// 	int nmemb = 0;
// 	int size = sizeof(char);
// 	ptr = calloc(nmemb, size);
// 	printf("Original:  %p\n", ptr);
// 	if (ptr != NULL)
// 		free(ptr);
// 	ptr = ft_calloc(nmemb, size);
// 	printf("My Adress: %p\n", ptr);
// 	if (ptr != NULL)
// 		free(ptr);
// }
