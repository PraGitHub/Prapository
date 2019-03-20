#include<iostream>
#include<new>
using namespace std;

class myClass{
	char a[1024][1024];
public:
	myClass(){
		for (int i = 0; i < 1024; i++){
			for (int j = 0; j < 1024; j++){
				a[i][j] = 'a';
			}
		}
	}
};


int main(){
	int continue_break = 1;
	int count = 1;

	while (true){
		if (continue_break){
			for (int i = 0; i < 100; i++){
				try{
					myClass* p = new myClass();
				}
				catch (bad_alloc& ex_ba){
					cout << "caught bad_alloc :: " << ex_ba.what() << endl;
					exit(0);
				}
				catch (...){
					cout << "caught unknown exception :: failed to allocate 100 MB" << endl;
					exit(0);
				}
			}
			cout << "allocated 100 MB" << endl;
			cout << "total = " << count * 100 << " MB" << endl;
		}
		else{
			break;
		}
		//cout << "enter 1 to continue / 0 to exit";
		//cin >> continue_break;
		cout << "Press CTRL+C to exit or " << endl;
		system("pause"); // Press any key to continue . . .
		count++;
	}
}