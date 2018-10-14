
#include <iostream>
#include <time.h>
#include <vector>
#include <array>
#include <Windows.h>
using namespace std;

const int rows = 11;
const int cols = 4;

void MaximumNumberStudents() // ����������� ��������� � ������������ ����������� ��������.
{
	int sc[rows][cols];
	srand(time(NULL));
	for (int i = 0; i < rows; i++)
	{
		for (int k = 0; k < cols; k++)
		{
			sc[i][k] = rand() % 20 + 10;
			printf("%i\t", sc[i][k]);
		}
		printf("\n");
	}
	int max = 0;
	int maxi = -1;
	for (int i = 0; i < rows; i++)
	{
		int sum = 0;
		for (int k = 0; k < cols; k++)
		{
			sum += sc[i][k];
		}
		if (sum > max)
		{
			max = sum;
			maxi = i;
		}
	}
	if (maxi != -1)
	{
		printf("%i-%i\n", maxi + 1, max);
	}
	system("pause");
}

void DeletingRows() // �������������� �������, ������ ������, �������� ������� ����������� �� �����������.
{
	srand(time(NULL)); // ���������� ��������� �����, ��������� ������� ����.
	int arr[rows][cols];
	for (int i = 0; i < rows; i++)
	{
		for (int k = 0; k < cols; k++)
		{
			arr[i][k] = rand() % 6;
		}
	}
	for (int i = 0; i < rows; i++)
	{
		for (int k = 0; k < cols; k++)
		{
			printf("%i\t", arr[i][k]);
		}
		printf("\n");
	}
	int(*b)[cols] = (int(*)[cols])malloc(cols * sizeof(int)); // ��������� ������
	int size = 0;
	for (int j = 0; j < rows; j++)
	{
		bool BO3 = true; // �������� �� ����������� ���������
		for (int k = 0; k < cols - 1; k++)
		{
			BO3 = arr[j][k] < arr[j][k + 1];
			if (!BO3)
				break;
		}
		if (!BO3)
		{
			memcpy(&b[size++][0], &arr[j][0], cols * sizeof(int));
			b = (int(*)[cols])realloc(b, (size + 1) * (cols * sizeof(int)));
		}
	}
	printf("%i\n", size);
	for (int i = 0; i < size; i++)
	{
		for (int k = 0; k < cols; k++)
		{
			printf("%i\t", b[i][k]);
		}
		printf("\n");
	}
		system("pause");
}

void DeterminationNumberElements() // ����������� ���������� ��������� � ����� �������, ������������� ��� �������� ����������, � ������� ������� �������������� ���� ����, ������ 7,5.
{
	const int cols = 6;

	srand(time(NULL));
	int sc[cols][cols];
	int count = 0;

	for (int i = 0; i < cols; i++) {
		for (int j = 0; j < cols; j++)
		{
			sc[i][j] = rand() % 20+1;
		}
	}

	for (int i = 0; i < cols; i++) {

		for (int j = 0; j < cols - i - 1; j++)
		{
			printf("%i\t", sc[i][j]);
			int n = sc[i][j];
			int sum = 0;
			int c = 0;
			while (n != 0)
			{
				sum += n % 10;
				n /= 10;
				c++;
			}
			if ((sum / c) > 7.5)
				count++;
		}
		printf("\n");
	}
	printf("Result: %i\n", count);
	system("pause");
}

int main()
{
	// ��������� ����������� �����-������
	SetConsoleCP(1251); // ��������� ��������� �����
	SetConsoleOutputCP(1251); // ��������� ��������� �����
							  // �������� ���

	int command;
	while (true)
	{
		cout << "������� �������: ";
		cin >> command;
		if (cin.fail())
		{
			cout << "�������� ���� �����! " << endl;
			cin.clear();
			cin.ignore(1000, '\n');
			command = 0;
		}
		else
		{


			switch (command)
			{
			default:
				cout << "������� �������� �������: ";
				break;
			case 1:
				MaximumNumberStudents();
				break;
			case 2:
				DeletingRows();
				break;
			case 3:
				DeterminationNumberElements();
				break;
			}
		}
	}
}