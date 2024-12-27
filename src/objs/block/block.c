/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 04:03:31 by dthan             #+#    #+#             */
/*   Updated: 2024/12/26 14:56:14 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/mman.h>
#include "block.h"

t_block *new_block(size_t size)
{
	void *block_base;
	t_block *block;
	t_chunk *initial_chunk;

	size = (size + PAGE_SIZE - 1) & ~(PAGE_SIZE - 1);
	block_base = mmap(0, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if (block_base == MAP_FAILED) return NULL;
	block = (t_block*)block_base;
	block->size = size - BLOCK_META_SIZE;
	block->chunks = (char*)block_base + BLOCK_META_SIZE;
	block->next = NULL;
	initial_chunk = block->chunks;
	initial_chunk->size = block->size - CHUNK_META_SIZE;
	initial_chunk->free = 1;
	initial_chunk->next = NULL;
	return block;
}

t_chunk *block_find_free_chunk(t_block *block, size_t size)
{
	t_chunk *chunk;

	chunk = block->chunks;
	while (chunk)
	{
		if (chunk->free && chunk->size >= size)
			return chunk;
		chunk = chunk->next;
	}
	return NULL;
}
