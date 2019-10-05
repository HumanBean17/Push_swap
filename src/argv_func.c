#include "push_swap.h"

int 	ArgvLen(char **argv)
{
	int len;

	len = 0;
	while (argv[len])
		len++;
	return (len);
}

void	ArgvDel(char **argv)
{
	int i;

	i = 0;
	while (argv[i])
	{
		ft_strdel(&argv[i]);
		i++;
	}
	free(argv);
}

char **AddFilename(char *filename, char **argv)
{
	char	 **newArgv;
	int 	i;
	int 	c;
	int 	len;

	i = g_printshift;
	c = 0;
	len = ArgvLen(argv);
	newArgv = (char **)ft_memalloc(sizeof(char *) * (len + 3));
	newArgv[0] = ft_strdup(filename);
	newArgv[1] = i == 2 ? ft_strdup("-c") : NULL;
	while (c < len)
	{
		newArgv[i] = ft_strdup(argv[c]);
		i++;
		c++;
	}
	ArgvDel(argv);
	return (newArgv);
}

char **ArgvSplit(int *argc, char **argv)
{
	char **newArgv;
	char **argvWithFilename;

	if ((*argc) < 4)
	{
		newArgv = ft_strsplit(argv[g_printshift], ' ');
		if (!newArgv[0])
			print_exit(69);
		argvWithFilename = AddFilename(argv[0], newArgv);
		(*argc) = ArgvLen(argvWithFilename);
		return (argvWithFilename);
	}
	return (argv);
}
