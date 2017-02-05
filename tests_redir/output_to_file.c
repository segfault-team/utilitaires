#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

# define OPENFLAGS (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)
# define SIMPLE_FLAGS (O_RDWR | O_CREAT | O_TRUNC)
# define DOUBLE_FLAGS (O_RDWR | O_CREAT | O_APPEND)

char	**ft_tabnew(size_t size);
char	*ft_strnew(size_t size);
size_t	ft_strlen(const char *s);

/*
**	CMD > filex
*/

int main(int ac, char **av, char **env)
{
	int		file_fd;
	int		ret;
	int		fd[2];
	pid_t	pid;
	char	*buf;
	char	*file = "42.txt";


	buf = ft_strnew(4096);
	pipe(fd);
	pid = fork();
	if (pid == 0)
	{
		file_fd = open(file, SIMPLE_FLAGS, OPENFLAGS);
		dup2(file_fd, STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		execve("/bin/ls", av, env);
	}
	return (0);
}
