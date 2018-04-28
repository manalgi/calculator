#include <iostream>
#include <string>
using namespace std;
#include "header.h"
#include <stdio.h>
#include <stdlib.h>

//pass to the right func according to input
double keyboard(char action,double x,double y) {
	if (action == 'p') {
		return power(x, y);
	}
	if (action == 'c') {
		return calccos(x);
	}
	if (action == 's') {
		return calcsin(x);
	}
	if (action == '!') {
		return fact(x);
	}
	return 0;
}
 
//clear console
void clear() {
	system("cls");
}

//take the x and y
double action1(string ac) {
	double x = 1, y = 1;
	char ch;
	ch = ac[0];
	if (ac[0] == 'p')
		y = atof(&ac[4]);
	
	x = atof(&ac[2]); 
	//cout << x << endl << y << endl << ch<<endl ;
	return keyboard(ch, x, y);
}

//clear array
void clr(double arr[]) {
	for (int i = 0; i < 100; i++)
	{
		arr[i] = 0;
	}
}

//detect if the string is a number or an action
double detec(string x) {
	if (x[0] == 'c' || x[0] == 's' || x[0] == '!' || x[0] == 'p') {
		return action1(x);
	}
	else return atof(x.c_str());
}
