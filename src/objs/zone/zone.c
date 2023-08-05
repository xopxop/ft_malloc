/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 02:47:30 by dthan             #+#    #+#             */
/*   Updated: 2023/07/16 00:52:53 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zone.h"
#include <sys/mman.h>
#include <sys/resource.h>
#define DEFINED_CHUNK_COUNT 100

// heap -> zone -> block -> chunk

t_defined_zone *new_defined_zone_obj(int pages_per_block)
{
  t_defined_zone *zone;

  
  zone = mmap(0, sizeof(t_defined_zone), PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1 ,0);
  zone->pages_per_block = pages_per_block;
  zone->chunks_per_block = (zone->pages_per_block * getpagesize() - sizeof(t_block)) / 100;
  zone->max_asking_bytes = zone->chunks_per_block - sizeof(t_chunk);
  zone->total_used_size = 0;
  zone->blocks = new_block_obj(zone->pages_per_block * getpagesize(), DEFINED_CHUNK_COUNT);
  return zone;
}

t_undefined_zone *new_undefined_zone_obj()
{
  t_undefined_zone *zone;
  struct rlimit rlimit;
  
  getrlimit(RLIMIT_AS, &rlimit);
  zone = mmap(0, sizeof(t_undefined_zone), PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1 ,0);
  zone->total_used_size = 0;
  zone->max_asking_bytes = rlimit.rlim_cur - sizeof(t_block) - sizeof(t_chunk);
  zone->blocks = NULL;
  return zone;
}

void *defined_zone_get_memory(t_defined_zone *zone, size_t bytes)
{
  t_block *block = zone->blocks;

  while (block) {
    if (block->chunk_available_count)
      return block_get_memory(block, bytes);
    block = block->next;
  }
  block = new_block_obj(block->max_bytes, block->chunk_count);
  blocks_add(zone->blocks, block);
  return block_get_memory(block, bytes);
}

void *undefined_zone_get_memory(t_undefined_zone *zone, size_t bytes)
{
  if (bytes > zone->max_asking_bytes)
    return NULL;
  t_block *block = new_block_obj(bytes + sizeof(t_block) + sizeof(t_chunk), 1);
  blocks_add(zone->blocks, block);
  return block_get_memory(block, bytes);
}
