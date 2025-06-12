/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 19:43:37 by matoledo          #+#    #+#             */
/*   Updated: 2025/06/12 12:14:38 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include "libft/libftget_next_line/libftget_next_line.h"
# include "libft/libftprintf/libftprintf.h"
# include "limits.h"

typedef struct node_moves
{
	t_list	*node;
	int		*moves;
}	t_node_moves;

typedef struct optimal_nodes
{
	t_list	*node_a;
	t_list	*node_b;
	int		*moves;
}	t_optimal_nodes;

t_list			*previous_node(t_list **lst, t_list *node);
void			swap(t_list *s, char lst);
void			push(t_list **s1, t_list **s2, char lst);
void			rotate(t_list **s, char lst);
void			reverse_rotate(t_list **s, char lst);
int				check_sorted(t_list *lst);
int				check_input(char *num);
int				check_repeated(t_list *lst, int num);
int				check_bigger_int(char *pt_aux);
int				add_numbers(t_list **lst, char **pt_aux);
int				fill_list(t_list **lst, char **s);
void			del_number(void *number);
void			free_memory(char **splitted_word);
t_node_moves	*search_correct_position(t_list **a, t_list *b);
void			move_to_node(t_list **lst, t_list *node, int size_lst, char c);
void			prepare_sort_list(t_list **a, t_list **b);
t_list			*get_node_max(t_list **lst);
t_list			*get_node_min(t_list **lst);
void			sort_3_elements(t_list	**a);

#endif