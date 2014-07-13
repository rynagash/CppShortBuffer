#include <iostream>
#include <cstring>

class ShortBuffer {
private:
	short* buffer;
	int capacity;
	int index;
public:
	ShortBuffer(int _bs = 1024)
	{
		buffer = NULL;
		index = -1;
		capacity = _bs;
		chageCapacitySize(capacity);
	}
	~ShortBuffer()
	{
		if (buffer != NULL) {
			delete [] buffer;
		}
	}
	void chageCapacitySize(int _bs)
	{
		capacity = _bs;
		if (buffer != NULL) {
			delete [] buffer;
		}
		buffer = new short[capacity];
	}
	bool setBuffer(const short* data, int size)
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
	int getIndex()
	{
		return index;
	}
	int getCapacity()
	{
		return capacity;
	}
	short* getBuffer()
	{
		return buffer;
	}
};
class CTest{
private:
	int currentBuffer;
	int numBuffers;
	ShortBuffer *buffers;
public:
	CTest(int nb = 2, int bs = 1024)
	{
		currentBuffer = -1;
		numBuffers = nb;
		buffers = new ShortBuffer[numBuffers];
	}
	~CTest()
	{
		delete [] buffers;
	}
	int getCurrentBufferIndex()
	{
		return currentBuffer;
	}
	int getNumBuffers()
	{
		return numBuffers;
	}
	ShortBuffer* getCurrentBuffer()
	{
		return &buffers[currentBuffer];
	}
	bool addBuffer(const short* data, int length)
	{
		currentBuffer = (currentBuffer + 1) % numBuffers;
		return buffers[currentBuffer].setBuffer(data, length);
	}
};

int main(void){
	short data[1024];
	for(int i=0; i<1024; i++){
		data[i] = i;
	}
	
	CTest ct(2);
	ct.addBuffer(data, 122);
	std::cout << ct.getCurrentBufferIndex() << ", " << ct.getCurrentBuffer()->getIndex() << std::endl;
	ct.addBuffer(data, 200);
	std::cout << ct.getCurrentBufferIndex() << ", " << ct.getCurrentBuffer()->getIndex() << std::endl;
	ct.addBuffer(data, 300);
	std::cout << ct.getCurrentBufferIndex() << ", " << ct.getCurrentBuffer()->getIndex() << std::endl;
	ct.addBuffer(data, 1024);
	std::cout << ct.getCurrentBufferIndex() << ", " << ct.getCurrentBuffer()->getIndex() << std::endl;
	
	
	
	return 0;
}
