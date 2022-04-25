#include <stdio.h>

struct Student
{
    char SurName[15];
    char Name[15];
    int Kurs;
    int MMath;
    int MPhiz;
    int MInf;
};

void scan(char SurName[], char Name[], int Kurs, int MMath, int MPhiz, int MInf)
{
    char c;
    int i=0;
    while(1){
        scanf("%c",&c);
        if(c==' ') break;
        SurName[i]=c;
        i++;
    }
    i=0;
    while(1){
        scanf("%c",&c);
        if(c==' ') break;
        Name[i]=c;
        i++;
    }
    scanf("%d %d %d %d",&Kurs,&MMath,&MPhiz,&MInf);
}

void Print (char SurName[], char Name[], int Kurs, int MMath, int MPhiz, int MInf)
{
    for(int i=0;i<15;i++) printf("%c",SurName[i]);
    for(int i=0;i<15;i++) printf("%c",Name[i]);
    printf("%5d%5d%5d%5d",Kurs,MMath,MPhiz,MInf);
}

int main()
{
    int n;
    scanf("%d",&n);
    struct Student mus[n];
    for(int i=0;i<n;i++) scan(mus[i].SurName,mus[i].Name,mus[i].Kurs,mus[i].MMath,mus[i].MPhiz,mus[i].MInf);
    for(int i=0;i<n;i++) Print(mus[i].SurName,mus[i].Name, mus[i].Kurs,mus[i].MMath,mus[i].MPhiz,mus[i].MInf);




    return 0;
}
