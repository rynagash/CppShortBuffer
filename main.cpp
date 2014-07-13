#include <iostream>
#include "ShortBufferContainer.h"

int main(void){
	short data[1024];
	for(int i=0; i<1024; i++){
		data[i] = i;
	}
	
	ShortBufferContainer ct(2);
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
