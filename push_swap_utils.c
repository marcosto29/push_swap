/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 19:41:58 by matoledo          #+#    #+#             */
/*   Updated: 2025/06/10 18:15:09 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*previous_node(t_list **lst, t_list *node)
{
	t_list	*aux;

	aux = *lst;
	if (aux == node)
		return (ft_lstlast(*lst));
	while (aux->next)
	{
		if (aux->next == node)
			return (aux);
		aux = aux->next;
	}
	return (NULL);
}

void	swap(t_list *s, char lst)
{
	int	aux;

	if (ft_lstsize(s) <= 1)
		return ;
	aux = *(int *)s->content;
	*(int *)s->content = *(int *)s->next->content;
	*(int *)s->next->content = aux;
	write(1, "s", 1);
	write(1, &lst, 1);
	write(1, "\n", 1);
}

void	push(t_list **s1, t_list **s2, char lst)
{
	t_list	*aux;

	if (ft_lstsize(*s1) <= 0)
		return ;
	aux = (*s1);
	(*s1) = (*s1)->next;
	aux->next = (*s2);
	(*s2) = aux;
	write(1, "p", 1);
	write(1, &lst, 1);
	write(1, "\n", 1);
}

void	rotate(t_list **s, char lst)
{
	t_list	*pt_aux;

	if (ft_lstsize(*s) <= 1)
		return ;
	pt_aux = (*s);
	(*s) = (*s)->next;
	ft_lstlast((*s))->next = pt_aux;
	pt_aux->next = NULL;
	write(1, "r", 1);
	write(1, &lst, 1);
	write(1, "\n", 1);
}

void	reverse_rotate(t_list **s, char lst)
{
	t_list	*pt_aux;

	if (ft_lstsize(*s) <= 1)
		return ;
	pt_aux = ft_lstlast((*s));
	previous_node(s, pt_aux)->next = NULL;
	pt_aux->next = (*s);
	(*s) = pt_aux;
	write(1, "rr", 2);
	write(1, &lst, 1);
	write(1, "\n", 1);
}
