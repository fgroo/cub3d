#include "error.h"

#include "libft.h"

#include <unistd.h>

void pr_error(const char *err)
{
	write(2, "Error\n", 6);
	if (err)
		write(2, err, ft_strlen(err));
}
