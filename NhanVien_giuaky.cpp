#include <iostream>
#include <bits/stdc++.h > 
using namespace std;
class NhanVien{
	protected:
		string ten;
		int nam;
	public:
		NhanVien(){}
		NhanVien(string t, int n){
			ten = t;
			nam = n;
		}
		virtual void nhap(){
			cout<<"Ten: ";cin>>ten;
			cout<<"Nam: ";cin>>nam;
		}
		virtual void xuat(){
			cout<<"Ten: "<<ten<<"\t\t";
			cout<<"Nam: "<<nam<<"\t\t";
		}
		virtual int tinhLuong(){
			
		}
		
		friend bool operator >( NhanVien a,int x);
};
bool operator > (NhanVien a ,int x){
			return a.nam>x ;
		}
class NVPhucVu: public NhanVien{
	int ngayCong;
	public:
		NVPhucVu(){}
		NVPhucVu(string t, int n, int nc):NhanVien(t, n){
			ngayCong = nc;
		}
		void nhap(){
			NhanVien::nhap();
			cout<<"Ngay Cong: ";cin>>ngayCong;
		}
		void xuat(){
			NhanVien::xuat();
			cout<<"Ngay Cong: "<<ngayCong;
			cout<<"\t\tTien luong: "<<tinhLuong()<<endl;
		}
		int tinhLuong(){
			return ngayCong*300000+ ngayCong>24?1000000:0;
		}
};

class NVQLDA: public NhanVien{
	int soDA;
	public:
		NVQLDA(){}
		NVQLDA(string t, int n, int nc):NhanVien(t, n){
			soDA = nc;
		}
		void nhap(){
			NhanVien::nhap();
			cout<<"So du an: ";cin>>soDA;
		}
		void xuat(){
			NhanVien::xuat();
			cout<<"So du an: "<<soDA;
			cout<<"\t\tTien luong: "<<tinhLuong()<<endl;
		}
		int tinhLuong(){
			return soDA>2?20000000:15000000;
		}
};
class ListNV{
	NhanVien ** nv;
	int len;
	public:
		ListNV(){
			len = 0;
			nv = new NhanVien*[0];
		}
		nhap(){
			cout<<"Nhap so luong Nhan Vien: ";cin>>len;
			nv=new NhanVien*[len];
			for (int i=0;i<len;i++){
				int loai;
				cout<<"Ban muon nhap nhan vien gi? (1: Phuc vu, 2: Quan ly): ";
				cin>>loai;
				if(loai==1)
					nv[i] = new NVPhucVu();
				else if(loai==2)
					nv[i] = new NVQLDA();
				nv[i]->nhap();
			}
		}
		xuat(){
			for(int i=0; i<len; i++)
				nv[i]->xuat();
		}
		tong_luong(){
			long tong=0;
			for(int i=0; i<len; i++)
				tong+=nv[i]->tinhLuong();
			cout<<"Tong luong = "<<tong;
		}
		Xuat_Nv_tham_nien(){
			for(int i=0; i<len; i++)
				if ( nv[i] > 10 ) nv[i]->xuat();
		}
}; 
main(){
	ListNV l;
	l.nhap();
	l.xuat();
	l.tong_luong();
}
