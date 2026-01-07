#include <stdio.h>
#include <unistd.h>

const char* LED_PATH = "/sys/class/leds/input2::capslock/brightness";

void toggle_led(){

    static int state = 0;
    state ^= 1;

    int brightness = state ? 255 : 0;
 
    FILE *fp = fopen(LED_PATH, "w");

    if (fp){
        fprintf(fp, "%d", brightness);
        fclose(fp);
    }else{
        perror("Error opening LED file. Try with sudo");
        return;
    }

    printf("Caps Lock LED is now: %s \n", state ? "ON" : "OFF");
}

int main(){

    printf("Starting blinking simulation .... \n");

    for (int i = 0; i < 10; i++){
        toggle_led();
        usleep(500000);
    }

    return 0;
}
