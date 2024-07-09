/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmafueni <jmafueni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:53:47 by jmafueni          #+#    #+#             */
/*   Updated: 2024/06/21 13:58:20 by jmafueni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_param(t_list **src, t_list **dest)
{
	t_list	*tmp;

	if (*src == NULL)
		return ;
	tmp = (*src)->next;
	(*src)->next = *dest;
	*dest = *src;
	*src = tmp;
}

void	do_pa(t_list **a, t_list **b)
{
	if (*b == NULL)
		return ;
	push_param(b, a);
	ft_putstr("pa\n");
}

void	do_pb(t_list **a, t_list **b)
{
	if (*a == NULL)
		return ;
	push_param(a, b);
	ft_putstr("pb\n");
}
