#include <string.h>
using namespace std;
char hashmap[]={'\0','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

void print(string input, string output){
  if(input.empty()){
    cout<<output<<endl;
    return;
  }
  for(int i=1;i<3;i++){
    string temp=input.substr(0,i);
    int tem= stoi(temp);
    
    int len=input.length();
	    if(len>=i && tem<=27){
	    print(input.substr(i),output+hashmap[tem]);
	    }
  }
  
}

void printAllPossibleCodes(string input) {
  print(input,"");
}
