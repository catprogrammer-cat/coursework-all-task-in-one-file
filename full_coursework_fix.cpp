#include <iostream>
#include <stdlib.h>     
#include <time.h>

#include <stdio.h> // for gets, puts;
#include <conio.h> // for getch();
#include <string.h> // for strlen (s); necessary in online compiler

#include <cctype>

//#include <cctype>
using namespace std;

void print_file(char* name){
    char s[100];
    FILE* f;
    f=fopen(name, "rt"); //открыть файл для чтения как текстовый
    if(f==NULL){
        cout<<"Cannot open file to veiw\n"; return;
    }
    
    cout << "\nView file" << endl;
    while (fgets(s, 100, f)){ //считывать из файла строки, пока они не закончатся (пока

    //не достигнут конец файла)

        s[strlen(s)-1]='\0'; //без этой строки строки будут выводиться через пустую

    //строку из-за добавленного ранее '\n'

    puts(s); //вывести строку на экран

    }
    fclose(f);
}

int max_value_matrix(int ** array2d,int size_x,int size_y){ //coursework_1_1 --> // Вычислить значение максимального 
                                                            // элемента главной диагонали матрицы.
    if(size_x != size_y){
        return 0;
    }
    else{
    int size = size_x; 
    int max;
    // Create array2d
    // Create array
    int *array1d = new int[size]; 
    // // fill matrix
    // srand ( time(0) );
    // for(int i = 0; i<size;i++){
    //     for(int j = 0;j<size;j++){
    //         array2d[i][j] = (rand() % 100);
    //     }
    // }
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

    //delete array1d
    delete[] array1d;
    return max;
    }
    
}

int* counter_positive_element_rows_array2d(int ** array2d,int size_x,int size_y){ //coursework_1_2 --> // Вычислить элементы вектора как количества 
    //create array
    int *array1d = new int[size_y]; 
    // counter positive element
    int quantity = 0;
    for(int i=0; i<size_y; i++){
        quantity = 0;
        for(int j=0;j<size_x;j++){
            if(array2d[i][j]>=0){
                quantity++;
            }
        }
        array1d[i] = quantity;
    }
    //delete array1d
    // delete[] array1d;
    return array1d;
}

int* sum_positive_elements_column_array2d(int ** array2d,int size_x,int size_y){ //coursework_1_3 --> // Определить: сумму элементов в тех столбцах, 
    //create matrix                                                       // которые не содержат отрицательных элементов;
   
    //create array
    int *array1d = new int[size_x];   
    // Calculate sum of positive element which constist
    // in column without negative element array2d
    for(int i=0;i<size_x;i++){
        array1d[i] = 0;
        for(int j=0;j<size_y;j++){       
            if(array2d[j][i] < 0){
                array1d[i] = 0;
                break;
            }
            else{
                array1d[i]+=array2d[j][i];
            }
        }
    }   
    //delete array1d
    // delete[] array1d;
    return array1d;
}

void find_max_element_of_diagonals_array2d(int ** array2d,int size_x,int size_y){ //coursework_1_4 --> // Найти минимум среди сумм модулей элементов диагоналей,
    //create matrix                                                       // параллельных побочной диагонали матрицы.
    //create array
    using namespace std;
    if(size_x != size_y){
        cout << "0";
    }else{
    int size = size_x; 
    // fill array1d of sum of diagonals
    ///////////////////////////////////////////////////
    int sum = 0;
    int calculation = 0;
    // Calculate quantity of first part of diagonals(with middle diagonal)
    // and second part of diagonals(without middle diagonal)
    int quantity_a = size - 1;
    int quantity_b = size - 2;
    int *array1d = new int[quantity_a+quantity_b];
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
    
    for(int i = 0; i < quantity_a + quantity_b; i++) {
        if(array1d[i] < min){
            min = array1d[i];
        }
    }
    // calculate index of min element
    int index = 0;
    for(int i = 0; i < quantity_a + quantity_b; i++){
        if(array1d[i] == min){
            break;
        }
        else{
            index++;
        }
    }

    // output vector(array1d)
    for(int i = 0; i < quantity_a + quantity_b; i++) {
        cout << "[" << array1d[i] << "]";
    }
    cout << endl;
    cout << "Min element : " << min << endl;
    cout << "Index of min element : " << index; 
   
    // delete array1d;
    delete [] array1d;
    }
    
}

    
void transfer_array2d_array1d(int ** array2d,int size_x,int size_y){ // coursework_2_1 --> // Создать одномерный массив из элементов матрицы.
   
    //create array
    int *array1d = new int[size_x*size_y]; 
    // transfer 'array2d' to 'array1d'
    int index=0;
    for(int i=0;i<size_x;i++)
        for(int j=0;j<size_y; j++,index++)
            array1d[index] = array2d[i][j];
    index=0;
    for(int i=0;i<size_x;i++)
        for(int j=0;j<size_y; j++,index++)
            cout << "[" << array1d[index] << "]";
    
    //delete array1d
    delete[] array1d;
    
}

