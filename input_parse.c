/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 10:56:59 by matoledo          #+#    #+#             */
/*   Updated: 2025/06/12 12:27:22 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	add_numbers(t_list **lst, char **pt_aux)
{
	int		*aux;
	t_list	*node;

	while (*pt_aux)
	{
		if (check_bigger_int(*pt_aux) == 0)
			return (0);
		aux = malloc(sizeof(int));
		*aux = ft_atoi(*pt_aux);
		if (check_repeated(*lst, *aux) == 0)
		{
			free(aux);
			return (0);
		}
		node = ft_lstnew(aux);
		ft_lstadd_back(lst, node);
		pt_aux++;
	}
	return (1);
}

int	fill_list(t_list **lst, char **s)
{
	char	**pt_aux;

	while (*s)
	{
		if (check_input(*s) == 0)
		{
			ft_lstclear(lst, del_number);
			free(lst);
			return (0);
		}
		pt_aux = ft_split(*s, ' ');
		if (add_numbers(lst, pt_aux) == 0)
		{
			free_memory(pt_aux);
			ft_lstclear(lst, del_number);
			free(lst);
			return (0);
		}
		free_memory(pt_aux);
		s++;
	}
	return (1);
}
