#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#define SEMKEY 0x12  // Kulcs

	int semid, nsems, rtn;
	unsigned nsops;	// Konstruktor darabsz�ma amivel foglalkoznia kell
	int semflg;
	struct sembuf sembuf, *sop;


int main()
{


	nsems = 1;
	semflg = 00666 | IPC_CREAT;
	semid = semget (SEMKEY, nsems, semflg);
	if (semid < 0 )
	{
        perror("semget() hiba!\n"); exit(0);
	}
	else
        printf("Azonos�t�: %d\n",semid);
        printf ("\n");

	nsops = 1;		//Egy m�velet van
	sembuf.sem_num = 0;	//A 0-ik szemaforral foglakozunk
	sembuf.sem_op = 1;	// N�vel�s
	sembuf.sem_flg = 0666;	// Flag be�ll�t�s
	sop = &sembuf;		// Argumentum k�r�se
	rtn = semop(semid, sop, nsops); // A 0-val visszat�r� semop sikeres.

	printf("Visszat�r�si �rt�k: %d\n",rtn);

    return 0;

}
