#include <iostream>
using namespace std;
void replaceSpace(char* ch, int length){
    int len = 0, slen = 0;
    for(int i = 0; ch[i] != '\0'; i++){
        len++;
        if(ch[i] == ' ') slen++;
    }
    int tlen = len + 2 * slen;
    if(tlen > length) return;
    char* p1 = ch + len, *p2 = ch + tlen;
    // p1 == p2 when all the spaces are replaced
    while(p1 != p2){
        if(*p1 == ' '){
            *p2-- = '0';
            *p2-- = '2';
            *p2-- = '%';
        }
        else{
            *p2-- = *p1;
        }
        p1--;
    }
}

int main(){
    char s[20] = "Hello World";
    replaceSpace(s, 20);
    cout << s << endl;
}
