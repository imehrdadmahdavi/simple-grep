#include <stdio.h>
#include <stdlib.h>
#include "dbg.h"

#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
	check(argc > 2, "USAGE: ./logfind word word");
	
	FILE *fp = NULL;
	char *buffer = calloc(BUFFER_SIZE, 1);;
	char *in = NULL;
	int totalRead = 0;
	int i = 0;

	check_mem(buffer);
	fp = fopen(".logfind", "r");
	check(fp != NULL, "Error opening the file!");

	while(fgets(buffer, BUFFER_SIZE - 1, fp)) {
        
		totalRead = strlen(buffer);
        	buffer[totalRead - 1] = buffer[totalRead - 1]
        		=='\n' ? '\0' : buffer[totalRead - 1];

		FILE *fp_tmp = NULL;
		for(i = 1; i < argc; i++){
			fp_tmp = fopen(buffer, "r");
			check(fp_tmp != NULL, "Error opening the file!");
			char *buffer_tmp = calloc(BUFFER_SIZE, 1);
			int j = 1;
			while(fgets(buffer_tmp, BUFFER_SIZE - 1, fp_tmp)){
				totalRead = strlen(buffer_tmp);
        			buffer_tmp[totalRead - 1] = buffer_tmp[totalRead - 1]
                		=='\n' ? '\0' : buffer[totalRead - 1];
				if(strstr(buffer_tmp, argv[i]) != NULL){
					printf("%s\t: found in %s -> line: %d\n", argv[i], buffer, j);
				}
				j++;
			}
        		if (buffer_tmp) free(buffer_tmp);
			if (fp_tmp) fclose(fp_tmp);
		}
	}
	return 0;
error:
	if(buffer) free (buffer);
	if(fp) fclose(fp);
	return 1;
}
