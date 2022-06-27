#include <stdio.h>
#include <string.h>
struct Library
{
      char bname[100];
      int bid,f,stat;
}lb[10];
int tot=0,v=0;
void Add()
{
      int n,i;
      printf("\nEnter the no.of Books to be added\n");
      scanf("%d",&n);
      tot+=n;
      for(i=v;i<tot;i++)
      {
          printf("Enter Book Name\n");
          scanf("%s",lb[i].bname);
          printf("Enter Book ID\n");
          scanf("%d",&lb[i].bid);
          lb[i].f=1;
      }
      v=i;
}
void View()
{
      int i;
      printf(tot>0 ? "The Available books are:\n":"No Books are available\n");
      for(i=0;i<tot;i++)
      {
        if(lb[i].f)
        printf("%s %d\n",lb[i].bname,lb[i].bid);
      }
}
void Issue()
{
    char x[100];
    int i,f;
    printf("Enter the Book Name\n");
    scanf("%s",x);
    for(i=0;i<tot;i++)
    {
        if(!strcmp(x,lb[i].bname)&& lb[i].f==1)
        {
            lb[i].f=0;
            f=1;break;
        }
    }
    printf(f==1 ? "Books Issued\n" : "Book Not Available\n");
}
void ViewIssued()
{
    int i;
    for(i=0;i<tot;i++)
    {
        if(lb[i].f==0)
        {
            printf("%s %d\n",lb[i].bname,lb[i].bid);
        }
    }
}
void Return()
{
    int i,f;
    char r[100];
    printf("Enter the Name of the Book to be returned\n");
    scanf("%s",r);
    for(i=0;i<tot;i++)
    {
        if(!strcmp(r,lb[i].bname)&& lb[i].f==0)
        {
            lb[i].f=1;
            f=1;break;
        }
    }
    printf(f==1 ? "Books Returned\n" : "Try Again\n");
    
}
int main()
{
      int a,b,n,i;
      while(1)
      {
      	    printf("\t\t Welcome to Library\t\t");
            printf("\n  1.Add/View books\n  2.Issue books\n  3.View Issued Books\n  4.Return Books\n  5.Exit\n");
            scanf("%d",&a);
            if(a==5)
            {
                  break;
            }
            else if(a==1)
            {
                  while(1)
                  {
                        printf("\n  1.Add Books\n  2.View Books\n  3.Exit\n");
                        scanf("%d",&b);
                        if(b==3)
                              break;
                        else if(b==2)
                              View();
                        else if(b==1)
                              Add();
                        else
                        printf("Invalid Input\n");
                        break;
                  }
            }
            else if(a==2)
            {
                  Issue();
            }
            else if(a==3)
            {
                 ViewIssued();
            }
            else if(a==4)
            {
                 Return();
            }
            
            
      }
}
