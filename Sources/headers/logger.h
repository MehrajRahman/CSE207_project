#ifndef LOGGER_H
#define LOGGER_H

#include <stdio.h>
#include <stdlib.h>
struct logger
{
    FILE *f_print;
    FILE *f_debug;
    FILE *f_error;
};

struct logger *init_logger(FILE *print_file, FILE *debug_file, FILE *error_file);
void log_print(const struct logger *l, const char *format, ...);
void log_debug(const struct logger *l, const char *format, ...);
void log_error(const struct logger *l, const char *format, ...);
void shutdown_logger(struct logger *l);

#endif