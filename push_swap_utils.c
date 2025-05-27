/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 19:41:58 by matoledo          #+#    #+#             */
/*   Updated: 2025/05/27 13:36:54 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	push(t_list *s1, t_list *s2)
{
	t_list	*aux;
	
	if (ft_lstsize(s2) <= 0)
		return ;
	aux = s2;
	s2 = s2->next;
	aux->next = s1;
	s1 = aux; 
}

void	rotate(t_list *s)
{
	t_list	*pt_aux;
	
	if (ft_lstsize(s) <= 1)
		return ;
	pt_aux = s;
	s = s->next;
	pt_aux->next = NULL;
	ft_lstlast(s)->next = pt_aux;
}

void	reverse_rotate(t_list *s)
{
	t_list	*pt_aux;
	t_list	*pt_aux2;
	
	if (ft_lstsize(s) <= 1)
		return ;
	pt_aux = s;
	pt_aux2 = s;
	while (pt_aux->next->next)
		pt_aux = pt_aux->next;
	ft_lstlast(s)->next = s->next;
	s = ft_lstlast(s);
	pt_aux -> next = pt_aux2;
	pt_aux2 -> next = NULL;
}