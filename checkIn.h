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

void checkInNew (vector<Person>& p)
{
	cin.clear();
	cin.ignore (256, '\n');
	string fn, ln, us, em, ph;
	cout << endl << endl << endl << endl;
	cout << "Please fill in the following information:" << endl;
	cout << "First Name: ";
	getline (cin, fn);
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
	p[v_size].assignInfo("X", p[v_size].countInfo() - 1);
	cout << endl << endl << endl;
	cout << "Thank you, " << p[v_size].findElement(0) << "! You're checked in!" << endl;
}

int Person::countInfo ()
{
	return info.size();
}


void checkInReturn (vector <Person>& p)
{
	cin.clear();
	cin.ignore (256, '\n');
	string us;
	cout << "Check-in with your username (case-sensitive): ";
	cin >> us;
	int p_size = p.size();
	//cout << "Your username is:" << us << us<< endl;
	for (int i = 0; i < p_size; i++)
	{
		//cout << "test against: " << p[i].findElement(2) << endl;		
		if (p[i].findElement(2) == us)
		{

			p[i].assignInfo("X", p[i].countInfo()-1);
			cout << endl << endl << endl;
			cout << "Thank you, " << p[i].findElement(0) << "! You're checked in!" << endl;
			return;
		}
	}

	cout << endl << endl << endl << "Username could not be found. Please try again." << endl;
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
	cout << endl << endl << endl << endl << endl;
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
void studentType (vector<Person>& v)
{
	string choice;
	do{
		cout << "\n\n\n";
		cout << setw (73) << setfill ('/') << "\n";
		cout << setw (73) << setfill ('\\') << "\n";
		cout << setw (73) << setfill ('/') << "\n";
		cout << setw (73) << setfill ('\\') << "\n";

		cout << "\n\n\n\n\n\n\n";
		DotSlash ();
		cout << "\n\n";
		cout << setw (73) << setfill ('/') << "\n";
		cout << setw (73) << setfill ('\\') << "\n";
		cout << setw (73) << setfill ('/') << "\n";
		cout << setw (73) << setfill ('\\') << "\n";
		cout << "\n\n\n\n\n\n\n\n";
		do
		{
		cout << "Please select if you are a new member or a returning member:" << endl;
		cout << "\t1 - New" << endl;
		cout << "\t2 - Returning" << endl << endl << endl << endl << endl;
			if (cin.fail())
			{
				cin.clear ();
				cin.ignore (256,'\n');
			}
			cin >> choice;
			if (choice != "1"&& choice != "2" && choice != "Q" && !cin.fail())
			{
				cout << "ERROR: Please enter a valid option (1 or 2)" << endl << endl;
			}
		}
		while (choice != "1" && choice != "2" && choice != "Q" && !cin.fail());
		if (choice == "1")
		{
			checkInNew (v);
		}
		else if (choice == "2")
		{
			checkInReturn (v);
		}
		else if (choice == "Q")
		{
			break;
		}
	}
	while (choice !="Q");}

void Person::assignInfo (string pinfo, int position)
{
	info[position] = pinfo;
}

 
string Person::findElement (int index)
{
	return info[index];
}

bool initVector (ifstream& file, vector<Person>& v)
{
	file.clear ();
	file.seekg (0, ios::beg);
	string row;
	int pos;
	//cout << "Testing first line..." << endl;
	getline (file, row);
	if (file.fail())
	{
		v.resize(1);
		for (int i = 0; i < 5; i++)
		{
			v[0].push();
		}
		//cout << "First line none... adding data." << endl;
		v[0].assignFirst("First");
		v[0].assignLast("Last");
		v[0].assignUser("User");
		v[0].assignEmail("Email");
		v[0].assignPhone("Phone");

		return true;
	}
	else
	{
		//cout <<"Values in first line valid..." << endl;
		file.clear ();
		file.seekg (0, ios::beg);
		int startpos = 0;
		pos = 0;
		int i = 0;
		int j = 0;
		getline (file, row);
		//cout << "First row taken..." << endl;
		while (!file.fail())
		{
			//cout << "New row..." << endl;
			if (i!=0)
			{
				v.resize(v.size()+1);
				v[i].push(v[0].countInfo());
			}
			while (pos!=-1)
			{
				pos = row.find (',', startpos);
				if (pos == -1)
				{
					v[i].assignInfo(row.substr(startpos), v[i].countInfo()-1);			
				}
				else
				{
					//cout << "Finding delim ','" << endl;
					string substring;
					substring = row.substr (startpos, pos-startpos);
					//cout << "Substring: " << substring << endl;
					//if (v[i].countInfo()>1)
					//	v[i].push();
					//cout << "info size of v[" << i << "]: " << v[i].countInfo() << endl;
					//cout << "debug: countinfo = " << v[i].countInfo() << endl;
					if (i==0)
					{
						v[i].assignInfo(substring, v[i].countInfo()-1);
					}
					else
					{
						v[i].assignInfo(substring, j);
					}
					startpos = pos + 1;
					if (i==0)
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
	return false;
}

void exportClose (ofstream& file, vector<Person>& v)
{
	int v_size = v.size();
	cout << "Exporting data to file..." << endl;
	for (int i = 0; i < v_size; i++)
	{
		int v_info_size = v[i].countInfo ();
		for (int j = 0; j < v_info_size; j++)
		{
			if (j!=0)
			{
				file << ",";
			}
			file << v[i].findElement(j);
		}
		file << "\n";
	}
	cout << "Closing file..." << endl;
	file.close();
}

#endif