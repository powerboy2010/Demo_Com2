#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
	char id[25];
	char name[30];
	int dept;
	float gpa;
	struct node *next;
	
}stu;

stu* createlist(stu **per)
{
	FILE *inf;
	char letter[30],letter2[30];
	
	stu *last,*newnode;
	inf = fopen("data.txt","r");
	newnode = (stu*)malloc(sizeof(stu));
	fscanf(inf,"%s",&letter);
	fscanf(inf,"%s",&letter2);
	fscanf(inf,"%s %s %d %f",&newnode->id,&newnode->name,&newnode->dept,&newnode->gpa);
	newnode->next=NULL;
	
	while(!feof(inf))
	{
		if(*per == NULL)
		{
			*per=newnode;
			last=newnode;
		}
		else
		{
			last->next=newnode;
			last=newnode;
		}
		newnode = (stu*)malloc(sizeof(stu));
		fscanf(inf,"%s %s %d %f",&newnode->id,&newnode->name,&newnode->dept,&newnode->gpa);
		newnode->next=NULL;
	}
	
	
	fclose(inf);
}

void up(stu *per)
{
	stu *run;
	int cnt=0;
	char maxper[25];
	float max=0;
	FILE *out;
	out = fopen("Upper.txt","w");
	fprintf(out,"The Education Profile of student in High GPA \n");
	fprintf(out,"=======================================================\n");
	fprintf(out,"   ID                       Name          Dept.	 GPA\n");
	fprintf(out,"=======                     ====          =====	 ===\n");
	run = per;
	while(run!=NULL)
	{
	
		if(run->gpa>3.00)
		{
			fprintf(out,"%s \t\t    %s",run->id,run->name);
			if(run->gpa>max)
			{
				max=run->gpa;
				strcpy(maxper,run->name);
			}
				cnt++;
			if(run->dept==1)
			{
				fprintf(out,"\t  CS	 %.2f\n",run->gpa);
			}
			else if(run->dept==2)
			{
				fprintf(out,"\t  IT	 %.2f\n",run->gpa);
			}
			else if(run->dept==3)
			{
				fprintf(out,"\t  SE	 %.2f\n",run->gpa);
			}
		}
		

		run=run->next;
	}
	fprintf(out,"\n=============================\n");
	fprintf(out,"Total is %d\n",cnt);
	fprintf(out,"Max GPA is %0.2f from %s",max,maxper);
	fprintf(out,"\n=============================\n");
	
	
	fclose(out);
}

void low(stu *per)
{
	stu *run;
	int cnt=0;
	char minper[20];
	float min=0;
	FILE *out;
	out = fopen("Lower.txt","w");
	fprintf(out,"The Education Profile of student in Low GPA \n");
	fprintf(out,"=======================================================\n");
	fprintf(out,"   ID                       Name          Dept.	 GPA\n");
	fprintf(out,"=======                     ====          =====	 ===\n");
	run = per;
	min=run->gpa;
	while(run!=NULL)
	{
	
		if(run->gpa<=2.99)
		{
			fprintf(out,"%s \t\t    %s",run->id,run->name);
			if(run->gpa<min)
			{
				min=run->gpa;
				strcpy(minper,run->name);
			}
				cnt++;
			if(run->dept==1)
			{
				fprintf(out,"\t  CS	 %.2f\n",run->gpa);
			}
			else if(run->dept==2)
			{
				fprintf(out,"\t  IT	 %.2f\n",run->gpa);
			}
			else if(run->dept==3)
			{
				fprintf(out,"\t  SE	 %.2f\n",run->gpa);
			}
		}
		
		run=run->next;
	}
	
	fprintf(out,"\n================================\n");
	fprintf(out,"Total is %d\n",cnt);
	fprintf(out,"Min GPA is %0.2f from %s",min,minper);
	fprintf(out,"\n================================\n");
	
	fclose(out);
}

int main()
{
	
	stu *per=NULL;
	createlist(&per);
	up(per);
	low(per);
	
	return 0;
	
}

