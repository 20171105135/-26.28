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
public:
    void pai();
    int gao;
    int di;
    float average;
    float  youxiao;
    float getaverage();
    float getyouxiao();
    void set(int Nnumber,char *Nname,char* Ndateofbirth [], char* Nclass_ [],char* NphoneNo,int Nscore[]);
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
void people::set (int Nnumber,char* Nname,char* Ndateofbirth[], char* Nclass_ [],char* NphoneNo,int Nscore[] )
{
    number=Nnumber;
    name=new char[20];
    strcpy(name,Nname);
    for(int i=0;i<5;i++)
    {
        score[i]=Nscore[i];
        
    }
}
void people::show1()
{
    cout<<number<<"\t\t"<<name<<"\t\t";
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
void main()
{
    int i,j;
    int Nnumber;
    char* Nname=new char[20];
    int Nscore[5];
    people p[5];
    for(i=0;i<5;i++)
    {
        cout<<"输入"<<i+1<<"号选手的信息"<<endl;
        cout<<"编号:";
        cin>>Nnumber;
        cout<<"姓名:";
        cin>>Nname;
        cout<<"评委打分:"<<endl;
        for(j=0;j<5;j++)
        {
            cout<<"第"<<"j+1"<<"个评委打分："；
            cin>>Nscore[j];
            
        }
        p[i].set(Nnumber,Nname,Nscore);
    }
    ofstream f1("f1.txt");
    for(i=0;i<5;i++)
    {
        f1.write((char*)(&p[i]),sizeof(p[i]));
    }
    f1.close();
    ifstream f2("f1.txt");
    system("cls");
    cout<<"number\t\tname\t\tscore“<<endl;
    for(i=0;i<5;i++)
    {
        f2.read((char*)(&p[i]),sizeof(p[i]));
        p[i].show1();
        cout<<endl;
    }
    f2.close();
    cout<<"按任意键开始统计“;
    getch();
    system("cls");
    cout<<"number\t\tname\t\tgao\t\tdi\t\taverage"<<endl;
    for(i=0;i<5;i++)
    {
        p[i].pai();
        p[i].gao=p[i].getgao();
        p[i].di=p[i].getdi();
        
    }
    ofstream f4("f2.txt");
    for(i=0;i<5;i++){
        f4.write((char*)(&p[i]));
        
    }
    f4.close();
    ifstream f5("f2.txt");
    for(i=0;i<5;i++){
        f4.write((char*)(&p[i])sizeof(p[i]));
    }
    f4.close();
    ifstream f5("f2.txt");
    for(i+0;i<5;i++){
        f5.read((char*)(&p[i]),sizeof(p[i]));
    }
    f4.close();
    ifstream f5("f2.txt");
    for(i=0;i<5:i++){
        f5.read((char*)(&p[i]),sizeof(p[i]));
    }

    }











