/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 10:56:59 by matoledo          #+#    #+#             */
/*   Updated: 2025/06/04 20:28:43 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_input(char *num)
{
	while (*num)
	{
		if (ft_isdigit(*num) == 0
			&& !((*num >= 9 && *num <= 13) || *num == 32))
			return (0);
		num++;
	}
	return (1);
}

int	check_repeated(t_list *lst, int num)
{
	while (lst)
	{
		if (*(int *)lst->content == num)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int	add_numbers(t_list **lst, char **pt_aux)
{
	int		*aux;
	t_list	*node;

	while (*pt_aux)
	{
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
			free_memory(pt_aux);
			return (0);
		}
		pt_aux = ft_split(*s, ' ');
		if (add_numbers(lst, pt_aux) == 0)
		{
			free_memory(pt_aux);
			return (0);
		}
		free_memory(pt_aux);
		s++;
	}
	return (1);
}
