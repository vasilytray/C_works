#include <stdio.h>
#include <locale.h>
#include "file_rpm.h"

void rp_file(char *fname)
{
	setlocale (LC_ALL, "Ru");
	char *buff=NULL;
	size_t fsize=0,readbites=0;
	FILE *filepoint = fopen(fname, "r");
	if(filepoint==NULL)
	{
		printf(" -> n/a");
		return 0;
	}
	fseek(filepoint, 0, SEEK_END);
	fsize = ftell(filepoint);
	fseek(filepoint, 0, SEEK_SET);
	buff=(char*)malloc(sizeof(char) * fsize+1);
	if(buff==NULL)
	{
		printf(" -> n/a");
		fclose(filepoint);
		return 0;
	}
	if((readbites=fread(buff,1,fsize,filepoint))!=fsize)
	{
		fclose(filepoint);
		printf(" -> n/a %llu",readbites);
		return 0;
	}
	buff[readbites]=0;
	printf(buff);
	fclose(filepoint);
	free(buff);
	return 1;
}

void rpch_file(char *name) {
  FILE *f = fopen(name, "rt");
    
  if (f != NULL) {
  int c = fgetc(f);
  while (c != EOF) {
    putc(c, stdout);
    c = fgetc(f);
  }
  fclose(f);
  }
}

