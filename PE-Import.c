#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>


int main(){
	FILE *fp;
	size_t length;
	ssize_t read;
	char *line = NULL;
	bool present;

	int found = access("PE-1.txt", "F_OK");
	fp = fopen("PE-1.txt","w");
	if(found == -1){
		//The file wasn't available
		fprintf(fp, "I want to learn PE file format!");
	}
	else{
		while((read = getline(&line, &length, fp)!=-1)){
			line[strcspn(line, "\n")] = 0;
			if(!strcmp(line, "I want to learn PE file format!")){
				printf(line, "%s");
				present = true;
			}
		}
		if(!present){
		fprintf(fp, "I want to learn PE file format!");
		}
	}
	fclose(fp);
	if(line)
		free(line);
	return 0;
}
