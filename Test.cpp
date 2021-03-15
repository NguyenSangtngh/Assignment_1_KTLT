#include <iostream>
#include <cmath>
using namespace std;
bool isPrimeNumber(int n) {
	bool Pr=true;
	for (int i=2;i<n ;i++) {

	if ((n%i)==0) {Pr=false;break;} 
	}
	return Pr;
}
//Mission_1 (100-->500)  
int getReady(int& HP, const int& ID, int& M, const int& E1){
if (E1<100 || E1>500) return -999;
//TH_1 (100-->199)
else if (E1>=100 && E1<=199) {
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
}
// TH_2
else if (E1>=200 && E1<=299) {
	int MGx;
	MGx=(E1%4)+1;
	switch (MGx){
		case 1 : //190
			if (ID==0) {if ((M%2)!=0 && M>=190) {M=M-190;HP=HP+5;}}
			else if(M>190){M=M-190;HP=HP+5;};
			break;
		case 2 ://195
			if (ID==0) {if ((M%2)==0 && M>=195) {M=M-195;HP=HP+7;}}
			else if(M>195) {M=M-195;HP=HP+7;}
			break;
		case 3 ://200
			if (ID==0) {if ((M%2)!=0 && M>=200) {M=M-200;HP=HP+9;}}
			else if(M>200){M=M-200;HP=HP+9;}
			break;
		case 4 ://205
			if (ID==0) {if ((M%2)==0 && M>=205) {M=M-205;HP=HP+11;}}
			else if (M>205){M=M-205;HP=HP+11;}
			break;
	}
}
// TH_3
else if (E1>=300 && E1<=399) {
	int last_E1;
	last_E1=E1%100;last_E1=last_E1%10;
	int last_HP;
	last_HP=HP%100;last_HP=last_HP%10;
	int a;
	if (isPrimeNumber(last_E1)==true) a=2*last_E1; else a=1;
	//Thuong
	if (isPrimeNumber(last_HP)==true && HP>=600 && ID==1 && M>500){
		HP=HP+200;
		M=M-500;
	}
	else if (isPrimeNumber(last_HP)==true && HP>=600 && M>=500) {
		float f0;
		f0= HP*(1+a*2.0/100.0)*1.0;
		HP=round(f0);    //lam_tron
		M=M-500;
	} 
	
	//Dao
	if (isPrimeNumber(last_HP)==false && HP>=600 && M>=300) {
		float f1;
		f1=HP*(1+a*1.0/100.0)*1.0;
		HP=round(f1);
		M=M-300; //lam tron
	} 

}
// TH_4
else if (E1>=400 && E1<=499) {
	if ((E1%5)==0) {
		float f2;
		f2=HP*0.9; 
		HP=round(f2);}//lam tron
}
// TH_5
else if (E1==500) {
	float f3;
	f3=(HP*3.0)/4.0;  
	HP=round(f3);  //lamtron
	f3=(M*3.0)/4.0;
	M=round(f3);
}
if (M<0) M=0;if (M>1000) M=1000;
if (HP<0) HP=0; if (HP>1000) HP=1000;
return M+HP;
}
// Misstion_2 (100-->499)  4.3

