#include <stdio.h>
#define MAX 20
typedef int Values[MAX];

int changeArr(int vals2[]) {
    vals2[0] = 200;
    vals2[1] = 100;
    printf("%d and ", vals2[0]);
    printf("%d\n", vals2[1]);
    return 0;
}   

int main (int argc, char *argv[]) {

    Values vals;
    changeArr(vals);
    printf("%d and ", vals[0]);
    printf("%d\n", vals[1]);
    return 0;

}