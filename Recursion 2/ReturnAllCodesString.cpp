#include <string.h>
using namespace std;
int atoi(char a)
{
    int i=a-'0';
    return i;
}
char itoa(int i)
{
    char c='a'+i-1;
    return c;
}
int getCodes(string input, string output[10000]) {
   if(input.size()==0)
   {
       output[0]="";
       return 1;
   }
    if(input.size()==1)
    {
        output[0]=itoa(atoi(input[0]));
        return 1;
    }
    string result1[10000],result2[10000];
    int size2=0;

    int size1=getCodes(input.substr(1),result1);
    if(input.size()>1)
    {
        if(atoi(input[0])*10+atoi(input[1])>=10&&atoi(input[0])*10+atoi(input[1])<27)
        {
            size2=getCodes(input.substr(2),result2);
        }

    }
    int k=0;
    for(int i=0;i<size1;i++)
    {
            output[k++]=itoa(atoi(input[0]))+result1[i];
    }
    for(int i=0;i<size2;i++)
    {
            output[k++]=itoa(atoi(input[0])*10+atoi(input[1]))+result2[i];
    }
    return k;
}
