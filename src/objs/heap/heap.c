/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 01:29:31 by dthan             #+#    #+#             */
/*   Updated: 2023/07/09 19:55:02 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heap.h"
#include <sys/mman.h>
// free heap

t_heap *new_heap_obj()
{
	t_heap *heap;
	void *address;

	address = mmap(0, sizeof(t_heap), PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1 ,0);

	heap = address;
	heap->tiny = new_defined_zone_obj(PAGES_PER_TINY_BLOCK);
	heap->small = new_defined_zone_obj(PAGES_PER_SMALL_BLOCK);
	heap->large = new_undefined_zone_obj();
	return heap;
}

/*
#include <stdio.h>

void heap_show_memory(t_heap *heap)
{
	printf("TINY: %p\n", (void*)(heap->tiny));
	blocks_print(heap->tiny->blocks);
	printf("SMALL: %p\n", (void*)(heap->small));
	blocks_print(heap->small->blocks);
	printf("LARGE: %p\n", (void*)(heap->large));
	blocks_print(heap->large->blocks);
	printf("Total: %d bytes\n", heap->tiny->size + heap->small->size + heap->large->size);
}
*/

void *heap_get_memory(t_heap *heap, size_t bytes)
{
	if (bytes <= 0)
		return NULL;
	else if (bytes <= heap->tiny->max_asking_bytes)
		return defined_zone_get_memory(heap->tiny, bytes);
	else if (bytes <= heap->small->max_asking_bytes)
		return defined_zone_get_memory(heap->tiny, bytes);
	else
		return undefined_zone_get_memory(heap->large, bytes);
}
