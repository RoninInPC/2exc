#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include"filefunction.h"
#include"secretfunction.h"
int main(int argc, char* argv[]) {
	if (argc == 5) {
		char* inputFile = argv[1];
		char* outputFile = argv[2];
		char* replaceable = argv[3];
		int* Arr = malloc(strlen(replaceable) * sizeof(char));
		for (int i = 0; i < strlen(replaceable); i++) {
			Arr[i] = 0;
		}
		char* replacement = argv[4];
		if (ErrorInFile(inputFile) == 1) {
			return 0;
		}
		if (ErrorInFile2(outputFile) == 1) {
			return 0;
		}
		FILE* f;
		FILE* f1;
		fopen_s(&f, inputFile, "r");
		fopen_s(&f1, outputFile, "w");
		fclose(f1);
		char c;
		int i = 0;
		int f3 = 0;
		while (1) {
			fscanf_s(f, "%c", &c, 1);
			if (feof(f) != 0) {
				for (int j = 0; j < strlen(replaceable); j++) {
					if (Arr[j] == 1) {
						fopen_s(&f1, outputFile, "a");
						fprintf(f1, "%c", replaceable[j]);
						fclose(f1);
					}
				}
				break;
			}
			if (c == replaceable[i]) {
				Arr[i] = 1;
				if (i == strlen(replaceable) - 1) {
					fopen_s(&f1, outputFile, "a");
					fprintf(f1, "%s", replacement);
					fclose(f1);
					for (int j = 0; j < strlen(replaceable); j++) {
						Arr[j] = 0;
					}
					i = 0;
				}
				else
				{
					i++;
				}
			}
			else {
				if (i == 0) {
					fopen_s(&f1, outputFile, "a");
					fprintf(f1, "%c", c);
					fclose(f1);
				}
				if (i != 0) {
					int f2 = Secret(replaceable,Arr,i);
					if (c != replaceable[i - f2]) {
						f2 = 0;
						f3 = 1;
					}
					else
					{
						i=i-f2+1;
					}
					if(f2 != 0){
						fopen_s(&f1, outputFile, "a");
						for (int j = 0; j < f2; j++) {
							fprintf(f1, "%c", replaceable[j]);
						}
						
						fclose(f1);
					}
					else
					{
						if (f3 == 0) {
							fopen_s(&f1, outputFile, "a");
							fprintf(f1, "%c", c);
							fclose(f1);
							f3 = 0;
						}
						else {
							for (int j = 0; j < strlen(replaceable); j++) {
								if (Arr[j] == 1) {
									fopen_s(&f1, outputFile, "a");
									fprintf(f1, "%c", replaceable[j]);
									fclose(f1);
								}
							}
							fopen_s(&f1, outputFile, "a");
							fprintf(f1, "%c", c);
							fclose(f1);
							for (int j = 0; j < strlen(replaceable); j++) {
								Arr[j] = 0;
							}
							i = 0;
						}
						
					}
				}
			}
		}
		fclose(f);
	}
	else
	{
		if (argc > 5) {
			printf("You write excess information");
			return 0;
		}
		if (argc < 5) {
			printf("You don't write information to task");
			return 0;
		}
	}
	return 0;
}