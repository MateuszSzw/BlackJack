//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <iostream>
#include <stdlib.h>
#include "Unit1.h"
#include <windows.h>

// Kod do Black Jack Mateusz Szwagrzyk Justyna �l�sarz Robert Szott-Ludwikowski




using namespace std;


//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

class Krupier;
class Sterownik;
class GUI_Login;
class Konserwator;
class Talia;
class Gracz;





class Krupier{
	public:
	friend class Sterownik;

	int karty[52];
        int wynik;


        void dobierz();

};



class Sterownik{
	public:
	friend class Talia;
	friend class Konserwator;
	friend class Krupier;
	friend class Gracz;
	friend class Bank;
        friend class GUI_Login;


        bool awaria;
	void ev_DobierzKarte();
	void ev_PrzestanDobierac();
        void ev_Login();
        void ev_Logout();
        void ev_GraczObstaw();
        void SprawdzWygrana();
        void GraKrupiera();
        void ev_Naprawa();

};

class GUI_Login{

      protected:
      int kwota_gracza;

  public:
  friend class Sterownik;
  string nazwa_gracza;

  void login();

  void logout();

};

class Konserwator{
	public:
	friend class Sterownik;
	void NaprawaAwarii();

};
class Taila{
	public:
	friend class Sterownik;
	int karty[52];

};



struct karta
{
        int lp;
        int wartosc;
        char nazwa;
};

class Gracz{
      public:
      int waluta;
	public:
	friend class Sterownik;

	int karty[52];
        int wynik;
	void login();


	void opusc_gre();


	void dobierz_karte();


	void przestan_dobierac();


	void obstaw(int kwota);



};

//----------------------------- GRA KRUPIERA --------------------------------

     void graKrupiera(TObject *Sender);

        Gracz g1;
	Sterownik S1;

	Krupier k1;
        GUI_Login Gui;
        
        
        
//----------------------------FUNKCJE GRACZA ---------------------------


void Gracz::dobierz_karte(){
  S1.ev_DobierzKarte();
}

void Gracz::przestan_dobierac(){
    S1.ev_PrzestanDobierac();
}


void Gracz::opusc_gre(){
          S1.ev_Logout();
}

void Gracz::login(){
	Form1->Button1->Visible=false;
     Form1->Button21->Visible=true;
     Form1->Button2->Visible=true;
     //Form1->Button3->Visible=true;
     Form1->Button4->Visible=true;
     Form1->Label8->Caption=IntToStr(g1.waluta);
     srand(time(NULL));
     g1.wynik=0;
     g1.karty[2]=0;
     g1.karty[3]=0;
     g1.karty[4]=0;
     g1.karty[0]=rand()%51+1;
     g1.karty[1]+=rand()%51+1;
     do{
     if(g1.karty[1]>52)g1.karty[1]+=rand()%51+1;
     else
     g1.karty[1]+=1;}while(g1.karty[1] == g1.karty[0]);


switch(g1.karty[0])
{
        case 1: {Form1->Image4->Picture->LoadFromFile("img/2_1.jpg" ); g1.wynik+=2;} break;
        case 2: {Form1->Image4->Picture->LoadFromFile("img/2_2.jpg" ); g1.wynik+=2;} break;
        case 3: {Form1->Image4->Picture->LoadFromFile("img/2_3.jpg" ); g1.wynik+=2;} break;
        case 4: {Form1->Image4->Picture->LoadFromFile("img/2_4.jpg" ); g1.wynik+=2;} break;
        case 5: {Form1->Image4->Picture->LoadFromFile("img/3_1.jpg" ); g1.wynik+=3;} break;
        case 6: {Form1->Image4->Picture->LoadFromFile("img/3_2.jpg" ); g1.wynik+=3;} break;
        case 7: {Form1->Image4->Picture->LoadFromFile("img/3_3.jpg" ); g1.wynik+=3;} break;
        case 8: {Form1->Image4->Picture->LoadFromFile("img/3_4.jpg" ); g1.wynik+=3;} break;
        case 9: {Form1->Image4->Picture->LoadFromFile("img/4_1.jpg" ); g1.wynik+=4;} break;
        case 10: {Form1->Image4->Picture->LoadFromFile("img/4_2.jpg" ); g1.wynik+=4;} break;
        case 11: {Form1->Image4->Picture->LoadFromFile("img/4_3.jpg" ); g1.wynik+=4;} break;
        case 12: {Form1->Image4->Picture->LoadFromFile("img/4_4.jpg" ); g1.wynik+=4;} break;
        case 13: {Form1->Image4->Picture->LoadFromFile("img/5_1.jpg" ); g1.wynik+=5;} break;
        case 14: {Form1->Image4->Picture->LoadFromFile("img/5_2.jpg" ); g1.wynik+=5;} break;
        case 15: {Form1->Image4->Picture->LoadFromFile("img/5_3.jpg" ); g1.wynik+=5;} break;
        case 16: {Form1->Image4->Picture->LoadFromFile("img/5_4.jpg" ); g1.wynik+=5;} break;
        case 17: {Form1->Image4->Picture->LoadFromFile("img/6_1.jpg" ); g1.wynik+=6;} break;
        case 18: {Form1->Image4->Picture->LoadFromFile("img/6_2.jpg" ); g1.wynik+=6;} break;
        case 19: {Form1->Image4->Picture->LoadFromFile("img/6_3.jpg" ); g1.wynik+=6;} break;
        case 20: {Form1->Image4->Picture->LoadFromFile("img/6_4.jpg" ); g1.wynik+=6;} break;
        case 21: {Form1->Image4->Picture->LoadFromFile("img/7_3.jpg" ); g1.wynik+=7;} break;
        case 22: {Form1->Image4->Picture->LoadFromFile("img/7_4.jpg" ); g1.wynik+=7;} break;
        case 23: {Form1->Image4->Picture->LoadFromFile("img/7_1.jpg" ); g1.wynik+=7;} break;
        case 24: {Form1->Image4->Picture->LoadFromFile("img/7_2.jpg" ); g1.wynik+=7;} break;
        case 25: {Form1->Image4->Picture->LoadFromFile("img/8_3.jpg" ); g1.wynik+=8;} break;
        case 26: {Form1->Image4->Picture->LoadFromFile("img/8_4.jpg" ); g1.wynik+=8;} break;
        case 27: {Form1->Image4->Picture->LoadFromFile("img/8_1.jpg" ); g1.wynik+=8;} break;
        case 28: {Form1->Image4->Picture->LoadFromFile("img/8_2.jpg" ); g1.wynik+=8;} break;
        case 29: {Form1->Image4->Picture->LoadFromFile("img/9_1.jpg" ); g1.wynik+=9;} break;
        case 30: {Form1->Image4->Picture->LoadFromFile("img/9_2.jpg" ); g1.wynik+=9;} break;
        case 31: {Form1->Image4->Picture->LoadFromFile("img/9_3.jpg" ); g1.wynik+=9;} break;
        case 32: {Form1->Image4->Picture->LoadFromFile("img/9_4.jpg" ); g1.wynik+=9;} break;
        case 33: {Form1->Image4->Picture->LoadFromFile("img/10_1.jpg" ); g1.wynik+=10;} break;
        case 34: {Form1->Image4->Picture->LoadFromFile("img/10_2.jpg" ); g1.wynik+=10;} break;
        case 35: {Form1->Image4->Picture->LoadFromFile("img/10_3.jpg" ); g1.wynik+=10;} break;
        case 36: {Form1->Image4->Picture->LoadFromFile("img/10_4.jpg" ); g1.wynik+=10;} break;
        case 37: {Form1->Image4->Picture->LoadFromFile("img/J_1.jpg" ); g1.wynik+=10;} break;
        case 38: {Form1->Image4->Picture->LoadFromFile("img/J_2.jpg" ); g1.wynik+=10;} break;
        case 39: {Form1->Image4->Picture->LoadFromFile("img/J_3.jpg" ); g1.wynik+=10;} break;
        case 40: {Form1->Image4->Picture->LoadFromFile("img/J_4.jpg" ); g1.wynik+=10;} break;
        case 41: {Form1->Image4->Picture->LoadFromFile("img/Q_1.jpg" ); g1.wynik+=10;} break;
        case 42: {Form1->Image4->Picture->LoadFromFile("img/Q_2.jpg" ); g1.wynik+=10;} break;
        case 43: {Form1->Image4->Picture->LoadFromFile("img/Q_3.jpg" ); g1.wynik+=10;} break;
        case 44: {Form1->Image4->Picture->LoadFromFile("img/Q_4.jpg" ); g1.wynik+=10;} break;
        case 45: {Form1->Image4->Picture->LoadFromFile("img/K_1.jpg" ); g1.wynik+=10;} break;
        case 46: {Form1->Image4->Picture->LoadFromFile("img/K_2.jpg" ); g1.wynik+=10;} break;
        case 47: {Form1->Image4->Picture->LoadFromFile("img/K_3.jpg" ); g1.wynik+=10;} break;
        case 48: {Form1->Image4->Picture->LoadFromFile("img/K_4.jpg" ); g1.wynik+=10;} break;
        case 49: {Form1->Image4->Picture->LoadFromFile("img/A_1.jpg" ); Form1->Label5->Visible=true; Form1->Button9->Visible=true; Form1->Button10->Visible=true;} break;
        case 50: {Form1->Image4->Picture->LoadFromFile("img/A_2.jpg" ); Form1->Label5->Visible=true; Form1->Button9->Visible=true; Form1->Button10->Visible=true;} break;
        case 51: {Form1->Image4->Picture->LoadFromFile("img/A_3.jpg" ); Form1->Label5->Visible=true; Form1->Button9->Visible=true; Form1->Button10->Visible=true;} break;
        case 52: {Form1->Image4->Picture->LoadFromFile("img/A_4.jpg" ); Form1->Label5->Visible=true; Form1->Button9->Visible=true; Form1->Button10->Visible=true;} break;
        }
switch(g1.karty[1])
{
        case 1: {Form1->Image5->Picture->LoadFromFile("img/2_1.jpg" ); g1.wynik+=2;} break;
        case 2: {Form1->Image5->Picture->LoadFromFile("img/2_2.jpg" ); g1.wynik+=2;} break;
        case 3: {Form1->Image5->Picture->LoadFromFile("img/2_3.jpg" ); g1.wynik+=2;} break;
        case 4: {Form1->Image5->Picture->LoadFromFile("img/2_4.jpg" ); g1.wynik+=2;} break;
        case 5: {Form1->Image5->Picture->LoadFromFile("img/3_1.jpg" ); g1.wynik+=3;} break;
        case 6: {Form1->Image5->Picture->LoadFromFile("img/3_2.jpg" ); g1.wynik+=3;} break;
        case 7: {Form1->Image5->Picture->LoadFromFile("img/3_3.jpg" ); g1.wynik+=3;} break;
        case 8: {Form1->Image5->Picture->LoadFromFile("img/3_4.jpg" ); g1.wynik+=3;} break;
        case 9: {Form1->Image5->Picture->LoadFromFile("img/4_1.jpg" ); g1.wynik+=4;} break;
        case 10: {Form1->Image5->Picture->LoadFromFile("img/4_2.jpg" ); g1.wynik+=4;} break;
        case 11: {Form1->Image5->Picture->LoadFromFile("img/4_3.jpg" ); g1.wynik+=4;} break;
        case 12: {Form1->Image5->Picture->LoadFromFile("img/4_4.jpg" ); g1.wynik+=4;} break;
        case 13: {Form1->Image5->Picture->LoadFromFile("img/5_1.jpg" ); g1.wynik+=5;} break;
        case 14: {Form1->Image5->Picture->LoadFromFile("img/5_2.jpg" ); g1.wynik+=5;} break;
        case 15: {Form1->Image5->Picture->LoadFromFile("img/5_3.jpg" ); g1.wynik+=5;} break;
        case 16: {Form1->Image5->Picture->LoadFromFile("img/5_4.jpg" ); g1.wynik+=5;} break;
        case 17: {Form1->Image5->Picture->LoadFromFile("img/6_1.jpg" ); g1.wynik+=6;} break;
        case 18: {Form1->Image5->Picture->LoadFromFile("img/6_2.jpg" ); g1.wynik+=6;} break;
        case 19: {Form1->Image5->Picture->LoadFromFile("img/6_4.jpg" ); g1.wynik+=6;} break;
        case 20: {Form1->Image5->Picture->LoadFromFile("img/6_3.jpg" ); g1.wynik+=6;} break;
        case 21: {Form1->Image5->Picture->LoadFromFile("img/7_3.jpg" ); g1.wynik+=7;} break;
        case 22: {Form1->Image5->Picture->LoadFromFile("img/7_4.jpg" ); g1.wynik+=7;} break;
        case 23: {Form1->Image5->Picture->LoadFromFile("img/7_1.jpg" ); g1.wynik+=7;} break;
        case 24: {Form1->Image5->Picture->LoadFromFile("img/7_2.jpg" ); g1.wynik+=7;} break;
        case 25: {Form1->Image5->Picture->LoadFromFile("img/8_3.jpg" ); g1.wynik+=8;} break;
        case 26: {Form1->Image5->Picture->LoadFromFile("img/8_4.jpg" ); g1.wynik+=8;} break;
        case 27: {Form1->Image5->Picture->LoadFromFile("img/8_1.jpg" ); g1.wynik+=8;} break;
        case 28: {Form1->Image5->Picture->LoadFromFile("img/8_2.jpg" ); g1.wynik+=8;} break;
        case 29: {Form1->Image5->Picture->LoadFromFile("img/9_1.jpg" ); g1.wynik+=9;} break;
        case 30: {Form1->Image5->Picture->LoadFromFile("img/9_2.jpg" ); g1.wynik+=9;} break;
        case 31: {Form1->Image5->Picture->LoadFromFile("img/9_3.jpg" ); g1.wynik+=9;} break;
        case 32: {Form1->Image5->Picture->LoadFromFile("img/9_4.jpg" ); g1.wynik+=9;} break;
        case 33: {Form1->Image5->Picture->LoadFromFile("img/10_1.jpg" ); g1.wynik+=10;} break;
        case 34: {Form1->Image5->Picture->LoadFromFile("img/10_2.jpg" ); g1.wynik+=10;} break;
        case 35: {Form1->Image5->Picture->LoadFromFile("img/10_3.jpg" ); g1.wynik+=10;} break;
        case 36: {Form1->Image5->Picture->LoadFromFile("img/10_4.jpg" ); g1.wynik+=10;} break;
        case 37: {Form1->Image5->Picture->LoadFromFile("img/J_1.jpg" ); g1.wynik+=10;} break;
        case 38: {Form1->Image5->Picture->LoadFromFile("img/J_2.jpg" ); g1.wynik+=10;} break;
        case 39: {Form1->Image5->Picture->LoadFromFile("img/J_3.jpg" ); g1.wynik+=10;} break;
        case 40: {Form1->Image5->Picture->LoadFromFile("img/J_4.jpg" ); g1.wynik+=10;} break;
        case 41: {Form1->Image5->Picture->LoadFromFile("img/Q_1.jpg" ); g1.wynik+=10;} break;
        case 42: {Form1->Image5->Picture->LoadFromFile("img/Q_2.jpg" ); g1.wynik+=10;} break;
        case 43: {Form1->Image5->Picture->LoadFromFile("img/Q_3.jpg" ); g1.wynik+=10;} break;
        case 44: {Form1->Image5->Picture->LoadFromFile("img/Q_4.jpg" ); g1.wynik+=10;} break;
        case 45: {Form1->Image5->Picture->LoadFromFile("img/K_1.jpg" ); g1.wynik+=10;} break;
        case 46: {Form1->Image5->Picture->LoadFromFile("img/K_2.jpg" ); g1.wynik+=10;} break;
        case 47: {Form1->Image5->Picture->LoadFromFile("img/K_3.jpg" ); g1.wynik+=10;} break;
        case 48: {Form1->Image5->Picture->LoadFromFile("img/K_4.jpg" ); g1.wynik+=10;} break;
        case 49: {Form1->Image5->Picture->LoadFromFile("img/A_1.jpg" ); Form1->Label5->Visible=true; Form1->Button11->Visible=true; Form1->Button12->Visible=true;} break;
        case 50: {Form1->Image5->Picture->LoadFromFile("img/A_2.jpg" ); Form1->Label5->Visible=true; Form1->Button11->Visible=true; Form1->Button12->Visible=true;} break;
        case 51: {Form1->Image5->Picture->LoadFromFile("img/A_3.jpg" ); Form1->Label5->Visible=true; Form1->Button11->Visible=true; Form1->Button12->Visible=true;} break;
        case 52: {Form1->Image5->Picture->LoadFromFile("img/A_4.jpg" ); Form1->Label5->Visible=true; Form1->Button11->Visible=true; Form1->Button12->Visible=true;} break;
        }

Form1->Label4->Caption=IntToStr(g1.wynik);
Form1->Label4->Visible-true;
	
	
	
}

