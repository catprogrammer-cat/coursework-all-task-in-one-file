// Найти минимум среди сумм модулей элементов диагоналей,
// параллельных побочной диагонали матрицы.

#include <iostream>
#include <stdlib.h>     
#include <time.h>

using namespace std;

 

int main()
{
    int size = 3;
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
            array2d[i][j] = (rand() % 10);
        }
    }
    
    
    ///////////////////////////////////////////////////
    
    
    int sum = 0;
    int calculation = 0;
    // Calculate quantity of first part of diagonals(with middle diagonal)
    // and second part of diagonals(withoit middle diagonal)
    int quantity_a = size - 1;
    int quantity_b = size - 2;
    
    
    
    
    for(int num = 0; num<quantity_a; num++){
        
        calculation = num - (size - 2); //size = 6 --> 4 ?? size = 5 --> 

        sum = 0;

        for(int i = 0;i<size-abs(calculation);i++){
            sum += abs(array2d[i][size-1-i+calculation]);
        }

    array1d[num] = sum;
    }
    for(int num = 0; num<quantity_b; num++){
        calculation = num - (size - 2); // 0 - (-3); ?? 1 - (-2)
        sum = 0;
        for(int i = quantity_a;i>=0+abs(calculation);i--){
            sum += abs(array2d[i][abs(size-1-i-calculation)]);
        }
    int minus = size-4;  
    array1d[(size+minus)-num] = sum;
    
    }
    
    
    
    
    
    
    
    ///////////////////////////////////////////////////
    
    
    
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
    
    
    // Output array1d
    for(int i = 0; i < quantity_a + quantity_b; i++) {
        cout << "[" << array1d[i] << "]";
    }
    int min = array1d[0];
    int index = 0;
    for(int i = 0; i < quantity_a + quantity_b; i++) {
        if(array1d[i] < min){
            min = array1d[i];
            
        }
    }
    for(int i = 0; i < quantity_a + quantity_b; i++){
        if(array1d[i] == min){
            break;
        }
        else{
            index++;
        }
    }
    
    cout << "\nmin element: " << min;
    cout << "\nindex max element: " << index << endl;
    
    //delete matrix
    for(int i = 0;i<size;i++){
         delete[] array2d[i];
     }
    delete[] array2d;
    //delete array1d
    //delete [] array1d;
    system("pause");
    return 0;
}
