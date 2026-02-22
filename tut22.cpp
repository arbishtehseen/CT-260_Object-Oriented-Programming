

// OOP -- Classes and objects
	
	// C++ --> initially called --> C with classes by stroustroup
	// class --> extension of structures (in C)
	// structures had limitations
	//        - members are public
	//        - No methods
	// Classes --> structures + more
	// Classes --> can have methods and properties(methods)
	// Classes --> can make few members as private & few as public
	// Classes --> have variables and methods
	// Structures in C++ are typedef. 
	// you can declare objects along with class declaration like this
	/*      
	     class Employee {
	                  //Class Definition
	           } harry , rohan , lovish; 
  */
  // harry.salary = 8 ,makes no sense if salary is private.
  
#include<iostream>   
#include<string>
#include<cstring>
using namespace std;

class binary{
	// By Deafult everything is private in class.
	
	string s ; 
	
	public: 
	   void read(void);
	   void check_binary(void); 
	   void ones(void); 
	   	
};

void binary :: read(void) {
	   
	   cout<<"Enter a Binary Number : "<<endl;
	   cin>>s; 
	   
}
void binary :: check_binary(void){
	
	for(int i = 0 ; i < s.length() ; i++ ){
		
		if(s.at(i) !=  '0' && s.at(i) != '1'){
			cout<<"INCORRECT BINARY FORMAT!!!!"<<endl;
			exit(0);   
		}
		
	}
	
}

void binary :: ones(void){
	
	for(int i = 0 ; i < s.length() ; i++){
		
		if (s.at(i) == '1'){
			s.at(i) = '0'; 
		}
		else if ( s.at(i) == '0'){
			s.at(i) = '1'; 
		}
		else {
			cout<<"INCORRECT BINARY FORMAT!!"<<endl;
		}
	}
	
	cout<<"Result : "<<s<<endl;
	
}


int main (){

	binary b;
	b.read();
	b.check_binary(); 
	b.ones();
	
	return 0; 
}