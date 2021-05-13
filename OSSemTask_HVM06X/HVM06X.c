#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int fd[20][2];
    for(int i = 0; i<20; i++){
        pipe(fd[i]);
    }

    int pid1 = fork();
    int pid2 = fork();
    int pid3 = fork();
    int pid4 = fork();
    int pid5 = fork();
    int pid6 = fork();
    int pid7 = fork();
    int pid8 = fork();
    int pid9 = fork();
    int pid10 = fork();

    if(pid1 == 0){ //a magyarázat pid1-től pid10-ig azonos, így csak itt magyaráznám. A parent megyarázata a 366. sorban kezdődik.
        for(int i = 0; i < 20; i++){
            for(int j = 0; j < 2; j++){
                if(i == 0 && j == 0){ //az i és j megadásával nyitva marad a kívánt pipe
                    continue;
                }
                else if(i == 1 && j == 1){ //az i és j megadásával nyitva marad a kívánt pipe
                    continue;
                }
                close(fd[i][j]);
            }
        }


        int tomb[100]; //helyi tomb
        int tomb1[100];  // "kapott" tomb

        for(int i = 0; i<100; i++){
            read(fd[0][0], &tomb1[i], sizeof(int)); //itt történik a tömb beolvasása és eltárolása egy másik tömbben
            tomb[i] = tomb1[i];
        }
        int max1 = 0;
        for(int j = 0; j < 100; j++){ //itt a maximum kiszámítása történik
            if(tomb[j] > max1){
                max1 = tomb[j];
            }
        }

        write(fd[1][1], &max1, sizeof(int)); // a maximum visszaküldése
        close(fd[0][0]);
        close(fd[1][1]); //a nyitva maradt pipeok bezárása
        return 0;
    }



    else if(pid2 == 0){
        for(int i = 0; i < 20; i++){
            for(int j = 0; j < 2; j++){
                if(i == 2 && j == 0){
                    continue;
                }
                else if(i == 3 && j == 1){
                    continue;
                }
                close(fd[i][j]);
            }
        }


        int tomb[100]; //helyi tomb
        int tomb2[100];  // "kapott" tomb

        for(int i = 0; i<100; i++){
            read(fd[2][0], &tomb2[i], sizeof(int));
            tomb[i] = tomb2[i];
        }
        int max2 = 0;
        for(int j = 0; j < 100; j++){
            if(tomb[j] > max2){
                max2 = tomb[j];
            }
        }

        write(fd[3][1], &max2, sizeof(int));
        close(fd[2][0]);
        close(fd[3][1]);
        return 0;
    }

    else if(pid3 == 0){
        for(int i = 0; i < 20; i++){
            for(int j = 0; j < 2; j++){
                if(i == 4 && j == 0){
                    continue;
                }
                else if(i == 5 && j == 1){
                    continue;
                }
                close(fd[i][j]);
            }
        }

        int tomb[100]; //helyi tomb
        int tomb3[100];  // "kapott" tomb

        for(int i = 0; i<100; i++){
            read(fd[4][0], &tomb3[i], sizeof(int));
            tomb[i] = tomb3[i];
        }
        int max3 = 0;
        for(int j = 0; j < 100; j++){
            if(tomb[j] > max3){
                max3 = tomb[j];
            }
        }

        write(fd[5][1], &max3, sizeof(int));
        close(fd[4][0]);
        close(fd[5][1]);
        return 0;
    }

    else if(pid4 == 0){
        for(int i = 0; i < 20; i++){
            for(int j = 0; j < 2; j++){
                if(i == 6 && j == 0){
                    continue;
                }
                else if(i == 7 && j == 1){
                    continue;
                }
                close(fd[i][j]);
            }
        }


        int tomb[100]; //helyi tomb
        int tomb4[100];  // "kapott" tomb

        for(int i = 0; i<100; i++){
            read(fd[6][0], &tomb4[i], sizeof(int));
            tomb[i] = tomb4[i];
        }
        int max4 = 0;
        for(int j = 0; j < 100; j++){
            if(tomb[j] > max4){
                max4 = tomb[j];
            }
        }

        write(fd[7][1], &max4, sizeof(int));
        close(fd[6][0]);
        close(fd[7][1]);
        return 0;
    }

    else if(pid5 == 0){
        for(int i = 0; i < 20; i++){
            for(int j = 0; j < 2; j++){
                if(i == 8 && j == 0){
                    continue;
                }
                else if(i == 9 && j == 1){
                    continue;
                }
                close(fd[i][j]);
            }
        }


        int tomb[100]; //helyi tomb
        int tomb5[100];  // "kapott" tomb

        for(int i = 0; i<100; i++){
            read(fd[8][0], &tomb5[i], sizeof(int));
            tomb[i] = tomb5[i];
        }
        int max5 = 0;
        for(int j = 0; j < 100; j++){
            if(tomb[j] > max5){
                max5 = tomb[j];
            }
        }

        write(fd[9][1], &max5, sizeof(int));
        close(fd[8][0]);
        close(fd[9][1]);
        return 0;
    }

    else if(pid6 == 0){
        for(int i = 0; i < 20; i++){
            for(int j = 0; j < 2; j++){
                if(i == 10 && j == 0){
                    continue;
                }
                else if(i == 11 && j == 1){
                    continue;
                }
                close(fd[i][j]);
            }
        }

        int tomb[100]; //helyi tomb
        int tomb6[100];  // "kapott" tomb

        for(int i = 0; i<100; i++){
            read(fd[10][0], &tomb6[i], sizeof(int));
            tomb[i] = tomb6[i];
        }
        int max6 = 0;
        for(int j = 0; j < 100; j++){
            if(tomb[j] > max6){
                max6 = tomb[j];
            }
        }

        write(fd[11][1], &max6, sizeof(int));
        close(fd[10][0]);
        close(fd[11][1]);
        return 0;
    }

    else if(pid7 == 0){
        for(int i = 0; i < 20; i++){
            for(int j = 0; j < 2; j++){
                if(i == 12 && j == 0){
                    continue;
                }
                else if(i == 13 && j == 1){
                    continue;
                }
                close(fd[i][j]);
            }
        }


        int tomb[100]; //helyi tomb
        int tomb7[100];  // "kapott" tomb

        for(int i = 0; i<100; i++){
            read(fd[12][0], &tomb7[i], sizeof(int));
            tomb[i] = tomb7[i];
        }
        int max7 = 0;
        for(int j = 0; j < 100; j++){
            if(tomb[j] > max7){
                max7 = tomb[j];
            }
        }

        write(fd[13][1], &max7, sizeof(int));
        close(fd[12][0]);
        close(fd[13][1]);
        return 0;
    }

    else if(pid8 == 0){
        for(int i = 0; i < 20; i++){
            for(int j = 0; j < 2; j++){
                if(i == 14 && j == 0){
                    continue;
                }
                else if(i == 15 && j == 1){
                    continue;
                }
                close(fd[i][j]);
            }
        }

        int tomb[100]; //helyi tomb
        int tomb8[100];  // "kapott" tomb

        for(int i = 0; i<100; i++){
            read(fd[14][0], &tomb8[i], sizeof(int));
            tomb[i] = tomb8[i];
        }
        int max8 = 0;
        for(int j = 0; j < 100; j++){
            if(tomb[j] > max8){
                max8 = tomb[j];
            }
        }

        write(fd[15][1], &max8, sizeof(int));
        close(fd[14][0]);
        close(fd[15][1]);
        return 0;
    }

    else if(pid9 == 0){
        for(int i = 0; i < 20; i++){
            for(int j = 0; j < 2; j++){
                if(i == 16 && j == 0){
                    continue;
                }
                else if(i == 17 && j == 1){
                    continue;
                }
                close(fd[i][j]);
            }
        }

        int tomb[100]; //helyi tomb
        int tomb9[100];  // "kapott" tomb

        for(int i = 0; i<100; i++){
            read(fd[16][0], &tomb9[i], sizeof(int));
            tomb[i] = tomb9[i];
        }
        int max9 = 0;
        for(int j = 0; j < 100; j++){
            if(tomb[j] > max9){
                max9 = tomb[j];
            }
        }

        write(fd[17][1], &max9, sizeof(int));
        close(fd[16][0]);
        close(fd[17][1]);
        return 0;
    }

    else if(pid10 == 0){
        for(int i = 0; i < 20; i++){
            for(int j = 0; j < 2; j++){
                if(i == 18 && j == 0){
                    continue;
                }
                else if(i == 19 && j == 1){
                    continue;
                }
                close(fd[i][j]);
            }
        }


        int tomb[100]; //helyi tomb
        int tomb10[100];  // "kapott" tomb

        for(int i = 0; i<100; i++){
            read(fd[18][0], &tomb10[i], sizeof(int));
            tomb[i] = tomb10[i];
        }
        int max10 = 0;
        for(int j = 0; j < 100; j++){
            if(tomb[j] > max10){
                max10 = tomb[j];
            }
        }

        write(fd[19][1], &max10, sizeof(int));
        close(fd[18][0]);
        close(fd[19][1]);
        return 0;
    }


    //Parent process
    else{
    for(int i = 0; i < 20; i++){ //a nem használt pipe végék bezárása
        if(i % 2 != 0){
            close(fd[i][1]);
        }
        else{
            close(fd[i][0]);
        }
    }

    int nagyTomb[1000];

    for(int i = 0; i < 1000; i++){ //random szám generálás
        nagyTomb[i] = (rand() % (100 - 0 +1)) + 0;
    }

    int tomb1[100];
    int tomb2[100];
    int tomb3[100];
    int tomb4[100];
    int tomb5[100];
    int tomb6[100];
    int tomb7[100];
    int tomb8[100];
    int tomb9[100];
    int tomb10[100];

    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
    int g;
    int h;
    int i;
    int j;

    int max1;
    int max2;
    int max3;
    int max4;
    int max5;
    int max6;
    int max7;
    int max8;
    int max9;
    int max10;
//alább történik a tömb szétosztása ebben az orbitális for ciklusban
    for(a=0, b=100, c=200, d=300, e=400, f=500, g=600, h=700, i=800, j=900; a<100, b<200, c<300, d<400, e<500, f<600, g<700, h<800, i<900, j<1000; a++, b++, c++, d++, e++, f++, g++, h++, i++, j++){
        tomb1[a] = nagyTomb[a];
        tomb2[a] = nagyTomb[b];
        tomb3[a] = nagyTomb[c];
        tomb4[a] = nagyTomb[d];
        tomb5[a] = nagyTomb[e];
        tomb6[a] = nagyTomb[f];
        tomb7[a] = nagyTomb[g];
        tomb8[a] = nagyTomb[h];
        tomb9[a] = nagyTomb[i];
        tomb10[a] = nagyTomb[j];

    }

//alább történik a tömbök elküldése az egyes processzeknek
        write(fd[0][1], tomb1, sizeof(int) * 100);
        write(fd[2][1], tomb2, sizeof(int) * 100);
        write(fd[4][1], tomb3, sizeof(int) * 100);
        write(fd[6][1], tomb4, sizeof(int) * 100);
        write(fd[8][1], tomb5, sizeof(int) * 100);
        write(fd[10][1], tomb6, sizeof(int) * 100);
        write(fd[12][1], tomb7, sizeof(int) * 100);
        write(fd[14][1], tomb8, sizeof(int) * 100);
        write(fd[16][1], tomb9, sizeof(int) * 100);
        write(fd[18][1], tomb10, sizeof(int) * 100);


        for(int i = 0; i<20; i++){ //az imént használt pipe végek bezárása
            if(i % 2 == 0){
            close(fd[i][1]);
        }
    }

//alább történik a maximumok kiolvasása
        read(fd[1][0], &max1, sizeof(int));
        read(fd[3][0], &max2, sizeof(int));
        read(fd[5][0], &max3, sizeof(int));
        read(fd[7][0], &max4, sizeof(int));
        read(fd[9][0], &max5, sizeof(int));
        read(fd[11][0], &max6, sizeof(int));
        read(fd[13][0], &max7, sizeof(int));
        read(fd[15][0], &max8, sizeof(int));
        read(fd[17][0], &max9, sizeof(int));
        read(fd[19][0], &max10, sizeof(int));



    int maximumokTomb[10] = {max1, max2, max3, max4, max5, max6, max7, max8, max9, max10};

    for(int i = 0; i<20; i++){ //az imént használt pipe végek bezárása
        if(i % 2 != 0){
            close(fd[i][0]);
        }
    }
    //itt várja meg a szülő a gyermekeit
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);
    waitpid(pid3, NULL, 0);
    waitpid(pid4, NULL, 0);
    waitpid(pid5, NULL, 0);
    waitpid(pid6, NULL, 0);
    waitpid(pid7, NULL, 0);
    waitpid(pid8, NULL, 0);
    waitpid(pid9, NULL, 0);
    waitpid(pid10, NULL, 0);

    printf("\nMaximum elemek: \n"); //maximum értékek kiírása
    for(int i = 0; i<10; i++){
        printf("%d\t", maximumokTomb[i]);
    }
    return 0;
    }
}
