//
//  main.cpp
//  solution
//
//  Created by John on 2/18/14.
//  Copyright (c) 2014 John. All rights reserved.
//

#include <iostream>
using namespace std;

void reverse(char* str);

int main(int argc, const char * argv[]){
    // insert code here...
    char str1[]="Sample string";
    char str2[]="k";
    char str3[]="";
    reverse(str1);
    reverse(str2);
    reverse(str3);
    cout<<str1<<endl;
    cout<<str2<<endl;
    cout<<str3<<endl;
    return 0;
}

void reverse(char* str){
    size_t length = strlen(str) ;
    if (length==0 || length==1) return;
    else {
        size_t c, i, j;
        for (i = 0, j = length - 1; i < j; i++, j--){
            c = str[i];
            str[i] = str[j];
            str[j] = c;
        }
    }
}