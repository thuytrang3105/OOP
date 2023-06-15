#include <bits/stdc++.h>
#include <vector>
#include <list>
using namespace std;
void VD1(){
	vector<int> vt;
	vt.push_back(5);
	vt.push_back(15);
	vt.push_back(3);
	vt.push_back(21);
	vt.push_back(0);
	vector <int>::iterator ivt;
	ivt=vt.begin();
	cout<<*ivt<<"\t";
	ivt++;
	cout<<*ivt<<"\t";
	ivt--;
	cout<<*ivt<<"\t";
}
void VD2(){
	vector<int> vt;
	vt.push_back(5);
	vt.push_back(15);
	vt.push_back(3);
	vt.push_back(21);
	vt.push_back(0);
	int vtMax=0;
	for (int i=1;i<vt.size();i++)
		if (vt[vtMax]<vt[i])	vtMax=i;
	cout<<vt[vtMax]<<"\t";
	vector <int>::iterator ivt;
	ivt=vt.begin();
	int gtMax=*ivt;
	while (ivt <vt.end()){
		if (*ivt > gtMax)	gtMax=*ivt;
		ivt++;
	}
	cout<<gtMax<<"\t";
}
void VD3(){
	list<int> vt;
	vt.push_back(5);
	vt.push_back(15);
	vt.push_back(3);
	vt.push_back(21);
	vt.push_back(0);
	list <int>::iterator ivt=vt.begin();
	while (ivt != vt.end()){
		cout<<*ivt<<"\t";
		ivt++;
	}
}
void VD4(){
	vector<int> vt;
	vt.push_back(5);
	vt.push_back(15);
	vt.push_back(3);
	vt.push_back(21);
	vt.push_back(0);
	vt.push_back(7);
	vt.push_back(15);
	vt.push_back(33);
	vt.push_back(25);
	vt.push_back(89);
/*	for (int i=0;i<vt.size();i++){
		for (int j=i+1;j<vt.size();j++)
			if (vt[i] >vt[j]){
				swap(vt[i],vt[j]);
			}
	}
*/
	cout<<"\nVector: ";
	for (int i=0;i<vt.size();i++)
		cout<<vt[i]<<"\t";
	cout<<endl;
	vector <int>::iterator ivt=find(vt.begin(),vt.end(),21);// cho gia tri vi tri cua...
	cout<<"\nVi tri cua 21 la: "<<(ivt>=vt.end()?-1:ivt-vt.begin())<<endl;
	sort(vt.begin(),vt.end());						//sap xep;
	cout<<*max_element(vt.begin(),vt.end())<<endl;   //tim gia max;
	cout<<"\nVector: ";
	for (int i=0;i<vt.size();i++)
		cout<<vt[i]<<"\t";
}
main(){
//	VD1();	 //gioi thieu iterator
//	VD2();   //tim gia tri max
//	VD3();	 //thay vector = list
	VD4();
}