//---------------------------- FUNKCJE GUI_LOGIN ------------------------

void GUI_Login::login(){
     S1.ev_Login();
}


void GUI_Login::logout(){
     S1.ev_Logout();
}

//---------------------------- FUNCKJE STEROWNIKA ------------------------


void Sterownik::ev_Logout(){
                     Form1->Close();
}

void Sterownik::ev_PrzestanDobierac(){
        Form1->Button5->Visible=false;
        Form1->Button6->Visible=false;
        Form1->Button21->Visible=false;
        Form1->Button2->Visible=false;
        Form1->Button4->Visible=false;
        k1.wynik=0;
        k1.karty[0]=rand()%51+1;
        k1.karty[1]=rand()%51+1;
        do{
        if(k1.karty[0]>52)k1.karty[0]=rand()%51+1;
        else
        k1.karty[0]+=1;}while((k1.karty[0] == g1.karty[0])||(k1.karty[0] == g1.karty[1])||(k1.karty[0] == g1.karty[2])||(k1.karty[0] == g1.karty[3])||(k1.karty[0] == g1.karty[4]));
        do{
        if(k1.karty[1]>52)k1.karty[1]=rand()%51+1;
        else
        k1.karty[1]+=1;}while((k1.karty[1] == g1.karty[0])||(k1.karty[1] == g1.karty[1])||(k1.karty[1] == g1.karty[2])||(k1.karty[1] == g1.karty[3])||(k1.karty[1] == k1.karty[0])||(k1.karty[1] == g1.karty[4]));

        switch(k1.karty[0])
{
        case 1: {Form1->Image6->Picture->LoadFromFile("img/2_1.jpg" ); k1.wynik+=2;} break;
        case 2: {Form1->Image6->Picture->LoadFromFile("img/2_2.jpg" ); k1.wynik+=2;} break;
        case 3: {Form1->Image6->Picture->LoadFromFile("img/2_3.jpg" ); k1.wynik+=2;} break;
        case 4: {Form1->Image6->Picture->LoadFromFile("img/2_4.jpg" ); k1.wynik+=2;} break;
        case 5: {Form1->Image6->Picture->LoadFromFile("img/3_1.jpg" ); k1.wynik+=3;} break;
        case 6: {Form1->Image6->Picture->LoadFromFile("img/3_2.jpg" ); k1.wynik+=3;} break;
        case 7: {Form1->Image6->Picture->LoadFromFile("img/3_3.jpg" ); k1.wynik+=3;} break;
        case 8: {Form1->Image6->Picture->LoadFromFile("img/3_4.jpg" ); k1.wynik+=3;} break;
        case 9: {Form1->Image6->Picture->LoadFromFile("img/4_1.jpg" ); k1.wynik+=4;} break;
        case 10: {Form1->Image6->Picture->LoadFromFile("img/4_2.jpg" ); k1.wynik+=4;} break;
        case 11: {Form1->Image6->Picture->LoadFromFile("img/4_3.jpg" ); k1.wynik+=4;} break;
        case 12: {Form1->Image6->Picture->LoadFromFile("img/4_4.jpg" ); k1.wynik+=4;} break;
        case 13: {Form1->Image6->Picture->LoadFromFile("img/5_1.jpg" ); k1.wynik+=5;} break;
        case 14: {Form1->Image6->Picture->LoadFromFile("img/5_2.jpg" ); k1.wynik+=5;} break;
        case 15: {Form1->Image6->Picture->LoadFromFile("img/5_3.jpg" ); k1.wynik+=5;} break;
        case 16: {Form1->Image6->Picture->LoadFromFile("img/5_4.jpg" ); k1.wynik+=5;} break;
        case 17: {Form1->Image6->Picture->LoadFromFile("img/6_1.jpg" ); k1.wynik+=6;} break;
        case 18: {Form1->Image6->Picture->LoadFromFile("img/6_2.jpg" ); k1.wynik+=6;} break;
        case 19: {Form1->Image6->Picture->LoadFromFile("img/6_3.jpg" ); k1.wynik+=6;} break;
        case 20: {Form1->Image6->Picture->LoadFromFile("img/6_4.jpg" ); k1.wynik+=6;} break;
        case 21: {Form1->Image6->Picture->LoadFromFile("img/7_3.jpg" ); k1.wynik+=7;} break;
        case 22: {Form1->Image6->Picture->LoadFromFile("img/7_4.jpg" ); k1.wynik+=7;} break;
        case 23: {Form1->Image6->Picture->LoadFromFile("img/7_1.jpg" ); k1.wynik+=7;} break;
        case 24: {Form1->Image6->Picture->LoadFromFile("img/7_2.jpg" ); k1.wynik+=7;} break;
        case 25: {Form1->Image6->Picture->LoadFromFile("img/8_3.jpg" ); k1.wynik+=8;} break;
        case 26: {Form1->Image6->Picture->LoadFromFile("img/8_4.jpg" ); k1.wynik+=8;} break;
        case 27: {Form1->Image6->Picture->LoadFromFile("img/8_1.jpg" ); k1.wynik+=8;} break;
        case 28: {Form1->Image6->Picture->LoadFromFile("img/8_2.jpg" ); k1.wynik+=8;} break;
        case 29: {Form1->Image6->Picture->LoadFromFile("img/9_1.jpg" ); k1.wynik+=9;} break;
        case 30: {Form1->Image6->Picture->LoadFromFile("img/9_2.jpg" ); k1.wynik+=9;} break;
        case 31: {Form1->Image6->Picture->LoadFromFile("img/9_3.jpg" ); k1.wynik+=9;} break;
        case 32: {Form1->Image6->Picture->LoadFromFile("img/9_4.jpg" ); k1.wynik+=9;} break;
        case 33: {Form1->Image6->Picture->LoadFromFile("img/10_1.jpg" ); k1.wynik+=10;} break;
        case 34: {Form1->Image6->Picture->LoadFromFile("img/10_2.jpg" ); k1.wynik+=10;} break;
        case 35: {Form1->Image6->Picture->LoadFromFile("img/10_3.jpg" ); k1.wynik+=10;} break;
        case 36: {Form1->Image6->Picture->LoadFromFile("img/10_4.jpg" ); k1.wynik+=10;} break;
        case 37: {Form1->Image6->Picture->LoadFromFile("img/J_1.jpg" ); k1.wynik+=10;} break;
        case 38: {Form1->Image6->Picture->LoadFromFile("img/J_2.jpg" ); k1.wynik+=10;} break;
        case 39: {Form1->Image6->Picture->LoadFromFile("img/J_3.jpg" ); k1.wynik+=10;} break;
        case 40: {Form1->Image6->Picture->LoadFromFile("img/J_4.jpg" ); k1.wynik+=10;} break;
        case 41: {Form1->Image6->Picture->LoadFromFile("img/Q_1.jpg" ); k1.wynik+=10;} break;
        case 42: {Form1->Image6->Picture->LoadFromFile("img/Q_2.jpg" ); k1.wynik+=10;} break;
        case 43: {Form1->Image6->Picture->LoadFromFile("img/Q_3.jpg" ); k1.wynik+=10;} break;
        case 44: {Form1->Image6->Picture->LoadFromFile("img/Q_4.jpg" ); k1.wynik+=10;} break;
        case 45: {Form1->Image6->Picture->LoadFromFile("img/K_1.jpg" ); k1.wynik+=10;} break;
        case 46: {Form1->Image6->Picture->LoadFromFile("img/K_2.jpg" ); k1.wynik+=10;} break;
        case 47: {Form1->Image6->Picture->LoadFromFile("img/K_3.jpg" ); k1.wynik+=10;} break;
        case 48: {Form1->Image6->Picture->LoadFromFile("img/K_4.jpg" ); k1.wynik+=10;} break;
        case 49: {Form1->Image6->Picture->LoadFromFile("img/A_1.jpg" ); k1.wynik+=11;} break;
        case 50: {Form1->Image6->Picture->LoadFromFile("img/A_2.jpg" ); k1.wynik+=11;} break;
        case 51: {Form1->Image6->Picture->LoadFromFile("img/A_3.jpg" ); k1.wynik+=11;} break;
        case 52: {Form1->Image6->Picture->LoadFromFile("img/A_4.jpg" ); k1.wynik+=11;} break;
        }
switch(k1.karty[1])
{
        case 1: {Form1->Image7->Picture->LoadFromFile("img/2_1.jpg" ); k1.wynik+=2;} break;
        case 2: {Form1->Image7->Picture->LoadFromFile("img/2_2.jpg" ); k1.wynik+=2;} break;
        case 3: {Form1->Image7->Picture->LoadFromFile("img/2_3.jpg" ); k1.wynik+=2;} break;
        case 4: {Form1->Image7->Picture->LoadFromFile("img/2_4.jpg" ); k1.wynik+=2;} break;
        case 5: {Form1->Image7->Picture->LoadFromFile("img/3_1.jpg" ); k1.wynik+=3;} break;
        case 6: {Form1->Image7->Picture->LoadFromFile("img/3_2.jpg" ); k1.wynik+=3;} break;
        case 7: {Form1->Image7->Picture->LoadFromFile("img/3_3.jpg" ); k1.wynik+=3;} break;
        case 8: {Form1->Image7->Picture->LoadFromFile("img/3_4.jpg" ); k1.wynik+=3;} break;
        case 9: {Form1->Image7->Picture->LoadFromFile("img/4_1.jpg" ); k1.wynik+=4;} break;
        case 10: {Form1->Image7->Picture->LoadFromFile("img/4_2.jpg" ); k1.wynik+=4;} break;
        case 11: {Form1->Image7->Picture->LoadFromFile("img/4_3.jpg" ); k1.wynik+=4;} break;
        case 12: {Form1->Image7->Picture->LoadFromFile("img/4_4.jpg" ); k1.wynik+=4;} break;
        case 13: {Form1->Image7->Picture->LoadFromFile("img/5_1.jpg" ); k1.wynik+=5;} break;
        case 14: {Form1->Image7->Picture->LoadFromFile("img/5_2.jpg" ); k1.wynik+=5;} break;
        case 15: {Form1->Image7->Picture->LoadFromFile("img/5_3.jpg" ); k1.wynik+=5;} break;
        case 16: {Form1->Image7->Picture->LoadFromFile("img/5_4.jpg" ); k1.wynik+=5;} break;
        case 17: {Form1->Image7->Picture->LoadFromFile("img/6_1.jpg" ); k1.wynik+=6;} break;
        case 18: {Form1->Image7->Picture->LoadFromFile("img/6_2.jpg" ); k1.wynik+=6;} break;
        case 19: {Form1->Image7->Picture->LoadFromFile("img/6_4.jpg" ); k1.wynik+=6;} break;
        case 20: {Form1->Image7->Picture->LoadFromFile("img/6_3.jpg" ); k1.wynik+=6;} break;
        case 21: {Form1->Image7->Picture->LoadFromFile("img/7_3.jpg" ); k1.wynik+=7;} break;
        case 22: {Form1->Image7->Picture->LoadFromFile("img/7_4.jpg" ); k1.wynik+=7;} break;
        case 23: {Form1->Image7->Picture->LoadFromFile("img/7_1.jpg" ); k1.wynik+=7;} break;
        case 24: {Form1->Image7->Picture->LoadFromFile("img/7_2.jpg" ); k1.wynik+=7;} break;
        case 25: {Form1->Image7->Picture->LoadFromFile("img/8_3.jpg" ); k1.wynik+=8;} break;
        case 26: {Form1->Image7->Picture->LoadFromFile("img/8_4.jpg" ); k1.wynik+=8;} break;
        case 27: {Form1->Image7->Picture->LoadFromFile("img/8_1.jpg" ); k1.wynik+=8;} break;
        case 28: {Form1->Image7->Picture->LoadFromFile("img/8_2.jpg" ); k1.wynik+=8;} break;
        case 29: {Form1->Image7->Picture->LoadFromFile("img/9_1.jpg" ); k1.wynik+=9;} break;
        case 30: {Form1->Image7->Picture->LoadFromFile("img/9_2.jpg" ); k1.wynik+=9;} break;
        case 31: {Form1->Image7->Picture->LoadFromFile("img/9_3.jpg" ); k1.wynik+=9;} break;
        case 32: {Form1->Image7->Picture->LoadFromFile("img/9_4.jpg" ); k1.wynik+=9;} break;
        case 33: {Form1->Image7->Picture->LoadFromFile("img/10_1.jpg" ); k1.wynik+=10;} break;
        case 34: {Form1->Image7->Picture->LoadFromFile("img/10_2.jpg" ); k1.wynik+=10;} break;
        case 35: {Form1->Image7->Picture->LoadFromFile("img/10_3.jpg" ); k1.wynik+=10;} break;
        case 36: {Form1->Image7->Picture->LoadFromFile("img/10_4.jpg" ); k1.wynik+=10;} break;
        case 37: {Form1->Image7->Picture->LoadFromFile("img/J_1.jpg" ); k1.wynik+=10;} break;
        case 38: {Form1->Image7->Picture->LoadFromFile("img/J_2.jpg" ); k1.wynik+=10;} break;
        case 39: {Form1->Image7->Picture->LoadFromFile("img/J_3.jpg" ); k1.wynik+=10;} break;
        case 40: {Form1->Image7->Picture->LoadFromFile("img/J_4.jpg" ); k1.wynik+=10;} break;
        case 41: {Form1->Image7->Picture->LoadFromFile("img/Q_1.jpg" ); k1.wynik+=10;} break;
        case 42: {Form1->Image7->Picture->LoadFromFile("img/Q_2.jpg" ); k1.wynik+=10;} break;
        case 43: {Form1->Image7->Picture->LoadFromFile("img/Q_3.jpg" ); k1.wynik+=10;} break;
        case 44: {Form1->Image7->Picture->LoadFromFile("img/Q_4.jpg" ); k1.wynik+=10;} break;
        case 45: {Form1->Image7->Picture->LoadFromFile("img/K_1.jpg" ); k1.wynik+=10;} break;
        case 46: {Form1->Image7->Picture->LoadFromFile("img/K_2.jpg" ); k1.wynik+=10;} break;
        case 47: {Form1->Image7->Picture->LoadFromFile("img/K_3.jpg" ); k1.wynik+=10;} break;
        case 48: {Form1->Image7->Picture->LoadFromFile("img/K_4.jpg" ); k1.wynik+=10;} break;
        case 49: {Form1->Image7->Picture->LoadFromFile("img/A_1.jpg" ); if(k1.wynik+11<21){k1.wynik+=11;}else k1.wynik+=1;} break;
        case 50: {Form1->Image7->Picture->LoadFromFile("img/A_2.jpg" ); if(k1.wynik+11<21){k1.wynik+=11;}else k1.wynik+=1;} break;
        case 51: {Form1->Image7->Picture->LoadFromFile("img/A_3.jpg" ); if(k1.wynik+11<21){k1.wynik+=11;}else k1.wynik+=1;} break;
        case 52: {Form1->Image7->Picture->LoadFromFile("img/A_4.jpg" ); if(k1.wynik+11<21){k1.wynik+=11;}else k1.wynik+=1;} break;
        }
        Form1->Label13->Caption=IntToStr(k1.wynik);
        int i=2;
        int n=0;
        while(k1.wynik<=g1.wynik)
         {      //Sleep(2000);
                k1.karty[i]=rand()%51+1;
                 do
                {
                        n==0;
                        do{
                                if(k1.karty[i]>52)k1.karty[i]=rand()%51+1;
                                else
                                k1.karty[i]+=1;}while((k1.karty[0] == g1.karty[0])||(k1.karty[0] == g1.karty[1])||(k1.karty[0] == g1.karty[2])||(k1.karty[0] == g1.karty[3])||(k1.karty[0] == g1.karty[4]));
                                for(int j=0;j<i;j++)if(k1.karty[i]==k1.karty[j])n++;
                        }while(n!=0&&n<52);
        if(i==2)
        {
        switch(k1.karty[i])
        {
        case 1: {Form1->Image8->Picture->LoadFromFile("img/2_1.jpg" ); k1.wynik+=2;} break;
        case 2: {Form1->Image8->Picture->LoadFromFile("img/2_2.jpg" ); k1.wynik+=2;} break;
        case 3: {Form1->Image8->Picture->LoadFromFile("img/2_3.jpg" ); k1.wynik+=2;} break;
        case 4: {Form1->Image8->Picture->LoadFromFile("img/2_4.jpg" ); k1.wynik+=2;} break;
        case 5: {Form1->Image8->Picture->LoadFromFile("img/3_1.jpg" ); k1.wynik+=3;} break;
        case 6: {Form1->Image8->Picture->LoadFromFile("img/3_2.jpg" ); k1.wynik+=3;} break;
        case 7: {Form1->Image8->Picture->LoadFromFile("img/3_3.jpg" ); k1.wynik+=3;} break;
        case 8: {Form1->Image8->Picture->LoadFromFile("img/3_4.jpg" ); k1.wynik+=3;} break;
        case 9: {Form1->Image8->Picture->LoadFromFile("img/4_1.jpg" ); k1.wynik+=4;} break;
        case 10: {Form1->Image8->Picture->LoadFromFile("img/4_2.jpg" ); k1.wynik+=4;} break;
        case 11: {Form1->Image8->Picture->LoadFromFile("img/4_3.jpg" ); k1.wynik+=4;} break;
        case 12: {Form1->Image8->Picture->LoadFromFile("img/4_4.jpg" ); k1.wynik+=4;} break;
        case 13: {Form1->Image8->Picture->LoadFromFile("img/5_1.jpg" ); k1.wynik+=5;} break;
        case 14: {Form1->Image8->Picture->LoadFromFile("img/5_2.jpg" ); k1.wynik+=5;} break;
        case 15: {Form1->Image8->Picture->LoadFromFile("img/5_3.jpg" ); k1.wynik+=5;} break;
        case 16: {Form1->Image8->Picture->LoadFromFile("img/5_4.jpg" ); k1.wynik+=5;} break;
        case 17: {Form1->Image8->Picture->LoadFromFile("img/6_1.jpg" ); k1.wynik+=6;} break;
        case 18: {Form1->Image8->Picture->LoadFromFile("img/6_2.jpg" ); k1.wynik+=6;} break;
        case 19: {Form1->Image8->Picture->LoadFromFile("img/6_3.jpg" ); k1.wynik+=6;} break;
        case 20: {Form1->Image8->Picture->LoadFromFile("img/6_4.jpg" ); k1.wynik+=6;} break;
        case 21: {Form1->Image8->Picture->LoadFromFile("img/7_3.jpg" ); k1.wynik+=7;} break;
        case 22: {Form1->Image8->Picture->LoadFromFile("img/7_4.jpg" ); k1.wynik+=7;} break;
        case 23: {Form1->Image8->Picture->LoadFromFile("img/7_1.jpg" ); k1.wynik+=7;} break;
        case 24: {Form1->Image8->Picture->LoadFromFile("img/7_2.jpg" ); k1.wynik+=7;} break;
        case 25: {Form1->Image8->Picture->LoadFromFile("img/8_3.jpg" ); k1.wynik+=8;} break;
        case 26: {Form1->Image8->Picture->LoadFromFile("img/8_4.jpg" ); k1.wynik+=8;} break;
        case 27: {Form1->Image8->Picture->LoadFromFile("img/8_1.jpg" ); k1.wynik+=8;} break;
        case 28: {Form1->Image8->Picture->LoadFromFile("img/8_2.jpg" ); k1.wynik+=8;} break;
        case 29: {Form1->Image8->Picture->LoadFromFile("img/9_1.jpg" ); k1.wynik+=9;} break;
        case 30: {Form1->Image8->Picture->LoadFromFile("img/9_2.jpg" ); k1.wynik+=9;} break;
        case 31: {Form1->Image8->Picture->LoadFromFile("img/9_3.jpg" ); k1.wynik+=9;} break;
        case 32: {Form1->Image8->Picture->LoadFromFile("img/9_4.jpg" ); k1.wynik+=9;} break;
        case 33: {Form1->Image8->Picture->LoadFromFile("img/10_1.jpg" ); k1.wynik+=10;} break;
        case 34: {Form1->Image8->Picture->LoadFromFile("img/10_2.jpg" ); k1.wynik+=10;} break;
        case 35: {Form1->Image8->Picture->LoadFromFile("img/10_3.jpg" ); k1.wynik+=10;} break;
        case 36: {Form1->Image8->Picture->LoadFromFile("img/10_4.jpg" ); k1.wynik+=10;} break;
        case 37: {Form1->Image8->Picture->LoadFromFile("img/J_1.jpg" ); k1.wynik+=10;} break;
        case 38: {Form1->Image8->Picture->LoadFromFile("img/J_2.jpg" ); k1.wynik+=10;} break;
        case 39: {Form1->Image8->Picture->LoadFromFile("img/J_3.jpg" ); k1.wynik+=10;} break;
        case 40: {Form1->Image8->Picture->LoadFromFile("img/J_4.jpg" ); k1.wynik+=10;} break;
        case 41: {Form1->Image8->Picture->LoadFromFile("img/Q_1.jpg" ); k1.wynik+=10;} break;
        case 42: {Form1->Image8->Picture->LoadFromFile("img/Q_2.jpg" ); k1.wynik+=10;} break;
        case 43: {Form1->Image8->Picture->LoadFromFile("img/Q_3.jpg" ); k1.wynik+=10;} break;
        case 44: {Form1->Image8->Picture->LoadFromFile("img/Q_4.jpg" ); k1.wynik+=10;} break;
        case 45: {Form1->Image8->Picture->LoadFromFile("img/K_1.jpg" ); k1.wynik+=10;} break;
        case 46: {Form1->Image8->Picture->LoadFromFile("img/K_2.jpg" ); k1.wynik+=10;} break;
        case 47: {Form1->Image8->Picture->LoadFromFile("img/K_3.jpg" ); k1.wynik+=10;} break;
        case 48: {Form1->Image8->Picture->LoadFromFile("img/K_4.jpg" ); k1.wynik+=10;} break;
        case 49: {Form1->Image8->Picture->LoadFromFile("img/A_1.jpg" ); k1.wynik+=11;} break;
        case 50: {Form1->Image8->Picture->LoadFromFile("img/A_2.jpg" ); k1.wynik+=11;} break;
        case 51: {Form1->Image8->Picture->LoadFromFile("img/A_3.jpg" ); k1.wynik+=11;} break;
        case 52: {Form1->Image8->Picture->LoadFromFile("img/A_4.jpg" ); k1.wynik+=11;} break;
        }
        }
        if(i==3)
        {
        switch(k1.karty[i])
        {
        case 1: {Form1->Image9->Picture->LoadFromFile("img/2_1.jpg" ); k1.wynik+=2;} break;
        case 2: {Form1->Image9->Picture->LoadFromFile("img/2_2.jpg" ); k1.wynik+=2;} break;
        case 3: {Form1->Image9->Picture->LoadFromFile("img/2_3.jpg" ); k1.wynik+=2;} break;
        case 4: {Form1->Image9->Picture->LoadFromFile("img/2_4.jpg" ); k1.wynik+=2;} break;
        case 5: {Form1->Image9->Picture->LoadFromFile("img/3_1.jpg" ); k1.wynik+=3;} break;
        case 6: {Form1->Image9->Picture->LoadFromFile("img/3_2.jpg" ); k1.wynik+=3;} break;
        case 7: {Form1->Image9->Picture->LoadFromFile("img/3_3.jpg" ); k1.wynik+=3;} break;
        case 8: {Form1->Image9->Picture->LoadFromFile("img/3_4.jpg" ); k1.wynik+=3;} break;
        case 9: {Form1->Image9->Picture->LoadFromFile("img/4_1.jpg" ); k1.wynik+=4;} break;
        case 10: {Form1->Image9->Picture->LoadFromFile("img/4_2.jpg" ); k1.wynik+=4;} break;
        case 11: {Form1->Image9->Picture->LoadFromFile("img/4_3.jpg" ); k1.wynik+=4;} break;
        case 12: {Form1->Image9->Picture->LoadFromFile("img/4_4.jpg" ); k1.wynik+=4;} break;
        case 13: {Form1->Image9->Picture->LoadFromFile("img/5_1.jpg" ); k1.wynik+=5;} break;
        case 14: {Form1->Image9->Picture->LoadFromFile("img/5_2.jpg" ); k1.wynik+=5;} break;
        case 15: {Form1->Image9->Picture->LoadFromFile("img/5_3.jpg" ); k1.wynik+=5;} break;
        case 16: {Form1->Image9->Picture->LoadFromFile("img/5_4.jpg" ); k1.wynik+=5;} break;
        case 17: {Form1->Image9->Picture->LoadFromFile("img/6_1.jpg" ); k1.wynik+=6;} break;
        case 18: {Form1->Image9->Picture->LoadFromFile("img/6_2.jpg" ); k1.wynik+=6;} break;
        case 19: {Form1->Image9->Picture->LoadFromFile("img/6_3.jpg" ); k1.wynik+=6;} break;
        case 20: {Form1->Image9->Picture->LoadFromFile("img/6_4.jpg" ); k1.wynik+=6;} break;
        case 21: {Form1->Image9->Picture->LoadFromFile("img/7_3.jpg" ); k1.wynik+=7;} break;
        case 22: {Form1->Image9->Picture->LoadFromFile("img/7_4.jpg" ); k1.wynik+=7;} break;
        case 23: {Form1->Image9->Picture->LoadFromFile("img/7_1.jpg" ); k1.wynik+=7;} break;
        case 24: {Form1->Image9->Picture->LoadFromFile("img/7_2.jpg" ); k1.wynik+=7;} break;
        case 25: {Form1->Image9->Picture->LoadFromFile("img/8_3.jpg" ); k1.wynik+=8;} break;
        case 26: {Form1->Image9->Picture->LoadFromFile("img/8_4.jpg" ); k1.wynik+=8;} break;
        case 27: {Form1->Image9->Picture->LoadFromFile("img/8_1.jpg" ); k1.wynik+=8;} break;
        case 28: {Form1->Image9->Picture->LoadFromFile("img/8_2.jpg" ); k1.wynik+=8;} break;
        case 29: {Form1->Image9->Picture->LoadFromFile("img/9_1.jpg" ); k1.wynik+=9;} break;
        case 30: {Form1->Image9->Picture->LoadFromFile("img/9_2.jpg" ); k1.wynik+=9;} break;
        case 31: {Form1->Image9->Picture->LoadFromFile("img/9_3.jpg" ); k1.wynik+=9;} break;
        case 32: {Form1->Image9->Picture->LoadFromFile("img/9_4.jpg" ); k1.wynik+=9;} break;
        case 33: {Form1->Image9->Picture->LoadFromFile("img/10_1.jpg" ); k1.wynik+=10;} break;
        case 34: {Form1->Image9->Picture->LoadFromFile("img/10_2.jpg" ); k1.wynik+=10;} break;
        case 35: {Form1->Image9->Picture->LoadFromFile("img/10_3.jpg" ); k1.wynik+=10;} break;
        case 36: {Form1->Image9->Picture->LoadFromFile("img/10_4.jpg" ); k1.wynik+=10;} break;
        case 37: {Form1->Image9->Picture->LoadFromFile("img/J_1.jpg" ); k1.wynik+=10;} break;
        case 38: {Form1->Image9->Picture->LoadFromFile("img/J_2.jpg" ); k1.wynik+=10;} break;
        case 39: {Form1->Image9->Picture->LoadFromFile("img/J_3.jpg" ); k1.wynik+=10;} break;
        case 40: {Form1->Image9->Picture->LoadFromFile("img/J_4.jpg" ); k1.wynik+=10;} break;
        case 41: {Form1->Image9->Picture->LoadFromFile("img/Q_1.jpg" ); k1.wynik+=10;} break;
        case 42: {Form1->Image9->Picture->LoadFromFile("img/Q_2.jpg" ); k1.wynik+=10;} break;
        case 43: {Form1->Image9->Picture->LoadFromFile("img/Q_3.jpg" ); k1.wynik+=10;} break;
        case 44: {Form1->Image9->Picture->LoadFromFile("img/Q_4.jpg" ); k1.wynik+=10;} break;
        case 45: {Form1->Image9->Picture->LoadFromFile("img/K_1.jpg" ); k1.wynik+=10;} break;
        case 46: {Form1->Image9->Picture->LoadFromFile("img/K_2.jpg" ); k1.wynik+=10;} break;
        case 47: {Form1->Image9->Picture->LoadFromFile("img/K_3.jpg" ); k1.wynik+=10;} break;
        case 48: {Form1->Image9->Picture->LoadFromFile("img/K_4.jpg" ); k1.wynik+=10;} break;
        case 49: {Form1->Image9->Picture->LoadFromFile("img/A_1.jpg" ); k1.wynik+=11;} break;
        case 50: {Form1->Image9->Picture->LoadFromFile("img/A_2.jpg" ); k1.wynik+=11;} break;
        case 51: {Form1->Image9->Picture->LoadFromFile("img/A_3.jpg" ); k1.wynik+=11;} break;
        case 52: {Form1->Image9->Picture->LoadFromFile("img/A_4.jpg" ); k1.wynik+=11;} break;
        }
        }
        if(i==4)
        {
        switch(k1.karty[i])
        {
        case 1: {Form1->Image10->Picture->LoadFromFile("img/2_1.jpg" ); k1.wynik+=2;} break;
        case 2: {Form1->Image10->Picture->LoadFromFile("img/2_2.jpg" ); k1.wynik+=2;} break;
        case 3: {Form1->Image10->Picture->LoadFromFile("img/2_3.jpg" ); k1.wynik+=2;} break;
        case 4: {Form1->Image10->Picture->LoadFromFile("img/2_4.jpg" ); k1.wynik+=2;} break;
        case 5: {Form1->Image10->Picture->LoadFromFile("img/3_1.jpg" ); k1.wynik+=3;} break;
        case 6: {Form1->Image10->Picture->LoadFromFile("img/3_2.jpg" ); k1.wynik+=3;} break;
        case 7: {Form1->Image10->Picture->LoadFromFile("img/3_3.jpg" ); k1.wynik+=3;} break;
        case 8: {Form1->Image10->Picture->LoadFromFile("img/3_4.jpg" ); k1.wynik+=3;} break;
        case 9: {Form1->Image10->Picture->LoadFromFile("img/4_1.jpg" ); k1.wynik+=4;} break;
        case 10: {Form1->Image10->Picture->LoadFromFile("img/4_2.jpg" ); k1.wynik+=4;} break;
        case 11: {Form1->Image10->Picture->LoadFromFile("img/4_3.jpg" ); k1.wynik+=4;} break;
        case 12: {Form1->Image10->Picture->LoadFromFile("img/4_4.jpg" ); k1.wynik+=4;} break;
        case 13: {Form1->Image10->Picture->LoadFromFile("img/5_1.jpg" ); k1.wynik+=5;} break;
        case 14: {Form1->Image10->Picture->LoadFromFile("img/5_2.jpg" ); k1.wynik+=5;} break;
        case 15: {Form1->Image10->Picture->LoadFromFile("img/5_3.jpg" ); k1.wynik+=5;} break;
        case 16: {Form1->Image10->Picture->LoadFromFile("img/5_4.jpg" ); k1.wynik+=5;} break;
        case 17: {Form1->Image10->Picture->LoadFromFile("img/6_1.jpg" ); k1.wynik+=6;} break;
        case 18: {Form1->Image10->Picture->LoadFromFile("img/6_2.jpg" ); k1.wynik+=6;} break;
        case 19: {Form1->Image10->Picture->LoadFromFile("img/6_3.jpg" ); k1.wynik+=6;} break;
        case 20: {Form1->Image10->Picture->LoadFromFile("img/6_4.jpg" ); k1.wynik+=6;} break;
        case 21: {Form1->Image10->Picture->LoadFromFile("img/7_3.jpg" ); k1.wynik+=7;} break;
        case 22: {Form1->Image10->Picture->LoadFromFile("img/7_4.jpg" ); k1.wynik+=7;} break;
        case 23: {Form1->Image10->Picture->LoadFromFile("img/7_1.jpg" ); k1.wynik+=7;} break;
        case 24: {Form1->Image10->Picture->LoadFromFile("img/7_2.jpg" ); k1.wynik+=7;} break;
        case 25: {Form1->Image10->Picture->LoadFromFile("img/8_3.jpg" ); k1.wynik+=8;} break;
        case 26: {Form1->Image10->Picture->LoadFromFile("img/8_4.jpg" ); k1.wynik+=8;} break;
        case 27: {Form1->Image10->Picture->LoadFromFile("img/8_1.jpg" ); k1.wynik+=8;} break;
        case 28: {Form1->Image10->Picture->LoadFromFile("img/8_2.jpg" ); k1.wynik+=8;} break;
        case 29: {Form1->Image10->Picture->LoadFromFile("img/9_1.jpg" ); k1.wynik+=9;} break;
        case 30: {Form1->Image10->Picture->LoadFromFile("img/9_2.jpg" ); k1.wynik+=9;} break;
        case 31: {Form1->Image10->Picture->LoadFromFile("img/9_3.jpg" ); k1.wynik+=9;} break;
        case 32: {Form1->Image10->Picture->LoadFromFile("img/9_4.jpg" ); k1.wynik+=9;} break;
        case 33: {Form1->Image10->Picture->LoadFromFile("img/10_1.jpg" ); k1.wynik+=10;} break;
        case 34: {Form1->Image10->Picture->LoadFromFile("img/10_2.jpg" ); k1.wynik+=10;} break;
        case 35: {Form1->Image10->Picture->LoadFromFile("img/10_3.jpg" ); k1.wynik+=10;} break;
        case 36: {Form1->Image10->Picture->LoadFromFile("img/10_4.jpg" ); k1.wynik+=10;} break;
        case 37: {Form1->Image10->Picture->LoadFromFile("img/J_1.jpg" ); k1.wynik+=10;} break;
        case 38: {Form1->Image10->Picture->LoadFromFile("img/J_2.jpg" ); k1.wynik+=10;} break;
        case 39: {Form1->Image10->Picture->LoadFromFile("img/J_3.jpg" ); k1.wynik+=10;} break;
        case 40: {Form1->Image10->Picture->LoadFromFile("img/J_4.jpg" ); k1.wynik+=10;} break;
        case 41: {Form1->Image10->Picture->LoadFromFile("img/Q_1.jpg" ); k1.wynik+=10;} break;
        case 42: {Form1->Image10->Picture->LoadFromFile("img/Q_2.jpg" ); k1.wynik+=10;} break;
        case 43: {Form1->Image10->Picture->LoadFromFile("img/Q_3.jpg" ); k1.wynik+=10;} break;
        case 44: {Form1->Image10->Picture->LoadFromFile("img/Q_4.jpg" ); k1.wynik+=10;} break;
        case 45: {Form1->Image10->Picture->LoadFromFile("img/K_1.jpg" ); k1.wynik+=10;} break;
        case 46: {Form1->Image10->Picture->LoadFromFile("img/K_2.jpg" ); k1.wynik+=10;} break;
        case 47: {Form1->Image10->Picture->LoadFromFile("img/K_3.jpg" ); k1.wynik+=10;} break;
        case 48: {Form1->Image10->Picture->LoadFromFile("img/K_4.jpg" ); k1.wynik+=10;} break;
        case 49: {Form1->Image10->Picture->LoadFromFile("img/A_1.jpg" ); k1.wynik+=11;} break;
        case 50: {Form1->Image10->Picture->LoadFromFile("img/A_2.jpg" ); k1.wynik+=11;} break;
        case 51: {Form1->Image10->Picture->LoadFromFile("img/A_3.jpg" ); k1.wynik+=11;} break;
        case 52: {Form1->Image10->Picture->LoadFromFile("img/A_4.jpg" ); k1.wynik+=11;} break;
        }
        }
         i++;
         }
         Form1->Label13->Caption=IntToStr(k1.wynik);
         if(k1.wynik>21)
         {
                Form1->Button23->Visible=true;
                g1.waluta+=500;
         }
         else {
                Form1->Button20->Visible=true;
                g1.waluta-=100;
         }
}

