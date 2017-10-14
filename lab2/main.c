/*
 * Arguments:
 *   config path (optional)
 *
 * Exit codes:
 *   0 Success:
 *   1 Unrecognized error
 *   2 Failed openning log file
 *   3 Failed starting daemon
 *   4 Error reading config
 */

#include <unistd.h>

#include "logger.h"
#include "config.h"
#include "daemon.h"

int listen_requests(int working_port, char *page_404, char *page_405);

int main(int argc, char *argv[])
{
	int exit_status;

	read_config((argc == 2)? argv[1]: CONFIG_FILE);

	init_logger(config.logging_level);

	daemonize();

	exit_status = listen_requests(config.working_port, config.page_404, config.page_405);
	log_debug("Exiting with status %d", exit_status);

	return exit_status;
}

int listen_requests(int working_port, char *page_404, char *page_405)
{
	log_debug("Starting listening requests on port %d", working_port);
	while (1)
	{
		log_info("Working...");
		sleep(10);
		log_info("Looks like my work done...");
		break;
	}
	return 0;
}


