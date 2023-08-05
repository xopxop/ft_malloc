/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 04:03:28 by dthan             #+#    #+#             */
/*   Updated: 2023/08/05 15:34:33 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BLOCK_H
#define BLOCK_H
#include "../chunk/chunk.h";
#include <stddef.h>

/*
  block node will contain:
  - max_bytes = for creating a new block
  - total_used_bytes = for printing
  - total_chunk_count = for printing
  - available_chunk_count = for finding free chunk in a block
  - next node;
*/

typedef struct s_block
{
	size_t total_used_bytes;
  size_t max_asking_bytes;
  size_t max_bytes;
  size_t chunk_count;
  size_t chunk_available_count;
  struct s_block *next;
} t_block;

t_block *new_block_obj(size_t size, size_t chunks_count);
void delete_block_obj(t_block *block);
void blocks_add(t_block **blocks, t_block *new_block);
t_block *blocks_remove(t_block **blocks, t_block *remove_block);
t_block *blocks_find(void *data);
void blocks_print(t_block *blocks);


void *block_get_memory(t_block *block, size_t size);

#endif
