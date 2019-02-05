#include<iostream>
#include<thread>
#include<Windows.h>
using namespace std;

class channel{
	string data;
	int count;
public:
	channel(){
		count = 0;
		data = "";
	}
	bool set_channel_data(string str){
		if (count == 0){
			data = str;
			count = 1;
			return true;
		}
		return false;
	}
	void reset_count(){
		count = 0;
	}
	string get_channel_data(){
		while (count > 0){ Sleep(100); }
		reset_count();
		return data;
	}
};

channel my_chan;

void sub_routine(){
	string str_channel_data;
	my_chan = channel();
	while (true){
		str_channel_data = my_chan.get_channel_data();
		cout << "sub_routine :: " << this_thread::get_id() << " :: str_channel_data = " << str_channel_data.c_str() << endl;
		Sleep(100);
	}
}

int main(){
	thread *t1 = new thread(&sub_routine);
	string str_data;
	bool set_status;
	t1->detach();
	int i = 0;
	char c[] = { "abcde" };
	while (true){
		str_data = "main_routine " + string((const char*)&c[i++%5]);
		set_status = my_chan.set_channel_data(str_data);
		if (set_status){
			cout << " set_status is true for " << str_data.c_str() << endl;
		}
		else{
			cout << " set_status is false for " << str_data.c_str() << endl;
		}
		Sleep(100);
	}
}