/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 01:25:49 by dthan             #+#    #+#             */
/*   Updated: 2023/07/05 20:14:06 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAP_H
# define HEAP_H
# include <stddef.h>
# include <unistd.h>
#include "../zone/zone.h"
# define PAGES_PER_TINY_BLOCK 2
# define PAGES_PER_SMALL_BLOCK 4

typedef struct s_heap
{
	t_defined_zone	*tiny;
	t_defined_zone	*small;
	t_undefined_zone	*large;
}	t_heap;

t_heap	*new_heap_obj(void);
void	*heap_get_memory(t_heap *heap, size_t size);

#endif