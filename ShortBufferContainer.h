#ifndef ___SHORTBUFFERCONTAINER_H
#define ___SHORTBUFFERCONTAINER_H

#include "ShortBuffer.h"

class ShortBufferContainer{
private:
	int currentBuffer;
	int numBuffers;
	ShortBuffer *buffers;
public:
	ShortBufferContainer(int nb = 2, int bs = 1024);
	~ShortBufferContainer();
	int getCurrentBufferIndex();
	int getNumBuffers();
	ShortBuffer* getCurrentBuffer();
	bool addBuffer(const short* data, int length);
};
#endif
