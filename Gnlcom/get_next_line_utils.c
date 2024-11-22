/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calleaum <calleaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:18:10 by clement           #+#    #+#             */
/*   Updated: 2024/11/22 06:22:22 by calleaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Calcule la longueur d'une chaîne de caractères jusqu'au '\0'
// Paramètre str: la chaîne à mesurer
// Retour: nombre de caractères dans la chaîne
size_t	ft_strlen(const char *str)
{
   size_t	len;

   len = 0;                // Initialise le compteur
   while (str[len])       // Continue jusqu'au '\0'
   	len++;             // Incrémente pour chaque caractère
   return (len);          // Retourne longueur totale
}

// Cherche la première occurrence d'un caractère dans une chaîne
// Paramètres:
//   str: chaîne où chercher
//   c: caractère à trouver
// Retour: pointeur vers caractère trouvé ou NULL si absent
char	*ft_strchr(const char *str, int c)
{
   if (!str)              // Vérifie si str est NULL
   	return (NULL);
   while (*str)           // Parcourt la chaîne
   {
   	if (*str == (char)c)  // Compare avec le caractère recherché
   		return ((char *)str); // Retourne position si trouvé
   	str++;             // Passe au caractère suivant
   }
   return (NULL);         // Caractère non trouvé
}

// Joint deux chaînes et libère la première
// Paramètres:
//   first: première chaîne (sera libérée)
//   second: deuxième chaîne
// Retour: nouvelle chaîne contenant first+second
char	*ft_strjoin(char *first, char *second)
{
   char	*result;
   int		pos1;
   int		pos2;

   if (!first)           // Si first est NULL
   {
   	first = malloc(1);  // Crée une chaîne vide
   	first[0] = '\0';
   }
   result = malloc(ft_strlen(first) + ft_strlen(second) + 1);
   if (!result)          // Vérifie l'allocation
   	return (NULL);
   pos1 = 0;
   while (first[pos1])   // Copie first dans result
   {
   	result[pos1] = first[pos1];
   	pos1++;
   }
   pos2 = 0;
   while (second[pos2])  // Ajoute second à la suite
   	result[pos1++] = second[pos2++];
   result[pos1] = '\0';  // Termine la chaîne
   return (free(first), result); // Libère first et retourne result
}

// Extrait une sous-chaîne
// Paramètres:
//   str: chaîne source
//   start: position de début
//   len: longueur à extraire
// Retour: nouvelle chaîne contenant l'extrait
char	*ft_substr(const char *str, unsigned int start, size_t len)
{
   char	*result;
   size_t	pos;

   if (!str || start > ft_strlen(str))  // Gestion cas d'erreur
   	return (malloc(1));              // Retourne chaîne vide
   if (ft_strlen(str + start) < len)    // Ajuste len si trop grande
   	len = ft_strlen(str + start);
   result = malloc(len + 1);            // Alloue mémoire
   if (!result)
   	return (NULL);
   pos = 0;
   while (pos < len && str[start + pos]) // Copie les caractères
   {
   	result[pos] = str[start + pos];
   	pos++;
   }
   result[pos] = '\0';                  // Termine la chaîne
   return (result);
}

// Vérifie si un retour à la ligne est présent
// Paramètre str: chaîne à vérifier
// Retour: 1 si '\n' présent, 0 sinon
int	ft_end_line(char *str)
{
   if (!str)              // Vérifie si str est NULL
   	return (0);
   while (*str)           // Parcourt la chaîne
   {
   	if (*str == '\n')  // Cherche '\n'
   		return (1);    // Trouvé
   	str++;             // Caractère suivant
   }
   return (0);            // Non trouvé
}
