#include "VectorInC.h"


int main()
{
double a;
double e1 = 1.111;
double e2 = 2.222;
double e3 = 3.333;
double e4 = 4.444;
double e5 = 5.555;


uVector *vector = newv(uVECTOR_TYPE_DOUBLE);
vector->push_back(vector,&e1);
vector->push_back(vector,&e2);
vector->push_back(vector,&e3);
vector->push_back(vector,&e4);
vector->push_back(vector,&e5);


a =*((double*)(vector->front(vector)));
printf("%lf",a);
return 0;

}
