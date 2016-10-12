//header file containing include statements, and namespace statement
#ifndef CHECK_IN
#define CHECK_IN

#include <fstream>
#include <string>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cstring>

using namespace std;

class Person
{
public:
	Person ()
	{
		info.resize(1);
	}
	void assignFirst (string);
	void assignLast (string);
	void assignEmail (string);
	void assignPhone (string);
	void assignUser (string);
	void assignInfo (string, int);
	int countInfo ();
	void push ();
	void push (int);
	string findElement (int);

private:
	vector<string> info;
};

using namespace std;

void Person::assignFirst (string fn)
{
	info[0] = fn;
}

void Person::assignLast (string ln)
{
	info [1] = ln;
}

void Person::assignEmail (string em)
{
	info [3] = em;
}

void Person::assignPhone (string ph)
{
	info [4] = ph;
}

void Person::assignUser (string us)
{
	info [2] = us;
}

void Person::push ()
{
	//cout << "Reallocating space for info of size " << info.size() << endl;
	info.resize(info.size()+1);
	//cout << "Allocated." << endl;
}

void Person:: push (int size)
{
	info.resize (size);
}

int Person::countInfo()
{
	return info.size();
}

void Person::assignInfo (string pinfo, int position)
{
	info[position] = pinfo;
}

 
string Person::findElement (int index)
{
	return info[index];
}
void updateInfo(vector<Person>& v)
{
	cin.clear();
	cin.ignore(256, '\n');
	int choice, index;
	string fn, ln, us, em, ph;
	bool found = false;
	int v_size = v.size();
	while (!found)
	{
		cout << "Enter your First Name (Enter \"Quit\" to got back to main menu) : ";
		getline(cin, fn);
		if (fn == "Quit")
		{
			return;
		}
		cout << "Enter your Last Name: ";
		getline(cin, ln);
		for (int i = 0; i < v_size; i++)
		{
			if ((v[i].findElement(0) == fn) && (v[i].findElement(1) == ln))
			{
				index = i;
				found = true;
				break;
			}
		}
		if (!found)
		{
			cout << endl << "ERROR: The combination of the First Name (\"" << fn << "\") and Last Name (\"" << ln << "\") you entered could not be found." << endl;
			cout << "Make sure you entered your first name correctly, or register as a \"New\" club member." << endl << endl;
		}
	}
	do
	{
		do
		{
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(256, '\n');
			}
			cout << endl << "What information would you like to update?" << endl << endl;
			cout << "\t1\t-\t Username" << endl;
			cout << "\t2\t-\t Email (does not change newsletter subscription)" << endl;
			cout << "\t3\t-\t Phone Number" << endl;
			cout << "\t4\t-\t Exit to main menu" << endl << endl;
			cout << "Enter your choice: ";
			cin >> choice;
			if ((choice < 1) || (choice > 4) || cin.fail())
			{
				cout << endl << "ERROR: Please enter a valid option." << endl << endl;
			}
		} while ((choice < 1) || (choice > 4) || cin.fail());
		if (choice == 4)
			return;
		cout << "New " << v[0].findElement(choice + 1) << " for " << v[index].findElement(0) << " " << v[index].findElement(1) << ":\t";
		string update;
		cin.clear();
		cin.ignore(256, '\n');
		getline(cin, update);
		//cout << "Assigning it to index + 1 : " << choice + 1 << endl;
		if (choice == 1) //for username checks to see if username is a duplicate
		{
			bool identical;
			int k = 0;
			do
			{
				identical = false;
				if (k != 0)
				{
					cout << "New " << v[0].findElement(choice + 1) << " for " << v[index].findElement(0) << " " << v[index].findElement(1) << ":\t";
					getline(cin, update);
				}
				int v_size = v.size();
				//cout << "3" << endl;
				for (int i = 0; i < v_size; i++)
				{
					string test;
					//cout << "1" << endl;
					test = v[i].findElement(2);
					//cout << "2" << endl;
					if (update == test)
					{
						cout << "ERROR: That username is already taken!" << endl << endl;
						identical = true;
						break;
					}
				}
				k++;
			} while (identical);
		}

		v[index].assignInfo(update, choice + 1);
	} while (choice != 4);
}

