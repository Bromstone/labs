#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <time.h>

typedef struct{
    char surname[10+1];
    char initials[4+1];
    char sex[6+1];
    int school_num;
    int medal;
    int russian_points;
    int maths_points;
    int informatics_points;
    int essay;
} person;

FILE *db;
//char fileName[40];
int records; //количество записей

void db_create(char fileName[40]) {
    
    db = fopen(fileName, "w"); //создаем файл
   
    if (db == NULL) printf("Error\n"); // Проверка открытия файла
    else printf("File has been made succesfully\n");
    
    fclose(db); // Закрытие файла

}

void db_create_bin(char fileName[40]) {
    
    db = fopen(fileName, "wb"); //создаем файл
   
    if (db == NULL) printf("Error\n"); // Проверка открытия файла
    else printf("File has been made succesfully\n");
    
    fclose(db); // Закрытие файла

}

void generation(char fileName[40]) {
    
    srand(time(NULL));
    
    person generated; //запись
    
    db = fopen(fileName, "a"); //открываем файл для записи
    
    printf("Enter the amount of records:\n"); //вводим количество нужных записей
    scanf("%d", &records);
    
    for (int i = 0; i < records; i++) {
        
        int rd = rand()%2;
        
        generated.surname[0] = rand()%26+'A';
        for(int e = 1; e < 10; e++) {
            generated.surname[e] = rand()%26+'a';
        }
        
        if (rd == 0) {
            generated.sex[0] = 'f';
            generated.sex[1] = 'e';
            generated.sex[2] = 'm';
            generated.sex[3] = 'a';
            generated.sex[4] = 'l';
            generated.sex[5] = 'e';
        } 
        else {
            generated.sex[0] = ' ';
            generated.sex[1] = ' ';
            generated.sex[2] = 'm';
            generated.sex[3] = 'a';
		    generated.sex[4] = 'l';
            generated.sex[5] = 'e';
        }
        
        generated.initials[0] = rand()%26 + 'A';
        generated.initials[1] = '.';
        generated.initials[2] = rand()%26 + 'A';
        generated.initials[3] = '.';
        
        generated.school_num = 100 + rand()%1000;
        
        generated.medal = rand()%1000000;
        
        generated.russian_points = 2 + rand()%1000000;
        
        generated.maths_points = 2 + rand()%1000000;
        
        generated.informatics_points = 2 + rand()%1000000;
        
        generated.essay = rand()%1000000;
        
        fprintf(db, "%s %s %s %d %d %d %d %d %d\n", generated.surname, generated.initials, generated.sex, generated.school_num, generated.medal, generated.russian_points, generated.maths_points, generated.informatics_points, generated.essay);
        
    }
    
    printf("Records have been added successfully\n");
    fclose(db);
    
}
void generation_bin(char fileName[40]) {
    
    srand(time(NULL));
    
    person generated; //запись
    
    db = fopen(fileName, "ab"); //открываем файл для записи
    
    printf("Enter the amount of records:\n"); //вводим количество нужных записей
    scanf("%d", &records);
    
    for (int i = 0; i < records; i++) {
        
        int rd = rand()%2;
        
        generated.surname[0] = rand()%26+'A';
        for(int e = 1; e < 10; e++) {
            generated.surname[e] = rand()%26+'a';
        }
        
        if (rd == 0) {
            generated.sex[0] = 'f';
            generated.sex[1] = 'e';
            generated.sex[2] = 'm';
            generated.sex[3] = 'a';
            generated.sex[4] = 'l';
            generated.sex[5] = 'e';
        } 
        else {
            generated.sex[0] = ' ';
            generated.sex[1] = ' ';
            generated.sex[2] = 'm';
            generated.sex[3] = 'a';
		    generated.sex[4] = 'l';
            generated.sex[5] = 'e';
        }
        
        generated.initials[0] = rand()%26 + 'A';
        generated.initials[1] = '.';
        generated.initials[2] = rand()%26 + 'A';
        generated.initials[3] = '.';
        
        generated.school_num = 100 + rand()%1000;
        
        generated.medal = rand()%1000000;
        
        generated.russian_points = 2 + rand()%1000000;
        
        generated.maths_points = 2 + rand()%1000000;
        
        generated.informatics_points = 2 + rand()%1000000;
        
        generated.essay = rand()%1000000;
        
        fwrite(&generated, sizeof(person), 1, db);
        
    }
    
    printf("Records have been added successfully\n");
    fclose(db);
    
}

void function(char fileName[40]) {
    int p;
    
    printf("Enter parameter:\n"); //вводим количество нужных записей
    scanf("%d", &p);
    
    db = fopen(fileName, "rb");
    
    person s;
    
    person *students = (person*)calloc(records, sizeof(person));
    person *result = (person*)calloc(records, sizeof(person));
    
    int i = 0;
    int amount = 0;
    
    while(!feof(db)){
        
        fscanf(db, "%s %4s %s %d %d %d %d %d %d", s.surname, s.initials, s.sex, &s.school_num, &s.medal, &s.russian_points, &s.maths_points, &s.informatics_points, &s.essay);
        students[i++] = s;
        
    }
    
    puts("---------------------------------------------------------------------------");
    puts("|  Surname   |Initials| Sex  |School|Medal|Russian|Maths|Informatics|Essay|");
    puts("---------------------------------------------------------------------------");

    for (int j = 0; j < records; ++j) {
        
        person s = students[j];
        
        if((s.russian_points == 5 || s.maths_points == 5 || s.informatics_points == 5) && s.russian_points + s.maths_points + s.informatics_points < p){
            printf("|%11s%s|%5s%3s|%6s|%5d%s|%3d%2s|%4d%3s|%3d%2s|%6d%5s|%3d%2s|\n", s.surname, " ", s.initials, " ", s.sex, s.school_num, " ",
                    s.medal, " ",  s.russian_points, " ",  s.maths_points, " ", s.informatics_points, " ", s.essay, " ");
            result[amount++] = s;
            
        }
    }

    if(amount == 0){
        puts("|                                       NO DATA                           |");
    }

    puts("---------------------------------------------------------------------------");


    fclose(db);
}

int main(int argc, char* argv[]) {
    
    db_create(argv[1]);
    db_create_bin(argv[2]);
    generation(argv[1]);
    generation_bin(argv[2]);
    function(argv[1]);
    
    return 0;
    
}
