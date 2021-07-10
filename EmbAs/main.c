#include <stdio.h>
#include <stdlib.h>

struct student {
    char name[20];
    int id;
    int day,month,year;
    int finalscore;
};

struct student A(struct student x);

struct node {
    struct student stud;
    struct node *next;
};

struct node* head;
struct node* tail;
struct node* temp;
struct node* aft;
struct node* pre;

struct student* p;
struct student* newp;

void insertlast();
void insertB();
void insertbeg(struct student x,int n);
void insertbegenning();
void insertend();
void insertmiddle();
void insertmid();

int k;
int n;


int main()
{
     k=4;
    struct student z;
    printf("Welcome to our project\n");
    printf("Please enter the number of students ");
    scanf("%d",n);

    p= (struct student*)calloc(n, sizeof(struct student));


    /*insertbeg(z,n);*/
    int i=1;
    while(i<=n)
{
 *(p+(i-1))=A(z);
 i=i+1;
 }
    return 0;
};

void insertbeginning(struct student x){

temp=(struct node* )malloc(sizeof(struct node));

if (n==0){
    head=tail=temp;
    temp->next= NULL;
    temp->stud= A(x);
}
else {

    temp->next=head;
    temp=head;
    temp->stud= A(x);
}

n++;

};

void insertend(struct student x){

temp=(struct node* )malloc(sizeof(struct node));

if (n==0){

    head=tail=temp;
    temp->next= NULL;
    temp->stud= A(x);

}
else {

    tail->next=temp;
    temp->next=NULL;
    temp->stud=A(x);

    }

n++;

};

void insertmiddle(struct student x){

temp=(struct node* )malloc(sizeof(struct node));

if (n==0){

    head=tail=temp;
    temp->next= NULL;
    temp->stud= A(x);

}
else {

    pre=head;

for (int i=0;i<k-1;i++){

    pre=pre->next;

}
    aft=pre->next;
    temp=pre->next;
    temp->next=aft;
    temp->stud=A(x);
    };

n++;

};

struct student A(struct student x){


printf("Please enter the student name ");
fflush(stdin);
gets(x.name);

printf("Please enter the student ID ");
scanf("%i",&(x.id));

printf("Please enter the student year of birth ");
scanf("%i",&(x.year));

printf("Please enter the student month of birth ");
scanf("%i",&(x.month));

printf("Please enter the student day of birth ");
scanf("%i",&(x.day));

printf("Please enter the student final score ");
scanf("%i",&(x.finalscore));

return x;

};
//--------------------------------------------------------------------
//----------------------------------------------------------------------
//-------------------------------------------------------------------------

void insertB(){
p = calloc(2, sizeof(struct student));
for(int i=0;i<2;i++){
    struct student c = {.name = "student", .id = i+1, .day = i+1, .month = i+1, .year = i+1, .finalscore = i+1};
    *(p+i) =c;
}
    printf ("name = %s, id= %d, day = %d\n", p->name, p->day, p->id);
    printf ("name = %s, id= %d, day = %d\n", (p+1)->name, (p+1)->day, (p+1)->id);
};

void insertbeg(struct student y,int n){

newp=(struct student*)realloc(p,(n+1)*sizeof(struct student));

for(int i=0;i<n+1;i++){
  *(newp+(n+1)-i) = *(newp+n-i);
};

*newp = A(y)
;
printf ("%d", p->id);

};

void insertmid(struct student y,int n,int k){

newp=(struct student*)realloc(p,(n+1)*sizeof(struct student));

for(int i=0;i<n+1;i++){

  while(i=k){
  *(newp+(n+1)-i) = *(newp+n-i);
    };
    *(newp+k) = A(y)
;
};

};


void insertlast(struct student y,int n){

newp=(struct student*)realloc(p,(n+1)*sizeof(struct student));

*(newp+n+1) = A(y)
;

printf ("%d", p->id);

};
