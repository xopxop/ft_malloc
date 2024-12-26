/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 18:43:10 by dthan             #+#    #+#             */
/*   Updated: 2023/06/17 14:26:35 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
#define FT_MALLOC_H

typedef struct s_block
{
    
}

typedef struct s_zone
{
    static size_t pages_count;
    size_t size;
    t_block *blocks;
}   t_zone;

typedef struct s_heap
{
    t_zone tiny;
    t_zone small;
    t_zone large;
}   t_heap;

t_heap g_malloc_heap;

#endif