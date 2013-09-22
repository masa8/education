#include <stdio.h>
#include <iostream>
#include <bitset>
/*!  Confirm the bits pattern of type float. */
class Data {
	union 
	{
		float input;
		int   output;
	} _data;
	public:
	void set(float f){ 
		_data.input = f;
	}
	void disp() { 
		std::bitset<32> bits(_data.output);
		std::cout << _data.input << ":\t" << 
			bits[31] << 
			" " <<
			bits[30] <<
			bits[29] <<
			bits[28] <<
			bits[27] <<
			bits[26] <<
			bits[25] <<
			bits[24] <<
			bits[23] <<
			" (1) " <<  
			bits[22] <<
			bits[21] <<
			bits[20] <<
			bits[19] <<
			bits[18] <<
			bits[17] <<
			bits[16] <<
			bits[15] <<
			bits[14] <<
			bits[13] <<
			bits[12] <<
			bits[11] <<
			bits[10] <<
			bits[9] <<
			bits[8] <<
			bits[7] <<
			bits[6] <<
			bits[5] <<
			bits[4] <<
			bits[3] <<
			bits[2] <<
			bits[1] <<
			bits[0] <<
			std::endl;
	}
			 
};

int main() {

	Data data;	
	data.set(1);
	data.disp();
        
        data.set(0);
	data.disp();

	data.set(2);
	data.disp();

 	data.set(3);
	data.disp();	
	
	data.set(4);
	data.disp();
	
	data.set(5);
	data.disp();

	data.set(10);
	data.disp();




}

