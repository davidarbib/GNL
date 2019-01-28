/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darbib <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 19:31:46 by darbib            #+#    #+#             */
/*   Updated: 2018/12/13 17:46:30 by darbib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *lst_cpy;
	t_list *head_cpy;
	t_list *trans_node;

	if (!lst)
		return (NULL);
	trans_node = (*f)(lst);
	lst = lst->next;
	lst_cpy = ft_lstnew((void const *)trans_node->content,
			trans_node->content_size);
	head_cpy = lst_cpy;
	while (lst)
	{
		trans_node = (*f)(lst);
		lst_cpy->next = ft_lstnew((void const *)trans_node->content,
				trans_node->content_size);
		lst_cpy = lst_cpy->next;
		lst = lst->next;
	}
	return (head_cpy);
}
