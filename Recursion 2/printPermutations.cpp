void swap(char &x,char &y)
{
    char temp;
    temp=x;
    x=y;
    y=temp;
}
void printPermutationsHelper(string s,int i,int n){
    int j;
    if (i == n)
        cout << s <<endl;
    else
    {
        for (j = i; j < s.length(); j++)

        {
            swap(s[i],s[j]);

            printPermutationsHelper(s, i + 1, n);

            swap(s[i],s[j]);
        }
    }
}
void printPermutations(string input)
{
    int n=input.size();
    printPermutationsHelper(input,0,n-1);
}
