#include<iostream>
#include<string>
using namespace std;

class Project;

class Engineer{
	
	public:
		void checkbudget(Project &p);
};

class Project{
	private:
		int budget;
		string projectid;
		
	public:
		Project() : budget(0) , projectid("N/A"){}
		Project(int budget, string projectid){
			this->budget = budget;
			this->projectid = projectid;
		}
		friend void Engineer::checkbudget(Project &p);
};

void Engineer::checkbudget(Project &p){
	cout<<p.budget<<endl;
}

int main(){
	Engineer e; 
	Project p(1000000 , "Draft Project"); 
	e.checkbudget(p);
	
	return 0;
}