#include<iostream>
#include<exception>
#include<stdexcept>
using namespace std;

class ATM : public exception{
	public:
		
		const char* what() const noexcept override{
			return "Buahahhahahaha" ;
		}
};

int main(){
	
	int amount; 
	cin>>amount;
	try{
		if(amount == 0){
			throw ATM();
		}
	}
    catch(const ATM& e){
    	cout<<e.what();
	}
}