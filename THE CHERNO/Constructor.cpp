#include<iostream>
using namespace std;

class Entity{
	
	public:
	float X , Y;
	
	Entity(){}
	Entity(float x, float y)
	{
		X = x;
		Y = y;
	}
	
			
	void display()
	{
		cout<<X<<" , "<<Y<<endl;
	}
};

int main(){
	Entity e(5.0f , 10.0f);
	e.display();
	
	return 0;
}