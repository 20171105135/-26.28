#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <cstring>
using namespace std;
class Competitor {
private:
    string id;
    string name;
    string birthday;
    string class_;
    string phoneNumber;
    vector<int>score;
    double average;
public:
    Competitor(string id,string name,string birthday,string class_,string phoneNumber,vector<int>score);
    double getAverage();
    string getId();
    string getName();
    string getClass();
    string getBirthday();
    string getPhoneNumber();
    bool operator <(Competitor & c);
};
Competitor::Competitor(string id,string name,string birthday,string class_,string phoneNumber,vector<int>score) {
    this->id=id;
    this->name=name;
    this->birthday=birthday;
    this->class_=class_;
    this->phoneNumber=phoneNumber;
    this->score=score;
    average=0;
    sort(score.begin(),score.end());
    vector<int>::iterator it;
    long count=score.size()-2;
    for(it=(++score.begin()); it!=(--score.end()); it++) {
        average+=*it;
    }
    average/=count;
}
double Competitor::getAverage() {
    return average;
}
bool Competitor::operator <(Competitor & c) {
    return average>c.getAverage();
}
string Competitor::getId() {
    return id;
}
string Competitor::getName() {
    return name;
}
string Competitor::getClass() {
    return class_;
}
string Competitor::getPhoneNumber() {
    return phoneNumber;
}
string Competitor::getBirthday() {
    return birthday;
}
bool greater1(Competitor &c,Competitor &b)
{
    return c.getAverage()<b.getAverage();
}
int main() {
    string id,name,birthday,class_,phoneNumber;
    vector<int>score;
    char buff[1024];
    vector<Competitor>cmr;
    int n;
    ifstream input("input.csv",ios::in);
    ofstream output("output.csv",ios::out);
    if(!input) {
        input.close();
        cout<<"open error!"<<endl;
        return 0;
    }
    if(!output) {
        output.close();
        cout<<"output error!"<<endl;
        return 0;
    }
    while(input.getline(buff,1024)) {
        for(int i=0; i<strlen(buff); i++)
            if(buff[i]==',')
                buff[i]=' ';
        stringstream stream1(buff);
        stream1>>id>>name>>birthday>>class_>>phoneNumber;
        while(stream1>>n) {
            score.push_back(n);
        }
        Competitor c(id,name,birthday,class_,phoneNumber,score);
        cmr.push_back(c);
        score.clear();
    }
    sort(cmr.begin(),cmr.end());
    vector<Competitor>::iterator it;
    for(it=cmr.begin(); it!=cmr.end(); it++) {
        output<<it->getId()<<","<<it->getName()<<","<<it->getBirthday()<<","<<
		      it->getClass()<<","<<it->getPhoneNumber()<<","<<it->getAverage()<<endl;
    }
    input.close();
    output.close();
    cout<<"OK"<<endl;
    return 0;
}
/*
 number ,name ,dateofbirth , class ,phoneNo ,score
 2017110001 ’≈»˝ ƒ– 19990107 2017Õ¯±‡ 13704718001 85 90 92 91 96
 2017110002 ¿ÓÀƒ ƒ– 19990802 2017Õ¯±‡ 13704718007 90 96 93 95 93
 */

