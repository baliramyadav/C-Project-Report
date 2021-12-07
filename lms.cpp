#include<iostream>
#include<fstream>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<process.h>
#include<cstdio>
#include<stdlib.h>
using namespace std;

class book
{
	char bkno[6];
	char bkname[30], author[20];

public:


	void add_book()
	{
		cout << "\n\t Enter Book Name- ";
		cin>>(bkname);
		cout << "\n\t Enter Book no.- ";
		cin>>(bkno);
		cout << "\n\t Enter Author- ";
		cin>>(author);

		cout << endl;
	}

	void show_book()
	{
		cout << "\n Book No.- " << bkno;
		cout << "\n Book Name - " << bkname;
		cout << "\n Author - " << author << "\n";

	}

	void modify_bk()
	{
		cout << "\n book no. - " << bkno << "\n";
		cout << "\n modify book name - " << "\n";
		cin>>(bkname);
		cout << "\n modify author - " << "\n";
		cin>>(author);

	}

	void bkreport()
	{
		cout << "\n\t" << bkno << "\t\t" << bkname << "\t\t" << author;
		cout << endl;
	}

	char* retbkno()
	{
		return bkno;
	}

	char* retbkname()
	{
		return bkname;
	}


};                                      //class book ends here.....

class student
{
	char stname[30], admno[6];
	int check;
	char stbno[6];                    /*to first check if book is
						issued or not so that junk
						value is not given in output
						of book issued....*/

public:



	void add_student()
	{
		cout << " \n\t\t\t\tAdd New Student ..";
		cout << "\n\nEnter Name - ";
		cin>>(stname);
		cout << "\nEnter adm. no. - ";
		cin>>(admno);
		cout << endl;
		check = 0;
	}


	void show_student()
	{
		cout << "\n Adm no - " << admno;
		cout << "\n Name - " << stname << endl;
		cout << "\n Book Issued - " << check;
	}


	void modify_st()
	{
		cout << "\n adm. no. - " << admno << endl;
		cout << "\nName - " << stname << endl;
		cout << "\n\nmodify name - ";
		cin>>(stname);

	}

	int retcheck()
	{
		return check;

	}
	char* retadmno()
	{
		return admno;
	}

	char* retstname()
	{
		return stname;
	}



	char* retstbno()
	{
		return stbno;
	}

	void addcheck()
	{
		check = 1;
	}

	void resetcheck()
	{
		check = 0;
	}

	void tbno(char t[])
	{
		//strcpy_s(stbno, t);
	}

	void streport()
	{
		cout << endl;
		cout << admno << "\t" << stname << "\t\t";
		cout << check << endl;
	}

};                                   //class student ends....

fstream f;
student s;
book b;



/********** function to write in file ********/

void write_book()
{
	system("cls");
	char ch;
	cout << "\t\t\t\t << ADD NEW BOOK >>";
	f.open("book.dat", ios::binary | ios::out | ios::app);
	do
	{
		b.add_book();
		f.write((char*)&b, sizeof(b));
		cout << "record added...\n\n";
		cout << "do you wanna continue to add records ? (y/n)  ";
		cin >> ch;
	} while (ch == 'Y' || ch == 'y');
	f.close();

}

void write_student()

{
	system("cls");
	char ch1;
	cout << "\n\t\t\t\t << ADD NEW STUDENT >>\n";
	f.open("student.dat", ios::binary | ios::out | ios::app);
	do
	{
		s.add_student();
		f.write((char*)&s, (int)sizeof(s));
		cout << "Record added ...\n\n";
		cout << "do you wanna continue ? (y/n) ";
		cin >> ch1;

	} while (ch1 == 'Y' || ch1 == 'y');
	f.close();

}

//********** funtion to insert students from begining **********

