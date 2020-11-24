#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
int Secret(char* replaceable, int* Arr, int i) {
	int k = 1;
	while (1) {
		int f = 1;
		for (int j = 0; j < i; j++) {
			if (replaceable[j] != replaceable[j + k] && j + k < i) {
				f = 0;
				k++;
				break;
			}
		}
		if (k > i) {
			break;
		}
		if (f == 1) {
			return k;
		}
	}
	return 0;
}