void Sterownik::ev_DobierzKarte(){
      
srand(time(NULL));
g1.karty[2]=rand()%51+1;
do{
if(g1.karty[2]>52)g1.karty[2]=rand()%51+1;
else
g1.karty[2]+=1;}while((g1.karty[2] == g1.karty[0])||(g1.karty[2] == g1.karty[1]));
switch(g1.karty[2])
{
        case 1: {Form1->Image1->Picture->LoadFromFile("img/2_1.jpg" ); g1.wynik+=2;} break;
        case 2: {Form1->Image1->Picture->LoadFromFile("img/2_2.jpg" ); g1.wynik+=2;} break;
        case 3: {Form1->Image1->Picture->LoadFromFile("img/2_3.jpg" ); g1.wynik+=2;} break;
        case 4: {Form1->Image1->Picture->LoadFromFile("img/2_4.jpg" ); g1.wynik+=2;} break;
        case 5: {Form1->Image1->Picture->LoadFromFile("img/3_1.jpg" ); g1.wynik+=3;} break;
        case 6: {Form1->Image1->Picture->LoadFromFile("img/3_2.jpg" ); g1.wynik+=3;} break;
        case 7: {Form1->Image1->Picture->LoadFromFile("img/3_3.jpg" ); g1.wynik+=3;} break;
        case 8: {Form1->Image1->Picture->LoadFromFile("img/3_4.jpg" ); g1.wynik+=3;} break;
        case 9: {Form1->Image1->Picture->LoadFromFile("img/4_1.jpg" ); g1.wynik+=4;} break;
        case 10: {Form1->Image1->Picture->LoadFromFile("img/4_2.jpg" ); g1.wynik+=4;} break;
        case 11: {Form1->Image1->Picture->LoadFromFile("img/4_3.jpg" ); g1.wynik+=4;} break;
        case 12: {Form1->Image1->Picture->LoadFromFile("img/4_4.jpg" ); g1.wynik+=4;} break;
        case 13: {Form1->Image1->Picture->LoadFromFile("img/5_1.jpg" ); g1.wynik+=5;} break;
        case 14: {Form1->Image1->Picture->LoadFromFile("img/5_2.jpg" ); g1.wynik+=5;} break;
        case 15: {Form1->Image1->Picture->LoadFromFile("img/5_3.jpg" ); g1.wynik+=5;} break;
        case 16: {Form1->Image1->Picture->LoadFromFile("img/5_4.jpg" ); g1.wynik+=5;} break;
        case 17: {Form1->Image1->Picture->LoadFromFile("img/6_1.jpg" ); g1.wynik+=6;} break;
        case 18: {Form1->Image1->Picture->LoadFromFile("img/6_2.jpg" ); g1.wynik+=6;} break;
        case 19: {Form1->Image1->Picture->LoadFromFile("img/6_3.jpg" ); g1.wynik+=6;} break;
        case 20: {Form1->Image1->Picture->LoadFromFile("img/6_4.jpg" ); g1.wynik+=6;} break;
        case 21: {Form1->Image1->Picture->LoadFromFile("img/7_3.jpg" ); g1.wynik+=7;} break;
        case 22: {Form1->Image1->Picture->LoadFromFile("img/7_4.jpg" ); g1.wynik+=7;} break;
        case 23: {Form1->Image1->Picture->LoadFromFile("img/7_1.jpg" ); g1.wynik+=7;} break;
        case 24: {Form1->Image1->Picture->LoadFromFile("img/7_2.jpg" ); g1.wynik+=7;} break;
        case 25: {Form1->Image1->Picture->LoadFromFile("img/8_3.jpg" ); g1.wynik+=8;} break;
        case 26: {Form1->Image1->Picture->LoadFromFile("img/8_4.jpg" ); g1.wynik+=8;} break;
        case 27: {Form1->Image1->Picture->LoadFromFile("img/8_1.jpg" ); g1.wynik+=8;} break;
        case 28: {Form1->Image1->Picture->LoadFromFile("img/8_2.jpg" ); g1.wynik+=8;} break;
        case 29: {Form1->Image1->Picture->LoadFromFile("img/9_1.jpg" ); g1.wynik+=9;} break;
        case 30: {Form1->Image1->Picture->LoadFromFile("img/9_2.jpg" ); g1.wynik+=9;} break;
        case 31: {Form1->Image1->Picture->LoadFromFile("img/9_3.jpg" ); g1.wynik+=9;} break;
        case 32: {Form1->Image1->Picture->LoadFromFile("img/9_4.jpg" ); g1.wynik+=9;} break;
        case 33: {Form1->Image1->Picture->LoadFromFile("img/10_1.jpg" ); g1.wynik+=10;} break;
        case 34: {Form1->Image1->Picture->LoadFromFile("img/10_2.jpg" ); g1.wynik+=10;} break;
        case 35: {Form1->Image1->Picture->LoadFromFile("img/10_3.jpg" ); g1.wynik+=10;} break;
        case 36: {Form1->Image1->Picture->LoadFromFile("img/10_4.jpg" ); g1.wynik+=10;} break;
        case 37: {Form1->Image1->Picture->LoadFromFile("img/J_1.jpg" ); g1.wynik+=10;} break;
        case 38: {Form1->Image1->Picture->LoadFromFile("img/J_2.jpg" ); g1.wynik+=10;} break;
        case 39: {Form1->Image1->Picture->LoadFromFile("img/J_3.jpg" ); g1.wynik+=10;} break;
        case 40: {Form1->Image1->Picture->LoadFromFile("img/J_4.jpg" ); g1.wynik+=10;} break;
        case 41: {Form1->Image1->Picture->LoadFromFile("img/Q_1.jpg" ); g1.wynik+=10;} break;
        case 42: {Form1->Image1->Picture->LoadFromFile("img/Q_2.jpg" ); g1.wynik+=10;} break;
        case 43: {Form1->Image1->Picture->LoadFromFile("img/Q_3.jpg" ); g1.wynik+=10;} break;
        case 44: {Form1->Image1->Picture->LoadFromFile("img/Q_4.jpg" ); g1.wynik+=10;} break;
        case 45: {Form1->Image1->Picture->LoadFromFile("img/K_1.jpg" ); g1.wynik+=10;} break;
        case 46: {Form1->Image1->Picture->LoadFromFile("img/K_2.jpg" ); g1.wynik+=10;} break;
        case 47: {Form1->Image1->Picture->LoadFromFile("img/K_3.jpg" ); g1.wynik+=10;} break;
        case 48: {Form1->Image1->Picture->LoadFromFile("img/K_4.jpg" ); g1.wynik+=10;} break;
        case 49: {Form1->Image1->Picture->LoadFromFile("img/A_1.jpg" ); Form1->Label5->Visible=true; Form1->Button13->Visible=true; Form1->Button14->Visible=true;} break;
        case 50: {Form1->Image1->Picture->LoadFromFile("img/A_2.jpg" ); Form1->Label5->Visible=true; Form1->Button13->Visible=true; Form1->Button14->Visible=true;} break;
        case 51: {Form1->Image1->Picture->LoadFromFile("img/A_3.jpg" ); Form1->Label5->Visible=true; Form1->Button13->Visible=true; Form1->Button14->Visible=true;;} break;
        case 52: {Form1->Image1->Picture->LoadFromFile("img/A_4.jpg" ); Form1->Label5->Visible=true; Form1->Button13->Visible=true; Form1->Button14->Visible=true;} break;
        }

Form1->Label4->Caption=IntToStr(g1.wynik);
Form1->Button5->Visible=true;
Form1->Button2->Visible=false;
if(g1.wynik==21){Form1->Button8->Visible=true; Form1->Button2->Visible=false; Form1->Button5->Visible=false; Form1->Button6->Visible=false; Form1->Button4->Visible=false; Form1->Button21->Visible=false; g1.waluta+=500;}
if(g1.wynik>21){Form1->Button7->Visible=true;  Form1->Button2->Visible=false; Form1->Button5->Visible=false; Form1->Button6->Visible=false; Form1->Button4->Visible=false; Form1->Button21->Visible=false; g1.waluta-=100;}
Form1->Label8->Caption=IntToStr(g1.waluta);
}