void insert_student()
{
	system("cls");
	char ch1;
	cout << "\n\t\t\t\t << ADD STUDENTS >>\n";
	f.open("student.dat", ios::binary | ios::out);
	do
	{
		s.add_student();
		f.write((char*)&s, (int)sizeof(s));
		cout << "Record added ...\n";
		cout << "do you wanna continue ? (y/n) ";
		cin >> ch1;

	} while (ch1 == 'Y' || ch1 == 'y');
	f.close();
}

/******** function to search ********/


void book_searchbyroll()
{
	char ch2;
	int f1 = 0;
	cout << "\t\t\t\t << SEARCH BOOK BY BOOK NO. >>";
	f.open("book.dat", ios::binary | ios::in);
	char roll1[6];
	do {
		system("cls");
		cout << "\n Enter the book no to be searched - ";
		cin>>(roll1);
		while (f.read((char*)&b, sizeof(b)))
		{
			if (_strcmpi(roll1, b.retbkno()) == 0)

			{
				f1 = 1;
				b.show_book();
			}
		}
		if (f1 == 0)
			cout << "\nBook not present...\n";
		cout << "\nDo you wanna continue (y/n) ? ";
		cin >> ch2;

	} while (ch2 == 'y' || ch2 == 'Y');

	f.close();
}

void student_searchbyroll()

{
	system("cls");
	char ch3;
	int f2 = 0;
	char roll2[6];
	cout << "\t\t\t\t << SEARCH STUDENT BY ROLL NO. >>";
	f.open("student.dat", ios::binary | ios::in);
	do
	{
		system("cls");
		cout << "\nEnter the roll no. of student - ";
		cin>>(roll2);
		while (f.read((char*)&s, (int)sizeof(s)))
		{
			if (_strcmpi(roll2, s.retadmno()) == 0)
			{
				f2 = 1;
				s.show_student();
			}
		}
		if (f2 == 0)
			cout << "Student not found...";
		cout << "Do you wanna continue ? (y/n) ";
		cin >> ch3;
	} while (ch3 == 'y' || ch3 == 'Y');
	f.close();
}

void student_searchbyname()

{
	system("cls");
	char ch3;
	int f3 = 0;
	char stuname[20];
	cout << "\t\t\t\t << SEARCH STUDENT BY ROLL NO. >>\n";
	f.open("student.dat", ios::binary | ios::in);
	do
	{
		system("cls");
		cout << "enter the name of the student-";
		cin>>(stuname);
		while (f.read((char*)&s, (int)sizeof(s)))
		{
			if (_strcmpi(stuname, s.retstname()) == 0)
			{
				f3 = 1;
				s.show_student();
			}
		}
		if (f3 == 0)
			cout << "\nstudent not found\n";
		cout << "do you wanna continue ? (y/n)";
		cin >> ch3;

	} while (ch3 == 'y' || ch3 == 'Y');
	f.close();
}

void book_searchbyname()

{
	system("cls");
	char ch4;
	int f4;
	cout << "\t\t\t\t << SEARCH BOOK BY NAME >>\n\n";
	f.open("book.dat", ios::binary | ios::in);
	char bukname[30];
	do
	{
		system("cls");
		cout << "\tenter the name of the book - ";
		cin>>(bukname);
		while (f.read((char*)&b, sizeof(b)))
		{
			if (_strcmpi(bukname, b.retbkname()) == 0)
			{
				f4 = 1;
				b.show_book();
			}
		}
		if (f4 == 0)
			cout << "\n\tbook not found...";
		cout << "\n\tdo you wanna continue ? (y/n)";
		cin >> ch4;

	} while (ch4 == 'y' || ch4 == 'Y');
	f.close();
}

//********* function to read specific record from file  *********


void display_bk()
{
	system("cls");
	char n[20];
	cout << "enter the book number-";
	cin>>(n);
	cout << endl << "book details-\n";
	int flag = 0;
	f.open("book.dat", ios::binary | ios::in);
	while (f.read((char*)&b, sizeof(b)))
	{
		if (_strcmpi(b.retbkno(), n) == 0)
		{
			b.show_book();
			flag = 1;
		}
	}
	f.close();
	if (flag == 0)
		cout << "\n\nthe book does not exist";
	_getch();
}

