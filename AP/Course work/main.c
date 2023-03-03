#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <windows.h>
#include <locale.h>
struct olimp{
    char surname[30];
    char country[30];
    char sport[30];
    int register1;
    int result;
    struct olimp *v1; // покажчик на попередню структуру
    struct olimp *v2; // покажчик на наступну структуру
};
typedef struct olimp olimp;
struct olimp *head;
struct olimp *tail;
void create(olimp *);
void list(olimp *);
void del(olimp *);
void add(olimp *);
void winners(olimp *);
void winners_country(olimp *);
void prizers(olimp *);
void doping(olimp *);
void sort(olimp *);
void write_in_file(olimp *);
void read_from_file(olimp *);
int main(){
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    system("cls");
    int kod;
    while(1)
    {
     // меню програми
     puts("Вибір дії");
     puts("1 - Введення списку рядків");
     puts("2 - Виведення списку рядків");
     puts("3 - Видалення елемента з початку");
     puts("4 - Видалення елемента з кінця");
     puts("5 - додавання елемента в початок");
     puts("6 - додавання елемента в кінец");
     puts("7 - видача списка призерів за кожним видом спорту");
     puts("8 - видача довідок про кількість золотих, срібних і бронзових медалей,завойованих кожною країною-учасницею Олімпіади;");
     puts("9 - видача відомостей про всіх призерів країни з заданою назвою;");
     puts("10 - видалення з бази записів про спортсменів з вказаним прізвищем з початку (на вимогу допінг-контролю)");
     puts("11 - видалення з бази записів про спортсменів з вказаним прізвищем з кінця (на вимогу допінг-контролю)");
     puts("12 - сортування за видами змагань");
     puts("13 - записати список у файл (Courser.txt) та вихід");
     puts("14 - вивести список з файла");
     puts("0 - Вихід");
     puts("Введіть код бажаної дії");
     scanf("%d", &kod);
     printf("Обраний код %d \n", kod);
     switch(kod)
     {
     case 1: create(head); break;
     case 2: printf("\n\nПерегляд з верху: \n\n"); list(head); printf("\n\nПерегляд з низу: \n\n"); list(tail); break;
     case 3: del(head); break;
     case 4: del(tail); break;
     case 5: add(head); break;
     case 6: add(tail); break;
     case 7: winners(head); break;
     case 8: winners_country(head); break;
     case 9: prizers(head); break;
     case 10: doping(head); break;
     case 11: doping(tail); break;
     case 12: sort(head); break;
     case 13: write_in_file(tail);  break;
     case 14: read_from_file(head); break;
     case 0: exit(1);break;
     default : printf("Error\n");
     }
     }
    return 0;
}
void create(olimp *p){ // функція (create) создає список
    char x[30],x2[30],x3[30];
    olimp *pred;
    pred = NULL;
    do {
    p=(olimp *)malloc(sizeof(olimp));
    gets(x2);
    printf("\nПрізвище -> ");
    gets(p->surname);
    printf("Реєстраційний номер -> ");
    scanf("%d",&p->register1);
    gets(x);
    printf("Країна -> ");
    gets(p->country);
    printf("Спорт -> ");
    scanf("%[^\n]%*c",p->sport);
    printf("Зайняте місце -> ");
    scanf("%d",&p->result);
    //gets(x3);
    p->v1=pred;
    if (pred != NULL)
    pred->v2=p;
    else
    head=p;
    pred=p;
    puts("Продовжити - будь-яка клавіша. Завершити - <esc>");
    } while (getch()!=27);
    tail=p;
    tail->v2=NULL;
}
void list(olimp *p){ // функція (list) виводить список
    if (p==head){
    while(p!=NULL){
        printf("Призвіще -> %s\n",p->surname);
        printf("Реєстаційний номер -> %d\n",p->register1);
        printf("Країна -> %s\n",p->country);
        printf("Спорт -> %s\n",p->sport);
        printf("Зайняте місце -> %d\n\n",p->result);
        p=p->v2;
    }
    }
    else if (p==tail){ // з кінця
    while (p!= NULL)
    {
        printf("Призвіще -> %s\n",p->surname);
        printf("Реєстаційний номер -> %d\n",p->register1);
        printf("Країна -> %s\n",p->country);
        printf("Спорт -> %s\n",p->sport);
        printf("Зайняте місце -> %d\n\n",p->result);
        p=p->v1;
    }
    }
    else
    puts("Невірна адреса");
}
void del(olimp *p){ // фунція (del) видаляє перший чи отсанній елемент списка
    if(p==NULL){
        puts("Черга порожня!");
        return;
    }
    if(p==head){
    head=p->v2;
    head->v1=NULL;
    free(p);
    p=head;
    }
    if(p==tail){
    tail=p->v1;
    tail->v2=NULL;
    free(p);
    p=tail;
    }
}
void add(olimp *p){ //фунція (add) добаляє елемент в початок чи кінец списка
    olimp *pn;
    char x[30],x2[30],x3[30];
    pn = (olimp *) malloc (sizeof (olimp));
    gets(x2);
    printf("Прізвище -> ");
    gets(pn->surname);
    printf("Реєстраційний номер -> ");
    scanf("%d",&pn->register1);
    gets(x);
    printf("Країна -> ");
    gets(pn->country);
    printf("Спорт -> ");
    scanf("%[^\n]%*c",pn->sport);
    printf("Зайняте місце -> ");
    scanf("%d",&pn->result);
    gets(x3);
    if(p==NULL){
        printf("черга порожня");
        head=tail=pn;
        return ;
    }
    if(p==head){
    pn-> v1 = NULL;
    pn-> v2 = p;
    p-> v1 = pn;
    head = pn;
    }
    if(p==tail){
    pn-> v1 = tail;
    pn-> v2 = NULL;
    p-> v2 = pn;
    tail = pn;
    }
}
void winners(olimp *p){ // фунція (winners) виводить список спортсменів, які здобули 1,2,3 місця на олімпіаді з назвою їх виду спорту
    if(p==head){
        while(p!=NULL){
            if(p->result==1 || p->result==2 || p->result==3){
                printf("Прізвище -> %s (Спорт -> %s)\n",p->surname,p->sport);
            }
            p=p->v2;
        }
    }
    if(p==tail){
        while(p!=NULL){
            if(p->result==1 || p->result==2 || p->result==3){
                printf("Прізвище -> %s (Спорт -> %s)\n",p->surname,p->sport);
            }
            p=p->v1;
        }
    }
}
void winners_country(olimp *p){ // функція (winners_country) виводить кількість медалей, завойованиою кожною країною
    olimp *p1,*p2;
    int temp;
    int count=0, count_1=0, count_2=0;
    p1=p;
    p2=NULL;
    while(p1 != NULL){
        p2 = p1->v2;
        while (p2 != NULL){
            if (strcmp(p1->country, p2->country)>0){
                for_sort(p1->sport, p2->sport);
                for_sort(p1->surname, p2->surname);
                for_sort(p1->country, p2->country);
                temp = p1->register1;
                p1->register1 = p2->register1;
                p2->register1 = temp;
                temp = p1->result;
                p1->result = p2->result;
                p2->result = temp;
            }
            p2 = p2->v2;
        }
        p1 = p1->v2;
    }
    p1=head;
    while(p1!=NULL){
            printf("Країна %s : ",p1->country);
            if(p1->result==1)  printf(" Золото ");
            if(p1->result==2)  printf(" Срібло ");
            if(p1->result==3)  printf(" Бронза ");
            printf("\n\n");
        p1=p1->v2;
    }
}
void prizers(olimp *p){ // фунція (prizers) надає інформацію смортсменів, які здобули медаль з задоною назвою країни
    char f[30],f1[30];
    if(p==NULL){
        puts("Черга порожня!");
        return;
    }
    printf("Країна -> ");
    gets(f1);
    gets(f);
    if(p==head){
    while(p!=NULL){
        if(strcmp((p->country),f)==0){
                if(p->result==3 || p->result==2 || p->result==1){
                printf("Прізвище -> %s\n",p->surname);
                printf("Реєстаційний номер -> %d\n",p->register1);
                printf("Країна -> %s\n",p->country);
                printf("Спорт -> %s\n",p->sport);
                printf("Зайняте місце -> %d\n\n",p->result);
                }
            }
            p=p->v2;
        }
    }
    if(p==tail){
    while(p!=NULL){
        if(strcmp((p->country),f)==0){
                if(p->result==3 || p->result==2 || p->result==1){
                printf("Прізвище -> %s\n",p->surname);
                printf("Реєстаційний номер -> %d\n",p->register1);
                printf("Країна -> %s\n",p->country);
                printf("Спорт -> %s\n",p->sport);
                printf("Зайняте місце -> %d\n\n",p->result);
                }
            }
            p=p->v1;
        }
    }
}
void doping(olimp *p){ // функція (doping) видалає спортсмена (за вимогою допінг-контролю) за вказаним прізвищем
    char sportsmen[30],y[30];
    if(p==NULL){
        puts("Черга порожня!");
        return;
    }
    printf("Видалення спортсмена (за вимогою допінг-контролю) -> ");
    gets(y);
    gets(sportsmen);
    if(p==head){
        while(p!=NULL){
            if(strcmp((p->surname),sportsmen)==0){
                    if(p!=head){
                        printf("Error\n");
                        return;
                    }
                printf("Спортсмена %s було видалено\n",p->surname);
                head=p->v2;
                head->v1=NULL;
                free(p);
                p=head;
            }
            p=p->v2;
        }
    }
    if(p==tail){
        while(p!=NULL){
            if(strcmp((p->surname),sportsmen)==0){
                    if(p!=tail) {
                    printf("Error\n");
                    return;
                    }
                printf("Спортсмена %s було видалено\n",p->surname);
                tail=p->v1;
                tail->v2=NULL;
                free(p);
                p=tail;
            }
            p=p->v1;
        }
    }
}
void for_sort(char *prev, char *next){ // функції (for_sort) та (sort) роблять сортування за видами спорту. Головна функція є (sort).
    char t1[30] = "";
    strcpy(t1, prev);
    strcpy(prev, next);
    strcpy(next, t1);
}
void sort(olimp *p){
    olimp *p1,*p2;
    int temp;
    int count=0, count_1=0, count_2=0;
    p1=p;
    p2=NULL;
    while(p1 != NULL){
        p2 = p1->v2;
        while (p2 != NULL){
            if (strcmp(p1->sport, p2->sport)>0){
                for_sort(p1->sport, p2->sport);
                for_sort(p1->surname, p2->surname);
                for_sort(p1->country, p2->country);
                temp = p1->register1;
                p1->register1 = p2->register1;
                p2->register1 = temp;
                temp = p1->result;
                p1->result = p2->result;
                p2->result = temp;
            }
            p2 = p2->v2;
        }
        p1 = p1->v2;
    }
}

