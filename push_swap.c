/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmafueni <jmafueni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:16:03 by jmafueni          #+#    #+#             */
/*   Updated: 2024/04/24 16:55:35 by jmafueni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printl(t_list *a)
{
	while (a)
	{
		printf("valeur = %d\n", a->value);
		printf("adresse = %p\n", a);
		printf("adr suiv = %p\n", a->next);
		a = a->next;
	}
}

t_list	*ft_lstlast(t_list *stash)
{
	t_list	*current;

	if (!stash)
		return (NULL);
	current = stash;
	while (current->next)
		current = current->next;
	return (current);
}

int	ft_isdigit(int c)
{
	if ((c >= '0') && (c <= '9'))
	{
		return (1);
	}
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	value;

	i = 0;
	value = 0;
	sign = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		value = value * 10 + nptr[i] - '0';
		i++;
	}
	return (value * sign);
}


t_list	*create_node(int a)
{
	t_list	*new;

	new = malloc(sizeof(t_list));

	if (!new)
		return (NULL);
	new->value = a;
	new->next = NULL;
	return (new);
}


void	ft_lstadd_back(t_list **lst, t_list* new)
{
	if (!lst || !new)
		return ;
	if (*lst)
		ft_lstlast(*lst)->next = new;
	else
		*lst = new;
}

void create_first (t_list *s, char **av)
{
	s = (t_list *)malloc(sizeof(t_list));
	if (!s)
		return ;
	(s)->value = ft_atoi(av[1]);
}

void node_loop(t_list **s, char **av)
{
	t_list *tmp;

	while(av++)
	{
		tmp = create_node(ft_atoi(*(av)));
		ft_lstadd_back(s, tmp);
	}
}

int	main(int ac, char **av)
{
	// int		i;
	t_list	*s = NULL;

	(void)ac;
	// t_list	*new_node;
	// // t_list	*last;

	// i = 1;
	// while (argv[i])
	// {
	node_loop(&s, av + 1);
	printl(s);
}
