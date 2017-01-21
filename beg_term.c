#include <curses.h>
#include <term.h>
#include "libft.h"

int	putchar_ft(int c)
{
	char	d;

	d = c;
	return (write(1, &d, 1));
}

int main()
{
	char			*name_term;
	struct termios	termos;
	char			*res;

	if ((name_term = getenv("TERM")) == NULL)
		return (-1);
	if (tgetent(NULL, name_term) == ERR)
		return (-1);
	if (tcgetattr(0, &termos) == -1)
		return (-1);
	termos.c_lflag &= ~(ICANON);
	termos.c_lflag &= ~(ECHO);
	termos.c_cc[VMIN] = 1;
	termos.c_cc[VTIME] = 0;
	if ((res = tgetstr("cl", NULL)) == NULL)
		return (-1);
	tputs(res, 0, putchar_ft);
	if (tcsetattr(0, TCSADRAIN, &termos) == -1)
		return (-1);
	while (1)
		;
	return (0);
}
