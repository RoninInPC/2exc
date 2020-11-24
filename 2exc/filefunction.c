#include<stdio.h>
#include<io.h>
int ErrorNoFile(char* fname) {
	if (_access(fname, 0) == -1)
	{
		printf("ERROR! File don't found\n");
		return 1;
	}
	return 0;
}
int ErrorNotRight(char* fname) {
	if (_access(fname, 4) == -1)
	{
		printf("ERROR! File restrict for administrator\n");
		return 1;
	}
	return 0;
}
int ErrorFileEmpty(char* fname) {
	FILE* f;
	fopen_s(&f, fname, "r");
	if (getc(f) == EOF)
	{
		printf("ERROR! File is empty\n");
		fclose(f);
		return 1;
	}
	fclose(f);
	return 0;
}
int ErrorInFile(char* fname) {
	if (ErrorNoFile(fname) == 1) return 1;
	if (ErrorNotRight(fname) == 1) return 1;
	if (ErrorFileEmpty(fname) == 1) return 1;
	return 0;
}
int ErrorInFile2(char* fname) {
	if (ErrorNoFile(fname) == 1) return 1;
	if (ErrorNotRight(fname) == 1) return 1;
	return 0;
}