void checkInNew (vector<Person>& p, int index)
{
	cin.clear();
	cin.ignore (256, '\n');
	string fn, ln, us, em, ph;
	cout << endl << endl << endl << endl;
	cout << "Please fill in the following information:" << endl;
	cout << "First Name (enter \"Quit\" to exit to main menu): ";
	getline (cin, fn);
	if (fn == "Quit")
	{
		return;
	}
	cout << "Last Name: ";
	getline (cin, ln);
	bool identical = true;
	do
	{
		cout << "Username (choose a username - case sensitive): ";
		cin >> us;
		identical = true;
		int p_size = p.size ();
		//cout << "3" << endl;
		for (int i = 0; i < p_size; i++)
		{
			string test;
			//cout << "1" << endl;
			test = p[i].findElement(2);
			//cout << "2" << endl;
			if (us == test)
			{
				cout << "That username is already taken!" << endl;
				identical = false;
				break;
			}
		}
	}
	while (!identical);
	cout << "Email: ";
	cin >> em;
	cout << "Phone number: ";
	cin >> ph;
	int v_size = p.size();
	p.resize(v_size+1);
	p[v_size].push(p[0].countInfo());
	p[v_size].assignFirst(fn);
	p[v_size].assignLast(ln);
	p[v_size].assignUser(us);
	p[v_size].assignEmail(em);
	p[v_size].assignPhone(ph);
	p[v_size].assignInfo("X", index);
	cout << string(40, '\n');
	cout << "Thank you, " << p[v_size].findElement(0) << "! You're checked in!" << endl;
}

void checkInReturn (vector <Person>& p, int index)
{
	bool found;
	do
	{
		cin.clear();
		cin.ignore(256, '\n');
		string us;
		found = false;
		cout << "Check-in with your username (case-sensitive) or type \"Quit\" to exit to main menu: ";
		cin >> us;
		if (us == "Quit")
			return;
		int p_size = p.size();
		//cout << "Your username is:" << us << us<< endl;
		for (int i = 0; i < p_size; i++)
		{
			//cout << "test against: " << p[i].findElement(2) << endl;		
			if (p[i].findElement(2) == us)
			{

				p[i].assignInfo("X", index);
				cout << string(40, '\n');
				cout << "Thank you, " << p[i].findElement(0) << "! You're checked in!" << endl;
				found = true;
				return;
			}
		}
		if (!found)
		{
			cout << endl << endl << endl << "ERROR: Username could not be found. Please try again." << endl << endl;
		}
	} while (!found);
	return;

}

void DotSlash ()
{
	cout << "**********************************************************************" << endl;
	cout << "*    ____    ____   ______       ____         ___     ____           *" << endl;
	cout << "*   ||  \\\\  ||  ||    ||        ||     ||    // \\\\   ||     ||   ||  *" << endl;
	cout << "*   ||   || ||  ||    ||    __  ||___  ||   ||___||  ||___  ||___||  *" << endl;
	cout << "*   ||   || ||  ||    ||   |__|     || ||   ||   ||      || ||   ||  *" << endl;
	cout << "*   ||__//  ||__||    ||        ____|| ||__ ||   ||  ____|| ||   ||  *" << endl;
	cout << "*                                                                    *" << endl;
	cout << "*   C   O   M   P   U   T   E   R         S   C   I   E   N   C   E  *" << endl;
	cout << "**********************************************************************" << endl;
	cout << endl << endl;
	}

bool openFileRead (ifstream& file, const char* fname)
{
	file.open (fname);
	if (!file)
		return false;
	else
		return true;}

bool openFileWrite (ofstream& file, const char* fname)
{
	file.open (fname);
	if (!file)
		return false;
	else
		return true;}

// function void studentType () pseudo-clear screen, creates Dot-Slash banner, asks if use is new or returning, depending on selected option, calls the corresponsing function (checkInNew () or checkInReturn ())
//hidden option "Q" to quit the program
//program continues to run until admin types "Q"

