#define __STDC_WANT_LIB_EXT1__ 1
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <locale.h>
#include "file_rpm.h"

//функция чтения и печати файла посимвольно
void rpch_file(char *filename) {
  FILE *filepoint = fopen(filename, "r"); //откроем файл для чтения
    
  if (filepoint != NULL) {
	int c = fgetc(filepoint);
  	while (c != EOF) {
    	putc(c, stdout);
    	c = fgetc(filepoint);
  	}
  	fclose(filepoint);
  }
}

//функция чтения и печати файла построчно
void rps_file(char *filename) {
	char *locale = setlocale(LC_ALL, ""); //подключим языковые локали
	char buff[512]; //определим буффер для считывания строки из файла
  	FILE *filepoint = NULL;
  	fopen_s(&filepoint, filename, "r"); //откроем файл для чтения через более безопасную функцию fopen_s()

 	if (filepoint == NULL) {  //проверим, что файл удалось открыть
		printf("Error opening %s for reading. Program terminated.", filename);  //если файл не смогли открыть, то выводим ошибку и выходим их функции
		exit (1);
	}
	
	setvbuf(filepoint, NULL, _IOFBF, BUFSIZ);  // Считаем файл в буфер. Блоки будут формироваться с размером 512 байт.

 	while (fgets(buff, 512, filepoint) != NULL) { //пока не дойдем до коонца файла, считываем по 512 байт до знака конца строки или пустой строки и выводим построчно.
 	   	printf("%s", buff);
 	}
 	 	fclose(filepoint); //закрываем файл
		filepoint = NULL; //обнуляем указатель на файл
}
