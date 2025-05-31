/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 12:48:57 by matoledo          #+#    #+#             */
/*   Updated: 2025/05/31 14:37:30 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	restart_list(t_list **lst, int *max_number)
{
	while ((*lst)->content != max_number)
	{
		(*lst) = (*lst)->next;
	}
}

void	sort_list(t_list **a, t_list **b)
{
	push(a, b);
	while (*a)
	{
		if((*a) > (*b))
		{
			if ((*a) > ft_lstlast((*b)))
				push(a, b);
			else
			{
				while ((*a) < ft_lstlast((*b)))
					reverse_rotate(b);
				push(a, b);
			}
		}
		else
		{
			if ((*a) < ft_lstlast((*b)))
			{
				push(a, b);
				rotate(b);
			}
			else
			{
				while ((*a) > ft_lstlast((*b)))
					reverse_rotate(b);
				push(a, b);
			}
		}
		(*a) = (*a) -> next;
	}
}
