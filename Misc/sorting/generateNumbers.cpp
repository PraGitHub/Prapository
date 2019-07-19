#include<iostream>
#include<sstream>
#include<fstream>
using namespace std;

int main(int NARG, char** ARGS){
  if(NARG != 2){
    cout<<"call this program by passing a valid integer as input"<<endl;
    cout<<"if 'n' is the number, then, this program will generate 'n' random integers and store them in a file - 'input.file'"<<endl;
    return 0;
  }
  string strNum(ARGS[1]);
  istringstream iss(strNum);
  int n;
  iss>>n;
  fstream outFile;
  outFile.open("input.file");
  outFile<<n<<endl;

  int num = -1;

  int arr[10] = {'i', 'l', 'r', 'a', 'w', 'j', 'o', 'a', 'g', 'k'};

  int count = n/2;
  for(int i=0; i<=n/2; i++){
    int gk = arr[i%10];
    num = gk + (i+arr[(i*i*gk)%10])*arr[(i*gk*gk)%10] + count--;
    outFile<<num<<" ";
  }

  for(int i=-n/2; i<0; i++){
    int gk = arr[i%10];
    num = gk + (i+arr[(i*i*gk)%10])*arr[(i*gk*gk)%10] + count--;
    outFile<<num<<" ";
  }

  outFile<<endl;
  outFile.close();
  return 0;
}
