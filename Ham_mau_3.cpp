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
		insert(int index, T x){
			len++;
			T *tam=new T[len];
			//chep mang cu qua mang moi  
			for (int i=0;i<index-1;i++)
				tam[i]=arr[i];
			for (int i=index;i<len;i++)
				tam[i]=arr[i-1];
			//them phan tu x vao mang moi 
			tam[index]=x;
			//gan mang cu bang mang moi 
			arr=tam; 
		}
		xoa(int index,T x){
			len--;
			T *tam=new T[len]; 
			for (int i=0;i<index-1;i++)
				tam[i]=arr[i];
			for (int i=index;i<len;i++)
				tam[i]=arr[i+1];  
			arr=tam; 
		}
};
main()
{
	Myvector<int > vt;
	vt.push_back(7);
	vt.push_back(13);
	vt.push_back(22);
	vt.push_back(5);
	vt.push_back(39);
	vt.display();
	vt.insert(3,100);
	vt.display();
 } 
