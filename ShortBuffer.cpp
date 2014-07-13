#include "ShourtBuffer.h"

ShortBuffer::ShortBuffer(int _bs = 1024)
{
	buffer = NULL;
	index = -1;
	capacity = _bs;
	chageCapacitySize(capacity);
}
ShortBuffer::~ShortBuffer()
{
	if (buffer != NULL) {
		delete [] buffer;
	}
}
void ShortBuffer::chageCapacitySize(int _bs)
{
	capacity = _bs;
	if (buffer != NULL) {
		delete [] buffer;
	}
	buffer = new short[capacity];
}
bool ShortBuffer::setBuffer(const short* data, int size)
{
	if (size <= capacity && buffer != NULL) {
		index = size;
		memcpy(buffer, data, size * sizeof(short));
		return true;
	} else {
		index = -1;
		return false;
	}
}
int ShortBuffer::getIndex()
{
	return index;
}
int ShortBuffer::getCapacity()
{
	return capacity;
}
short* ShortBuffer::getBuffer()
{
	return buffer;
}
