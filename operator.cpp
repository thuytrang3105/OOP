#include <iostream>
using namespace std;
class Fraction{
	int nu,de;
public:
	Fraction(){
		
	}
	Fraction(int a,int b){
		this->nu=a;
		this->de=b;
	}
	void display(){
		cout<<nu<<"/"<<de<<endl;
	}
	friend Fraction operator *(Fraction a,Fraction b);
	friend bool  operator >(Fraction a,Fraction b);
	friend Fraction operator -(Fraction a,int b);	
}; 
Fraction operator *(Fraction a,Fraction b){
	a.nu=a.nu*b.nu;
	a.de=a.de*b.de;
	return a;
}
bool operator >(Fraction a,Fraction b){
	return a.nu*b.de>b.nu*a.de ;
}
Fraction operator -(Fraction a,int b){
	a.nu=a.nu-b*a.de;
	return a;
}
main(){
	Fraction a(1,2);
	Fraction b(3,4);
	Fraction c=a*b;
	c.display();
	Fraction d=a-3;
	d.display();
	if(a>b) cout<<"true";
	else cout<<"false";
	cout<<(a>b); 
}


