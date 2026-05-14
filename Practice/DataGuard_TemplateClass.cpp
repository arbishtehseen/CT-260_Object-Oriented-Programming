#include<iostream>
#include<string>
using namespace std;

template<typename T>
class DataGuard{
	private:
		T value;
	public:
		DataGuard(T value) : value(value){}
		void Process() const{
			cout<<"Processing the Value...."<<value<<endl;
		}
};

template<typename T>
class DataGuard<T*>{
	private:
		T* value;
	public:
		DataGuard(T* value) : value(value){}
		void Process() const{
			if(!(*value)){
				cout<<"Processing the value...."<<*value<<" at address..."<<value<<endl;
			}
			else{
				cout<<"Invalid data"<<endl;
			}
		}
		void doublee(T* value){
			(*value)*=2;
			cout<<"Updated Value : "<<*value<<endl;
		}
};

template<>
class DataGuard<string>{
	private:
		string value;
	public:
		DataGuard(string value) : value(value){}
		void getlength() const{
			cout<<value.length()<<endl;
		}
		void uppercase() {
			for(int i = 0 ; i < value.length() ; i++){
				if(value[i] >= 'a' && value[i] <= 'z'){
			    value[i] = value[i] - 32;
			}
    	}
			cout<<value<<endl;
	}
};

int main(){
	DataGuard<int> o1(4);
	DataGuard<char> o2('&');
	DataGuard<float> o3(8.9);
	DataGuard<string> o4("arbish");
	int a = 45;
	DataGuard<int*> o5(&a);
	int b;
	DataGuard<int*> o6(&b);
	
	o4.getlength();
	o4.uppercase();
	o1.Process();
	o2.Process();
	o3.Process();
	o5.Process();
	o6.Process();
	o5.doublee(&a);

	return 0;
}