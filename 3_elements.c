/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_elements.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 14:20:27 by matoledo          #+#    #+#             */
/*   Updated: 2025/06/12 12:47:52 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3_elements(t_list	**a)
{
	t_list	*max;

	max = get_node_max(a);
	while (*(int *)ft_lstlast(*a)->content != *(int *)max->content)
		rotate(a, 'a');
	if (*(int *)(*a)->content > *(int *)(*a)->next->content)
		swap(*a, 'a');
	del_number(max->content);
	free(max);
}
