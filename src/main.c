#include "../includes/pipex.h"

int main(int argc, char **argv)
{
	int i;

	i = pipex(argc, argv);
	if (i != 0)
		Get_error(i);
	return (0);
}
