#include <iostream>
#include <math.h>
using namespace std;
int Result_Mission_1 (int HP,int M){
	if (M<0) M=0;if (M>1000) M=1000;
	if (HP<0) HP=0; if (HP>1000) HP=1000;
	return M+HP;
}
bool isPrimeNumber(int n) {
	bool Pr=true;
	for (int i=2;i<n ;i++) {

	if ((n%i)==0) {Pr=false;break;} 
	}
	return Pr;
}

//Mission_1 (100-->500)
int getReady(int& HP, const int& ID, int& M, const int& E1){

//TH_1 (100-->199)
if (E1>=100 && E1<=199) {
    int h=0;int J=0;
    if (ID==0) {
		h=(E1-100)%64; 
		J=HP%100;
		if (J>h) {
			if ((M%2)==0 && M>=200) {
				M=M-200;HP=HP+25;
			} else if (HP>=500 && M>=300) {
				M=M-300; HP=HP+50;
			}
		}	
	}
	if (ID==1)  {HP=HP+75;}	
    return Result_Mission_1(HP,M) ;
}
// TH_2
else if (E1>=200 && E1<=299) {
	int MGx;
	MGx=(E1%4)+1;
	switch (MGx){
		case 1 : //190
			if (ID==0)
				if ((M%2)!=0 && M>=190) {M=M-190;HP=HP+5;}
			else {M=M-190;HP=HP+5;};
			break;
		case 2 ://195
			if (ID==0)
				if ((M%2)==0 && M>=195) {M=M-195;HP=HP+7;}
			else {M=M-195;HP=HP+7;}
			break;
		case 3 ://200
			if (ID==0)
				if ((M%2)!=0 && M>=200) {M=M-200;HP=HP+9;}
			else {M=M-200;HP=HP+9;}
			break;
		case 4 ://205
			if (ID==0)
				if ((M%2)==0 && M>=205) {M=M-205;HP=HP+11;}
			else {M=M-205;HP=HP+11;}
			break;
	}
    return Result_Mission_1(HP,M) ;
}
// TH_3
else if (E1>=300 && E1<=399) {
	int last;
	last=E1%100;last=last%10;
	int a; a=last*2;
	//Thuong
	if (isPrimeNumber(last)==true && HP>=600 && M>=500) {
		if (ID==1) {HP=HP+200;M=M-500;}
		else {HP=HP+(HP*a *2)/100;M=M-500;}
	} 
	//Dao
	if (isPrimeNumber(last)==false && HP>=600 && M>=300) {
		HP=HP+(HP*a)/100;M=M-300;
	} 
	return Result_Mission_1(HP,M) ;
}
// TH_4
else if (E1>=400 && E1<=499) {
	if ((E1%5)==0) HP=(HP*90)/100;
	return Result_Mission_1(HP,M) ;
}
// TH_5
else if (E1==500) {
	HP=HP/4;
	M=M/4;
	return Result_Mission_1(HP,M) ;
}
else return -999;
}
// Misstion_2 (100-->499)

int firstBattle(int& HP1, int& HP2, const int& ID1, const int& ID2, const int& E2){
	int win=0;
	//TH_1
	if (E2>=100 && E2<=199) {
		HP1=11*HP1/10; HP2=HP2*13/10;
	}
	//TH_2
	else if (E2>=200 && E2<=299) {
		HP1=17*HP1/10; HP2=HP2*12/10;
	}
	//TH3
	else if (E2>=300 && E2<=399){
		if (E2<350) HP1=HP1+30;
		else HP1=HP1+(E2%100);
	}
	//TH4
	else if (E2>=400 && E2<=499){
		HP1=(HP1*130/100)*50/100;
		HP2=HP2*80/100;
	}
	int HP_1=HP1; 
	//Ko vua & tuong
	if(E2<100 || E2>=500) return -999;
	else if (ID1==0 && ID2==0) {
		int m; m=(2*HP1*HP2)/(HP1+HP2)+1; //Chưa làm tròn
  		HP1=HP1-abs(HP2-m);
   		HP2=HP2-abs(HP_1-m);
		if (HP1<0) HP1=0;
		if (HP2<0) HP2=0;
   		if (HP1>HP2) win= 1;
		else if (HP1==HP2) win= 0;
		else if (HP1<HP2) win= -1;
	HP1=(HP1*80)/100; // TH_5
	}
	//Co vua ko tuong
	else if (ID1==1 && ID2==0) {
		HP2=0;
		HP1=(HP1*80)/100;
		win=1;
	}
	//Ko vua co tuong
	else if (ID1==0 && ID2==2){
		HP1=0;
		win= -1;
	}
	else if(ID1==1 && ID2==2) {HP1=(HP1*80)/100;win= 0;}
	return win;100

}
//Mission_3 (100-->499)
int secondBattle(int& HP1, int& HP2, const int& ID1, const int& ID2, const int& E3){
   	HP1=1.4*HP1;
	HP2=1.6*HP2;
	int win=0;
   	if(ID1==1) HP1=HP1*2;

   	//TH1
   	if(E3>=100 && E3<=199) {
 		if (ID2==0) HP2=(HP2*95)/100;
   	}
	
	int HP_1=HP1; 
	if(E3<100 || E3>=500) return win=-999;
	else if (E3>=200 && E3<=299){           //TH2
		if (ID2==0) HP2=(HP2*95)/100;
		win=0;
	}
	else if (ID1==0 && ID2==0) {
		int m; m=(2*HP1*HP2)/(HP1+HP2)+1; //Chưa làm tròn
		HP1=HP1-abs(HP2-m);
		HP2=HP2-abs(HP1-m);
		if (HP1<0) HP1=0;
		if (HP2<0) HP2=0;
		if (HP1>HP2) win=1;
		else if (HP1==HP2) win=0;
		else if (HP1<HP2  ) {
	    if (E3>=100 && E3<=199) HP1=HP_1;
		win=-1;
		}
	}
	else if (ID1==1 && ID2==0) {HP2=0;win=1;}
	else if (ID1==0 && ID2==2) {
		if (E3>=100 && E3<=199) HP1=HP_1; else HP1=0;
		win=-1;
	}
	else if (ID1==1 && ID2==2) {win=0;}
	return win;
  
}
int main(){
	int HP=1000; int M=400;int E=450;int ID=1;
	int HP1;int HP2;int E3;int ID1;int ID2;
	cout<<"HP1=";cin>>HP1;
	cout<<"HP2=";cin>>HP2;
	cout<<"E3=";cin>>E3;
	cout<<"ID1=";cin>>ID1;
	cout<<"ID2=";cin>>ID2;
	cout<<secondBattle(HP1,HP2,ID1,ID2,E3)<<"\n"<<"HP1="<<HP1<<"\n"<<"HP2="<<HP2<<"\n";
    return 0;
	
}


