/*
 * Copyright (c) 2005-2006 Institute for System Programming
 * Russian Academy of Sciences
 * All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


#include "io/file/file_agent.h"
#include "io/term/term_agent.h"

#include <errno.h>
#include <fcntl.h>
#include <pty.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <utmp.h>

/********************************************************************/
/**                         Read Functions                         **/
/********************************************************************/
int readWinSize(TAInputStream *stream, struct winsize *winp)
{
    if(startsWith_TAInputStream(stream, "null:"))
    {
        verifyType_TAInputStream(stream, "null");
        return 0;
    }

    verifyType_TAInputStream(stream, "winsize");

    winp->ws_row = readUShort(stream);
    winp->ws_col = readUShort(stream);
    winp->ws_xpixel = readUShort(stream);
    winp->ws_ypixel = readUShort(stream);
    return 1;
}

/********************************************************************/
/**                        Helper Functions                        **/
/********************************************************************/

static speed_t getSUTSpeed(speed_t modelSpeed)
{
    if(modelSpeed == 0)     return B0;
    if(modelSpeed == 50)    return B50;
    if(modelSpeed == 75)    return B75;
    if(modelSpeed == 110)   return B110;
    if(modelSpeed == 134)   return B134;
    if(modelSpeed == 150)   return B150;
    if(modelSpeed == 200)   return B200;
    if(modelSpeed == 300)   return B300;
    if(modelSpeed == 600)   return B600;
    if(modelSpeed == 1200)  return B1200;
    if(modelSpeed == 1800)  return B1800;
    if(modelSpeed == 2400)  return B2400;
    if(modelSpeed == 4800)  return B4800;
    if(modelSpeed == 9600)  return B9600;
    if(modelSpeed == 19200) return B19200;
    if(modelSpeed == 38400) return B38400;

    return modelSpeed;
}

static speed_t getModelSpeed(speed_t sutSpeed)
{
    if(sutSpeed == B0)     return 0;
    if(sutSpeed == B50)    return 50;
    if(sutSpeed == B75)    return 75;
    if(sutSpeed == B110)   return 110;
    if(sutSpeed == B134)   return 134;
    if(sutSpeed == B150)   return 150;
    if(sutSpeed == B200)   return 200;
    if(sutSpeed == B300)   return 300;
    if(sutSpeed == B600)   return 600;
    if(sutSpeed == B1200)  return 1200;
    if(sutSpeed == B1800)  return 1800;
    if(sutSpeed == B2400)  return 2400;
    if(sutSpeed == B4800)  return 4800;
    if(sutSpeed == B9600)  return 9600;
    if(sutSpeed == B19200) return 19200;
    if(sutSpeed == B38400) return 38400;

    return sutSpeed;
}

