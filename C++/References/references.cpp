#include <iostream>
#include <string>

using namespace std;

int x = 20;

void swap(int& first, int& second){
	int temp = first;
	first = second;
	second = temp;
}

/*
The function returns a reference to the value x. 
In the main function we are changing this reference value to something else.
So from now on, this value only will be updated.
*/
int& func(){
	return x;
}

void swap_str(string &str1, string &str2){
	string temp;
	temp = str1;
	str1 = str2;
	str2 = temp;
}

int main(){
	int a=2, b=3;
	string s = "hello";
	string s1 = "world";
	swap(a, b);
	cout<<"A = "<<a<<" B = "<<b<<endl;
	cout<<"\nTesting References"<<endl;
	cout<<"x = "<<x<<endl;
	func() = 30;
	cout<<"Now x = "<<x<<endl;
	cout<<"s = "<<s<<" s1 = "<<s1<<endl;
	swap_str(s, s1);
	cout<<"s = "<<s<<" s1 = "<<s1<<endl;
	return 0;
}
