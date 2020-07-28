#include <iostream>
#include <conio.h>
#include <string>
#include <vector>
#include <fstream> 
#include <time.h>
#include<Windows.h>
using namespace std;
void print_massege(string massege,bool top=true,bool buttom=true){
	if(top){cout<<"+------------------+"<<endl;}
	cout<<"|";
	bool front=true;
	for(int i=massege.length();i<18;i++)
	{
	if (front==true){massege=" "+massege;} 
	else{ massege=massege+" ";}
	
	front=!front;
	}
	cout<<massege.c_str();
	cout<<"|"<< endl;
	
	if(buttom) { cout<<"+------------------+"<<endl;}
}
void print_hangman(int guesscount=0){
	if(guesscount>=1)	print_massege("|",false,false);
	if(guesscount>=2)	print_massege("|",false,false);
	if(guesscount>=3)	print_massege("0",false,false);
	if(guesscount==4)	print_massege("/",false,false);
	if(guesscount==5)	print_massege("|",false,false);
	if(guesscount>=6)	print_massege("/|\\",false,false);
	if(guesscount>=7)	print_massege("|",false,false);
	if(guesscount==8)	print_massege("/",false,false);
	if(guesscount>=9)	print_massege("/ \\",false,false);
}
void printletters(string gussed,char from,char to){
string s;
for(char i=from;i<=to;i++){
	if(gussed.find(i)==string::npos){
	s+=i;
	s+=" ";
	}else s+="  ";
 }
	print_massege(s,false,false);
}
void printremaningletters(string taken){
	printletters(taken,'A','F');
	printletters(taken,'G','L');
	printletters(taken,'M','R');
	printletters(taken,'S','W');
	printletters(taken,'X','Z');
}
bool placeholder(string word,string guessed){
   string s;
   for(int i=0;i<word.length();i++){
	   if(guessed.find(word[i])==string::npos){
	   s+="_";
	   }
	   else{s+=word[i];}
   }
   print_massege(s,false);
   if(word==s)return true;
   else return false;
}
string loadrandomword(string path){

int linenum=0;
vector<string> v;
string s;
ifstream read(path);
if(read.is_open())
{while (std::getline(read,s)){
	v.push_back(s);}
int x=rand()%v.size();
s=v[x];
}
read.close();
return s;
}
int triesleft(string word,string guessed){
int error=0;
for(int i=0;i<guessed.length();i++){
	if(word.find(guessed[i]==string::npos))
		error++;
}
return error;
}

int main(){
	srand(time(0));
	 string wordtoguess=loadrandomword("reader.txt");
	int tries=0;
	bool win=false;
	string guesses;
	do
	{   system("cls");
		print_massege("HANG MAN",true,true);
		print_massege("",false,false);
		print_massege("",false,false);
		print_hangman(tries);
		print_massege("",false,false);
		print_massege("",false,false);
		print_massege("available letters",true,true);
		printremaningletters(guesses);
		print_massege("guess word",true,true);
	win=placeholder(wordtoguess,guesses);
	   if(win)break;
		char x;
		cout<<">";
		cin>>x;
		if(guesses.find(x)==string::npos)guesses+=x;
		tries=triesleft(wordtoguess,guesses);
	}while(tries<10&&win==false);
	if (win==true){print_massege("you win");}
	  else   {print_massege("you lose");}
	
		getchar();
system("pause");
return 0;
} 