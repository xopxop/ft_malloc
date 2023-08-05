/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 04:03:31 by dthan             #+#    #+#             */
/*   Updated: 2023/07/22 03:20:27 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/mman.h>
#include "block.h"

// free_block

t_block *new_block_obj(size_t size, size_t chunk_count)
{
  t_block *new_block;
  t_chunk *chunk = NULL;
  void *address;

	new_block = mmap(0, size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1 ,0);
	new_block->total_used_bytes = 0;
  new_block->chunk_count = chunk_count;
  new_block->max_bytes = size;
  new_block->max_asking_bytes = ((size - sizeof(t_block)) / chunk_count) - sizeof(t_chunk);
  new_block->next = NULL;
  while (--chunk_count >= 0) {
    if (chunk == NULL)
      address = new_block + 1;
    else
      address = (t_chunk*)((void*)(chunk + 1) + new_block->max_asking_bytes);
    chunk = new_chunk(address);
  }
	return new_block;
}

void blocks_add(t_block **blocks, t_block *new_block)
{
  t_block *block;

  if (*blocks == NULL)
    *blocks = new_block;
  else
  {
    block = *blocks;
    while (block->next)
      block = block->next;
    block->next = new_block;
  }
}

/*

t_block *blocks_remove(t_block **blocks, t_block *remove_block)
{
  t_block *block;

  block = *blocks;
  while (block)
  {
    if (block == remove_block)
    {
      *blocks = NULL;
      break ;
    }
    else if (block->next == remove_block)
    {
      block->next = remove_block->next;
      remove_block->next = NULL;
      break ;
    }
    block = block->next;
  }
  return remove_block;
}

t_block *blocks_find(void *data)
{
  return (t_block*)data - 1;
}
*/

/*

#include <stdio.h>

void blocks_print(t_block *blocks)
{
  t_block *block;

  block = blocks;
  while (block)
  {
    printf("%p - %p : %d bytes\n", (void*)(block + 1), (void*)((block + 1) + block->size));
    block = block->next;
  }
}

*/

void *blocks_get_memory(t_block *blocks, size_t size)
{
  t_block *block = blocks;

  while (block) {
    if (block->chunk_available_count)
      return block_get_memory(block, size);
    block = block->next;
  }
  block = new_block_obj(blocks->max_bytes, block->chunk_count);
  blocks_add(blocks, block);
  return block_get_memory(block, size);
}

void *block_get_memory(t_block *block, size_t size) {
  t_chunk *chunk = NULL;
  size_t chunk_count = block->chunk_count;

  while (chunk_count--) {
    if (chunk == NULL)
      chunk = block + 1;
    else
      chunk = (t_chunk*)((void*)(chunk + 1) + block->max_asking_bytes);
    if (chunk->available)
      break;
  }
  block->chunk_available_count--;
  return chunk_get_memory(chunk, size);
}