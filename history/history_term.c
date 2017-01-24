#include <fcntl.h>
#include "libft.h"

int putchar_ft(int c);

/*
**	MANAGE PROMPT OF HISTORY CMD
**	TODO: ERASE CURRENT LINE AND PROMPT FROM
**		  THE BEGING OF THE LINE
*/

int	term_history(int up)
{
	static char	**hcmd = NULL;
	char		*tmp;
	int			fd;
	int			i;

	i = 0;
	if ((fd = open("/tmp/.history", O_RDONLY)) == -1)
		return (ft_printf("MANAGE ERROR"));
	if (!hcmd)
	{
		hcmd = malloc(sizeof(hcmd));
		while (get_next_line(fd, &tmp) > 0)
			hcmd[i++] = tmp;
	}
	if (!i)
		while (hcmd[i + 1])
			++i;
	i -= up;
	i = (i < 0) ? 0 : i;
	if (i >= -1)
		ft_printf("%s", hcmd[i]);
	if (close(fd) == -1)
		ft_printfd(2, "MANAGE ERROR");
	return (0);
}
