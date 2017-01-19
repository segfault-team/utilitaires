#include "42sh.h"

void	redirect(int src, int dest)
{
	int		ret;

	ret = 1;
	while (ret)
	{
		ret = read(src, &buf[++i], 1);
		write(dest, &buf[i], 1);
	}
}
