#include <stdio.h>

typedef struct {
 
    int age;
    const char* name;

} Person;

int main(){

    Person p1;

    p1.age = 29;
    p1.name = "Alice";

    printf("The person name is %s and it is %d years old. \n", p1.name, p1.age);

    return 0;
}
