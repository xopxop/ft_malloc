/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formulars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 10:35:54 by dthan             #+#    #+#             */
/*   Updated: 2025/03/17 11:17:58 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t aligned_data_size(size_t size, size_t alignment)
{
    return (size + (alignment - 1)) & ~(alignment - 1);
}
