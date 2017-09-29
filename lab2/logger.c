#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "logger.h"

// TODO: control log len

int logging_level = LOG_LEVEL_INFO;
char* log_file_path = DEFAULT_LOG_FILE;

void write_log(char message[], char prefix[])
{
	char tm[9];
	char buf[LOG_MESSAGE_LEN];
	time_t now = time(NULL);
	FILE *f = fopen(log_file_path, "a");

	if (f == NULL) exit(2);

	strftime(tm, sizeof(tm), "%H:%M:%S", localtime(&now));

	sprintf(buf, "%s[%s]%s\n", prefix, tm,  message);

	printf("\r%s", buf);
	fprintf(f, "%s",  buf);

	fclose(f);
}

void log_info(char message[], ...)
{
	if (logging_level < LOG_LEVEL_INFO) return;
	// TODO: remove same code
	va_list args;
	char buf[LOG_MESSAGE_LEN];

	va_start(args, message);
	vsnprintf(buf, LOG_MESSAGE_LEN, message, args);
	va_end(args);
	// TODO: remove same code

	write_log(buf, "[ INFO]");
}

void log_debug(char message[], ...)
{
	if (logging_level < LOG_LEVEL_DEBUG) return;
	// TODO: remove same code
	va_list args;
    char buf[LOG_MESSAGE_LEN];

    va_start(args, message);
    vsnprintf(buf, LOG_MESSAGE_LEN, message, args);
    va_end(args);
	// TODO: remove same code

    write_log(buf, "[DEBUG]");
}

void log_trace(char message[], ...)
{
	if (logging_level < LOG_LEVEL_TRACE) return;
	// TODO: remove same code
	va_list args;
    char buf[LOG_MESSAGE_LEN];

    va_start(args, message);
    vsnprintf(buf, LOG_MESSAGE_LEN, message, args);
    va_end(args);
	// TODO: remove same code

    write_log(buf, "[TRACE]");
}

void init_logger(char log_file[], int _logging_level)
{
	// TODO: new log each run
	// TODO: limit number of logs
	FILE *f = fopen(log_file, "w");
	if (f == NULL) exit(2);
	fclose(f);

	log_file_path = log_file;

    if (_logging_level < LOG_LEVEL_SILENT || _logging_level > LOG_LEVEL_TRACE)
		log_info("Wrong log level received (%d) Using default: %d", _logging_level, logging_level);
	else
	{
		logging_level = _logging_level;
		log_trace("Set logging level to %d", logging_level);
	}
	log_debug("Using file %s for log output", log_file);
}
