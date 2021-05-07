#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#define SEMKEY 0x12  // Kulcs

	int semid,	// Szemafor azonos�t�
	    nsems,	// Szemaforok sz�ma
	    semnum,	// Szemafor sz�ma
	    rtn;	// Visszat�r�si �rt�k

	int semflg;	// Flag
	struct sembuf sembuf, *sop;
    union semun;

	int cmd;	// semctl()-nek sz�l� parancs v�ltoz�ja

int main()
{

    int arg;


	nsems = 1;	// Egyetlen szemafor a set-ben
	semflg = 00666 | IPC_CREAT;
	semid = semget (SEMKEY, nsems, semflg);
	if (semid < 0 ) {perror("semget() hiba!\n"); exit(0);}
	else printf("\n Az azonos�t�: %d\n",semid);
	printf ("K�rem a semval erteket: ");

	semnum = 0;	// 0. szemafort azonos�tom

	cmd = SETVAL;	// �ll�tsd be a szemafor �rteket
	scanf("%d", &arg);
	rtn = semctl(semid, semnum, cmd, arg); // Semid-vel azonos�tott set 0-ik szemafor

	printf("\nVisszat�r�si �rt�k: %d\nSemval �rt�ke: %d\n",rtn, arg);

    return 0;

}
