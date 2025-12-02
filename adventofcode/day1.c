#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp = fopen("adventofcode/day1.txt", "r");

    int result = 0;
    int current = 50;

    char direction;
    int value;
    while (fscanf(fp, " %c%d", &direction, &value) == 2) {
        if(direction == 'R') {
            current += value;

            while(current > 99) {
                current -= 100;
            }

        } else {
            current -= value;

             while(current < 0) {
                current += 100;
            }
        }

        if(current == 0) {
            result += 1;
        }
    }

    printf("%d", result);
}