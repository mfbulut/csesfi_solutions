#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>

typedef long long i64;
#define range(i,a,b) for(i64 i=(a);(i<(b));(i)++)
int toggleBit(int N, int K) { return (N ^ (1 << K)); }

i64 goal = 0;
i64 count = 0;
i64 buttons[10000] = {0};

i64 find_buttons() {
    range(i, 0, count) {
        if(buttons[i] == goal) return 1;
    }
    
    range(i, 0, count) {
        range(j, 0, count) {
            if((buttons[i] ^ buttons[j]) == goal) return 2;
        }
    }
    
    range(i, 0, count) {
        range(j, 0, count) {
            range(k, 0, count) {
                if((buttons[i] ^ buttons[j] ^ buttons[k]) == goal) return 3;
            }
        }
    }
    
    range(i, 0, count) {
        range(j, 0, count) {
            range(k, 0, count) {
                range(l, 0, count) {
                    if((buttons[i] ^ buttons[j] ^ buttons[k] ^ buttons[l]) == goal) return 4;
                }
            }
        }
    }
    
    range(i, 0, count) {
        range(j, 0, count) {
            range(k, 0, count) {
                range(l, 0, count) {
                    range(m, 0, count) {
                        if((buttons[i] ^ buttons[j] ^ buttons[k] ^ buttons[l] ^ buttons[m]) == goal) return 5;
                    }
                }
            }
        }
    }
    
    range(i, 0, count) {
        range(j, 0, count) {
            range(k, 0, count) {
                range(l, 0, count) {
                    range(m, 0, count) {
                        range(n, 0, count) {
                            if((buttons[i] ^ buttons[j] ^ buttons[k] ^ buttons[l] ^ buttons[m] ^ buttons[n]) == goal) return 6;
                        }
                    }
                }
            }
        }
    }
    
    range(i, 0, count) {
        range(j, 0, count) {
            range(k, 0, count) {
                range(l, 0, count) {
                    range(m, 0, count) {
                        range(n, 0, count) {
                            range(o, 0, count) {
                                if((buttons[i] ^ buttons[j] ^ buttons[k] ^ buttons[l] ^ buttons[m] ^ buttons[n] ^ buttons[o]) == goal) return 7;
                            }
                        }
                    }
                }
            }
        }
    }
    
    range(i, 0, count) {
        range(j, 0, count) {
            range(k, 0, count) {
                range(l, 0, count) {
                    range(m, 0, count) {
                        range(n, 0, count) {
                            range(o, 0, count) {
                                range(p, 0, count) {
                                    if((buttons[i] ^ buttons[j] ^ buttons[k] ^ buttons[l] ^ buttons[m] ^ buttons[n] ^ buttons[o] ^ buttons[p]) == goal) return 8;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    
    return -1;
}


i64 sum = 0;

int main() {
    FILE *fp = fopen("adventofcode/day10.txt", "r");
    
    start:
    goal = 0;
    count = 0;
    range(i, 0, 10000) buttons[i] = 0;
    
    i64 bit = 0;
    char c = 0;
    while (fscanf(fp, "%c", &c) == 1) {        
        if(c == '\n') break;
        else if(c == '.') bit++;
        else if(c == '#')  goal = toggleBit(goal, bit++);
        else if(c == '(') {
            i64 num;
            while (fscanf(fp, "%lld", &num) == 1) {
                buttons[count] = toggleBit(buttons[count], num);
                fscanf(fp, ",");
            }
            count++;
        }
    }
    if(goal == 0) return 0;
    
    printf("Goal: %lld\n", goal);
    printf("%lld\n", find_buttons());
    
    sum += find_buttons();
    printf("%lld\n", sum);
    
    goto start;
}