void Sterownik::ev_Login(){
                   g1.wynik=0;
g1.karty[0]=0;
g1.karty[1]=0;
g1.karty[2]=0;
g1.karty[3]=0;
g1.karty[4]=0;
g1.wynik=0;
Form1->Image1->Picture->LoadFromFile("img/rewers.jpg" );
Form1->Image2->Picture->LoadFromFile("img/rewers.jpg" );
Form1->Image3->Picture->LoadFromFile("img/rewers.jpg" );
Form1->Image4->Picture->LoadFromFile("img/rewers.jpg" );
Form1->Image5->Picture->LoadFromFile("img/rewers.jpg" );
Form1->Image6->Picture->LoadFromFile("img/rewers.jpg" );
Form1->Image7->Picture->LoadFromFile("img/rewers.jpg" );
Form1->Image8->Picture->LoadFromFile("img/rewers.jpg" );
Form1->Image9->Picture->LoadFromFile("img/rewers.jpg" );
Form1->Image10->Picture->LoadFromFile("img/rewers.jpg" );
Form1->Image1->Visible=true;
Form1->Image2->Visible=true;
Form1->Image3->Visible=true;
Form1->Image4->Visible=true;
Form1->Image5->Visible=true;
Form1->Image6->Visible=true;
Form1->Image7->Visible=true;
Form1->Image8->Visible=true;
Form1->Image9->Visible=true;
Form1->Image10->Visible=true;
Form1->Button1->Visible=true;
Form1->Button19->Visible=false;
Form1->Label7->Visible=true;
Form1->Label8->Visible=true;
Form1->Label9->Visible=true;
Form1->Label1->Visible=true;
Form1->Label2->Visible=true;
Form1->Label3->Visible=true;
Form1->Label4->Visible=true;
Form1->Label10->Visible=true;
Form1->Label12->Visible=true;
Form1->Label13->Visible=true;
Form1->Label6->Visible=false;
}



//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
        g1.waluta=5000;
        g1.karty[0]=0;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
     g1.login();
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
srand(time(NULL));
g1.karty[3]=rand()%51+1;
do{
if(g1.karty[4]>52)g1.karty[4]=rand()%51+1;
else
g1.karty[3]+=1;}while((g1.karty[3] == g1.karty[0])||(g1.karty[3] == g1.karty[1])||(g1.karty[3] == g1.karty[2]));
switch(g1.karty[3])
{
        case 1: {Image2->Picture->LoadFromFile("img/2_1.jpg" ); g1.wynik+=2;} break;
        case 2: {Image2->Picture->LoadFromFile("img/2_2.jpg" ); g1.wynik+=2;} break;
        case 3: {Image2->Picture->LoadFromFile("img/2_3.jpg" ); g1.wynik+=2;} break;
        case 4: {Image2->Picture->LoadFromFile("img/2_4.jpg" ); g1.wynik+=2;} break;
        case 5: {Image2->Picture->LoadFromFile("img/3_1.jpg" ); g1.wynik+=3;} break;
        case 6: {Image2->Picture->LoadFromFile("img/3_2.jpg" ); g1.wynik+=3;} break;
        case 7: {Image2->Picture->LoadFromFile("img/3_3.jpg" ); g1.wynik+=3;} break;
        case 8: {Image2->Picture->LoadFromFile("img/3_4.jpg" ); g1.wynik+=3;} break;
        case 9: {Image2->Picture->LoadFromFile("img/4_1.jpg" ); g1.wynik+=4;} break;
        case 10: {Image2->Picture->LoadFromFile("img/4_2.jpg" ); g1.wynik+=4;} break;
        case 11: {Image2->Picture->LoadFromFile("img/4_3.jpg" ); g1.wynik+=4;} break;
        case 12: {Image2->Picture->LoadFromFile("img/4_4.jpg" ); g1.wynik+=4;} break;
        case 13: {Image2->Picture->LoadFromFile("img/5_1.jpg" ); g1.wynik+=5;} break;
        case 14: {Image2->Picture->LoadFromFile("img/5_2.jpg" ); g1.wynik+=5;} break;
        case 15: {Image2->Picture->LoadFromFile("img/5_3.jpg" ); g1.wynik+=5;} break;
        case 16: {Image2->Picture->LoadFromFile("img/5_4.jpg" ); g1.wynik+=5;} break;
        case 17: {Image2->Picture->LoadFromFile("img/6_1.jpg" ); g1.wynik+=6;} break;
        case 18: {Image2->Picture->LoadFromFile("img/6_2.jpg" ); g1.wynik+=6;} break;
        case 19: {Image2->Picture->LoadFromFile("img/6_4.jpg" ); g1.wynik+=6;} break;
        case 20: {Image2->Picture->LoadFromFile("img/6_3.jpg" ); g1.wynik+=6;} break;
        case 21: {Image2->Picture->LoadFromFile("img/7_3.jpg" ); g1.wynik+=7;} break;
        case 22: {Image2->Picture->LoadFromFile("img/7_4.jpg" ); g1.wynik+=7;} break;
        case 23: {Image2->Picture->LoadFromFile("img/7_1.jpg" ); g1.wynik+=7;} break;
        case 24: {Image2->Picture->LoadFromFile("img/7_2.jpg" ); g1.wynik+=7;} break;
        case 25: {Image2->Picture->LoadFromFile("img/8_3.jpg" ); g1.wynik+=8;} break;
        case 26: {Image2->Picture->LoadFromFile("img/8_4.jpg" ); g1.wynik+=8;} break;
        case 27: {Image2->Picture->LoadFromFile("img/8_1.jpg" ); g1.wynik+=8;} break;
        case 28: {Image2->Picture->LoadFromFile("img/8_2.jpg" ); g1.wynik+=8;} break;
        case 29: {Image2->Picture->LoadFromFile("img/9_1.jpg" ); g1.wynik+=9;} break;
        case 30: {Image2->Picture->LoadFromFile("img/9_2.jpg" ); g1.wynik+=9;} break;
        case 31: {Image2->Picture->LoadFromFile("img/9_3.jpg" ); g1.wynik+=9;} break;
        case 32: {Image2->Picture->LoadFromFile("img/9_4.jpg" ); g1.wynik+=9;} break;
        case 33: {Image2->Picture->LoadFromFile("img/10_1.jpg" ); g1.wynik+=10;} break;
        case 34: {Image2->Picture->LoadFromFile("img/10_2.jpg" ); g1.wynik+=10;} break;
        case 35: {Image2->Picture->LoadFromFile("img/10_3.jpg" ); g1.wynik+=10;} break;
        case 36: {Image2->Picture->LoadFromFile("img/10_4.jpg" ); g1.wynik+=10;} break;
        case 37: {Image2->Picture->LoadFromFile("img/J_1.jpg" ); g1.wynik+=10;} break;
        case 38: {Image2->Picture->LoadFromFile("img/J_2.jpg" ); g1.wynik+=10;} break;
        case 39: {Image2->Picture->LoadFromFile("img/J_3.jpg" ); g1.wynik+=10;} break;
        case 40: {Image2->Picture->LoadFromFile("img/J_4.jpg" ); g1.wynik+=10;} break;
        case 41: {Image2->Picture->LoadFromFile("img/Q_1.jpg" ); g1.wynik+=10;} break;
        case 42: {Image2->Picture->LoadFromFile("img/Q_2.jpg" ); g1.wynik+=10;} break;
        case 43: {Image2->Picture->LoadFromFile("img/Q_3.jpg" ); g1.wynik+=10;} break;
        case 44: {Image2->Picture->LoadFromFile("img/Q_4.jpg" ); g1.wynik+=10;} break;
        case 45: {Image2->Picture->LoadFromFile("img/K_1.jpg" ); g1.wynik+=10;} break;
        case 46: {Image2->Picture->LoadFromFile("img/K_2.jpg" ); g1.wynik+=10;} break;
        case 47: {Image2->Picture->LoadFromFile("img/K_3.jpg" ); g1.wynik+=10;} break;
        case 48: {Image2->Picture->LoadFromFile("img/K_4.jpg" ); g1.wynik+=10;} break;
        case 49: {Image2->Picture->LoadFromFile("img/A_1.jpg" ); Label5->Visible=true; Button15->Visible=true; Button16->Visible=true;} break;
        case 50: {Image2->Picture->LoadFromFile("img/A_2.jpg" ); Label5->Visible=true; Button15->Visible=true; Button16->Visible=true;} break;
        case 51: {Image2->Picture->LoadFromFile("img/A_3.jpg" ); Label5->Visible=true; Button15->Visible=true; Button16->Visible=true;} break;
        case 52: {Image2->Picture->LoadFromFile("img/A_4.jpg" ); Label5->Visible=true; Button15->Visible=true; Button16->Visible=true;} break;
        }

