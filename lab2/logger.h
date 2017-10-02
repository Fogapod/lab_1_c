#ifndef LOGGER_H_
#define LOGGER_H_

#define LOG_LEVEL_INFO        0
#define LOG_LEVEL_DEBUG       1
#define LOG_LEVEL_TRACE       2
#define LOG_LEVEL_SILENT     -1

#define MAX_LOG_MESSAGE_LEN   1024
#define MAX_LOG_NAME_LEN      128
#define DEFAULT_LOG_PATH      ""
#define DEFAULT_LOG_FILE      "%d_%H_%M_%S.log"

void init_logger(int _logging_level);

void log_info (char*, ...);
void log_debug(char*, ...);
void log_trace(char*, ...);

#endif
