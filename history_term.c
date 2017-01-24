#include <fcntl.h>
#include "libft.h"

#define WIN_X wpos->x
#define WIN_Y wpos->y
typedef struct  s_pos
{
	int         x;
	int         y;
}               t_pos;

int 	putchar_ft(int c);
void	print_pos(char *str, t_pos *wpos);

/*
**	MANAGE PROMPT OF HISTORY CMD
**	TODO: ERASE CURRENT LINE AND PROMPT FROM
**		  THE BEGING OF THE LINE
*/

int	term_history(int up, t_pos *wpos)
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
	{
		while (hcmd[i])
			++i;
	}
	i -= up;
	i = (i < 0) ? 0 : i;
	WIN_X = 3;
	if (i > -1)
		print_pos(hcmd[i], wpos);
	if (close(fd) == -1)
		ft_printfd(2, "MANAGE ERROR");
	return (0);
}
