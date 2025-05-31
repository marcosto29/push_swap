/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 19:41:58 by matoledo          #+#    #+#             */
/*   Updated: 2025/05/31 12:50:59 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*previous_node(t_list **lst, t_list *node)
{
	t_list	*aux;

	aux = *lst;
	while(aux->next)
	{
		if (aux->next == node)
			return aux;
		aux = aux->next;
	}
	return (NULL);
}

void	swap(t_list *s)
{
	int aux;

	if(ft_lstsize(s) <= 0)
	{
		aux = *(int *)s->content;
		*(int *)s->content = *(int *)s->next->content;
		*(int *)s->next->content = aux;
	}
}

void	push(t_list **s1, t_list **s2)
{
	t_list	*aux;
	
	if (ft_lstsize(s1) <= 0)
		return ;
	aux = (*s1);
	(*s1) = (*s1)->next;
	aux->next = (*s1);
	(*s1) = aux;
}

void	rotate(t_list **s)
{
	t_list	*pt_aux;
	
	if (ft_lstsize((*s)) <= 1)
		return ;
	pt_aux = (*s);
	(*s) = (*s)->next;
	ft_lstlast((*s))->next = pt_aux;
	pt_aux->next = NULL;
}

void	reverse_rotate(t_list **s)
{
	t_list	*pt_aux;
	
	if (ft_lstsize((*s)) <= 1)
		return ;
	pt_aux = ft_lstlast((*s));
	previous_node(s, pt_aux)->next = NULL;
	pt_aux->next = (*s);
	(*s) = pt_aux;
}
