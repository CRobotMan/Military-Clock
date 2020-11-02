#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int Get_IndexOfChar(string text, char chrToSearch)
{
	for(int x = 0; x < text.length(); x++)
	{
		if(text[x] == chrToSearch)
		{
			return x;
		}
	}
	
	return -1;
}

bool Get_AM_PM_String(string text, int* hour, int* min)
{
	int indexOf_Colons = Get_IndexOfChar(text, ':');
	
	if(indexOf_Colons < 0 || indexOf_Colons > 2) 
	{
		return false;
	}
	
	char temp_Hour[3];
	char temp_Min[3];
	
	temp_Hour[0] = text[indexOf_Colons - 2];
	temp_Hour[1] = text[indexOf_Colons - 1];
	temp_Hour[2] = '\0';
	
	*hour = atoi(temp_Hour);
	
	temp_Min[0] = text[indexOf_Colons + 1];
	temp_Min[1] = text[indexOf_Colons + 2];
	temp_Min[2] = '\0';
	
	*min = atoi(temp_Min);
	
	return true;
}

int main(int argc, char** argv) {

	while(true)	
	{
		system("CLS");
		
		string input;
		string timeMode;
		
		cout << "-------------- Military Clock --------------" << endl;
		
		cout << "Please enter a desired time (HH:MM) with AM/PM:\t";
		
		cin >> input;
		cin >> timeMode;
		
		int hour, min; char timeType[3];
		
		bool result = Get_AM_PM_String(input, &hour, &min);
		
		if(result == false)
		{
			cout << "Invalid time format entered! Please read the time again, soldier! :D" << endl;
			system("PAUSE");
			continue;
		}
		
		if((hour<0 || hour > 12) || (min<0 || min>59))
		  {
		    cout << "Invalid time format entered! Please read the time again, soldier! :D" << endl;
		    system("PAUSE");
		    continue;
		  } 
		  else if(timeMode == "AM" && hour!=12)
		  {
		    cout << hour << ":" << min;
		  }
		  else if(timeMode == "AM" && hour==12)
		  {
		    cout << hour-12 << ":" << min;
		  }    
		  else if(timeMode == "PM" && hour!=12)
		  {
		    cout << hour+12 << ":" << min;
		  }
		  else if(timeMode == "PM" && hour==12)
		  {
		    cout << hour << ":" << min;
		  }
		  
		  cout << endl;
		  
		  system("PAUSE");
		  
		  break;
	}
	
	return 0;
}
