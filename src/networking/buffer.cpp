#include "networking/buffer.h"

Buffer::Buffer(void *data_, uint64_t datalen_) : data(data_), datalen(datalen_), pos(0)
{
    //ctor
}
Buffer::~Buffer()
{
    std::free(data);
}

ReadBuffer::ReadBuffer(void *data_, uint64_t datalen_) : Buffer(data_, datalen_)
{
    //ctor
}
ReadBuffer::~ReadBuffer()
{
    //dtor
}

WriteBuffer::WriteBuffer() : Buffer(std::malloc(STARTING_SIZE), STARTING_SIZE)
{
    //ctor
}
WriteBuffer::~WriteBuffer()
{
    //dtor
}
void WriteBuffer::enlarge(uint64_t newsize)
{
    void *newdata = std::malloc(newsize);
    std::memcpy(newdata, data, datalen);
    std::free(data);
    data = newdata;
    datalen = newsize;
}
