/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpochlau <bpochlau@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:59:28 by bpochlau          #+#    #+#             */
/*   Updated: 2023/11/21 15:17:05 by bpochlau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_ra(t_vars **vars)
{
	ft_r(&(*vars)->a);
	ft_printf("ra\n");
	return (OK);
}

int	ft_rb(t_vars **vars)
{
	ft_r(&(*vars)->b);
	ft_printf("rb\n");
	return (OK);
}

int	ft_rr(t_vars **vars)
{
	ft_r(&(*vars)->a);
	ft_r(&(*vars)->b);
	ft_printf("rr\n");
	return (OK);
}
