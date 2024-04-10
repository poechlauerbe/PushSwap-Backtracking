/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_fun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpochlau <poechlauerbe@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 13:22:54 by bpochlau          #+#    #+#             */
/*   Updated: 2023/11/23 16:25:37 by bpochlau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_pos_ret(t_vars **vars, int i, int *a_top_i, int *a_low_i)
{
	if (i > *a_top_i)
	{
		if ((*vars)->h_a == 3)
			while ((*vars)->a->i != *a_top_i)
				ft_ra(vars);
		else
			while ((*vars)->a->i != *a_top_i)
				ft_rra(vars);
		*a_top_i = i;
	}
	else if (i < *a_low_i)
	{
		while (ft_lstlast((*vars)->a)->i != *a_low_i)
			ft_rra(vars);
		*a_low_i = i;
	}
	else
	{
		if ((*vars)->h_a == 3)
			while (!(i > (*vars)->a->i && i < ft_lstlast((*vars)->a)->i))
				ft_ra(vars);
		else
			while (!(i > (*vars)->a->i && i < ft_lstlast((*vars)->a)->i))
				ft_rra(vars);
	}
}

void	ft_ret_b_a(t_vars **vars)
{
	t_list	*t_b;
	int		a_top_i;
	int		a_low_i;

	a_top_i = (*vars)->a->i;
	a_low_i = ft_lstlast((*vars)->a)->i;
	while ((*vars)->b != NULL)
	{
		t_b = ft_lstlast((*vars)->b);
		ft_check_pos_ret(vars, t_b->i, &a_top_i, &a_low_i);
		ft_pa(vars);
	}
	while (ft_lstlast((*vars)->a)->i != 0)
		ft_rra(vars);
}

void	ft_sort_a_3(t_vars **vars)
{
	t_list	*st;

	st = (*vars)->a;
	if (st->i > st->next->i && st->next->i > st->next->next->i)
		return ;
	else if (st->i > st->next->i && st->next->i < st->next->next->i)
	{
		if (st->i > st->next->next->i)
			ft_sa(vars);
		else
			ft_ra(vars);
	}
	else if (st->i < st->next->i && st->next->i > st->next->next->i)
	{
		if (st->i > st->next->next->i)
		{
			ft_sa(vars);
			ft_ra(vars);
		}
		else
			ft_rra(vars);
	}
	else if (st->i < st->next->i && st->next->i < st->next->next->i)
	{
		ft_sa(vars);
		ft_rra(vars);
	}
}
