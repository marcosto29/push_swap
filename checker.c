/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 11:46:16 by matoledo          #+#    #+#             */
/*   Updated: 2025/06/13 09:11:08 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sorted(t_list *lst)
{
	t_list	*pt_aux;

	pt_aux = lst;
	pt_aux = pt_aux->next;
	while (pt_aux)
	{
		if (*(int *)pt_aux->content < *(int *)lst->content)
			return (1);
		pt_aux = pt_aux->next;
		lst = lst->next;
	}
	return (0);
}

int	check_input(char *num)
{
	int	counter;

	counter = 0;
	if (*num == '-' || *num == '+')
		num++;
	while (*num)
	{
		counter++;
		if (ft_isdigit(*num) == 0
			&& !((*num >= 9 && *num <= 13) || *num == 32))
			return (0);
		num++;
	}
	if (counter >= 11)
		return (0);
	return (1);
}

int	check_repeated(t_list *lst, int num)
{
	while (lst)
	{
		if (*(int *)lst->content == num)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int	check_bigger_int(char *pt_aux)
{
	long	*checker;

	checker = ft_calloc(sizeof(long), 1);
	*checker = ft_atol(pt_aux);
	if (*checker > INT_MAX || *checker < INT_MIN)
	{
		free(checker);
		return (0);
	}
	free(checker);
	return (1);
}
