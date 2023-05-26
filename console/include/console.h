#ifndef CONSOLE_H
#define CONSOLE_H

/**
 * Writes in the console in ciano color
 * Use this method to write simple messages in
 * the screen
 */
void write_console(char *str, ...);

/**
 * Thorws an error writing in console a message
 * in red color
 * Use this method to throw errors
 */
void throw_error(char *str, ...);

/**
 * Writes in the console in yellow color
 * Use this method to write warnings to the user
 */
void callout(char *str, ...);

/**
 * Clears the screen
 */
void clear_screen();

#endif
