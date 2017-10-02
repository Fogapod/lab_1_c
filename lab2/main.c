/*
 * Exit codes:
 *   0 Success:
 *   1 Unrecognized error
 *   2 Failed openning log file
 *   3 Failed starting daemon
 */

#include <unistd.h>

#include "logger.h"
#include "daemon.h"

int main(int argc, char* argv[])
{
	// TODO: get this values from config
    init_logger(LOG_LEVEL_TRACE);

	daemonize();

	log_info("Hello from Daemon!");
	sleep(3);
    log_debug("Daemon exiting");

	return 0;
}
