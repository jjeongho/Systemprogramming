#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <search.h>


struct Student {

	char student_name[10];
	int mid_score;
	int final_score;
};

struct Student *root = NULL;

int compare(const void *cp1, const void*cp2) {
	return strcmp(((struct Student*)cp1)->student_name,((struct Student*)cp2)->student_name);
}

void print_node(const void *, VISIT , int);

int main() {
	int i,student_number;
	struct Student **ret;
 

	printf("Please enter the number of students. : ");
	scanf("%d",&student_number);


	if(student_number <=0 || student_number == NULL) 
		abort();

 

	struct Student *tree[student_number];
	for(i = 0; i < sizeof(tree) / sizeof(struct Student*); i++) {
		tree[i] = malloc(sizeof(struct Student));
		printf("Please enter a user name to add to the tree (name,middle score, final score) \n");
		scanf("%s %d %d",tree[i]->student_name,&tree[i]->mid_score,&tree[i]->final_score);
 

		ret = (struct Student **) tsearch((void *) tree[i],(void**) &root, compare);
		printf("\"%s\" is ", (*ret)->student_name);


		if (*ret == tree[i])
			printf("Added to tree.\n");
		else
			printf("Already exists in the tree.\n");

		twalk((void *) root, print_node);
		for (int i = 0; i < sizeof(tree) / sizeof(struct Student*); i++) 
		free(tree[i]); 
}


	void print_node(const void *nodeptr, VISIT order, int level)
{
	if (order == preorder || order == leaf)
		printf("name = %-20s, middle score = %d final score = %d\n",(*(struct Student **)nodeptr)->student_name,(*(struct Student **)nodeptr)->mid_score,(*(struct Student **)nodeptr)->final_score);
}
}
