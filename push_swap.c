/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmafueni <jmafueni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:16:03 by jmafueni          #+#    #+#             */
/*   Updated: 2024/04/25 17:17:53 by jmafueni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printl(t_list *a)
{
	while(a)
	{
		printf("adresse = %p\n", a);
		printf("valeur = %d\n", a->value);
		printf("adresse suiv = %p\n", a->next);
		a = a->next;
	}
}

int	ft_is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(char *nptr)
{
	int	i;
	int	value;
	int	sign;

	i = 0;
	value = 0;
	sign = 1;
	while (nptr[i] && ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] != 32))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_is_digit(nptr[i]))
	{
		value = value * 10 + nptr[i] - '0';
		i++;
	}
	return (value * sign);
}

t_list	*ft_lstnew(int n)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->value = n;
	new->next = NULL;
	return (new);
}

t_list	*ft_lstlast(t_list *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

void ft_lstaddback(t_list **lst, int n)
{
	t_list *current;
	if (!lst)
		return ;
	if (*lst)
	{
		current = ft_lstlast(*lst);
		current->next = ft_lstnew(n);
	}
}

t_list	*filllst(t_list *lst,char **av)
{
	// int i;
	lst = ft_lstnew(ft_atoi(*av));
	av++;
	while (*av)
	{
		ft_lstaddback(&lst, ft_atoi(*av));
		av++;
	}
		printl(lst);
	return (lst);
}

int	main (int ac, char **av)
{
	t_list	*s;
	s = NULL;
	(void)ac;
	s = filllst(s, av + 1);
}
