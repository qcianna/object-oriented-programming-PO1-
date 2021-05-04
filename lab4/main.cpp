#include "func.h"
#include <iostream>

int main(){

	int data1[] = {1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1};
	int data2[] = {1, 0, 1, 0, 1, 0, 1, 0, 1, 1};

	Bits bits1;
	set(&bits1, data1, sizeof(data1)/sizeof(data1[0]) );
	Bits bits2;
	set(&bits2, data2, sizeof(data2)/sizeof(data2[0]) );
	print(&bits1);
	std::cout << "  ";
	print(&bits2);

	const Bits bits3 = add_up(&bits1, &bits2);

	std::cout << "summed: " << std::endl;
	print(&bits3);
	
	int mask_data[] = {1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1};
	Bits mask;
	set(&mask, mask_data, sizeof(mask_data)/sizeof(mask_data[0]) );

	bit_and(&bits1, &mask);
	std::cout << "after and: " << std::endl;
	print(&bits1);

	bit_xor(&bits1, &mask);
	std::cout << "after xor: " << std::endl;
	print(&bits1);

	const Bits bits4 = add_up(&bits1, &bits2);
	std::cout << "summed again: " << std::endl;
	print(&bits4);

	std::cout << to_decimal(&bits1) << " + " << to_decimal(&bits2) << " = ";
	std::cout << to_decimal(&bits4) << std::endl;
}


/* //Output:

110011101111

  1010101011

summed: 
111110011010

after and: 
110010101101

after xor: 
001100010000

summed again: 
010110111011

784 + 683 = 1467
*/
