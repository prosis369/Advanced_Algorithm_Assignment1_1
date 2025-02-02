#include<stdio.h>
#include<stdlib.h>
#include <time.h>
// #include "dyntable_impl.h"

typedef struct dynamic_table
{
	int* a;
	int noofelements;
	int size;
}dt;

struct timespec timer_start(){
	struct timespec start_time;
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start_time);
	return start_time;
}

// call this function to end a timer, returning nanoseconds elapsed as a long
long timer_end(struct timespec start_time){
	struct timespec end_time;
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end_time);
	long diffInNanos = (end_time.tv_sec - start_time.tv_sec) * (long)1e9 + (end_time.tv_nsec - start_time.tv_nsec);
	return diffInNanos;
}

void* make_new_dynamic_table(int s)
{
	dt* table = (dt*)malloc(sizeof(dt));
	table -> size = s;
	table -> a = (int*)malloc(sizeof(int)*s);
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
		int *new = (int*)malloc(2*sizeof(int)*(((dt *)*table)->size)); //check if you can use malloc ??
		for(int i = 0; i < ((dt *)*table)->size; i++)
		{
			new[i] = ((dt *)*table)->a[i];
		}
		((dt *)*table)->size = 2*(((dt *)*table)->size);
		((dt *)*table)->a = new;
		((dt *)*table)->a[((dt *)*table)->noofelements] = element;
		((dt *)*table)->noofelements++;
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
		int *new = (int*)malloc(0.5*sizeof(int)*(((dt *)*table)->size));
		for(int i = 0; i < ((dt *)*table)->noofelements; i++)
		{
			new[i] = ((dt *)*table)->a[i];
		}
		r = ((dt *)*table)->a[((dt *)*table)->noofelements-1];
		((dt *)*table)->size = 0.5*(((dt *)*table)->size);
		((dt *)*table)->a = new;
		((dt *)*table)->noofelements--;
	}
	return r;
}


int main() {
	void* dt = make_new_dynamic_table(10);
	for(int i=1; i<=100; ++i) 
	{
        struct timespec vartime = timer_start();
		if(i%2) 
		{       
			int r = random()%100; 
			push_back(&dt, r);
			// printf("Insert: %d\n", r);
		}
        else 
        {
          	int p = pop_back(&dt);   // Changed it to &dt from dt
          	// printf("Pop: %d\n", p);
        }

        long time_elapsed_nanos = timer_end(vartime);
        printf("%ld\n", time_elapsed_nanos);
    }
}

// int main()
// {
// 	void* dt1 = make_new_dynamic_table(3);     
// 	push_back(&dt1, 10);
// 	push_back(&dt1, 11);
// 	push_back(&dt1, 12);
// 	push_back(&dt1, 13);
// 	pop_back(&dt1);
// 	pop_back(&dt1);
// 	pop_back(&dt1);
// }


// int main() {
// 	void* dt1 = make_new_dynamic_table(3);     
// 	push_back(&dt1, 10);
// 	printf("Size: %d\n",((dt *)dt1) -> size);
// 	printf("Number %d\n",((dt *)dt1) -> noofelements);
// 	push_back(&dt1, 20);
// 	printf("Size: %d\n",((dt *)dt1) -> size);
// 	printf("Number %d\n",((dt *)dt1) -> noofelements);
// 	// push_back(&dt1, 30);
// 	// printf("Size: %d\n",((dt *)dt1) -> size);
// 	// printf("Number %d\n",((dt *)dt1) -> noofelements);
// 	// push_back(&dt1, 40);
// 	// printf("Size: %d\n",((dt *)dt1) -> size);
// 	// printf("Number %d\n",((dt *)dt1) -> noofelements);
// 	// push_back(&dt1, 50);
// 	// printf("Size: %d\n",((dt *)dt1) -> size);
// 	// printf("Number %d\n",((dt *)dt1) -> noofelements);
// 	// push_back(&dt1, 60);
// 	// printf("Size: %d\n",((dt *)dt1) -> size);
// 	// printf("Number %d\n",((dt *)dt1) -> noofelements);
// 	// push_back(&dt1, 70);
// 	// printf("Size: %d\n",((dt *)dt1) -> size);
// 	// printf("Number %d\n",((dt *)dt1) -> noofelements);

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