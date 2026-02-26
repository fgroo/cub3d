// #include "parser.h"
#include "libft.h"

/*  Pass a line from the .cub file to extract the path of the texturefile.
 *
 *  Example:
 *  void foo()
 *  {
 *		...
 *
 *		char *line = get_next_line(fd);
 *		if (!line)
 *			return (NULL);
 *		char *tex = fetch_texture_file(line, "NO");
 *
 *		...
 *  }
 */
char *fetch_texture_file(const char *line, const char *identifier)
{
	char	*tex;
	size_t 	i;
	size_t	len;

	i = 0;
	while (line[i] && line[i] == identifier[i])
		++i;
	if (identifier[i] != '\0')
		return (NULL);
	while (line[i] && ft_isspace(line[i]))
		++i;
	if (line[i] == '\0')
		return (NULL);
	len = 0;
	while (line[i + len] && !ft_isspace(line[i + len]))
		++len;
	tex = ft_strndup(line + i, len);
	return tex;
}

// int fetch_color(const char *line, const char *identifier)
// {
// 	char	*tex;
// 	size_t 	i;
//
// 	i = 0;
// 	while (line[i] && line[i] == identifier[i])
// 		++i;
// 	if (identifier[i] != '\0')
// 		return (-1);
// 	while (line[i] && ft_isspace(line[i]))
// 		++i;
// 	if (line[i] == '\0')
// 		return (-1);
// 	return color;
// }

int to_hex_color(int r, int g, int b)
{
	if (r < 0 || g < 0 || b < 0 || r > 255 || g > 255 || b > 255)
		return (-1);
	return ((r << 16) | (g << 8) | b);
}

