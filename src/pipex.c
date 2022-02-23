#include "../includes/pipex.h"

int pipex(int argc, char **argv)
{
	s_list s;
	
	if (argc != 4)
		return (1);
	malloc_file(argc, argv, &s);
	printf("%s\n", s.stock2);
	return (0);
}