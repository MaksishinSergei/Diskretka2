#include <stdio.h>
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
using namespace std;
bool ai(bool a, bool b)
{
    return (!(!a || b));
}//антиимпликация
bool i(bool a, bool b)
{
    return (!a || b);
}//импликация
bool eq(bool a, bool b)
{
    return (!(a^b));
}//эквивалентность
bool f2(bool x,bool y)
{
    bool l=!(!x&&!y);//вводимаая функция
    return l;
}
bool f1(bool x,bool y)
{
    bool l=eq(x,y);//вводимаая функция
    return l;
}
bool polzhev1(bool & samka1)
{
    bool Lin=1;
    cout<<endl;
    cout<<"Полином Жегалкина 1 функции: "<<endl;
    cout<<endl;
    string G="(";
    bool zna[4],znach[4],znach1[4];
    bool x,y;
    int d=4;
    for (int i=0; i<d; i++) {
        {
            if (i<(d/2)) {
                x=0;
            } else {
                x=1;
            }
            if ((i%2)==1) {
                y=1;
            } else {
                y=0;
            }

        }

        znach[i]=f1(x,y);
    }
    for(int i=0; i<d/2; i++) {
        if ((!znach[i])!=znach[3-i]) {

            samka1=0;
        }
    }
    zna[3]=znach[0];
    int k=3;
    while (k>0) {
        for(int i=0; i<k; i++) {
            znach1[i]=znach[i]^znach[i+1];
            zna[k-1]=znach1[0];
        }
        for(int i=0; i<k; i++) {
            znach[i]=znach1[i];
        }
        k--;
    }
    reverse(zna,zna+4);
    for(int i=0; i<4; i++) {
        if (zna[i]==1) {
            switch (i) {
            case 0:
                G=G+"1)+(";
                break;
            case 1:
                G=G+"y"+")+(";
                break;
            case 2:
                G=G+"x"+")+(";
                break;
            case 3:
                G=G+"xy"+")+(";
                Lin=0;
                break;
            }
        }
    }
    G=G.substr (0,G.length()-2);
    cout<<G<<endl;
    return Lin;
}
bool polzhev2(bool & samka2)
{
    bool Lin=1;
    cout<<endl;
    cout<<"Полином Жегалкина 2 функции: "<<endl;
    cout<<endl;
    string G="(";
    bool zna[4],znach[4],znach1[4];
    bool x,y;
    int d=4;
    for (int i=0; i<d; i++) {
        {
            if (i<(d/2)) {
                x=0;
            } else {
                x=1;
            }
            if ((i%2)==1) {
                y=1;
            } else {
                y=0;
            }
        }
        znach[i]=f2(x,y);
    }
    for(int i=0; i<d/2; i++) {
        if ((!znach[i])!=znach[3-i]) {
            samka2=0;
        }
    }
    zna[3]=znach[0];
    int k=3;
    while (k>0) {
        for(int i=0; i<k; i++) {
            znach1[i]=znach[i]^znach[i+1];
            zna[k-1]=znach1[0];
        }
        for(int i=0; i<k; i++) {
            znach[i]=znach1[i];
        }
        k--;
    }
    reverse(zna,zna+4);
    for(int i=0; i<4; i++) {
        if (zna[i]==1) {
            switch (i) {
            case 0:
                G=G+"1)+(";
                break;
            case 1:
                G=G+"y"+")+(";
                break;
            case 2:
                G=G+"x"+")+(";
                break;
            case 3:
                G=G+"xy"+")+(";
                Lin=0;
                break;
            }
        }
    }
    G=G.substr (0,G.length()-2);
    cout<<G<<endl;
    cout<<endl;
    return Lin;
}
bool xyz (bool & M, bool & Mn, bool & T10, bool & T20,bool & T11,bool & T21)
{
    cout<<"Таблица истинности: "<<endl;
    cout<<setw(5)<<"x"<<setw(5)<<"y"<<setw(5)<<"f1"<<setw(5)<<"f2"<<endl;
    bool x,y;
    int d=4;
    bool fon[4]= {0};
    bool ftw[4]= {0};
    for (int i=0; i<d; i++) {
        {
            if (i<(d/2)) {
                x=0;
            } else {
                x=1;
            }
            if ((i%2)==1) {
                y=1;
            } else {
                y=0;
            }
        }
        if (((x==0)&&(y==0))&&(f1(x,y)==0)) {
            T10=1;
        }
        if (((x==0)&&(y==0))&&(f2(x,y)==0)) {
            T20=1;
        }
        if (((x==1)&&(y==1))&&(f1(x,y)==1)) {
            T11=1;
        }
        if (((x==1)&&(y==1))&&(f2(x,y)==1)) {
            T21=1;
        }
        fon[i]=f1(x,y);
        ftw[i]=f2(x,y);
        cout<<setw(5)<<x<<setw(5)<<y<<setw(5)<<f1(x,y)<<setw(5)<<f2(x,y)<<endl;
    }
    for(int i=0; i<3; i++) {
        if (fon[i+1]<fon[i]) {
            M=0;
            break;
        }
    }
    for(int i=0; i<3; i++) {
        if (ftw[i+1]<ftw[i]) {
            Mn=0;
            break;
        }
    }
}


int main()
{
    bool B;
    bool P;
    bool T10=0,T20=0,T11=0,T21=0;
    bool M1=1;
    bool M2=1;
    bool s1=1;
    bool s2=1;
    xyz(M1,M2,T10,T20,T11,T21);
    bool Lin1=polzhev1(s1);
    bool Lin2=polzhev2(s2);
    cout<<setw(3)<<"T0"<<setw(3)<<"T1"<<setw(3)<<"L"<<setw(3)<<"M"<<setw(3)<<"S"<<setw(3)<<endl;
    cout<<T10<<setw(3)<<T11<<setw(3)<<Lin1<<setw(3)<<M1<<setw(3)<<s1<<setw(3)<<endl;
    cout<<T20<<setw(3)<<T21<<setw(3)<<Lin2<<setw(3)<<M2<<setw(3)<<s2<<setw(3)<<endl;
    cout<<endl;
    if (((Lin1==1)&&(Lin2==1))||((M1==1)&&(M2==1))||((s1==1)&&(s2==1))||((T10==1)&&(T20==1))||((T11==1)&&(T21==1))) {
        P=0;
        cout<<"Система неполная"<<endl;
    } else {
        P=1;
        cout<<"Система полная"<<endl;
    }
    if ((P==1)&&((Lin1==1)||(M1==1)||(s1==1)||(T10==1)||(T11)==1)&&((Lin2==1)||(M2==1)||(s2==1)||(T20==1)||(T21)==1)){
        B=1;
        cout<<"Система является базисом"<<endl;
    } else {
        B=0;
        cout<<"Система не является базисом"<<endl;
    }
    return 0;
}
// & & — логическое «И» или логическое умножение (конъюнкция). Оператор И возвращает истину, если верны оба утверждения.
// || — логическое «ИЛИ» или логическое сложение (дизъюнкция). Оператор ИЛИ возвращает истину, если верно хотя бы одно утверждение.
// ! — логическое отрицание. Возвращает истину, если утверждение ложно.
// ^ + по модулю 2
// !(&&) - антиконьюнкция
// ! (||) -антидизъюнкция
