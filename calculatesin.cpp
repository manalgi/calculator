//
// Created by manal on 24-Apr-18.
//

#include <iostream>
#include "Header.h"
double eps = 0.000001;
using namespace std;


//factorial! calculation
double fact(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    else if (n == 2) {
        return 2;
    }
    return n * fact(n - 1);
}

//power calculation
double power(double x,int n) {
    /*if (n == 1) {
     return x;
     }
     return x * power(n - 1, x);*/
    double sum=x;
    for (int i = 1; i < n; i++) {
        sum = sum * x;
    }
    return sum;
}

/*
 //sin calculation
 double calcsin(double x) {
	double numartor=x, denominator=1, sum = 0;
	bool negative = false;
	int num = 1, sign = 1;
	if (x < 0) {
 x = x * -1;
 negative = true;
	}
 
	sum = x;
	cout << x << endl;
	while (eps<(numartor / denominator)) {
 num += 2; sign = sign * -1;
 numartor = power(num, x);
 denominator = fact(num);
 cout << (numartor / denominator)*(double)sign<<endl;
 sum = sum + (numartor / denominator)*(double)sign;
 //cout<<(numartor/denominator)*(double)sign<<endl;
 
 
	};
	if (negative == false)
 return sum;
	else
 return sum * -1;
	return sum;
 }
 */
double calcsin(double x) {
    if (x == 0) {
        return 0;
    }
    double sum = x, temp = x;
    int sign = -1, n = 3;
    do {
        temp = temp * x * x / (n * (n - 1));
        sum = sum + sign * temp;
        
        // update temp value
        n += 2;
        sign *= -1;
    } while (eps < temp);
    
    return sum;
}
double calccos(double x) {
    if (x == 0) {
        return 0;
    }
    double sum = 1, temp = 1;
    int sign = -1, n = 2;
    do {
        temp = temp * x * x / (n * (n - 1));
        sum = sum + sign * temp;
        
        // update temp value
        n += 2;
        sign *= -1;
    } while (eps < temp);
    
    return sum;
}

/*//cos calculation
 double calccos(double x) {
	double numartor = x, denominator, sum = 0;
	int num = 0, sign = 1;
	sum = 1;
	do {
 num += 2; sign = sign * -1;
 numartor = power(num, x);
 denominator = fact(num);
 sum = sum + (numartor / denominator)*(double)sign;
 //cout<<(numartor/denominator)*(double)sign<<endl;
 
 
	} while (eps<(numartor / denominator));
	return sum;
 }*/

double operation(char ch, double x, double y) {
    switch (ch) {
        case('+'): return (x + y); break;
        case('/'): return (x / y); break;
        case('*'): return (x * y); break;
        case('-'): return (x - y); break;
            
    }
    return 0;
}



