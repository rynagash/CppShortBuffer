#include "ShortBufferContainer.h"

ShortBufferContainer::ShortBufferContainer(int nb, int bs)
{
	currentBuffer = -1;
	numBuffers = nb;
	buffers = new ShortBuffer[numBuffers];
}
ShortBufferContainer::~ShortBufferContainer()
{
	delete [] buffers;
}
int ShortBufferContainer::getCurrentBufferIndex()
{
	return currentBuffer;
}
int ShortBufferContainer::getNumBuffers()
{
	return numBuffers;
}
ShortBuffer* ShortBufferContainer::getCurrentBuffer()
{
	return &buffers[currentBuffer];
}
bool ShortBufferContainer::addBuffer(const short* data, int length)
{
	currentBuffer = (currentBuffer + 1) % numBuffers;
	return buffers[currentBuffer].setBuffer(data, length);
}
