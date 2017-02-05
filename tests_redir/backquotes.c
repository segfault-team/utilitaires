#include "shell.h"

static int		get_size(char *str)
{
	int		i;

	i = 0;
	while (str[i] && ft_isalpha(str[i]))
		i++;
	return (i);
}

static char	*remove_parenthesis(char *str)
{
	char	*ret;

	if (str)
		free(str);
	ret = ft_strdup(str, 1, ft_strlen(str) - 2);
	return (ret);
}

char	*backquotes(t_env *e, char *str)
{
	char	*ret;
	char	*var_raw;
	char 	*var;
	char	*tmp;
	int		i;
	int		j;

	ret = NULL;
	var = NULL;
//	var_raw = NULL;
//	tmp = NULL;
	i = -1;
	j = -1;
	while (str[++i])
	{
		if (str[i] != '$')
			ret[++j] = str[i]
		tmp = NULL;
		var_raw = NULL;
		if (str[i] == '$')
		{
i//			ret = (!str[i - 1] ? NULL : ft_strdup(str, 0, i - 1));
			var_raw = ft_strdup(str, (i + 1), get_size(&str[i]));
			var_raw = remove_parenthesis(var_raw);
			var = ft_getenv(e->env, var_raw);
			free(var_raw);
			if (var)
				tmp = ft_strjoin(ret, var);
			free(ret);
			ret = tmp;
			i += get_size(&str[i]);
			j = ft_strlen(ret);
		}
	}
}