Label4->Caption=IntToStr(g1.wynik);
Button6->Visible=true;
Button5->Visible=false;
if(g1.wynik==21){Button8->Visible=true; Form1->Button2->Visible=false; Form1->Button5->Visible=false; Form1->Button6->Visible=false; Form1->Button4->Visible=false; Form1->Button21->Visible=false; g1.waluta+=500;}
if(g1.wynik>21){Button7->Visible=true; Form1->Button2->Visible=false; Form1->Button5->Visible=false; Form1->Button6->Visible=false; Form1->Button4->Visible=false; Form1->Button21->Visible=false; g1.waluta-=100;}
Label8->Caption=IntToStr(g1.waluta);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
srand(time(NULL));
g1.karty[4]=rand()%51+1;
do{
if(g1.karty[4]>52)g1.karty[4]=rand()%51+1;
else
g1.karty[4]+=1;}while((g1.karty[4] == g1.karty[0])||(g1.karty[4] == g1.karty[1])||(g1.karty[4] == g1.karty[2])||(g1.karty[4] == g1.karty[3]));
switch(g1.karty[4])
{
        case 1: {Image3->Picture->LoadFromFile("img/2_1.jpg" ); g1.wynik+=2;} break;
        case 2: {Image3->Picture->LoadFromFile("img/2_2.jpg" ); g1.wynik+=2;} break;
        case 3: {Image3->Picture->LoadFromFile("img/2_3.jpg" ); g1.wynik+=2;} break;
        case 4: {Image3->Picture->LoadFromFile("img/2_4.jpg" ); g1.wynik+=2;} break;
        case 5: {Image3->Picture->LoadFromFile("img/3_1.jpg" ); g1.wynik+=3;} break;
        case 6: {Image3->Picture->LoadFromFile("img/3_2.jpg" ); g1.wynik+=3;} break;
        case 7: {Image3->Picture->LoadFromFile("img/3_3.jpg" ); g1.wynik+=3;} break;
        case 8: {Image3->Picture->LoadFromFile("img/3_4.jpg" ); g1.wynik+=3;} break;
        case 9: {Image3->Picture->LoadFromFile("img/4_1.jpg" ); g1.wynik+=4;} break;
        case 10: {Image3->Picture->LoadFromFile("img/4_2.jpg" ); g1.wynik+=4;} break;
        case 11: {Image3->Picture->LoadFromFile("img/4_3.jpg" ); g1.wynik+=4;} break;
        case 12: {Image3->Picture->LoadFromFile("img/4_4.jpg" ); g1.wynik+=4;} break;
        case 13: {Image3->Picture->LoadFromFile("img/5_1.jpg" ); g1.wynik+=5;} break;
        case 14: {Image3->Picture->LoadFromFile("img/5_2.jpg" ); g1.wynik+=5;} break;
        case 15: {Image3->Picture->LoadFromFile("img/5_3.jpg" ); g1.wynik+=5;} break;
        case 16: {Image3->Picture->LoadFromFile("img/5_4.jpg" ); g1.wynik+=5;} break;
        case 17: {Image3->Picture->LoadFromFile("img/6_1.jpg" ); g1.wynik+=6;} break;
        case 18: {Image3->Picture->LoadFromFile("img/6_2.jpg" ); g1.wynik+=6;} break;
        case 19: {Image3->Picture->LoadFromFile("img/6_3.jpg" ); g1.wynik+=6;} break;
        case 20: {Image3->Picture->LoadFromFile("img/6_4.jpg" ); g1.wynik+=6;} break;
        case 21: {Image3->Picture->LoadFromFile("img/7_3.jpg" ); g1.wynik+=7;} break;
        case 22: {Image3->Picture->LoadFromFile("img/7_4.jpg" ); g1.wynik+=7;} break;
        case 23: {Image3->Picture->LoadFromFile("img/7_1.jpg" ); g1.wynik+=7;} break;
        case 24: {Image3->Picture->LoadFromFile("img/7_2.jpg" ); g1.wynik+=7;} break;
        case 25: {Image3->Picture->LoadFromFile("img/8_3.jpg" ); g1.wynik+=8;} break;
        case 26: {Image3->Picture->LoadFromFile("img/8_4.jpg" ); g1.wynik+=8;} break;
        case 27: {Image3->Picture->LoadFromFile("img/8_1.jpg" ); g1.wynik+=8;} break;
        case 28: {Image3->Picture->LoadFromFile("img/8_2.jpg" ); g1.wynik+=8;} break;
        case 29: {Image3->Picture->LoadFromFile("img/9_1.jpg" ); g1.wynik+=9;} break;
        case 30: {Image3->Picture->LoadFromFile("img/9_2.jpg" ); g1.wynik+=9;} break;
        case 31: {Image3->Picture->LoadFromFile("img/9_3.jpg" ); g1.wynik+=9;} break;
        case 32: {Image3->Picture->LoadFromFile("img/9_4.jpg" ); g1.wynik+=9;} break;
        case 33: {Image3->Picture->LoadFromFile("img/10_1.jpg" ); g1.wynik+=10;} break;
        case 34: {Image3->Picture->LoadFromFile("img/10_2.jpg" ); g1.wynik+=10;} break;
        case 35: {Image3->Picture->LoadFromFile("img/10_3.jpg" ); g1.wynik+=10;} break;
        case 36: {Image3->Picture->LoadFromFile("img/10_4.jpg" ); g1.wynik+=10;} break;
        case 37: {Image3->Picture->LoadFromFile("img/J_1.jpg" ); g1.wynik+=10;} break;
        case 38: {Image3->Picture->LoadFromFile("img/J_2.jpg" ); g1.wynik+=10;} break;
        case 39: {Image3->Picture->LoadFromFile("img/J_3.jpg" ); g1.wynik+=10;} break;
        case 40: {Image3->Picture->LoadFromFile("img/J_4.jpg" ); g1.wynik+=10;} break;
        case 41: {Image3->Picture->LoadFromFile("img/Q_1.jpg" ); g1.wynik+=10;} break;
        case 42: {Image3->Picture->LoadFromFile("img/Q_2.jpg" ); g1.wynik+=10;} break;
        case 43: {Image3->Picture->LoadFromFile("img/Q_3.jpg" ); g1.wynik+=10;} break;
        case 44: {Image3->Picture->LoadFromFile("img/Q_4.jpg" ); g1.wynik+=10;} break;
        case 45: {Image3->Picture->LoadFromFile("img/K_1.jpg" ); g1.wynik+=10;} break;
        case 46: {Image3->Picture->LoadFromFile("img/K_2.jpg" ); g1.wynik+=10;} break;
        case 47: {Image3->Picture->LoadFromFile("img/K_3.jpg" ); g1.wynik+=10;} break;
        case 48: {Image3->Picture->LoadFromFile("img/K_4.jpg" ); g1.wynik+=10;} break;
        case 49: {Image3->Picture->LoadFromFile("img/A_1.jpg" ); Label5->Visible=true; Button17->Visible=true; Button18->Visible=true;} break;
        case 50: {Image3->Picture->LoadFromFile("img/A_2.jpg" ); Label5->Visible=true; Button17->Visible=true; Button18->Visible=true;} break;
        case 51: {Image3->Picture->LoadFromFile("img/A_3.jpg" ); Label5->Visible=true; Button17->Visible=true; Button18->Visible=true;} break;
        case 52: {Image3->Picture->LoadFromFile("img/A_4.jpg" ); Label5->Visible=true; Button17->Visible=true; Button18->Visible=true;} break;
        }

