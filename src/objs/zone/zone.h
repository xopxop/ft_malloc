/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zone.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 12:11:15 by du.than           #+#    #+#             */
/*   Updated: 2024/12/26 12:24:56 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZONE_H
#define ZONE_H
#include "../block/block.h"

typedef struct s_zone
{
	size_t size;
	struct s_block *blocks;
}	t_zone;

#endif
