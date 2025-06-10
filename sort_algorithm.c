/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 12:48:57 by matoledo          #+#    #+#             */
/*   Updated: 2025/06/10 21:06:29 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_to_node(t_list **lst, t_list *node, int size_lst, char c)
{
	int		moves;
	t_list	*pt_aux;

	pt_aux = *lst;
	moves = 0;
	while (*(int *)pt_aux->content != *(int *)node->content)
	{
		moves++;
		pt_aux = pt_aux->next;
	}
	while (*(int *)(*lst)->content != *(int *)node->content)
	{
		if (moves <= size_lst / 2)
			rotate(lst, c);
		else
			reverse_rotate(lst, c);
	}
}

static void	evaluate_optimal_node(t_optimal_nodes *return_nodes, t_list **a, t_list *pt_aux, int moves_b)
{
	t_node_moves		*node_a;

	node_a = search_correct_position(a, pt_aux);
	if (*(int *)node_a->moves + moves_b < *(int *)return_nodes->moves)
	{
		*(int *)return_nodes->moves = *(int *)node_a->moves + moves_b;
		return_nodes->node_b = pt_aux;
		return_nodes->node_a = node_a->node;
	}
}

t_optimal_nodes	*o_nodes(t_list **a, t_list **b, int size_b)
{
	int				j;
	int				moves_b;
	t_list			*pt_aux;
	t_optimal_nodes	*return_nodes;

	j = 0;
	pt_aux = *b;
	return_nodes = ft_calloc(sizeof(t_optimal_nodes), 1);
	return_nodes->moves = ft_calloc(sizeof(int), 1);
	*(int *)return_nodes->moves = __INT_MAX__;
	while (pt_aux)
	{
		if (j <= size_b / 2)
			moves_b = j;
		else
			moves_b = size_b - j;
		evaluate_optimal_node(return_nodes, a, pt_aux, moves_b);
		pt_aux = pt_aux->next;
		j++;
	}
	return (return_nodes);
}

static void	sort_list(t_list **a, t_list **b, int size_a, int size_b)
{
	t_optimal_nodes	*next_nodes;
	t_list			*min;

	while (size_b--)
	{
		next_nodes = o_nodes(a, b, size_b);
		move_to_node(a, next_nodes->node_a, size_a, 'a');
		move_to_node(b, next_nodes->node_b, size_b, 'b');
		push(b, a, 'a');
		size_a++;
	}
	min = get_node_min(a);
	move_to_node(a, min, size_a, 'a');
}

void	prepare_sort_list(t_list **a, t_list **b)
{
	int			size_a;
	int			size_b;

	size_a = ft_lstsize(*a);
	size_b = 0;
	while (size_a > 2)
	{
		push(a, b, 'b');
		size_a--;
		size_b++;
	}
	if (*(int *)(*a)->content > *(int *)(*a)->next->content)
		swap(*a, 'a');
	sort_list(a, b, size_a, size_b);
}