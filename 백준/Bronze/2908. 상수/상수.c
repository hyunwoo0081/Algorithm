#include <stdio.h>

int main(){
    char a[7], tmp;
    scanf("%[^\n]s", a);
    
    if(a[2] > a[6] || (a[2] == a[6] && a[1] > a[5]) || (a[2] == a[6] && a[1] == a[5] && a[0] > a[4]))
        printf("%c%c%c",a[2],a[1],a[0]);
    else
        printf("%c%c%c",a[6],a[5],a[4]);
    
    return 0;
}
