#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main() {
    int child;


    mkfifo("file", S_IRUSR | S_IWUSR );

    child = fork();

    if(child > 0) {
        char s[1024];
        int fd;


        fd = open("file", O_RDONLY);
        read(fd, s, sizeof(s));
        printf("%s", s);

        close(fd);
        unlink("file");
    } else if(child == 0) {
        int fd;


        fd = open("file", O_WRONLY);
        write(fd, "Slyízs István Gábor\n", 30);
        close(fd);
    }

    return 0;
}
