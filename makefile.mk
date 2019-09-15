a.out: dyntable_client.o dynamic_table1.o
	gcc dyntable_client.o dynamic_table1.o
dyntable_client.o: dyntable_client.c dyntable_impl.h
	gcc -c dyntable_client.c
dynamic_table1.o: dynamic_table1.c dyntable_impl.h
	gcc -c dynamic_table1.c







