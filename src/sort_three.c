/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmafueni <jmafueni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:49:01 by jmafueni          #+#    #+#             */
/*   Updated: 2024/06/11 15:39:25 by jmafueni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_highest_index(t_list *lst)
{
	int	index;

	index = lst->index;
	while (lst)
	{
		if (lst->index > index)
			index = lst->index;
		lst = lst->next;
	}
	return (index);
}

void	three_sort(t_list **lst)
{
	int	highest;

	if (is_sorted(*lst))
		return ;
	highest = find_highest_index(*lst);
	if ((*lst)->index == highest)
		do_ra(lst);
	else if ((*lst)->next->index == highest)
		do_rra(lst);
	if ((*lst)->index > (*lst)->next->index)
		do_sa(lst);
}
