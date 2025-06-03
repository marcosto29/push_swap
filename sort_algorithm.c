/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 12:48:57 by matoledo          #+#    #+#             */
/*   Updated: 2025/06/03 21:00:17 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	sort_list(t_list **a, t_list **b)
// {
// 	int	min_number;

// 	push(a, b, 'b');
// 	push(a, b, 'b');
// 	push(a, b, 'b');
// 	min_number = get_min_number(b);
// 	sort_3_elements(b, min_number);
// 	while(*a)
// 	{
// 		if (*(int *)(*a)->content < min_number)
// 		{
// 			//meter funcion para ver si se tardaria menos en hacer reverse o rotate normal
// 			while (*(int *)(*b)->content != min_number)
// 				rotate(b, 'b');
// 			min_number = *(int *)(*a)->content;
// 			push(a, b, 'b');
// 		}
// 		else 
// 		{
// 			while (!(*(int *)(*b)->content > *(int *)(*a)->content &&
// 					*(int *)(ft_lstlast(*b))->content < *(int *)(*a)->content))
// 				rotate(b, 'b');
// 			push(a, b, 'b');
// 		}
// 	}
// 	while (*(int *)(*b)->content != min_number)
// 		rotate(b, 'b');
// }
