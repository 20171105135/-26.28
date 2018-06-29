//
//  main.cpp
//  评委打分2
//
//  Created by 王皎 on 18/6/29.
//  Copyright © 2018年 王皎. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <windows.h>
#include <ctime>
using namespace std;
class people
{
private:
    int number;
    char* name;
    char* dateofbirth [8];
    char*  class [10];
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
    void set(int Nnumber,char *Nname,char* Ndateofbirth [], char* Nclass [],char* NphoneNo,int Nscore[],char* Nneirong);
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
            float getaverage;
};
int people::getyouxiao()
{
    int s=score[1];
    return s;
}
float people::getaverage()
{
    float s=score[1]+score[2]+score[3]/3;
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
