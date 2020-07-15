#include <iostream>
#include <stdio.h>

using namespace std;

double exp(){
    char a[10];
    cin >> a;
    switch(a[0])
    {
    case '+': return exp() + exp(); break;
    case '-': return exp() - exp(); break;
    case '*': return exp() * exp(); break;
    case '/': return exp() / exp(); break;
    default: return atof(a); break;
    }
}

int main(){
    double res = exp();
    printf("%f\n", res);
}