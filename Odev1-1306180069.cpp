#include<stdio.h>
#include<stdlib.h>

int *dizi;
int boyut = 2;
int tepe = 0;

int pop(){
	if (dizi == NULL)
	{
		printf(" Yigit bos oldugu icin islem gerceklestirilemiyor. ");
		return -1;
	}
	if (tepe <= boyut / 4)
	{
		int *dizi2 = (int*)malloc(sizeof(int)*boyut / 2);
		for (int i = 0; i < boyut; i++)
		{
			dizi2[i] = dizi[i];
		}
		free(dizi);
		dizi = dizi2;
		boyut /= 2;
	}
	return dizi[--tepe];
}

void push(int a) {
	if (dizi == NULL)
	{
		dizi = (int*)malloc(sizeof(int) * 2);
	}

	if (tepe >= boyut)
	{
		int *dizi2 = (int*)malloc(sizeof(int)*boyut * 2);
		for (int i = 0; i < boyut; i++)
		{
			dizi2[i] = dizi[i];
		}
		free(dizi);
		dizi = dizi2;
		boyut *= 2;
	}
	dizi[tepe++] = a;
}

void bastir() {
	for (int i = 0; i < tepe; i++)
	{
		printf("%d ", dizi[i]);
	}
}

int main() {
	int secim;
	int eleman;

	do {
		printf("\n-------------------------------------\n");
		printf("Islem seciniz \n");
		printf("Yigita eleman eklemek icin : 1\n");
		printf("Yigittan eleman silmek icin : 2\n");
		printf("Yigiti listelemek icin : 3\n");
		printf("Cikmak icin : 4\n");
		printf("\n-------------------------------------\n");
		scanf_s("%d", &secim);

		switch (secim) {

		case 1:
			printf("Eklemek istediginiz degeri giriniz :");
			scanf_s("%d", &eleman);
			push(eleman);
			break;

		case 2:
			pop();
			break;

		case 3:
			printf("\n");
			bastir();
			printf("\n");
			break;
		}
	} while (secim == 1 || secim == 2 || secim == 3);


	system("pause");
	return 0;
}