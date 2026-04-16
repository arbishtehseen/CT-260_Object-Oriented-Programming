#include<iostream>
using namespace std;

void increement(int& value){
	value++;
}

int main(){
	
	int a = 5;  
	
	// creating refrence to variable a.
	// here & --> is part of variable declaration.
	// its part of the type.
	int& ref = a;
	increement(a);
	
	// ref doesnt actually exists it j exists in the source code
	cout<<a;
	
	// we j created an alias for a
	
	return 0; 
}