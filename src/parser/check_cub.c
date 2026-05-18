/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjorge-p < rjorge-p@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 12:24:12 by rjorge-p          #+#    #+#             */
/*   Updated: 2026/05/18 13:25:34 by rjorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int check_cub(char *filename)
{
    int len;

    if (!filename)
        return (0);
    len = ft_strlen(filename);
    if (len < 4)
        return (0);
    if (ft_strncmp(filename + len - 4, ".cub", 4) != 0)
        return (0);
    return (1);
}