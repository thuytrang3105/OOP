#include <bits/stdc++.h>
#include <cstring>
using namespace std;
class Student {
public: 
    string name;
    string id;
    double math,physics,chemistry;
    Student() {
        name = "";
        id = "";
        math = 0;
	physics =0; 
	chemistry =0; 
    }
    Student(string n, string id, double math,double physics, double chemistry ) {
        this->name = n;
        this->id = id;
        this->math = math;
	this->physics=physics;
	this->chemistry=chemistry;
    }
    
    void input() {
    	cin.ignore() ;
        cout << "\tName = ";  //cin>>name;
        getline(cin,name); 
        cout << "\tID = ";
        cin >> id;
        cout << "\tNhap diem thanh phan cua " << name << ":\n";
        cout << "\t\tMath = ";
	cin >> math;
        cout << "\t\tPhysics = "; 
	cin >> physics;
        cout << "\t\tChemistry = "; 
	cin >> chemistry;
    }
    double average(){
    	return ( math+physics+chemistry)/3;
	}
    string getName() {
        return name;
    }
    string getId() {
        return id;
    }
    double getMath() {
        return math;
    }   
    double getPhysics() {
        return physics;
    }
    double getChemistry() {
        return chemistry;
	}
    friend bool operator > (Student a,Student b);
    friend bool operator == (Student a,Student b);
    friend ostream & operator << (ostream&,Student&);
    friend istream & operator >> (ostream&,Student&);
};
bool operator > (Student a,Student b){
	return a.average()>b.average();
}
bool operator == (Student a,Student b){
	return a.average()==b.average();
}
ostream & operator << (ostream& os ,Student& x){
	cout << endl << "Name: "<< x.getName();
    cout<< endl << "ID "<<x.getId();
    cout << endl << "\tMath "<< x.getMath();
    cout << endl << "\tPhysics "<< x.getPhysics();
    cout<< endl << "\tChemistry "<< x.getChemistry();
    cout<< endl;
}
istream & operator >> (istream& is ,Student& x){
	cin.ignore() ;
    cout << "\tName = ";  //cin>>name;
    getline(cin,x.name); 
    cout << "\tID = ";
    cin >> x.id;
    cout << "\tNhap diem thanh phan cua " << x.name << ":\n";
	cout << "\t\tMath = "; cin >> x.math;
    cout << "\t\tPhysics = "; cin >> x.physics;
    cout << "\t\tChemistry = "; cin >> x.chemistry;
    return is; 
}
class StudentList {
    Student** students;
    int len;
public:
    StudentList() {
        len = 0;
    }   
    void inputList() {
        cout << "\nCo bao nhieu sinh vien: "; cin >> len;
        students = new Student*[len];
        for (int i = 0; i < len; i++) {
            cout << "Nhap thong tin sinh vien thu " << i+1 << ":\n";
            students[i] = new Student();
            students[i]->input();
        }
    }
    
    void printStudentsTranscript() {
    	cout<<endl;
        cout << setw(3) << "STT";
        cout << setw(12) << "Name";
        cout << setw(12) << "ID";
        cout << setw(7) << "Math";
        cout << setw(10) << "Physics";
        cout << setw(12) << "Chemistry";

        cout << endl;
    }
};
main(){
	cout<<"\nLUA CHON: ";
	cout<<"\n     1.Tao danh sach thi sinh va in ra danh sach";
	cout<<"\n     2.So sanh 2 thi sinh.";
	int loai;
	cout<<"\n ->";cin>>loai;
	if (loai==1){
		StudentList l;
		l.inputList();
		l.printStudentsTranscript();
	}
	else {
		Student s1;
		s1.input();
		Student s2;
		cin >> s2;
		if (s1>s2){
			cout<<endl<<s1.getName()<<" co diem cao hon "<<s2.getName();
			cout<<s1<<s2;	
		}
		else if (s1==s2){
				cout<<endl<<s1.getName()<<" co diem bang "<<s2.getName();
				cout<<s1<<s2 ;
		}else 
        	cout << endl << s2.getName() << " co diem cao hon " << s1.getName();
    }
	}

