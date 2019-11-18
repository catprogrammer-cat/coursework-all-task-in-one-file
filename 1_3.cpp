// Определить: сумму элементов в тех столбцах, 
// которые не содержат отрицательных элементов;

#include <iostream>

using namespace std;

int main()
{
    srand ( time(0) );
    int x = 10;
    int y = 5;
    //create matrix
    int **array2d = new int * [y];
    for(int i = 0;i<y;i++){
        array2d[i] = new int [x];
    }
    //create array
    int *array1d = new int[x]; 
    
    
    
    // fill matrix
    for(int i = 0; i<y;i++){
        for(int j = 0;j<x;j++){
            array2d[i][j] = (rand() % 20)-10;
        }
    }
    
    
    // output matrix 
    for(int i = 0; i<y;i++){
        cout << i << ":\t";
        for(int j = 0;j<x;j++){
            if(array2d[i][j]>=0){
                cout << "[ " << array2d[i][j]  << "]";
            }else{
                cout << "[" << array2d[i][j]  << "]";
            }
            
        }
        cout << ";" << endl;
    }
    /////////
    // Calcultation
    for(int i=0;i<y;i++){
        array1d[i] = 0;
        for(int j=0;j<x;j++){
            
            if(array2d[j][i] < 0){
                array1d[i] = 0;
                break;
            }
            else{
                array1d[i]+=array2d[j][i];
            }
         
        }
    }

    /////////
    for(int i=0;i<x;i++){
        cout << "[" << array1d[i] << "]";
    }
    
    //////////////
    
    //delete matrix
    for(int i = 0;i<y;i++){
        delete[] array2d[i];
    }
    delete[] array2d;
    //delete array1d
    delete[] array1d;
    return 0;
}
