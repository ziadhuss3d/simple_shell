#include "main.h"
/**
 * command_exists - A function checks if command exists befor forking,
 * @args: Argument array.
 *
 *
 * Return: 0 if command does not exists in PATH, 1 otherwise
 */

int command_exists(char **args)
{
	char *path, *dir;
	char path_search[4096];
	char command_path[4096];

	if (args[0][0] == '/' || args[0][0] == ',')
	{
		return (access(args[0], X_OK) == 0);
	}
	else
	{
		path = getenv("PATH");
		if (path == NULL)
		{
			write(2, "PATH VARIABLE NOT FOUND. \n", 25);
			exit(EXIT_FAILURE);
		}

		sprintf(path_search, "%s:/user/bin", path);

		dir = strtok(path_search, ":");
		while (dir)
		{
			snprintf(command_path, sizeof(command_path), "%s/%s", dir, args[0]);
			if (access(command_path, X_OK) == 0)
			{
				return (1);
			}
			dir = strtok(NULL, ":");
		}
	}
	return (0);
}
