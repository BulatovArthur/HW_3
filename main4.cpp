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

struct td
{
	int **td = nullptr;
	int a;
	int b;
};

void delete_td(td &td)
{
        for (int i = 0; i < td.a; i++)
                delete []td.td[i];
	delete [] td.td;
}

void delete_arr(int **&fam, td &td)
{
	for (int i = 0; i < td.a; i++)
		delete []fam[i];
	delete []td.td;
}

int init_td(td &td, int argc, char *argv[])
{
	int p = 2;
	for (int i = 0; i < td.a; i++)
	{
		for (int j = 0; j < td.b; j++)
			td.td[i][j] = 0;
	}
	for (int i = 0; i < td.a; i++)
	{
		for (int j = 0; j < td.b; j++, p++)
		{
			if (p < argc)
				td.td[i][j] = atoi(argv[p]);
		}
	}
}

void show_td(td &td)
{
	if (td.td == nullptr)
		cout << "Matrix is empty" << endl;
	for (int i = 0; i < td.a; i++)
	{
		for (int j = 0; j < td.b; j++)
			cout << td.td[i][j] << " ";
		cout << endl;
	}
}

void add_td(td &td)
{
	if (td.td == nullptr)
		cout << "Matrix is empty" << endl;
	else
	{
		cout << "Enter the matrix " << td.a << 'x' << td.b << endl;
		int **fam;
		fam = new int *[td.a];
		for (int i = 0; i < td.a; i++)
			fam[i] = new int[td.b];
		for (int i = 0; i < td.a; i++)
		{
			for (int j = 0; j < td.b; j++)
				cin >> fam[i][j];
		}
		cout << "Result: " << endl;
		for (int i = 0; i < td.a; i++)
		{
			for (int j = 0; j < td.b; j++)
			{
				td.td[i][j] = td.td[i][j] + fam[i][j];
				cout << td.td[i][j] << " ";
			}
			cout << endl;
		}
		delete_arr(fam, td);
	}
}

void mult_td(td &td)
{
	if (td.td == nullptr)
		cout << "Matrix is empty" << endl;
	else
	{
		cout << "Enter the size of the matrix: " << endl;
		int x, y;
		cout << "String: ";
		cin >> x; // количество строк
		cout << "Columns: ";
		cin >> y; // количество столбов
		if (x != td.b)
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
			finmat = new int*[td.a];
			
			for (int i = 0; i < td.a; i++)
				finmat[i] = new int [y];
			
			for (int i = 0; i < td.a; i++)
			{
				for (int j = 0; j < y; j++)
					finmat[i][j] = 0;
			}
			for (int i = 0; i < td.a; i++)
			{
				for (int j = 0; j < y; j++)
				{
					for (int k = 0; k < x; k++)
						finmat[i][j] += td.td[i][k]*fmm[k][j];
					cout << finmat[i][j] << " ";
				}
				cout << endl;
			}
			delete_arr(finmat, td);
		}
	}
}

void trans_td(td &td)
{
	if (td.td == nullptr)
		cout << "Matrix is empty" << endl;
	else
	{
		int **ttdd = new int *[td.a];
		for (int i = 0; i < td.a; i++)
			ttdd[i] = new int[td.b];
		for (int i = 0; i < td.a; i++)
		{
			for (int j = 0; j < td.b; j++)
				ttdd[i][j] = td.td[i][j];
		}
		delete_td (td);
		int temp;
		td.a = td.b;
		td.b = temp;
		td.td = new int *[td.a];
		for (int i = 0; i < td.a; i++)
			td.td[i] = new int[td.b];
		for (int i = 0; i < td.a; i++)
		{
			for (int j = 0; j < td.b; j++)
				td.td[i][j] = ttdd[j][i];
		}
		delete_arr(ttdd, td);
	}
}

void save_td(td &td)
{
	ofstream fout("matrix.txt", ios::app);
	for(int i = 0; i < td.a; i++)
	{
		for(int j = 0; j < td.b; j++)
		{
			fout << td.td[i][j] << " ";
		}
		fout << endl;
	}
	fout.close();
}

void loading_td(td &td)
{
	cout << "Size: " << endl;
	cin >> td.a >> td.b;
	td.td = new int *[td.a];
	for (int i = 0; i < td.a; i++)
		td.td[i] = new int[td.b];
	ifstream fin("matrix.txt");
	if (fin.is_open())
	{
		for (int i = 0; i < td.a; i++)
		{
			for (int j = 0; j < td.b; j++)
				td.td[i][j] = 0;
		}
		for (int i = 0; i < td.a; i++)
		{
			for (int j = 0; j < td.b; j++)
				fin >> td.td[i][j];
			cout << endl;
		}
	}
	else
		cout << "Error";
	fin.close();
}

int main(int argc, char *argv[])
{
	td td;
        string fir, sec;
	if (argc == 1)
	{
		td.a = td.b = 0;
		td.td = nullptr;
	}
	else
	{
	        for (int i = 0; argv[1][i] != 'x'; i++)
        	        fir = argv[1][i];

        	for (int i = 2; i < strlen(argv[1]); i++)
                	sec = argv[1][i];

        	td.a = atoi(fir.c_str());
        	td.b = atoi(sec.c_str());
        	td.td = new int *[td.a];

        	for (int i = 0; i < td.a; i++)
                	td.td[i] = new int[td.b];
	}
        int p = 2;
	int op;
	init_td(td, argc, argv);
	while(true)
	{
		menu();
		cin >> op;
		switch(op)
		{
			case 1:
				show_td(td);
				break;
			case 2:
				add_td(td);
				break;
			case 3:
				mult_td(td);
				break;
			case 4:
				trans_td(td);
				break;
			case 5:
				save_td(td);
				break;
			case 6:
				loading_td(td);
				break;
			case 8:
				delete_td(td);
				return 0;
			default:
				cerr << "Error" << endl;
		}
	}
	return 0;
}
