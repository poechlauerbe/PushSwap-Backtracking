/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_rev_rot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpochlau <bpochlau@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 19:03:45 by bpochlau          #+#    #+#             */
/*   Updated: 2023/11/21 15:15:42 by bpochlau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_rra(t_vars **vars)
{
	ft_rev_r(&(*vars)->a);
	ft_printf("rra\n");
	return (OK);
}

int	ft_rrb(t_vars **vars)
{
	ft_rev_r(&(*vars)->b);
	ft_printf("rrb\n");
	return (OK);
}

int	ft_rrr(t_vars **vars)
{
	ft_rev_r(&(*vars)->a);
	ft_rev_r(&(*vars)->b);
	ft_printf("rrr\n");
	return (OK);
}
