/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 04:03:31 by dthan             #+#    #+#             */
/*   Updated: 2025/03/13 15:54:58 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/mman.h>
#include "block.h"
#include "../../helpers/formulars.h"

t_chunk *block_get_first_chunk(t_block *block)
{
	return (t_chunk*)((char*)block + sizeof(t_block));
}

t_chunk *block_find_free_chunk(t_block *block, size_t size)
{
	t_chunk *chunk;

	chunk = block_get_first_chunk(block);
	while (chunk)
	{
		if (chunk->is_free && chunk->data_size >= size)
			return (chunk);
		chunk = chunk->next;
	}
	return (NULL);
}

t_block *new_block(size_t size)
{
	void	*base_address;
	size_t	data_size;
	t_block *block;

	size = align_data_size(size, getpagesize());
	base_address = mmap(0, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if (base_address == MAP_FAILED)
		return (NULL);
	data_size = size - sizeof(t_block) - sizeof(t_chunk);
	block = (t_block*)base_address;
	block->meta_data.total_data_size = data_size;
	block->meta_data.available_data_size = data_size;
	new_chunk((char*)base_address + sizeof(t_block), data_size);
	return (block);
}
