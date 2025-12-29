#include "shell.h"

/**
 * get_path_env - Gets the PATH environment variable
 *
 * Return: Pointer to the PATH value, or NULL if not found
 */
static char *get_path_env(void)
{
	int i = 0;

	while (environ[i])
	{
		if (strncmp(environ[i], "PATH=", 5) == 0)
			return (environ[i] + 5);
		i++;
	}
	return (NULL);
}

/**
 * check_file_exists - Checks if a file exists and is executable
 * @filepath: The path to the file
 *
 * Return: 1 if file exists and is executable, 0 otherwise
 */
static int check_file_exists(char *filepath)
{
	if (access(filepath, F_OK | X_OK) == 0)
		return (1);
	return (0);
}

/**
 * build_full_path - Builds a full path from directory and command
 * @dir: The directory path
 * @command: The command name
 *
 * Return: Newly allocated string with full path, or NULL on failure
 */
static char *build_full_path(char *dir, char *command)
{
	char *full_path;
	size_t dir_len, cmd_len;

	dir_len = strlen(dir);
	cmd_len = strlen(command);
	full_path = malloc(dir_len + cmd_len + 2);
	if (!full_path)
		return (NULL);

	strcpy(full_path, dir);
	full_path[dir_len] = '/';
	strcpy(full_path + dir_len + 1, command);

	return (full_path);
}

/**
 * find_path - Finds the full path of a command
 * @command: The command to find
 *
 * Description: Searches for a command in the PATH directories.
 * If the command contains a slash, it's treated as a path.
 *
 * Return: Full path to command (must be freed), or NULL if not found
 */
char *find_path(char *command)
{
	char *path_env, *path_copy, *dir, *full_path;

	if (!command || !*command)
		return (NULL);

	if (strchr(command, '/'))
	{
		if (check_file_exists(command))
			return (strdup(command));
		return (NULL);
	}

	path_env = get_path_env();
	if (!path_env || !*path_env)
		return (NULL);

	path_copy = strdup(path_env);
	if (!path_copy)
		return (NULL);

	dir = strtok(path_copy, ":");
	while (dir)
	{
		full_path = build_full_path(dir, command);
		if (full_path && check_file_exists(full_path))
		{
			free(path_copy);
			return (full_path);
		}
		free(full_path);
		dir = strtok(NULL, ":");
	}

	free(path_copy);
	return (NULL);
}