void display_studt()
{
	system("cls");
	char n[20];
	cout << "enter the admission number-";
	cin>>(n);
	cout << endl << "student details-\n";
	int flag = 0;
	f.open("student.dat", ios::binary | ios::in);
	while (f.read((char*)&s, (int)sizeof(s)))
	{
		if (_strcmpi(n, s.retadmno()) == 0)
		{
			s.show_student();
			flag = 1;
		}
	}
	f.close();
	if (flag == 0)
		cout << "\n\nstudent does not exist";
	_getch();
}

//********* function to modify record of file **********


void modify_book()
{
	char n[6];
	int found = 0;
	system("cls");
	cout << "\n\n\tmodify book record....";
	cout << "\n\nenter the book number of the book-";
	cin >> n;
	f.open("book.dat", ios::binary | ios::in | ios::out);
	while (f.read((char*)&b, sizeof(b)) && found == 0)
	{
		if (_strcmpi(b.retbkno(), n) == 0)
		{
			b.show_book();
			cout << "\nenter the new details of the book\n";
			b.modify_bk();
			int pos = -1 *(int)sizeof(b);
			f.seekp(pos, ios::cur);
			f.write((char*)&b, sizeof(b));
			cout << "\n\nrecord updated\n";
			found = 1;
		}
	}
	f.close();
	if (found == 0)
		cout << "\n\nrecord not found\n";
	_getch();
}

void modify_student()
{
	char n[6];
	int found = 0;
	system("cls");
	cout << "\n\n\tmodify student record....";
	cout << "\n\nenter the admission number of the student -";
	cin >> n;
	f.open("student.dat", ios::binary | ios::in | ios::out);
	while (f.read((char*)&s, (int)sizeof(s)) && found == 0)
	{
		if (_strcmpi(s.retadmno(), n) == 0)
		{
			s.show_student();
			cout << "\n\nenter the new details of the student \n";
			s.modify_st();
			int pos = -1 * (int)sizeof(s);
			f.seekp(pos, ios::cur);
			f.write((char*)&s, (int)sizeof(s));
			cout << "\n\nrecord updated\n";
			found = 1;
		}
	}
	f.close();
	if (found == 0)
		cout << "\n\nrecord not found\n";
	_getch();
}

//********* function to delete record of file **********

void delete_student()
{
	system("cls");
	char n[6];
	int flag = 0;
	system("cls");
	cout << "\n\n\ndelete student...";
	cout << "\n\nenter the adm. no. of the student you want to delete";
	cin >> n;
	f.open("student.dat", ios::binary | ios::in | ios::out);
	fstream f2;
	f2.open("temp.dat", ios::binary | ios::out);
	f.seekg(0, ios::beg);
	while (f.read((char*)&s, (int)sizeof(s)))
	{
		if (_strcmpi(s.retadmno(), n) != 0)
			f2.write((char*)&s, (int)sizeof(s));
		else
			flag = 1;
	}
	f2.close();
	f.close();
	remove("student.dat");
	rename("temp.dat", "student.dat");
	if (flag == 1)
		cout << "\n\nrecord deleted";
	else
		cout << "\n\nrecord not found";
	_getch();
}

void delete_book()
{
	system("cls");
	char n[6];
	int flag = 0;

	cout << "\n\n\ndelete book...";
	cout << "\n\nenter the book no. of book you want to delete";
	cin>>(n);
	f.open("book.dat", ios::binary | ios::in | ios::out);

	fstream f2;

	f2.open("temp.dat", ios::binary | ios::out);
	f.seekg(0, ios::beg);
	while (f.read((char*)&b, sizeof(b)))
	{
		if (_strcmpi(b.retbkno(), n) != 0)
			f2.write((char*)&b, sizeof(b));
		else
			flag = 1;
	}
	f2.close();
	f.close();
	remove("book.dat");
	rename("temp.dat", "book.dat");
	if (flag == 1)
		cout << "\n\nrecord deleted";
	else
		cout << "\n\nrecord not found";
	_getch();
}


