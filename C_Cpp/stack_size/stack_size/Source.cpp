#include<iostream>

using namespace std;

class kB{
	char a[1024];
public:
	void set(){
		cout << "kB :: set" << endl;
		for (int i = 0; i < 1024; i++){
			a[i] = '1';
		}
	}
};

class MB{
	kB a[1024];
public:
	void set(){
		cout << "MB :: set" << endl;
		for (int i = 0; i < 1024; i++){
			a[i].set();
		}
	}
};

class GB{
	MB a[1024];
public:
	void set(){
		cout << "GB :: set" << endl;
		for (int i = 0; i < 1024; i++){
			a[i].set();
		}
	}
};

void allocate_in_stack(){
	cout << "trying to allocate in stack" << endl;
	GB objGB;
	cout << sizeof(GB) << endl;
	objGB.set();
	cout << "allocated in stack  and this is a miracle" << endl;
}

GB* allocate_in_heap(){
	cout << "trying to allocate in heap" << endl;
	GB* pGB = new GB();
	cout << "allocated in heap" << endl;
	return pGB;
}

int main(int NARG, char** ARGS){
	if (NARG != 2){
		cout << "Usage : " << endl;
		cout << "\"stack_size.exe 1\" for allocation in stack" << endl;
		cout << "\"stack_size.exe 2\" for allocation in heap" << endl;
		return 0;
	}

	string strArg(ARGS[1]);
	GB* pGB = nullptr;

	if (strArg == "1"){
		allocate_in_stack();
	}
	else{
		pGB = allocate_in_heap();
	}

	//system("pause");
	if (pGB != nullptr){
		delete pGB;
	}
	else{
		if (strArg != "1"){
			cout << "did not find continous 1GB space to allocate" << endl;
		}
	}
	return 0;
}
