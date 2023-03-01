#include <iostream>
#include <time.h>
using namespace std;

int main() {
	int iLotto[45];

	for (int i = 0; i < 45; i++) 
	{
		iLotto[i] = i + 1;
	}

	for (int i = 0; i < 100; ++i) 
	{
		int temp, idx1, idx2;
		idx1 = rand() % 45;
		idx2 = rand() % 45;

		temp = iLotto[idx1];
		iLotto[idx1] = iLotto[idx2];
		iLotto[idx2] = temp;
	}

	for (int i = 0; i < 45; i++)
	{
		cout << iLotto[i] << endl;
	}

	for (int i = 0; i < 5; i++) 
	{
		cout << iLotto[i] << "\t";
	}

	cout << "보너스 번호" << iLotto[6];
}
