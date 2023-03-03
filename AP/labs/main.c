#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{

    printf("1 - lab1\n");
    printf("2 - lab2\n");
    printf("3 - lab3\n");

    int key;
    printf("Choose function of labs -> ");
    scanf("%d",&key);

    switch(key) {

        case 1:
            lab1();
            break;

        case 2:
            lab2();
            break;

        case 3:
            lab3();
            break;

        default:
            printf("Invalid choice");

    }

    return 0;
}

void lab1() {

    float a,b,c,i;
    printf("Input cathetus a\n");
    scanf("%f",&a);
    printf("Input cathetus c\n");
    scanf("%f",&c);
    printf("Input hypotenuse\n");
    scanf("%f",&b);
    i=(a+c-b)/2;
    if(i<0){
        printf("\nCheck your data, radius cant be negative\n");
        exit(1);
    }
    printf("\nRadius = %.2f\n",i);
    printf("\nPress Enter for exit");
    getch();

}

void lab2() {

    float x,y,z;
    float a,a1,a2,a3,a4,a5,a6,a7,a8;
    printf("Input x\n");
    scanf("%f",&x);
    printf("Input y\n");
    scanf("%f",&y);
    printf("Input z\n");
    scanf("%f",&z);

    a1=pow(sin(x),5);
    a2=pow(sin(y),5);
    a3=pow(sin(z),5);
    a4=a1+a2+a3;
    a5=pow(cos(x+y+z),5);
    a7=pow(tan(y),x);
    a6=a4-a5+a7;
    a8=z+pow((y),x)*2+0,005*y;
    a=a6/a8;

    float b;
    b=2.1*x-pow(((x-7),4)+sin(z),(1./3));

    printf("\na = %.2f \n",a);
    printf("\nb = %.2f\n",b);
    printf("\nPress Enter for exit");
    getch();

}

void lab3() {

    printf("First task: \n\n");

    float x,y;
    printf("Input x\n");
    scanf("%f",&x);
    printf("Input y\n");
    scanf("%f",&y);
    if(pow((x),2)+pow((y),2)==1 || pow((x),2)+pow((y),2)==1){
    printf("Point in the area\n");}
    else {
        if(x==1 && y==1 || y==1 && x==1 || x==-1 && y==-1 || y==-1 &&
        x==-1){
            printf("Point in the area\n");
        }
        else{
            if(x==1 && y>=0 && y<1 || y==1 && x>=0 && x<1 || x==-1
            && y<=0 && y>-1 || y==-1 && x<=0 && x>-1){
                printf("Point in the area\n");
            }
            else{
                if(x>1 && y>1 || x<-1 && y<-1 || x>1 && y==1 || x<-1
                && y==-1){
                    printf("Point out of area\n");
                }
            }
        }
    }

    printf("\n\nSecond task: \n\n");

    float x1,y1,a,c;
    printf("Input x\n");
    scanf("%f",&x1);
    printf("Input a\n");
    scanf("%f",&a);
    c=x1+fabs(a-1);

    if(c>10){
        y1=x1/5;
        printf("y = %.2f\n",y1);
    }
    else {
        if(c<10){
            y1=a*5;
            printf("y = %.2f\n",y1);
        }
        else
        {
            y1=a-12;
            printf("y = %.2f\n",y1);
        }
    }

}
