#include<stdio.h>

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		char x[1005];int n;
		scanf("%s%d",x,&n);
		for(int i=0;x[i]!=0;++i)
		{
			x[i]-='a';
			x[i]=(x[i]+n)%26;
			x[i]+='a';
			printf("%c",x[i]);
		}
		printf("\n");
	}
	return 0;
}