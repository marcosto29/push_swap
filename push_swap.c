/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 19:18:51 by matoledo          #+#    #+#             */
/*   Updated: 2025/06/10 21:06:20 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int i = 0;

void	del_number(void *number)
{
	free(number);
}

void	free_memory(char **splitted_word)
{
	char	**pt_aux;

	pt_aux = splitted_word;
	while (*pt_aux)
	{
		free(*pt_aux++);
	}
	free(splitted_word);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char) c)
		{
			return ((char *)s);
		}
		s++;
	}
	if (*s == (char) c)
		return ((char *)s);
	return (NULL);
}


void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*pt_dest;
	const char	*pt_src;

	pt_src = src;
	pt_dest = dest;
	if (!src && !dest)
		return (dest);
	while (n--)
	{
		*pt_dest++ = *pt_src++;
	}
	return (dest);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
	{
		return (2048);
	}
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	number;
	int	negative;

	number = 0;
	negative = 1;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == 43 || *nptr == 45)
	{
		if (*nptr == 45)
			negative = -1;
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		number = number * 10 + (*nptr - '0');
		nptr++;
	}
	return (number * negative);
}

void	*ft_memset(void *dest, int c, size_t n)
{
	char	*pt_dest;

	pt_dest = dest;
	while (n--)
	{
		*pt_dest++ = (char)c;
	}
	return (dest);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total;
	char	*pt_call;

	total = nmemb * size;
	pt_call = malloc(total);
	if (!pt_call)
		return (NULL);
	ft_bzero(pt_call, total);
	return (pt_call);
}

static unsigned int	ft_splits_number(const char *to_split, char split_character)
{
	unsigned int	splits;

	splits = 0;
	while (*to_split)
	{
		while (*to_split && *to_split == split_character)
			to_split++;
		if (!*to_split)
			break ;
		splits++;
		while (*to_split && *to_split != split_character)
			to_split++;
	}
	return (splits);
}

static char	**ft_split_word(char **split, const char *to_split, char c)
{
	char	*pt_aux;
	char	*splitted;
	char	**pt_split;

	pt_split = split;
	while (*to_split)
	{
		while (*to_split && *to_split == c)
			to_split++;
		if (!*to_split)
			break ;
		pt_aux = ft_strchr(to_split, c);
		if (!pt_aux)
			pt_aux = ft_strchr(to_split, '\0');
		splitted = ft_calloc(sizeof(char), pt_aux - to_split + 1);
		if (!splitted)
			return (NULL);
		ft_memcpy(splitted, to_split, pt_aux - to_split);
		*split++ = splitted;
		to_split = pt_aux;
	}
	return (pt_split);
}

//function to split the string s to different string given the character c
char	**ft_split(char const *s, char c)
{
	char			**pt_return;
	unsigned int	splits;

	if (!s)
		return (NULL);
	splits = ft_splits_number(s, c);
	pt_return = ft_calloc(sizeof(char *), splits + 1);
	if (!pt_return)
		return (NULL);
	if (!ft_split_word(pt_return, s, c))
	{
		free_memory(pt_return);
		return (NULL);
	}
	return (pt_return);
}

int	ft_lstsize(t_list *lst)
{
	t_list	*aux;
	int		size;

	if (!lst)
		return (0);
	aux = lst;
	size = 1;
	while (aux->next)
	{
		size++;
		aux = aux->next;
	}
	return (size);
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*aux_node;

	if (!lst)
		return (NULL);
	aux_node = lst;
	while (aux_node->next)
	{
		aux_node = aux_node->next;
	}
	return (aux_node);
}

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *) ft_calloc(sizeof(t_list), 1);
	if (!node)
		return (0);
	node->content = content;
	node->next = NULL;
	return (node);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*old_node;

	old_node = *lst;
	*lst = new;
	new->next = old_node;
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*aux_node;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	aux_node = *lst;
	while (aux_node->next)
	{
		aux_node = aux_node->next;
	}
	aux_node->next = new;
}

t_list	*previous_node(t_list **lst, t_list *node)
{
	t_list	*aux;

	aux = *lst;
	if (aux == node)
		return (ft_lstlast(*lst));
	while (aux->next)
	{
		if (aux->next == node)
			return (aux);
		aux = aux->next;
	}
	return (NULL);
}

void	swap(t_list *s, char lst)
{
	int	aux;

	i++;
	if (ft_lstsize(s) <= 1)
		return ;
	aux = *(int *)s->content;
	*(int *)s->content = *(int *)s->next->content;
	*(int *)s->next->content = aux;
	write(1, "s", 1);
	write(1, &lst, 1);
	write(1, "\n", 1);
}

void	push(t_list **s1, t_list **s2, char lst)
{
	t_list	*aux;

	i++;
	if (ft_lstsize(*s1) <= 0)
		return ;
	aux = (*s1);
	(*s1) = (*s1)->next;
	aux->next = (*s2);
	(*s2) = aux;
	write(1, "p", 1);
	write(1, &lst, 1);
	write(1, "\n", 1);
}

void	rotate(t_list **s, char lst)
{
	t_list	*pt_aux;

	i++;
	if (ft_lstsize(*s) <= 1)
		return ;
	pt_aux = (*s);
	(*s) = (*s)->next;
	ft_lstlast((*s))->next = pt_aux;
	pt_aux->next = NULL;
	write(1, "r", 1);
	write(1, &lst, 1);
	write(1, "\n", 1);
}

void	reverse_rotate(t_list **s, char lst)
{
	t_list	*pt_aux;

	i++;
	if (ft_lstsize(*s) <= 1)
		return ;
	pt_aux = ft_lstlast((*s));
	previous_node(s, pt_aux)->next = NULL;
	pt_aux->next = (*s);
	(*s) = pt_aux;
	write(1, "rr", 2);
	write(1, &lst, 1);
	write(1, "\n", 1);
}

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	del(lst->content);
	free(lst);
}

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current_node;

	while (*lst)
	{
		current_node = *lst;
		*lst = (*lst)->next;
		ft_lstdelone(current_node, del);
	}
}

int	check_input(char *num)
{
	while (*num)
	{
		if (ft_isdigit(*num) == 0
			&& !((*num >= 9 && *num <= 13) || *num == 32))
			return (0);
		num++;
	}
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

int	add_numbers(t_list **lst, char **pt_aux)
{
	int		*aux;
	t_list	*node;

	while (*pt_aux)
	{
		aux = malloc(sizeof(int));
		*aux = ft_atoi(*pt_aux);
		if (check_repeated(*lst, *aux) == 0)
		{
			free(aux);
			return (0);
		}
		node = ft_lstnew(aux);
		ft_lstadd_back(lst, node);
		pt_aux++;
	}
	return (1);
}

int	fill_list(t_list **lst, char **s)
{
	char	**pt_aux;

	while (*s)
	{
		if (check_input(*s) == 0)
		{
			free_memory(pt_aux);
			return (0);
		}
		pt_aux = ft_split(*s, ' ');
		if (add_numbers(lst, pt_aux) == 0)
		{
			free_memory(pt_aux);
			return (0);
		}
		free_memory(pt_aux);
		s++;
	}
	return (1);
}

t_list	*get_node_max(t_list **lst)
{
	t_list	*pt_return;
	t_list	*pt_aux;

	pt_aux = *lst;
	pt_return = ft_calloc(sizeof(t_list), 1);
	pt_return->content = ft_calloc(sizeof(int), 1);
	*(int *)pt_return->content = *(int *)pt_aux->content;
	while (pt_aux)
	{
		if (*(int *)pt_aux->content > *(int *)pt_return->content)
			*(int *)pt_return->content = *(int *)pt_aux->content;
		pt_aux = pt_aux->next;
	}
	return (pt_return);
}

t_list	*get_node_min(t_list **lst)
{
	t_list	*pt_return;
	t_list	*pt_aux;

	pt_aux = *lst;
	pt_return = ft_calloc(sizeof(t_list), 1);
	pt_return->content = ft_calloc(sizeof(int), 1);
	*(int *)pt_return->content = *(int *)pt_aux->content;
	while (pt_aux)
	{
		if (*(int *)pt_aux->content < *(int *)pt_return->content)
			*(int *)pt_return->content = *(int *)pt_aux->content;
		pt_aux = pt_aux->next;
	}
	return (pt_return);
}

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

t_node_moves	*search_extreme_insert_position(t_list **a, t_list *extreme)
{
	int				counter;
	t_list			*pt_aux;
	t_node_moves	*pt_return;

	counter = 0;
	pt_aux = *a;
	pt_return = ft_calloc(sizeof(t_node_moves), 1);
	pt_return->moves = ft_calloc(sizeof(int), 1);
	while (*(int *)pt_aux->content != *(int *)extreme->content)
	{
		pt_aux = pt_aux->next;
		counter++;
	}
	pt_return->node = pt_aux;
	*(int *)pt_return->moves = counter;
	return (pt_return);
}

t_node_moves	*search_mid_insert_position(t_list **a, t_list *b)
{
	int				counter;
	t_list			*pt_aux;
	t_node_moves	*pt_return;

	counter = 0;
	pt_aux = *a;
	pt_return = ft_calloc(sizeof(t_node_moves), 1);
	pt_return->moves = ft_calloc(sizeof(int), 1);
	while (!(*(int *)pt_aux->content > *(int *)b->content
			&& *(int *)previous_node(a, pt_aux)->content < *(int *)b->content))
	{
		pt_aux = pt_aux->next;
		counter++;
	}
	pt_return->node = pt_aux;
	*(int *)pt_return->moves = counter;
	return (pt_return);
}

t_node_moves	*search_correct_position(t_list **a, t_list *b)
{
	t_list	*min;
	t_list	*max;

	min = get_node_min(a);
	max = get_node_max(a);
	if (*(int *)b->content < *(int *)min->content
		|| *(int *)b->content > *(int *)max->content)
		return (search_extreme_insert_position(a, min));
	else
		return (search_mid_insert_position(a, b));
}

void	evaluate_optimal_node(t_optimal_nodes *return_nodes, t_list **a, t_list *pt_aux, int moves_b)
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

int	main(int argc, char **argv)
{
	t_list	**a;
	t_list	**b;

	if (argc >= 2)
	{
		argv++;
		b = ft_calloc(sizeof(t_list *), 1);
		a = ft_calloc(sizeof(t_list *), 1);
		if (fill_list(a, argv) == 0)
		{
			//ft_printf("Error\n");
			exit(1);
		}
		prepare_sort_list(a, b);	
		while (*a)
		{
			printf("%d\n", *(int *)(*a)->content);
			*a = (*a)->next;
		}
		printf("operaciones: %d\n", i);
		ft_lstclear(a, del_number);
		free(a);
	}
	exit (0);
}
