/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 20:10:19 by dthan             #+#    #+#             */
/*   Updated: 2025/03/13 15:03:58 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chunk.h"

void	*chunk_get_data(t_chunk *chunk)
{
	return (void*((char*)chunk + sizeof(t_chunk_meta_data)));
}

tchunk *new_chunk(char *base_address, size_t data_size)
{
	t_chunk *chunk;

	chunk = (t_chunk*)base_address;
	chunk_generate_chunk_meta_data(base_address, data_size);
	chunk->meta_data.data_size = data_size;
	chunk->meta_data.is_free = 1;
	chunk->next = NULL;
	return (chunk);
}

void	chunk_split(t_chunk *chunk, size_t bytes)
{
	t_chunk *new_chunk;

	new_chunk = new_chunk( \
		(char*)chunk + sizeof(t_chunk_meta_data) + bytes, \
		chunk->meta_data.data_size - bytes - sizeof(t_chunk_meta_data) \
	);
	new_chunk = chunk->next;
	chunk->next = new_chunk;
	chunk->meta_data.data_size = bytes;
}
