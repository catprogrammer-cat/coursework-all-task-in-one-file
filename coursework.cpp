
#include <iostream>

int max_value_matrix(int size){ //coursework_1_1 --> // Вычислить значение максимального 
    int max;                                       // элемента главной диагонали матрицы.
    // Create array2d
    int **array2d = new int * [size];
    for(int i = 0;i<size;i++){
        array2d[i] = new int [size];
    }
    // Create array
    int *array1d = new int[size]; 
    // fill matrix
    srand ( time(0) );
    for(int i = 0; i<size;i++){
        for(int j = 0;j<size;j++){
            array2d[i][j] = (rand() % 100);
        }
    }
    // Calculating matrix
    for(int i=0,j=0; i<size,j<size; i++,j++){
        array1d[i] = array2d[i][j];
    }
    // Find max value of array1d(diagonal)
    max = array1d[0];
    for(int i = 0; i<size; i++){
        if(array1d[i] > max){
            max = array1d[i];
        }
    }
    //delete matrix
    for(int i = 0;i<size;i++){
        delete[] array2d[i];
    }
    delete[] array2d;
    //delete array1d
    delete[] array1d;
    return max;
}

int counter_positive_element_rows_array2d(int x,int y){ //coursework_1_2 --> // Вычислить элементы вектора как количества 
    int **array2d = new int * [y];                                                  // положительных элементов строк матрицы.
    for(int i = 0;i<size;i++){
        array2d[i] = new int [x];
    }
    //create array
    int *array1d = new int[y]; 
    // fill matrix
    srand ( time(0) );
    for(int i = 0; i<y;i++){
        for(int j = 0;j<x;j++){
            array2d[i][j] = (rand() % 20)-10;
        }
    }
    // counter positive element
    int quantity = 0;
    for(int i=0; i<y; i++){
        quantity = 0;
        for(int j=0;j<x;j++){
            if(array2d[i][j]>=0){
                quantity++;
            }
        }
        array1d[i] = quantity;
    }
    //delete matrix
    for(int i = 0;i<size;i++){
        delete[] array2d[i];
    }
    delete[] array2d;
    //delete array1d
    delete[] array1d;
    return array1d;
}

int sum_positive_elements_column_array2d(int x,int y){ //coursework_1_3 --> // Определить: сумму элементов в тех столбцах, 
    //create matrix                                                       // которые не содержат отрицательных элементов;
    int **array2d = new int * [y];
    for(int i = 0;i<y;i++){
        array2d[i] = new int [x];
    }
    //create array
    int *array1d = new int[x]; 
    // fill matrix
    srand ( time(0) );
    for(int i = 0; i<y;i++){
        for(int j = 0;j<x;j++){
            array2d[i][j] = (rand() % 20)-10;
        }
    } 
    // Calculate sum of positive element which constist
    // in collumn without negative element array2d
    for(int i=0;i<x;i++){
        array1d[i] = 0;
        for(int j=0;j<y;j++){       
            if(array2d[j][i] < 0){
                array1d[i] = 0;
                break;
            }
            else{
                array1d[i]+=array2d[j][i];
            }
        }
    }
    //delete matrix
    for(int i = 0;i<y;i++){
        delete[] array2d[i];
    }
    delete[] array2d;
    //delete array1d
    delete[] array1d;
    return array1d;
}

int find_max_element_of_diagonals_array2d(int size){ //coursework_1_4 --> // Найти минимум среди сумм модулей элементов диагоналей,
    //create matrix                                                       // параллельных побочной диагонали матрицы.
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
    // fill array1d of sum of diagonals
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
    // calculate min element
    int min = array1d[0];
    // int index = 0;
    for(int i = 0; i < quantity_a + quantity_b; i++) {
        if(array1d[i] < min){
            min = array1d[i];
        }
    }
    //delete matrix
    for(int i = 0;i<size;i++){
         delete[] array2d[i];
     }
    delete[] array2d;
    //delete array1d
    //delete [] array1d;
    return min;
}

    
int* transfer_array2d_array1d(int size_x,int size_y){ // coursework_2_1 --> // Создать одномерный массив из элементов матрицы.
    //create matrix                                   // v_1
    int **array2d = new int * [size_y];
    for(int i = 0;i<size_x;i++){
        array2d[i] = new int [size_x];
    }
    //create array
    int *array1d = new int[size_x*size_y]; 
    // fill matrix
    srand ( time(0) );
    for(int i = 0; i<size_x;i++){
        for(int j = 0;j<size_y;j++){
            array2d[i][j] = (rand() % 100);
        }
    }
    // transfer 'array2d' to 'array1d'
    int index=0;
    for(int i=0;i<size_x;i++)
        for(int j=0;j<size_y; j++,index++)
            array1d[index] = array2d[i][j];
    // delete matrix
    for(int i = 0;i<size_x;i++){
        delete[] array2d[i];
    }
    delete[] array2d;
    // //delete array1d
    // delete[] array1d;
    return array1d;
}





using namespace std;

int main()
{
    cout<<max_value_matrix(1000);

    return 0;
}
