#include <stdio.h>

void goo(){
    printf("goo\n");
    return;
}
void foo() {
    printf("foo\n");
    goo();
    return;
}
int main(void){

    foo();

    return 0;
}