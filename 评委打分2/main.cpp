//
//  main.cpp
//  评委打分2
//
//  Created by 王皎 on 18/6/29.
//  Copyright © 2018年 王皎. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;
class people
{
private:
    int number;
    char* name;
    char* dateofbirth [8];
    char* class_ [10];
    char* phoneNo [10];
    int score [5];
    char* neirong;
public:
    void pai();
    int gao;
    int di;
    float average;
    float  youxiao;
    float getaverage();
    float getyouxiao();
    void set(int Nnumber,char *Nname,char* Ndateofbirth [], char* Nclass_ [],char* NphoneNo,int Nscore[],char* Nneirong);
    void show1();
    void show2();
    void show3()
    {
        for(int i=0;i<5;i++)
        {
            cout<<score[i]<<"  ";
        }
    }
    int getgao();
    int getdi();
    float getaverage_;
};
float people::getyouxiao()
{
    int s=score[1];
    return s;
}
float people::getaverage()
{
    float s=(score[1]+score[2]+score[3])/3;
    return s;
}
int people::getgao()
{
    int s=score[0];
    return s;
}
int people::getdi()
{
    int s=score[4];
    return s;
}
void people ::pai()
{
    for (int j=0;j<4;j++)
    {
       for (int i=0;i<4-j;i++)
        {
            if(score[i]<score[i+1])
            {
                int t=score[i];
                score[i]=score[i+1];
                score[i+1]=t;
            }
        }
    }
}
void people::set (int Nnumber,char* Nname,char* Ndateofbirth[], char* Nclass_ [],char* NphoneNo,int Nscore[],char* Nneirong )
{
    number=Nnumber;
    name=new char[20];
    strcpy(name,Nname);
    for(int i=0;i<5;i++)
    {
        score[i]=Nscore[i];
        
    }
    neirong=new char[20];
    strcpy(neirong,Nneirong);
}
void people::show1()
{
    cout<<number<<"\t\t"<<name<<"\t\t"<<neirong<<"\t\t";
    for(int i=0;i<5;i++)
    {
        cout<<score[i]<<"  ";
    }
    cout<<endl;
}
void people::show2()
{
    cout<<number<<"\t\t"<<name<<"\t\t"<<gao<<"\t\t"<<di<<"\t\t"<<average;
}
int main(int arge , const char * argv[])
{
    FILE *a;
    char s1[200];
    char s2[200];
    char s3[200];
    char s4[200];
    char s5[200];
    char s6[200];
    if ((a=fopen("/Users/20171105135a/Desktop/评委打分2/评委打分2/6.29.strings","r"))==0)
    {
        printf ("文件不存在\n");
    }
    
    else{
        fscanf(a,"%s ,%s ,%s ,%s ,%s ,%s",s1,s2,s3,s4,s5,s6);
        printf("%s \n%s \n%s \n%s \n%s \n%s \n",s1,s2,s3,s4,s5,s6);
    }
    return 0;
}