int firstBattle(int& HP1, int& HP2, const int& ID1, const int& ID2, const int& E2){
	//TH_1
	float f4;int win=0;
	if (E2>=100 && E2<=199) {
		f4=HP1*1.1; HP1=round(f4);
		f4=HP2*1.3; HP2=round(f4);//Chưa làm tròn
	}
	//TH_2
	else if (E2>=200 && E2<=299) {
		f4=HP1*1.7; HP1=round(f4);
		f4=HP2*1.2; HP2=round(f4);//Chưa làm tròn
	}
	//TH3
	else if (E2>=300 && E2<=399){
		if (E2<350) HP1=HP1+30;
		else HP1=HP1+(E2%100);        
	}
	//TH4
	else if (E2>=400 && E2<=499){
		f4=HP1*1.3;  HP1=round(f4);
		if (HP1>1000) HP1=1000;       //CheckHP
		f4=HP1*0.5;HP1=round(f4);//Chưa làm tròn
		f4=HP2*0.8;   HP2=round(f4);
	}
	if (HP1>1000) HP1=1000; if (HP2>1000) HP2=1000; //checkHP
	//Ko vua & tuong
	if(E2<100 || E2>=500)  win=-999;
	else if (ID1==0 && ID2==0) {
		int m; int HP_1=HP1; 
		f4=(2.0*HP1*HP2)/(HP1+HP2)*1.0;
		m=round(f4); //Chưa làm tròn
  		HP1=HP1-abs(HP2-m);
   		HP2=HP2-abs(HP_1-m);
		if (HP1<0) HP1=0;     //Check HP
		if (HP2<0) HP2=0;
   		if (HP1>HP2) win= 1;
		else if (HP1==HP2) win= 0;
		else if (HP1<HP2) win= -1;
	f4=HP1*0.8; HP1=round(f4);// TH_5    Chưa làm tròn
	}
	//Co vua ko tuong
	else if (ID1==1 && ID2==0) {
		HP2=0;
		f4=HP1*0.8; 
		HP1=round(f4);   // Chưa làm tròn
		win=1;
	}
	//Ko vua co tuong
	else if (ID1==0 && ID2==2){
		HP1=0;
		win= -1;
	}
	else if(ID1==1 && ID2==2) {f4=HP1*0.8;HP1=round(f4);win=0;}    //Chưa làm tròn
	return win;
}
//Mission_3 (100-->499)
int secondBattle(int& HP1, int& HP2, const int& ID1, const int& ID2, const int& E3){
   	int win=0;float f5;
    if(E3<100 || E3>=300)  win=-999;
	else {
		f5=1.4*HP1;
		HP1=round(f5);  //Chua lam tron
		f5=1.6*HP2;
		 HP2=round(f5);  //Chua lam tron
		 if (HP1>1000) HP1=1000; if (HP2>1000) HP2=1000;  //CheckHP
   		if(ID1==1) HP1=HP1*2; if (HP1>1000) HP1=1000;
		 //TH1
		if (E3>=100 && E3<=199){          
			if (ID1==0 && ID2==0) {
				f5=HP2*0.95;
				HP2=round(f5);  //Chưa làm tròn
				int m; int HP_1=HP1; 
				f5=(2.0*HP1*HP2)/(HP1+HP2)*1.0;
				m=round(f5); //Chưa làm tròn
				HP1=HP1-abs(HP2-m);
				HP2=HP2-abs(HP_1-m);
				if (HP1<0) HP1=0; //CheckHP
				if (HP2<0) HP2=0;
				if (HP1>HP2) win=1;
				else if (HP1==HP2) win=0;  
				else { win=-1; HP1=HP_1;}
			}
			else if (ID1==1 && ID2==0) {
				HP2=0; win =1;
			}
			else if (ID1==0 && ID2==2) {
				HP1=0; win=-1;
			}
			else if (ID1==1 && ID2==2) win=0;
		}
		//TH2
		if (E3>=200 && E3<=299){
			if (ID2==0) {f5=HP2*0.95;HP2=round(f5);} //Chua Lam Tron
			win=0;
		}
	}
   	
   return win;
	
}
//Mission_4
int finalBattle(int& HP1, int& HP2, const int& ID1, const int& ID2, const int& E4){
	int win=0;float f6;
   //TH_1
   if(E4>=100 && E4<=199){
	   if (ID2==2) HP2=(HP2*30)/100; else {f6=HP2*0.1;HP2=round(f6);} //chua lam tron
	   win=0;
   }
   else if(E4>=200 && E4<=299){
	   HP2=0;
	   win=1;
   }
   else win=-999;
   return  win;
}

int main(){
	int HP=613;
	int M=401;
	int E1=355;
	int ID=0;
	int HP1=900;
	int HP2=200 ;
	int E2=450;
	int E3=120;
	int E4=100;
	int ID1=0;
	int ID2=0;
	//cout<<getReady(HP,ID,M,E1)<<"\n"<<HP<<"\n"<<M;
	cout<<firstBattle(HP1,HP2,ID1,ID2,E2)<<"\n"<<HP1<<"\n"<<HP2;
   // cout<<secondBattle(HP1,HP2,ID1,ID2,E3)<<"\n"<<HP1<<"\n"<<HP2;
	//cout<<finalBattle(HP1,HP2,ID1,ID2,E4)<<"\n"<<HP1<<"\n"<<HP2;
    return 0;
	
}


