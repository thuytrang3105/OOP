#include<iostream>
using namespace std;
class IntArr{
	int arr[100];
	int len;
	public :
		IntArr (int a[],int n){
			this->len=n;
			for (int i=0;i<len;i++)
				this->arr[i]=a[i];
		}
		IntArr(){
			
		}
		void display(){
			for (int i=0;i<len;i++)
				cout<<arr[i]<<" ";
			cout<<endl;
		}

		friend IntArr operator+=(IntArr a,IntArr b);
};

//noi 2 mang 
IntArr operator+=(IntArr a,IntArr b){ 
	for (int i=0;i<a.len+b.len;i++)
		if (a.len>i) a.arr[i]=a.arr[i];
		else a.arr[i]=b.arr[i-a.len];
		a.len=a.len+b.len;
	return a;
}
main(){
	int x[]={1,2,3,4,5,6,7},y[]={5,2,3,7,8,4};
	IntArr a(x,7);
	IntArr b(y,6);
	IntArr c=a+b;
	c.display();

}