void write_in_file(olimp *p){ // фунція (write_in_file) заносить список у файл Courser.txt. Після вибора дії цієї фунції програма виконує функцію та завершує роботу програми
    FILE *f;
    if(p==NULL){
        puts("Черга порожня!");
        return;
    }
    if((f=fopen("c:\\Courser.txt", "wb"))==NULL){
        printf("Неможливо відкрити файл для запису\n");
        return 1;
    }
    olimp *file = head;
    while(file!=NULL){

            fprintf(f,"%3s %5d %5s  %5s %5d\n",file->surname,file->register1,file->country,file->sport,file->result);
            file=file->v2;
    }
    fclose(f);
    exit(1);
}

void read_from_file(olimp *p){
    FILE* f;
    if((f=fopen("c:\\Courser.txt", "rb"))==NULL){
        printf("Неможливо відкрити файл для зчитування\n");
        return 1;
    }

    olimp *f1 = (olimp*)malloc(sizeof(olimp));
    while(fscanf(f,"%s%d%s%s%d",f1->surname,&f1->register1,f1->country,f1->sport,&f1->result)!=EOF){
    f1->v1 = f1->v2 = NULL;
    add_el(f1,p);
    f1 = malloc(sizeof(olimp));
    }list(head);
    fclose(f);
}
void add_el(olimp *t,olimp *p){
    if(head == NULL && tail == NULL){
            head = tail = t;
            return;
    }
    t->v2 = head;
    head->v1 = t;
    head = t;
}