Label4->Caption=IntToStr(g1.wynik);
if(g1.wynik==21){Button8->Visible=true; Form1->Button2->Visible=false; Form1->Button5->Visible=false; Form1->Button6->Visible=false; Form1->Button4->Visible=false; Form1->Button21->Visible=false; g1.waluta+=500;}
if(g1.wynik>21){Button7->Visible=true; Form1->Button2->Visible=false; Form1->Button5->Visible=false; Form1->Button6->Visible=false; Form1->Button4->Visible=false; Form1->Button21->Visible=false; g1.waluta-=100;}
Label8->Caption=IntToStr(g1.waluta);
if(g1.wynik<21)
{
        k1.wynik=0;
        k1.karty[0]=rand()%51+1;
        k1.karty[1]=rand()%51+1;
        do{
        if(k1.karty[0]>52)k1.karty[0]=rand()%51+1;
        else
        k1.karty[0]+=1;}while((k1.karty[0] == g1.karty[0])||(k1.karty[0] == g1.karty[1])||(k1.karty[0] == g1.karty[2])||(k1.karty[0] == g1.karty[3])||(k1.karty[0] == g1.karty[4]));
        do{
        if(k1.karty[1]>52)k1.karty[1]=rand()%51+1;
        else
        k1.karty[1]+=1;}while((k1.karty[1] == g1.karty[0])||(k1.karty[1] == g1.karty[1])||(k1.karty[1] == g1.karty[2])||(k1.karty[1] == g1.karty[3])||(k1.karty[1] == k1.karty[0])||(k1.karty[1] == g1.karty[4]));

        switch(k1.karty[0])
{
        case 1: {Form1->Image6->Picture->LoadFromFile("img/2_1.jpg" ); k1.wynik+=2;} break;
        case 2: {Form1->Image6->Picture->LoadFromFile("img/2_2.jpg" ); k1.wynik+=2;} break;
        case 3: {Form1->Image6->Picture->LoadFromFile("img/2_3.jpg" ); k1.wynik+=2;} break;
        case 4: {Form1->Image6->Picture->LoadFromFile("img/2_4.jpg" ); k1.wynik+=2;} break;
        case 5: {Form1->Image6->Picture->LoadFromFile("img/3_1.jpg" ); k1.wynik+=3;} break;
        case 6: {Form1->Image6->Picture->LoadFromFile("img/3_2.jpg" ); k1.wynik+=3;} break;
        case 7: {Form1->Image6->Picture->LoadFromFile("img/3_3.jpg" ); k1.wynik+=3;} break;
        case 8: {Form1->Image6->Picture->LoadFromFile("img/3_4.jpg" ); k1.wynik+=3;} break;
        case 9: {Form1->Image6->Picture->LoadFromFile("img/4_1.jpg" ); k1.wynik+=4;} break;
        case 10: {Form1->Image6->Picture->LoadFromFile("img/4_2.jpg" ); k1.wynik+=4;} break;
        case 11: {Form1->Image6->Picture->LoadFromFile("img/4_3.jpg" ); k1.wynik+=4;} break;
        case 12: {Form1->Image6->Picture->LoadFromFile("img/4_4.jpg" ); k1.wynik+=4;} break;
        case 13: {Form1->Image6->Picture->LoadFromFile("img/5_1.jpg" ); k1.wynik+=5;} break;
        case 14: {Form1->Image6->Picture->LoadFromFile("img/5_2.jpg" ); k1.wynik+=5;} break;
        case 15: {Form1->Image6->Picture->LoadFromFile("img/5_3.jpg" ); k1.wynik+=5;} break;
        case 16: {Form1->Image6->Picture->LoadFromFile("img/5_4.jpg" ); k1.wynik+=5;} break;
        case 17: {Form1->Image6->Picture->LoadFromFile("img/6_1.jpg" ); k1.wynik+=6;} break;
        case 18: {Form1->Image6->Picture->LoadFromFile("img/6_2.jpg" ); k1.wynik+=6;} break;
        case 19: {Form1->Image6->Picture->LoadFromFile("img/6_3.jpg" ); k1.wynik+=6;} break;
        case 20: {Form1->Image6->Picture->LoadFromFile("img/6_4.jpg" ); k1.wynik+=6;} break;
        case 21: {Form1->Image6->Picture->LoadFromFile("img/7_3.jpg" ); k1.wynik+=7;} break;
        case 22: {Form1->Image6->Picture->LoadFromFile("img/7_4.jpg" ); k1.wynik+=7;} break;
        case 23: {Form1->Image6->Picture->LoadFromFile("img/7_1.jpg" ); k1.wynik+=7;} break;
        case 24: {Form1->Image6->Picture->LoadFromFile("img/7_2.jpg" ); k1.wynik+=7;} break;
        case 25: {Form1->Image6->Picture->LoadFromFile("img/8_3.jpg" ); k1.wynik+=8;} break;
        case 26: {Form1->Image6->Picture->LoadFromFile("img/8_4.jpg" ); k1.wynik+=8;} break;
        case 27: {Form1->Image6->Picture->LoadFromFile("img/8_1.jpg" ); k1.wynik+=8;} break;
        case 28: {Form1->Image6->Picture->LoadFromFile("img/8_2.jpg" ); k1.wynik+=8;} break;
        case 29: {Form1->Image6->Picture->LoadFromFile("img/9_1.jpg" ); k1.wynik+=9;} break;
        case 30: {Form1->Image6->Picture->LoadFromFile("img/9_2.jpg" ); k1.wynik+=9;} break;
        case 31: {Form1->Image6->Picture->LoadFromFile("img/9_3.jpg" ); k1.wynik+=9;} break;
        case 32: {Form1->Image6->Picture->LoadFromFile("img/9_4.jpg" ); k1.wynik+=9;} break;
        case 33: {Form1->Image6->Picture->LoadFromFile("img/10_1.jpg" ); k1.wynik+=10;} break;
        case 34: {Form1->Image6->Picture->LoadFromFile("img/10_2.jpg" ); k1.wynik+=10;} break;
        case 35: {Form1->Image6->Picture->LoadFromFile("img/10_3.jpg" ); k1.wynik+=10;} break;
        case 36: {Form1->Image6->Picture->LoadFromFile("img/10_4.jpg" ); k1.wynik+=10;} break;
        case 37: {Form1->Image6->Picture->LoadFromFile("img/J_1.jpg" ); k1.wynik+=10;} break;
        case 38: {Form1->Image6->Picture->LoadFromFile("img/J_2.jpg" ); k1.wynik+=10;} break;
        case 39: {Form1->Image6->Picture->LoadFromFile("img/J_3.jpg" ); k1.wynik+=10;} break;
        case 40: {Form1->Image6->Picture->LoadFromFile("img/J_4.jpg" ); k1.wynik+=10;} break;
        case 41: {Form1->Image6->Picture->LoadFromFile("img/Q_1.jpg" ); k1.wynik+=10;} break;
        case 42: {Form1->Image6->Picture->LoadFromFile("img/Q_2.jpg" ); k1.wynik+=10;} break;
        case 43: {Form1->Image6->Picture->LoadFromFile("img/Q_3.jpg" ); k1.wynik+=10;} break;
        case 44: {Form1->Image6->Picture->LoadFromFile("img/Q_4.jpg" ); k1.wynik+=10;} break;
        case 45: {Form1->Image6->Picture->LoadFromFile("img/K_1.jpg" ); k1.wynik+=10;} break;
        case 46: {Form1->Image6->Picture->LoadFromFile("img/K_2.jpg" ); k1.wynik+=10;} break;
        case 47: {Form1->Image6->Picture->LoadFromFile("img/K_3.jpg" ); k1.wynik+=10;} break;
        case 48: {Form1->Image6->Picture->LoadFromFile("img/K_4.jpg" ); k1.wynik+=10;} break;
        case 49: {Form1->Image6->Picture->LoadFromFile("img/A_1.jpg" ); k1.wynik+=11;} break;
        case 50: {Form1->Image6->Picture->LoadFromFile("img/A_2.jpg" ); k1.wynik+=11;} break;
        case 51: {Form1->Image6->Picture->LoadFromFile("img/A_3.jpg" ); k1.wynik+=11;} break;
        case 52: {Form1->Image6->Picture->LoadFromFile("img/A_4.jpg" ); k1.wynik+=11;} break;
        }
switch(k1.karty[1])
{
        case 1: {Form1->Image7->Picture->LoadFromFile("img/2_1.jpg" ); k1.wynik+=2;} break;
        case 2: {Form1->Image7->Picture->LoadFromFile("img/2_2.jpg" ); k1.wynik+=2;} break;
        case 3: {Form1->Image7->Picture->LoadFromFile("img/2_3.jpg" ); k1.wynik+=2;} break;
        case 4: {Form1->Image7->Picture->LoadFromFile("img/2_4.jpg" ); k1.wynik+=2;} break;
        case 5: {Form1->Image7->Picture->LoadFromFile("img/3_1.jpg" ); k1.wynik+=3;} break;
        case 6: {Form1->Image7->Picture->LoadFromFile("img/3_2.jpg" ); k1.wynik+=3;} break;
        case 7: {Form1->Image7->Picture->LoadFromFile("img/3_3.jpg" ); k1.wynik+=3;} break;
        case 8: {Form1->Image7->Picture->LoadFromFile("img/3_4.jpg" ); k1.wynik+=3;} break;
        case 9: {Form1->Image7->Picture->LoadFromFile("img/4_1.jpg" ); k1.wynik+=4;} break;
        case 10: {Form1->Image7->Picture->LoadFromFile("img/4_2.jpg" ); k1.wynik+=4;} break;
        case 11: {Form1->Image7->Picture->LoadFromFile("img/4_3.jpg" ); k1.wynik+=4;} break;
        case 12: {Form1->Image7->Picture->LoadFromFile("img/4_4.jpg" ); k1.wynik+=4;} break;
        case 13: {Form1->Image7->Picture->LoadFromFile("img/5_1.jpg" ); k1.wynik+=5;} break;
        case 14: {Form1->Image7->Picture->LoadFromFile("img/5_2.jpg" ); k1.wynik+=5;} break;
        case 15: {Form1->Image7->Picture->LoadFromFile("img/5_3.jpg" ); k1.wynik+=5;} break;
        case 16: {Form1->Image7->Picture->LoadFromFile("img/5_4.jpg" ); k1.wynik+=5;} break;
        case 17: {Form1->Image7->Picture->LoadFromFile("img/6_1.jpg" ); k1.wynik+=6;} break;
        case 18: {Form1->Image7->Picture->LoadFromFile("img/6_2.jpg" ); k1.wynik+=6;} break;
        case 19: {Form1->Image7->Picture->LoadFromFile("img/6_4.jpg" ); k1.wynik+=6;} break;
        case 20: {Form1->Image7->Picture->LoadFromFile("img/6_3.jpg" ); k1.wynik+=6;} break;
        case 21: {Form1->Image7->Picture->LoadFromFile("img/7_3.jpg" ); k1.wynik+=7;} break;
        case 22: {Form1->Image7->Picture->LoadFromFile("img/7_4.jpg" ); k1.wynik+=7;} break;
        case 23: {Form1->Image7->Picture->LoadFromFile("img/7_1.jpg" ); k1.wynik+=7;} break;
        case 24: {Form1->Image7->Picture->LoadFromFile("img/7_2.jpg" ); k1.wynik+=7;} break;
        case 25: {Form1->Image7->Picture->LoadFromFile("img/8_3.jpg" ); k1.wynik+=8;} break;
        case 26: {Form1->Image7->Picture->LoadFromFile("img/8_4.jpg" ); k1.wynik+=8;} break;
        case 27: {Form1->Image7->Picture->LoadFromFile("img/8_1.jpg" ); k1.wynik+=8;} break;
        case 28: {Form1->Image7->Picture->LoadFromFile("img/8_2.jpg" ); k1.wynik+=8;} break;
        case 29: {Form1->Image7->Picture->LoadFromFile("img/9_1.jpg" ); k1.wynik+=9;} break;
        case 30: {Form1->Image7->Picture->LoadFromFile("img/9_2.jpg" ); k1.wynik+=9;} break;
        case 31: {Form1->Image7->Picture->LoadFromFile("img/9_3.jpg" ); k1.wynik+=9;} break;
        case 32: {Form1->Image7->Picture->LoadFromFile("img/9_4.jpg" ); k1.wynik+=9;} break;
        case 33: {Form1->Image7->Picture->LoadFromFile("img/10_1.jpg" ); k1.wynik+=10;} break;
        case 34: {Form1->Image7->Picture->LoadFromFile("img/10_2.jpg" ); k1.wynik+=10;} break;
        case 35: {Form1->Image7->Picture->LoadFromFile("img/10_3.jpg" ); k1.wynik+=10;} break;
        case 36: {Form1->Image7->Picture->LoadFromFile("img/10_4.jpg" ); k1.wynik+=10;} break;
        case 37: {Form1->Image7->Picture->LoadFromFile("img/J_1.jpg" ); k1.wynik+=10;} break;
        case 38: {Form1->Image7->Picture->LoadFromFile("img/J_2.jpg" ); k1.wynik+=10;} break;
        case 39: {Form1->Image7->Picture->LoadFromFile("img/J_3.jpg" ); k1.wynik+=10;} break;
        case 40: {Form1->Image7->Picture->LoadFromFile("img/J_4.jpg" ); k1.wynik+=10;} break;
        case 41: {Form1->Image7->Picture->LoadFromFile("img/Q_1.jpg" ); k1.wynik+=10;} break;
        case 42: {Form1->Image7->Picture->LoadFromFile("img/Q_2.jpg" ); k1.wynik+=10;} break;
        case 43: {Form1->Image7->Picture->LoadFromFile("img/Q_3.jpg" ); k1.wynik+=10;} break;
        case 44: {Form1->Image7->Picture->LoadFromFile("img/Q_4.jpg" ); k1.wynik+=10;} break;
        case 45: {Form1->Image7->Picture->LoadFromFile("img/K_1.jpg" ); k1.wynik+=10;} break;
        case 46: {Form1->Image7->Picture->LoadFromFile("img/K_2.jpg" ); k1.wynik+=10;} break;
        case 47: {Form1->Image7->Picture->LoadFromFile("img/K_3.jpg" ); k1.wynik+=10;} break;
        case 48: {Form1->Image7->Picture->LoadFromFile("img/K_4.jpg" ); k1.wynik+=10;} break;
        case 49: {Form1->Image7->Picture->LoadFromFile("img/A_1.jpg" ); if(k1.wynik+11<21){k1.wynik+=11;}else k1.wynik+=1;} break;
        case 50: {Form1->Image7->Picture->LoadFromFile("img/A_2.jpg" ); if(k1.wynik+11<21){k1.wynik+=11;}else k1.wynik+=1;} break;
        case 51: {Form1->Image7->Picture->LoadFromFile("img/A_3.jpg" ); if(k1.wynik+11<21){k1.wynik+=11;}else k1.wynik+=1;} break;
        case 52: {Form1->Image7->Picture->LoadFromFile("img/A_4.jpg" ); if(k1.wynik+11<21){k1.wynik+=11;}else k1.wynik+=1;} break;
        }
        Label13->Caption=IntToStr(k1.wynik);
        int i=2;
        int n=0;
        while(k1.wynik<=g1.wynik)
         {
                k1.karty[i]=rand()%51+1;
                 do
                {
                        n==0;
                        do{
                                if(k1.karty[i]>52)k1.karty[i]=rand()%51+1;
                                else
                                k1.karty[i]+=1;}while((k1.karty[0] == g1.karty[0])||(k1.karty[0] == g1.karty[1])||(k1.karty[0] == g1.karty[2])||(k1.karty[0] == g1.karty[3])||(k1.karty[0] == g1.karty[4]));
                                for(int j=0;j<i;j++)if(k1.karty[i]==k1.karty[j])n++;
                        }while(n!=0);
        switch(k1.karty[i])
        {
        case 1: {Form1->Image8->Picture->LoadFromFile("img/2_1.jpg" ); k1.wynik+=2;} break;
        case 2: {Form1->Image8->Picture->LoadFromFile("img/2_2.jpg" ); k1.wynik+=2;} break;
        case 3: {Form1->Image8->Picture->LoadFromFile("img/2_3.jpg" ); k1.wynik+=2;} break;
        case 4: {Form1->Image8->Picture->LoadFromFile("img/2_4.jpg" ); k1.wynik+=2;} break;
        case 5: {Form1->Image8->Picture->LoadFromFile("img/3_1.jpg" ); k1.wynik+=3;} break;
        case 6: {Form1->Image8->Picture->LoadFromFile("img/3_2.jpg" ); k1.wynik+=3;} break;
        case 7: {Form1->Image8->Picture->LoadFromFile("img/3_3.jpg" ); k1.wynik+=3;} break;
        case 8: {Form1->Image8->Picture->LoadFromFile("img/3_4.jpg" ); k1.wynik+=3;} break;
        case 9: {Form1->Image8->Picture->LoadFromFile("img/4_1.jpg" ); k1.wynik+=4;} break;
        case 10: {Form1->Image8->Picture->LoadFromFile("img/4_2.jpg" ); k1.wynik+=4;} break;
        case 11: {Form1->Image8->Picture->LoadFromFile("img/4_3.jpg" ); k1.wynik+=4;} break;
        case 12: {Form1->Image8->Picture->LoadFromFile("img/4_4.jpg" ); k1.wynik+=4;} break;
        case 13: {Form1->Image8->Picture->LoadFromFile("img/5_1.jpg" ); k1.wynik+=5;} break;
        case 14: {Form1->Image8->Picture->LoadFromFile("img/5_2.jpg" ); k1.wynik+=5;} break;
        case 15: {Form1->Image8->Picture->LoadFromFile("img/5_3.jpg" ); k1.wynik+=5;} break;
        case 16: {Form1->Image8->Picture->LoadFromFile("img/5_4.jpg" ); k1.wynik+=5;} break;
        case 17: {Form1->Image8->Picture->LoadFromFile("img/6_1.jpg" ); k1.wynik+=6;} break;
        case 18: {Form1->Image8->Picture->LoadFromFile("img/6_2.jpg" ); k1.wynik+=6;} break;
        case 19: {Form1->Image8->Picture->LoadFromFile("img/6_3.jpg" ); k1.wynik+=6;} break;
        case 20: {Form1->Image8->Picture->LoadFromFile("img/6_4.jpg" ); k1.wynik+=6;} break;
        case 21: {Form1->Image8->Picture->LoadFromFile("img/7_3.jpg" ); k1.wynik+=7;} break;
        case 22: {Form1->Image8->Picture->LoadFromFile("img/7_4.jpg" ); k1.wynik+=7;} break;
        case 23: {Form1->Image8->Picture->LoadFromFile("img/7_1.jpg" ); k1.wynik+=7;} break;
        case 24: {Form1->Image8->Picture->LoadFromFile("img/7_2.jpg" ); k1.wynik+=7;} break;
        case 25: {Form1->Image8->Picture->LoadFromFile("img/8_3.jpg" ); k1.wynik+=8;} break;
        case 26: {Form1->Image8->Picture->LoadFromFile("img/8_4.jpg" ); k1.wynik+=8;} break;
        case 27: {Form1->Image8->Picture->LoadFromFile("img/8_1.jpg" ); k1.wynik+=8;} break;
        case 28: {Form1->Image8->Picture->LoadFromFile("img/8_2.jpg" ); k1.wynik+=8;} break;
        case 29: {Form1->Image8->Picture->LoadFromFile("img/9_1.jpg" ); k1.wynik+=9;} break;
        case 30: {Form1->Image8->Picture->LoadFromFile("img/9_2.jpg" ); k1.wynik+=9;} break;
        case 31: {Form1->Image8->Picture->LoadFromFile("img/9_3.jpg" ); k1.wynik+=9;} break;
        case 32: {Form1->Image8->Picture->LoadFromFile("img/9_4.jpg" ); k1.wynik+=9;} break;
        case 33: {Form1->Image8->Picture->LoadFromFile("img/10_1.jpg" ); k1.wynik+=10;} break;
        case 34: {Form1->Image8->Picture->LoadFromFile("img/10_2.jpg" ); k1.wynik+=10;} break;
        case 35: {Form1->Image8->Picture->LoadFromFile("img/10_3.jpg" ); k1.wynik+=10;} break;
        case 36: {Form1->Image8->Picture->LoadFromFile("img/10_4.jpg" ); k1.wynik+=10;} break;
        case 37: {Form1->Image8->Picture->LoadFromFile("img/J_1.jpg" ); k1.wynik+=10;} break;
        case 38: {Form1->Image8->Picture->LoadFromFile("img/J_2.jpg" ); k1.wynik+=10;} break;
        case 39: {Form1->Image8->Picture->LoadFromFile("img/J_3.jpg" ); k1.wynik+=10;} break;
        case 40: {Form1->Image8->Picture->LoadFromFile("img/J_4.jpg" ); k1.wynik+=10;} break;
        case 41: {Form1->Image8->Picture->LoadFromFile("img/Q_1.jpg" ); k1.wynik+=10;} break;
        case 42: {Form1->Image8->Picture->LoadFromFile("img/Q_2.jpg" ); k1.wynik+=10;} break;
        case 43: {Form1->Image8->Picture->LoadFromFile("img/Q_3.jpg" ); k1.wynik+=10;} break;
        case 44: {Form1->Image8->Picture->LoadFromFile("img/Q_4.jpg" ); k1.wynik+=10;} break;
        case 45: {Form1->Image8->Picture->LoadFromFile("img/K_1.jpg" ); k1.wynik+=10;} break;
        case 46: {Form1->Image8->Picture->LoadFromFile("img/K_2.jpg" ); k1.wynik+=10;} break;
        case 47: {Form1->Image8->Picture->LoadFromFile("img/K_3.jpg" ); k1.wynik+=10;} break;
        case 48: {Form1->Image8->Picture->LoadFromFile("img/K_4.jpg" ); k1.wynik+=10;} break;
        case 49: {Form1->Image8->Picture->LoadFromFile("img/A_1.jpg" ); k1.wynik+=11;} break;
        case 50: {Form1->Image8->Picture->LoadFromFile("img/A_2.jpg" ); k1.wynik+=11;} break;
        case 51: {Form1->Image8->Picture->LoadFromFile("img/A_3.jpg" ); k1.wynik+=11;} break;
        case 52: {Form1->Image8->Picture->LoadFromFile("img/A_4.jpg" ); k1.wynik+=11;} break;
        }
         //Sleep(2000);
         i++;
         }
         Label13->Caption=IntToStr(k1.wynik);
         if(k1.wynik>=21)
         {
                Button23->Visible=true;
         }
         else {
                Button20->Visible=true;
         }
}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
Label8->Caption=IntToStr(g1.waluta);
g1.wynik=0; k1.wynik=0;
g1.karty[0]=0;
g1.karty[1]=0;
g1.karty[2]=0;
g1.karty[3]=0;
g1.karty[4]=0;
k1.karty[0]=0;
k1.karty[1]=0;
k1.karty[2]=0;
k1.karty[3]=0;
k1.karty[4]=0;
Button2->Visible=true;
Button4->Visible=true;
Button21->Visible=true;
Button5->Visible=false;
Button6->Visible=false;
Button9->Visible=false;
Button10->Visible=false;
Button11->Visible=false;
Button12->Visible=false;
Button13->Visible=false;
Button14->Visible=false;
Button15->Visible=false;
Button16->Visible=false;
Button17->Visible=false;
Button18->Visible=false;
g1.wynik=0;
Form1->Image1->Picture->LoadFromFile("img/rewers.jpg" );
Image2->Picture->LoadFromFile("img/rewers.jpg" );
Image3->Picture->LoadFromFile("img/rewers.jpg" );
Image4->Picture->LoadFromFile("img/rewers.jpg" );
Image5->Picture->LoadFromFile("img/rewers.jpg" );
Form1->Image6->Picture->LoadFromFile("img/rewers.jpg" );
Form1->Image7->Picture->LoadFromFile("img/rewers.jpg" );
Form1->Image8->Picture->LoadFromFile("img/rewers.jpg" );
Form1->Image9->Picture->LoadFromFile("img/rewers.jpg" );
Form1->Image10->Picture->LoadFromFile("img/rewers.jpg" );
     srand(time(NULL));
     g1.karty[0]=rand()%51+1;
     g1.karty[1]=rand()%51+1;
     do{
     g1.karty[1]=rand()%51+1;}while(g1.karty[1] == g1.karty[0]);


