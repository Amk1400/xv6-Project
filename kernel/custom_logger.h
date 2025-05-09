#ifndef __LOGGER_CUSTOM_H__
#define __LOGGER_CUSTOM_H__

#include "types.h"

// Define log levels
#define LOG_LEVEL_INFO 1
#define LOG_LEVEL_WARN 2
#define LOG_LEVEL_ERROR 3

// Function prototype for logging messages
void log_message(int level, const char *message);

#endif