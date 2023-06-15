#include <iostream>
using namespace std;
class Employee{
	string name;
	int salary;
	public:
		void setDetails(string n,int s){
			name=n;
			salary=s;
		}
		string getName(){
			return name;
		}
		void pay(){
			cout<<"\nDa tra cho anh/chi "<<name<<" tien luong la "<<salary;
		}
}; 
class Worker: public Employee{
// Private:
//		int level;
	public:
		int level;
		void setlevel(int l){
			level=l;
		}
		int getlevel(){
			return level;
		}
		void dowork(){
			cout<<"\n\tNhan vien "<<getName()<<" co level "<<level<<" dang don phong";
		}
		
};
class Manager: public Employee{
	public:
		int dept;
		void setdept(int d){
			dept=d;
		}
		int getdept(){
			return dept;
		}
		void manage(){
			cout<<"\n\tNhan vien "<<getName()<<" co dept "<<dept<<" dang quan li nhan su";
		}
}; 
class Director: public Employee{
	public:
		void makePlan(){
			cout<<"\nDirector "<<getName()<<" dang lam du an";
		}
}; 
main(){
	cout<<"All WORKER "<<endl ;
	Worker w;
	w.setDetails("hung",20000000);
	w.pay();
	w.dowork();
	cout<<endl<<w.level;
	Worker u;
	u.setDetails("linh",25000000);
	u.setlevel(4);
	u.pay();
	u.dowork();
	cout<<endl<<u.level;
	Worker v;
	v.setDetails("thuyen",30000000);
	v.setlevel(2);
	v.pay();
	v.dowork();
	cout<<endl<<v.level;
	Manager m;
	m.setDetails("hoang",3000000);
	m.pay();
	m.manage();
	cout<<endl<<m.dept;
	Manager n;
	n.setDetails("huong",10000000);
	n.setdept(2);
	n.pay();
	n.manage();
	cout<<endl<<n.dept;
	Director d;
	d.setDetails("Trang",1000000000);
	d.pay();
	d.makePlan(); 
}