switch(g1.karty[0])
{
        case 1: {Image4->Picture->LoadFromFile("img/2_1.jpg" ); g1.wynik+=2;} break;
        case 2: {Image4->Picture->LoadFromFile("img/2_2.jpg" ); g1.wynik+=2;} break;
        case 3: {Image4->Picture->LoadFromFile("img/2_3.jpg" ); g1.wynik+=2;} break;
        case 4: {Image4->Picture->LoadFromFile("img/2_4.jpg" ); g1.wynik+=2;} break;
        case 5: {Image4->Picture->LoadFromFile("img/3_1.jpg" ); g1.wynik+=3;} break;
        case 6: {Image4->Picture->LoadFromFile("img/3_2.jpg" ); g1.wynik+=3;} break;
        case 7: {Image4->Picture->LoadFromFile("img/3_3.jpg" ); g1.wynik+=3;} break;
        case 8: {Image4->Picture->LoadFromFile("img/3_4.jpg" ); g1.wynik+=3;} break;
        case 9: {Image4->Picture->LoadFromFile("img/4_1.jpg" ); g1.wynik+=4;} break;
        case 10: {Image4->Picture->LoadFromFile("img/4_2.jpg" ); g1.wynik+=4;} break;
        case 11: {Image4->Picture->LoadFromFile("img/4_3.jpg" ); g1.wynik+=4;} break;
        case 12: {Image4->Picture->LoadFromFile("img/4_4.jpg" ); g1.wynik+=4;} break;
        case 13: {Image4->Picture->LoadFromFile("img/5_1.jpg" ); g1.wynik+=5;} break;
        case 14: {Image4->Picture->LoadFromFile("img/5_2.jpg" ); g1.wynik+=5;} break;
        case 15: {Image4->Picture->LoadFromFile("img/5_3.jpg" ); g1.wynik+=5;} break;
        case 16: {Image4->Picture->LoadFromFile("img/5_4.jpg" ); g1.wynik+=5;} break;
        case 17: {Image4->Picture->LoadFromFile("img/6_1.jpg" ); g1.wynik+=6;} break;
        case 18: {Image4->Picture->LoadFromFile("img/6_2.jpg" ); g1.wynik+=6;} break;
        case 19: {Image4->Picture->LoadFromFile("img/6_1.jpg" ); g1.wynik+=6;} break;
        case 20: {Image4->Picture->LoadFromFile("img/6_2.jpg" ); g1.wynik+=6;} break;
        case 21: {Image4->Picture->LoadFromFile("img/7_3.jpg" ); g1.wynik+=7;} break;
        case 22: {Image4->Picture->LoadFromFile("img/7_4.jpg" ); g1.wynik+=7;} break;
        case 23: {Image4->Picture->LoadFromFile("img/7_1.jpg" ); g1.wynik+=7;} break;
        case 24: {Image4->Picture->LoadFromFile("img/7_2.jpg" ); g1.wynik+=7;} break;
        case 25: {Image4->Picture->LoadFromFile("img/8_3.jpg" ); g1.wynik+=8;} break;
        case 26: {Image4->Picture->LoadFromFile("img/8_4.jpg" ); g1.wynik+=8;} break;
        case 27: {Image4->Picture->LoadFromFile("img/8_1.jpg" ); g1.wynik+=8;} break;
        case 28: {Image4->Picture->LoadFromFile("img/8_2.jpg" ); g1.wynik+=8;} break;
        case 29: {Image4->Picture->LoadFromFile("img/9_1.jpg" ); g1.wynik+=9;} break;
        case 30: {Image4->Picture->LoadFromFile("img/9_2.jpg" ); g1.wynik+=9;} break;
        case 31: {Image4->Picture->LoadFromFile("img/9_3.jpg" ); g1.wynik+=9;} break;
        case 32: {Image4->Picture->LoadFromFile("img/9_4.jpg" ); g1.wynik+=9;} break;
        case 33: {Image4->Picture->LoadFromFile("img/10_1.jpg" ); g1.wynik+=10;} break;
        case 34: {Image4->Picture->LoadFromFile("img/10_2.jpg" ); g1.wynik+=10;} break;
        case 35: {Image4->Picture->LoadFromFile("img/10_3.jpg" ); g1.wynik+=10;} break;
        case 36: {Image4->Picture->LoadFromFile("img/10_4.jpg" ); g1.wynik+=10;} break;
        case 37: {Image4->Picture->LoadFromFile("img/J_1.jpg" ); g1.wynik+=10;} break;
        case 38: {Image4->Picture->LoadFromFile("img/J_2.jpg" ); g1.wynik+=10;} break;
        case 39: {Image4->Picture->LoadFromFile("img/J_3.jpg" ); g1.wynik+=10;} break;
        case 40: {Image4->Picture->LoadFromFile("img/J_4.jpg" ); g1.wynik+=10;} break;
        case 41: {Image4->Picture->LoadFromFile("img/Q_1.jpg" ); g1.wynik+=10;} break;
        case 42: {Image4->Picture->LoadFromFile("img/Q_2.jpg" ); g1.wynik+=10;} break;
        case 43: {Image4->Picture->LoadFromFile("img/Q_3.jpg" ); g1.wynik+=10;} break;
        case 44: {Image4->Picture->LoadFromFile("img/Q_4.jpg" ); g1.wynik+=10;} break;
        case 45: {Image4->Picture->LoadFromFile("img/K_1.jpg" ); g1.wynik+=10;} break;
        case 46: {Image4->Picture->LoadFromFile("img/K_2.jpg" ); g1.wynik+=10;} break;
        case 47: {Image4->Picture->LoadFromFile("img/K_3.jpg" ); g1.wynik+=10;} break;
        case 48: {Image4->Picture->LoadFromFile("img/K_4.jpg" ); g1.wynik+=10;} break;
        case 49: {Image4->Picture->LoadFromFile("img/A_1.jpg" ); Label5->Visible=true; Button9->Visible=true; Button10->Visible=true;} break;
        case 50: {Image4->Picture->LoadFromFile("img/A_2.jpg" ); Label5->Visible=true; Button9->Visible=true; Button10->Visible=true;} break;
        case 51: {Image4->Picture->LoadFromFile("img/A_3.jpg" ); Label5->Visible=true; Button9->Visible=true; Button10->Visible=true;} break;
        case 52: {Image4->Picture->LoadFromFile("img/A_4.jpg" ); Label5->Visible=true; Button9->Visible=true; Button10->Visible=true;} break;
        }
switch(g1.karty[1])
{
        case 1: {Image5->Picture->LoadFromFile("img/2_1.jpg" ); g1.wynik+=2;} break;
        case 2: {Image5->Picture->LoadFromFile("img/2_2.jpg" ); g1.wynik+=2;} break;
        case 3: {Image5->Picture->LoadFromFile("img/2_3.jpg" ); g1.wynik+=2;} break;
        case 4: {Image5->Picture->LoadFromFile("img/2_4.jpg" ); g1.wynik+=2;} break;
        case 5: {Image5->Picture->LoadFromFile("img/3_1.jpg" ); g1.wynik+=3;} break;
        case 6: {Image5->Picture->LoadFromFile("img/3_2.jpg" ); g1.wynik+=3;} break;
        case 7: {Image5->Picture->LoadFromFile("img/3_3.jpg" ); g1.wynik+=3;} break;
        case 8: {Image5->Picture->LoadFromFile("img/3_4.jpg" ); g1.wynik+=3;} break;
        case 9: {Image5->Picture->LoadFromFile("img/4_1.jpg" ); g1.wynik+=4;} break;
        case 10: {Image5->Picture->LoadFromFile("img/4_2.jpg" ); g1.wynik+=4;} break;
        case 11: {Image5->Picture->LoadFromFile("img/4_3.jpg" ); g1.wynik+=4;} break;
        case 12: {Image5->Picture->LoadFromFile("img/4_4.jpg" ); g1.wynik+=4;} break;
        case 13: {Image5->Picture->LoadFromFile("img/5_1.jpg" ); g1.wynik+=5;} break;
        case 14: {Image5->Picture->LoadFromFile("img/5_2.jpg" ); g1.wynik+=5;} break;
        case 15: {Image5->Picture->LoadFromFile("img/5_3.jpg" ); g1.wynik+=5;} break;
        case 16: {Image5->Picture->LoadFromFile("img/5_4.jpg" ); g1.wynik+=5;} break;
        case 17: {Image5->Picture->LoadFromFile("img/6_1.jpg" ); g1.wynik+=6;} break;
        case 18: {Image5->Picture->LoadFromFile("img/6_2.jpg" ); g1.wynik+=6;} break;
        case 19: {Image5->Picture->LoadFromFile("img/6_3.jpg" ); g1.wynik+=6;} break;
        case 20: {Image5->Picture->LoadFromFile("img/6_4.jpg" ); g1.wynik+=6;} break;
        case 21: {Image5->Picture->LoadFromFile("img/7_3.jpg" ); g1.wynik+=7;} break;
        case 22: {Image5->Picture->LoadFromFile("img/7_4.jpg" ); g1.wynik+=7;} break;
        case 23: {Image5->Picture->LoadFromFile("img/7_1.jpg" ); g1.wynik+=7;} break;
        case 24: {Image5->Picture->LoadFromFile("img/7_2.jpg" ); g1.wynik+=7;} break;
        case 25: {Image5->Picture->LoadFromFile("img/8_3.jpg" ); g1.wynik+=8;} break;
        case 26: {Image5->Picture->LoadFromFile("img/8_4.jpg" ); g1.wynik+=8;} break;
        case 27: {Image5->Picture->LoadFromFile("img/8_1.jpg" ); g1.wynik+=8;} break;
        case 28: {Image5->Picture->LoadFromFile("img/8_2.jpg" ); g1.wynik+=8;} break;
        case 29: {Image5->Picture->LoadFromFile("img/9_1.jpg" ); g1.wynik+=9;} break;
        case 30: {Image5->Picture->LoadFromFile("img/9_2.jpg" ); g1.wynik+=9;} break;
        case 31: {Image5->Picture->LoadFromFile("img/9_3.jpg" ); g1.wynik+=9;} break;
        case 32: {Image5->Picture->LoadFromFile("img/9_4.jpg" ); g1.wynik+=9;} break;
        case 33: {Image5->Picture->LoadFromFile("img/10_1.jpg" ); g1.wynik+=10;} break;
        case 34: {Image5->Picture->LoadFromFile("img/10_2.jpg" ); g1.wynik+=10;} break;
        case 35: {Image5->Picture->LoadFromFile("img/10_3.jpg" ); g1.wynik+=10;} break;
        case 36: {Image5->Picture->LoadFromFile("img/10_4.jpg" ); g1.wynik+=10;} break;
        case 37: {Image5->Picture->LoadFromFile("img/J_1.jpg" ); g1.wynik+=10;} break;
        case 38: {Image5->Picture->LoadFromFile("img/J_2.jpg" ); g1.wynik+=10;} break;
        case 39: {Image5->Picture->LoadFromFile("img/J_3.jpg" ); g1.wynik+=10;} break;
        case 40: {Image5->Picture->LoadFromFile("img/J_4.jpg" ); g1.wynik+=10;} break;
        case 41: {Image5->Picture->LoadFromFile("img/Q_1.jpg" ); g1.wynik+=10;} break;
        case 42: {Image5->Picture->LoadFromFile("img/Q_2.jpg" ); g1.wynik+=10;} break;
        case 43: {Image5->Picture->LoadFromFile("img/Q_3.jpg" ); g1.wynik+=10;} break;
        case 44: {Image5->Picture->LoadFromFile("img/Q_4.jpg" ); g1.wynik+=10;} break;
        case 45: {Image5->Picture->LoadFromFile("img/K_1.jpg" ); g1.wynik+=10;} break;
        case 46: {Image5->Picture->LoadFromFile("img/K_2.jpg" ); g1.wynik+=10;} break;
        case 47: {Image5->Picture->LoadFromFile("img/K_3.jpg" ); g1.wynik+=10;} break;
        case 48: {Image5->Picture->LoadFromFile("img/K_4.jpg" ); g1.wynik+=10;} break;
        case 49: {Image5->Picture->LoadFromFile("img/A_1.jpg" ); Label5->Visible=true; Button11->Visible=true; Button12->Visible=true;} break;
        case 50: {Image5->Picture->LoadFromFile("img/A_2.jpg" ); Label5->Visible=true; Button11->Visible=true; Button12->Visible=true;} break;
        case 51: {Image5->Picture->LoadFromFile("img/A_3.jpg" ); Label5->Visible=true; Button11->Visible=true; Button12->Visible=true;} break;
        case 52: {Image5->Picture->LoadFromFile("img/A_4.jpg" ); Label5->Visible=true; Button11->Visible=true; Button12->Visible=true;} break;
        }


