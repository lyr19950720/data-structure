#include<stdio.h>
int a[14];
int main()
{
	int i,m,s,x,count;
	for(i=1;i<14;++i)
	{
		for(m=i+1;;++m)
		{
			s=0;  
			count=2*i;
			while(1)
			{
				x=(s+m)%count;
				if(!x)
					x=count;
				if(x<=i)
					break;
				s=x-1;
				count--;
				if(count==i)
				{
					a[i]=m;
					break;
				}
			}
			if(count==i)
				break;
		}
	}
	int k;
	while(scanf("%d",&k)&&k)
		printf("%d\n",a[k]);
	return 0;
}