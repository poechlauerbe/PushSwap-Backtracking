/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpochlau <bpochlau@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:18:54 by bpochlau          #+#    #+#             */
/*   Updated: 2023/11/24 14:14:39 by bpochlau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_stack(t_list *stack)
{
	ft_printf("\nsorted: ");
	while (stack)
	{
		ft_printf("%i [%i]   ", stack->num, stack->i);
		stack = stack->next;
	}
	ft_printf("\n");
}

void	ft_free_check(t_check **turk)
{
	int	i;

	i = 0;
	while ((*turk)->next[i])
	{
		ft_free_check(&(*turk)->next[i]);
		i++;
	}
	if ((*turk)->ca)
		ft_free_list(&(*turk)->ca);
	if ((*turk)->cb)
		ft_free_list(&(*turk)->cb);
	*turk = NULL;
}

void	ft_exit(t_vars **vars, int errcd)
{
	if (errcd != OK)
		err_mes(errcd);
	// ft_print_stack((*vars)->a);
	// ft_print_stack((*vars)->b);
	ft_free_list(&(*vars)->a);
	ft_free_list(&(*vars)->b);
	if ((*vars)->turk)
		free((*vars)->turk);
	exit(errcd);
}

void	ft_free_list(t_list **lst)
{
	t_list	*temp;

	while (*lst)
	{
		temp = lst[0]->next;
		free (*lst);
		*lst = temp;
	}
	*lst = NULL;
}

void	err_mes(int errcd)
{
	ft_putstr_fd("Error!\n", 2);
	ft_putstr_fd("Error code: ", 2);
	ft_putnbr_fd(errcd, 2);
	ft_putstr_fd("\n", 2);
}
