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

void Output(int**& mas, int& a, int& b, int argc, char* argv[])
{
  int i, j, p;
  p = 2;
  string first, second;

  for (i = 0; (argv[1][i] != 'x'); i++)  // задаем размеры массива двумерного
    first += argv[1][i];

  for (i += 1; i < strlen(argv[1]); i++)
    second += argv[1][i];

  a = atoi(first.c_str()); // возвращает указатель
  b = atoi(second.c_str());

  mas = new int*[a];

  for (i = 0; i < a; i++)
    mas[i] = new int[b];

  for (i = 0; i < a; i++)
    for (j = 0; j < b; j++)
      mas[i][j] = 0;

  for (i = 0; i < a; i++)
    for (j = 0; j < b; j++, p++) 
    {
      if (p < argc)
        mas[i][j] = atoi(argv[p]);
    }
}

void Show(int** mas, int a, int b)
{
  for (int i = 0; i < a; i++) 
  {
    for (int j = 0; j < b; j++)
      cout << mas[i][j] << " ";
    cout << endl;
  }
}

int main(int argc, char* argv[])
{
  int **mas = nullptr;
  int a, b;
  Output(mas, a, b, argc, argv);
  int op;
  while (true) 
  {
    menu();
    cin >> op;
    switch (op)
    {
      case 1:
        Show(mas, a, b);
        break;
      case 2:
        break;
      case 3:
        break;
      case 4:
        break;
      case 5:
        break;
      case 6:
        break;
      case 7:
        break;
      case 8:
        delete[] mas;
        return 0;
      default:
        cerr << "Error" << endl;
    }
  }
  return 0;
}
