void printKeypad(int num,string output)
{

  if(num==0)
  {
    cout<<output<<endl;
    return;
  }
  string input[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
  string s=input[num%10];
  for(int i=0;i<s.size();i++)
  {
    printKeypad(num/10,s[i]+output);
    
  }
}
void printKeypad(int num)
{
    string output="";
    printKeypad(num,output);
}
