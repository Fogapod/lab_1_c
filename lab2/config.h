#ifndef CONFIG_H_
#define CONFIG_H_

#define DEFAULT_CONFIG_FILE      "myhttpserver.conf"

#define DEFAULT_LOGGING_LEVEL    LOG_LEVEL_INFO  // logger.h
#define DEFAULT_WORKING_PORT     80
#define DEFAULT_PAGE_DEFAULT     "index.html"
#define DEFAULT_PAGE_404         "404.html"
#define DEFAULT_PAGE_405         "405.html"

#define OPTION_LOGGING_LEVEL     "logging_level"
#define OPTION_WORKING_PORT      "port"
#define OPTION_PAGE_DEFAULT      "default_page"
#define OPTION_PAGE_404          "page_404"
#define OPTION_PAGE_405          "page_405"

#define CONFIG_LINE_BUFFER_SIZE  1024
#define CONFIG_DELIMITER         '='

struct config_struct {
	int  logging_level;
	int  working_port;
	char page_default[256];
	char page_404[256];
	char page_405[256];
};

struct config_struct config;

void read_config(char* config_file);

#endif
