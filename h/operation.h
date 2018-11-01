#include "closure.h"

double daddition(double a, double b);

int iaddition(int a, int b);

long laddition(long a, long b);

float faddition(float a, float b);

Closure* add(double first_arg);

double addition(Closure *closure, double value);