// Создать новую матрицу из тех столбцов заданной матрицы, не
// содержат элементы из диапазона (10, 20].

// int create_array2d_not_range(int ** array2d, int size_x,int size_y){
//     //create matrix
//     int new_size_x = size_x;
//     int new_size_y = size_y;
//     for(int i = 0; i < size_y; i++){
//         for(int i = 0; i < size_x; i++){
//             if(array2d[i][j] > 10 && array2d[i][j] <= 20){
//                 new_size_x--;
//             }
//         }
//     }
//     //create matrix
//     int **array2d_new = new int * [new_size_y];
//     for(int i = 0;i<new_size_x;i++){
//         array2d_new[i] = new int [new_size_x];
//     }

//     for(int i = 0; i < size_y; i++){
//         for(int i = 0; i < size_x; i++){
//             array2d_new[][];
//             if(array2d[i][j] > 10 && array2d[i][j] <= 20){
//                 new_size_x--;
//             }
//         }
//     }
    

   
// }

void determine_x_in_string(char string[]){
    
    int i, len, quantity=0;
    bool check;
    len=strlen(string); //Length of the string
    
    for (i=0; i<len; i++){
        if(string[i] ==  'x'){
            check = true;
            printf("This string has x\n");
            break;
        }
        else if(string[i] == 'X'){
            check = true;
            printf("This string has X\n");
            break;

        }else{
            check = false;            
        }

    }
    if(check == false){
        printf("This string hasn't x/X\n");         
    }
}



void check_coincidence_numbers(char string_1[], char string_2[]){
    int len_1, len_2, quantity=0;
    len_1 = strlen(string_1); //Length of the string
    len_2 = strlen(string_2);
    int counter = 0;
    int i=0;
    int j=0;
    for(;i<len_1;i++){
        for(;j<len_2;j++){
            if(string_1[i] == string_2[j] && isdigit(string_1[i]) && isdigit(string_2[i])){
                counter++;
                break;
            }
        }
    }
    cout << counter << endl;
}



using namespace std;

