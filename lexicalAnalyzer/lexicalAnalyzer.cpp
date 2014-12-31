// lexicalAnalyzer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>
#include <iomanip>
#include <regex>
#include <algorithm>
using namespace std;


int i= 0,j=0,ii,jj;
	string iff[50],lbb[50],opp[50];
	ifstream ifs("file.txt");
	ifstream lb("lab.txt");
	ifstream op("op.txt");
	bool check = true;
	bool c = false;
	//-------------------------------------FUNC=============
	


bool in_quote(const std::string& cont, const std::string& s)
{
    return std::search(cont.begin(), cont.end(), s.begin(), s.end()) != cont.end();
}
void _tmain(int argc, _TCHAR* argv[])
{
	cout<<setw(40)<<"**********************************************************"<<endl;
	cout <<setw(20)<<"LEXIMEZS"<<setw(20)<< "TOKENS"<<endl;
	cout<<setw(40)<<"**********************************************************"<<endl;
	if (ifs.is_open() && lb.is_open() && op.is_open()) {
		smatch m;
		regex e ("int");
    // print file:
			while(check!=false){
					
					
		
					
							   //--------------------------------------
							for(i = 0 ; i < 50 ; i++){getline(ifs,iff[i]); c=false; regex_search ( iff[i], m, e );
								for(j = 0 ; j < 50 ; j++){getline(lb,lbb[j]);
									 if (in_quote(iff[i], lbb[j]) && lbb[j]!=""){cout <<setw(20)<<lbb[j]<<setw(30)<< "keyword (found)"<<endl;c=true;}
								}
								//FOR OPERATORS
								for(j = 0 ; j < 50 ; j++){getline(op,opp[j]);
								if (in_quote(iff[i], opp[j]) && opp[j]!=""){cout <<setw(20)<<opp[j]<<setw(30)<< "Operator (found)"<<endl;c=true;}
								}
								if(in_quote(iff[i], "**")){check=false;}
								//--------------------REGEX
								


								if(!c && iff[i]!=""){cout <<setw(20)<<iff[i]<<setw(30)<< "Undefined on line["<<i+1<<"]"<<endl;}
						}
							if (m.ready() ) {cout <<setw(20)<<m.suffix()<<setw(30)<< "Identifier(s)/Variables"<<endl;}
									
									  
							
							//====----------------------------------------
							
							
							
			}
  }
  else {
    // show message:
    std::cout << "Error opening file";
  }
 
	getch();
}

