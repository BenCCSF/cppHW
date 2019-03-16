#include <iostream>
using namespace std;

void _strcpy( char *dest, const char *src);
void _strncpy( char *dest, const char *src, int n);
void _strcpy2 ( char *dest, const char *src);
int _strlen (const char* str);
int _strcmp( const char* str1, const char* str2);
int _strncmp (const char* str1, const char* str2, int n);
char* _strstr(char *str1, char *str2); 
void _strcat(char* str1, const char* str2);
void _strncat(char* str1, const char* str2, int n);

int main() {
    const char* mysource = "demon king";
    char mydestination[100] = "a cool thing is a ";
    _strncat(mydestination, mysource, 3);
    cout << "_strcpy " << mydestination << endl;
    int l = _strlen(mydestination);
    cout << "_strlen " << l << endl;
    const char *s1 = "tricksters";
    const char *s2 = "trickster";
    cout << "S1 & S2 compare as follows : " <<_strncmp(s1, s2, 9)<<endl;
    char s3[100] = "something";
    char s4[100] = "some";
    cout << "Strstr of s3 and s4 : " << _strstr(s3, s4) << endl;
    return 0;
}
// example of string copy operation
void  _strcpy(char *destination, const char *source) {
 
    int i=0;
    while(source[i]) {
        destination[i] = source[i];
        i++;
    }
    destination[i] = '\0';
}
 
//more elegant implementation of string copy
void _strcpy2(char *destination, const char *source) {
 
   //check if source is not null and destination is not null
   while(*destination++ = *source++);
}
 
//example implementation of string length.
int _strlen(const char* str) {
 
    int len=0;
    while(*str++) len++;
    
    return len;
}
//example implementation of string compare
int _strcmp(const char* s1, const char* s2) {
   while(*s1 && (*s1 == *s2)) {
       s1++;
       s2++;
    }
    return *(const unsigned char*)s1 - *(const unsigned char*)s2;
}
 
//Fill in this method so that calling _stracat can append s2 contents to s1
void _strcat(char* s1, const char* s2) {
    //First find end of str1
    while(*s1) s1++;
    //Now copu string 2 into string 1
    while((*s1++ = *s2++));
}
//check if string s2 is inside or embedded within string s1
char* _strstr(char *s1, char *s2) {
    char *s2iter = s2;
    //For going through s2 (we still want to know the start of s2)
    while (*s1) {
        if (*s1 == *s2iter) {
            if (!*++s2iter) return ++s1;
            //change s2iter by one, and then check if the value it points to is null. If true, we return a pointer to the next character of s1
        }
        else {
            s2iter = s2;
        }
        s1++;
    }
    return s1; //In this case, the function returns a null charater, implying that s1 is not inside s2
}
// _strcpy for specified number of characters n.
void _strncpy(char *s1, const char* s2, int n) {
    int i = 1;
    while((*s1++ = *s2++) && i++ < n);
    if (i == n) {
        //If we exited because of hitting n, add exit char
        s1 = '\0';
    }
}
// _strcmp for specified number of characters n
int _strncmp(const char* s1, const char*s2, int n) {
    int i = 1;
    while(i++ < n && *s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return *(const unsigned char*)s1 - *(const unsigned char*)s2;
}
// _strcat for specified number of characters n.
void _strncat(char* s1, const char *s2, int n) {
    while(*s1) s1++;
    int i = 1;
    while((*s1++ = *s2++) && i++ < n);
    if (i == n) {
        //If we exited because of hitting n, add exit char
        s1 = '\0';
    }
}
