#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>

int main(){
	void*handle;
	int (*add) (int, int), (*subtract) (int, int), (*multiply) (int, int);
	float(*divide) (int, int); 
	char *error; 
	handle = dlopen("./lib/libtest.so", RTLD_LAZY); 
	if(!handle) { 
		fputs (dlerror(),stderr); 
		exit(1);
		 } 
	add = dlsym(handle, "add"); 
	if ((error = dlerror()) != NULL) { 
		fprintf (stderr, "%s", error); 
		exit(1);
		 } 
	subtract = dlsym(handle, "subtract"); 
	if ((error = dlerror()) != NULL) {
		fprintf (stderr, "%s", error); 
		exit(1);
		 } 
	multiply = dlsym(handle, "multiply"); 
	if ((error = dlerror()) != NULL) {
		fprintf (stderr, "%s", error); 
		exit(1); 
		} 
	divide = dlsym(handle, "divide"); 
	if ((error = dlerror()) != NULL) { 
		fprintf (stderr, "%s", error); 
		exit(1); 
		}

	int a = 0;
	int b = 0;
	printf(" Number Insert : \n");
	scanf("%d", &a);
	scanf("%d", &b);
	
	printf(" add result : %d\n subtract result : %d\n multiply result %d\n divide result %f\n",add(a,b),subtract(a,b),multiply(a,b),divide(a,b));
	dlclose(handle);
}
