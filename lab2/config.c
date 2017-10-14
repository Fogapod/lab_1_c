#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "logger.h"
#include "config.h"

void read_config_line(char *line, FILE *f)
{
	int c, i;
	i = 0;

	while ( (c = fgetc(f)) != EOF && c != '\n')
	{
		if (c == ' ' || c == '\t') continue;

		line[i] = c;
		i++;
	}

	line[i] = '\0';
}

int get_config_integer_value(char *key, char *val, size_t val_len)
{
	// no negative numbers allowed
	int int_value = 0;
	int i;

	for (i = 0; i < val_len; i++)
	{
		if ( '0' <= val[i] && val[i] <= '9')
		{
			int_value *= 10;
			int_value += val[i] - '0';
		}
		else
		{
			printf("Error reading intager value of %s: %s!\n", key, val);
			exit(4);
		}
	}

	return int_value;
}

void parse_config_line(char *line, size_t line_len)
{
	char   key[CONFIG_LINE_BUFFER_SIZE / 2];
	char   val[CONFIG_LINE_BUFFER_SIZE / 2];
	int    i, j;

	for (i = 0; i < line_len; i++)
	{
		if (line[i] == CONFIG_DELIMITER) break;

		key[i] = line[i];
	}

	if (i == 0)
	{
		printf("Error! Empty key found\n");
		exit(4);
	}

	key[i] = '\0';
	i++;

	for (j = 0; i < line_len; j++)
	{
		val[j] = line[i];
		i++;
	}

	if (j == 0)
    {
        printf("Error! Empty value found\n");
		exit(4);
	}

	val[j] = '\0';

	if (strcmp(key, OPTION_LOGGING_LEVEL) == 0)
		config.logging_level = get_config_integer_value(key, val, strlen(val));

	else if (strcmp(key, OPTION_WORKING_PORT) == 0)
		config.working_port = get_config_integer_value(key, val, strlen(val));

	else if (strcmp(key, OPTION_PAGE_DEFAULT) == 0)
		strcpy(config.page_default, val);

	else if (strcmp(key, OPTION_PAGE_404) == 0)
		strcpy(config.page_404, val);

	else if (strcmp(key, OPTION_PAGE_405) == 0)
		strcpy(config.page_405, val);
	
	else
	{
		printf("Error! Unknown config key: %s\n", line);
		exit(4);
	}
}

void read_config(char *config_file)
{
	FILE *f;
	int   c;
	char  line[CONFIG_LINE_BUFFER_SIZE];

	config.logging_level        = DEFAULT_LOGGING_LEVEL;
	config.working_port         = DEFAULT_WORKING_PORT; 
	strcpy(config.page_default,   DEFAULT_PAGE_DEFAULT);
	strcpy(config.page_404,       DEFAULT_PAGE_404);
	strcpy(config.page_405,       DEFAULT_PAGE_405);

	if ((f = fopen(config_file, "r")) == NULL)
	{
		printf("Failed openning config file! (%s)\n", config_file);
		exit(4);
	}
	else
	{
		while ((c = fgetc(f)) != EOF )
		{
			if (c == '\n') continue;

			ungetc(c, f);

			read_config_line(line, f);
			parse_config_line(line, strlen(line));
		}

		fclose(f);
	}
}
