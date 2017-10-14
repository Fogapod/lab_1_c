#ifndef LOGGER_H_
#define LOGGER_H_

#define LOG_LEVEL_INFO       0
#define LOG_LEVEL_DEBUG      1
#define LOG_LEVEL_TRACE      2
#define LOG_LEVEL_SILENT    -1

#define LOG_FILE_NAME        "%d_%H_%M_%S.log"
#define MAX_LOG_MESSAGE_LEN  1024

void init_logger(int _logging_level);

void log_info (char *, ...);
void log_debug(char *, ...);
void log_trace(char *, ...);

#endif
