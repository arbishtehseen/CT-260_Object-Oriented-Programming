#include<iostream>
#include<string>
using namespace std;


class Vector2{
	public:
		float x , y;
};


int main(){
	// stack
	/* here the actual memory is being copied, and later on if
	 b is changed a is not affected at all. */
	 
	Vector2 a = {2.3 , 3.3};
	Vector2 b = a; 
	b.x = 5.5;
	
	//heap
	/* here , address at which the actual memory is present is being
	copied, meaning if b is modified then a too is affected. */
	
	Vector2 *h_a = new Vector2;
	*h_a = {8.9 , 7.7}; 
	Vector2 *h_b = new Vector2;
	*h_b = *h_a;
	
	/* or
	Vector2 *h_a = new Vector2;
	Vector2* h_b = a; 
	*/

	
	return 0;
}