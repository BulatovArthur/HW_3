#include <iostream>
#include <string>
#include <cstring>

using namespace std;

void menu()
{
	cout << "Operations:" << endl;
	cout << "1. Output matrix" << endl;
	cout << "2. Add the matrix" << endl;
	cout << "3. Add Multiply the matrix" << endl;
	cout << "4. Transpose the matrix" << endl;
	cout << "5. Save to file" << endl;
	cout << "6. Upload from file" << endl;
	cout << "7. Sort matrix" << endl;
	cout << "8. End the program" << endl;
}

void delete_td(int **td, int &a)
{
        for (int i = 0; i < a; i++)
        {
                delete []td[i];
        }
}

int init_td(int **td, int &a, int &b, int argc, char *argv[])
{
	int p = 2;
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			td[i][j] = 0;
		}
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

void show_td(int **td, int &a, int &b, int argc)
{
	if (td == nullptr)
	{
		cout << "Matrix is empty" << endl;
		return;
	}
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			cout << td[i][j] << " ";
		}
		cout << endl;
	}
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
	        {
        	        fir = argv[1][i];
        	}
        	for (int i = 2; i < strlen(argv[1]); i++)
        	{
                	sec = argv[1][i];
        	}
        	a = atoi(fir.c_str());
        	b = atoi(sec.c_str());
        	td = new int *[a];
        	for (int i = 0; i < a; i++)
        	{
                	td[i] = new int[b];
        	}
	}
        int p = 2;
	int op;
	while(true)
	{
		menu();
		cin >> op;
		switch(op)
		{
			case 1:
				init_td(td, a, b, argc, argv);
				show_td(td, a, b, argc);
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

