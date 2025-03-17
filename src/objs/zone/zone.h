/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zone.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 12:11:15 by du.than           #+#    #+#             */
/*   Updated: 2025/03/17 09:53:43 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZONE_H
#define ZONE_H
#include "../block/block.h"
#define TINY_ZONE_LIMIT_SIZE 

enum e_zone
{
	TINY,
	SMALL,
	LARGE
};

typedef struct s_zone
{
	size_t limit_size;
	struct s_block *blocks;
}	t_zone;

t_chunk		*zone_find_free_chunk(t_zone *zone, size_t size);
t_block		*zone_extend_new_block(t_zone *zone, size_t size);

#endif