/************************************************
	 function to display complete data
  ************************************************/


void display_stlist()
{
	system("cls");
	f.open("student.dat", ios::binary | ios::in);
	cout << "\t\t\t\t << STUDENT LIST >>\n\n";
	cout << "Adm No \t\tStudent Name \t\t book issued\n ";

	while (f.read((char*)&s, (int)sizeof(s)))
	{
		s.streport();
	}
	f.close();

}

void display_bklist()
{
	system("cls");
	f.open("book.dat", ios::binary | ios::in);
	cout << "\t\t\t\t << BOOK LIST >>\n\n";
	cout << "\tBook No \tBook Name \tBook Author \n\n ";

	while (f.read((char*)&b, sizeof(b)))
	{
		b.bkreport();
	}
	f.close();
}


// ********** function to issue book ***********


void book_issue()
{
	fstream f1;
	char sn[6], bn[6];
	int found = 0, flag = 0;
	system("cls");
	cout << "\n\n\t\t\t\tBOOK ISSUE ...";
	cout << "\n\n\tEnter The student's admission no.";
	cin >> sn;
	f.open("student.dat", ios::binary | ios::in | ios::out);
	f1.open("book.dat", ios::binary | ios::in | ios::out);
	while (f.read((char*)&s, (int)sizeof(s)) && found == 0)
	{
		if (_strcmpi(s.retadmno(), sn) == 0)
		{
			found = 1;
			if (s.retcheck() == 0)
			{
				cout << "\n\n\tEnter the book no. ";
				cin >> bn;

				while (f1.read((char*)&b, sizeof(b)) && flag == 0)
				{

					if (_strcmpi(b.retbkno(), bn) == 0)

					{

						b.show_book();
						flag = 1;
						s.addcheck();

						s.tbno(b.retbkno());
						int pos = -1 * (int)sizeof(s);
						f.seekp(pos, ios::cur);
						f.write((char*)&s, (int)sizeof(s));

						cout << "\n\n\t Book issued successfully \n\n";
						cout << "Please Note:: Fine will be imposed of";
						cout << "Rs 1 for each day after 10 days period. ";

					}
				}

				if (flag == 0)

					cout << "\n\nBook no. does not exist";
			}
			else
				cout << "\n\nYou have not returned the last book ";
		}
	}
	if (found == 0)
		cout << "\n\nStudent record not exist...";
	_getch();
	f.close();
	f1.close();
}

//********* function to deposit book **********

void book_deposit()
{
	fstream f1;
	char sn[6], bn[6];
	int found = 0, flag = 0, day, fine;
	system("cls");
	cout << "\n\nBOOK DEPOSIT ...";

	cout << "\n\n\tEnter The students admission no. ";
	cin >> sn;

	f.open("student.dat", ios::binary | ios::in | ios::out);
	f1.open("book.dat", ios::binary | ios::in | ios::out);

	while (f.read((char*)&s, (int)sizeof(s)) && found == 0)
	{
		if (_strcmpi(s.retadmno(), sn) == 0)
		{
			found = 1;
			if (s.retcheck() == 1)
			{
				while (f1.read((char*)&b, sizeof(b)) && flag == 0)
				{
					if (_strcmpi(b.retbkno(), s.retstbno()) == 0)
					{
						b.show_book();
						flag = 1;
						cout << "\n\nBook deposited in no. of days";
						cin >> day;
						if (day > 10)
						{

							fine = (day - 10) * 1;

							cout << "\n\nFine has to deposited Rs. " << fine;

						}
						s.resetcheck();
						int pos = -1 * (int)sizeof(s);
						f.seekp(pos, ios::cur);
						f.write((char*)&s, (int)sizeof(s));
						cout << "\n\n\t Book deposited successfully";

					}
				}
				if (flag == 0)
					cout << "Book does not exist";
			}
			else
				cout << "No book is issued..please check!!";
		}
	}
	if (found == 0)
		cout << "Student record does not exist...";
	_getch();
	f.close();
	f1.close();
}
/******************************
 administrator menu
******************************/

