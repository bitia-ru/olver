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


#include "util/compress/compress_agent.h"
#include <zlib.h>

#include <stdio.h>
#include <errno.h>


/********************************************************************/
/*                          Utilities                               */
/********************************************************************/

void writeULongList(TAThread thread, const uLongf* res, int size)
{
    int i;

    for(i=0;i<size;i++)
        writeULong(thread, res[i]);
}

static TACommandVerdict ZLIB_VERSION_cmd(TAThread thread,TAInputStream stream)
{
    char* res;

    START_TARGET_OPERATION(thread);

    res = ZLIB_VERSION;

    END_TARGET_OPERATION(thread);

    // Response
    writeString(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict z_stream_size_cmd(TAThread thread,TAInputStream stream)
{
    int res;

    START_TARGET_OPERATION(thread);

    res = sizeof(z_stream);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

int readZStream(TAInputStream* stream, z_stream* strm)
{
    char* isNull;

    verifyType_TAInputStream(stream,"z_stream");

    isNull = readString(stream);

    ta_debug_printf("isNull==%s\n", isNull);

    if(isNull[1]=='U')
        return 1;

    strm->adler = readULong(stream);
    strm->avail_in=readUInt(stream);
    strm->avail_out=readUInt(stream);
    strm->data_type=readInt(stream);
    strm->msg=readString(stream);
    strm->state=readPointer(stream);

    strm->zalloc=readPointer(stream);
    strm->zfree=readPointer(stream);

    strm->opaque=readPointer(stream);

    strm->next_in=readPointer(stream);
    strm->next_out=readPointer(stream);

    strm->reserved = readULong(stream);
    strm->total_in = readULong(stream);
    strm->total_out = readULong(stream);

    ta_debug_printf("read: returning 0(not is null)...\n");

    return 0;
}

void writeZStream(TAThread thread, z_stream* strm)
{
    if(strm==NULL)
    {
        writeString(thread, "NULL");
        return;
    }

    writeString(thread, "NON_NULL");
    writeULong(thread, strm->adler);
    writeUInt(thread, strm->avail_in);
    writeUInt(thread, strm->avail_out);
    writeInt(thread, strm->data_type);
    writeString(thread, strm->msg);
    writePointer(thread, strm->state);

    ta_debug_printf("strm->state==%d\n", strm->state);

    writePointer(thread, strm->zalloc);
    writePointer(thread, strm->zfree);

    writePointer(thread, strm->opaque);

    writePointer(thread, strm->next_in);
    writePointer(thread, strm->next_out);

    writeULong(thread, strm->reserved);
    writeULong(thread, strm->total_in);
    writeULong(thread, strm->total_out);
}


/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict adler32_cmd(TAThread thread,TAInputStream stream)
{
    char* buf;
    uLong adler, res;
    uInt len;
    size_t size;
    int bufIsNull;

    // Prepare
    adler = readULong(&stream);
    readByteArray(&stream, &buf, &size);
    len = readUInt(&stream);
    bufIsNull = readInt(&stream);

    START_TARGET_OPERATION(thread);

    if(!bufIsNull)
        res = adler32(adler, (Bytef*)buf, len);
    else
        res = adler32(adler, Z_NULL, len);

    END_TARGET_OPERATION(thread);

    // Response
    writeULong(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict compress_cmd(TAThread thread,TAInputStream stream)
{
    Bytef * dest, *source;
    uLongf destLen, sourceLen;
    int res;

    dest = readPointer(&stream);
    destLen = readULong(&stream);
    source = readPointer(&stream);
    sourceLen=readULong(&stream);

    START_TARGET_OPERATION(thread);

    res = compress(dest, &destLen, source, sourceLen);

    END_TARGET_OPERATION(thread);

    writePointer(thread, dest);
    writeULong(thread, destLen);
    writeInt(thread, res);

    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict compress2_cmd(TAThread thread,TAInputStream stream)
{
    Bytef * dest, *source;
    uLongf destLen, sourceLen;
    int res, level;

    dest = readPointer(&stream);
    destLen = readULong(&stream);
    source = readPointer(&stream);
    sourceLen = readULong(&stream);
    level = readInt(&stream);

    ta_debug_printf("level==%d\n", level);
    ta_debug_printf("source==%s\n", source);

    START_TARGET_OPERATION(thread);

    if(level==-1)
        res = compress2(dest, &destLen, source, sourceLen,
                                                Z_DEFAULT_COMPRESSION);
    else
        res = compress2(dest, &destLen, source, sourceLen, level);

    END_TARGET_OPERATION(thread);

    ta_debug_printf("dest==%s\n", dest);

    writePointer(thread, dest);
    writeULong(thread, destLen);
    writeInt(thread, res);

    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict compressBound_cmd(TAThread thread,TAInputStream stream)
{
    unsigned long sourceLen;
    int res;

    sourceLen = readULong(&stream);

    START_TARGET_OPERATION(thread);

    res = compressBound(sourceLen);

    END_TARGET_OPERATION(thread);

    writeInt(thread, res);

    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict crc32_cmd(TAThread thread,TAInputStream stream)
{
    uLong crc, res;
    uInt len;
    Bytef* buf;

    // Prepare
    crc = readULong(&stream);
    buf = readPointer(&stream);
    len = readUInt(&stream);

    START_TARGET_OPERATION(thread);

    res = crc32(crc, buf, len);

    END_TARGET_OPERATION(thread);

    if(buf==0)
        ta_debug_printf("res==%u\n", res);

    // Response
    writeULong(thread, res);

    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict deflate_cmd(TAThread thread,TAInputStream stream)
{
    z_stream strm;
    int flush, res, is_null;

    is_null = readZStream(&stream, &strm);
    flush = readInt(&stream);

    /*ta_debug_printf( "next_in==%d\navail_in==%u\ntotal_in==%lu\nnext_out==%d\n"
            "avail_out==%u\ntotal_out==%lu\n",
            strm.next_in, strm.avail_in, strm.total_in, strm.next_out,
            strm.avail_out,strm.total_out);

    ta_debug_printf( "msg==%s\nstate==%d\nzalloc==%d\nzfree==%d\n"
            "opaque==%d\ndata_type==%d\nadler==%lu\nreserved==%lu\n",
            strm.msg, strm.state,
            strm.zalloc, strm.zfree, strm.opaque, strm.data_type, strm.adler,
            strm.reserved);*/

    START_TARGET_OPERATION(thread);

    if(!is_null)
        res = deflate(&strm, flush);
    else
        res = deflate(0, flush);

    END_TARGET_OPERATION(thread);

    ta_debug_printf("deflate executed...\n");

    // Response
    if(!is_null)
        writeZStream(thread, &strm);
    else
        writeZStream(thread, 0);

    writeInt(thread, res);

    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict deflateBound_cmd(TAThread thread,TAInputStream stream)
{
    z_stream strm;
    int res, is_null;
    uLong sourceLen;

    is_null = readZStream(&stream, &strm);
    sourceLen = readULong(&stream);

    /*ta_debug_printf( "next_in==%d\navail_in==%u\ntotal_in==%lu\nnext_out==%d\n"
            "avail_out==%u\ntotal_out==%lu\n",
            strm.next_in, strm.avail_in, strm.total_in, strm.next_out,
            strm.avail_out,strm.total_out);

    ta_debug_printf( "msg==%s\nstate==%d\nzalloc==%d\nzfree==%d\n"
            "opaque==%d\ndata_type==%d\nadler==%lu\nreserved==%lu\n",
            strm.msg, strm.state,
            strm.zalloc, strm.zfree, strm.opaque, strm.data_type, strm.adler,
            strm.reserved);*/

    START_TARGET_OPERATION(thread);

    if(!is_null)
        res = deflateBound(&strm, sourceLen);
    else
        res = deflateBound(0, sourceLen);

    END_TARGET_OPERATION(thread);

    // Response
    if(!is_null)
        writeZStream(thread, &strm);
    else
        writeZStream(thread, 0);

    writeInt(thread, res);

    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict deflateCopy_cmd(TAThread thread,TAInputStream stream)
{
    z_stream source, dest;
    int res, is_null_source, is_null_dest;

    is_null_dest = readZStream(&stream, &dest);
    is_null_source = readZStream(&stream, &source);

    /*ta_debug_printf( "next_in==%d\navail_in==%u\ntotal_in==%lu\nnext_out==%d\n"
            "avail_out==%u\ntotal_out==%lu\n",
            strm.next_in, strm.avail_in, strm.total_in, strm.next_out,
            strm.avail_out,strm.total_out);

    ta_debug_printf( "msg==%s\nstate==%d\nzalloc==%d\nzfree==%d\n"
            "opaque==%d\ndata_type==%d\nadler==%lu\nreserved==%lu\n",
            strm.msg, strm.state,
            strm.zalloc, strm.zfree, strm.opaque, strm.data_type, strm.adler,
            strm.reserved);*/

    START_TARGET_OPERATION(thread);

    if(!is_null_dest)
    {
        if(!is_null_source)
        {
            res = deflateCopy(&dest, &source);
        }
        else
        {
            res = deflateCopy(&dest, 0);
        }
    }
    else
    {
        if(!is_null_source)
        {
            res = deflateCopy(0, &source);
        }
        else
        {
            res = deflateCopy(0, 0);
        }
    }

    END_TARGET_OPERATION(thread);

    // Response
    if(!is_null_dest)
        writeZStream(thread, &dest);
    else
        writeZStream(thread, 0);

    writeInt(thread, res);

    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict deflateEnd_cmd(TAThread thread,TAInputStream stream)
{
    z_stream strm;
    int res, is_null;

    is_null = readZStream(&stream, &strm);

    /*ta_debug_printf( "next_in==%d\navail_in==%u\ntotal_in==%lu\nnext_out==%d\n"
            "avail_out==%u\ntotal_out==%lu\n",
            strm.next_in, strm.avail_in, strm.total_in, strm.next_out,
            strm.avail_out,strm.total_out);

    ta_debug_printf( "msg==%s\nstate==%d\nzalloc==%d\nzfree==%d\n"
            "opaque==%d\ndata_type==%d\nadler==%lu\nreserved==%lu\n",
            strm.msg, strm.state,
            strm.zalloc, strm.zfree, strm.opaque, strm.data_type, strm.adler,
            strm.reserved);*/

    START_TARGET_OPERATION(thread);

    if(!is_null)
        res = deflateEnd(&strm);
    else
        res = deflateEnd(0);

    END_TARGET_OPERATION(thread);

    // Response
    if(!is_null)
        writeZStream(thread, &strm);
    else
        writeZStream(thread, 0);

    writeInt(thread, res);

    sendResponse(thread);

    return taDefaultVerdict;
}


static TACommandVerdict deflateInit2__cmd(TAThread thread,TAInputStream stream)
{
    z_stream strm;
    int level, method, windowBits, memLevel, strategy, stream_size, res, is_null;
    char* version;

    is_null = readZStream(&stream, &strm);
    level = readInt(&stream);
    method = readInt(&stream);
    windowBits = readInt(&stream);
    memLevel = readInt(&stream);
    strategy = readInt(&stream);
    version = readString(&stream);
    stream_size = readInt(&stream);

    START_TARGET_OPERATION(thread);

    if(!is_null)
        res = deflateInit2_(&strm, level, method, windowBits, memLevel, strategy,
            version, stream_size);
    else
        res = deflateInit2_(0, level, method, windowBits, memLevel, strategy,
            version, stream_size);

    END_TARGET_OPERATION(thread);

    // Response
    if(!is_null)
        writeZStream(thread, &strm);
    else
        writeZStream(thread, 0);

    writeInt(thread, res);

    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict deflateInit__cmd(TAThread thread,TAInputStream stream)
{
    z_stream strm;
    int level, stream_size, res, is_null;
    char* version;

    is_null = readZStream(&stream, &strm);
    level = readInt(&stream);
    version = readString(&stream);
    stream_size = readInt(&stream);

    START_TARGET_OPERATION(thread);

    if(!is_null)
        res = deflateInit_(&strm, level, version, stream_size);
    else
        res = deflateInit_(0, level, version, stream_size);

    END_TARGET_OPERATION(thread);

    ta_debug_printf("res==%d\n");

    // Response
    if(!is_null)
        writeZStream(thread, &strm);
    else
        writeZStream(thread, 0);

    writeInt(thread, res);

    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict deflateParams_cmd(TAThread thread,TAInputStream stream)
{
    z_stream strm;
    int res, is_null, level, strategy;

    is_null = readZStream(&stream, &strm);
    level = readInt(&stream);
    strategy = readInt(&stream);

    /*ta_debug_printf( "next_in==%d\navail_in==%u\ntotal_in==%lu\nnext_out==%d\n"
            "avail_out==%u\ntotal_out==%lu\n",
            strm.next_in, strm.avail_in, strm.total_in, strm.next_out,
            strm.avail_out,strm.total_out);

    ta_debug_printf( "msg==%s\nstate==%d\nzalloc==%d\nzfree==%d\n"
            "opaque==%d\ndata_type==%d\nadler==%lu\nreserved==%lu\n",
            strm.msg, strm.state,
            strm.zalloc, strm.zfree, strm.opaque, strm.data_type, strm.adler,
            strm.reserved);*/

    START_TARGET_OPERATION(thread);

    if(!is_null)
        res = deflateParams(&strm, level, strategy);
    else
        res = deflateParams(0, level, strategy);

    END_TARGET_OPERATION(thread);

    // Response
    if(!is_null)
        writeZStream(thread, &strm);
    else
        writeZStream(thread, 0);

    writeInt(thread, res);

    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict deflateReset_cmd(TAThread thread,TAInputStream stream)
{
    z_stream strm;
    int res, is_null;

    is_null = readZStream(&stream, &strm);

    /*ta_debug_printf( "next_in==%d\navail_in==%u\ntotal_in==%lu\nnext_out==%d\n"
            "avail_out==%u\ntotal_out==%lu\n",
            strm.next_in, strm.avail_in, strm.total_in, strm.next_out,
            strm.avail_out,strm.total_out);

    ta_debug_printf( "msg==%s\nstate==%d\nzalloc==%d\nzfree==%d\n"
            "opaque==%d\ndata_type==%d\nadler==%lu\nreserved==%lu\n",
            strm.msg, strm.state,
            strm.zalloc, strm.zfree, strm.opaque, strm.data_type, strm.adler,
            strm.reserved);*/

    START_TARGET_OPERATION(thread);

    if(!is_null)
        res = deflateReset(&strm);
    else
        res = deflateReset(0);

    END_TARGET_OPERATION(thread);

    // Response
    if(!is_null)
        writeZStream(thread, &strm);
    else
        writeZStream(thread, 0);

    writeInt(thread, res);

    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict deflateSetDictionary_cmd(TAThread thread,TAInputStream stream)
{
    z_stream strm;
    int res, is_null;
    Bytef * dictionary;
    uInt dictlen;

    is_null = readZStream(&stream, &strm);
    dictionary = (Bytef*) readPointer(&stream);
    dictlen = readUInt(&stream);

    /*ta_debug_printf( "next_in==%d\navail_in==%u\ntotal_in==%lu\nnext_out==%d\n"
            "avail_out==%u\ntotal_out==%lu\n",
            strm.next_in, strm.avail_in, strm.total_in, strm.next_out,
            strm.avail_out,strm.total_out);

    ta_debug_printf( "msg==%s\nstate==%d\nzalloc==%d\nzfree==%d\n"
            "opaque==%d\ndata_type==%d\nadler==%lu\nreserved==%lu\n",
            strm.msg, strm.state,
            strm.zalloc, strm.zfree, strm.opaque, strm.data_type, strm.adler,
            strm.reserved);*/

    START_TARGET_OPERATION(thread);

    if(!is_null)
        res = deflateSetDictionary(&strm, dictionary, dictlen);
    else
        res = deflateSetDictionary(0, dictionary, dictlen);

    END_TARGET_OPERATION(thread);

    // Response
    if(!is_null)
        writeZStream(thread, &strm);
    else
        writeZStream(thread, 0);

    writeInt(thread, res);

    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict get_crc_table_cmd(TAThread thread,TAInputStream stream)
{
    const uLongf* res;

    START_TARGET_OPERATION(thread);

    res = get_crc_table();

    END_TARGET_OPERATION(thread);

    // Response
    writeULongList(thread, res, 256);

    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict gzclose_cmd(TAThread thread,TAInputStream stream)
{
    void* file;
    int res, errnum;

    file = readPointer(&stream);

    START_TARGET_OPERATION(thread);

    errno = 0;
    res = gzclose(file);

    END_TARGET_OPERATION(thread);

    gzerror(file, &errnum);

    writeInt(thread, errnum);
    writeInt(thread, errno);
    writeInt(thread, res);

    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict gzdopen_cmd(TAThread thread,TAInputStream stream)
{
    char *mode;
    void* res;
    int fd;

    fd = readInt(&stream);
    mode = readString(&stream);

    START_TARGET_OPERATION(thread);

    errno=0;
    res = gzdopen(fd, mode);

    END_TARGET_OPERATION(thread);

    writeInt(thread, errno);
    writePointer(thread, res);

    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict gzeof_cmd(TAThread thread,TAInputStream stream)
{
    void* file;
    int res;

    file = readPointer(&stream);

    START_TARGET_OPERATION(thread);

    errno=0;
    res = gzeof(file);

    END_TARGET_OPERATION(thread);

    writeInt(thread, res);

    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict gzerror_cmd(TAThread thread,TAInputStream stream)
{
    void* file;
    int errnum;
    const char* res;

    file = readPointer(&stream);

    START_TARGET_OPERATION(thread);

    res = gzerror(file, &errnum);

    END_TARGET_OPERATION(thread);

    writeInt(thread, errnum);
    writeString(thread, res);

    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict gzflush_cmd(TAThread thread,TAInputStream stream)
{
    void* file;
    int res, flush, errnum;

    file = readPointer(&stream);
    flush = readInt(&stream);

    START_TARGET_OPERATION(thread);

    res = gzflush(file, flush);

    END_TARGET_OPERATION(thread);

    gzerror(file, &errnum);

    writeInt(thread, errnum);
    writeInt(thread, errno);
    writeInt(thread, res);

    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict gzgetc_cmd(TAThread thread,TAInputStream stream)
{
    void* file;
    int res, errnum;

    file = readPointer(&stream);

    START_TARGET_OPERATION(thread);

    res = gzgetc(file);

    END_TARGET_OPERATION(thread);

    gzerror(file, &errnum);

    writeInt(thread, errnum);
    writeInt(thread, res);

    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict gzgets_cmd(TAThread thread,TAInputStream stream)
{
    void* file;
    char* buf, *res;
    int len, errnum;

    file = readPointer(&stream);
    buf = (char*)readPointer(&stream);
    len = readInt(&stream);

    START_TARGET_OPERATION(thread);

    res = gzgets(file, buf, len);

    END_TARGET_OPERATION(thread);

    gzerror(file, &errnum);

    writeInt(thread, errnum);
    writePointer(thread, (void*)res);

    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict gzopen_cmd(TAThread thread,TAInputStream stream)
{
    char* path, *mode;
    void* res;

    path = readString(&stream);
    mode = readString(&stream);

    START_TARGET_OPERATION(thread);

    errno = 0;
    res = gzopen(path, mode);

    END_TARGET_OPERATION(thread);

    writeInt(thread, errno);
    writePointer(thread, res);

    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict gzprintf_cmd(TAThread thread,TAInputStream stream)
{
    void* file;
    char* s;
    int res, errnum;

    file = readPointer(&stream);
    s = readString(&stream);

    START_TARGET_OPERATION(thread);

    res = gzprintf(file, s);

    END_TARGET_OPERATION(thread);

    writeInt(thread, errnum);
    writeInt(thread, errno);
    writeInt(thread, res);

    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict gzputc_cmd(TAThread thread,TAInputStream stream)
{
    void* file;
    int res, c;

    file = readPointer(&stream);
    c = readInt(&stream);

    START_TARGET_OPERATION(thread);

    res = gzputc(file, c);

    END_TARGET_OPERATION(thread);

    writeInt(thread, res);

    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict gzputs_cmd(TAThread thread,TAInputStream stream)
{
    void* file;
    char* s;
    int res, errnum;

    file = readPointer(&stream);
    s = readString(&stream);

    START_TARGET_OPERATION(thread);

    res = gzputs(file, s);

    END_TARGET_OPERATION(thread);

    gzerror(file, &errnum);

    writeInt(thread, errnum);
    writeInt(thread, errno);
    writeInt(thread, res);

    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict gzread_cmd(TAThread thread,TAInputStream stream)
{
    void* file, *buf;
    unsigned int len;
    int errnum, res;

    file = readPointer(&stream);
    buf = readPointer(&stream);
    len = readUInt(&stream);

    START_TARGET_OPERATION(thread);

    errno = 0;
    res = gzread(file, buf, len);

    END_TARGET_OPERATION(thread);

    gzerror(file, &errnum);

    writeInt(thread, errnum);
    writeInt(thread, errno);
    writeInt(thread, res);

    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict gzrewind_cmd(TAThread thread,TAInputStream stream)
{
    void* file;
    int res, errnum;

    file = readPointer(&stream);

    START_TARGET_OPERATION(thread);

    res = gzrewind(file);

    END_TARGET_OPERATION(thread);

    gzerror(file, &errnum);

    writeInt(thread, errnum);
    writeInt(thread, res);

    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict gzseek_cmd(TAThread thread,TAInputStream stream)
{
    void* file;
    z_off_t offset, res;
    int errnum, whence;

    file = readPointer(&stream);
    offset = (off_t)readLLong(&stream);
    whence = readInt(&stream);

    START_TARGET_OPERATION(thread);

    res = gzseek(file, offset, whence);

    END_TARGET_OPERATION(thread);

    gzerror(file, &errnum);

    writeInt(thread, errnum);
    writeLLong(thread, (long long)res);

    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict gzsetparams_cmd(TAThread thread,TAInputStream stream)
{
    void* file;
    int res, level, strategy;

    file = readPointer(&stream);
    level = readInt(&stream);
    strategy = readInt(&stream);

    START_TARGET_OPERATION(thread);

    res = gzsetparams(file, level, strategy);

    END_TARGET_OPERATION(thread);

    writeInt(thread, res);

    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict gztell_cmd(TAThread thread,TAInputStream stream)
{
    void* file;
    z_off_t res;
    int errnum;

    file = readPointer(&stream);

    START_TARGET_OPERATION(thread);

    res = gztell(file);

    END_TARGET_OPERATION(thread);

    gzerror(file, &errnum);

    writeInt(thread, errnum);
    writeLLong(thread, (long long)res);

    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict gzwrite_cmd(TAThread thread,TAInputStream stream)
{
    void* file, *buf;
    unsigned int res;
    int len, errnum;

    file = readPointer(&stream);
    buf = readPointer(&stream);
    len = readUInt(&stream);

    START_TARGET_OPERATION(thread);

    errno = 0;
    res = gzwrite(file, buf, len);

    END_TARGET_OPERATION(thread);

    gzerror(file, &errnum);

    writeInt(thread, errnum);
    writeInt(thread, errno);
    writeInt(thread, res);

    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict inflate_cmd(TAThread thread,TAInputStream stream)
{
    z_stream strm;
    int flush, res, is_null;

    is_null = readZStream(&stream, &strm);
    flush = readInt(&stream);

    /*ta_debug_printf( "next_in==%d\navail_in==%u\ntotal_in==%lu\nnext_out==%d\n"
            "avail_out==%u\ntotal_out==%lu\n",
            strm.next_in, strm.avail_in, strm.total_in, strm.next_out,
            strm.avail_out,strm.total_out);

    ta_debug_printf( "msg==%s\nstate==%d\nzalloc==%d\nzfree==%d\n"
            "opaque==%d\ndata_type==%d\nadler==%lu\nreserved==%lu\n",
            strm.msg, strm.state,
            strm.zalloc, strm.zfree, strm.opaque, strm.data_type, strm.adler,
            strm.reserved);*/

    START_TARGET_OPERATION(thread);

    if(!is_null)
        res = inflate(&strm, flush);
    else
        res = inflate(0, flush);

    END_TARGET_OPERATION(thread);

    ta_debug_printf("inflate: strm.next_out==%s\n", (strm.next_out-strm.total_out));

    // Response
    if(!is_null)
        writeZStream(thread, &strm);
    else
        writeZStream(thread, 0);

    ta_debug_printf("inflate res==%d\n", res);

    writeInt(thread, res);

    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict inflateEnd_cmd(TAThread thread,TAInputStream stream)
{
    z_stream strm;
    int res, is_null;

    is_null = readZStream(&stream, &strm);

    /*ta_debug_printf( "next_in==%d\navail_in==%u\ntotal_in==%lu\nnext_out==%d\n"
            "avail_out==%u\ntotal_out==%lu\n",
            strm.next_in, strm.avail_in, strm.total_in, strm.next_out,
            strm.avail_out,strm.total_out);

    ta_debug_printf( "msg==%s\nstate==%d\nzalloc==%d\nzfree==%d\n"
            "opaque==%d\ndata_type==%d\nadler==%lu\nreserved==%lu\n",
            strm.msg, strm.state,
            strm.zalloc, strm.zfree, strm.opaque, strm.data_type, strm.adler,
            strm.reserved);*/

    START_TARGET_OPERATION(thread);

    if(!is_null)
        res = inflateEnd(&strm);
    else
        res = inflateEnd(0);

    END_TARGET_OPERATION(thread);

    // Response
    if(!is_null)
        writeZStream(thread, &strm);
    else
        writeZStream(thread, 0);

    writeInt(thread, res);

    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict inflateInit2__cmd(TAThread thread,TAInputStream stream)
{
    z_stream strm;
    int stream_size, res, is_null, windowBits;
    char* version;

    is_null = readZStream(&stream, &strm);
    windowBits = readInt(&stream);
    version = readString(&stream);
    stream_size = readInt(&stream);

    START_TARGET_OPERATION(thread);

    if(!is_null)
        res = inflateInit2_(&strm, windowBits, version, stream_size);
    else
        res = inflateInit2_(0, windowBits, version, stream_size);

    END_TARGET_OPERATION(thread);

    ta_debug_printf("res==%d\n");

    // Response
    if(!is_null)
        writeZStream(thread, &strm);
    else
        writeZStream(thread, 0);

    writeInt(thread, res);

    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict inflateInit__cmd(TAThread thread,TAInputStream stream)
{
    z_stream strm;
    int stream_size, res, is_null;
    char* version;

    is_null = readZStream(&stream, &strm);
    version = readString(&stream);
    stream_size = readInt(&stream);

    START_TARGET_OPERATION(thread);

    if(!is_null)
        res = inflateInit_(&strm, version, stream_size);
    else
        res = inflateInit_(0, version, stream_size);

    END_TARGET_OPERATION(thread);

    ta_debug_printf("res==%d\n");

    // Response
    if(!is_null)
        writeZStream(thread, &strm);
    else
        writeZStream(thread, 0);

    writeInt(thread, res);

    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict inflateReset_cmd(TAThread thread,TAInputStream stream)
{
    z_stream strm;
    int res, is_null;

    is_null = readZStream(&stream, &strm);

    /*ta_debug_printf( "next_in==%d\navail_in==%u\ntotal_in==%lu\nnext_out==%d\n"
            "avail_out==%u\ntotal_out==%lu\n",
            strm.next_in, strm.avail_in, strm.total_in, strm.next_out,
            strm.avail_out,strm.total_out);

    ta_debug_printf( "msg==%s\nstate==%d\nzalloc==%d\nzfree==%d\n"
            "opaque==%d\ndata_type==%d\nadler==%lu\nreserved==%lu\n",
            strm.msg, strm.state,
            strm.zalloc, strm.zfree, strm.opaque, strm.data_type, strm.adler,
            strm.reserved);*/

    START_TARGET_OPERATION(thread);

    if(!is_null)
        res = inflateReset(&strm);
    else
        res = inflateReset(0);

    END_TARGET_OPERATION(thread);

    // Response
    if(!is_null)
        writeZStream(thread, &strm);
    else
        writeZStream(thread, 0);

    writeInt(thread, res);

    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict inflateSetDictionary_cmd(TAThread thread,TAInputStream stream)
{
    z_stream strm;
    int res, is_null;
    Bytef * dictionary;
    uInt dictlen;

    is_null = readZStream(&stream, &strm);
    dictionary = (Bytef*) readPointer(&stream);
    dictlen = readUInt(&stream);

    /*ta_debug_printf( "next_in==%d\navail_in==%u\ntotal_in==%lu\nnext_out==%d\n"
            "avail_out==%u\ntotal_out==%lu\n",
            strm.next_in, strm.avail_in, strm.total_in, strm.next_out,
            strm.avail_out,strm.total_out);

    ta_debug_printf( "msg==%s\nstate==%d\nzalloc==%d\nzfree==%d\n"
            "opaque==%d\ndata_type==%d\nadler==%lu\nreserved==%lu\n",
            strm.msg, strm.state,
            strm.zalloc, strm.zfree, strm.opaque, strm.data_type, strm.adler,
            strm.reserved);*/

    START_TARGET_OPERATION(thread);

    if(!is_null)
        res = inflateSetDictionary(&strm, dictionary, dictlen);
    else
        res = inflateSetDictionary(0, dictionary, dictlen);

    END_TARGET_OPERATION(thread);

    // Response
    if(!is_null)
        writeZStream(thread, &strm);
    else
        writeZStream(thread, 0);

    writeInt(thread, res);

    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict inflateSync_cmd(TAThread thread,TAInputStream stream)
{
    z_stream strm;
    int res, is_null;

    is_null = readZStream(&stream, &strm);

    START_TARGET_OPERATION(thread);

    if(!is_null)
        res = inflateSync(&strm);
    else
        res = inflateSync(0);

    END_TARGET_OPERATION(thread);

    // Response
    if(!is_null)
        writeZStream(thread, &strm);
    else
        writeZStream(thread, 0);

    writeInt(thread, res);

    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict inflateSyncPoint_cmd(TAThread thread,TAInputStream stream)
{
    z_stream strm;
    int res, is_null;

    is_null = readZStream(&stream, &strm);

    START_TARGET_OPERATION(thread);

    if(!is_null)
        res = inflateSyncPoint(&strm);
    else
        res = inflateSyncPoint(0);

    END_TARGET_OPERATION(thread);

    ta_debug_printf("ISP: res==%d\n", res);

    // Response
    if(!is_null)
        writeZStream(thread, &strm);
    else
        writeZStream(thread, 0);

    writeInt(thread, res);

    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict uncompress_cmd(TAThread thread,TAInputStream stream)
{
    Bytef * dest, *source;
    uLongf destLen, sourceLen;
    int res;

    dest = readPointer(&stream);
    destLen = readULong(&stream);
    source = readPointer(&stream);
    sourceLen = readULong(&stream);

    START_TARGET_OPERATION(thread);

    res = uncompress(dest, &destLen, source, sourceLen);

    END_TARGET_OPERATION(thread);

    writePointer(thread, dest);
    writeULong(thread, destLen);
    writeInt(thread, res);

    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict zError_cmd(TAThread thread,TAInputStream stream)
{
    const char* res;
    int err;

    err = readInt(&stream);

    START_TARGET_OPERATION(thread);

    res = zError(err);

    END_TARGET_OPERATION(thread);

    writeString(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict zlibVersion_cmd(TAThread thread,TAInputStream stream)
{
    const char* res;

    START_TARGET_OPERATION(thread);

    res = zlibVersion();

    END_TARGET_OPERATION(thread);

    writeString(thread, res);

    sendResponse(thread);

    return taDefaultVerdict;
}


/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_util_compress_commands(void)
{
    ta_register_command("adler32",adler32_cmd);
    ta_register_command("compress",compress_cmd);
    ta_register_command("compress2",compress2_cmd);
    ta_register_command("compressBound",compressBound_cmd);
    ta_register_command("crc32",crc32_cmd);
    ta_register_command("deflate",deflate_cmd);
    ta_register_command("deflateBound",deflateBound_cmd);
    ta_register_command("deflateCopy",deflateCopy_cmd);
    ta_register_command("deflateEnd",deflateEnd_cmd);
    ta_register_command("deflateInit2_",deflateInit2__cmd);
    ta_register_command("deflateInit_",deflateInit__cmd);
    ta_register_command("deflateParams",deflateParams_cmd);
    ta_register_command("deflateReset",deflateReset_cmd);
    ta_register_command("deflateSetDictionary",deflateSetDictionary_cmd);
    ta_register_command("get_crc_table",get_crc_table_cmd);
    ta_register_command("gzclose",gzclose_cmd);
    ta_register_command("gzdopen",gzdopen_cmd);
    ta_register_command("gzeof",gzeof_cmd);
    ta_register_command("gzerror",gzerror_cmd);
    ta_register_command("gzflush",gzflush_cmd);
    ta_register_command("gzgetc",gzgetc_cmd);
    ta_register_command("gzgets",gzgets_cmd);
    ta_register_command("gzopen",gzopen_cmd);
    ta_register_command("gzprintf",gzprintf_cmd);
    ta_register_command("gzputc",gzputc_cmd);
    ta_register_command("gzputs",gzputs_cmd);
    ta_register_command("gzread",gzread_cmd);
    ta_register_command("gzrewind",gzrewind_cmd);
    ta_register_command("gzseek",gzseek_cmd);
    ta_register_command("gzsetparams",gzsetparams_cmd);
    ta_register_command("gztell",gztell_cmd);
    ta_register_command("gzwrite",gzwrite_cmd);
    ta_register_command("inflate",inflate_cmd);
    ta_register_command("inflateEnd",inflateEnd_cmd);
    ta_register_command("inflateInit2_",inflateInit2__cmd);
    ta_register_command("inflateInit_",inflateInit__cmd);
    ta_register_command("inflateReset",inflateReset_cmd);
    ta_register_command("inflateSetDictionary",inflateSetDictionary_cmd);
    ta_register_command("inflateSync",inflateSync_cmd);
    ta_register_command("inflateSyncPoint",inflateSyncPoint_cmd);
    ta_register_command("uncompress",uncompress_cmd);
    ta_register_command("zError",zError_cmd);
    ta_register_command("zlibVersion",zlibVersion_cmd);

    //Utility cmds
    ta_register_command("ZLIB_VERSION",ZLIB_VERSION_cmd);
    ta_register_command("z_stream_size", z_stream_size_cmd);
}

