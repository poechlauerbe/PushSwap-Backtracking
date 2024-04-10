/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpochlau <bpochlau@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:17:16 by bpochlau          #+#    #+#             */
/*   Updated: 2023/09/16 18:12:59 by bpochlau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

void	ft_trimiterateup(int *i, int *j, char *s1, char *set)
{
	*i = -1;
	while (s1[++*i])
	{
		*j = -1;
		while (set[++*j])
		{
			if (s1[*i] == set[*j])
				break ;
		}
		if (s1[*i] != set[*j])
			break ;
	}
}

void	ft_lentrim(char *s, char *set, int *len)
{
	int	i;

	while (s[--*len])
	{
		i = -1;
		while (set[++i])
		{
			if (s[*len] == set[i])
				break ;
		}
		if (s[*len] != set[i])
			return ;
	}
	return ;
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		len;
	int		i;
	int		j;
	char	*ptr;

	if (!s1 || !set)
		return (NULL);
	len = ft_strlen((char *) s1);
	ft_lentrim((char *) s1, (char *) set, &len);
	ft_trimiterateup(&i, &j, (char *) s1, (char *) set);
	if (len - i < -1)
	{
		len = -1;
		i = 0;
	}
	ptr = malloc(sizeof(char) * (len - i + 2));
	if (!ptr)
		return (NULL);
	j = 0;
	while (i <= len)
		ptr[j++] = s1[i++];
	ptr[j] = '\0';
	return (ptr);
}

// int main (void)
// {
// 	// char *s1 = "  \t \t \n   \n\n\n\t";
// 	char *s1 = "   \t  \n\n \t\t  \n\n\nHello \t  Please !\n   \n \n \t\t\n  ";
//     char *set = " \n\t";
// 	// char *s1= "d*+*+*+This is a *-string*+*+*+";
// 	// char *set= "*+d";
// 	// char *s1= "";
// 	// char *set= "";
// 	char *ptr;
// 	ptr = ft_strtrim(s1, set);
// 	printf("$%s$\n", ptr);
// }
