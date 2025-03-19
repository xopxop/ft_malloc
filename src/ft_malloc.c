/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 00:37:32 by dthan             #+#    #+#             */
/*   Updated: 2025/03/19 11:51:41 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"
#include "helpers/formulars.h"


#include <stdio.h>
#include <string.h>
#include <unistd.h>

t_zone	*select_zone(size_t size)
{
	if (size > 0 && size <= TINY_ZONE_MAX_CHUNK_SIZE)
		return (&(g_heap.tiny));
	else if (size > TINY_ZONE_MAX_CHUNK_SIZE && size <= SMALL_ZONE_MAX_CHUNK_SIZE)
		return (&(g_heap.small));
	return (&(g_heap.large));
}

void	*ft_malloc(size_t size)
{
	t_zone	*zone;
	t_block	*block;
	t_chunk	*chunk;

	if (size == 0) return (NULL);
	size = aligned_data_size(size, ALIGNMENT);
	zone = select_zone(size);
	if (!zone) return (NULL);
	chunk = zone_find_free_chunk(zone, size);
	if (!chunk)
	{
		block = zone_extend_new_block(zone, size);
		if (!block) return (NULL);
		chunk = block_find_free_chunk(block, size);
	}
	if (chunk->meta_data.data_size > size + aligned_chunk_data_size())
		chunk_split(chunk, size);
	chunk->meta_data.is_free = 0;
	return (chunk_get_data(chunk));
}

size_t	show_alloc_mem_zone(t_zone zone)
{
	t_block *block;
	t_chunk *chunk;
	size_t total_size = 0;

	block = zone.blocks;
	while (block)
	{
		chunk = block_get_first_chunk(block);
		while (chunk)
		{
			if (!chunk->meta_data.is_free)
			{
				printf("%p - %p : %zu bytes\n", (void*)chunk_get_data(chunk), (void*)chunk_get_data(chunk) + chunk->meta_data.data_size, chunk->meta_data.data_size);
				total_size += chunk->meta_data.data_size;
			}
			chunk = chunk->next;
		}
		block = block->next;
	}
	return (total_size);
}

void	show_alloc_mem()
{
	size_t total_size = 0;

	total_size = 0;
	printf("TINY zone: %p\n", (void*)(g_heap.tiny.blocks));
	total_size += show_alloc_mem_zone(g_heap.tiny);
	printf("SMALL zone: %p\n", &(g_heap.small.blocks));
	total_size += show_alloc_mem_zone(g_heap.small);
	printf("LARGE zone: %p\n", &(g_heap.large.blocks));
	total_size += show_alloc_mem_zone(g_heap.large);
	printf("Total: %zu bytes\n", total_size);
}

// Testing the allocator
int main() {
	// Act
	void	*tiny1 = ft_malloc(10); // Tiny Zone
	void	*tiny2 = ft_malloc(1); // Tiny Zone

	show_alloc_mem();
	return 0;
}
