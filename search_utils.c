/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 18:18:42 by matoledo          #+#    #+#             */
/*   Updated: 2025/06/11 13:18:28 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*get_node_max(t_list **lst)
{
	t_list	*pt_return;
	t_list	*pt_aux;

	pt_aux = *lst;
	pt_return = ft_calloc(sizeof(t_list), 1);
	pt_return->content = ft_calloc(sizeof(int), 1);
	*(int *)pt_return->content = *(int *)pt_aux->content;
	while (pt_aux)
	{
		if (*(int *)pt_aux->content > *(int *)pt_return->content)
			*(int *)pt_return->content = *(int *)pt_aux->content;
		pt_aux = pt_aux->next;
	}
	return (pt_return);
}

t_list	*get_node_min(t_list **lst)
{
	t_list	*pt_return;
	t_list	*pt_aux;

	pt_aux = *lst;
	pt_return = ft_calloc(sizeof(t_list), 1);
	pt_return->content = ft_calloc(sizeof(int), 1);
	*(int *)pt_return->content = *(int *)pt_aux->content;
	while (pt_aux)
	{
		if (*(int *)pt_aux->content < *(int *)pt_return->content)
			*(int *)pt_return->content = *(int *)pt_aux->content;
		pt_aux = pt_aux->next;
	}
	return (pt_return);
}

static t_node_moves	*search_extreme_insert_position(t_list **a, t_list *extreme)
{
	int				counter;
	t_list			*pt_aux;
	t_node_moves	*pt_return;

	counter = 0;
	pt_aux = *a;
	pt_return = ft_calloc(sizeof(t_node_moves), 1);
	pt_return->moves = ft_calloc(sizeof(int), 1);
	while (*(int *)pt_aux->content != *(int *)extreme->content)
	{
		pt_aux = pt_aux->next;
		counter++;
	}
	ft_lstdelone(extreme, del_number);
	pt_return->node = pt_aux;
	*(int *)pt_return->moves = counter;
	return (pt_return);
}

static t_node_moves	*search_mid_insert_position(t_list **a, t_list *m)
{
	int				counter;
	t_list			*pt_aux;
	t_node_moves	*pt_return;

	counter = 0;
	pt_aux = *a;
	pt_return = ft_calloc(sizeof(t_node_moves), 1);
	pt_return->moves = ft_calloc(sizeof(int), 1);
	while (!(*(int *)pt_aux->content > *(int *)m->content
			&& *(int *)previous_node(a, pt_aux)->content < *(int *)m->content))
	{
		pt_aux = pt_aux->next;
		counter++;
	}
	pt_return->node = pt_aux;
	*(int *)pt_return->moves = counter;
	return (pt_return);
}

t_node_moves	*search_correct_position(t_list **a, t_list *b)
{
	t_list	*min;
	t_list	*max;

	min = get_node_min(a);
	max = get_node_max(a);
	if (*(int *)b->content < *(int *)min->content
		|| *(int *)b->content > *(int *)max->content)
	{
		ft_lstdelone(max, del_number);
		return (search_extreme_insert_position(a, min));
	}
	else
	{
		ft_lstdelone(min, del_number);
		ft_lstdelone(max, del_number);
		return (search_mid_insert_position(a, b));
	}
}
