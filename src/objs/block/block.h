/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 04:03:28 by dthan             #+#    #+#             */
/*   Updated: 2024/12/26 14:40:54 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BLOCK_H
#define BLOCK_H
#define PAGE_SIZE getpagesize()
#define BLOCK_META_SIZE sizeof(t_block)
#include "../chunk/chunk.h"

typedef struct s_block
{
	size_t	size;
	void	*base;
	t_chunk	*chunks;
	struct s_block *next;
}	t_block;

#endif
