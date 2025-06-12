/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 10:56:59 by matoledo          #+#    #+#             */
/*   Updated: 2025/06/12 22:28:09 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sorted(t_list *lst)
{
	t_list	*pt_aux;

	pt_aux = lst;
	pt_aux = pt_aux->next;
	while (pt_aux)
	{
		if (*(int *)pt_aux->content < *(int *)lst->content)
			return (1);
		pt_aux = pt_aux->next;
		lst = lst->next;
	}
	return (0);
}

int	check_input(char *num)
{
	if (*num == '-' || *num == '+')
		num++;
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

int	add_number(t_list **lst, char *pt_aux)
{
	int		*aux;
	t_list	*node;

	aux = malloc(sizeof(int));
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
