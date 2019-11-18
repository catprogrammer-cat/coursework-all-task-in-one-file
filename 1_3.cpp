// Определить: сумму элементов в тех столбцах, 
// которые не содержат отрицательных элементов;
#include <iostream>

using namespace std;

int main()
{
    
    int x = 15;
    int y = 3;
    
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
