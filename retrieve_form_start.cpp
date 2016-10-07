// File: retrieve_form_start.cpp
// Author: 
// cs102 Online
// Date: 
// Description: This program retrieves three form fields and sends the result
//				back to the browser

#include <iomanip>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
using namespace std;

struct FIELDS 
{    
   
	string name;
	string value;
}; 

const int cnt = 3;	//cnt should be set to the number of fields the html form contains

// Prototypes
void parse(string, FIELDS []);
string param(string, FIELDS [], int);

//main begins
int main()
{    
	FIELDS name_value_pairs [cnt];

	string qs(getenv("QUERY_STRING")); 
     //string qs("first=fred&last=flint&food=red");
	cout << "Content-type:text/html\n\n"; 
	//cout << "debug with qs: " << qs << "<p>" << endl;

	parse(qs, name_value_pairs); 


// Three fields are retrieved with the param function
	string first = param("first", name_value_pairs, cnt);
    string last = param("last", name_value_pairs, cnt);
	string food = param("food", name_value_pairs, cnt);
	
	  //  cout << "Content-type:text/html\n\n";
        cout << "<html>" << endl;
        cout << "<head>" << endl;
        cout << "<title>Grabbing Data From the URL</title>" << endl;
        cout << "</head>" << endl;
        cout << "<body>" << endl;
        cout <<" <center><h2>Hello Everyone! Thank you for the input!! </h2><center>"<<endl;
       

        cout <<" Thank you, you have ordered <br> "<<endl;
        cout << food << "<br>\n";
        
        
        
    // if(food == "Sushi"){ 
    //      cout << "Sushi" << endl; 
      // } 
  //    else if(food == "Pizza"){           
     //      cout << "Pizza" << endl; 
    //   } 
   //  else if(food == "Ramen"){ 
     //      cout << "Ramen" << endl; 
  //    } 
    //    else if(food == "Salad"){ 
    //           cout << "Salad" << endl; 
    //  } 
   //   else if(food == "BBQ"){ 
    //      cout << "BBQ" << endl; 
//  } 
    
    cout << "</font></body>" << endl;
    cout << "</html>" << endl;
        return 0;
}
	
//*******************************************
//******** Functions begin ******************
//*******************************************

//*******************************************
// parse()
// This will separate the name/value pairs found after the ? in 
// the URL and populate the name_value_pairs array of structures
//*******************************************

void parse (string qs, FIELDS f_name_value_pairs []) 
{         
        string name, value; 
        int start_pos = 0, pos;  
        for (int counter=0; counter<cnt; counter++) { 
                pos = qs.find("=", start_pos); 
                f_name_value_pairs[counter].name = qs.substr(start_pos, pos - start_pos); 
                name=f_name_value_pairs[counter].name;  
                cout << "name: " << name << "<br>" << endl;  
                start_pos = pos + 1;   
                pos = qs.find("&", start_pos); 
                if (pos == string::npos) { 
                        pos = qs.length(); 
                } 
                f_name_value_pairs[counter].value = qs.substr(start_pos, pos - start_pos); 
                value=f_name_value_pairs[counter].value;  
                cout << "value: " << value << "<br>" << endl;  
                start_pos = pos + 1; 
        }  
         
} 


//*******************************************
// param()
// This will find the field value based on the
// field name
//*******************************************
string param(string lookUp, FIELDS f_name_value_pairs[], int f_cnt) 
{       //int number;  
        bool found = false;  
        value;
       for(int counter=0; counter<cnt; counter++)
 {     
 
	    if(lookUp == f_name_value_pairs[counter].name)
    {
		value = f_name_value_pairs[counter].value;
		found = true;
		}

		
   }
         if(found==false)
       {  
        return("");
        }
        else
        {
        return value;
        }
    
} 

