/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zone.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 02:45:39 by dthan             #+#    #+#             */
/*   Updated: 2023/07/08 14:22:40 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZONE_H
#define ZONE_H
# include "../block/block.h"

typedef struct s_defined_zone
{
	struct s_block *blocks;
	size_t chunks_per_block;
	size_t pages_per_block;
	size_t max_asking_bytes;
	size_t total_used_size;
} t_defined_zone;

typedef struct s_undefined_zone
{
	struct s_block *blocks;
	size_t total_used_size;
	size_t max_asking_bytes;
} t_undefined_zone;

t_defined_zone *new_defined_zone_obj(int pages_per_block);
t_undefined_zone *new_undefined_zone_obj();
void *defined_zone_get_memory(t_defined_zone *zone, size_t bytes);
void *undefined_zone_get_memory(t_undefined_zone *zone, size_t bytes);

#endif
