#include <iostream>
#include <stdlib.h>     
#include <time.h>
#include <stdio.h> // for gets, puts;
#include <conio.h> // for getch();
#include <string.h> // for strlen (s); necessary in online compiler
#include <cctype>

using namespace std;

/////////////////////////////////////////////////////////////////////////
///////////////////////////// File function////////////////////////////
/////////////////////////////////////////////////////////////////////////
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

void calculate_size_array2d(char* name, int &size_x, int &size_y){
    FILE* f;
    char s[100], *t; // t --> tabulation
    f = fopen(name, "rt"); //открыть файл для чтения как текстовый
    if (f == NULL){
        cout << "Cannot open file to veiw\n";
    }

    int i, j;
    // counter size of array2d from FILES
    for(i=0; fgets(s, 100, f); i++){ // Считывать из файла строки, пока они не закончатся
        j=0;
        t = strtok(s, " \t");
        for(;t != NULL; j++){
            // array2d[i][j] = atoi(t);
            t = strtok(NULL, " \t");
        }
    }
    int x, y;
    size_x = j;
    size_y = i;

    fclose(f);
}


int** read_and_push_array2d_return(char* name){
    
    FILE* f;
    char s[100], *t; // t --> tabulation
    f = fopen(name, "rt"); //открыть файл для чтения как текстовый
    if (f == NULL){
        return 0;
    }

    int i, j;
    // counter size of array2d from FILES
    for(i=0; fgets(s, 100, f); i++){ // Считывать из файла строки, пока они не закончатся
        j=0;
        t = strtok(s, " \t");
        for(;t != NULL; j++){
            // array2d[i][j] = atoi(t);
            t = strtok(NULL, " \t");
        }
    }
    int x, y;
    x = j;
    y = i;

    // create array using size
    //create matrix
    int **array2d = new int * [y];
    for(int i = 0;i<x;i++){
        array2d[i] = new int [x];
    }
    fclose(f);
    f = fopen(name, "rt"); //открыть файл для чтения как текстовый
    if (f == NULL){
       return 0;
    }
    // push values into array2d form FILES
    for(i=0; fgets(s, 100, f); i++){ // Считывать из файла строки, пока они не закончатся
        j=0;
        t = strtok(s, " \t");
        
        for(;t != NULL; j++){
            array2d[i][j] = atoi(t);
            t = strtok(NULL, " \t");
        }
    }
    fclose(f);
    return array2d;

}




/////////////////////////////////////////////////////////////////////////
///////////////////////////// Coursework_1////////////////////////////
/////////////////////////////////////////////////////////////////////////


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

void find_max_element_of_diagonals_array2d(int ** array2d,int size_x,int size_y,FILE *f3,char* file_name){ //coursework_1_4 --> // Найти минимум среди сумм модулей элементов диагоналей,
    //create matrix                                                       // параллельных побочной диагонали матрицы.
    //create array
    // using namespace std;

    
    // fclose(f3);

    if(size_x != size_y){
        cout << "0";
        fputs("0",f3);
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
        fputs("[",f3); fprintf(f3, "%d", array1d[i]); fputs("]",f3);  
        
    }
    cout << endl;
    fputs("\n",f3);
    cout << "Min element : " << min << endl;
    fputs("Min element : ",f3); fprintf(f3, "%d", min); fputs("\n",f3);
    cout << "Index of min element : " << index << endl;
    fputs("Index of min element : ",f3); fprintf(f3, "%d", index); 
   
    // delete array1d;
    delete [] array1d;
    }
    //fclose(f3);
}

    /////////////////////////////////////////////////////////////////////////
    ///////////////////////////// Coursework_2////////////////////////////
    /////////////////////////////////////////////////////////////////////////
