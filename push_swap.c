/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 19:18:51 by matoledo          #+#    #+#             */
/*   Updated: 2025/05/31 14:50:39 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	i = 0;

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
	while(aux->next)
	{
		if (aux->next == node)
			return aux;
		aux = aux->next;
	}
	return (NULL);
}

void	swap(t_list *s)
{
	i++;
	int aux;

	if(ft_lstsize(s) <= 0)
	{
		aux = *(int *)s->content;
		*(int *)s->content = *(int *)s->next->content;
		*(int *)s->next->content = aux;
	}
}

void	push(t_list **s1, t_list **s2)
{
	i++;
	t_list	*aux;
	
	if (ft_lstsize(s1) <= 0)
		return ;
	aux = (*s1);
	(*s1) = (*s1)->next;
	aux->next = (*s2);
	(*s2) = aux;
}

void	rotate(t_list **s)
{
	i++;
	t_list	*pt_aux;
	
	if (ft_lstsize((*s)) <= 1)
		return ;
	pt_aux = (*s);
	(*s) = (*s)->next;
	ft_lstlast((*s))->next = pt_aux;
	pt_aux->next = NULL;
}

void	reverse_rotate(t_list **s)
{
	i++;
	t_list	*pt_aux;
	
	if (ft_lstsize((*s)) <= 1)
		return ;
	pt_aux = ft_lstlast((*s));
	previous_node(s, pt_aux)->next = NULL;
	pt_aux->next = (*s);
	(*s) = pt_aux;
}

void	fill_list(t_list **lst, char **s, int size)
{
	t_list	*node;
	int		aux;
	int		i;

	i = 0;
	while(i < size)
	{
		aux = ft_atoi(s[i]);
		node = ft_lstnew(aux);
		ft_lstadd_back(lst, node);
		i++;
	}
}

void	restart_list(t_list **lst, int *max_number)
{
	while ((*lst)->content != max_number)
		rotate(lst);
}

void	sort_list(t_list **a, t_list **b)
{
	int	*max_number;

	max_number = (*a) -> content;
	push(a, b);
	while (*a)
	{
		if((*a)->content > (*b)->content)
		{
			if ((*a)->content > ft_lstlast((*b))->content)
			{
				max_number = (*a) -> content;
				push(a, b);
			}
			else
			{
				while ((*a)->content > (*b) -> content)
					reverse_rotate(b);
				push(a, b);
			}
		}
		else
		{
			if ((*a)->content < ft_lstlast((*b))->content)
			{
				push(a, b);
				rotate(b);
			}
			else
			{
				while ((*a)->content < (*b) -> content)
					rotate(b);
				push(a, b);
			}
		}
		restart_list(b, max_number);
	}
}

int	main(int argc, char **argv)
{
	t_list	**a;
	t_list	**b;
char	*str[] = {
	"83", "5", "291", "12", "47", "390", "17", "64", "256", "804",
	"38", "700", "129", "6", "911", "302", "10", "423", "67", "99",
	"205", "871", "3", "58", "71", "88", "940", "15", "32", "199",
	"521", "110", "8", "675", "49", "222", "370", "41", "93", "1002",
	"913", "27", "3021", "76", "134", "818", "901", "2", "104", "999",
	"55", "342", "707", "611", "78", "20", "804", "47", "168", "444",
	"303", "18", "92", "84", "123", "66", "201", "987", "450", "23",
	"333", "600", "47", "1100", "9999", "51", "109", "800", "290", "145",
	"314", "400", "753", "321", "22", "172", "299", "67", "13", "9998",
	"75", "87", "202", "308", "409", "60", "99", "777", "306", "44"
};
	//if (argc >= 3)
	//{
		//argv++;
	b = ft_calloc(sizeof(t_list *), 1);
	a = ft_calloc(sizeof(t_list *), 1);
	fill_list(a, str, 100);
	sort_list(a, b);
	
	//}
	while (*b)
	{
		printf("%d\n", (*b)->content);
		(*b) = (*b)->next;
	}
	printf("%d operaciones\n", i);
}