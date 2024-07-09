/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmafueni <jmafueni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:29:22 by jmafueni          #+#    #+#             */
/*   Updated: 2024/07/01 14:58:21 by jmafueni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// size_t	count_words(char const *s, char c)
// {
// 	size_t	words;
// 	size_t	i;

// 	words = 0;
// 	i = 0;
// 	while (s[i])
// 	{
// 		if (s[i] != c && (s[i + 1] == c || s[i] == '\0'))
// 			words++;
// 		i++;
// 	}
// 	return(words);
// }

// void	fill_tab(char *new, char const *s, char c)
// {
// 	size_t	i;

// 	i = 0;
// 	while (s[i] && s[i] != c)
// 	{
// 		new[i] = s[i];
// 		i++;
// 	}
// 	new[i] = '\0';
// }

// void	set_mem(char **tab, char const *s, char c)
// {
// 	size_t	count;
// 	size_t	index;
// 	size_t	i;

// 	index = 0;
// 	i = 0;
// 	while (s[index])
// 	{
// 		count = 0;
// 		while (s[index + count] && s[index + count] != c)
// 			count++;
// 		if (count > 0)
// 		{
// 			tab[i] = malloc(sizeof(char) * (count + 1));
// 			if (!tab[i])
// 				return ;
// 			fill_tab(tab[i], (s + index), c);
// 			i++;
// 			index = index + count;
// 		}
// 		else
// 			index++;
// 	}
// 	tab[i] = 0;
// }

// char	**ft_split(char const *s, char c)
// {
// 	size_t	words;
// 	char	**tab;

// 	if (!s)
// 		return (NULL);
// 	words = count_words(s, c);
// 	tab = (char **)malloc(sizeof(char *) * (words + 1));
// 	if (!tab)
// 		return (NULL);
// 	set_mem(tab, s, c);
// 	return (tab);
// }

t_list	*filllst2(int ac, char **av)
{
	t_list		*a;
	long int	n;
	int			i;

	a = NULL;
	n = 0;
	i = 0;
	while (i < ac)
	{
		n = ft_atoi(av[i]);
		if (n > INT_MAX || n < INT_MIN)
		{
			error(&a, NULL);
			return (NULL);
		}
		if (i == 0)
			a = ft_lstnew2((int)n);
		else
			ft_lstaddback(&a, ft_lstnew2((int)n));
		i++;
	}
	return (a);
}

char	**check_single_arg(char *av)
{
	char	**arg;

	arg = ft_split(av, ' ');
	if (!is_correct_input(arg))
	{
		ft_free_split(arg);
		error(NULL, NULL);
	}
	return (arg);
}

size_t	ft_count_words2(char **words)
{
	size_t	count;

	count = 0;
	while (*words != NULL)
	{
		words++;
		count++;
	}
	return (count);
}