/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict gettermios_cmd(TAThread thread, TAInputStream stream)
{
    struct termios* termios_p;

    // Prepare
    termios_p = readPointer(&stream);

    START_TARGET_OPERATION(thread);
    END_TARGET_OPERATION(thread);

    writeUInt(thread, getModelSpeed(termios_p->c_ispeed));
    writeUInt(thread, getModelSpeed(termios_p->c_ospeed));

    // iflag
    writeChar(thread, termios_p->c_iflag & BRKINT ? '\xFF' : '\x00');
    writeChar(thread, termios_p->c_iflag & ICRNL  ? '\xFF' : '\x00');
    writeChar(thread, termios_p->c_iflag & IGNBRK ? '\xFF' : '\x00');
    writeChar(thread, termios_p->c_iflag & IGNCR  ? '\xFF' : '\x00');
    writeChar(thread, termios_p->c_iflag & IGNPAR ? '\xFF' : '\x00');
    writeChar(thread, termios_p->c_iflag & INLCR  ? '\xFF' : '\x00');
    writeChar(thread, termios_p->c_iflag & INPCK  ? '\xFF' : '\x00');
    writeChar(thread, termios_p->c_iflag & ISTRIP ? '\xFF' : '\x00');
    writeChar(thread, termios_p->c_iflag & IXANY  ? '\xFF' : '\x00');
    writeChar(thread, termios_p->c_iflag & IXOFF  ? '\xFF' : '\x00');
    writeChar(thread, termios_p->c_iflag & IXON   ? '\xFF' : '\x00');
    writeChar(thread, termios_p->c_iflag & PARMRK ? '\xFF' : '\x00');

    // oflag
    writeChar(thread, termios_p->c_oflag & OPOST  ? '\xFF' : '\x00');
    writeChar(thread, termios_p->c_oflag & ONLCR  ? '\xFF' : '\x00');
    writeChar(thread, termios_p->c_oflag & OCRNL  ? '\xFF' : '\x00');
    writeChar(thread, termios_p->c_oflag & ONOCR  ? '\xFF' : '\x00');
    writeChar(thread, termios_p->c_oflag & ONLRET ? '\xFF' : '\x00');
    writeChar(thread, termios_p->c_oflag & OFILL  ? '\xFF' : '\x00');
    writeChar(thread, termios_p->c_oflag & OFDEL  ? '\xFF' : '\x00');

    if((termios_p->c_oflag & NLDLY) == NL0)
        writeInt(thread, 0);
    else if((termios_p->c_oflag & NLDLY) ==  NL1)
        writeInt(thread, 1);
    else
        writeInt(thread, -1);

    if((termios_p->c_oflag & CRDLY) == CR0)
        writeInt(thread, 0);
    else if((termios_p->c_oflag & CRDLY) == CR1)
        writeInt(thread, 1);
    else if((termios_p->c_oflag & CRDLY) == CR2)
        writeInt(thread, 2);
    else if((termios_p->c_oflag & CRDLY) == CR3)
        writeInt(thread, 3);
    else
        writeInt(thread, -1);

    if((termios_p->c_oflag & TABDLY) == TAB0)
        writeInt(thread, 0);
    else if((termios_p->c_oflag & TABDLY) == TAB1)
        writeInt(thread, 1);
    else if((termios_p->c_oflag & TABDLY) == TAB2)
        writeInt(thread, 2);
    else if((termios_p->c_oflag & TABDLY) == TAB3)
        writeInt(thread, 3);
    else
        writeInt(thread, -1);

    if((termios_p->c_oflag & BSDLY) == BS0)
        writeInt(thread, 0);
    else if((termios_p->c_oflag & BSDLY) == BS1)
        writeInt(thread, 1);
    else
        writeInt(thread, -1);

    if((termios_p->c_oflag & VTDLY) == VT0)
        writeInt(thread, 0);
    else if((termios_p->c_oflag & VTDLY) == VT1)
        writeInt(thread, 1);
    else
        writeInt(thread, -1);

    if((termios_p->c_oflag & FFDLY) == FF0)
        writeInt(thread, 0);
    else if((termios_p->c_oflag & FFDLY) == FF1)
        writeInt(thread, 1);
    else
        writeInt(thread, -1);

    // cflag
    if((termios_p->c_cflag & CSIZE) == CS5)
        writeInt(thread, 5);
    else if((termios_p->c_cflag & CSIZE) == CS6)
        writeInt(thread, 6);
    else if((termios_p->c_cflag & CSIZE) == CS7)
        writeInt(thread, 7);
    else if((termios_p->c_cflag & CSIZE) == CS8)
        writeInt(thread, 8);
    else
        writeInt(thread, -1);

    writeChar(thread, termios_p->c_cflag & CSTOPB ? '\xFF' : '\x00');
    writeChar(thread, termios_p->c_cflag & CREAD  ? '\xFF' : '\x00');
    writeChar(thread, termios_p->c_cflag & PARENB ? '\xFF' : '\x00');
    writeChar(thread, termios_p->c_cflag & PARODD ? '\xFF' : '\x00');
    writeChar(thread, termios_p->c_cflag & HUPCL  ? '\xFF' : '\x00');
    writeChar(thread, termios_p->c_cflag & CLOCAL ? '\xFF' : '\x00');

    // lflag
    writeChar(thread, termios_p->c_lflag & ECHO   ? '\xFF' : '\x00');
    writeChar(thread, termios_p->c_lflag & ECHOE  ? '\xFF' : '\x00');
    writeChar(thread, termios_p->c_lflag & ECHOK  ? '\xFF' : '\x00');
    writeChar(thread, termios_p->c_lflag & ECHONL ? '\xFF' : '\x00');
    writeChar(thread, termios_p->c_lflag & ICANON ? '\xFF' : '\x00');
    writeChar(thread, termios_p->c_lflag & IEXTEN ? '\xFF' : '\x00');
    writeChar(thread, termios_p->c_lflag & ISIG   ? '\xFF' : '\x00');
    writeChar(thread, termios_p->c_lflag & NOFLSH ? '\xFF' : '\x00');
    writeChar(thread, termios_p->c_lflag & TOSTOP ? '\xFF' : '\x00');

    // cc
    writeUChar(thread, termios_p->c_cc[VEOF]);
    writeUChar(thread, termios_p->c_cc[VEOL]);
    writeUChar(thread, termios_p->c_cc[VERASE]);
    writeUChar(thread, termios_p->c_cc[VINTR]);
    writeUChar(thread, termios_p->c_cc[VKILL]);
    writeUChar(thread, termios_p->c_cc[VMIN]);
    writeUChar(thread, termios_p->c_cc[VQUIT]);
    writeUChar(thread, termios_p->c_cc[VSUSP]);
    writeUChar(thread, termios_p->c_cc[VTIME]);
    writeUChar(thread, termios_p->c_cc[VSTART]);
    writeUChar(thread, termios_p->c_cc[VSTOP]);

    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict settermios_cmd(TAThread thread, TAInputStream stream)
{
    struct termios *termios_p;

    // Prepare
    termios_p = readPointer(&stream);

    START_TARGET_OPERATION(thread);

    verifyType_TAInputStream(&stream, "termios");

    // ispeed
    termios_p->c_ispeed = getSUTSpeed(readUInt(&stream));

    // ospeed
    termios_p->c_ospeed = getSUTSpeed(readUInt(&stream));

    // iflag
    termios_p->c_iflag = readChar(&stream) != '\x00' ?
        termios_p->c_iflag | BRKINT : termios_p->c_iflag & ~BRKINT;
    termios_p->c_iflag = readChar(&stream) != '\x00' ?
        termios_p->c_iflag | ICRNL  : termios_p->c_iflag & ~ICRNL;
    termios_p->c_iflag = readChar(&stream) != '\x00' ?
        termios_p->c_iflag | IGNBRK : termios_p->c_iflag & ~IGNBRK;
    termios_p->c_iflag = readChar(&stream) != '\x00' ?
        termios_p->c_iflag | IGNCR  : termios_p->c_iflag & ~IGNCR;
    termios_p->c_iflag = readChar(&stream) != '\x00' ?
        termios_p->c_iflag | IGNPAR : termios_p->c_iflag & ~IGNPAR;
    termios_p->c_iflag = readChar(&stream) != '\x00' ?
        termios_p->c_iflag | INLCR  : termios_p->c_iflag & ~INLCR;
    termios_p->c_iflag = readChar(&stream) != '\x00' ?
        termios_p->c_iflag | INPCK  : termios_p->c_iflag & ~INPCK;
    termios_p->c_iflag = readChar(&stream) != '\x00' ?
        termios_p->c_iflag | ISTRIP : termios_p->c_iflag & ~ISTRIP;
    termios_p->c_iflag = readChar(&stream) != '\x00' ?
        termios_p->c_iflag | IXANY  : termios_p->c_iflag & ~IXANY;
    termios_p->c_iflag = readChar(&stream) != '\x00' ?
        termios_p->c_iflag | IXOFF  : termios_p->c_iflag & ~IXOFF;
    termios_p->c_iflag = readChar(&stream) != '\x00' ?
        termios_p->c_iflag | IXON   : termios_p->c_iflag & ~IXON;
    termios_p->c_iflag = readChar(&stream) != '\x00' ?
        termios_p->c_iflag | PARMRK : termios_p->c_iflag & ~PARMRK;

    // oflag
    termios_p->c_oflag = readChar(&stream) != '\x00' ?
        termios_p->c_oflag | OPOST  : termios_p->c_oflag & ~OPOST;
    termios_p->c_oflag = readChar(&stream) != '\x00' ?
        termios_p->c_oflag | ONLCR  : termios_p->c_oflag & ~ONLCR;
    termios_p->c_oflag = readChar(&stream) != '\x00' ?
        termios_p->c_oflag | OCRNL  : termios_p->c_oflag & ~OCRNL;
    termios_p->c_oflag = readChar(&stream) != '\x00' ?
        termios_p->c_oflag | ONOCR  : termios_p->c_oflag & ~ONOCR;
    termios_p->c_oflag = readChar(&stream) != '\x00' ?
        termios_p->c_oflag | ONLRET : termios_p->c_oflag & ~ONLRET;
    termios_p->c_oflag = readChar(&stream) != '\x00' ?
        termios_p->c_oflag | OFILL  : termios_p->c_oflag & ~OFILL;
    termios_p->c_oflag = readChar(&stream) != '\x00' ?
        termios_p->c_oflag | OFDEL  : termios_p->c_oflag & ~OFDEL;
    termios_p->c_oflag &= ~NLDLY;
    switch(readInt(&stream))
    {
    case  0: termios_p->c_oflag |= NL0; break;
    default: termios_p->c_oflag |= NL1; break;
    }
    termios_p->c_oflag &= ~CRDLY;
    switch(readInt(&stream))
    {
    case  0: termios_p->c_oflag |= CR0; break;
    case  1: termios_p->c_oflag |= CR1; break;
    case  2: termios_p->c_oflag |= CR2; break;
    default: termios_p->c_oflag |= CR3; break;
    }
    termios_p->c_oflag &= ~TABDLY;
    switch(readInt(&stream))
    {
    case  0: termios_p->c_oflag |= TAB0; break;
    case  1: termios_p->c_oflag |= TAB1; break;
    case  2: termios_p->c_oflag |= TAB2; break;
    default: termios_p->c_oflag |= TAB3; break;
    }
    termios_p->c_oflag &= ~BSDLY;
    switch(readInt(&stream))
    {
    case  0: termios_p->c_oflag |= BS0; break;
    default: termios_p->c_oflag |= BS1; break;
    }
    termios_p->c_oflag &= ~VTDLY;
    switch(readInt(&stream))
    {
    case  0: termios_p->c_oflag |= VT0; break;
    case  1: termios_p->c_oflag |= VT1; break;
    }
    termios_p->c_oflag &= ~FFDLY;
    switch(readInt(&stream))
    {
    case  0: termios_p->c_oflag |= FF0; break;
    default: termios_p->c_oflag |= FF1; break;
    }
    // cflag
    termios_p->c_cflag &= ~CSIZE;
    switch(readInt(&stream))
    {
    case  5: termios_p->c_cflag |= CS5; break;
    case  6: termios_p->c_cflag |= CS6; break;
    case  7: termios_p->c_cflag |= CS7; break;
    default: termios_p->c_cflag |= CS8; break;
    }
    termios_p->c_cflag = readChar(&stream) != '\x00' ?
        termios_p->c_cflag | CSTOPB : termios_p->c_cflag & ~CSTOPB;
    termios_p->c_cflag = readChar(&stream) != '\x00' ?
        termios_p->c_cflag | CREAD  : termios_p->c_cflag & ~CREAD;
    termios_p->c_cflag = readChar(&stream) != '\x00' ?
        termios_p->c_cflag | PARENB : termios_p->c_cflag & ~PARENB;
    termios_p->c_cflag = readChar(&stream) != '\x00' ?
        termios_p->c_cflag | PARODD : termios_p->c_cflag & ~PARODD;
    termios_p->c_cflag = readChar(&stream) != '\x00' ?
        termios_p->c_cflag | HUPCL  : termios_p->c_cflag & ~HUPCL;
    termios_p->c_cflag = readChar(&stream) != '\x00' ?
        termios_p->c_cflag | CLOCAL : termios_p->c_cflag & ~CLOCAL;

    // lflag
    termios_p->c_lflag = readChar(&stream) != '\x00' ?
        termios_p->c_lflag | ECHO   : termios_p->c_lflag & ~ECHO;
    termios_p->c_lflag = readChar(&stream) != '\x00' ?
        termios_p->c_lflag | ECHOE  : termios_p->c_lflag & ~ECHOE;
    termios_p->c_lflag = readChar(&stream) != '\x00' ?
        termios_p->c_lflag | ECHOK  : termios_p->c_lflag & ~ECHOK;
    termios_p->c_lflag = readChar(&stream) != '\x00' ?
        termios_p->c_lflag | ECHONL : termios_p->c_lflag & ~ECHONL;
    termios_p->c_lflag = readChar(&stream) != '\x00' ?
        termios_p->c_lflag | ICANON : termios_p->c_lflag & ~ICANON;
    termios_p->c_lflag = readChar(&stream) != '\x00' ?
        termios_p->c_lflag | IEXTEN : termios_p->c_lflag & ~IEXTEN;
    termios_p->c_lflag = readChar(&stream) != '\x00' ?
        termios_p->c_lflag | ISIG   : termios_p->c_lflag & ~ISIG;
    termios_p->c_lflag = readChar(&stream) != '\x00' ?
        termios_p->c_lflag | NOFLSH : termios_p->c_lflag & ~NOFLSH;
    termios_p->c_lflag = readChar(&stream) != '\x00' ?
        termios_p->c_lflag | TOSTOP : termios_p->c_lflag & ~TOSTOP;

    // cc
    termios_p->c_cc[VEOF]   = readUChar(&stream);
    termios_p->c_cc[VEOL]   = readUChar(&stream);
    termios_p->c_cc[VERASE] = readUChar(&stream);
    termios_p->c_cc[VINTR]  = readUChar(&stream);
    termios_p->c_cc[VKILL]  = readUChar(&stream);
    termios_p->c_cc[VMIN]   = readUChar(&stream);
    termios_p->c_cc[VQUIT]  = readUChar(&stream);
    termios_p->c_cc[VSUSP]  = readUChar(&stream);
    termios_p->c_cc[VTIME]  = readUChar(&stream);
    termios_p->c_cc[VSTART] = readUChar(&stream);
    termios_p->c_cc[VSTOP]  = readUChar(&stream);

    END_TARGET_OPERATION(thread);

    writeString(thread, "Ok");
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict cfgetispeed_cmd(TAThread thread, TAInputStream stream)
{
    struct termios *termios_p;
    speed_t res;

    // Prepare
    termios_p = readPointer(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = cfgetispeed(termios_p);

    END_TARGET_OPERATION(thread);

    // Response
    writeUInt(thread, getModelSpeed(res));
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict cfgetospeed_cmd(TAThread thread, TAInputStream stream)
{
    struct termios* termios_p;
    speed_t res;

    // Prepare
    termios_p = readPointer(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = cfgetospeed(termios_p);

    END_TARGET_OPERATION(thread);

    // Response
    writeUInt(thread, getModelSpeed(res));
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict cfmakeraw_cmd(TAThread thread, TAInputStream stream)
{
    struct termios* termios_p;

    // Prepare
    termios_p = readPointer(&stream);

    START_TARGET_OPERATION(thread);

    cfmakeraw(termios_p);

    END_TARGET_OPERATION(thread);

    // Response
    writeString(thread, "Ok");
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict cfsetispeed_cmd(TAThread thread, TAInputStream stream)
{
    struct termios* termios_p;
    speed_t speed;
    int res;

    // Prepare
    termios_p = readPointer(&stream);
    speed = getSUTSpeed(readUInt(&stream));

    START_TARGET_OPERATION(thread);

    // Execute
    errno = 0;
    res = cfsetispeed(termios_p, speed);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict cfsetospeed_cmd(TAThread thread, TAInputStream stream)
{
    struct termios* termios_p;
    speed_t speed;
    int res;

    // Prepare
    termios_p = readPointer(&stream);
    speed = getSUTSpeed(readUInt(&stream));

    START_TARGET_OPERATION(thread);

    // Execute
    errno = 0;
    res = cfsetospeed(termios_p, speed);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict cfsetspeed_cmd(TAThread thread, TAInputStream stream)
{
    struct termios* t;
    speed_t speed;
    int res;

    // Prepare
    t = readPointer(&stream);
    speed = getSUTSpeed(readUInt(&stream));

    START_TARGET_OPERATION(thread);

    // Execute
    errno = 0;
    res = cfsetspeed(t, speed);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict close_tty_cmd(TAThread thread, TAInputStream stream)
{
    int fildes, res;

    // Prepare
    fildes = readInt(&stream);

    BEFORE_BLOCKED_TARGET_OPERATION(thread);

    writeString(thread, "Ok");
    sendResponse(thread);

    START_TARGET_OPERATION(thread);

    // Execute
    errno = 0;
    res = close(fildes);

    END_TARGET_OPERATION(thread);

    // Response
    writeDeferredReaction(thread, "close_tty_return");
    writeInt(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict ctermid_cmd(TAThread thread, TAInputStream stream)
{
    char *s;
    char *res;
    char buffer[L_ctermid];

    // Prepare
    s = readString(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = ctermid(s == NULL ? NULL : buffer);

    END_TARGET_OPERATION(thread);

    // Response
    writeString(thread, res);
    writeString(thread, s == NULL ? NULL : buffer);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict getlogin_cmd(TAThread thread, TAInputStream stream)
{
    char *res;

    START_TARGET_OPERATION(thread);

    // Execute
    errno = 0;
    res = getlogin();

    END_TARGET_OPERATION(thread);

    // Response
    writeString(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict getlogin_r_cmd(TAThread thread, TAInputStream stream)
{
    char *name;
    size_t namesize;
    int res;

    // Prepare
    namesize = readSize(&stream);
    name = (char *)ta_alloc_memory(namesize);

    if(name == NULL)
    {
        sendException(thread, "Can not allocate memory for name");
        return taDefaultVerdict;
    }

    START_TARGET_OPERATION(thread);

    // Execute
    res = getlogin_r(name, namesize);

    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    writeString(thread, name);
    sendResponse(thread);

    ta_dealloc_memory(name);

    return taDefaultVerdict;
}

static TACommandVerdict grantpt_cmd(TAThread thread, TAInputStream stream)
{
    int fildes, res;

    // Prepare
    fildes = readInt(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    errno = 0;
    res = grantpt(fildes);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict isatty_cmd(TAThread thread, TAInputStream stream)
{
    int fildes, res;

    // Prepare
    fildes = readInt(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    errno = 0;
    res = isatty(fildes);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict open_tty_cmd(TAThread thread, TAInputStream stream)
{
    char *path, oflag, res;

    // Prepare
    path = readString(&stream);
    oflag = readOpenFlags(&stream);

    BEFORE_BLOCKED_TARGET_OPERATION(thread);

    writeString(thread, "Ok");
    sendResponse(thread);

    START_TARGET_OPERATION(thread);

    // Execute
    errno = 0;
    res = open(path, oflag);

    END_TARGET_OPERATION(thread);

    // Response
    writeDeferredReaction(thread, "open_tty_return");
    writeInt(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict openpty_cmd(TAThread thread, TAInputStream stream)
{
    int amaster, aslave, nflag, wflag, res;
    char name[sysconf(_SC_TTY_NAME_MAX)];
    struct termios *termp;
    struct winsize win;

    // Prepare
    nflag = readInt(&stream);
    termp = readPointer(&stream);
    wflag = readWinSize(&stream, &win);

    START_TARGET_OPERATION(thread);

    // Execute
    errno = 0;
    res = openpty(&amaster, &aslave, nflag ? name : NULL, termp, wflag ? &win : NULL);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    writeInt(thread, amaster);
    writeInt(thread, aslave);

    if(nflag)
    {
        writeString(thread, name);
    }

    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict posix_openpt_cmd(TAThread thread,TAInputStream stream)
{
    int oflag, res;

    // Prepare
    oflag = readOpenFlags(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    errno = 0;
    res = posix_openpt(oflag);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict ptsname_cmd(TAThread thread, TAInputStream stream)
{
    int fildes;
    char *res;

    // Prepare
    fildes = readInt(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    errno = 0;
    res = ptsname(fildes);

    END_TARGET_OPERATION(thread);

    // Response
    writeString(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict read_tty_cmd(TAThread thread, TAInputStream stream)
{
    int fildes;
    size_t nbyte;
    char *buf;
    ssize_t res;

    // Prepare
    fildes = readInt(&stream);
    nbyte = readSize(&stream);
    buf = ta_alloc_memory(nbyte);

    if(buf == NULL)
    {
        sendException(thread, "Can not allocate memory for buf");
        return taDefaultVerdict;
    }

    BEFORE_BLOCKED_TARGET_OPERATION(thread);

    writeString(thread, "Ok");
    sendResponse(thread);

    START_TARGET_OPERATION(thread);

    // Execute
    errno = 0;
    res = read(fildes, buf, nbyte);

    END_TARGET_OPERATION(thread);

    // Response
    writeDeferredReaction(thread, "read_tty_return");
    writeSSize(thread, res);
    writeByteArray(thread, buf, res);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict tcdrain_cmd(TAThread thread, TAInputStream stream)
{
    int fildes, res;

    // Prepare
    fildes = readInt(&stream);

    BEFORE_BLOCKED_TARGET_OPERATION(thread);

    writeString(thread, "Ok");
    sendResponse(thread);

    START_TARGET_OPERATION(thread);

    // Execute
    errno = 0;
    res = tcdrain(fildes);

    END_TARGET_OPERATION(thread);

    // Response
    writeDeferredReaction(thread, "tcdrain_return");
    writeInt(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict tcflow_cmd(TAThread thread, TAInputStream stream)
{
    int fildes, action, res;

    // Prepare
    fildes = readInt(&stream);
    action = readInt(&stream);

    BEFORE_BLOCKED_TARGET_OPERATION(thread);

    writeString(thread, "Ok");
    sendResponse(thread);

    START_TARGET_OPERATION(thread);

    // Execute
    errno = 0;
    res = tcflow(fildes, action);

    END_TARGET_OPERATION(thread);

    // Response
    writeDeferredReaction(thread, "tcflow_return");
    writeInt(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict tcflush_cmd(TAThread thread, TAInputStream stream)
{
    int fildes, queue_selector, res;

    // Prepare
    fildes = readInt(&stream);
    queue_selector = readInt(&stream);

    BEFORE_BLOCKED_TARGET_OPERATION(thread);

    writeString(thread, "Ok");
    sendResponse(thread);

    START_TARGET_OPERATION(thread);

    // Execute
    errno = 0;
    res = tcflush(fildes, queue_selector);

    END_TARGET_OPERATION(thread);

    // Response
    writeDeferredReaction(thread, "tcflush_return");
    writeInt(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict tcgetattr_cmd(TAThread thread, TAInputStream stream)
{
    int fildes, res;
    struct termios *termios_p;

    // Prepare
    fildes = readInt(&stream);
    termios_p = readPointer(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    errno = 0;
    res = tcgetattr(fildes, termios_p);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict tcgetpgrp_cmd(TAThread thread, TAInputStream stream)
{
    int fildes;
    pid_t res;

    // Prepare
    fildes = readInt(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    errno = 0;
    res = tcgetpgrp(fildes);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict tcgetsid_cmd(TAThread thread, TAInputStream stream)
{
    int fildes;
    pid_t res;

    // Prepare
    fildes = readInt(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    errno = 0;
    res = tcgetsid(fildes);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict tcsendbreak_cmd(TAThread thread, TAInputStream stream)
{
    int fildes, duration, res;

    // Prepare
    fildes = readInt(&stream);
    duration = readInt(&stream);

    BEFORE_BLOCKED_TARGET_OPERATION(thread);
    writeString(thread, "Ok");
    sendResponse(thread);

    START_TARGET_OPERATION(thread);

    // Execute
    errno = 0;
    res = tcsendbreak(fildes, duration);

    END_TARGET_OPERATION(thread);

    // Response
    writeDeferredReaction(thread, "tcsendbreak_return");
    writeInt(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict tcsetattr_cmd(TAThread thread, TAInputStream stream)
{
    int fildes, optional_actions, res;
    struct termios *termios_p;

    // Prepare
    fildes = readInt(&stream);
    optional_actions = readInt(&stream);
    termios_p = readPointer(&stream);

    BEFORE_BLOCKED_TARGET_OPERATION(thread);

    writeString(thread, "Ok");
    sendResponse(thread);

    START_TARGET_OPERATION(thread);

    // Execute
    errno = 0;
    res = tcsetattr(fildes, optional_actions, termios_p);

    END_TARGET_OPERATION(thread);

    // Response
    writeDeferredReaction(thread, "tcsetattr_return");
    writeInt(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict tcsetpgrp_cmd(TAThread thread, TAInputStream stream)
{
    int fildes, res;
    pid_t pgid_id;

    // Prepare
    fildes = readInt(&stream);
    pgid_id = readInt(&stream);

    BEFORE_BLOCKED_TARGET_OPERATION(thread);

    writeString(thread, "Ok");
    sendResponse(thread);

    START_TARGET_OPERATION(thread);

    // Execute
    errno = 0;
    res = tcsetpgrp(fildes, pgid_id);

    END_TARGET_OPERATION(thread);

    // Response
    writeDeferredReaction(thread, "tcsetpgrp_return");
    writeInt(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict ttyio_TIOCGWINSZ_cmd(TAThread thread, TAInputStream stream)
{
    int fd, argp_is_not_null, res;
    struct winsize arg;

    // Prepare
    fd = readInt(&stream);
    argp_is_not_null = readInt(&stream);

    // Mark that we actually call ioctl
    ta_debug_printf( "search for ioctl (%u)...\n", (unsigned long)pthread_self() );

    START_TARGET_OPERATION(thread);

    // Execute
    errno = 0;
    res = ioctl(fd, TIOCGWINSZ, argp_is_not_null ? &arg : NULL);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);

    if(argp_is_not_null)
    {
        writeUShort(thread, arg.ws_row);
        writeUShort(thread, arg.ws_col);
        writeUShort(thread, arg.ws_xpixel);
        writeUShort(thread, arg.ws_ypixel);
    }

    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict ttyname_cmd(TAThread thread, TAInputStream stream)
{
    int fildes;
    char *res;

    // Prepare
    fildes = readInt(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    errno = 0;
    res = ttyname(fildes);

    END_TARGET_OPERATION(thread);

    // Response
    writeString(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict ttyname_r_cmd(TAThread thread, TAInputStream stream)
{
    int fildes, res;
    char *name;
    size_t namesize;

    // Prepare
    fildes = readInt(&stream);
    namesize = readSize(&stream);
    name = (char *)ta_alloc_memory(namesize);

    if(name == NULL)
    {
        sendException(thread, "Can not allocate memory for name");
        return taDefaultVerdict;
    }

    START_TARGET_OPERATION(thread);

    // Execute
    res = ttyname_r(fildes, name, namesize);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    writeString(thread, name);
    sendResponse(thread);

    ta_dealloc_memory(name);

    return taDefaultVerdict;
}

static TACommandVerdict unlockpt_cmd(TAThread thread, TAInputStream stream)
{
    int fildes, res;

    // Prepare
    fildes = readInt(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    errno = 0;
    res = unlockpt(fildes);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict write_tty_cmd(TAThread thread, TAInputStream stream)
{
    int fildes;
    size_t nbyte;
    char *buf;
    ssize_t res;

    // Prepare
    fildes = readInt(&stream);
    readByteArray(&stream, &buf, &nbyte);

    BEFORE_BLOCKED_TARGET_OPERATION(thread);

    writeString(thread, "Ok");
    sendResponse(thread);

    START_TARGET_OPERATION(thread);

    // Execute
    errno = 0;
    res = write(fildes, buf, nbyte);

    END_TARGET_OPERATION(thread);

    // Response
    writeDeferredReaction(thread, "write_tty_return");
    writeSSize(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict login_tty_cmd(TAThread thread, TAInputStream stream)
{
    int fildes;
    int res;
    
    // Prepare
    fildes = readInt(&stream);
    
    START_TARGET_OPERATION(thread);
    
    // Execute
    errno = 0;
    res = login_tty (fildes);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    writeInt(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_io_term_commands(void)
{
    ta_register_command("gettermios", gettermios_cmd);
    ta_register_command("settermios", settermios_cmd);

    ta_register_command("cfgetispeed", cfgetispeed_cmd);
    ta_register_command("cfgetospeed", cfgetospeed_cmd);
    ta_register_command("cfmakeraw", cfmakeraw_cmd);
    ta_register_command("cfsetispeed", cfsetispeed_cmd);
    ta_register_command("cfsetospeed", cfsetospeed_cmd);
    ta_register_command("cfsetspeed", cfsetspeed_cmd);
    ta_register_command("close_tty", close_tty_cmd);
    ta_register_command("ctermid", ctermid_cmd);
    ta_register_command("getlogin", getlogin_cmd);
    ta_register_command("getlogin_r", getlogin_r_cmd);
    ta_register_command("grantpt", grantpt_cmd);
    ta_register_command("isatty", isatty_cmd);
    ta_register_command("open_tty", open_tty_cmd);
    ta_register_command("openpty", openpty_cmd);
    ta_register_command("posix_openpt", posix_openpt_cmd);
    ta_register_command("ptsname", ptsname_cmd);
    ta_register_command("read_tty", read_tty_cmd);
    ta_register_command("tcdrain", tcdrain_cmd);
    ta_register_command("tcflow", tcflow_cmd);
    ta_register_command("tcflush", tcflush_cmd);
    ta_register_command("tcgetattr", tcgetattr_cmd);
    ta_register_command("tcgetpgrp", tcgetpgrp_cmd);
    ta_register_command("tcgetsid", tcgetsid_cmd);
    ta_register_command("tcsendbreak", tcsendbreak_cmd);
    ta_register_command("tcsetattr", tcsetattr_cmd);
    ta_register_command("tcsetpgrp", tcsetpgrp_cmd);
    ta_register_command("ttyio_TIOCGWINSZ", ttyio_TIOCGWINSZ_cmd);
    ta_register_command("ttyname", ttyname_cmd);
    ta_register_command("ttyname_r", ttyname_r_cmd);
    ta_register_command("unlockpt", unlockpt_cmd);
    ta_register_command("write_tty", write_tty_cmd);
    ta_register_command("login_tty", login_tty_cmd);
}

