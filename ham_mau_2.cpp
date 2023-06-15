#include <iostream>
#include <vector>
using namespace std;
class Phanso{
	int tu,mau;
	public:
		Phanso (int t,int m){
			this->tu=t;
			this->mau=m;
		}
		friend ostream& operator <<(ostream&,Phanso);
};
ostream& operator <<(ostream& os,Phanso x){
	os<<x.tu<<"/"<<x.mau;
}
void VD1(){
	vector <int> vt;
	vt.push_back(5);
	vt.push_back(3);
	vt.push_back(15);
	
	vt.pop_back();
	for (int i=0;i<vt.size();i++)
		cout<<vt[i]<<"\t";
}
void VD2(){
	vector <Phanso> vt;
	vt.push_back(Phanso(3,5));
	vt.push_back(Phanso(4,5));
	vt.push_back(Phanso(2,5));
	
	vt.pop_back();
	for (int i=0;i<vt.size();i++)
		cout<<vt[i]<<"\t";
}
main(){
//	VD1();
	VD2();
} 
