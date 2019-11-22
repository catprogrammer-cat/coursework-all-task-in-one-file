#include <iostream>

using namespace std;

int main()
{
    int size = 2;
    
    //create matrix
    int **array2d = new int * [size];
    for(int i = 0;i<size;i++){
        array2d[i] = new int [size];
    }
    //create array
    int *array1d = new int[size]; 
    
    
    
    // fill matrix
    srand ( time(0) );
    for(int i = 0; i<size;i++){
        for(int j = 0;j<size;j++){
            array2d[i][j] = (rand() % 100);
        }
    }
    
    
    // output matrix 
    for(int i = 0; i<size;i++){
        cout << i << ":\t";
        for(int j = 0;j<size;j++){
            if(array2d[i][j]>=0){
                cout << "[ " << array2d[i][j]  << "]";
            }else{
                cout << "[" << array2d[i][j]  << "]";
            }
            
        }
        cout << ";" << endl;
    }
    
    
    // output array1d
    for(int i = 0;i<size;i++){
        cout << "[" << array1d[i] << "]";
    }
    
    
    //delete matrix
    for(int i = 0;i<size;i++){
        delete[] array2d[i];
    }
    delete[] array2d;
    //delete array1d
    delete[] array1d;
    return 0;
}
