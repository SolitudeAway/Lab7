#include <iostream>
#include <iomanip>
using namespace std;

int inputSize();  //розміру масиву
void arrayRand(float arr[], int, int, int); //заповнення масиву випадковими значеннями
void arrayOutput(float arr[], int n); //виведення масиву
void arrayChange(float arr[], int n, int, int func(float, int)); //зміна від'ємних значень масиву
int elementChange(float a, int); //повернення суми цифр дробової частини

int main()
{
	srand(time(NULL));
	int an = 3, pn = 3;			//кількість всіх цифр і цифр після коми
	int n = inputSize();		//розмір масиву 
	float* B = new float[n];	//оголошення динамічного масиву
	arrayRand(B, n, an, pn);	//заповнення масиву випадковими значеннями
	cout << "Array: ";
	arrayOutput(B, n);			//виведення згенерованого масиву
	arrayChange(B, n, pn, elementChange);//зміна масиву відповідно до задачі
	cout << endl << "Changed array: ";
	arrayOutput(B, n);			//виведення зміненого масиву
	cout << endl;
	delete[] B;					//видалення динамічного масиву
	system("pause");
}

int inputSize()
{
	int n;
	cout << "Enter the size of array: ";
	cin >> n;
	return n;
}

void arrayRand(float B[], int n, int an, int pn)
{
	for (int i = 0; i < n; i++)
	{
		B[i] = (rand() * rand()) % int(2 * pow(10, an) - 1) - (pow(10, an) - 1);
		B[i] = B[i] / pow(10, pn);
	}
}

void arrayOutput(float arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << "  ";
}

void arrayChange(float arr[], int n, int b, int func(float, int))
{
	for (int i = 0; i < n; i++)
	{
		if (arr[i] < 0)
			arr[i] = func(arr[i], b);
	}
}

int elementChange(float a, int pn)
{
	int sum = 0;
	a = abs(a);
	a -= floor(a);
	int b = round(a * pow(10, pn));
	for (int i = 0; i < pn; i++)
	{
		sum += b % 10;
		b /= 10;
	}
	return sum;
}
