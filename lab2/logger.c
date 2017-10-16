#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "logger.h"

// TODO: control log len

int  logging_level;
char log_file[256];

void write_log(char message[], char prefix[])
{
	time_t  now = time(NULL);
	char    tm[9];
	char    buf[MAX_LOG_MESSAGE_LEN];
	FILE   *f;

	if ((f = fopen(log_file, "a")) == NULL) exit(2);

	strftime(tm, sizeof(tm), "%H:%M:%S", localtime(&now));
	sprintf(buf, "%s[%s]%s\n", prefix, tm,  message);

	printf("\r%s", buf);
	fflush(stdout);

	fprintf(f, "%s",  buf);
	fflush(f);

	fclose(f);
}

void log_info(char message[], ...)
{
	if (logging_level < LOG_LEVEL_INFO) return;
	// TODO: remove same code
	va_list args;
	char buf[MAX_LOG_MESSAGE_LEN];

	va_start(args, message);
	vsnprintf(buf, MAX_LOG_MESSAGE_LEN, message, args);
	va_end(args);
	// TODO: remove same code

	write_log(buf, "[INFO ]");
}

void log_debug(char message[], ...)
{
	if (logging_level < LOG_LEVEL_DEBUG) return;
	// TODO: remove same code
	va_list args;
	char buf[MAX_LOG_MESSAGE_LEN];

	va_start(args, message);
	vsnprintf(buf, MAX_LOG_MESSAGE_LEN, message, args);
	va_end(args);
	// TODO: remove same code

	write_log(buf, "[DEBUG]");
}

void log_trace(char message[], ...)
{
	if (logging_level < LOG_LEVEL_TRACE) return;
	// TODO: remove same code
	va_list args;
	char buf[MAX_LOG_MESSAGE_LEN];

	va_start(args, message);
	vsnprintf(buf, MAX_LOG_MESSAGE_LEN, message, args);
	va_end(args);
	// TODO: remove same code

    write_log(buf, "[TRACE]");
}

void init_logger(int _logging_level)
{
	time_t  now = time(NULL);
	FILE   *f;

	strcpy(log_file, LOG_FILE_NAME);

	strftime(log_file, sizeof(log_file), LOG_FILE_NAME, localtime(&now));

	// TODO: limit number of log files
	if ((f = fopen(log_file, "w")) == NULL) exit(2);
	fclose(f);

	if (_logging_level < LOG_LEVEL_SILENT || _logging_level > LOG_LEVEL_TRACE)
		log_info("Wrong log level received (%d) Using default: %d", _logging_level, logging_level);
	else
	{
		logging_level = _logging_level;
		log_trace("Set logging level to %d", logging_level);
	}
	log_debug("Using file %s for log output", log_file);
}
