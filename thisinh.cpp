#include <iostream>
#include <fstream>
using namespace std;
class ThiSinh{
	string id;
	string ten;
	double diem1;
	double diem2;
	double diem3;
	public:
		ThiSinh(){}
		ThiSinh(string i, string t, double d1, double d2, double d3){
			id= i;
			ten = t;
			diem1= d1;
			diem2= d2;
			diem3 = d3;
		}
		void xem(){
			cout<<"id: "<<id<<"\tten: "<<ten<<"\n\tToan: "<<diem1<<"\tLy: "<<diem2<<"\tHoa: "<<diem3<<endl;
		}
		void nhap(){
			cout<<"Nhap id: "; cin>>id;
			cout<<"Nhap ten: "; cin>>ten;
			cout<<"Nhap diem1: "; cin>>diem1;
			cout<<"Nhap diem2: "; cin>>diem2;
			cout<<"Nhap diem3: "; cin>>diem3;
		}
		double tong(){
			return diem1 + diem2 + diem3;
		}
		string getName() {	return ten;	}
		string getId(){		return id;	}
		double getDiem1(){	return diem1;	}
		double getDiem2(){	return diem2; }
		double getDiem3(){	return diem3;	}
		
};

class DSThiSinh{
	ThiSinh *ts;
	int len;
	public:
		void docDS(){
			ifstream fi("abc.txt");
			fi>>len;
			ts = new ThiSinh[len];
			for(int i=0; i<len; i++){
				string id;
				string ten;
				double diem1;
				double diem2;
				double diem3;
				fi>>id;
				fi>>ten;
				fi>>diem1;
				fi>>diem2;
				fi>>diem3;
				ts[i] = ThiSinh(id, ten, diem1, diem2, diem3);
			}
		}
		void xemTatCa(){
			for(int i=0; i<len; i++){
				ts[i].xem();
			}	
		}
		void them(){
			len++;
			ThiSinh *tam = new ThiSinh[len];
			for(int i=0; i<len-1; i++){
				tam[i]= ts[i];
			}
			tam[len-1].nhap();
			ts= tam;
		}
		void sapXep(){
			for(int i=0; i<len-1; i++){
				for(int j=i+1; j<len; j++){
					if(ts[i].tong() < ts[j].tong()){
						ThiSinh tam = ts[i];
						ts[i] = ts[j];
						ts[j]= tam;
					}
				}
			}
		}
		void outdata(){
			ofstream of("out_data.txt");
			for(int i=0; i<len; i++){
				of<<"\nId :"<<ts[i].getId();
				of<<"\tTen :"<<ts[i].getName();
				of<<"\n\tDiem 1: "<<ts[i].getDiem1();
				of<<"\n\tDiem 2: "<<ts[i].getDiem2();
				of<<"\n\tDiem 3: "<<ts[i].getDiem3();
			}
		}
};
main(){
	DSThiSinh ds;
	do{
		cout<<"\nLUA CHON :";
		cout<<"\n1.doc danh sach ";
		cout<<"\n2.them 1 thi sinh ";
		cout<<"\n3.sap xep danh sach ";
		cout<<"\n4.xem danh sach ";
		cout<<"\n5.luu vao file - out_data - "; 
		cout<<"\nkhac.thoat ";
		int loai;
		cout<<"\n->";cin>>loai;
		if (loai==1)	ds.docDS();
		else if (loai==2)	ds.them();
			else if (loai==3)	ds.sapXep();
			else if (loai==4)	ds.xemTatCa();
				else if (loai==5)	ds.outdata();
					else break;
	}while (1);
}
