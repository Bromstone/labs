#include<stdlib.h>
#include<stdio.h>
#include<malloc.h>

int mat_m = 0;              //размеры матрицы
int mat_n = 0;

int *first;                 //массивы схемы размещения 3
int *second;
int *third;

int *amount_of_numbers;
int *sum_in_line;

int size = 0;                                                        //размер массивов два и три для динамического выделения памяти, вывода этих массивов и работы с первым массивом"%d\n", line_end

void matrix_read(char file_name[40]) {                               //читаем матрицу
    
    FILE *file = fopen(file_name, "r");                              //открываем файл
    
    if (file == NULL) {
        
        fprintf(stderr, "Не удалось открыть файл \"%s\"\n", file_name);
        
    }
    
    fscanf(file, "%d%d", &mat_m, &mat_n);                           //считываем размеры матрицы
    
    first = (int*)malloc(mat_m * sizeof(int));                      //выделяем память под первый массив
    
    for (int a = 0; a < mat_m; a++) {                               //забиваем первый массив значениями -1, чтобы можно было проверять, не пуста ли ячейка
        first[a] = -1;
    }
    
    first[0] = 0;                                                   //индексация элементов первой строки всегда начинается с нулевого элемента второго массива
    
    int counter = 0;                                                //переменная, которая знает, в каком месте второго массива мы находимся
    
    for (int i = 0; i < mat_m; i++) {
        
        for (int j = 0; j < mat_n; j++) {
            
            int tmp;
            
            fscanf(file, "%d", &tmp);                                //получаем очередное значение из матрицы
            
            if (tmp != 0) {
                
                
                if(first[i] == -1) {                                 //ячейка первого массива пуста, значит мы встретили первое ненулевое значение в текущей строке (за исключением когда мы 
                                                                     //обрабатываем первую строку;
                    first[i] = size;         //присваиваем элементу первого массива размер второго массива (этот размер будет номером следующей ячейки второго массива)
                    
                }                                                    
            
                second = (int*)realloc(second, (size + 1) * sizeof(int));   //выделяем память под очередную ячейку в массивах 2 и 3
                third = (int*)realloc(third, (size + 1) * sizeof(int));
                size++;                                                     //увеличиваем на 1 значение размера массива
                    
                second[counter] = j;                                //в нужную ячейку второго массива записываем номер столбца, в котором находится ненулевой элемент
                third[counter] = tmp;                               //в такую же по номеру ячейку третьего массива записываем значение ненулевого элемента
                
                counter++;                                          //при каждом вхождении ненулевого элемента будет заполняться еще одна ячейка, поэтому увеличиваем размер на 1
                
            }
            
        }
        
    }
    
}

void print_matrix_in() {                                            //печать матрицы в физическом представлении
    
    printf("Physical matrix view:\n\n");
    
    for(int i = 0; i < mat_m; i++) {
        
        printf("%d ", first[i]);
        
    }
    
    printf("\n");
    
    for(int i = 0; i < size; i++) {
        
        printf("%d ", second[i]);
        
    }
    
    printf("\n");
    
    for(int i = 0; i < size; i++) {
        
        printf("%d ", third[i]);
        
    }
    
    printf("\n");
    printf("\n");
    
}

void print_matrix_twoDimensions() {                                 //читаем матрицу
    
    printf("Two-dimensional matrix view:\n\n");
    
    int position = 0;                                               //здесь лежит текущий номер ячейки второго массива, в котором мы находимся
    
    for(int i = 0; i < mat_m; i++) {                                //отталкиваемся от разницы значений соседних элементов первого массива
        
        int line_end;                                               //эта переменная хранит в себе номер элемента второго массива, с которого начинаюся элементы уже след. строки матрицы
        
        if(i < mat_m - 1) {
            line_end = first[i + 1];
        }
        
        else {
            line_end = mat_n - 1;
        }
        
        for(int j = 0; j < mat_n; j++) {
            
            if(j !=  second[position] || position > line_end) {
                
                printf("0 ");
                
            }
            
            else {
                
                printf("%d ", third[position]);                     //печатаем соответствующее значение из 3 массива
                position++;                                         //увеличиваем счетчик
                
            }
            
        }
        
        printf("\n");
        
    }
    
    printf("\n");
    
}

void matrix_processing() {
    
    amount_of_numbers = (int*)malloc(mat_m * sizeof(int));          //массив количества чисел в каждой из строк массива
    sum_in_line = (int*)malloc(mat_m * sizeof(int));                //массив который содержит суммы каждой из строк массива
    
    for(int a = 0; a < mat_m; a++) {
        amount_of_numbers[a] = 0;
        sum_in_line[a] = 0;
    }
    
    int max_amount_of_numbers = 0;
    
    printf("Matrix processing...\n\n");
    
    int position = 0;
    int line_end;
    
    for(int i = 0; i < mat_m; i++) {
        
        if(i < mat_m - 1) {
            line_end = first[i + 1];
        }
        
        else {
            line_end = mat_n - 1;
        }
        
        for(int j = 0; j < mat_n; j++) {                             //считаем количество и сумму по каждой строке
            
            if(j !=  second[position] || position > line_end) {
                
                continue;
                
            }
            
            else {
                
                amount_of_numbers[i]++;
                sum_in_line[i] = sum_in_line[i] + third[position];
                position++;
                
            }
            
        }
        
    }
    
    for(int p = 0; p < mat_m; p++) {                 
                                                                    //ищем максимальное количество чисел в строках массива
        if(amount_of_numbers[p] > max_amount_of_numbers) {
            
            max_amount_of_numbers = amount_of_numbers[p];
            
        }
    }
    
    printf("Max amount of numbers: ");
    printf("%d", max_amount_of_numbers);
    printf("\n\n");
    
    for(int k = 0; k < mat_m; k++) {
        
        if(amount_of_numbers[k] == max_amount_of_numbers) {
            
            printf("Line number: ");
            printf("%d", k);
            printf("\n");
            printf("Sum: ");
            printf("%d", sum_in_line[k]);
            printf("\n");
            printf("\n");
        }
        
    }
    
}

int main(int argc, char* argv[]) {

    matrix_read(argv[1]);
    print_matrix_in();
    print_matrix_twoDimensions();
    matrix_processing();
    
    return 0;
    
}
