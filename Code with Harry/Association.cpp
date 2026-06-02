#include<iostream>
#include<string>
using namespace std;

class Patient{
	private:
		char* pname;
		int age;
	
	public:
		Patient(const char* n, int a){
			int size = strlen(n);
			pname = new char[size+1];
			memcpy(pname, n , size+1);
			
			if(a > 0){
				age = a;
			}
		}
		
		const char* getpatientname() const {   return pname;	}
		int getage()  const  { return age; }
		
		~Patient(){
			delete[] pname;
		}
};

class Doctor{
	private:
		char* dname;
		
	public:
		Doctor(const char* n){
			int size = strlen(n);
			dname = new char[size+1];
			memcpy(dname, n , size+1);
		}
		
		void treat(Patient& p){
			cout<<dname<<" is treating "<<p.getpatientname()
			<<" "<<" who is "<<p.getage()<<" years old."<<endl;
		}
	
};

int main(){
	Patient p("Aisha" , 21);
	Doctor d("arbish");
	
	d.treat(p);
	
	return 0;
}