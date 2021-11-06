#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <math.h>
#include <string>
#include <algorithm>
using namespace std;
bool Tnull(bool f)
{
    if (f==0) {
        return 1;
    } else {
        return 0;
    }
}
bool Tone(bool f)
{
    if (f==1) {
        return 1;
    } else {
        return 0;
    }
}
int main()
{
    string Min="(!xy)+(x!z)";
    bool P;
    int K;
    cout<<"Введите кол-во единичных наборов: "<<endl;
    cin>>K;
    string s[K];
    bool f[8]= {0};
    int DIM1 = 3;
    int DIM2 = (pow(2,DIM1));
    int ary[DIM1][DIM2];
    bool x,y,z;
    cout<<"Введите единичные наборы: "<<endl;
    for (int i = 0; i < K; i++) {
        cin>>s[i];
        x=stoi(s[i])/100;
        y=stoi(s[i])/10%10;
        z=stoi(s[i])%10;
        for (int j = 0; j < DIM2; j++) {

            for (int i = 0; i < DIM1; i++) {


                if (j<((DIM2)/2)) {
                    ary[0][j]=0;
                } else {
                    ary[0][j]=1;
                }
                if ((j==2)||(j==3)||(j==6)||(j==7)) {
                    ary[1][j]=1;
                } else {
                    ary[1][j]=0;
                }
                if ((j%2)==1) {
                    ary[2][j]=1;
                } else {
                    ary[2][j]=0;
                };
                if ((ary[0][j]==x) && (ary[1][j]==y) && (ary[2][j]==z)) {
                    f[j]=1;
                }
            }
        }
    }
    cout<<setw(3)<<"x"<<setw(3)<<"y"<<setw(3)<<"z"<<setw(3)<<"f"<<endl;
    for (int j = 0; j < DIM2; j++) {
        for (int i = 0; i < DIM1; i++) {
            if (j<((DIM2)/2)) {
                ary[0][j]=0;
            } else {
                ary[0][j]=1;
            }
            if ((j==2)||(j==3)||(j==6)||(j==7)) {
                ary[1][j]=1;
            } else {
                ary[1][j]=0;
            }
            if ((j%2)==1) {
                ary[2][j]=1;
            } else {
                ary[2][j]=0;
            }
            cout << setw(3) << ary[i][j];

        }
        cout << setw(3) << f[j];
        cout << endl;
    }

    bool nullT=Tnull(f[0]);
    bool oneT=Tone(f[7]);
    int DIM3=DIM1+1;
    int ary1[DIM3][DIM2];
    bool samka=1;
    for (int j = 0; j < DIM2; j++) {
        if (!f[j]!=f[DIM2-1-j]) {
            samka=0;
        }
        for (int i = 0; i < DIM3; i++) {

            if (i==DIM1) {
                ary1[i][j]=f[j];
            } else {
                ary1[i][j]=ary[i][j];
            }
        }
    }

    cout<<"Полином Жегалкина функции: "<<endl;
    string G="(";
    bool zna[8],znach[8],znach1[8];
    int d=8;
    for (int i=0; i<d; i++) {
        {
            if (i<(d/2)) {
                x=0;
            } else {
                x=1;
            }
            if ((i==2)||(i==3)||(i==6)||(i==7)) {
                y=1;
            } else {
                y=0;
            }
            if ((i%2)==1) {
                z=1;
            } else {
                z=0;
            }

        }
        znach[i]=f[i];
        cout<<znach[i];
    }
    cout<<endl;
    zna[7]=znach[0];
    int k=7;
    while (k>0) {
        for(int i=0; i<k; i++) {
            znach1[i]=znach[i]^znach[i+1];
            cout<<znach1[i];
            zna[k-1]=znach1[0];
        }
        cout<<endl;
        for(int i=0; i<k; i++) {
            znach[i]=znach1[i];
        }
        k--;
    }
    reverse(zna,zna+8);
    bool LinT=1;
    for(int i=0; i<8; i++) {
        if (zna[i]==1) {
            switch (i) {
            case 0:
                G=G+"1)+(";
                break;
            case 1:
                G=G+"z"+")+(";
                break;
            case 2:
                G=G+"y"+")+(";
                break;
            case 3:
                G=G+"yz"+")+(";
                LinT=0;
                break;
            case 4:
                G=G+"x"+")+(";
                break;
            case 5:
                G=G+"xz"+")+(";
                LinT=0;
                break;
            case 6:
                G=G+"xy"+")+(";
                LinT=0;
                break;
            case 7:
                G=G+"xyz"+")+(";
                LinT=0;
                break;
            }
        }
    }
    G=G.substr (0,G.length()-2);
    cout<<G<<endl;
    bool Mono=1;
    for (int i = 0; i < (DIM2-1); i++) {
        if (f[i+1]<f[i]) {
            Mono=0;
            break;
        }
    }
    cout<<"min ДНФ: "<<Min<<endl;
    cout<<setw(8)<<"T0"<<setw(8)<<"T1"<<setw(8)<<"S"<<setw(8)<<"M"<<setw(8)<<"L"<<endl;
    cout<<setw(8)<<nullT<<setw(8)<<oneT<<setw(8)<<samka<<setw(8)<<Mono<<setw(8)<<LinT<<endl;
    if ((nullT==0)&&(oneT==0)&&(samka==0)&&(Mono==0)&&(LinT==0)) {
        P=1;
        cout<<"Функция полная"<<endl;
    } else {
        P=0;
        cout<<"Функция не полная"<<endl;
    }
    return 0;
}
