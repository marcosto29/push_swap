/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 19:41:58 by matoledo          #+#    #+#             */
/*   Updated: 2025/05/26 21:34:58 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list *s)
{
	t_list *aux;

	if(ft_lstsize(s) <= 0)
	{
		aux = s;
		*(s->next) = *(s->next->next);
		*(s->next->next) = *aux;
	}
}

char	**push(t_list *s1, t_list *s2)
{
	char	**pt_aux;

	if (ft_strlen(s2) == 0)
		return ;
	
	//Toma el primer elemento del stack b y lo pone el primero en el stack a. No hace nada si b está vacío
}

void	rotate(char *s)
{

	//Desplaza hacia arriba todos los elementos del stack a una posición, de forma que el primer elemento se convierte en el último.
}

void	reverse_rotate(char *s)
{
	
	//Desplaza hacia abajo todos los elementos del stack a una posición, de forma que el último elemento se convierte en el primero
}