int main()
{   
    //////////////////////////////////////////////////////////////////////////////////
    //*****************************file operation***********************************//
    //////////////////////////////////////////////////////////////////////////////////
    
    char* name_1 = "F1.txt"; //имя файла на жёстком диске (в текущей папке проекта)
    char* name_2 = "F2.txt"; //имя файла на жёстком диске (в текущей папке проекта)

    print_file(name_2);


    cout << endl << endl << endl;


    // declare size of matrix
    int size_x = 6;
    int size_y = 6;
    //create matrix
    int **array2d = new int * [size_y];
    for(int i = 0;i<size_x;i++){
        array2d[i] = new int [size_x];
    }
    // fill matrix
    srand ( time(0) );
    for(int i = 0; i<size_y;i++){
        for(int j = 0;j<size_x;j++){
            array2d[i][j] = (rand() % 20) - 10;
        }
    }
    // output matrix 
    for(int i = 0; i<size_y;i++){
        cout << i << ":\t";
        for(int j = 0;j<size_x;j++){
            if(array2d[i][j]>=0){
                cout << "[ " << array2d[i][j]  << "]";
            }else{
                cout << "[" << array2d[i][j]  << "]";
            }

        }
        cout << ";" << endl;
    }
    //////////////////////////////////////////////////////////////////////////////////
    //****************************************************************************//
    //////////////////////////////////////////////////////////////////////////////////

    ////////////////////////////////COURSEWORK 1_1////////////////////////////////////
    cout << "------------------------------------------" << endl;
    cout << "Coursework 1, task 1: \"Calculate the maximum value element of the main diagonal of the matrix.\"" << endl;
    cout << "Max value of main diagonal of matrix : " << max_value_matrix(array2d,size_x,size_y) << " <----- If width and height of matrix will not be equal , then return 0;(diagonal doesen't exist)"<< endl;
    cout << "------------------------------------------" << endl;




    ////////////////////////////////COURSEWORK 1_2////////////////////////////////////
    cout << "------------------------------------------" << endl;
    cout << "Coursework 1, task 2: \"Calculate vector elements as quantities positive elements of the rows of the matrix.\"" << endl;
    //double* vector_after = return_vector(array_2d,vector);
    int* array1d_p_1_2 = counter_positive_element_rows_array2d(array2d,size_x,size_y);
    cout << "Vector of quantities positive elements of the rows of the matrix : ";
    for(int i = 0;i < size_y; i++){
        cout << "[" << array1d_p_1_2[i] << "]" ;
    }
    cout << endl; 
    cout << "------------------------------------------" << endl;




    ////////////////////////////////COURSEWORK 1_3////////////////////////////////////
    cout << "------------------------------------------" << endl;
    cout << "Coursework 1, task 3: \"determine: the sum of the elements in those columns that do not contain negative elements.\"" << endl;
    int* array1d_p_1_3 = sum_positive_elements_column_array2d(array2d,size_x,size_y);
    cout << "Vector of sum of the elements of the columns of the matrix that do not contain negative elements : ";
    for(int i = 0;i < size_x; i++){
        cout << "[" << array1d_p_1_3[i] << "]" ;
    }
    cout << endl; 
    cout << "------------------------------------------" << endl;

                                                                                                                                               
    ////////////////////////////////COURSEWORK 1_4////////////////////////////////////
    cout << "------------------------------------------" << endl;
    cout << "Coursework 1, task 4: \"Find the minimum among the sums of the modules of the elements of the diagonals parallel to the side diagonal of the matrix.\"" << endl;
    
    cout << "Vector of sum of the side diagonal of the matrix: ";
    find_max_element_of_diagonals_array2d(array2d,size_x,size_y);
    cout << endl; 
    cout << "------------------------------------------" << endl;

    ////////////////////////////////COURSEWORK 2_1////////////////////////////////////
    cout << "------------------------------------------" << endl;
    cout << "Coursework 2, task 1: \"Create a one-dimensional array of matrix elements.\"" << endl;
    transfer_array2d_array1d(array2d,size_x,size_y);
    cout << endl; 
    cout << "------------------------------------------" << endl;

    // char string_1[200] = "Hello, my name is xxxtentacion. I play in dota2 and warcraft3";
    char string_1[200] = "2";
    char string_2[200] = "2222";
    ////////////////////////////////COURSEWORK 3_1////////////////////////////////////
    cout << "------------------------------------------" << endl;
    cout << "Coursework 3, task 1: \"Determine if the string contains the letter X (small or large).\"" << endl;
    puts(string_1);
    determine_x_in_string(string_1); 
    cout << endl;
    cout << "------------------------------------------" << endl;
    
    ////////////////////////////////COURSEWORK 3_2////////////////////////////////////
    cout << "------------------------------------------" << endl;
    cout << "Coursework 3, task 2: \"Print the number of digits from line S2 that occur in line S1.\"" << endl;
    puts(string_1);
    puts(string_2);
    check_coincidence_numbers(string_1, string_2);
    cout << endl;
    cout << "------------------------------------------" << endl;


    //////////////////////////////////////////////////////////////////////////////////
    //****************************************************************************//
    //////////////////////////////////////////////////////////////////////////////////

    // delete matrix
    for(int i = 0;i<size_x;i++){
        delete[] array2d[i];
    }
    delete[] array2d;

    

    system("pause");
    return 0;
}