void transfer_array2d_array1d(int ** array2d,int size_x,int size_y, FILE *f3,int flag){ // coursework_2_1 --> // Создать одномерный массив из элементов матрицы.
   
    //create array
    int *array1d = new int[size_x*size_y]; 
    // transfer 'array2d' to 'array1d'
    int index=0;
    for(int i=0;i<size_x;i++)
        for(int j=0;j<size_y; j++,index++)
            array1d[index] = array2d[i][j];
    index=0;
    for(int i=0;i<size_x;i++){
        for(int j=0;j<size_y; j++,index++){
            if(flag == 0){
                cout << "[" << array1d[index] << "]";
            }else{
                fputs("[", f3); fprintf(f3, "%d", array1d[index]); fputs("]", f3);
            }
        }        
    }

            
    
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

    /////////////////////////////////////////////////////////////////////////
    ///////////////////////////// Coursework_3////////////////////////////
    /////////////////////////////////////////////////////////////////////////
void determine_x_in_string(char name_2[],FILE *f3,bool flag){
    

    FILE* f2;
    f2 = fopen(name_2, "rt"); //открыть файл для создания как текстовый
    
    char s[200];
    // int i = 0, j;
    // cout << "nFirst words of all lines:\n";
    // fputs("\n3.1. First words of all lines:\n", f3);
    // while (fgets(s, 100, f3)) {
    //    fgets(s,100,f3);
    //    cout << s;
    // }

    int i, quantity=0;
    // bool check;
    int len; //=strlen(s); //Length of the string
    // cout << "hello world";
    while(fgets(s, 200, f2)){
        fgets(s, 200, f2);
        len = strlen(s);
        
        for (i=0; i<len; i++){
            if(s[i] ==  'x'){
                if(flag == 0){
                    cout << s;
                    cout << "    ++This string has x";
                    cout << endl;
                }else{
                    fprintf(f3, "%s", s);
                    fputs("    ++This string has x", f3);
                    fputs("\n",f3);
                }
                break;           
                
            }
            else if(s[i] == 'X'){
                if(flag == 0){
                    cout << s;
                    cout << "    ++This string has X";
                    cout << endl;
                }else{
                    fprintf(f3, "%s", s);
                    fputs("    ++This string has X", f3);
                    fputs("\n",f3);  
                }
                break;   

            }else{
                if(flag == 0){
                    cout << s;
                    cout << "    --This string hasn't x/X";
                    cout << endl;
                }else{
                    fprintf(f3, "%s", s);
                    fputs("    --This string hasn't x/X", f3);
                    fputs("\n",f3); 
                }
                break;
            }
        }
           
    }
    fclose(f2);
    

}



// void check_coincidence_numbers(char name_2[], FILE *f3){

//     FILE* f2;
//     f2 = fopen(name_2, "rt"); //открыть файл для создания как текстовый

//     char string_1[200];
//     char string_2[200];
    
//     int quantity = 0;

//     int counter = 0;
//     int len_1, len_2;

//     len_1 = strlen(string_1); //Length of the string
//     len_2 = strlen(string_2);

//     while(fgets(string_1, 200, f2)){
//         quantity++;
//     }
//     for(int ii = 0;ii < quantity;ii++){
//         if(ii%2 == 0){
//             fgets(string_1, 200, f2);
//             len_1 = strlen(string_1); //Length of the string
//             ii++;
//         }if(ii%2 != 0){
//             fgets(string_2, 200, f2);
//             len_2 = strlen(string_2);
//         }
//         for(int i=0; i<len_2;i++){
//             for(int j=0; j<len_1;j++){
//                 if(string_2[i] == string_1[j] && isdigit(string_1[i]) && isdigit(string_2[i])){
//                     counter++;
//                     break;
//                 }
//             }
//         }
//         for(int i=0;i<quantity;i++){
//             cout << "(" << string_1 << ")" << endl;
//             cout << "(" << string_2 << ")" << endl;
//             cout << "   counter = " <<  counter << endl;
//         }
//     }
// }


// //Перше слово кожного рядка
// void сруф (char* name2, FILE *f3)
// {
//     FILE* f2;
//     char s[100], *t=new char[100];
//     int i = 0, j; 
//     f2 = fopen(name2, "rt"); //открыть файл для чтения как текстовый

//     if (f2 == NULL) {
//         cout << "Cannot open file to veiw\n";
//         return;
//     }
//     cout << "\nFirst words of all lines:\n";
//     fputs("\n3.1. First words of all lines:\n", f3);
//     while (fgets(s, 100, f2)) { //считывать из файла строки, пока они не закончатся (пока
//         t = strtok(s, " ,.;-^=:!?");
//         puts(t);
//         fprintf(f3, "%s\n", t);
//     }
//     fclose(f2);
// }



void output_word_multiple_3_and_quantity(char name_2[], FILE *f3){
    
    
    FILE* f2;
    f2 = fopen(name_2, "rt"); //открыть файл для создания как текстовый
    char *t=new char[200];
    char s[200];
    
    int len_word = 0;

    // while(fgets(s, 200, f2)) {
    //     t = strtok(s, " ,.;-^=:!?");
    //     while (t != NULL){

    //         t = strtok(NULL, " .,;?!-");   
    //         cout << strlen(t) << endl;
    //     }
    // }
    int counter_1 = 0;
    int counter_2 = 0;
    while (fgets(s, 100, f2))
	{
		t = strtok(s, " ");
		while (t != NULL)
		{
			
				// printf("%s\t", t);
				// fprintf(f3, "%s\t", t);
                        
                len_word = strlen(t);
                if(len_word%3 == 0){

                    cout << t;
                    cout << " <-- " << len_word << endl;

                    fprintf(f3, "%s", t);
                    fputs(" <-- ", f3);
                    fprintf(f3, "%d", len_word);
                    fputs("\n", f3);
                    
                    
                }
                
			    t = strtok(NULL, " ");
		}
	}
    

  

}




using namespace std;

int main()
{   
    //////////////////////////////////////////////////////////////////////////////////
    //*****************************file operation***********************************//
    //////////////////////////////////////////////////////////////////////////////////
    char* name_1="F1.txt"; //имя файла на жёстком диске (в текущей папке проекта)
    char* name_2="F2.txt";
    char* name_3="F3.txt";
    // Declare file f3 for result work program 
    FILE* f3;

    f3 = fopen(name_3, "wt"); //create file to push a result of work programm
    if (f3 == NULL) {
        cout << "Cannot open file to view\n";
        return 1;
    }
    print_file(name_2); // print file F2.txt

    cout << endl << endl << endl; // separate information

    //////////////////////////////////////////////////////////////////////////////////
    //*****************************Prepare array2d to work************************//
    //////////////////////////////////////////////////////////////////////////////////
    // declare size of matrix
    int size_x;
    int size_y;
    // Calculate size_x and size_y (size of array2d in file)
    // We can use size_x and size_y as varible which have size of array2d
    calculate_size_array2d(name_1, size_x,size_y);
    // Output sizes x and y of array2d
    cout << "Size_x = " << size_x << endl;
    cout << "Size_y = " << size_y << endl;
    // -------------------------------------------------------------------------------------------- //

    
    fputs("Size_y = ", f3); fprintf(f3, "%d", size_y); fputs("\n", f3);
    fputs("\n", f3);
    // Create matrix
    int **array2d;
    array2d = read_and_push_array2d_return(name_1);
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
    // -------------------------------------------------------------------------------------------- //
    
    for(int i = 0; i<size_y;i++){
        fprintf(f3, "%d", i); fputs(":\t", f3); //cout << i << ":\t";  
        for(int j = 0;j<size_x;j++){
            if(array2d[i][j]>=0){
                fputs("[ ", f3); fprintf(f3, "%d", array2d[i][j]); fputs("]", f3); //cout << "[ " << array2d[i][j]  << "]"; 
            }else{
                fputs("[", f3); fprintf(f3, "%d", array2d[i][j]); fputs("]", f3); //cout << "[" << array2d[i][j]  << "]";
            }

        }
         fputs("\n", f3);
    }

    


    //////////////////////////////////////////////////////////////////////////////////
    //****************************************************************************//
    //////////////////////////////////////////////////////////////////////////////////

    ////////////////////////////////COURSEWORK 1_1////////////////////////////////////
    cout << "------------------------------------------" << endl;
    cout << "Coursework 1, task 1: \"Calculate the maximum value element of the main diagonal of the matrix.\"" << endl;

    cout << "Max value of main diagonal of matrix : " << max_value_matrix(array2d,size_x,size_y) << " <----- If width and height of matrix will not be equal , then return 0;(diagonal doesen't exist)"<< endl;
    cout << "------------------------------------------" << endl;
    // -------------------------------------------------------------------------------------------- //
    fputs("------------------------------------------\n", f3);
    fputs("Coursework 1, task 1: \"Calculate the maximum value element of the main diagonal of the matrix.\"\n", f3);
        fputs("Max value of main diagonal of matrix : ", f3);
        fprintf(f3, "%d", max_value_matrix(array2d,size_x,size_y)); // yourCounter of type int in this case
        fputs(" <----- If width and height of matrix will not be equal , then return 0;(diagonal doesen't exist)\n", f3);
    fputs("------------------------------------------\n", f3);
    




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
    // -------------------------------------------------------------------------------------------- //
    fputs("------------------------------------------\n", f3);
    fputs("Coursework 1, task 2: \"Calculate vector elements as quantities positive elements of the rows of the matrix.\"\n", f3);
    //int* array1d_p_1_2 = counter_positive_element_rows_array2d(array2d,size_x,size_y);
        fputs("Vector of quantities positive elements of the rows of the matrix : ", f3);
        for(int i = 0;i < size_y; i++){
            fputs("[", f3); fprintf(f3, "%d", array1d_p_1_2[i]); fputs("]", f3);
        }
        fputs("\n", f3);
    fputs("------------------------------------------\n", f3);








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
    // -------------------------------------------------------------------------------------------- //
    fputs("------------------------------------------\n", f3);
    fputs("Coursework 1, task 3: \"determine: the sum of the elements in those columns that do not contain negative elements.\"\n", f3);
    //int* array1d_p_1_3 = sum_positive_elements_column_array2d(array2d,size_x,size_y);
    fputs("Vector of sum of the elements of the columns of the matrix that do not contain negative elements : ", f3);
        for(int i = 0;i < size_y; i++){
            fputs("[", f3); fprintf(f3, "%d", array1d_p_1_3[i]); fputs("]", f3);
        }
        fputs("\n", f3);
    fputs("------------------------------------------\n", f3);






                                                                                                                                               
    ////////////////////////////////COURSEWORK 1_4////////////////////////////////////
    cout << "------------------------------------------" << endl;
    cout << "Coursework 1, task 4: \"Find the minimum among the sums of the modules of the elements of the diagonals parallel to the side diagonal of the matrix.\"" << endl;
    
    cout << "Vector of sum of the side diagonal of the matrix: ";
    
    cout << endl; 
    cout << "------------------------------------------" << endl;
    // -------------------------------------------------------------------------------------------- //
    fputs("------------------------------------------\n", f3);//
    fputs("Coursework 1, task 4: \"Find the minimum among the sums of the modules of the elements of the diagonals parallel to the side diagonal of the matrix.\"\n", f3);//
        fputs("Vector of sum of the side diagonal of the matrix: ", f3);
        //
        find_max_element_of_diagonals_array2d(array2d,size_x,size_y,f3,name_3);
        //
        fputs("\n", f3);
    fputs("------------------------------------------\n", f3);



    ////////////////////////////////COURSEWORK 2_1////////////////////////////////////
    cout << "------------------------------------------" << endl;
    cout << "Coursework 2, task 1: \"Create a one-dimensional array of matrix elements.\"" << endl;
    transfer_array2d_array1d(array2d,size_x,size_y,f3,0);
    cout << endl; 
    cout << "------------------------------------------" << endl;
    // -------------------------------------------------------------------------------------------- //
    fputs("------------------------------------------\n", f3);//
    fputs("Coursework 2, task 1: \"Create a one-dimensional array of matrix elements.\"\n", f3);//
        
        //
        transfer_array2d_array1d(array2d,size_x,size_y,f3,1);
        //
        fputs("\n", f3);
    fputs("------------------------------------------\n", f3);





    // char string_1[200] = "Hello, my name is xxxtentacion. I play in dota2 and warcraft3";
    char string_1[100] = "22233333332";
    char string_2[100] = "222232";
    
   
    
    ////////////////////////////////COURSEWORK 3_1////////////////////////////////////
    cout << "------------------------------------------" << endl;
    cout << "Coursework 3, task 1: \"Determine if the string contains the letter X (small or large).\"" << endl;
    puts(string_1);
    puts(string_2);
    determine_x_in_string(name_2, f3, 0);
    // determine_x_in_string(string_1); 
    cout << endl;
    cout << "------------------------------------------" << endl;
    // -------------------------------------------------------------------------------------------- //
    fputs("------------------------------------------\n", f3);//
    fputs("Coursework 3, task 1: \"Determine if the string contains the letter X (small or large).\"\n", f3);//
        
        //
        determine_x_in_string(name_2, f3, 1);
        //
    fputs("\n", f3);
    fputs("------------------------------------------\n", f3);


    ////////////////////////////////COURSEWORK 3_2////////////////////////////////////
    cout << "------------------------------------------" << endl;
    cout << "Coursework 3, task 2: \"Print the number of digits from line S2 that occur in line S1.\"" << endl;
    // puts(string_1);
    // puts(string_2);
    // check_coincidence_numbers(name_2, f3);
    // check_coincidence_numbers(string_1, string_2);
    cout << endl;
    cout << "------------------------------------------" << endl;



    output_word_multiple_3_and_quantity(name_2, f3);
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
