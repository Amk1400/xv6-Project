#include "types.h"
#include "riscv.h"
#include "defs.h"
#include "custom_logger.h"

void log_message(int level, const char *message) {
  switch (level) {
    case LOG_LEVEL_INFO:
      printf("INFO: %s\n", message);
      break;
    case LOG_LEVEL_WARN:
      printf("WARNING: %s\n", message);
      break;
    case LOG_LEVEL_ERROR:
      printf("ERROR: %s\n", message);
      break;
    default:
      printf("UNKNOWN LEVEL: %s\n", message);
      break;
  }
}