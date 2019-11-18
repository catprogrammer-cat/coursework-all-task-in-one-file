// Создать одномерный массив из элементов матрицы.

#include <iostream>

using namespace std;

int main()
{
    int x_size = 10;
    int y_size = 5;
    
    //create matrix
    int **array2d = new int * [y_size];
    for(int i = 0;i<x_size;i++){
        array2d[i] = new int [x_size];
    }
    //create array
    int *array1d = new int[x_size*y_size]; 
    
    
    
    // fill matrix
    srand ( time(0) );
    for(int i = 0; i<x_size;i++){
        for(int j = 0;j<y_size;j++){
            array2d[i][j] = (rand() % 100);
        }
    }
    
    // transfer 'array2d' to 'array1d'
    int index=0;
    for(int i=0;i<x_size;i++)
        for(int j=0;j<y_size; j++,index++)
        array1d[index] = array2d[i][j];
    
    
    // output matrix 
    for(int i = 0; i<y_size;i++){
        cout << i << ":\t";
        for(int j = 0;j<x_size;j++){
            if(array2d[i][j]>=0){
                cout << "[ " << array2d[i][j]  << "]";
            }else{
                cout << "[" << array2d[i][j]  << "]";
            }
            
        }
        cout << ";" << endl;
    }
    
    
    // output array1d
    for(int i = 0;i<(x_size*y_size);i++){
        cout << "[" << array1d[i] << "]";
    }
    
    
    // delete matrix
    for(int i = 0;i<x_size;i++){
        delete[] array2d[i];
    }
    delete[] array2d;
    //delete array1d
    delete[] array1d;
    return 0;
}
