/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 10:56:59 by matoledo          #+#    #+#             */
/*   Updated: 2025/06/13 09:12:58 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	add_number(t_list **lst, char *pt_aux)
{
	int		*aux;
	long	*checker;
	t_list	*node;

	checker = ft_calloc(sizeof(long), 1);
	*checker = ft_atol(pt_aux);
	if (*checker > INT_MAX || *checker < INT_MIN)
	{
		free(checker);
		return (0);
	}
	free(checker);
	aux = ft_calloc(sizeof(int), 1);
	*aux = ft_atoi(pt_aux);
	if (check_repeated(*lst, *aux) == 0)
	{
		free(aux);
		return (0);
	}
	node = ft_lstnew(aux);
	ft_lstadd_back(lst, node);
	return (1);
}

int	fill_list(t_list **lst, char **s)
{
	char	**pt_aux;
	char	**pt_free;

	while (*s)
	{
		pt_aux = ft_split(*s, ' ');
		pt_free = pt_aux;
		while (*pt_aux)
		{
			if (check_input(*pt_aux) == 0 || add_number(lst, *pt_aux) == 0)
			{
				free_memory(pt_aux);
				ft_lstclear(lst, del_number);
				free(lst);
				return (0);
			}
			pt_aux++;
		}
		free_memory(pt_free);
		s++;
	}
	return (1);
}
