#include<stdio.h>
#include <iostream>
#include<string>
#include<cstring>
using namespace std;
int main()
{
	string CT="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string PT="VWXYZABCDEFGHIJKLMNOPQRSTU";
	int len=CT.size();
    char s[105],e[105];	char message[105];
	while(gets(s))
	{	    
	     if(strcmp(s,"ENDOFINPUT")==0)
			 break;
		 if(strcmp(s,"START")==0)
		  { 
			    gets(message);
			
				gets(e);
		        if(strcmp(e,"END")==0)
				{
                   for(int i=0;i<strlen(message);i++)
				{
				if(message[i]>='A'&&message[i]<='Z')
				{
					for(int j=0;j<len;j++ )
					{

						if(CT[j]==message[i])
						{		
			    		   message[i]=PT[j];
							cout<<PT[j];
							break;
						}
					}
				}
				else
					cout<<message[i];
				
			}
				   cout<<endl;
				}
		    	
		   }
	}
     	 
			
	
	return 0;
}