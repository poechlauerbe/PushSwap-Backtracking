/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpochlau <bpochlau@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 15:58:25 by bpochlau          #+#    #+#             */
/*   Updated: 2023/11/21 15:43:21 by bpochlau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_i_3(t_list *a, t_vars **vars)
{
	if (a->next->i == 2)
		ft_sa(vars);
	else if (a->next->i == 1)
	{
		if (a->next->next->i == 0)
			ft_sa(vars);
		ft_pb(vars);
		ft_sa(vars);
		ft_pa(vars);
	}
	else if (a->next->i == 0)
	{
		if (a->next->next->i == 1)
			ft_sa(vars);
		ft_pb(vars);
		ft_sa(vars);
		ft_pa(vars);
		ft_sa(vars);
	}
}

void	ft_sort_i_2(t_list *a, t_vars **vars)
{
	if (a->next->i == 3)
	{
		ft_pb(vars);
		ft_pb(vars);
		ft_sa(vars);
		ft_pa(vars);
		ft_pa(vars);
		if (a->next->i == 0)
			ft_sa(vars);
	}
	else if (a->next->i == 1)
	{
		if (a->next->next->i == 3)
			ft_sa(vars);
		ft_ra(vars);
	}
	else if (a->next->i == 0)
	{
		if (a->next->next->i == 3)
			ft_sa(vars);
		ft_ra(vars);
		ft_sa(vars);
	}
}

void	ft_sort_i_1(t_list *a, t_vars **vars)
{
	if (a->next->i == 3)
	{
		if (a->next->next->i == 0)
			ft_sa(vars);
		ft_rra(vars);
		ft_sa(vars);
	}
	else if (a->next->i == 2)
	{
		if (a->next->next->i == 0)
			ft_ra(vars);
		ft_pb(vars);
		ft_sa(vars);
		if (a->next != NULL)
			ft_rra(vars);
		ft_pa(vars);
	}
	else if (a->next->i == 0)
	{
		if (a->next->next->i == 2)
			ft_sa(vars);
		ft_ra(vars);
		ft_ra(vars);
	}
}

void	ft_sort_i_0(t_list *a, t_vars **vars)
{
	if (a->next->i == 3)
	{
		if (a->next->next->i == 1)
			ft_sa(vars);
		ft_rra(vars);
	}
	else if (a->next->i == 2)
	{
		if (a->next->next->i == 3)
			ft_sa(vars);
		ft_rra(vars);
		ft_sa(vars);
		ft_ra(vars);
	}
	else if (a->next->i == 1)
	{
		if (a->next->next->i == 2)
			ft_sa(vars);
		ft_ra(vars);
		ft_ra(vars);
		ft_sa(vars);
	}
}
