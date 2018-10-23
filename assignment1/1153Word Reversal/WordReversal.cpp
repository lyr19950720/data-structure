#include <stdio.h>
#include <string.h>
	const int maxn = 10000;
	char str[maxn], stack[maxn];
int main ( )

{
    int n,len;
        scanf ( "%d", &n );
        getchar ( );    
        while ( n -- )
        {
            int top = -1;
            fgets ( str, maxn, stdin );
            len = strlen ( str );
            for ( int i = 0; i < len; i ++ )
            {
                if (str[i] >= 'A' && str[i] <= 'Z' || str[i] >= 'a' && str[i] <= 'z' )
                   stack[++ top] = str[i];
                else
                {
                    while ( top >= 0 )
                        printf ( "%c", stack[top --] );
                    printf ( "%c", str[i] );
                }
            }
            while ( top >= 0 )  
                printf ( "%c", stack[top --] );
    }
    return 0;
}
