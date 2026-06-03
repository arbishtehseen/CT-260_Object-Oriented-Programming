#include<iostream>
#include<exception>
using namespace std;

class InsufficientFundsexception : public exception{
	private: 
	string fullmessage;
	double available;
	double requested;
	
	public:
		InsufficientFundsexception(double avail, double req){
			requested = req;
			available = avail;
			
			fullmessage = "Pagal h";
		}
		
		const char* what() const noexcept override{
			return fullmessage.c_str();
		}
		
		double getavailable() const{ return available;}
		double getrequested() const{ return requested;}
};

int main(){
    double a = 900;
    double b = 90000;
	
	try{
		if(a < b){
			throw InsufficientFundsexception(a , b);
		}
	}
	catch(const InsufficientFundsexception& e){
		cout<<e.what();
	}
}