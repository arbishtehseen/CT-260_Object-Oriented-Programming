#include<iostream>
#include<string>
using namespace std;

class BankAccount{
	private:
		char* accountholder_name;
		int size;
		int account_number;
		double balance;
		
	public:
		BankAccount() :  account_number(0) ,
		                balance(0.0)
						{
							size = 1;
							accountholder_name = new char[size];
							accountholder_name[0] = '\0';
						}
        
        BankAccount(const char* name, int accnum , double b){
        	size = strlen(name); 
        	if(size != 0)
			{
				accountholder_name = new char[size+1]; 
				memcpy(accountholder_name , name , size+1);
			}
			
			if(accnum > 0)
			{
				account_number = accnum;
			}
			if(b > 0.0)
			{
				balance = b; 
			}
		}
		
		BankAccount(const BankAccount& other)
		{
			size = other.size;
			if(size != 0)
			{
				accountholder_name = new char[size+1];
				memcpy(accountholder_name , other.accountholder_name , size+1);
			}
			
			if(other.account_number > 1)
			{
				account_number = other.account_number;
			}
			if(other.balance > 0.0)
			{
				balance = other.balance;
			}
			
		}
		
		~BankAccount(){ delete[] accountholder_name;
		cout<<"Destructor Invoked"<<endl;}
		
		const char* getaccountholder_name() const{
			return accountholder_name;
		}
		
		int getaccountnumber() const{
			return account_number;
		}
		
		double getbalance() const{
			return balance;
		}
		
		void setbalance(double b){
			if(b > 0.0)
			{
				balance = b;
			}
			else{
				cout<<"[ERROR] : Invalid Balance Entered"<<endl;
			}
		}
		
		friend ostream& operator<<(ostream& stream, const BankAccount& temp);
	
};

ostream& operator<<(ostream& stream , const BankAccount& temp)
{
	stream <<" [Name] : "<<temp.accountholder_name<<endl;
	stream <<" [Account Number] : "<<temp.account_number <<endl;
	stream <<" [Balance] : "<<temp.balance << endl;
	
	return stream;
}



int main(){
	BankAccount obj1("Arbish" , 53, 78000);
	BankAccount obj2 = obj1;
	cout << obj1 <<endl;
	cout << obj2 <<endl;
	obj1.setbalance(-900);
	
	
	return 0;
}