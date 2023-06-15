#include <bits/stdc++.h>
#include <fstream>
#include <vector>
using namespace std;
class Sinhvien{
	public:
	string ten;
	double tb;
		Sinhvien(){
			
		}
		Sinhvien (string t,double d){
			ten=t;
			tb=d;
		}
		print (){
			cout<<"ten: "<<ten<<"\tDiem: "<<tb;
		}
		string getTen(){
			return ten;
		}
		double getDiem(){
			return tb;
		}
		friend istream& operator >>(istream& , Sinhvien x);
		friend ostream& operator <<(ostream& , Sinhvien x);	 
};
istream& operator >>(istream& is, Sinhvien& x){
	cout<<"Nhap ten: "; is>>x.ten;
	cout<<"Nhap diem: ";is>>x.tb;
	return is;
}
ostream& operator <<(ostream& os, Sinhvien x){
	os<<"Nhap ten: "<<x.getTen();
	os<<"Nhap diem: "<<x.getDiem();
	return os;
}
template <typename T>
class Myvector{
	int len;
	T*arr;
	public:
		Myvector(){
			len=0;
			arr=new T[0];
		}
		push_back(T x){
			len++;
			//tao mang moi co chieu dai lon hon mang cu 1 don vi 
			T *tam=new T[len];
			//chep mang cu qua mang moi  
			for (int i=0;i<len-1;i++)
				tam[i]=arr[i];
			//them phan tu x vao mang moi 
			tam[len-1]=x;
			//gan mang cu bang mang moi 
			arr=tam; 
		} 
		display(){
			for (int i=0;i<len;i++){
				cout<<arr[i]<<"\t"; 
			} 
		} 
		T& operator  [] ( int x){
			return arr[x];
		}
		setAt(int index, T x){
			if (x=="")
				cout<<"\nTHONG BAO\n";
			else
				arr[index]=x;
		}
};
void T1(){
	vector<Sinhvien> vt;
	vt.push_back(Sinhvien("trang",9.8));
	vt.push_back(Sinhvien("tuan",8.9));
	vt.push_back(Sinhvien("vu",8));
	vt.push_back(Sinhvien("quy",7));
	vt.push_back(Sinhvien("trang",9));
	
	vt[0].print();cout<<endl;
	vt[1].print();cout<<endl;
	vt[2].print();cout<<endl;
	vt[3].print();cout<<endl;
	vt[4].print();cout<<endl;
}
void T2(){
	Myvector<string> my;
	my.push_back("trang") ;
	my.push_back("tuan") ;
	my.push_back("thanh") ;
	my[1] = "vu";
	my.display(); 
} 
void T3(){
	Myvector <Sinhvien> my;
	my.push_back(Sinhvien("trang",9));
	my.push_back(Sinhvien());
	cin>>my[1];
	cout<<my[1];
	my.display();
    
}
main(){
//	T1();
//	T2(); 
	T3();

}
