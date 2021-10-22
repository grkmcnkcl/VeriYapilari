/*------------------------------------------------------------
* Title      : Matris Çarpýmý
* Written by : Görkem ÇANAKÇILI
* Student ID : 1306180069
* Date		 : 04.12.2018
--------------------------------------------------------------*/
#include<iostream>
using namespace std;
const int O = 10;
void matrisOku(int m[O][O])
{
	for (int i = 0; i < O; i++)
	{
		for (int j = 0; j < O; j++)
		{
			cout << i + 1 << ". satir " << j + 1 << ". sutun elemanini giriniz :"; cin >> m[i][j];
		}
	}
}

void matrisCarp(int m1[O][O], int m2[O][O], int m3[O][O])
{
	for (int i = 0; i < O; i++)
	{
		for (int j = 0; j < O; j++)
		{
			for (int k = 0; k < O; k++)
			{
				m3[i][j] += m1[i][k] * m2[k][j];
			}
		}
	}
}
void matrisYaz(int m3[O][O])
{
	for (int i = 0; i < O; i++)
	{
		for (int j = 0; j < O; j++)
		{
			cout << "  " << m3[i][j];
		}cout << endl;
	}
}
int main()
{

	int matris1[O][O];
	int matris2[O][O];
	int matris3[O][O] = { 0 };
	cout << "Birinci matrisin " << endl;
	matrisOku(matris1);
	cout << "Ikinci matrisin " << endl;
	matrisOku(matris2);
	matrisCarp(matris1, matris2, matris3);
	cout << "Matrislerin carpimi \n";
	matrisYaz(matris3);
	return 0;
}
