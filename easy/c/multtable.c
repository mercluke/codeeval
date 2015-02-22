#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    int ii, jj;

    for(ii = 1; ii <= 12; ii++)
    {
        for(jj = 1; jj <= 12; jj++)
        {
            if(jj == 1) printf("%i", ii*jj);
            else if(jj == 12)printf("%4i\n", ii*jj);
            else printf("%4i", ii*jj);
        }
    }
    
	return 0;
}