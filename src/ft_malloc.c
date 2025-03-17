/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalorin <esalorin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 00:37:32 by dthan             #+#    #+#             */
/*   Updated: 2025/03/17 07:52:21 by esalorin         ###   ########.fr       */
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
		printf("here\n");
		block = zone_extend_new_block(zone, size);
		if (!block) return (NULL);
		chunk = block_find_free_chunk(block, size);
	}
	if (chunk->meta_data.data_size > size + aligned_chunk_data_size())
		chunk_split(chunk, size);
	chunk->meta_data.is_free = 0;
	return (chunk_get_data(chunk));
}

void 	print_chunk(t_chunk *chunks)
{
	int i = 0;
	t_chunk *chunk;

	chunk = chunks;
	while (chunk)
	{
		printf("Chunk Address: %p\n", (void*)chunk);
		i++;
		chunk = chunk->next;
	}
	printf("index - %d\n", i);
}

void print_block(t_block *blocks)
{
	t_block *block;

	block = blocks;
	while (block)
	{
		printf("-----------------------\n");
		printf("Block Address: %p\n", (void*)block);
		print_chunk(block_get_first_chunk(block));
		printf("-----------------------\n");
		block = block->next;
	}
}

void	print_heap()
{
	printf("TINY zone: \n");
	print_block(g_heap.tiny.blocks);
}

// Testing the allocator
int main() {
	print_heap();

	// Act
	void	*tiny1 = ft_malloc(10); // Tiny Zone
	void	*tiny2 = ft_malloc(10); // Tiny Zone
	void	*tiny3 = ft_malloc(10); // Tiny Zone
	void	*tiny4 = ft_malloc(10); // Tiny Zone

	print_heap();
	return 0;
}
