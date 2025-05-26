/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 19:43:37 by matoledo          #+#    #+#             */
/*   Updated: 2025/05/26 21:27:13 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include "libft/libftget_next_line/libftget_next_line.h"
# include "libft/libftprintf/libftprintf.h"

void	swap(t_list s);
char	push(t_list s1, t_list s2);
void	rotate(t_list s);
void	reverse_rotate(t_list s);

#endif