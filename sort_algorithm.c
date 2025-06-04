/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 12:48:57 by matoledo          #+#    #+#             */
/*   Updated: 2025/06/04 18:30:00 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	next_movement(t_list **b, int extreme_number)
// {
// 	int		counter1;
// 	t_list	*pt_aux;

// 	counter1 = 0;
// 	pt_aux = *b;
// 	while (*(int *)pt_aux->content != extreme_number)
// 	{
// 		counter1++;
// 		pt_aux = pt_aux->next;
// 	}
// 	if (counter1 > ft_lstsize(*b) / 2)
// 		return (1);
// 	return (0);
// }

// int	bigger_number(int num1, int num2)
// {
// 	if (num2 > num1)
// 		return (1);
// 	return (0);
// }

// int	smaller_number(int num1, int num2)
// {
// 	if (num2 < num1)
// 		return (1);
// 	return (0);
// }

// int	get_number(t_list **lst, int (*cond)(int num1, int num2))
// {
// 	int		extreme_number;
// 	t_list	*pt_aux;

// 	pt_aux = *lst;
// 	extreme_number = *(int *)pt_aux->content;
// 	while(pt_aux)
// 	{
// 		if (cond(extreme_number, *(int *)pt_aux->content) == 1)
// 			extreme_number = *(int *)pt_aux->content;			
// 		pt_aux = pt_aux->next;
// 	}
// 	return (extreme_number);
// }

// void	sort_3_elements(t_list **lst, int min_number)
// {
// 	int	movement;

// 	movement = next_movement(lst, min_number);
// 	while (*(int *)(*lst )->content != min_number)
// 	{
// 		if (movement == 0)
// 			rotate(lst, 'b');
// 		if (movement == 1)
// 		{
// 			if (*(int *)(*lst)->next->content < *(int *)(*lst)->content)
// 				swap(*lst, 'b');
// 			reverse_rotate(lst, 'b');
// 		}
// 	}
// 	if (*(int *)(*lst)->next->content > *(int *)ft_lstlast((*lst))->content)
// 	{
// 		rotate(lst, 'b');
// 		swap(*lst, 'b');
// 		reverse_rotate(lst, 'b');
// 	}
// }

// int	search_number(t_list *a, t_list **b, int min, int max)
// {
// 	t_list	*pt_aux;

// 	pt_aux = *b;
// 	if (*(int *)a->content < min)
// 		return (min);
// 	if (*(int *)a->content > max)
// 		return (min);
// 	while (!(*(int *)pt_aux->content > *(int *)a->content &&
// 		*(int *)previous_node(b, pt_aux)->content < *(int *)a->content))
// 		pt_aux = pt_aux->next;
// 	return (*(int *)pt_aux->content);
// }

// void	sort_list(t_list **a, t_list **b)
// {
// 	int		min_number;
// 	int		max_number;
// 	int		movement;
// 	int		next_number;

// 	push(a, b, 'b');
// 	push(a, b, 'b');
// 	push(a, b, 'b');
// 	min_number = get_number(b, smaller_number);
// 	max_number = get_number(b, bigger_number);
// 	sort_3_elements(b, min_number);
// 	while(*a)
// 	{
// 		next_number = search_number(*a, b, min_number, max_number);
// 		movement = next_movement(b, next_number);
// 		while (*(int *)(*b)->content != next_number)
// 		{
// 			if (movement == 0)
// 				rotate(b, 'b');
// 			if (movement == 1)
// 				reverse_rotate(b, 'b');
// 		}
// 		if (*(int *)(*a)->content > max_number)
// 			max_number = *(int *)(*a)->content;
// 		if (*(int *)(*a)->content < min_number)
// 			min_number = *(int *)(*a)->content;
// 		push(a, b, 'b');
// 	}
// 	while (*(int *)(*b)->content != min_number)
// 		rotate(b, 'b');
// }
