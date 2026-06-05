#include<iostream>
#include<stdexcept>
using namespace std;

int main(){
	
	try{
	int *p = new int[100000000000];
	cout<<"Memory Allocated Successfully!"<<endl;
	delete[] p;
	}
	catch(const exception &e){
		cout<<"[ERROR OCCURED] : "<<e.what()<<endl;
	}
	
	return 0;
}