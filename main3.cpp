#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

using namespace std;

void menu()
{
	cout << "Operations:" << endl;
	cout << "1. Output matrix" << endl;
	cout << "2. Add the matrix" << endl;
	cout << "3. Multiply the matrix" << endl;
	cout << "4. Transpose the matrix" << endl;
	cout << "5. Save to file" << endl;
	cout << "6. Upload from file" << endl;
	cout << "7. Sort matrix" << endl;
	cout << "8. End the program" << endl;
}

void delete_td(int **&td, int &a)
{
        for (int i = 0; i < a; i++)
                delete []td[i];
	delete [] td;
}

int init_td(int **&td, int &a, int &b, int argc, char *argv[])
{
	int p = 2;
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
			td[i][j] = 0;
	}
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++, p++)
		{
			if (p < argc)
				td[i][j] = atoi(argv[p]);
		}
	}
}

void show_td(int **&td, int &a, int &b)
{
	if (td == nullptr)
		cout << "Matrix is empty" << endl;
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
			cout << td[i][j] << " ";
		cout << endl;
	}
}

void add_td(int **&td, int &a, int &b)
{
	if (td == nullptr)
		cout << "Matrix is empty" << endl;
	else
	{
		cout << "Enter the matrix " << a << 'x' << b << endl;
		int **fam;
		fam = new int *[a];
		for (int i = 0; i < a; i++)
			fam[i] = new int[b];
		for (int i = 0; i < a; i++)
		{
			for (int j = 0; j < b; j++)
				cin >> fam[i][j];
		}
		cout << "Result: " << endl;
		for (int i = 0; i < a; i++)
		{
			for (int j = 0; j < b; j++)
			{
				td[i][j] = td[i][j] + fam[i][j];
				cout << td[i][j] << " ";
			}
			cout << endl;
		}
		delete_td(fam, a);
	}
}
void mult_td(int **&td, int &a, int &b)
{
	if (td == nullptr)
		cout << "Matrix is empty" << endl;
	else
	{
		cout << "Enter the size of the matrix: " << endl;
		int x, y;
		cout << "String: ";
		cin >> x; // количество строк
		cout << "Columns: ";
		cin >> y; // количество столбов
		if (x != b)
			cout << "Error. Wrong size." << endl;
		else
		{
			int **fmm = nullptr;
			fmm = new int*[x];
			
			for (int i = 0; i < x; i++)
				fmm[i] = new int[y];
			
			for (int i = 0; i < x; i++)
			{
				for (int j = 0; j < y; j++)
					cin >> fmm[i][j];
			}
			int **finmat = nullptr;
			finmat = new int*[a];
			
			for (int i = 0; i < a; i++)
				finmat[i] = new int [y];
			
			for (int i = 0;i < a; i++)
			{
				for (int j = 0; j < y; j++)
					finmat[i][j] = 0;
			}
			for (int i = 0; i < a; i++)
			{
				for (int j = 0; j < y; j++)
				{
					for (int k = 0; k < x; k++)
						finmat[i][j] += td[i][k]*fmm[k][j];
					cout << finmat[i][j] << " ";
				}
				cout << endl;
			}
			delete_td(finmat, a);
		}
	}
}

void trans_td(int **&td, int &a, int &b)
{
	if (td == nullptr)
		cout << "Matrix is empty" << endl;
	else
	{
		int **ttdd = new int *[a];
		for (int i = 0; i < a; i++)
			ttdd[i] = new int[b];
		for (int i = 0; i < a; i++)
		{
			for (int j = 0; j < b; j++)
				ttdd[i][j] = td[i][j];
		}
		delete_td (td, a);
		int temp;
		a = b;
		b = temp;
		td = new int *[a];
		for (int i = 0; i < a; i++)
			td[i] = new int[b];
		for (int i = 0; i < a; i++)
		{
			for (int j = 0; j < b; j++)
				td[i][j] = ttdd[j][i];
		}
		delete_td(ttdd, a);
	}
}

void save_td(int **&td, int &a, int &b)
{
	ofstream fout("matrix.txt", ios::app);
	for(int i = 0; i < a; i++)
	{
		for(int j = 0; j < b; j++)
		{
			fout << td[i][j] << " ";
		}
		fout << endl;
	}
	fout.close();
}

void loading_td(int **&td, int &a, int &b)
{
	cout << "Size: " << endl;
	cin >> a >> b;
	td = new int *[a];
	for (int i = 0; i < a; i++)
		td[i] = new int[b];
	ifstream fin("matrix.txt");
	if (fin.is_open())
	{
		for (int i = 0; i < a; i++)
		{
			for (int j = 0; j < b; j++)
				fin >> td[i][j];
			cout << endl;
		}
	}
	else
		cout << "Error";
	fin.close();
}

int main(int argc, char *argv[])
{
	int **td = nullptr;
	int a, b;
        string fir, sec;
	if (argc == 1)
	{
		a = b = 0;
		td = nullptr;
	}
	else
	{
	        for (int i = 0; argv[1][i] != 'x'; i++)
        	        fir = argv[1][i];

        	for (int i = 2; i < strlen(argv[1]); i++)
                	sec = argv[1][i];

        	a = atoi(fir.c_str());
        	b = atoi(sec.c_str());
        	td = new int *[a];

        	for (int i = 0; i < a; i++)
                	td[i] = new int[b];
	}
        int p = 2;
	int op;
	init_td(td, a, b , argc, argv);
	while(true)
	{
		menu();
		cin >> op;
		switch(op)
		{
			case 1:
				show_td(td, a, b);
				break;
			case 2:
				add_td(td, a, b);
				break;
			case 3:
				mult_td(td, a, b);
				break;
			case 4:
				trans_td(td, a, b);
				break;
			case 5:
				save_td(td, a, b);
				break;
			case 6:
				loading_td(td, a, b);
				break;
			case 8:
				delete_td(td, a);
				return 0;
			default:
				cerr << "Error" << endl;
		}
	}
	return 0;
}
