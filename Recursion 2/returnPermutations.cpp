#include <string>
using namespace std;
int returnPermutations(string input, string output[]){
  if(input.empty()){
    output[0]="";
    return 1;
  }
  int len = input.length();
 // int ans;
  int k=0;
  string newout[10000];
  for(int i=0;i<len;i++){
    int ans=returnPermutations(input.substr(0,i)+input.substr(i+1),newout);
    for(int j=0;j<ans;j++){
      output[k++] = input[i] + newout[j];
    }
  }         
  return k;
}
