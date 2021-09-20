#include<stdio.h>
#include<stdlib.h>
#include"Person.h"
#include"StackCursorBased.h"

int main(){
	Stacklist s=-1;
	VSpace vs;
	Person List[5]={
	{"Kirk", 'M',"Cebu"},
	{"Gel", 'F',"Lapu-Lapu"},
	{"Ajax", 'M',"Tokyo"},
	{"Vladmir", 'M',"Helsinki"},
	{"Joshua", 'M',"Maryland"},
	}
	
	initVSpace(&vs);
	push(&vs,List[4]);
	push(&vs, List[0]);
	pop(&vs);
	display(vs, s);
	insertSorted(&vs, &s, List[3]);
	removeFromList(&vs,"Cebu",&s);
	display(vs, s);
	
	return 0;
}

