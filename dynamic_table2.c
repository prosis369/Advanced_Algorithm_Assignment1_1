#include<stdio.h>
#include<stdlib.h>
#include "dyntable_impl.h"

typedef struct dynamic_table
{
	int noofelements;
	int size;
	int a[0];
}dt;

void* make_new_dynamic_table(int s)
{
	dt* table = malloc(sizeof(*table) + sizeof(int) * s);
	table -> size = s;
	table -> noofelements = 0;
	return table;
}

void push_back(void** table, int element)
{
	if(((dt *)*table)->noofelements < ((dt *)*table)->size)
	{
		((dt *)*table)->a[((dt *)*table)->noofelements] = element;
		((dt *)*table)->noofelements++;
	}
	else
	{
		dt* table1 = make_new_dynamic_table(2*((dt *)*table)->size);
		for(int i = 0; i < ((dt *)*table)->size; i++)
		{
			table1->a[table1->noofelements] = ((dt *)*table)->a[i];
			table1->noofelements++;
		}
		table1->a[table1->noofelements] = element;
		table1->noofelements++;
		*table = table1;
		//free(table1); // check this
	}
}

int pop_back(void** table)
{
	int r;
	if(((dt *)*table)->noofelements == 0)
	{
		return -1;
	}
	else if(((dt *)*table)->noofelements > 0.5*((dt *)*table)->size)
	{
		r = ((dt *)*table)->a[((dt *)*table)->noofelements-1];
		((dt *)*table)->noofelements--;
	}
	else
	{
		dt* table1 = make_new_dynamic_table(0.5*((dt *)*table)->size);
		for(int i = 0; i < ((dt *)*table)->noofelements; i++)
		{
			table1->a[table1->noofelements] = ((dt *)*table)->a[i];
			table1->noofelements++;
		}
		r = table1->a[table1->noofelements-1];
		table1->noofelements--;
		*table = table1;
		//free(table1); // check this
	}
	return r;
}


// int main() {
// 	void* dt1 = make_new_dynamic_table(3);     
// 	push_back(&dt1, 10);
// 	printf("Size: %d\n",((dt *)dt1) -> size);
// 	printf("Number %d\n",((dt *)dt1) -> noofelements);
// 	push_back(&dt1, 20);
// 	printf("Size: %d\n",((dt *)dt1) -> size);
// 	printf("Number %d\n",((dt *)dt1) -> noofelements);
// 	push_back(&dt1, 30);
// 	printf("Size: %d\n",((dt *)dt1) -> size);
// 	printf("Number %d\n",((dt *)dt1) -> noofelements);
// 	push_back(&dt1, 40);
// 	printf("Size: %d\n",((dt *)dt1) -> size);
// 	printf("Number %d\n",((dt *)dt1) -> noofelements);
// 	push_back(&dt1, 50);
// 	printf("Size: %d\n",((dt *)dt1) -> size);
// 	printf("Number %d\n",((dt *)dt1) -> noofelements);
// 	push_back(&dt1, 60);
// 	printf("Size: %d\n",((dt *)dt1) -> size);
// 	printf("Number %d\n",((dt *)dt1) -> noofelements);
// 	push_back(&dt1, 70);
// 	printf("Size: %d\n",((dt *)dt1) -> size);
// 	printf("Number %d\n",((dt *)dt1) -> noofelements);

// 	for(int i = 0; i<((dt *)dt1) -> noofelements; i++)
// 	{
// 		printf("%d\n",((dt *)dt1)->a[i]);
// 	}
// 	pop_back(&dt1);
// 	printf("Size: %d\n",((dt *)dt1) -> size);
// 	printf("Number %d\n",((dt *)dt1) -> noofelements);
// 	pop_back(&dt1);
// 	printf("Size: %d\n",((dt *)dt1) -> size);
// 	printf("Number %d\n",((dt *)dt1) -> noofelements);
// 	pop_back(&dt1);
// 	printf("Size: %d\n",((dt *)dt1) -> size);
// 	printf("Number %d\n",((dt *)dt1) -> noofelements);
// 	pop_back(&dt1);
// 	printf("Size: %d\n",((dt *)dt1) -> size);
// 	printf("Number %d\n",((dt *)dt1) -> noofelements);
// 	pop_back(&dt1);
// 	printf("Size: %d\n",((dt *)dt1) -> size);
// 	printf("Number %d\n",((dt *)dt1) -> noofelements);

// 	for(int i = 0; i<((dt *)dt1) -> noofelements; i++)
// 	{
// 		printf("%d\n",((dt *)dt1)->a[i]);
// 	}

// 	push_back(&dt1, 20);
// 	printf("Size: %d\n",((dt *)dt1) -> size);
// 	printf("Number %d\n",((dt *)dt1) -> noofelements);
// 	push_back(&dt1, 30);
// 	printf("Size: %d\n",((dt *)dt1) -> size);
// 	printf("Number %d\n",((dt *)dt1) -> noofelements);
// 	push_back(&dt1, 40);
// 	printf("Size: %d\n",((dt *)dt1) -> size);
// 	printf("Number %d\n",((dt *)dt1) -> noofelements);
// 	push_back(&dt1, 50);
// 	printf("Size: %d\n",((dt *)dt1) -> size);
// 	printf("Number %d\n",((dt *)dt1) -> noofelements);

// 	for(int i = 0; i<((dt *)dt1) -> noofelements; i++)
// 	{
// 		printf("%d\n",((dt *)dt1)->a[i]);
// 	}
// }