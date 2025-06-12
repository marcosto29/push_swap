/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 19:18:51 by matoledo          #+#    #+#             */
/*   Updated: 2025/06/12 22:27:50 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	**a;
	t_list	**b;

	if (argc >= 2)
	{
		a = ft_calloc(sizeof(t_list *), 1);
		if (fill_list(a, argv + 1) == 0)
		{
			ft_printf("Error\n");
			exit(1);
		}
		if (!(*a) || check_sorted(*a) == 0)
		{
			ft_lstclear(a, del_number);
			free(a);
			exit(0);
		}
		b = ft_calloc(sizeof(t_list *), 1);
		prepare_sort_list(a, b);	
		ft_lstclear(a, del_number);
		free(a);
		free(b);
	}
	exit (0);
}
