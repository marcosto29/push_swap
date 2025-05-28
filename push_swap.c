/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 19:18:51 by matoledo          #+#    #+#             */
/*   Updated: 2025/05/28 17:13:40 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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
	t_list	*aux;
	
	if (ft_lstsize(s2) <= 0)
		return ;
	aux = (*s2);
	(*s2) = (*s2)->next;
	aux->next = (*s1);
	(*s1) = aux;
}

void	rotate(t_list **s)
{
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

int	main(int argc, char **argv)
{
	t_list	**lst;
	char	*str[] = {"2", "3", "34", "54"};

	//if (argc >= 3)
	//{
		//argv++;
		lst = ft_calloc(sizeof(t_list *), 1);
		fill_list(lst, str, 4);
	//}

	while (*lst)
	{
		printf("%d\n", (*lst)->content);
		(*lst) = (*lst)->next;
	}
}