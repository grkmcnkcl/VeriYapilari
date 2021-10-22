#include<stdio.h>
#include<stdlib.h>
#include <math.h >
#include <time.h>
#include<conio.h>
#include<iostream>
#include<string.h>


int carp(int dizi[], int boyut) {
	int i;
	int carpim = 1;
	int boyyut = (sizeof(dizi) / sizeof(int));
	printf("%d\n", boyyut);
	for (i = 0; i < boyyut; i++) {
		carpim = carpim * dizi[i];
	}

	return carpim;
}

int main(int argc, char *argv[]) {
	int sonuc;
	int arrar[] = { 1,2,5,4,7,6,5 };
	int boyyut;

	boyyut = (sizeof(arrar) / sizeof(int));
	printf("%d\n", boyyut);

	sonuc = carp(arrar, boyyut);
	printf("%d\n", sonuc);
	system("pause");
	return 0;
}