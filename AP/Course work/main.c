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
    struct olimp *v1; // �������� �� ��������� ���������
    struct olimp *v2; // �������� �� �������� ���������
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
     // ���� ��������
     puts("���� 䳿");
     puts("1 - �������� ������ �����");
     puts("2 - ��������� ������ �����");
     puts("3 - ��������� �������� � �������");
     puts("4 - ��������� �������� � ����");
     puts("5 - ��������� �������� � �������");
     puts("6 - ��������� �������� � ����");
     puts("7 - ������ ������ ������� �� ������ ����� ������");
     puts("8 - ������ ������ ��� ������� �������, ������ � ��������� �������,����������� ������ ������-��������� �������;");
     puts("9 - ������ ��������� ��� ��� ������� ����� � ������� ������;");
     puts("10 - ��������� � ���� ������ ��� ���������� � �������� �������� � ������� (�� ������ �����-��������)");
     puts("11 - ��������� � ���� ������ ��� ���������� � �������� �������� � ���� (�� ������ �����-��������)");
     puts("12 - ���������� �� ������ �������");
     puts("13 - �������� ������ � ���� (Courser.txt) �� �����");
     puts("14 - ������� ������ � �����");
     puts("0 - �����");
     puts("������ ��� ������ 䳿");
     scanf("%d", &kod);
     printf("������� ��� %d \n", kod);
     switch(kod)
     {
     case 1: create(head); break;
     case 2: printf("\n\n�������� � �����: \n\n"); list(head); printf("\n\n�������� � ����: \n\n"); list(tail); break;
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
void create(olimp *p){ // ������� (create) ����� ������
    char x[30],x2[30],x3[30];
    olimp *pred;
    pred = NULL;
    do {
    p=(olimp *)malloc(sizeof(olimp));
    gets(x2);
    printf("\n������� -> ");
    gets(p->surname);
    printf("������������ ����� -> ");
    scanf("%d",&p->register1);
    gets(x);
    printf("����� -> ");
    gets(p->country);
    printf("����� -> ");
    scanf("%[^\n]%*c",p->sport);
    printf("������� ���� -> ");
    scanf("%d",&p->result);
    //gets(x3);
    p->v1=pred;
    if (pred != NULL)
    pred->v2=p;
    else
    head=p;
    pred=p;
    puts("���������� - ����-��� ������. ��������� - <esc>");
    } while (getch()!=27);
    tail=p;
    tail->v2=NULL;
}
void list(olimp *p){ // ������� (list) �������� ������
    if (p==head){
    while(p!=NULL){
        printf("������� -> %s\n",p->surname);
        printf("����������� ����� -> %d\n",p->register1);
        printf("����� -> %s\n",p->country);
        printf("����� -> %s\n",p->sport);
        printf("������� ���� -> %d\n\n",p->result);
        p=p->v2;
    }
    }
    else if (p==tail){ // � ����
    while (p!= NULL)
    {
        printf("������� -> %s\n",p->surname);
        printf("����������� ����� -> %d\n",p->register1);
        printf("����� -> %s\n",p->country);
        printf("����� -> %s\n",p->sport);
        printf("������� ���� -> %d\n\n",p->result);
        p=p->v1;
    }
    }
    else
    puts("������ ������");
}
void del(olimp *p){ // ������ (del) ������� ������ �� ������� ������� ������
    if(p==NULL){
        puts("����� �������!");
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
void add(olimp *p){ //������ (add) ������� ������� � ������� �� ���� ������
    olimp *pn;
    char x[30],x2[30],x3[30];
    pn = (olimp *) malloc (sizeof (olimp));
    gets(x2);
    printf("������� -> ");
    gets(pn->surname);
    printf("������������ ����� -> ");
    scanf("%d",&pn->register1);
    gets(x);
    printf("����� -> ");
    gets(pn->country);
    printf("����� -> ");
    scanf("%[^\n]%*c",pn->sport);
    printf("������� ���� -> ");
    scanf("%d",&pn->result);
    gets(x3);
    if(p==NULL){
        printf("����� �������");
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
void winners(olimp *p){ // ������ (winners) �������� ������ ����������, �� ������� 1,2,3 ���� �� ������ � ������ �� ���� ������
    if(p==head){
        while(p!=NULL){
            if(p->result==1 || p->result==2 || p->result==3){
                printf("������� -> %s (����� -> %s)\n",p->surname,p->sport);
            }
            p=p->v2;
        }
    }
    if(p==tail){
        while(p!=NULL){
            if(p->result==1 || p->result==2 || p->result==3){
                printf("������� -> %s (����� -> %s)\n",p->surname,p->sport);
            }
            p=p->v1;
        }
    }
}
void winners_country(olimp *p){ // ������� (winners_country) �������� ������� �������, ������������ ������ ������
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
            printf("����� %s : ",p1->country);
            if(p1->result==1)  printf(" ������ ");
            if(p1->result==2)  printf(" ����� ");
            if(p1->result==3)  printf(" ������ ");
            printf("\n\n");
        p1=p1->v2;
    }
}
void prizers(olimp *p){ // ������ (prizers) ���� ���������� ����������, �� ������� ������ � ������� ������ �����
    char f[30],f1[30];
    if(p==NULL){
        puts("����� �������!");
        return;
    }
    printf("����� -> ");
    gets(f1);
    gets(f);
    if(p==head){
    while(p!=NULL){
        if(strcmp((p->country),f)==0){
                if(p->result==3 || p->result==2 || p->result==1){
                printf("������� -> %s\n",p->surname);
                printf("����������� ����� -> %d\n",p->register1);
                printf("����� -> %s\n",p->country);
                printf("����� -> %s\n",p->sport);
                printf("������� ���� -> %d\n\n",p->result);
                }
            }
            p=p->v2;
        }
    }
    if(p==tail){
    while(p!=NULL){
        if(strcmp((p->country),f)==0){
                if(p->result==3 || p->result==2 || p->result==1){
                printf("������� -> %s\n",p->surname);
                printf("����������� ����� -> %d\n",p->register1);
                printf("����� -> %s\n",p->country);
                printf("����� -> %s\n",p->sport);
                printf("������� ���� -> %d\n\n",p->result);
                }
            }
            p=p->v1;
        }
    }
}
void doping(olimp *p){ // ������� (doping) ������ ���������� (�� ������� �����-��������) �� �������� ��������
    char sportsmen[30],y[30];
    if(p==NULL){
        puts("����� �������!");
        return;
    }
    printf("��������� ���������� (�� ������� �����-��������) -> ");
    gets(y);
    gets(sportsmen);
    if(p==head){
        while(p!=NULL){
            if(strcmp((p->surname),sportsmen)==0){
                    if(p!=head){
                        printf("Error\n");
                        return;
                    }
                printf("���������� %s ���� ��������\n",p->surname);
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
                printf("���������� %s ���� ��������\n",p->surname);
                tail=p->v1;
                tail->v2=NULL;
                free(p);
                p=tail;
            }
            p=p->v1;
        }
    }
}
void for_sort(char *prev, char *next){ // ������� (for_sort) �� (sort) ������� ���������� �� ������ ������. ������� ������� � (sort).
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

void write_in_file(olimp *p){ // ������ (write_in_file) �������� ������ � ���� Courser.txt. ϳ��� ������ 䳿 ���� ������ �������� ������ ������� �� ������� ������ ��������
    FILE *f;
    if(p==NULL){
        puts("����� �������!");
        return;
    }
    if((f=fopen("c:\\Courser.txt", "wb"))==NULL){
        printf("��������� ������� ���� ��� ������\n");
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
        printf("��������� ������� ���� ��� ����������\n");
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