void studentType (vector<Person>& v, int index)
{
	string choice;
	do
	{
		cout << "\n\n";
		cout << "\n\n";
		DotSlash ();
		cout << endl;
		cout << "*****Welcome to Dot - Slash Computer Science Check-In!*****" << endl << endl;
		cout << "If you have any questions, feel free to ask one of the ./Officers" << "\n";
		cout << "\n\n";
		do
		{
		cout << "Please select an option" << endl << endl;
		cout << "\t1 - New member check-in" << endl;
		cout << "\t2 - Returning member check-in" << endl;
		cout << "\t3 - Returning member update info" << endl;
		cout << endl << endl << "Enter \"help\" for more information/help!" << endl << endl << endl;
		cout << "What would you like to do? (Using the keyboard, enter the number of the option and press ENTER/RETURN):\t";
		cin >> choice;
		if (choice != "1"&& choice != "2" && choice != "3" && choice != "Q" && choice != "help")
			{
				cout << "ERROR: Please enter a valid option (1 or 2)" << endl << endl;
			}
		}
		while (choice != "1" && choice != "2" && choice != "3" && choice != "Q" && choice != "help");
		if (choice == "1")
		{
			checkInNew (v, index);
		}
		else if (choice == "2")
		{
			checkInReturn (v, index);
		}
		else if (choice == "3")
		{
			updateInfo(v);
		}
		else if (choice == "help")
		{
			cout << string(40, '\n');
			cout << "HELP MENU:" << endl << endl << endl;
			cout << "Please enter the number corresponding to the option of your choice:" << endl << endl << endl;
			cout << "\tIf you are a new member, enter '1' on the main menu and then enter your infomation " << endl << endl;
			cout << "\tIf you are a returning member, enter '2' on the main menu and then enter your username to check in" << endl << endl;
			cout << "\tIf you need to update your information, enter '3' on the main menu and then enter your First Name then Last Name" << endl;
			cout << "\tOnce you've entered your name, you will be able to choose an option for whcih info you want to update." << endl << endl << endl;
			cout << endl << "\tIf you are a returning member, but haven't used this check-in program before," << endl << "\tyou must first create a username. Please choose option 3, put in your first name," << endl << "\tthen your last name, and then choose to update" << endl;
			cout << "\tyour username. You will use this username to check-in. Once you have chosen a " << endl << "\tusername, exit to the main menu, and check in as a returning member." << endl;
			cout << endl << endl << endl;
			cout << "Press ENTER to continue...";
			string cont;
			cin.clear();
			cin.ignore(256, '\n');
			getline(cin, cont);
			cout << string(40, '\n');
		}
		else if (choice == "Q")
		{
			return;
		}
	}
	while (choice !="Q");
}
// takes information from the file and puts it into the roster vector
void initVector (ifstream& file, vector<Person>& v)
{
	file.clear ();
	file.seekg (0, ios::beg);
	string row;
	int pos;
	//cout << "Testing first line..." << endl;
	getline (file, row);
	if (file.fail()) //if the file is blank make the starting titles
	{
		v[0].push(5);
		//cout << "First line none... adding data." << endl;
		v[0].assignFirst("First Name");
		v[0].assignLast("Last Name");
		v[0].assignUser("Username");
		v[0].assignEmail("Email Address");
		v[0].assignPhone("Phone Number");

		return; //exits initVector and returns the value of true to the bool variable
	}
	else
	{
		//cout <<"Values in first line valid..." << endl;
		file.clear (); //bring pointer to the beginning
		file.seekg (0, ios::beg);
		int startpos = 0;
		pos = 0;
		int i = 0;
		int j = 0;
		getline (file, row);
		//cout << "First row taken..." << endl;
		while (!file.fail()) //go until file is at the end
		{
			//cout << "New row..." << endl;
			if (i!=0) 
			{
				v.resize(v.size()+1); //since v already has an initialized size of 1, we skip resizing for the first index 0
				v[i].push(v[0].countInfo()); //after creating another v element, we must create a vector the same size of the 0 index for the info vector
			}
			while (pos!=-1) //testing against EOL
			{
				pos = row.find (',', startpos); //finds "," in the row; returns -1 if EOL
				if (pos == -1) //this is for the very last term (after the last ,)
				{
					v[i].assignInfo(row.substr(startpos), v[i].countInfo()-1);			
				}
				else //
				{
					//cout << "Finding delim ','" << endl;
					string substring;
					substring = row.substr (startpos, pos-startpos);
					//cout << "Substring: " << substring << endl;
					//if (v[i].countInfo()>1)
					//	v[i].push();
					//cout << "info size of v[" << i << "]: " << v[i].countInfo() << endl;
					//cout << "debug: countinfo = " << v[i].countInfo() << endl;
					/*
					if (i==0)
					{
						v[0].assignInfo(substring, v[0].countInfo()-1);
					}
					else
					{
					*/
					v[i].assignInfo(substring, j);
					//}
					startpos = pos + 1;
					if (i==0) //for the title element in the roster, creates a new column for it
						v[i].push();
					j++;
				}
			}
			//cout << "Reallocating vector size..." << endl;

			i++;
			j=0;
			startpos = 0;
			getline (file, row);
			//cout << "Next row taken..." << endl;
			pos = 0;
		}
	}
	return;
}

void exportClose (ofstream& file, vector<Person>& v)
{
	int v_size = v.size();
	int v_info_size = v[0].countInfo ();
	cout << "Exporting data to file..." << endl;
	for (int i = 0; i < v_size; i++)
	{
		if (i!= 0)
		{
			file << "\n";
		}
		for (int j = 0; j < v_info_size; j++)
		{
			if (j!=0)
			{
				file << ",";
			}
			file << v[i].findElement(j);
		}
	}
	cout << "Closing file..." << endl;
	file.close();
}



#endif