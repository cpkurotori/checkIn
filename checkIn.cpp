#include "checkIn.h" //checkIn.h contains all headers

int main (int argc, char* argv[])
{
	if(argc < 2)
	{
		cout << "Please indicate a roster file to pull from/create." << endl << endl;
		exit (EXIT_FAILURE);
	}
	cout << "What is today's date entry: ";
	string date;
	cin >> date;
	ifstream infile;
	ofstream outfile;
	bool opened = openFileRead(infile, argv [1]);
	if (!opened)
	{
		outfile.open (argv [1]);
		outfile.close ();
		cout << "File created." << endl;
		infile.open (argv[1]);

	}
	vector<Person> roster;
	roster.resize(1);
	bool nofile;
	cout << "Initializing vector for roster..." << endl;
	nofile = initVector (infile, roster); //puts all the data in file into roster vector
	//for (int i = 0; i < roster.size(); i++)
	//{
	//	cout << "Name element of roster[" << i << "] = " << roster[i].findElement (0) << endl;
	//}
	if (!nofile)
		roster[0].push();
	if (infile.is_open())
		infile.close();
	if (outfile.is_open())
		outfile.close();
	roster[0].assignInfo(date,roster[0].countInfo()-1);
	for (int i = 1; i < roster.size(); i++)
	{
		roster[i].push(roster[0].countInfo());
		roster[i].assignInfo(" ",roster[i].countInfo()-1);
	}
	//for (int j = 0; j < roster.size(); j++)
	//{
	//	for (int i = 0; i < roster[j].countInfo(); i++)
	//	{
	//		cout << roster[j].findElement(i) << endl;
	//	}
	//	cout << "Next roster position..." << endl;
	//}
	cout << string (100, '\n');
	studentType (roster);
	opened = openFileWrite (outfile, argv[1]);
	exportClose (outfile, roster);
	//studentType (); //calls studentType function that asks the user if they are new or returning (hidden option Q for admin to quit program)
	return 0;
}