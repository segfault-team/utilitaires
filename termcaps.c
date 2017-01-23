#include <stdlib.h>
#include <curses.h>
#include <term.h>
#include <unistd.h>
#include <stdio.h>

int	putchar_ft(int c)
{
	char	d;

	d = c;
	return (write(1, &d, 1));
}

int	get_touch(struct termios termos)
{
	char	buf[3];
	char	*res;

	return (0);
}

int main()
{
	char			*name_term;
	struct termios	termos;
	char			*res;
	char			buf[3];
	char			test;

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
	if (tcsetattr(0, TCSADRAIN, &termos) == -1)
		return (-1);
	while (1)
	{
		read(0, buf, 3);
		if (buf[0] >= 'a' && buf[0] <= 'z')
		{
			test = (char)buf[0];
			tputs(&test, 0, putchar_ft);
	//		printf("%c", (char)buf[0]);
		}
		if (buf[0] == 4)
			printf("^d\n");
		else if (buf[0] == 12)
		{
			res = tgetstr("le", NULL);
			tputs(res, 0, putchar_ft);
		}
		if (buf[0] == 27 && buf[1] == 91)
		{
			if (buf[2] == 65)
				printf("up arrow\n");
			if (buf[2] == 66)
				printf("down arrow\n");
			if (buf[2] == 67)
				printf("right arrow\n");
			if (buf[2] == 68)
			{
			//	printf("left arrow\n");
				res = tgetstr("le", NULL);
				tputs(res, 0, putchar_ft);
			}
		}
//		if (buf[0])
//			printf("%d | %d | %d\n", buf[0], buf[1], buf[2]);
		buf[0] = 0;
		buf[1] = 0;
		buf[2] = 0;
	}
	return (0);
}
