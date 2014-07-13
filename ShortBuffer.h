#ifndef ___SHORTBUFFER_H
#define ___SHORTBUFFER_H

#include <cstring>

class ShortBuffer {
private:
	short* buffer;
	int capacity;
	int index;
public:
	ShortBuffer(int _bs = 1024);
	~ShortBuffer();
	void chageCapacitySize(int _bs);
	bool setBuffer(const short* data, int size);
	int getIndex();
	int getCapacity();
	short* getBuffer();
};

#endif
