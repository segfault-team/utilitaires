#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int		main(void)
{
	int		ret;
	int		i;
	char	buf[2048];

	ret = 0;
	i = -1;
	while ((ret = read(0, &buf[++i], 1)))
		printf("%c\n", buf[i]);
	return (0);
}
