#include <iostream>
using namespace std;
class Camera{
	string brand;
	int resolution;
public:
	Camera(string b){
		brand=b;
		resolution=360;
	}
	Camera(string b,int r){
		brand=b;
		resolution=r;
	}
	void display(){
		cout<<" Brand Camera :" <<brand<<endl; 
        cout << " Do phan giai: " << resolution << " MP " << endl;
    }
    void takephoto(){
		cout<<"take a photo "<<endl;
	}
};
class Phone{
	string brand;
	string screen;
public:
	Phone(string b){
		brand=b;
		screen="LED"; 
	}
	Phone(string b,string sc ){
		brand=b;
		screen=sc; 
	}
	void call(string number ){
		cout<<"call with "<<number<<endl;
	}
	void display(){
		 cout<<" Brand Phone :" <<brand<<endl; 
         cout << " Man hinh : " << screen << endl; 
     }
};

class CellPhone : public Phone , public Camera{
	string brand;
public:
	CellPhone(string brand,string cbrand,string pbrand):Phone(pbrand),Camera(cbrand){
		this->brand=brand;
	}
	CellPhone(string brand,string cbrand,int resolution ,string pbrand,string screen ) :Phone(pbrand,screen),Camera(cbrand,resolution){
		this->brand=brand;
	}
	void display(){
		cout<<"Thuong hieu dien thoai di dong : " << brand<<endl;
		Phone::display();
		Camera::display();
	}
};
int main(){
	CellPhone c("Samsung","Canon",480,"Viettel","LED");
	c.display();
	c.call("0923844224");
	c.takephoto();
	
	cout<<endl;
	CellPhone cp("Vivo","Dahua",480,"Vina","LCD");
	cp.display();  
	cp.call("0223844224");
	cp.takephoto();
	
	}
