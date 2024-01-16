/**
 * \file utils.h
 * \brief Header file containing functions for I/O operations.
 */

#ifndef UTILS_H
#define UTILS_H

#include <stdbool.h>
#include <stdarg.h>

/**
 * \brief Prints a formatted string to the standard output followed by a newline.
 *
 * This function prints a formatted string to the standard output followed by a newline character.
 *
 * \param fmt The format string, similar to printf.
 * \param ... Additional arguments to be formatted.
 */
void println(const char *fmt, ...);

/**
 * \brief Reads a line from the standard input and returns it as a dynamically allocated string.
 *
 * This function reads a line from the standard input and returns it as a dynamically allocated string.
 * The caller is responsible for freeing the allocated memory.
 *
 * \return A pointer to the dynamically allocated string containing the input line.
 */
char *getln();

/**
 * \brief Converts a string to a double value.
 *
 * This function converts a string to a double value according to specified formatting rules.
 *
 * \param string The input string to be converted to a double.
 * \param ... Optional arguments that specify formatting rules.
 *            If the first optional argument is true then also parse comma as a decimal separator.
 * \return The double value parsed from the input string.
 */
double toDouble(const char* string, ...);

/**
 * \brief Retrieves a double value from user input.
 *
 * This function retrieves a double value from user input.
 *
 * \return The double value entered by the user.
 */
double getDouble();

#endif // UTILS_H
