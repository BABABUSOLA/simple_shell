#include "main_shell.h"

/**
 * process_input - process input
 * @info: the parameter & return info struct
 * @av: the argument vector from main()
 *
 * Return: 0 on success, 1 on error, or error code
 */

void process_input(info_t *info, char **av)
{
	ssize_t r;
	int builtin_ret = 0;

	do {
		clear_info(info);
		if (interact(info))
		{
			_eputs("$ ");
		}
		_eputchar(BUF_FLUSH);
		r = get_input(info);
		if (r != -1)
		{
			set_info(info, av);
			builtin_ret = find_builtin_command(info);
			if (builtin_ret == -1)
			{
				find_cmd(info);
			}
		}
		else if (interact(info))
		{
			_eputchar('\n');
		}
		free_info(info, 0);
	} while (r != -1 && builtin_ret != -2);
}


/**
 * handle_exit_conditions - handle the exit condition
 * @info: the parameter & return info struct
 * @builtin_ret: the exit status
 * Return: 0 on success, 1 on error, or error code
 */
void handle_exit_conditions(info_t *info, int builtin_ret)
{
	write_history(info);
	free_info(info, 1);

	if (!interact(info) && info->status)
	{
		exit(info->status);
	}

	if (builtin_ret == -2)
	{
		if (info->err_num == -1)
		{
			exit(info->status);
		}
		exit(info->err_num);
	}
}
