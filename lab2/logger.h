#ifndef LOGGER_H_
#define LOGGER_H_

#define LOG_LEVEL_INFO    0
#define LOG_LEVEL_DEBUG   1
#define LOG_LEVEL_TRACE   2
#define LOG_LEVEL_SILENT -1

#define LOG_MESSAGE_LEN 1024
#define DEFAULT_LOG_FILE "default.log"

void init_logger(char* log_file, int _logging_level);

void log_info (char*, ...);
void log_debug(char*, ...);
void log_trace(char*, ...);

#endif
