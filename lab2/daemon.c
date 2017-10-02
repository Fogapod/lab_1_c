#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

#include "logger.h"
#include "daemon.h"

void daemonize(void){
	pid_t pid = fork();

	if (pid == -1)
    {
        log_info("Failed starting daemon process");
        exit(3);
    }
    else if (pid > 0)
	{
		log_debug("Daemon process started (%d)", pid);
		exit(0);
	}

	umask(0);
	setsid();
	// chdir("/");
	close(STDIN_FILENO);
	// close(STDOUT_FILENO);
	close(STDERR_FILENO);
}
