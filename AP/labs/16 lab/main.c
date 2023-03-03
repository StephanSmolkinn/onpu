#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <windows.h>

int main()
{
     int n=3,m=3,i,j;
     int array[n][m];
     int winX, winY, winH, winW;
     WINDOW* windowInput;
     initscr();
     if(!has_colors()){
     endwin();
     printf("Colors are not supported!");
     return 1;
     }
     curs_set(0);
     start_color();
     init_pair( 1, COLOR_BLACK, COLOR_WHITE );

     cbreak();
     refresh();
     winX = 20; winY = 3;
     winH = 3; winW = 38;
     windowInput = newwin( winH, winW, winY, winX);
     box( windowInput, 0, 0 );
     wbkgd(windowInput, COLOR_PAIR(1) );
     wrefresh(windowInput);

     move(winY + 1, winX + 3);
     attron(COLOR_PAIR(1));
     printw("Matrix (3x3) Press any key -> ");
     getch();

     winW=5;
     winX = 0;
     winY = 7;
     for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                 WINDOW *windowArray[n][m];
                 windowArray[i][j] = newwin( winH, winW, winY, winX );
                 box(windowArray[i][j], 0, 0 );

                 wbkgd(windowArray[i][j], COLOR_PAIR(1) );
                 wrefresh(windowArray[i][j]);

                 move(winY + 1, winX + 1);
                 attron(COLOR_PAIR(1));
                 scanw("%d",&array[i][j]);

                 winX += 7;
            }
            winX = 0;
            winY += winH;
     }
     system("cls");
     int ni,nj;
     winX = 20; winY = 7;
     winH = 3; winW = 30;
     WINDOW *fori;
     fori = newwin( winH, winW, winY, winX);
     box(fori, 0, 0 );
     wbkgd(fori, COLOR_PAIR(1));
     wrefresh(fori);

     move(winY + 1, winX + 3);
     attron(COLOR_PAIR(1));
     printw("Input i (0<=i<=2) -> ");
     scanw("%d",&ni);

     if(ni < 0 || ni > 2){
        printf("\nInput Error\n");
        return;
     }

     winX = 65; winY = 7;
     winH = 3; winW = 30;
     fori = newwin( winH, winW, winY, winX);
     box(fori, 0, 0 );
     wbkgd(fori, COLOR_PAIR(1));
     wrefresh(fori);

     move(winY + 1, winX + 3);
     attron(COLOR_PAIR(1));
     printw("Input j (0<=j<=2) -> ");
     scanw("%d",&nj);

     if(nj < 0 || nj > 2){
        printf("\nInput Error\n");
        return;
     }

     system("cls");
     int multi=1;
     int multi1=1;
     int multi2;
     for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(i==ni){
                multi*=array[ni][j];
            }
            if(j==nj){
                multi1*=array[i][nj];
            }
        }
     }
     multi2=multi1*multi;

     for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(i>=1 && j>=1){
                    if(i==1 && j==1) array[i][j];
                    else array[i][j]=multi2;
            }
        }
     }
     system("cls");

     winX = 22; winY = 4;
     winH = 3; winW = 23;
     fori = newwin( winH, winW, winY, winX);
     box(fori, 0, 0 );
     wbkgd(fori, COLOR_PAIR(1));
     wrefresh(fori);

     move(winY + 1, winX + 3);
     attron(COLOR_PAIR(1));
     printw("New matrix -> ");

     winH=3;
     winW=8;
     winX = 20;
     winY = 10;
     for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                 WINDOW *windowArray1[n][m];
                 windowArray1[i][j] = newwin( winH, winW, winY, winX );
                 box(windowArray1[i][j], 0, 0 );

                 wbkgd(windowArray1[i][j], COLOR_PAIR(1) );
                 wrefresh(windowArray1[i][j]);

                 move(winY + 1, winX + 1);
                 attron(COLOR_PAIR(1));
                 printw("%d",array[i][j]);

                 winX += 12;
            }
            winX = 20;
            winY += winH;
     }
     getch();

     printf("\nProgram finished successfully\n");

     endwin();

    return 0;
}

