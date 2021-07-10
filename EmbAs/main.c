#include <stdio.h>
#include <stdlib.h>
struct student {
    char studentName[20];
    int id;
    int day, month, year;
    int finalScore;
};
struct node {
    struct student info;
    struct node* next;
};
int m, i;
int n;
struct node* head;
struct node* tail;
struct student* temp;
struct node* new_node;
void linkedLists(void);
void array(void);
struct student insert(struct student y);
void insertEnd_A(struct student* point, int m, struct student x);
void insertFirst_A(struct student* point, int m, struct student x);
void insertMiddle_A(struct student* point, int m, struct student x);
void insertFirst_l(struct student x);
void insertEnd_l(struct student x);
void insertMiddle_l(struct student x, int y);




int main()
{
    printf("Welcome to our project \n\n");
    int z;
    printf("please choose your suitable choice\n");
    printf("1-linked lists , 2-dynamic array \n");
    scanf("%d", &z);
    switch (z)
    {
        case 1 :
            linkedLists();
            break;
        case 2 :
            array();
            break;
        default: printf("please Enter a suitable choice");
            break;
    }


    for (i = 1;i <= n;i++)
    {
        printf("Name of Student please : ");
        printf("%s\n", (((temp + (i - 1))->studentName)));
    }

    return 0;
}
void linkedLists(void)
{
    int h;
    m = 0;
    struct student s;
    s.day = 0;
    s.month = 0;
    s.year = 0;
    s.id = 0;
    s.finalScore = 0;
    head = NULL;
    tail = NULL;
    printf("Enter the number of students please: \n");
    scanf("%i", &n);
    for (i = 1;i <= n;i++)
    {
        insertEnd_l(s);
    }


    printf("1-insert at first \n 2-insert at end \n 3-insert at middle \n 0-exit \n");
    scanf("%d", &h);
    switch (h)
    {
        case 1:
            insertFirst_l(s);
            break;
        case 2:
            insertEnd_l(s);
            break;
        case 3:
            insertMiddle_l(s, n);
        case 0:
            break;
    }

}

void array(void)
{
    int h;
    struct student* ptr;
    struct student s;
    s.day = 0;
    s.month = 0;
    s.year = 0;
    s.id = 0;
    s.finalScore = 0;
    printf("Enter number of students please: \n ");
    scanf("%i", &n);
    ptr = (struct student*)malloc(n * sizeof(struct student));
    int k;
    for (i = 1;i <= n;i++)
    {
        *(ptr + (i - 1)) = insert(s);

    }

    printf("1-insert at beginning \n 2-insert at end \n 3-insert at middle \n 0-exit \n");
    scanf("%d", &h);
    switch (h)
    {
        case 1:
        {
            insertFirst_A(ptr, n, s);
            n++;
            break;
        }
        case 2:
        {
            insertEnd_A(ptr, n, s);
            n++;
            break;
        }
        case 3:
        {
            insertMiddle_A(ptr, n, s);
            n++;
            break;
        }
        case 0:
            break;
    }

}


void insertEnd_A(struct student* point, int m, struct student x)
{
    m++;
    /*struct student* temp;*/
    printf("Enter the new student please\n");
    temp = (struct student*)realloc(point, (m) * sizeof(struct student));
    *(temp + m-1) = insert(x);
    /*free(point);*/
    /*printf("%i", temp->id);*/


}

void insertFirst_A(struct student* point, int m, struct student x)
{
    m++;
    int k;
    /*struct student* temp;*/
    temp = (struct student*)realloc(point, (m) * sizeof(struct student));
    for (k = m-1;k >= 1;k--)
    {
        *(temp + k) = *(temp + (k - 1));

    }
    printf("Enter the new student please \n");
    *temp = insert(x);
}

void insertMiddle_A(struct student* point, int m, struct student x)
{
    int k;
    m++;
    /*struct student* temp;*/
    temp = (struct student*)realloc(point, (m) * sizeof(struct student));
    if ((m) % 2 == 0) {
        for (k = m-1;k > (m) / 2;k--)
        {
            *(temp + k) = *(temp + (k - 1));

        }
        printf("Enter the new student please \n");
        *(temp + ((m) / 2)) = insert(x);
    }
    else
    {
        for (k = m-1;k > m / 2;k--)
        {
            *(temp + k) = *(temp + (k - 1));

        }
        printf("Enter the new student please \n");
        *(temp + (m / 2)) = insert(x);
    }
}

struct student insert(struct student y)
{
    printf("enter name of student please \n");
    fflush(stdin);
    scanf("%*c");
    fgets(y.studentName, sizeof(y.studentName), stdin);
    printf("Enter id of student please\n");
    scanf("%i", &(y.id));
    printf("Enter the day of birth please :\n");
    scanf("%i", &(y.day));
    printf("Enter the month of birth please :\n");
    scanf("%i", &(y.month));
    printf("Enter year of birth please :\n");
    scanf("%i", &(y.year));
    printf("Enter final score please :\n");
    scanf("%i", &(y.finalScore));
    return y;
}

void insertFirst_l(struct student x)
{
    if (m == 0)
    {
        new_node = (struct node*)malloc(sizeof(struct node));
        head = tail = new_node;
        new_node->next = NULL;
        new_node->info = insert(x);

    }
    else
    {
        new_node = (struct node*)malloc(sizeof(struct node));
        new_node->next = head;
        head = new_node;
        new_node->info = insert(x);
    }
    m++;
}

void insertEnd_l(struct student x)
{
    if (m == 0)
    {
        new_node = (struct node*)malloc(sizeof(struct node));
        head = tail = new_node;
        new_node->next = NULL;
        new_node->info = insert(x);


    }
    else
    {
        new_node = (struct node*)malloc(sizeof(struct node));
        tail->next = new_node;
        new_node->next = NULL;
        tail = new_node;
        new_node->info = insert(x);

    }
    m++;
}
void insertMiddle_l(struct student x, int y)
{
    int d;//counter
    struct node* curr;
    new_node = (struct node*)malloc(sizeof(struct node));
    curr = head;
    if ((y + 1) % 2 == 0)
    {
        for (d = 1;d < (y + 1) / 2;d++)
        {
            curr = curr->next;
        }
        new_node->next = curr->next;
        curr->next = new_node;
        printf("\n enter the new student \n");
        new_node->info = insert(x);
        m++;
    }
    else
    {
        for (d = 1;d < y / 2;d++)
        {
            curr = curr->next;
        }
        new_node->next = curr->next;
        curr->next = new_node;
        printf("\n enter the new student \n");
        new_node->info = insert(x);
        m++;
    }

}
