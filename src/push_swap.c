/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmafueni <jmafueni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:16:03 by jmafueni          #+#    #+#             */
/*   Updated: 2024/07/02 15:22:32 by jmafueni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int	is_sorted(t_list *lst)
{
	while (lst->next != NULL)
	{
		if (lst->value > lst->next->value)
			return (0);
		lst = lst->next;
	}
	return (1);
}

void	push_swap(t_list **a, t_list **b, int lst_size)
{
	if (lst_size == 2 && !is_sorted(*a))
		do_sa(a);
	else if (lst_size == 3)
		three_sort(a);
	else if (lst_size > 3 && !is_sorted(*a))
		sort(a, b);
}

void	ft_free_split(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	int		lst_size;
	char	**arg;

	arg = NULL;
	if (ac < 2)
		return (0);
	if (ac == 2)
		arg = check_single_arg(av[1]);
	else if (!is_correct_input(av))
		error(NULL, NULL);
	if (ac == 2)
		a = filllst2(ft_count_words2(arg), arg);
	else
		a = filllst(ac, av);
	b = NULL;
	lst_size = ft_lst_size(a);
	assign_index(a, lst_size + 1);
	push_swap(&a, &b, lst_size);
	free_list(&a);
	free_list(&b);
	if (arg != NULL)
		ft_free_split(arg);
}
