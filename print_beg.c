#include <sys/ioctl.h>

# define RED "\033[31m"
# define WHITE "\033[;0m"
# define GREEN "\033[32m"
# define BLUE "\033[34m"
# define YELLOW "\033[33m"
# define ITALIC "\x1b[3m"


#define WIN_X wpos->x
#define WIN_Y wpos->y
typedef struct  s_pos
{
	int         x;
	int         y;
}               t_pos;

void	print_pos(char *str, t_pos *wpos)
{
	int				i;
    struct winsize	w;

	i = -1;
	ioctl(0, TIOCGWINSZ, &w);
	while (str[++i])
	{
		// check pour le ">=" our ">"
		if (WIN_X + 1 < w.ws_col)
			++WIN_X;
		else
		{
			WIN_X = 0;
			if (WIN_Y + 1 < w.ws_row)
				++WIN_Y;
		}
		if (str[i] == '\n')
		{
			WIN_X = 0;
			++WIN_Y;
		}
		ft_putchar(str[i]);
	}
}

static void	dsh_computer_ii(t_pos *wpos)
{
	print_pos("`..........YBRPFT?!::::::::::::::::::::::::;iof68bo.      WBBBBbo.\n", wpos);
	print_pos("  `..........:::::::::::::::::::::::;iof688888888888b.     `YBBBP^'\n", wpos);
	print_pos("    `........::::::::::::::::;iof688888888888888888888b.     `\n", wpos);
	print_pos("     `......:::::::::;iof688888888888888888888888888888b.\n", wpos);
	print_pos("       `....:::;iof688888888888888888888888888888888899fT!\n", wpos);
	print_pos("         `..::!8888888888888888888888888888888899fT|!^\"'\n", wpos);
	print_pos("           `' !!988888888888888888888888899fT|!^\"'\n", wpos);
	print_pos("             `!!8888888888888888899fT|!^\"'\n", wpos);
	print_pos("               `!988888888899fT|!^\"'\n", wpos);
	print_pos("                 `!9899fT|!^\"'\n", wpos);
	print_pos("                   `!^\"'\n\n", wpos);
}

void		dsh_computer(t_pos *wpos)
{
	print_pos("\n                      .,,uod8B8bou,,.\n", wpos);
	print_pos("             ..,uod8BBBBBBBBBBBBBBBBRPFT?l!i:.\n", wpos);
	print_pos("         ,=m8BBBBBBBBBBBBBBBRPFT?!||||||||||||||\n", wpos);
	print_pos("         !...:!TVBBBRPFT||||||||||!!^^\"\"'   ||||\n", wpos);
	print_pos("         !.......:!?|||||!!^^\"\"'            ||||\n", wpos);
	print_pos("         !.........||||                     ||||\n", wpos);
	ft_printf("         !.........||||     %s%s%s", GREEN, "## > ", ITALIC);
	ft_printf("%s%s%s        ||||\n", BLUE, "dsh", "\x1b[0m", WHITE);
	print_pos("         !.........||||                     ||||\n", wpos);
	print_pos("         !.........||||                     ||||\n", wpos);
	print_pos("         !.........||||                     ||||\n", wpos);
	print_pos("         !.........||||                     ||||\n", wpos);
	print_pos("         `.........||||                    ,||||\n", wpos);
	print_pos("          .;.......||||               _.-!!|||||\n", wpos);
	print_pos("   .,uodWBBBBb.....||||       _.-!!|||||||||!:'\n", wpos);
	print_pos("!YBBBBBBBBBBBBBBb..!|||:..-!!|||||||!iof68BBBBBb....\n", wpos);
	print_pos("!..YBBBBBBBBBBBBBBb!!||||||||!iof68BBBBBBRPFT?!::   `.\n", wpos);
	print_pos("!....YBBBBBBBBBBBBBBbaaitf68BBBBBBRPFT?!:::::::::     `.\n", wpos);
	print_pos("!......YBBBBBBBBBBBBBBBBBBBRPFT?!::::::;:!^\"`;:::       `.\n", wpos);
	print_pos("!........YBBBBBBBBBBRPFT?!::::::::::^''...::::::;         iBBbo.\n", wpos);
	dsh_computer_ii(wpos);
}
