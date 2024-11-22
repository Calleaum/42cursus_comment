/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calleaum <calleaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:18:06 by clement           #+#    #+#             */
/*   Updated: 2024/11/22 06:22:21 by calleaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Cette fonction traite le buffer après avoir extrait une ligne
// Elle crée une nouvelle chaîne contenant le reste du buffer après le '\n'
static char *ft_new_str(char *buffer)
{
    int     i;
    int     j;
    char    *str;

    i = 0;
    // Trouve la position du premier '\n'
    while (buffer[i] && buffer[i] != '\n')
        i++;
    // Si pas de '\n', libère le buffer et retourne NULL
    if (!buffer[i])
        return (free(buffer), NULL);
    // Alloue la mémoire pour la nouvelle chaîne
    str = malloc(sizeof(char) * (ft_strlen(buffer) - i + 1));
    if (!str)
        return (free(str), NULL);
    i++; // Passe le '\n'
    j = 0;
    // Copie le reste du buffer après le '\n'
    while (buffer[i])
        str[j++] = buffer[i++];
    str[j] = '\0';
    // Libère l'ancien buffer et retourne la nouvelle chaîne
    return (free(buffer), str);
}

// Cette fonction lit depuis le descripteur de fichier et remplit le buffer
static char *ft_read_str(int fd, char *buffer)
{
    char    *s;
    int     bytes;

    // Alloue un buffer temporaire pour la lecture
    s = malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (!s)
        return (NULL);
    bytes = 1;
    // Continue de lire tant qu'on ne trouve pas de '\n' et qu'on n'est pas à la fin du fichier
    while (!ft_strchr(buffer, '\n') && bytes != 0)
    {
        bytes = read(fd, s, BUFFER_SIZE);
        if (bytes < 0)
            return (free(s), free(buffer), NULL);
        s[bytes] = '\0';
        // Concatène ce qu'on vient de lire avec le buffer existant
        buffer = ft_strjoin(buffer, s);
    }
    return (free(s), buffer);
}

// Cette fonction extrait une ligne du buffer
static char *ft_get_line(char *buffer)
{
    int     i;
    char    *str;

    i = 0;
    if (!buffer[i])
        return (NULL);
    // Trouve la fin de la ligne
    while (buffer[i] && buffer[i] != '\n')
        i++;
    // Extrait la sous-chaîne jusqu'au '\n' inclus
    str = ft_substr(buffer, 0, i + ft_end_line(buffer));
    if (!str)
        return (free(str), NULL);
    return (str);
}

// Fonction principale qui retourne une ligne lue depuis un fd
char *get_next_line(int fd)
{
    char        *line;
    static char *buffer = NULL; // Buffer statique pour conserver les données entre les appels

    // Vérifie les paramètres invalides
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    // Lit depuis le fd et remplit le buffer
    buffer = ft_read_str(fd, buffer);
    if (!buffer)
        return (NULL);
    // Extrait une ligne du buffer
    line = ft_get_line(buffer);
    // Met à jour le buffer pour le prochain appel
    buffer = ft_new_str(buffer);
    return (line);
}

// #include <stdio.h>
// #include <fcntl.h>
// int	main(void)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("file.txt", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		perror("Error opening file");
// 		return (1);
// 	}
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}
// 	close(fd);
// 	return (0);
// }
