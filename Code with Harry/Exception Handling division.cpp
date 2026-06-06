#include<iostream>
#include<stdexcept>
using namespace std;

int main(){
	
	int a , b;
	
	cin>>a>>b; 
	try{
		if(b != 0){
	       int c = a/b; 
	        cout<<c<<endl;
	   }
	   else{
	   	throw "b shouldn't be equal to 0.";
	   }
    }
    catch(const char* message){
    	cout<<"[Exception Occured] : "<<message<<endl;
}
	return 0;
}