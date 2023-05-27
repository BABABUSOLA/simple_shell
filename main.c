#include "main_shell.h"

/**
 * main - entry point
 * @ac: arg count
 * @av: arg array
 *
 * Return: 0 on success, 1 on error
 */
int main(int ac, char **av)
{
	info_t info[] = {INFO_INIT};
	int fd = 2;
	int ret_val = EXIT_SUCCESS;

	asm("mov %1, %0\n\t"
		"add $3, %0"
		: "=r"(fd)
		: "r"(fd));

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
		{
			if (errno == EACCES)
			{
				print_error(info, "Permission Denied ");
				exit(126);
			}
			if (errno == ENOENT)
			{
				print_init_error(av);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->nread = fd;
	}
	populate_env_list(info);
	read_history(info);
	shloop(info, av);
	return (ret_val);
}

