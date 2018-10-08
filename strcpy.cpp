#include <string>
#include <iostream>
using namespace std;
char* myStrcpy(char* dest, char* src){
    char* temp = dest;
    while((*dest++ = *src++) != '\0')
        ; // <<== Very important!!!

    return temp;
}

int main(){
    char d[] = "worldworld";
    char s[] = "hello";
    char* res = myStrcpy(d, s);
    cout << res << endl;
    return 0;
}
