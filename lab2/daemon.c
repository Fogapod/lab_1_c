/* 
 * Exit codes:
 *   1 Unrecognized error
 *   2 Failed openning log file
 */


#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>

#include "logger.h"

int main(int argc, char* argv[])
{
	// TODO: get this values from config
	init_logger(DEFAULT_LOG_FILE, LOG_LEVEL_TRACE);

	pid_t pid = fork();

	if (pid == -1)
	{
		log_info("Failed starting daemon process");
		return 1;
	}
	else if (pid > 0)
	{

		log_debug("Daemon process started (%d)", pid);
		return 0;
	}

	umask(0);
	setsid();
	// chdir("/");
	close(STDIN_FILENO);
	// close(STDOUT_FILENO);
	close(STDERR_FILENO);

	log_info("Hello from Daemon!");
	sleep(3);
	log_debug("Daemon exiting");

	return 0;
}
