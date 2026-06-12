#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Person{
	protected:
		string name;
		string CNIC;
		int age;
		string gender;
	
	public:
		Person(){}
		Person(string n, string NIC, int a, string gen)
		{
			name = n;
			CNIC = NIC;
			age = a;
			gender = gen;
		}
		
	    string getname() const { return name;}
	    string getCNIC() const { return CNIC;}
	    int getage() const { return age;}
		string getgender()	 const { return gender;}
		
		void printinfo() const{
			cout<<"[Name] : "<<name<<endl;
			cout<<"[CNIC Number] : "<<CNIC<<endl;
			cout<<"[Age] : "<<age<<endl;
			cout<<"[Gender] : "<<gender<<endl;
		}
		virtual ~Person(){}
};

class Doctor : virtual public Person{
	private:
		string specialisation;
		int licensenumber;
		double consultationfee;
		
	public:
		Doctor(string n, string nic, int a, string gen, string spec, int ln , double fee) :
			Person(n , nic, a , gen){
				specialisation = spec;
				licensenumber = ln;
				consultationfee = fee;
			}
			
		string getspecialisation() const { return specialisation;}
		int getlicensenumber() const{ return licensenumber;}
		double getconsultationfee() const{ return consultationfee;}
		
		void printinfo() const{
			cout<<"[Doctor Name] : "<<name<<endl;
			cout<<"[CNIC Number] : "<<CNIC<<endl;
			cout<<"[Age] : "<<age<<endl;
			cout<<"[Gender] : "<<gender<<endl;
			cout<<"[Specialisation] : "<<specialisation<<endl;
			cout<<"[License Number] : "<<licensenumber<<endl;
			cout<<"[Consultation Fee] : "<<consultationfee<<endl;
		}
};

class Patient : virtual public Person{
	private:
		int medrecordnum;
		string date;
	public:
		Patient(string n, string nic, int a, string gen, int recordnum, string d ) :
			Person(n , nic, a , gen){
				medrecordnum = recordnum;
				date = d;
			}
			int getrecordnum() const{ return medrecordnum;}
			string getdate() const{ return date;}
			
			void printinfo() const{
			cout<<"[Patient Name] : "<<name<<endl;
			cout<<"[CNIC Number] : "<<CNIC<<endl;
			cout<<"[Age] : "<<age<<endl;
			cout<<"[Gender] : "<<gender<<endl;
			cout<<"[Medical Record Number] : "<<medrecordnum<<endl;
			cout<<"[Date] : "<<date<<endl;
		}
};

class DoctorPatient : public Doctor, public Patient{
	private:
		string person;
	public:
		DoctorPatient(string n, string nic, int a, string gen,string spec, int ln , double fee,
		 int recordnum, string d, string p) :
				Person(n , nic, a , gen) , 
				Doctor(n , nic, a , gen , spec, ln, fee) ,
				Patient(n , nic, a , gen , recordnum, d){
					person = p;
				}
		void printinfo() const{
			if (person == "doctor" ){
		    cout<<"[Doctor Name] : "<<name<<endl;
			cout<<"[CNIC Number] : "<<CNIC<<endl;
			cout<<"[Age] : "<<age<<endl;
			cout<<"[Gender] : "<<gender<<endl;
			cout<<"[Specialisation] : "<<getspecialisation()<<endl;
			cout<<"[License Number] : "<<getlicensenumber()<<endl;
			cout<<"[Consultation Fee] : "<<getconsultationfee()<<endl;
		}
		else if(person == "patient"){
			cout<<"[Patient Name] : "<<name<<endl;
			cout<<"[CNIC Number] : "<<CNIC<<endl;
			cout<<"[Age] : "<<age<<endl;
			cout<<"[Gender] : "<<gender<<endl;
			cout<<"[Medical Record Number] : "<<getrecordnum()<<endl;
			cout<<"[Date] : "<<getdate()<<endl;
		}
		else{
			cout<<"Invalid input"<<endl;
		}
		}
};

class Appointment{
	private:
		Doctor* dr;
		Patient* p;
	
	public:
		Appointment( Doctor* d,  Patient* pat){
			if(d->getCNIC() == pat->getCNIC()){
				cout<<"ERROR"<<endl;
				dr = nullptr;
				pat = nullptr;
			}
			else{
				dr = d;
				p = pat;
			}
		}
	
};

class Hospital{
	private:
		vector<Person*> person;
	
	public:
		
	    ~Hospital(){
	    	for(int i = 0 ; i < person.size(); i++){
	    		delete person[i]; // memory cleanup
			}
	    	person.clear();
		}
		
		void addperson(Person* p){
			person.push_back(p);
		}
		
		void removeperson(string cnic){

			for(auto it = person.begin(); it !=  person.end() ; ++it){
				if((*it)->getCNIC() == cnic){
					delete *it;  // memory freed
					person.erase(it);   // vector entry deleted(Dangling pointer prevented).
			}
		}
	}
};

int main(){
	Doctor dobj("Arbish" , "890890890890", 18, "female" , "Gynae" , 90890, 900.00); 
	dobj.printinfo();
	
	
	return 0;
}
