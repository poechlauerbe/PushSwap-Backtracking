/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_sp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpochlau <bpochlau@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:46:25 by bpochlau          #+#    #+#             */
/*   Updated: 2023/11/21 15:13:43 by bpochlau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sa(t_vars **vars)
{
	ft_s(&(*vars)->a);
	ft_printf("sa\n");
	return (OK);
}

int	ft_sb(t_vars **vars)
{
	ft_s(&(*vars)->b);
	ft_printf("sb\n");
	return (OK);
}

int	ft_ss(t_vars **vars)
{
	ft_s(&(*vars)->a);
	ft_s(&(*vars)->b);
	ft_printf("ss\n");
	return (OK);
}

int	ft_pa(t_vars **vars)
{
	ft_p(&(*vars)->a, &(*vars)->b);
	(*vars)->h_a += 1;
	(*vars)->h_b -= 1;
	ft_printf("pa\n");
	return (OK);
}

int	ft_pb(t_vars **vars)
{
	ft_p(&(*vars)->b, &(*vars)->a);
	(*vars)->h_a -= 1;
	(*vars)->h_b += 1;
	ft_printf("pb\n");
	return (OK);
}
