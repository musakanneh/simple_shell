#include "holberton.h"

/**
 * main - entry point for application
 * @ac: argument count
 * @av: argument vector
 * Return: 0 on success
 */
int main(int ac, char **av)
{
	config build;
	(void)ac;
	signal(SIGINT, handle_sigint);
	config_init(&build);
	build.shell_name = av[0];
	shell(&build);
	return (0);
}

/**
 * config_init - initialize member values for config struct
 * @build: input build
 *
 * Description: Accepts structured input commnad, and finds the right
 * configuration to execute from the built-in configurations.
 * Return: build with initialized members
 */
config *config_init(config *build)
{
	build->env = generateLinkedList(environ);
	build->env_list = NULL;
	build->args = NULL;
	build->buffer = NULL;
	build->path = _getenv("PATH", environ);
	build->full_path = NULL;
	build->count_line = 0;
	build->shell_name = NULL;
	build->error_status = 0;
	return (build);
}
