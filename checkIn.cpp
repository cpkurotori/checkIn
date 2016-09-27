#include "checkIn.h"

int main ()
{
	studentType ();
	return 0;
}




void studentType ()
{
	string choice;
	do{
		cout << string (100, '\n');
		DotSlash ();
		cout << endl << endl;
		do
		{
		cout << "Please select if you are a new member or a returning member:" << endl;
		cout << "\t1 - New" << endl;
		cout << "\t2 - Returning" << endl;
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
			checkInNew ();
		}
		else if (choice == "2")
		{
			checkInReturn ();
		}
		else if (choice == "Q")
		{
			break;
		}
	}
	while (choice !="Q");
	
}

void checkRecords(string file_name, int* records_count_row, int* records_count_column)
	{
	fstream file;
	file.open (file_name);
	file.clear ();
	file.seekg(0L, ios::beg);
	*records_count_row = 0;
	*records_count_column = 0;
	string data;
	while (!file.fail())
	{
		getline (file,data);
		*records_count_row++;
	}
	*records_count_row--;
	file.clear ();
	file.seekg(0L, ios::beg);
	int start_pos, pos;
	string first_line;
	start_pos = 0;
	pos = 0;
	getline (file, first_line);
	while (pos!=string::npos)
	{
		pos = first_line.find (",", start_pos);
		start_pos = pos +1;
		*records_count_column ++;
	}
	file.close ();
}