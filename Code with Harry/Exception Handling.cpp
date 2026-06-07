#include<iostream>
#include<string>
using namespace std;

/*
- an exception is an unexpected problem that arises during the execution
of a program our program terminates suddenly with some errors/issues.
Exception occurs during the running of the program.

The try keyword represents a block of code that may throw an exception 
places inside the try block. It's followed by one
or more catch blocks. If an exception occurs, try block throws that 
exception.

The catch statement represents a block of code that is executed when a 
particular exception is thrown from the try block.
The code to handle the exception is written inside the catch block.

An exception in C++ can be thrown using throw keyword.
When a program encounters a throw statement, then it immediately
terminates teh current function and starts finding a matching
catch block to handle the thrown exception.
*/

class Customer{
	private:
		string name;
		double balance;
		int accountnum;
	public:
		Customer(string n, double b, int an) : name(n) , balance(b) , accountnum(an){}
		
		void deposit(double am){
			
			if(am > 0){
				cout<<am<<" deposited successfully!"<<endl;
			}
			else{
				throw "Amount is less than 0.";
			}
		}
		
		void withdraw(double am){
			if(am >= 0 && am <= balance){
				cout<<am<<" withdrawed successfully!"<<endl;
			}
			else if(am < 0){
				throw "Amount is less than 0.";
			}
			else{
				throw "Insufficinet Balance";
			}
		}	
};

int main(){
	Customer C1("Arbish" , 9800, 10);
	try{
	C1.deposit(900);
	C1.withdraw(12000);
    }
    catch(const char* e){
    	cout<<"[ERROR] : "<<e<<endl;
	}
	
	return 0;
}