/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpochlau <bpochlau@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 18:54:15 by bpochlau          #+#    #+#             */
/*   Updated: 2023/10/23 11:15:57 by bpochlau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

int			ft_printf(const char *str, ...);
int			ft_check_and_print(va_list prints, char *str);
char		*ft_malloc_string(char *str);
void		ft_signcheck(char *s, va_list prints, size_t *i, int *len);
void		ft_print_unsigned(unsigned int numb, int *totlen);

void		ft_printstr(char *s, int *totlen);
void		ft_printnbr(int nb, int *totlen);
long long	ft_pot(int numb, int pot);

int			ft_hexlen(long numb);
void		ft_print_add(void *add, int *totlen);
void		ft_printhex(unsigned int numb, char c, int *totlen);
void		ft_real_add(void *add, int *totlen, char *hexsmall);

#endif
