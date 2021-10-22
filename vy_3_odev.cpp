#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<math.h>


int main()
{
	int A[100] = { 0 };
	int B[100] = { 0 };
	
	int boyut = 0;
	
	FILE *fp,*dosya;
	char ch;
	
	fp = fopen("C:\\Users\\pc\\Desktop\\matrisler.txt", "r");
	while (feof(fp) == NULL)
	{
		ch = getc(fp);
		if (ch == '\n')
		{
			boyut++;
		}
	}
	fclose(fp);
	
	boyut = (boyut-3)/2;
	
	dosya = fopen("C:\\Users\\pc\\Desktop\\matrisler.txt", "r");
	int i = 0;
	int j = 0;
	while (i<boyut*2)
	{
		if (i < boyut)
		{
			fscanf(dosya, "%d", &A[i]);
		}
		if(i == boyut ) {
			fscanf(dosya, "%d", &B[j]);
			j++;
		}
		if (i > boyut) {
			fscanf(dosya, "%d", &B[j]);
			j++;
		}
			i++;
		
	}
	
	fclose(dosya);
	int boyut_karekok = sqrt(boyut);

	int dizi1[100][100];
	int dizi2[100][100];
	int sonucMatris[100][100] = { 0 };
	int k = 0;
	for (int  i = 0; i < boyut_karekok; i++)
	{
		for (int j = 0; j < boyut_karekok; j++)
		{
			dizi1[i][j] = A[k];
			k++;
		}
	}
	k = 0;
	for (int i = 0; i < boyut_karekok; i++)
	{
		for (int j = 0; j < boyut_karekok; j++)
		{
			dizi2[i][j] = B[k];
			k++;
		}
	}


	for (int i = 0; i < boyut_karekok; i++)
	{
		for (int j = 0; j < boyut_karekok; j++)
		{
			for (int k = 0; k < boyut_karekok; k++)
			{
				sonucMatris[i][j] = sonucMatris[i][j] + (dizi1[i][k] * dizi2[k][j]);
				
			}
		}
	}

	FILE *dosya_yaz;

	dosya_yaz = fopen("C:\\Users\\pc\\Desktop\\sonuc.txt", "w");
	for (int i = 0; i < boyut_karekok; i++)
	{
		for (int j = 0; j < boyut_karekok; j++)
		{
			fprintf(dosya_yaz, "%d\n", sonucMatris[i][j]);

		}
	}
	for (int i = 0; i < boyut_karekok; i++)
	{
		for (int j = 0; j < boyut_karekok; j++)
		{
			printf("%d\n", dizi1[i][j]);

		}
	}
	fclose(dosya_yaz);
	system("pause");
	return 0;
}