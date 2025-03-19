/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 04:03:31 by dthan             #+#    #+#             */
/*   Updated: 2025/03/19 11:52:06 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/mman.h>
#include <unistd.h>
#include "block.h"
#include "../../helpers/formulars.h"

size_t	aligned_block_data_size()
{
	return aligned_data_size(sizeof(t_block), sizeof(void*));
}

t_chunk *block_get_first_chunk(t_block *block)
{
	return (t_chunk*)((char*)block + sizeof(t_block));
}


#include <stdio.h>

t_chunk *block_find_free_chunk(t_block *block, size_t size)
{
	t_chunk *chunk;

	chunk = block_get_first_chunk(block);
	while (chunk)
	{
		if (chunk->meta_data.is_free && chunk->meta_data.data_size >= size)
			return (chunk);
		chunk = chunk->next;
	}
	return (NULL);
}

t_block *new_block(size_t size)
{
	size_t	requested_data_size;
	void	*base_address;
	t_block *block;

	requested_data_size = aligned_data_size( \
		size + aligned_block_data_size() + aligned_chunk_data_size(), \
		getpagesize() \
	);
	base_address = mmap(0, requested_data_size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if (base_address == MAP_FAILED)
		return (NULL);
	block = (t_block*)base_address;
	block->meta_data.available_data_size = requested_data_size - aligned_block_data_size() - aligned_chunk_data_size();
	block->meta_data.total_data_size = block->meta_data.available_data_size;
	new_chunk((void*)((char*)base_address + aligned_block_data_size()), block->meta_data.available_data_size);
	return (block);
}
