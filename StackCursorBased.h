#ifndef STACKCURSORBASED_H
#define STACKCURSORBASED_H
#define MAX 100

#include "Person.h"

typedef Person Type;
typedef int Position;
typedef int StackList;

typedef struct {
    Person elem;
    Position next;
} CNode;

typedef struct {
    CNode data[MAX];
    Position avail;
} VSpace;


void initVSpace(VSpace *vs);
int allocSpace(VSpace *vs);
void freeSpace(VSpace *vs, int position);
void push(VSpace *vs, Person elem);
void pop(VSpace *vs);
Person peek(VSpace VS);
void insertSorted(VSpace *vs, StackList *s, Person data);
void removeFromList(VSpace *vs, String city, StackList *s);

void initVSpace(VSpace *vs){
	int i;
	for(i=MAX-1; i>=0; i--){
		vs->data[i].next=i-1;
	}
	vs->avail=MAX-1;
}
int allocSpace(VSpace *vs){
	Position retVal=vs->avail;
	if(vs->avail!=-1){
		vs->avail=vs->s[vs->avail].next;
	}
	return retVal;
}
void freeSpace(VSpace *vs, Position index){
	if(index!=-1 && index<MAX){
		vs->s[index].next=vs->avail;
		vs->avail=index;
	}
}
void push(VSpace *vs, Person data){
	StackList temp=allocSpace(vs);
	if(temp!=-1){
		vs->data[temp].elem=data;
		vs->data[temp].next=*s;
		*s=temp;
	}else{
		printf("The List is full.\n");
	}
}


void pop(VSpace *vs, StackList *s){
	if(!isEmpty(*vs, *s)){
		Position temp;
		temp=*s;
		*s=vs->data[temp].next;
		freeSpace(vs, temp);
	}
}
Person peek(VSpace vs, StackList s){
	return vs.data[s].elem;
}



/************************************************************************************************
 * Create a function that would insert a new person based on the order of the city in ASC order. 
 * Top must always have the smallest value.
 * Utilize the functions push, pop, and peek.
 * HINT: You could use also another stack/temporary stack.
 * **********************************************************************************************/
 void insertSorted(VSpace *vs, StackList *s, Person data){
 	Person temp;
 	VSpace tempStack;
 	int i,j;
 	j=s;
	i=s;
 	tempStack=vs;
 	while(strcmp(vs->data[i].elem.city, temp.city)==0){
 		temp=peek(vs);
 		push(&tempStack, temp);
 		pop(&vs);
 		i=vs->data[i].next;
	 }
	 push(&tempStack, data);
	 while(tempStack.data[j].next!=-1){
	 	temp=peek(tempStack);
	 	push(&vs, temp);
	 	pop(&tempStack);
	 }
	 
 }
/************************************************************************************************
 * Create a function that would extract (remove from the original list) the person living from a
 * specified city.
 * Utilize the concept of stack but will not use the functions push, pop, and peek.
 * HINT: You could use also another stack/temporary stack.
 * **********************************************************************************************/
void removeFromList(VSpace *vs, String city, StackList *s){
	int i,j;
	VSpace tempStack;
	tempStack=vs;
	
	for(i=s;i!=1 && strcmp(vs->data[i].elem.city, city) != 0;i=vs->data[i].next){}
	for(j=s; j!=i-1;j=vs->data[j].next){}
	vs->data[j].next=i+1;
	freeSpace(vs, i);
}
// visualization
void visualize(VSpace vs, StackList s){
	Position trav;
	for(trav=s; trav!=-1; trav=vs.s[trav].next){
		displayPersonInfo(vs->data[trav].elem);
	}
}

// display

void display(VSpace vs, StackList s){
	Position trav;
	for(trav=s; trav!=-1; trav=vs.s[trav].next){
		displayPersonInfo(vs->data[trav].elem);
	}
}

#endif
