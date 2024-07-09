/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmafueni <jmafueni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:12:53 by jmafueni          #+#    #+#             */
/*   Updated: 2024/06/25 13:51:27 by jmafueni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* push_all_save_three:
*	Pushes all the elements of list a into list b, except the three last ones.
*	Pushes the smaller values first, and then the larger values to help with
*	sorting efficiency.
*/
void	push_all_save_three(t_list **a, t_list **b)
{
	int	lst_size;
	int	pushed;
	int	i;

	lst_size = ft_lst_size(*a);
	pushed = 0;
	i = 0;
	while (lst_size > 6 && i < lst_size && pushed < lst_size / 2)
	{
		if ((*a)->index <= lst_size / 2)
		{
			do_pb(a, b);
			pushed++;
		}
		else
			do_ra(a);
		i++;
	}
	while (lst_size - pushed > 3)
	{
		do_pb(a, b);
		pushed++;
	}
}

/* shift_list:
*	After the bulk of the list is sorted, shifts list a until the lowest
*	value is at the top. If it is in the bottom half of the list, reverse
*	rotate it into position, otherwise rotate until it is at the top of the
*	list.
*/
void	shift_lst(t_list **a)
{
	int	lowest_pos;
	int	lst_size;

	lst_size = ft_lst_size(*a);
	lowest_pos = get_lowest_index_position(a);
	if (lowest_pos > lst_size / 2)
	{
		while (lowest_pos < lst_size)
		{
			do_rra(a);
			lowest_pos++;
		}
	}
	else
	{
		while (lowest_pos > 0)
		{
			do_ra(a);
			lowest_pos--;
		}
	}
}

/* sort:
*	Sorting algorithm for a list larger than 3.
*		Push everything but 3 numbers to list B.
*		Sort the 3 numbers left in list A.
*		Calculate the most cost-effective move.
*		Shift elements until list A is in order.
*/

void	sort(t_list **a, t_list **b)
{
	push_all_save_three(a, b);
	three_sort(a);
	while (*b)
	{
		get_target_position(a, b);
		get_cost(a, b);
		do_cheapest_move(a, b);
	}
	if (!is_sorted(*a))
		shift_lst(a);
}
