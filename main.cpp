#include <iostream>
#include <cstdlib>

using namespace std;

void Output(int argc, int * array, char * argv[])
{ 
  if (argc != 1)
  {
    for(int i = 1; i < argc; i++)
    {
      array[i] = atoi(argv[i]);
    }
  
    int mas[array[1]][array[3]];
    int count = (argc-4);
        
    for (int i = 0; i < array[1]; i++)
    {       
      for (int j = 0; j < array[3]; j++)
      {
        mas[i][j] = array[4 + i*array[3] + j];              
        cout << mas[i][j] << " ";
      }
      cout << endl;
    }   
  }
  else
    cout << "The matrix is ​​empty" << endl;
}

int main(int argc, char* argv[])
{
  cout << "Operations:" << endl;
  cout << "1. Output matrix" << endl;
  cout << "2. Add the matrix" << endl;
  cout << "3. Add Multiply the matrix" << endl;
  cout << "4. Transpose the matrix" << endl;
  cout << "5. Save to file" << endl;
  cout << "6. Upload from file" << endl;
  cout << "7. Sort matrix" << endl;

  int *array = new int[argc-1];

  int op = 0;
  cin >> op;

  switch(op)
  {
    case 1:
      Output(argc, array, argv);
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
  }

  delete [] array;
  return 0;
}
