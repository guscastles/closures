#include "operation.h"
#include <malloc.h>

double daddition(double a, double b) {
    return a + b;
}

int iaddition(int a, int b) {
    return (int) daddition(a, b);
}

long laddition(long a, long b) {
    return (long) daddition(a, b);
}

float faddition(float a, float b) {
    return (float) daddition(a, b);
}

double addition(Closure *closure, double value) {
    return daddition(closure->first_arg, value);
}

Closure* add(double first_arg) {
    Closure *closure = malloc(sizeof(closure));
    closure->first_arg = first_arg;
    closure->call = &addition;
    
    return closure;
}