Label4->Caption=IntToStr(g1.wynik);
Button7->Visible=false;
Button8->Visible=false;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button4Click(TObject *Sender)
{
 g1.opusc_gre();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button9Click(TObject *Sender)
{
g1.wynik+=1;
Label5->Visible=false; Button9->Visible=false; Button10->Visible=false;
Label4->Caption=IntToStr(g1.wynik);
if(g1.wynik==21){Button8->Visible=true; g1.waluta+=500;}
Label8->Caption=IntToStr(g1.waluta);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button10Click(TObject *Sender)
{
  g1.wynik+=11;
Label5->Visible=false; Button9->Visible=false; Button10->Visible=false;
Label4->Caption=IntToStr(g1.wynik);
if(g1.wynik==21){Button8->Visible=true; g1.waluta+=500;}
if(g1.wynik>21){Button7->Visible=true; g1.waluta-=100;}
Label8->Caption=IntToStr(g1.waluta);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button11Click(TObject *Sender)
{
   g1.wynik+=1;
Label5->Visible=false; Button11->Visible=false; Button12->Visible=false;
Label4->Caption=IntToStr(g1.wynik);
if(g1.wynik==21){Button8->Visible=true; g1.waluta+=500;}
Label8->Caption=IntToStr(g1.waluta);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button12Click(TObject *Sender)
{
 g1.wynik+=11;
Label5->Visible=false; Button11->Visible=false; Button12->Visible=false;
Label4->Caption=IntToStr(g1.wynik);
if(g1.wynik==21){Button8->Visible=true; g1.waluta+=500;}
if(g1.wynik>21){Button7->Visible=true; g1.waluta-=100;}
Label8->Caption=IntToStr(g1.waluta);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button13Click(TObject *Sender)
{
 g1.wynik+=1;
Label5->Visible=false; Button13->Visible=false; Button14->Visible=false;
Label4->Caption=IntToStr(g1.wynik);
if(g1.wynik==21){Button8->Visible=true; g1.waluta+=500;}
Label8->Caption=IntToStr(g1.waluta);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button14Click(TObject *Sender)
{
  g1.wynik+=11;
Label5->Visible=false; Button13->Visible=false; Button14->Visible=false;
Label4->Caption=IntToStr(g1.wynik);
if(g1.wynik==21){Button8->Visible=true; g1.waluta+=500;}
if(g1.wynik>21){Button7->Visible=true; g1.waluta-=100;}
Label8->Caption=IntToStr(g1.waluta);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button15Click(TObject *Sender)
{
g1.wynik+=1;
Label5->Visible=false; Button15->Visible=false; Button16->Visible=false;
Label4->Caption=IntToStr(g1.wynik);
if(g1.wynik==21){Button8->Visible=true; g1.waluta+=500;}
Label8->Caption=IntToStr(g1.waluta);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button16Click(TObject *Sender)
{
g1.wynik+=11;
Label5->Visible=false; Button15->Visible=false; Button16->Visible=false;
Label4->Caption=IntToStr(g1.wynik);
if(g1.wynik==21){Button8->Visible=true; g1.waluta+=500;}
if(g1.wynik>21){Button7->Visible=true; g1.waluta-=100;}
Label8->Caption=IntToStr(g1.waluta);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button17Click(TObject *Sender)
{
g1.wynik+=1;
Label5->Visible=false; Button18->Visible=false; Button17->Visible=false;
Label4->Caption=IntToStr(g1.wynik);
if(g1.wynik==21){Button8->Visible=true; g1.waluta+=500;}
Label8->Caption=IntToStr(g1.waluta);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button18Click(TObject *Sender)
{
g1.wynik+=11;
Label5->Visible=false; Button17->Visible=false; Button17->Visible=false;
Label4->Caption=IntToStr(g1.wynik);
if(g1.wynik==21){Button8->Visible=true; g1.waluta+=500;}
if(g1.wynik>21){Button7->Visible=true; g1.waluta-=100;}
Label8->Caption=IntToStr(g1.waluta);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button19Click(TObject *Sender)
{
Gui.login();

}
//---------------------------------------------------------------------------


//----------------------------------Gra Krupiera-----------------------------
   void graKrupiera(TObject *Sender)
  {

          //Button21Click(Sender);


        }

//---------------------------------------------------------------------------









void __fastcall TForm1::Button20Click(TObject *Sender)
{
Label8->Caption=IntToStr(g1.waluta);
g1.wynik=0; k1.wynik=0;
Label13->Caption=IntToStr(k1.wynik);
g1.karty[0]=0;
g1.karty[1]=0;
g1.karty[2]=0;
g1.karty[3]=0;
g1.karty[4]=0;
k1.karty[0]=0;
k1.karty[1]=0;
k1.karty[2]=0;
k1.karty[3]=0;
k1.karty[4]=0;
Button2->Visible=true;
Button4->Visible=true;
Button21->Visible=true;
Button5->Visible=false;
Button20->Visible=false;
Button23->Visible=false;
Button6->Visible=false;
Button9->Visible=false;
Button10->Visible=false;
Button11->Visible=false;
Button12->Visible=false;
Button13->Visible=false;
Button14->Visible=false;
Button15->Visible=false;
Button16->Visible=false;
Button17->Visible=false;
Button18->Visible=false;
g1.wynik=0;
Form1->Image1->Picture->LoadFromFile("img/rewers.jpg" );
Image2->Picture->LoadFromFile("img/rewers.jpg" );
Image3->Picture->LoadFromFile("img/rewers.jpg" );
Image4->Picture->LoadFromFile("img/rewers.jpg" );
Image5->Picture->LoadFromFile("img/rewers.jpg" );
Form1->Image6->Picture->LoadFromFile("img/rewers.jpg" );
Form1->Image7->Picture->LoadFromFile("img/rewers.jpg" );
Form1->Image8->Picture->LoadFromFile("img/rewers.jpg" );
Form1->Image9->Picture->LoadFromFile("img/rewers.jpg" );
Form1->Image10->Picture->LoadFromFile("img/rewers.jpg" );
     srand(time(NULL));
     g1.karty[0]=rand()%51+1;
     g1.karty[1]=rand()%51+1;
     do{
     g1.karty[1]=rand()%51+1;}while(g1.karty[1] == g1.karty[0]);


switch(g1.karty[0])
{
        case 1: {Image4->Picture->LoadFromFile("img/2_1.jpg" ); g1.wynik+=2;} break;
        case 2: {Image4->Picture->LoadFromFile("img/2_2.jpg" ); g1.wynik+=2;} break;
        case 3: {Image4->Picture->LoadFromFile("img/2_3.jpg" ); g1.wynik+=2;} break;
        case 4: {Image4->Picture->LoadFromFile("img/2_4.jpg" ); g1.wynik+=2;} break;
        case 5: {Image4->Picture->LoadFromFile("img/3_1.jpg" ); g1.wynik+=3;} break;
        case 6: {Image4->Picture->LoadFromFile("img/3_2.jpg" ); g1.wynik+=3;} break;
        case 7: {Image4->Picture->LoadFromFile("img/3_3.jpg" ); g1.wynik+=3;} break;
        case 8: {Image4->Picture->LoadFromFile("img/3_4.jpg" ); g1.wynik+=3;} break;
        case 9: {Image4->Picture->LoadFromFile("img/4_1.jpg" ); g1.wynik+=4;} break;
        case 10: {Image4->Picture->LoadFromFile("img/4_2.jpg" ); g1.wynik+=4;} break;
        case 11: {Image4->Picture->LoadFromFile("img/4_3.jpg" ); g1.wynik+=4;} break;
        case 12: {Image4->Picture->LoadFromFile("img/4_4.jpg" ); g1.wynik+=4;} break;
        case 13: {Image4->Picture->LoadFromFile("img/5_1.jpg" ); g1.wynik+=5;} break;
        case 14: {Image4->Picture->LoadFromFile("img/5_2.jpg" ); g1.wynik+=5;} break;
        case 15: {Image4->Picture->LoadFromFile("img/5_3.jpg" ); g1.wynik+=5;} break;
        case 16: {Image4->Picture->LoadFromFile("img/5_4.jpg" ); g1.wynik+=5;} break;
        case 17: {Image4->Picture->LoadFromFile("img/6_1.jpg" ); g1.wynik+=6;} break;
        case 18: {Image4->Picture->LoadFromFile("img/6_2.jpg" ); g1.wynik+=6;} break;
        case 19: {Image4->Picture->LoadFromFile("img/6_1.jpg" ); g1.wynik+=6;} break;
        case 20: {Image4->Picture->LoadFromFile("img/6_2.jpg" ); g1.wynik+=6;} break;
        case 21: {Image4->Picture->LoadFromFile("img/7_3.jpg" ); g1.wynik+=7;} break;
        case 22: {Image4->Picture->LoadFromFile("img/7_4.jpg" ); g1.wynik+=7;} break;
        case 23: {Image4->Picture->LoadFromFile("img/7_1.jpg" ); g1.wynik+=7;} break;
        case 24: {Image4->Picture->LoadFromFile("img/7_2.jpg" ); g1.wynik+=7;} break;
        case 25: {Image4->Picture->LoadFromFile("img/8_3.jpg" ); g1.wynik+=8;} break;
        case 26: {Image4->Picture->LoadFromFile("img/8_4.jpg" ); g1.wynik+=8;} break;
        case 27: {Image4->Picture->LoadFromFile("img/8_1.jpg" ); g1.wynik+=8;} break;
        case 28: {Image4->Picture->LoadFromFile("img/8_2.jpg" ); g1.wynik+=8;} break;
        case 29: {Image4->Picture->LoadFromFile("img/9_1.jpg" ); g1.wynik+=9;} break;
        case 30: {Image4->Picture->LoadFromFile("img/9_2.jpg" ); g1.wynik+=9;} break;
        case 31: {Image4->Picture->LoadFromFile("img/9_3.jpg" ); g1.wynik+=9;} break;
        case 32: {Image4->Picture->LoadFromFile("img/9_4.jpg" ); g1.wynik+=9;} break;
        case 33: {Image4->Picture->LoadFromFile("img/10_1.jpg" ); g1.wynik+=10;} break;
        case 34: {Image4->Picture->LoadFromFile("img/10_2.jpg" ); g1.wynik+=10;} break;
        case 35: {Image4->Picture->LoadFromFile("img/10_3.jpg" ); g1.wynik+=10;} break;
        case 36: {Image4->Picture->LoadFromFile("img/10_4.jpg" ); g1.wynik+=10;} break;
        case 37: {Image4->Picture->LoadFromFile("img/J_1.jpg" ); g1.wynik+=10;} break;
        case 38: {Image4->Picture->LoadFromFile("img/J_2.jpg" ); g1.wynik+=10;} break;
        case 39: {Image4->Picture->LoadFromFile("img/J_3.jpg" ); g1.wynik+=10;} break;
        case 40: {Image4->Picture->LoadFromFile("img/J_4.jpg" ); g1.wynik+=10;} break;
        case 41: {Image4->Picture->LoadFromFile("img/Q_1.jpg" ); g1.wynik+=10;} break;
        case 42: {Image4->Picture->LoadFromFile("img/Q_2.jpg" ); g1.wynik+=10;} break;
        case 43: {Image4->Picture->LoadFromFile("img/Q_3.jpg" ); g1.wynik+=10;} break;
        case 44: {Image4->Picture->LoadFromFile("img/Q_4.jpg" ); g1.wynik+=10;} break;
        case 45: {Image4->Picture->LoadFromFile("img/K_1.jpg" ); g1.wynik+=10;} break;
        case 46: {Image4->Picture->LoadFromFile("img/K_2.jpg" ); g1.wynik+=10;} break;
        case 47: {Image4->Picture->LoadFromFile("img/K_3.jpg" ); g1.wynik+=10;} break;
        case 48: {Image4->Picture->LoadFromFile("img/K_4.jpg" ); g1.wynik+=10;} break;
        case 49: {Image4->Picture->LoadFromFile("img/A_1.jpg" ); Label5->Visible=true; Button9->Visible=true; Button10->Visible=true;} break;
        case 50: {Image4->Picture->LoadFromFile("img/A_2.jpg" ); Label5->Visible=true; Button9->Visible=true; Button10->Visible=true;} break;
        case 51: {Image4->Picture->LoadFromFile("img/A_3.jpg" ); Label5->Visible=true; Button9->Visible=true; Button10->Visible=true;} break;
        case 52: {Image4->Picture->LoadFromFile("img/A_4.jpg" ); Label5->Visible=true; Button9->Visible=true; Button10->Visible=true;} break;
        }
switch(g1.karty[1])
{
        case 1: {Image5->Picture->LoadFromFile("img/2_1.jpg" ); g1.wynik+=2;} break;
        case 2: {Image5->Picture->LoadFromFile("img/2_2.jpg" ); g1.wynik+=2;} break;
        case 3: {Image5->Picture->LoadFromFile("img/2_3.jpg" ); g1.wynik+=2;} break;
        case 4: {Image5->Picture->LoadFromFile("img/2_4.jpg" ); g1.wynik+=2;} break;
        case 5: {Image5->Picture->LoadFromFile("img/3_1.jpg" ); g1.wynik+=3;} break;
        case 6: {Image5->Picture->LoadFromFile("img/3_2.jpg" ); g1.wynik+=3;} break;
        case 7: {Image5->Picture->LoadFromFile("img/3_3.jpg" ); g1.wynik+=3;} break;
        case 8: {Image5->Picture->LoadFromFile("img/3_4.jpg" ); g1.wynik+=3;} break;
        case 9: {Image5->Picture->LoadFromFile("img/4_1.jpg" ); g1.wynik+=4;} break;
        case 10: {Image5->Picture->LoadFromFile("img/4_2.jpg" ); g1.wynik+=4;} break;
        case 11: {Image5->Picture->LoadFromFile("img/4_3.jpg" ); g1.wynik+=4;} break;
        case 12: {Image5->Picture->LoadFromFile("img/4_4.jpg" ); g1.wynik+=4;} break;
        case 13: {Image5->Picture->LoadFromFile("img/5_1.jpg" ); g1.wynik+=5;} break;
        case 14: {Image5->Picture->LoadFromFile("img/5_2.jpg" ); g1.wynik+=5;} break;
        case 15: {Image5->Picture->LoadFromFile("img/5_3.jpg" ); g1.wynik+=5;} break;
        case 16: {Image5->Picture->LoadFromFile("img/5_4.jpg" ); g1.wynik+=5;} break;
        case 17: {Image5->Picture->LoadFromFile("img/6_1.jpg" ); g1.wynik+=6;} break;
        case 18: {Image5->Picture->LoadFromFile("img/6_2.jpg" ); g1.wynik+=6;} break;
        case 19: {Image5->Picture->LoadFromFile("img/6_3.jpg" ); g1.wynik+=6;} break;
        case 20: {Image5->Picture->LoadFromFile("img/6_4.jpg" ); g1.wynik+=6;} break;
        case 21: {Image5->Picture->LoadFromFile("img/7_3.jpg" ); g1.wynik+=7;} break;
        case 22: {Image5->Picture->LoadFromFile("img/7_4.jpg" ); g1.wynik+=7;} break;
        case 23: {Image5->Picture->LoadFromFile("img/7_1.jpg" ); g1.wynik+=7;} break;
        case 24: {Image5->Picture->LoadFromFile("img/7_2.jpg" ); g1.wynik+=7;} break;
        case 25: {Image5->Picture->LoadFromFile("img/8_3.jpg" ); g1.wynik+=8;} break;
        case 26: {Image5->Picture->LoadFromFile("img/8_4.jpg" ); g1.wynik+=8;} break;
        case 27: {Image5->Picture->LoadFromFile("img/8_1.jpg" ); g1.wynik+=8;} break;
        case 28: {Image5->Picture->LoadFromFile("img/8_2.jpg" ); g1.wynik+=8;} break;
        case 29: {Image5->Picture->LoadFromFile("img/9_1.jpg" ); g1.wynik+=9;} break;
        case 30: {Image5->Picture->LoadFromFile("img/9_2.jpg" ); g1.wynik+=9;} break;
        case 31: {Image5->Picture->LoadFromFile("img/9_3.jpg" ); g1.wynik+=9;} break;
        case 32: {Image5->Picture->LoadFromFile("img/9_4.jpg" ); g1.wynik+=9;} break;
        case 33: {Image5->Picture->LoadFromFile("img/10_1.jpg" ); g1.wynik+=10;} break;
        case 34: {Image5->Picture->LoadFromFile("img/10_2.jpg" ); g1.wynik+=10;} break;
        case 35: {Image5->Picture->LoadFromFile("img/10_3.jpg" ); g1.wynik+=10;} break;
        case 36: {Image5->Picture->LoadFromFile("img/10_4.jpg" ); g1.wynik+=10;} break;
        case 37: {Image5->Picture->LoadFromFile("img/J_1.jpg" ); g1.wynik+=10;} break;
        case 38: {Image5->Picture->LoadFromFile("img/J_2.jpg" ); g1.wynik+=10;} break;
        case 39: {Image5->Picture->LoadFromFile("img/J_3.jpg" ); g1.wynik+=10;} break;
        case 40: {Image5->Picture->LoadFromFile("img/J_4.jpg" ); g1.wynik+=10;} break;
        case 41: {Image5->Picture->LoadFromFile("img/Q_1.jpg" ); g1.wynik+=10;} break;
        case 42: {Image5->Picture->LoadFromFile("img/Q_2.jpg" ); g1.wynik+=10;} break;
        case 43: {Image5->Picture->LoadFromFile("img/Q_3.jpg" ); g1.wynik+=10;} break;
        case 44: {Image5->Picture->LoadFromFile("img/Q_4.jpg" ); g1.wynik+=10;} break;
        case 45: {Image5->Picture->LoadFromFile("img/K_1.jpg" ); g1.wynik+=10;} break;
        case 46: {Image5->Picture->LoadFromFile("img/K_2.jpg" ); g1.wynik+=10;} break;
        case 47: {Image5->Picture->LoadFromFile("img/K_3.jpg" ); g1.wynik+=10;} break;
        case 48: {Image5->Picture->LoadFromFile("img/K_4.jpg" ); g1.wynik+=10;} break;
        case 49: {Image5->Picture->LoadFromFile("img/A_1.jpg" ); Label5->Visible=true; Button11->Visible=true; Button12->Visible=true;} break;
        case 50: {Image5->Picture->LoadFromFile("img/A_2.jpg" ); Label5->Visible=true; Button11->Visible=true; Button12->Visible=true;} break;
        case 51: {Image5->Picture->LoadFromFile("img/A_3.jpg" ); Label5->Visible=true; Button11->Visible=true; Button12->Visible=true;} break;
        case 52: {Image5->Picture->LoadFromFile("img/A_4.jpg" ); Label5->Visible=true; Button11->Visible=true; Button12->Visible=true;} break;
        }


Label4->Caption=IntToStr(g1.wynik);
Button7->Visible=false;
Button8->Visible=false;
}
//---------------------------------------------------------------------------




void __fastcall TForm1::Button2Click(TObject *Sender)
{
 g1.dobierz_karte();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button21Click(TObject *Sender)
{
             g1.przestan_dobierac();
}
//---------------------------------------------------------------------------

