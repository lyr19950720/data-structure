/*#include<iostream>
using namespace std;
int main()
{
	int N;
    cin>>N;
	while(N>0&&N<1000)
	{	
		int M;
		cin>>M;
		char s[80];
		char temp;
		int i=0;	
	//	getline(cin,temp);
		temp=cin.get();
		while(cin>>temp)
		{ 
			if()
			if(temp>='A'&&temp<'Z')
			{	
			if(i==M-1)
		       i++;
	    	 else
			 {
			 s[i]=temp;
			 cout<<s[i];
	     	 i++;
			 }
			}	
		}
    	N--;
	}*/
#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 80
using namespace std;
int main()
{ 
int N=0;cin>>N;
while(N>0){
    int n;
    char str[MAXN];
    gets(str);
    scanf("%d", &n);
    int len = strlen(str);
    for(int i = n-1; i < len; i++)
       str[i] = str[i+1];
    for(int j = 0; j < len; j++) 
       printf("%c", str[j]);

	N--;
}
   

	


return 0;
}

 //  return 0;
//}