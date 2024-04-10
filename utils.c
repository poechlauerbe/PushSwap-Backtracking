/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpochlau <bpochlau@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 17:09:22 by bpochlau          #+#    #+#             */
/*   Updated: 2023/11/20 16:43:32 by bpochlau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_copy_list(t_list *stack)
{
	t_list	*start;
	t_list	*new;

	start = NULL;
	while (stack)
	{
		new = ft_lstnew(stack->num);
		if (!new)
			return (NULL);
		new->i = stack->i;
		ft_lstadd_back(&start, new);
		stack = stack->next;
	}
	return (start);
}

int	ft_atoi_w_err(const char *nptr, int *num)
{
	int		i;
	long	numb;
	int		pre;

	pre = 1;
	numb = 0;
	i = 0;
	while (nptr[i] == ' ' || nptr[i] == '\n' || nptr[i] == '\t'
		|| nptr[i] == '\r' || nptr[i] == '\f' || nptr[i] == '\v')
		i++;
	if (nptr[i] == '-')
	{
		pre = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		numb = 10 * numb + nptr[i++] - 48;
		if (numb * pre > INT_MAX || numb * pre < INT_MIN)
			return (INTEGER_OVERFLOW_OR_UNDERFLOW);
	}
	*num = numb * pre;
	return (OK);
}
