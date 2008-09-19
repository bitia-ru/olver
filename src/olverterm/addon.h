#ifndef __ADDON_H__
#define __ADDON_H__

#include _CURSES_HEADER

/* Write a message to:
    specified file. (When PROG_DUMPFILE_ENV is defined.)
    stdout.     (When PROG_DUMPFILE_ENV is not defined.) */
void Message (int type, char *format, ...);

/* Start a session with terminal emulator */
int Make_Session (void);

/* Request terminal emulator to dump the displayed contents. */
void Dump_Contents (int scol, int srow, int ecol, int erow);

/* Request terminal emulator to dump the displayed contents. */
void Input_String (char *request, size_t request_len);

/* Convert a wide character string to a complex character string. */
//int Wcs_to_Ccs (cchar_t *ccs, wchar_t *wcs, int wcs_len);

/* Make a file descriptor of socket. */
int sock_client (char *messege, size_t message_len);
#endif
