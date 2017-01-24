#include <stdlib.h>
#include <curses.h>
#include <term.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/ioctl.h>


typedef struct	s_env
{
	char		**cmd;
}				t_env;


#define WIN_X wpos->x
#define WIN_Y wpos->y
typedef struct	s_pos
{
	int			x;
	int			y;
}				t_pos;


int		term_history(int up, t_pos *wpos);
void	print_pos(char *str, t_pos *wpos);
void	dsh_computer(t_pos *pos);


int	putchar_ft(int c)
{
	char	d;
	static int i = 0;

	++i;
	d = c;
	if (i % 2 && (c >= 'a' && c <= 'z'))
		return (write(1, &d, 1));
	else if (c >= 'a' && c <= 'z')
	{
		i = 0;
		return (i);
	}
	else
		return (write(1, &d, 1));
}


int	get_touch(struct termios termos)
{
	char	buf[3];
	char	*res;

	return (0);
}


int	check_key(char buf[3], int a, int b, int c)
{
	if (buf[0] == (char)a && buf[1] == (char)b && buf[2] == (char)c)
		return (1);
	return (0);
}


int main()
{
	char			*name_term;
	struct termios	termos;
	char			*res;
	char			*id;
	char			buf[3];
	char			test;
	int				up = 0;
	char			**test_2;
	t_pos			wpos;

	if ((name_term = getenv("TERM")) == NULL)
		return (-1);
	if (tgetent(NULL, name_term) == ERR)
		return (-1);
	if (tcgetattr(0, &termos) == -1)
		return (-1);
	//	tputs(tgetstr("cl", NULL), 0, putchar_ft);
	//	tputs(tgoto(tgetstr("cm", NULL), 0, 0), 1, putchar_ft);
	termos.c_lflag &= ~(ICANON);
	termos.c_lflag &= ~(ECHO);
	termos.c_cc[VMIN] = 1;
	termos.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &termos) == -1)
		return (-1);



//	REPLACE CUROS A THE BEGING OF THE WIN {0:0}
	res = tgetstr("cl", NULL);
	tputs(res, 1, putchar_ft);
	res = tgetstr("cm", NULL);
	tputs(tgoto(res, 0, 0), 1, putchar_ft);
	res = tgetstr("se", NULL);
	tputs(res, 1, putchar_ft);
	wpos.x = 0;
	wpos.y = 1;
	dsh_computer(&wpos);
	print_pos("#> ", &wpos);
	res = tgetstr("cm", NULL);
	tputs(tgoto(res, wpos.x, wpos.y), 1, putchar_ft);

	while (1)
	{
		while (read(0, buf, 3))
		{
			up = (check_key(buf, 27, 91, 65)) ? up + 1: 0;
			if ((buf[0] >= 'a' && buf[0] <= 'z') || (buf[0] >= 'A' && buf[0] <= 'Z'))
			{
				test = buf[0];
				tputs(&test, 1, putchar_ft);
			}
			else if (buf[0] == 4)
				printf("^d\n");
			else if (buf[0] == 10)
			{
				res = tgetstr("cm", NULL);
				++wpos.y;
				tputs(tgoto(res, 0, wpos.y), 1, putchar_ft);
				wpos.x = 3;
				print_pos("#> ", &wpos);
			}
			else if (buf[0] == 1)
			{
				// retour au debut de ligne
				res = tgetstr("cr", NULL);
				tputs(res, 1, putchar_ft);
			}
			else if (check_key(buf, 12, 0, 0))
			{
				res = tgetstr("cl", NULL);
				tputs(res, 1, putchar_ft);
			}
			else if (check_key(buf, 27, 91, 65))
			{
				//cr: return at the begining of the line
				//cd: clear the line
			res = tgetstr("cr", NULL);
				id = tgetstr("cd", NULL);
				tputs(res, 1, putchar_ft);
				tputs(id, 1, putchar_ft);
				res = tgetstr("cm", NULL);
				print_pos("#> ", &wpos);
				tputs(tgoto(res, 3, wpos.y), 1, putchar_ft);
				term_history(up, &wpos);
			}
			else if (check_key(buf, 27, 91, 66))
				printf("down arrow\n");
			else if (check_key(buf, 27, 91, 67))
			{
				res = tgetstr("nd", NULL);
				tputs(res, 1, putchar_ft);
			}
			else if (check_key(buf, 27, 91, 68) && wpos.x >= 4)
			{
				--wpos.x;
				res = tgetstr("le", NULL);
				tputs(res, 1, putchar_ft);
			}
//			else if (buf[0])
//				printf("\n%d | %d | %d\n", buf[0], buf[1], buf[2]);
			buf[0] = 0;
			buf[1] = 0;
			buf[2] = 0;
		}
	}
	return (0);
}
