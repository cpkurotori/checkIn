#include "checkIn.h" //checkIn.h contains all headers

int main ()
{
	//ask very first user (admin) for the year
	int year;
	do
	{
		if (cin.fail ())
		{
			cin.clear ();
			cin.ignore (256, '\n');

		}
		cout << "What year is it?" << endl;
		cin >> year;
		if (year < 2016 || cin.fail())
		{
			cout << "ERROR: You must enter a year after 2015." << endl << endl;
		}
	}
	while (year < 2016 || cin.fail ());
	//create filename reference ([YEAR]Roster.csv)
	//follows roster template, comma separated/delimited values
	// '\n' is considered new row; ',' is considered new column
	//assign file name to vaiable "string filename"
	string year_s = to_string(year);
	string filename = year_s + "Roster.csv";
	//cout << filename << endl;
	//call checkRecords (with parameters of the filename and pointers to variables holding row count and column count)
	int *rows;
	int *columns;
	checkRecords (filename, rows, columns);
	cout << "rows: " << to_string(*rows) << " columns: " << to_string(*columns) << endl;
	studentType (); //calls studentType function that asks the user if they are new or returning (hidden option Q for admin to quit program)
	return 0;
}



// function void studentType () pseudo-clear screen, creates Dot-Slash banner, asks if use is new or returning, depending on selected option, calls the corresponsing function (checkInNew () or checkInReturn ())
//hidden option "Q" to quit the program
//program continues to run until admin types "Q"
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
//function checkRecords counts how many rows and columns there are in the roster for the year
void checkRecords(string file_name, int* records_count_row, int* records_count_column)
	{
	ifstream file (file_name);
	file.clear ();
	file.seekg(0L, ios::beg);
	*records_count_row = 0;
	*records_count_column = 0;
	string data;
	if (!file.fail())
	{
		while (!file.fail())
		{
			getline (file,data);
			*records_count_row++;
		}
		*records_count_row--;
	}
	file.clear ();
	file.seekg(0L, ios::beg);
	int start_pos, pos;
	string first_line;
	start_pos = 0;
	pos = 0;
	getline (file, first_line);
	if (!file.fail())
		while (pos!=string::npos)
		{
			pos = first_line.find (",", start_pos);
			start_pos = pos +1;
			*records_count_column ++;
		}
	file.close ();
}