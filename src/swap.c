/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmafueni <jmafueni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:19:07 by jmafueni          #+#    #+#             */
/*   Updated: 2024/06/11 15:39:09 by jmafueni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_param(t_list *lst)
{
	int	tmp;

	if (lst == NULL || lst->next == NULL)
		return ;
	tmp = lst->value;
	lst->value = lst->next->value;
	lst->next->value = tmp;
	tmp = lst->index;
	lst->index = lst->next->index;
	lst->next->index = tmp;
}

void	do_sa(t_list **a)
{
	swap_param(*a);
	ft_putstr("sa\n");
}

void	do_sb(t_list **b)
{
	swap_param(*b);
	ft_putstr("sb\n");
}

void	do_ss(t_list **a, t_list **b)
{
	swap_param(*a);
	swap_param(*b);
	ft_putstr("ss\n");
}
