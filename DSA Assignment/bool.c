#include<stdbool.h>
#include<stdio.h>

int boolean(int a){
    bool x = true;
    bool y = false;
    if (a == 0) {
        return y;
    }
    if (a == 1) {
        return x;
    }
}

bool stuff(int a){
    if (a == 0) {
        return false;
    }
    if (a == 1) {
        return true;
    }
}

bool array(int a){
    bool arr[] = {true, false};
    if (a == 0) {
        return arr[1];
    }
    if (a == 1) {
        return arr[0];
    }
}

int main(void) {
    if (boolean(1)) {
        printf("This is true \n");
    }
    if (!boolean(0)) {
        printf("This is false \n");
    }
    if (stuff(1)) {
        printf("This is true \n");
    }
    if (!stuff(0)) {
        printf("This is false \n");
    }
    if (array(1)) {
        printf("This is true \n");
    }
    if (!array(0)) {
        printf("This is false \n");
    }

}