void admin()
{
	char c, ch;
	do {
		system("cls");
		cout << "\t\t\t\t\t\t\t Enter $ for exit. ";
		cout << "\n\t 0. Add new book.";
		cout << "\n\t 1. Search book by book no.";
		cout << "\n\t 2. Search book by name .";
		cout << "\n\t 3. Delete book .";
		cout << "\n\t 4. Modify book details. \n\t";
		cout << "\n\t 5. Add new student.";
		cout << "\n\t 6. Search student by roll no. ";
		cout << "\n\t 7. Search student by name.";
		cout << "\n\t 8. Delete student .";
		cout << "\n\t 9. Modify student details. ";
		cout << "\n\t #. add students from begining.";
		cout << "\n\nEnter your choice... ";

		cin >> c;
		cout << endl;

		switch (c)
		{
		case '0': write_book();
			break;
		case '1': book_searchbyroll();
			break;
		case '2': book_searchbyname();
			break;
		case '3': delete_book();
			break;
		case '4': modify_book();
			break;
		case '5': write_student();
			break;
		case '6': student_searchbyroll();
			break;
		case '7': student_searchbyname();
			break;
		case '8': delete_student();
			break;
		case '9': modify_student();
			break;
		case '#': insert_student();
			break;

		case '$': exit(0);


		default: cout << "Invalid Input...";
			break;
		}
		cout << "\nDo you wanna go to Administrator menu again ? (y/n) ";
		cin >> ch;
	} while (ch == 'y' || ch == 'Y');
	_getch();
}

/***********************************************
	password function for admin menu
   ***********************************************/

void password()
{
	system("cls");
	char pass[20];
	cout << "\n\n\n\n\n\n\n\t\t\tENTER THE 4 DIGIT PASSWORD -\n\n\t\t\t\t";
	cin>>(pass);
	if (_strcmpi(pass, "9876") == 0)
		admin();
	else
		cout << "\n\n\n\t\t\twrong password entered\n\n\t\t\t";
	_getch();
}

/************************************
 Main Function
  ************************************/

int main()
{
	char c1, c2;
	system("cls");
	cout << " \n\n\n\n\n\n ";
	cout << " \t\t\t*********************** ";
	cout << " \n\n\t\t\tWELCOME TO BOOK LIBRARY ";
	cout << " \n\n\t\t\t*********************** ";
	_getch();

	do {
		system("cls");
		cout << "\t\t\t\t\t\t\t Press $ for Exit..\n";
		cout << "\n\t\t\t Menu\n ";
		cout << "\t 1. Display Book List ";
		cout << "\n\t 2. Display Student List ";
		cout << "\n\t 3. Issue a Book ";
		cout << "\n\t 4. Deposit a Book ";
		cout << "\n\t 5. Administrator Menu ";
		cout << "\n\t 6. Display specific book details.";
		cout << "\n\t 7. Display specific student details.";
		cout << "\n\n Enter your choice - ";



		cin >> c1;
		switch (c1)
		{
		case '1': display_bklist();
			break;
		case '3': book_issue();
			break;
		case '4': book_deposit();
			break;
		case '5': password();
			break;
		case '6': display_bk();
			break;
		case '2': display_stlist();
			break;
		case '7': display_studt();
			break;
		case '$': system("cls");
			cout << "\n\n\n\t\tEnd of program";
			cout << "\n\n\t\t**************";
			_getch();
			exit(0);
			break;
		default: cout << "\nInvalid Choice..";
			break;
		}
		cout << "\ndo u wanna go to main menu again (y/n) ? ";
		cin >> c2;
	} while (c2 == 'y' || c2 == 'Y');
	_getch();
}

