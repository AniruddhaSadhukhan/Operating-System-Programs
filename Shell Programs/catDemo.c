
#include<stdio.h>
 
int main(int argc,char* argv[])
{
    	if (argc ==1)
    	{
    		printf("Usage: ./a.out file1 file2 ... \n");
    		return 0;
    	}
    	
    	int i;
    	char c;
    	FILE *ptr;
    	for(i=1;i<argc;i++)
	{
		ptr = fopen(argv[i],"r");
    		if (ptr == NULL)
		{
		printf("Cannot open file \n");
		continue;
		}
	 
		// Read contents from file
		c = fgetc(ptr);
		while (c != EOF)
	    	{
			printf ("%c", c);
			c = fgetc(ptr);
	    	}
	 
	    	fclose(ptr);
	    	printf("\n\n\n");
	}
        
    	return 0;
}
