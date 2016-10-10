#include "checkIn.h" //checkIn.h contains all headers

int main (int argc, char* argv[])
{
	string f_string;
	const char* file_name;
	string date, term, notes;
	int day, month, year;
	do
	{
	if (cin.fail())
	{
		cin.clear();
		cin.ignore(256,'\n');
	}
	cout << "Month: ";
	cin >> month;
	if ((month < 1) | (month > 12) | cin.fail())
		cout << endl << "ERROR: Please enter a valid month (of integer type)!" << endl << endl;
	}
	while ((month < 1) | (month > 12) | cin.fail());
	do
	{
	if (cin.fail())
	{
		cin.clear();
		cin.ignore(256,'\n');
	}
	cout << "Day: ";
	cin >> day;
	if ((day < 1) | (day > 31) | cin.fail())
		cout << endl << "ERROR: Please enter a valid day (of integer type)!" << endl << endl;
	}
	while ((day < 1) | (day > 31) | cin.fail());
	do
	{
	if (cin.fail())
	{
		cin.clear();
		cin.ignore(256,'\n');
	}
	cout << "Year: ";
	cin >> year;
	if ((year < 2016) | (year > 3000)| cin.fail())
		cout << endl << "ERROR: Please enter a valid year (of integer type)!" << endl << endl;
	}
	while ((year < 2016) | (year > 3000) | cin.fail());
	if(argc == 2)
	{
	file_name = argv[1];
	}
	else
	{
		do
		{
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(256,'\n');
			}
			cout << "What term is it (Fall/Spring/Summer): ";
			cin >> term;
			if ((term!= "Fall") && (term!= "Summer") && (term != "Spring"))
			{
				cout << endl << "ERROR: Please enter a valid term!" << endl << endl;
			}
		}
		while ((term!= "Fall") && (term!= "Summer") && (term != "Spring"));
	f_string = term + to_string(year) + ".csv";
	file_name = f_string.c_str();
	}
	string s_year = to_string(year);
	//cout << s_year[0];
	cout << "Do you have any special notes for today? (if none press return):" << endl;
	cin.clear();
	cin.ignore (256, '\n');
	getline (cin, notes);
	date = to_string(month)+'/'+to_string(day)+'/'+s_year[2] + s_year[3];
	if (!notes.empty())
		date = date +'('+notes+')';
	//cout << date;
	ifstream infile;
	ofstream outfile;
	bool opened = openFileRead(infile, file_name);
	if (!opened)
	{
		outfile.open (file_name);
		outfile.close ();
		cout << "File created." << endl;
		infile.open (file_name);

	}
	vector<Person> roster;
	roster.resize(1); //creates the first element for roster (i.e. the title element)
	bool nofile;
	cout << "Initializing vector for roster..." << endl;
	nofile = initVector (infile, roster); //puts all the data in file into roster vector
	//for (int i = 0; i < roster.size(); i++)
	//{
	//	cout << "Name element of roster[" << i << "] = " << roster[i].findElement (0) << endl;
	//}
	if (infile.is_open())
		infile.close();
	if (outfile.is_open())
		outfile.close();
	//test if the date is a duplicate and if it isn't add and element to the info of title element, if it is, don't and use the index of the date to assign "X" to that element for people that check in
	bool identicalDay = false;
	int date_index;
	int roster_size = roster.size ();
	for (int i = 0; i < roster.size(); i++) //tests if there is an identical date already in the title element; if there is return true and log the index of it into date_index, if not identicalDate will stay false
	{
		if (roster[0].findElement(i) == date)
		{
			identicalDay = true;
			date_index = i;
			break;
		}
	}
	if (!identicalDay)
	{
		roster[0].push(); //adds element to info vector of title element
		roster[0].assignInfo(date, roster[0].countInfo() - 1); //assigns date value to the just created element in info
		date_index = roster[0].countInfo() - 1;
		for (int i = 1; i < roster_size; i++) //assigns blank element to the new date element index in every roster position (after the title element)
		{
			roster[i].push(roster[0].countInfo());
			roster[i].assignInfo(" ", roster[i].countInfo() - 1);
		}
	}
	cout << string(40, '\n');
	studentType (roster, date_index); //pass the roster and date index to the student type function
	opened = openFileWrite (outfile, file_name);
	exportClose (outfile, roster);
	//studentType (); //calls studentType function that asks the user if they are new or returning (hidden option Q for admin to quit program)
	return 0;
}