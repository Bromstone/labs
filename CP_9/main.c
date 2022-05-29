#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char strings_array[12][115];

void strings_read(char file_name[30]) {                                 //считываем ключи со строками в массив
    
    printf("- Reading keys and strings...\n\n");
    
    FILE *file;
    
    file = fopen(file_name, "r");
    
    for(int i = 0; i < 12; i++) {
        
        fgets(strings_array[i], 115, file);
        
        puts(strings_array[i]);
        
    }
    
}

int check_order() {                                                    //проверяем изначальный порядок ключей (прямой - 0, обратный - 1 или перемешанный - 2)
    
    int n_gt_p = -1;                                                   //переменная которая хранит результат первого сравнения (1 если след > пред, 0 если наоборот)
    
    for(int i = 0; i < 11; i++) {
        
        if(strncmp(strings_array[i], strings_array[i+1], 6) < 0 && n_gt_p == -1) {
            n_gt_p = 1;
        }
        
        else if(strncmp(strings_array[i], strings_array[i+1], 6) > 0 && n_gt_p == -1) {
            n_gt_p = 0;
        }
        
        else if(strncmp(strings_array[i], strings_array[i+1], 6) < 0 && n_gt_p == 1) {   //условие будет выполняться, если элементы идут по возрастанию
            continue;
        }
        
        else if(strncmp(strings_array[i], strings_array[i+1], 6) > 0 && n_gt_p == 0) {   //условие будет выполняться, если элементы идут по убыванию
            continue;
        }
        
        
        else if(strncmp(strings_array[i], strings_array[i+1], 6) < 0 && n_gt_p == 0) {   //массив сортирован рандомно
            return 2;
        }
        
        else if(strncmp(strings_array[i], strings_array[i+1], 6) > 0 && n_gt_p == 1) {   //массив сортирован рандомно
            return 2;
        }
        
    }
    
    if(n_gt_p == 0) {
        return 1;
    }
    
    else {
        return 0;
    }
    
}

void sorting_backwards() {
    
    char tmp[115];
    
    for(int i = 0; i < 6; i++) {
        
        strcpy(tmp, strings_array[11-i]); //в tmp лежит последняя строка
        strcpy(strings_array[11-i], strings_array[i]); // складываем первую строку в последнюю
        strcpy(strings_array[i], tmp); //складываем в первую строку tmp (т.е. последнюю)
        
    }
    
}

void print_array() {
    
    for(int i = 0; i < 12; i++) {
    
        puts(strings_array[i]);
        
    }
    
}

void shaker_sort(int count) {

  int left = 0, right = count - 1;             // левая и правая границы сортируемой области массива
  int flag = 1;                                // флаг наличия перемещений
                                               // Выполнение цикла пока левая граница не сомкнётся с правой и пока в массиве имеются перемещения
  while ((left < right) && flag > 0) {
      
    flag = 0;
    
    for (int i = left; i < right; i++) {  //двигаемся слева направо
        
      if (strncmp(strings_array[i], strings_array[i+1], 6) > 0) {        // если следующий элемент меньше текущего, меняем их местами
        char tmp[115];
        strcpy(tmp, strings_array[i]);
        strcpy(strings_array[i], strings_array[i + 1]);
        strcpy(strings_array[i + 1], tmp);
        flag = 1;      // перемещения в этом цикле были
      }
      
    }
    
    right--; // сдвигаем правую границу на предыдущий элемент
    
    for (int i = right; i > left; i--) {  //двигаемся справа налево
        
      if (strncmp(strings_array[i-1], strings_array[i], 6) > 0) {        // если предыдущий элемент больше текущего, меняем их местами
        char tmp[115];
        strcpy(tmp, strings_array[i]);
        strcpy(strings_array[i], strings_array[i - 1]);
        strcpy(strings_array[i - 1], tmp);
        flag = 1;    // перемещения в этом цикле были
      }
      
    }
    
    left++; // сдвигаем левую границу на следующий элемент
    
  }
  
}

int binary_search(char key[7], int n)
{
    int low, high, middle;
    low = 0;
    high = n - 1;
    while (low <= high) {
        
        middle = (low + high) / 2;
        if (strncmp(key, strings_array[middle], 6) < 0) {
            high = middle - 1;
        }
        else if (strncmp(key, strings_array[middle], 6) > 0) {
            low = middle + 1;
        }
        else {
            printf("\n%s\n", strings_array[middle]);
            return 0;
        }
        
    }
    return -1;
}

int main(int argc, char* argv[]) {
    
    strings_read(argv[1]);
    
    printf("- Checking the order of strings...\n\n");
    
    if(check_order() == 0) {
        printf("- Strings are sorted just OK. No need to sort them.\n\n");
    }
    else if(check_order() == 1) {
        printf("- Strings array is sorted! But backwards... Need to sort it =(\n\n");
        sorting_backwards();
        print_array();
        printf("- Now it's sorted!\n\n");
    }
    else {
        printf("- Strings array is unsorted. Need to sort it.\n\n");
        shaker_sort(12);
        print_array();
        printf("- Now it's sorted!\n\n");
    }
    
    char c;
    char value[7];
    printf("Choose an option:\n");
    printf("1) Return an element by a key\n");
    while ((c = getchar()) != EOF) {                            // Чтение символа из потока ввода
        if (c == '\n') continue;
        switch (c) {
            case '1':
                printf("\nEnter the value: ");
                scanf("%s", value);
                binary_search(value, 12);
                break;
            default:
                printf("The number you entered isn't in the menu :(\nPlease try again, in case you made a mistake\n");
                break;
        }
        printf("Choose an option:\n");
        printf("1) Return an element by a key\n");
    }
    return 0;
}
