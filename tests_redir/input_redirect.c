#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

# define OPENFLAGS (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)

char	**ft_tabnew(size_t size);
char	*ft_strnew(size_t size);
size_t	ft_strlen(const char *s);

/*
**	CMD < filex
*/

int main(int ac, char **av, char **env)
{
	int		file_fd;
	int		ret;
	int		fd[2];
	pid_t	pid;
	char	**tsort;
	char	*buf;
	char	*file = "42.txt";


	buf = ft_strnew(4096);
	tsort = ft_tabnew(3);
	tsort[0] = strdup("sort");
	tsort[1] = strdup("-r");
	tsort[2] = NULL;
	pipe(fd);
	pid = fork();
	if (pid == 0)
	{
		file_fd = open(file, O_RDWR | O_CREAT, OPENFLAGS);
		dup2(fd[1], STDOUT_FILENO);
		while ((ret = read(file_fd, buf, 4096)))
		{
			buf[ret] = '\0';
			write(fd[1], buf, ft_strlen(buf));
		}
		close(fd[0]);
		close(fd[1]);
		exit(0);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		execve("/usr/bin/sort", tsort, env);
	}
	return (0);
}
