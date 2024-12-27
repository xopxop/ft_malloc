/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 20:09:30 by dthan             #+#    #+#             */
/*   Updated: 2024/12/26 14:40:15 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHUNK_H
#define CHUNK_H
#define CHUNK_META_SIZE sizeof(t_chunk)

typedef struct s_chunk
{
	size_t	size;
	int		free;
	struct s_chunk	*next;
}	t_chunk;

#endif