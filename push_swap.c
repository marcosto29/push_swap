/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 19:18:51 by matoledo          #+#    #+#             */
/*   Updated: 2025/06/04 18:47:46 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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

int	i = 0;

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
	while(aux->next)
	{
		if (aux->next == node)
			return aux;
		aux = aux->next;
	}
	return (NULL);
}

void	swap(t_list *s, char lst)
{
	int aux;

	i++;
	if(ft_lstsize(s) <= 1)
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
		if (ft_isdigit(*num) == 0 && 
			!((*num >= 9 && *num <= 13) || *num == 32))
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

	while(*s)
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

int	better_movement(t_list **b, int extreme_number)
{
	int		counter1;
	t_list	*pt_aux;

	counter1 = 0;
	pt_aux = *b;
	while (*(int *)pt_aux->content != extreme_number)
	{
		counter1++;
		pt_aux = pt_aux->next;
	}
	if (counter1 > ft_lstsize(*b) / 2)
		return (1);
	return (0);
}

int	bigger_number(int num1, int num2)
{
	if (num2 > num1)
		return (1);
	return (0);
}

int	smaller_number(int num1, int num2)
{
	if (num2 < num1)
		return (1);
	return (0);
}

int	get_number(t_list **lst, int (*cond)(int num1, int num2))
{
	int		extreme_number;
	t_list	*pt_aux;

	pt_aux = *lst;
	extreme_number = *(int *)pt_aux->content;
	while(pt_aux)
	{
		if (cond(extreme_number, *(int *)pt_aux->content) == 1)
			extreme_number = *(int *)pt_aux->content;			
		pt_aux = pt_aux->next;
	}
	return (extreme_number);
}

void	sort_3_elements(t_list **lst, int min_number)
{
	int	movement;

	movement = better_movement(lst, min_number);
	while (*(int *)(*lst )->content != min_number)
	{
		if (movement == 0)
			rotate(lst, 'b');
		if (movement == 1)
		{
			if (*(int *)(*lst)->next->content < *(int *)(*lst)->content)
				swap(*lst, 'b');
			reverse_rotate(lst, 'b');
		}
	}
	if (*(int *)(*lst)->next->content > *(int *)ft_lstlast((*lst))->content)
	{
		rotate(lst, 'b');
		swap(*lst, 'b');
		reverse_rotate(lst, 'b');
	}
}

int	search_number(t_list *a, t_list **b, int min, int max)
{
	t_list	*pt_aux;

	pt_aux = *b;
	if (*(int *)a->content < min)
		return (min);
	if (*(int *)a->content > max)
		return (min);
	while (!(*(int *)pt_aux->content > *(int *)a->content &&
		*(int *)previous_node(b, pt_aux)->content < *(int *)a->content))
		pt_aux = pt_aux->next;
	return (*(int *)pt_aux->content);
}

void	sort_list(t_list **a, t_list **b)
{
	int		min_number;
	int		max_number;
	int		next_movement;
	int		next_number;

	push(a, b, 'b');
	push(a, b, 'b');
	push(a, b, 'b');
	min_number = get_number(b, smaller_number);
	max_number = get_number(b, bigger_number);
	sort_3_elements(b, min_number);
	while(*a)
	{
		//esto busca el mejor movimiento para el primer nodo
		//pero antes de esto se podría mirar si algún otro nodo tiene mejor movimiento
		next_number = search_number(*a, b, min_number, max_number);
		next_movement = better_movement(b, next_number);
		while (*(int *)(*b)->content != next_number)
		{
			if (next_movement == 0)
				rotate(b, 'b');
			if (next_movement == 1)
				reverse_rotate(b, 'b');
		}
		if (*(int *)(*a)->content > max_number)
			max_number = *(int *)(*a)->content;
		if (*(int *)(*a)->content < min_number)
			min_number = *(int *)(*a)->content;
		push(a, b, 'b');
	}
	while (*(int *)(*b)->content != min_number)
		rotate(b, 'b');
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
		sort_list(a, b);
		while (*b)
		{
			printf("%d \n", *(int *)(*b)->content);
			(*b) = (*b)->next;
		}
		//ft_lstclear(a, del_number);
		free(a);
		printf("%d operaciones\n", i);
	}
	exit (0);
}
