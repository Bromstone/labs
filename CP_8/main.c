 #include<stdio.h>
#include<stdlib.h>

#include "lin.h"

void print_menu() {                                             // Функция вывода меню
    printf("\nSelect the desired action by writing the appropriate number:\n");
    printf("1) Initialise list\n");
    printf("2) Add an element to start of the list\n");
    printf("3) Add an element to end of the list\n");
    printf("4) Add an element to a certain position in the list\n");
    printf("5) Delete the list\n");
    printf("6) Delete a certain element from the list\n");
    printf("7) Print the list\n");
    printf("8) Print the size of the list\n");
    printf("9) Delete 'n' elements from the mid of the list\n");
}

int main(void)                                                  
{
    list *h = NULL;
    int pos = 0;
    char value[30];                                                  
    char c;                                                     
    printf("Linear list lab\n");
    print_menu();
    while ((c = getchar()) != EOF) {                            // Чтение символа из потока ввода
        if (c == '\n') continue;
        switch (c) {
            case '1':
                printf("\nEnter the value: ");
                scanf("%s", value);
                h = create(value);
                break;
            case '2':
                printf("\nEnter the value: ");
                scanf("%s", value);
                h = add_element_start(value, h);
                break;
            case '3':
                printf("\nEnter the value: ");
                scanf("%s", value);
                add_element_end(value, h);
                break;
            case '4':
                printf("\nEnter the position: ");
                scanf("%d", &pos);
                printf("\nEnter the value: ");
                scanf("%s", value);
                h = add_element_n_position(value, pos, h);
                break;
            case '5':
                h = delete_list(h);
                break;
            case '6':
                printf("\nEnter the position: ");
                scanf("%d", &pos);
                h = delete_element(h, pos);
                break;
            case '7':
                print_list(h);
                break;
            case '8':
                printf("%d\n", list_size(h));
                break;
            case '9':
                printf("\nEnter the amount of elements to delete: ");
                scanf("%d", &pos);
                h = mid_delete(pos, h);
                break;
            default:
                printf("The number you entered isn't in the menu :(\nPlease try again, in case you made a mistake\n");
                break;
        }
        print_menu();
    }
}
