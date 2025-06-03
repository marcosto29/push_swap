/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 19:43:37 by matoledo          #+#    #+#             */
/*   Updated: 2025/06/03 13:24:46 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include "libft/libftget_next_line/libftget_next_line.h"
# include "libft/libftprintf/libftprintf.h"

t_list	*previous_node(t_list **lst, t_list *node);
void	swap(t_list *s, char lst);
void	push(t_list **s1, t_list **s2, char lst);
void	rotate(t_list **s, char lst);
void	reverse_rotate(t_list **s, char lst);
void	del_number(void *number);
int		check_input(char *num);
int		check_repeated(t_list *lst, int num);
int		add_numbers(t_list **lst, char **pt_aux);
int		fill_list(t_list **lst, char **s);
void	free_memory(char **splitted_word);
//void	sort_list(t_list **a, t_list **b, char lst);

#endif