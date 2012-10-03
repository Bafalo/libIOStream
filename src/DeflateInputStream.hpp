
#ifndef DEFLATEINPUTSTREAM_HPP
#define DEFLATEINPUTSTREAM_HPP

#include <string>
#include <zlib.h>

#include "RawInputStream.hpp"
#include "Buffer.hpp"
#include "MaybePointer.hpp"

#ifndef ZLIB_H
typedef struct gzFile_s *gzFile;
#endif

namespace IOStream {

class DeflateInputStream : public RawInputStream {
public:
    DeflateInputStream(MaybePointer<RawInputStream> raw);
    ~DeflateInputStream();

    int fd();
    
    ssize_t read(void *bytes, size_t size);
    ssize_t peek(void *bytes, size_t size);
    void seek(size_t offset, int whence);
    void putBack();
    void close();
private:
    void init();
    void populateBuffer();

    z_stream zstream;
    Buffer buffer;
    MaybePointer<RawInputStream> raw;
};

}

#endif // DEFLATEOUTPUTSTREAM_HPP
