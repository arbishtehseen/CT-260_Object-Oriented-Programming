#include<iostream>
using namespace std;

template<typename T, typename U , typename op>
auto calculate(T val1, U val2, op operatorr){
	
	if(operatorr == '+'){
		return val1 + val2;
	}
	else if(operatorr == '-'){
		return val1 - val2;
	}
	else if(operatorr == '*'){
		return val1 * val2;
	}
	else if(operatorr == '/'){
		if(val2 != 0){
			return val1 / val2;
		}
		else{
			cout<<"denomiantor cannot be zero!"<<endl;
			return 0;
		}
	}
	else{
		cout<<"Invalid Operator type!"<<endl;
		return 0;
	}
}

int main(){
	auto result1 = calculate(3 , 3 , '+');
	auto result2 = calculate(9 , 3 , '-');
	auto result3 = calculate(3 , 3 , '*');
	auto result4 = calculate(9 , 3 , '/');
	auto result5 = calculate(9 , 0 , '/');
	
	cout<<result1<<endl;
	cout<<result2<<endl;
	cout<<result3<<endl;
	cout<<result4<<endl;
	cout<<result5<<endl;
	
	return 0;
}