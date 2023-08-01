#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <conio.h>

using namespace std;

	vector<string>userName = {"admin"};
	vector<string>passWord = {"1234"};
	
	vector<string>bookID;
	vector<string>bookTitle;
	vector<string>bookAuthor;
	vector<string>bookPublisher;
	vector<string>bookAvailability;
	
	vector<string>patreonID;
	vector<string>patreonName;
	vector<string>patreonCP;
	vector<string>patreonAvail;
	
	vector<string>checkBookID;
	vector<string>checkBookTitle;
	vector<string>checkBookAuthor;
	vector<string>checkBookPublisher;
	vector<string>checkBookAvailability;
	vector<string>checkPatronID;
	vector<string>checkPatronName;
	vector<string>checkPatronCP;
	vector<string>checkPatronAvail;
	
	
void openFile(int s){
	string word;
	int pos = 0;
	ifstream myfile;
	if(s==1) myfile.open("bookData.txt");
	if(s==2) myfile.open("patronData.txt");
	if(s==3) myfile.open("checkoutData.txt");
	if(myfile.is_open()){
		if(s==1){bookID.clear(); bookTitle.clear(); bookAuthor.clear(); bookPublisher.clear(); bookAvailability.clear();}
		if(s==2){patreonID.clear(); patreonName.clear(); patreonCP.clear();}
		if(s==3){checkBookID.clear(); checkBookTitle.clear(); checkBookAuthor.clear(); checkBookPublisher.clear(); checkBookAvailability.clear(); checkPatronID.clear(); checkPatronName.clear(); checkPatronCP.clear(); checkPatronAvail.clear();}
		while(getline(myfile,word)){
			if(s==1){
				if(pos == 0 and word.size()!=0) bookID.push_back(word);
				if(pos == 1 and word.size()!=0) bookTitle.push_back(word);
				if(pos == 2 and word.size()!=0) bookAuthor.push_back(word);
				if(pos == 3 and word.size()!=0) bookPublisher.push_back(word);
				if(pos == 4 and word.size()!=0) bookAvailability.push_back(word);
			}
			if(s==2){
				if(pos == 0 and word.size()!=0) patreonID.push_back(word);
				if(pos == 1 and word.size()!=0) patreonName.push_back(word);
				if(pos == 2 and word.size()!=0) patreonCP.push_back(word);
				if(pos == 3 and word.size()!=0) patreonAvail.push_back(word);
			}
			if(s==3){
				if(pos == 0 and word.size()!=0) checkBookID.push_back(word);
				if(pos == 1 and word.size()!=0) checkBookTitle.push_back(word);
				if(pos == 2 and word.size()!=0) checkBookAuthor.push_back(word);
				if(pos == 3 and word.size()!=0) checkBookPublisher.push_back(word);
				if(pos == 4 and word.size()!=0) checkBookAvailability.push_back(word);
				if(pos == 5 and word.size()!=0) checkPatronID.push_back(word);
				if(pos == 6 and word.size()!=0) checkPatronName.push_back(word);
				if(pos == 7 and word.size()!=0) checkPatronCP.push_back(word);
				if(pos == 8 and word.size()!=0) checkPatronAvail.push_back(word);
			}
			pos++;
			if(word.size()==0) pos = 0;
		}
		myfile.close();
	}
	else{
		cout << "Enable to open the file!" << endl;
	}
}
void saveFile(int n){
	fstream myfile;
	if(n==1) myfile.open("bookData.txt", ios::out);
	if(n==2) myfile.open("patronData.txt", ios::out);
	if(n==3) myfile.open("checkoutData.txt", ios::out);
	if(myfile.is_open()){
		if(n==1){
			for (int i = 0; i<(int)bookID.size();i++){
				fstream mf("bookData.txt", ios::app);
				mf << bookID[i] << "\n";
				mf << bookTitle[i] << "\n";
				mf << bookAuthor[i] << "\n";
				mf << bookPublisher[i] << "\n";
				mf << bookAvailability[i] << "\n\n";
			}
		}
		if(n==2){
			for (int i = 0; i<(int)patreonID.size();i++){
				fstream mf("patronData.txt", ios::app);
				mf << patreonID[i] << "\n";
				mf << patreonName[i] << "\n";
				mf << patreonCP[i] << "\n";
				mf << patreonAvail[i] << "\n\n";
			}
		}
		if(n==3){
			for (int i = 0; i<(int)checkBookID.size();i++){
				fstream mf("checkoutData.txt", ios::app);
				mf << checkBookID[i] << "\n";
				mf << checkBookTitle[i] << "\n";
				mf << checkBookAuthor[i] << "\n";
				mf << checkBookPublisher[i] << "\n";
				mf << checkBookAvailability[i] << "\n";
				mf << checkPatronID[i] << "\n";
				mf << checkPatronName[i] << "\n";
				mf << checkPatronCP[i] << "\n";
				mf << checkPatronAvail[i] << "\n\n";
			}
		}
		myfile.close();
	}
}

void header(){
cout << "\t __    _ _                " << endl;   
cout << "\t|  |  |_| |_ ___ ___ ___ _ _ " << endl;
cout << "\t|  |__| | . |  _| .'|  _| | |" << endl;
cout << "\t|_____|_|___|_| |__,|_| |_  |" << endl;
cout << "\t                        |___| " << endl;
cout << " _____                                   _   " << endl;
cout << "|     |___ ___ ___ ___ ___ _____ ___ ___| |_ " << endl;
cout << "| | | | .'|   | .'| . | -_|     | -_|   |  _|" << endl;
cout << "|_|_|_|__,|_|_|__,|_  |___|_|_|_|___|_|_|_|  " << endl;
cout << "                  |___|                      " << endl;
cout << "\t _____         _                             " << endl;
cout << "\t|   __|_ _ ___| |_ ___ _____                 " << endl;
cout << "\t|__   | | |_ -|  _| -_|     |                " << endl;
cout << "\t|_____|_  |___|_| |___|_|_|_|                " << endl;
cout << "\t      |___|                                  " << endl;
}

void header2(){
	cout << "************************* LIBRARY MANAGEMENT SYSTEM *************************" << endl;
	cout << "=============================================================================" << endl;
}

void logIN(){
	UserInput:
	system("cls");
	header();
	string user;
	string pass;
	int ch;
	cout << "\n\n\tUsername: ";
	cin >> user;
	cout << "\tPassword: ";
	ch = getch();
	while (ch != 13){
		pass.push_back(ch);
		cout << "*";
		ch = getch();
	}
	int n = userName.size();
	for (int i = 0;i<n;i++){
		if (user == userName[i] && pass == passWord[i]){
			system("cls");
			header();
			cout << "\n\n\t\tAcces Granted" << endl << endl;
			cout << "\t";
			system("pause");
			break;
		}
		else{
			system("cls");
			header();
			cout << "\n\n\tAccess Denied" << endl << endl;
			cout << "\tInvalid Username or Password" << endl << endl;
			cout << "\t";
			system("pause");
			goto UserInput;
		}
	}
}

void addBookData(){
	
	
	char id[100];
	char title[100];
	char author[100];
	char publisher[100];
	string avail = "Yes";
	cin.ignore();
	Input:
	system("cls");
	header2();
	openFile(1);
	cout << "\t\t\t\tADDING A NEW BOOK" << endl;
	cout << "Book ID: ";
	cin.getline(id, 100);
	int n = bookID.size();
	for (int i = 0;i<n;i++){
		if(id == bookID[i]){
			cout << "Book ID Number Already Exist" << endl;
			system("pause");
			goto Input;
		}
	}
		bookID.push_back(id);
		cout << "Book Title: ";
		cin.getline(title, 100);
		bookTitle.push_back(title);
		cout << "Author Name: ";
		cin.getline(author, 100);
		bookAuthor.push_back(author);
		cout << "Publisher Name: ";
		cin.getline(publisher, 100);
		bookPublisher.push_back(publisher);
		bookAvailability.push_back(avail);
		cout << "\nAdded Succesful!" << endl << endl;
		saveFile(1);
		bookID.clear(); bookTitle.clear(); bookAuthor.clear(); bookPublisher.clear(); bookAvailability.clear();
		
}

void searchBooks(){
	openFile(1);
	cout << "\t\t\t\tSEARCHING A BOOK" << endl;
	string search;
	int n = bookID.size();
	int counter = 0;
	int select;
	cout << "\n\t\t\t\t  Search by: " << endl << endl;
	cout << "\t\t[1] Book ID\t\t\t[2] Book Tittle" << endl << endl;
	cout << "\t\t[3] Boook Author\t\t[4] Book Publisher" << endl << endl;
	cout << "\t\t[5] Book Availability\t\t[0] Return to Main Menu" << endl << endl;
	cout << "\t\t    Select: ";
	while(!(cin >> select) || select > 5 || select < 0){
		cin.clear();
		cin.ignore(99999,'\n');
		cout << "\t\t    Invalid Input" << endl;
		cout << "\t\t    Select: ";
	}
	
	if (select == 1){
		system("cls");
		header2();
		cout << "\t\t\t\tSEARCHING A BOOK" << endl;
		cout << "\nSearch by Book ID: ";
		cin >> search;
		cout << "\n\t\t\t\tCURRENT RECORD" << endl;
		cout << "=============================================================================" << endl;
		for (int i = 0; i<n;i++){
			if (bookID[i] == search){
				counter++;
				cout << "|| BOOK ID: " << bookID[i] << endl;
				cout << "|| TITLE: " << bookTitle[i] << endl;
				cout << "|| AUTHOR: " << bookAuthor[i] << endl;
				cout << "|| PUBLISHER: " << bookPublisher[i] << endl;
				cout << "|| AVAILABILITY: " << bookAvailability[i] << endl;
				cout << "=============================================================================" << endl;
				cout << "                                                           Total Records: " << counter << endl;
			}
		}
				
		if (counter == 0){
				cout << "\n\t\t\t\tNO RECORD FOUND" << endl << endl;
				cout << "=============================================================================" << endl;
				cout << "                                                           Total Records: " << counter << endl;
			}
	}
	else if (select == 2){
		system("cls");
		cin.ignore();
		header2();
		cout << "\t\t\t\tSEARCHING A BOOK" << endl;
		cout << "\nSearch by Book Title: ";
		getline(cin, search);
		cout << "\n\t\t\t\tCURRENT RECORD" << endl;
		cout << "=============================================================================" << endl;
		for (int i = 0; i<n;i++){
			if (bookTitle[i] == search){
				counter++;
				cout << "|| BOOK ID: " << bookID[i] << endl;
				cout << "|| TITLE: " << bookTitle[i] << endl;
				cout << "|| AUTHOR: " << bookAuthor[i] << endl;
				cout << "|| PUBLISHER: " << bookPublisher[i] << endl;
				cout << "|| AVAILABILITY: " << bookAvailability[i] << endl;
				cout << "=============================================================================" << endl;
				cout << "                                                           Total Records: " << counter << endl;
			}
		}
				
		if (counter == 0){
				cout << "\n\t\t\t\tNO RECORD FOUND" << endl << endl;
				cout << "=============================================================================" << endl;
				cout << "                                                           Total Records: " << counter << endl;
			}
			
	}
	else if (select == 3){
		system("cls");
		cin.ignore();
		header2();
		cout << "\t\t\t\tSEARCHING A BOOK" << endl;
		cout << "\nSearch by Book Author: ";
		getline(cin, search);
		cout << "\n\t\t\t\tCURRENT RECORD" << endl;
		cout << "=============================================================================" << endl;
		for (int i = 0; i<n;i++){
			if (bookAuthor[i] == search){
				counter++;
				cout << "|| BOOK ID: " << bookID[i] << endl;
				cout << "|| TITLE: " << bookTitle[i] << endl;
				cout << "|| AUTHOR: " << bookAuthor[i] << endl;
				cout << "|| PUBLISHER: " << bookPublisher[i] << endl;
				cout << "|| AVAILABILITY: " << bookAvailability[i] << endl;
				cout << "=============================================================================" << endl;
				cout << "                                                           Total Records: " << counter << endl;
			}
		}
				
		if (counter == 0){
				cout << "\n\t\t\t\tNO RECORD FOUND" << endl << endl;
				cout << "=============================================================================" << endl;
				cout << "                                                           Total Records: " << counter << endl;
			}
	}
	else if (select == 4){
		system("cls");
		cin.ignore();
		header2();
		cout << "\t\t\t\tSEARCHING A BOOK" << endl;
		cout << "\nSearch by Book Publisher: ";
		getline(cin, search);
		cout << "\n\t\t\t\tCURRENT RECORD" << endl;
		cout << "=============================================================================" << endl;
		for (int i = 0; i<n;i++){
			if (bookPublisher[i] == search){
				counter++;
				cout << "|| BOOK ID: " << bookID[i] << endl;
				cout << "|| TITLE: " << bookTitle[i] << endl;
				cout << "|| AUTHOR: " << bookAuthor[i] << endl;
				cout << "|| PUBLISHER: " << bookPublisher[i] << endl;
				cout << "|| AVAILABILITY: " << bookAvailability[i] << endl;
				cout << "=============================================================================" << endl;
				cout << "                                                           Total Records: " << counter << endl;
			}
		}
				
		if (counter == 0){
				cout << "\n\t\t\t\tNO RECORD FOUND" << endl << endl;
				cout << "=============================================================================" << endl;
				cout << "                                                           Total Records: " << counter << endl;
			}
	}
	else if (select == 5){
		system("cls");
		int avail;
		header2();
		cout << "\t\t\t\tSEARCHING A BOOK" << endl;
		cout << "\nSearch by Book Availability" << endl;
		cout << "\n[1] Available or [2] Not Availble: ";
		cin >> avail;
		if (avail == 1){
			cout << "\n\t\t\t\tCURRENT RECORD" << endl;
			cout << "=============================================================================" << endl;
			for (int i = 0; i<n;i++){
				if (bookAvailability[i] == "Yes"){
				counter++;
				cout << "|| BOOK ID: " << bookID[i] << endl;
				cout << "|| TITLE: " << bookTitle[i] << endl;
				cout << "|| AUTHOR: " << bookAuthor[i] << endl;
				cout << "|| PUBLISHER: " << bookPublisher[i] << endl;
				cout << "|| AVAILABILITY: " << bookAvailability[i] << endl;
				cout << "=============================================================================" << endl;
				cout << "                                                           Total Records: " << counter << endl;
				}
			}
				
		}
		else if (avail == 2){
			cout << "\t\t\t\tCURRENT RECORD" << endl;
			cout << "=============================================================================" << endl;
			for (int i = 0; i<n;i++){
				if (bookAvailability[i] == "No"){
				counter++;
				cout << "|| BOOK ID: " << bookID[i] << endl;
				cout << "|| TITLE: " << bookTitle[i] << endl;
				cout << "|| AUTHOR: " << bookAuthor[i] << endl;
				cout << "|| PUBLISHER: " << bookPublisher[i] << endl;
				cout << "|| AVAILABILITY: " << bookAvailability[i] << endl;
				cout << "=============================================================================" << endl;
				cout << "                                                           Total Records: " << counter << endl;
				}
			}
			
		}
		if (counter == 0){
				cout << "\n\t\t\t\tNO RECORD FOUND" << endl << endl;
				cout << "=============================================================================" << endl;
				cout << "                                                           Total Records: " << counter << endl;
		}
	}
	else{
		cout << "\n\t\t    Returning to main menu" << endl << endl;
		cout << "\t\t    ";
	}
}

void updateBookData(string search){
	openFile(1);
	char title[100];
	char author[100];
	char publisher[100];
	int select;
	int n = bookID.size();
	getline(cin,search);
	int counter = 0;
	cout << "\n\t\t\t\tCURRENT RECORD" << endl;
	cout << "=============================================================================" << endl;
	for (int i = 0; i<n;i++){
		if (bookID[i] == search){
			counter++;
			cout << "|| BOOK ID: " << bookID[i] << endl;
			cout << "|| TITLE: " << bookTitle[i] << endl;
			cout << "|| AUTHOR: " << bookAuthor[i] << endl;
			cout << "|| PUBLISHER: " << bookPublisher[i] << endl;
			cout << "|| AVAILABILITY: " << bookAvailability[i] << endl;
			cout << "=============================================================================" << endl;
			cout << "\nAre You Sure You Want to update this Data?" << endl << endl;
			cout << "Yes[1] or No[0]: ";
			break;
			
		}
		
	}
	
	if (counter == 0){
		cout << "\n\t\t\t   Book ID Number not exist!" << endl << endl;
		cout << "=============================================================================" << endl;
	}
	else{
		while(!(cin >> select) || select >1 || select <0){
					cin.clear();
					cin.ignore(99999,'\n');
					cout << "Invalid Input" << endl;
					cout << "Yes[1] or No[0]: "; 
		}
		
		if (select == 1){
			system("cls");
			header2();
			cout << "\t\t\t   UPDATE BOOK INFORMATION" << endl;
			for (int i = 0; i<n;i++){
				if (bookID[i] == search){
					counter++;
					cout << "=============================================================================" << endl;
					cout << "|| BOOK ID: " << bookID[i] << endl;
					cin.ignore();
					cout << "|| NEW BOOK TITLE: ";
					cin.getline(title, 50);
					bookTitle.push_back(title);
					cout << "|| NEW AUTHOR NAME: ";
					cin.getline(author, 50);
					bookAuthor.push_back(author);
					cout << "|| NEW PUBLISHER NAME: ";
					cin.getline(publisher, 50);
					bookPublisher.push_back(publisher);
					cout << "|| AVAILABILITY: " << bookAvailability[i] << endl;
					cout << "=============================================================================" << endl;
					bookTitle[i] = title;
					bookAuthor[i] = author;
					bookPublisher[i] = publisher;
					bookAvailability[i] = bookAvailability[i];
					saveFile(1);
					cout << "\nUpdate Successful" << endl << endl;
					break;
				}
			}
		}
		else if (select == 0){
					cout << "\nTransaction Cancelled" << endl;
					cout << "\nReturning to Main Menu" << endl << endl;
				}
	}
	
}

void deleteBookData(string search){
	int n = bookID.size();
	int counter = 0;
	int select;
	cout << "\t\t\t\tCURRENT RECORD" << endl;
	cout << "=============================================================================" << endl;
	for (int i = 0;i<n;i++){
		if (bookID[i] == search){
			counter++;
			cout << "|| BOOK ID: " << bookID[i] << endl;
			cout << "|| TITLE: " << bookTitle[i] << endl;
			cout << "|| AUTHOR: " << bookAuthor[i] << endl;
			cout << "|| PUBLISHER: " << bookPublisher[i] << endl;
			cout << "|| AVAILABILITY: " << bookAvailability[i] << endl;
			cout << "=============================================================================" << endl;
			if (bookAvailability[i] == "No"){
				cout << "This Book has been Checked Out" << endl << endl;
				cout << "Cannot be DELETE!" << endl << endl;
				cout << "Transaction Cancelled" << endl << endl;
			}
			else{
				cout << "Are You Sure You Want to delete this Data?" << endl << endl;
				cout << "Yes[1] or [0]: ";
				while(!(cin >> select) || select >1 || select<0){
					cin.clear();
					cin.ignore(99999,'\n');
					cout << "Invalid Input" << endl;
					cout << "Yes[1] or [0]: ";
				}
				if (select == 1){
					bookID.erase(bookID.begin()+i);
					bookTitle.erase(bookTitle.begin()+i);
					bookAuthor.erase(bookAuthor.begin()+i);
					bookPublisher.erase(bookPublisher.begin()+i);
					bookAvailability.erase(bookAvailability.begin()+i);
					cout << "\nSuccesfully Deleted" << endl << endl;
					saveFile(1);
					break;
				}
				else{
					cout << "\nTransaction Cancelled" << endl;
					cout << "\nReturn to Main Menu" << endl << endl;
					break;
				}
			}
		}
	}
	if (counter == 0){
		cout << "\n\t\t\t   Book ID Number not exist!" << endl << endl;
		cout << "=============================================================================" << endl;
	}
}

void displayBookList(){
	openFile(1);
	int n = bookID.size();
	int counter = 0;
	cout << "\t\t\t     ALL RECORDS OF BOOK" << endl;
	cout << "=============================================================================" << endl;
	for (int i = 0; i<n;i++){	
			counter++;
			cout << "|| BOOK ID: " << bookID[i] << endl;
			cout << "|| TITLE: " << bookTitle[i] << endl;
			cout << "|| AUTHOR: " << bookAuthor[i] << endl;
			cout << "|| PUBLISHER: " << bookPublisher[i] << endl;
			cout << "|| AVAILABILITY: " << bookAvailability[i] << endl;
			cout << "=============================================================================" << endl;
			
	}
			
	if (counter == 0){
		cout << "\t\t\t\tEMPTY RECORD" << endl << endl;
		cout << "=============================================================================" << endl;
	}
	cout << "                                                           Total Records: " << counter << endl;
}

void addPatron(){
	char id[100];
	char name[100];
	char contact[100];
	string avail = "No";
	cin.ignore();
	Input:
	system("cls");
	header2();
	openFile(2);
	cout << "\t\t\t\tADDING A NEW PATREON" << endl;
	cout << "Patreon ID: ";
	cin.getline(id, 100);
	int n = patreonID.size();
	for (int i = 0;i<n;i++){
		if(id == patreonID[i]){
			cout << "Patreon ID Number Already Exist" << endl;
			system("pause");
			goto Input;
		}
	}
		patreonID.push_back(id);
		cout << "Patreon Name: ";
		cin.getline(name, 100);
		patreonName.push_back(name);
		cout << "Patreon CP #: ";
		cin.getline(contact, 100);
		patreonCP.push_back(contact);
		patreonAvail.push_back(avail);
		cout << "\nAdded Succesful!" << endl << endl;
		saveFile(2);
		patreonID.clear(); patreonName.clear(); patreonCP.clear();
}

void searchPatron(){
	openFile(2);
	cout << "\t\t\t\tSEARCHING A PATREON INFO" << endl;
	string search;
	int n = patreonID.size();
	int counter = 0;
	int select;
	cout << "\n\t\t\t\t  Search by: " << endl << endl;
	cout << "\t\t[1] Patreon ID" << endl << endl;
	cout << "\t\t[2] Patreon Name" << endl << endl;
	cout << "\t\t[0] Return to Main Menu" << endl << endl;
	cout << "\t\t    Select: ";
	while(!(cin >> select) || select > 2 || select < 0){
		cin.clear();
		cin.ignore(99999,'\n');
		cout << "\t\t    Invalid Input" << endl;
		cout << "\t\t    Select: ";
	}
	
	if (select == 1){
		system("cls");
		header2();
		cout << "\t\t\t\tSEARCHING A PATREON INFO" << endl;
		cout << "\nSearch by Patreon ID: ";
		cin >> search;
		cout << "\n\t\t\t\tCURRENT RECORD" << endl;
		cout << "=============================================================================" << endl;
		for (int i = 0; i<n;i++){
			if (patreonID[i] == search){
				counter++;
				cout << "|| PATREON ID: " << patreonID[i] << endl;
				cout << "|| NAME: " << patreonName[i] << endl;
				cout << "|| CONTACT #: " << patreonCP[i] << endl;
				cout << "|| BORROWED BOOKS: " << patreonAvail[i] << endl;
				cout << "=============================================================================" << endl;
				cout << "                                                           Total Records: " << counter << endl;
				break;
			}
		}
				
		if (counter == 0){
				cout << "\n\t\t\t\tNO RECORD FOUND" << endl << endl;
				cout << "=============================================================================" << endl;
				cout << "                                                           Total Records: " << counter << endl;
		}
	}
	else if (select == 2){
		system("cls");
		cin.ignore();
		header2();
		cout << "\t\t\t\tSEARCHING A PATREON INFO" << endl;
		cout << "\nSearch by Patreon Name: ";
		getline(cin, search);
		cout << "\n\t\t\t\tCURRENT RECORD" << endl;
		cout << "=============================================================================" << endl;
		for (int i = 0; i<n;i++){
			if (patreonName[i] == search){
				counter++;
				cout << "|| PATREON ID: " << patreonID[i] << endl;
				cout << "|| NAME: " << patreonName[i] << endl;
				cout << "|| CONTACT #: " << patreonCP[i] << endl;
				cout << "|| BORROWED BOOKS: " << patreonAvail[i] << endl;
				cout << "=============================================================================" << endl;
				cout << "                                                           Total Records: " << counter << endl;
			}
		}
				
		if (counter == 0){
				cout << "\n\t\t\t\tNO RECORD FOUND" << endl << endl;
				cout << "=============================================================================" << endl;
				cout << "                                                           Total Records: " << counter << endl;
			}
	}
	else{
		cout << "\n\t\t    Returning to main menu" << endl << endl;
		cout << "\t\t    ";
	}
	
}

void updatePatronData(string search){
	openFile(2);
	char name[100];//char variable for bookTitle with limit of 100 char
	char contact[100];//char variable for bookAuthor with limit of 100 char
	int select;
	int n = patreonID.size();
	getline(cin,search);
	int counter = 0;
	cout << "\n\t\t\t\tCURRENT RECORD" << endl;
	cout << "=============================================================================" << endl;
	for (int i = 0; i<n;i++){
		if (patreonID[i] == search){
			counter++;
			cout << "|| PATREON ID: " << patreonID[i] << endl;
			cout << "|| NAME: " << patreonName[i] << endl;
			cout << "|| CONTACT #: " << patreonCP[i] << endl;
			cout << "|| BORROWED BOOKS: " << patreonAvail[i] << endl;
			cout << "=============================================================================" << endl;
			cout << "\nAre You Sure You Want to update this Data?" << endl << endl;
			cout << "Yes[1] or No[0]: ";
			break;
		
		}
	}
	if (counter == 0){
		cout << "\n\t\t\t   Patron ID Number not exist!" << endl << endl;
		cout << "=============================================================================" << endl;
	}
	else{
		while(!(cin >> select) || select >1 || select <0){
				cin.clear();
				cin.ignore(99999,'\n');
				cout << "Invalid Input" << endl;
				cout << "Yes[1] or No[0]: "; 
		}
	
		if (select == 1){
			system("cls");
			header2();
			cout << "\t\t\t   UPDATE PATREON INFORMATION" << endl;
			for (int i = 0; i<n;i++){
				if (patreonID[i] == search){
					counter++;
					cout << "=============================================================================" << endl;
					cout << "|| PATREON ID: " << patreonID[i] << endl;
					cin.ignore();
					cout << "|| NEW PATREON NAME: ";
					cin.getline(name, 50);
					patreonName.push_back(name);
					cout << "|| NEW PATREON CONTACT #: ";
					cin.getline(contact, 50);
					patreonName.push_back(contact);
					cout << "|| BORROWED BOOKS: " << patreonAvail[i] << endl;
					cout << "=============================================================================" << endl;
					patreonName[i] = name;
					patreonCP[i] = contact;
					patreonAvail[i] = patreonAvail[i];
					saveFile(2);
					cout << "\nUpdate Successful" << endl << endl;
					break;
				}
			}
		}
		else if (select == 0){
					cout << "\nTransaction Cancelled" << endl;
					cout << "\nReturning to Main Menu" << endl << endl;
		}
	}
}

void deletePatronData(string search){
	int n = patreonID.size();
	int counter = 0;
	int select;
	cout << "\t\t\t\tCURRENT RECORD" << endl;
	cout << "=============================================================================" << endl;
	for (int i = 0;i<n;i++){
		if (patreonID[i] == search){
			counter++;
			cout << "|| PATREON ID: " << patreonID[i] << endl;
			cout << "|| NAME: " << patreonName[i] << endl;
			cout << "|| CONTACT #: " << patreonCP[i] << endl;
			cout << "|| BORROWED BOOKS: " << patreonAvail[i] << endl;
			cout << "=============================================================================" << endl;
			if (patreonAvail[i] == "Yes"){
				cout << "This Patron has been BORROWED a book" << endl << endl;
				cout << "Cannot be DELETE!" << endl << endl;
				cout << "Transaction Cancelled" << endl << endl;
			}
			else{
				cout << "Are You Sure You Want to delete this Data?" << endl << endl;
				cout << "Yes[1] or [0]: ";
				while(!(cin >> select) || select >1 || select<0){
					cin.clear();
					cin.ignore(99999,'\n');
					cout << "Invalid Input" << endl;
					cout << "Yes[1] or [0]: ";
				}
				if (select == 1){
					patreonID.erase(patreonID.begin()+i);
					patreonName.erase(patreonName.begin()+i);
					patreonCP.erase(patreonCP.begin()+i);
					cout << "\nSuccesfully Deleted" << endl << endl;
					saveFile(2);
					break;
				}
				else{
					cout << "\nTransaction Cancelled" << endl;
					cout << "\nReturn to Main Menu" << endl << endl;
					break;
				}
			}
		}
	}
	if (counter == 0){
		cout << "\n\t\t\t   Patreon ID Number not exist!" << endl << endl;
		cout << "=============================================================================" << endl;
	}
}

void displayPatronList(){
	openFile(2);
	int n = patreonID.size();
	int counter = 0;
	cout << "\t\t\t     ALL RECORDS OF PATREON" << endl;
	cout << "=============================================================================" << endl;
	for (int i = 0; i<n;i++){	
			counter++;
			cout << "|| PATREON ID: " << patreonID[i] << endl;
			cout << "|| NAME: " << patreonName[i] << endl;
			cout << "|| CONTACT #: " << patreonCP[i] << endl;
			cout << "|| BORROWED BOOKS: " << patreonAvail[i] << endl;
			cout << "=============================================================================" << endl;
			
	}
			
	if (counter == 0){
		cout << "\t\t\t\tEMPTY RECORD" << endl << endl;
		cout << "=============================================================================" << endl;
	}
	cout << "                                                           Total Records: " << counter << endl;
}

void checkOut(){
	cout << "\t\t\t   CHECK OUT BOOKS" << endl;
	cout << "\n(enter id not exist to exit)";
	TryAgain1:
	openFile(3);
	openFile(2);
	openFile(1);
	string borrowID;
	string borrowName;
	string borrowCP;
	string borrowAvail = "Yes";
	string patronSearch;
	int patron = 0;
	cout << "\nPatron ID: ";
	cin >> patronSearch;
	for (int i = 0; i<(int)patreonID.size();i++){
		if (patreonID[i] == patronSearch){
			cout << "=============================================================================" << endl;
			cout << "|| PATRON ID: " << patreonID[i] << endl;
			cout << "|| NAME: " << patreonName[i] << endl;
			cout << "|| CONTACT #: " << patreonCP[i] << endl;
			cout << "|| BORROWED BOOKS: " << patreonAvail[i] << endl;
			cout << "=============================================================================" << endl;
			if (patreonAvail[i] == "Yes"){
				cout << "Patron already check out a book" << endl;
				goto TryAgain1;
			}
			else if (patreonAvail[i] == "No"){
				cout << "Patron can check out a book" << endl;
				patron++;
				borrowID = patreonID[i];
				borrowName = patreonName[i];
				borrowCP = patreonCP[i];
				patreonAvail[i] = "Yes";
				break;
			}
		}
	}
	if (patron == 0){
		cout << "=============================================================================" << endl;
		cout << "\t\t\t\tEMPTY RECORD" << endl << endl;
		cout << "=============================================================================" << endl;
	}
	TryAgain2:
	string borrowBookID;
	string borrowBookTitle;
	string borrowBookAuthor;
	string borrowBookPublisher;
	string borrowBookAvailability = "No";
	int book = 0;
	string bookSearch;
	cout << "\n(enter id not exist to exit)";
	cout << "\nBook ID: ";
	cin >> bookSearch;
	for (int i = 0; i<(int)patreonID.size();i++){
		if (bookID[i] == bookSearch){
			cout << "=============================================================================" << endl;
			cout << "|| BOOK ID: " << bookID[i] << endl;
			cout << "|| TITLE: " << bookTitle[i] << endl;
			cout << "|| AUTHOR: " << bookAuthor[i] << endl;
			cout << "|| PUBLISHER: " << bookPublisher[i] << endl;
			cout << "|| AVAILABILITY: " << bookAvailability[i] << endl;
			cout << "=============================================================================" << endl;
			if (bookAvailability[i] == "No"){
				cout << "Book already check out" << endl;
				goto TryAgain2;
			}
			else if (bookAvailability[i] == "Yes"){
				cout << "Book can be check out" << endl;
				book++;
				borrowBookID = bookID[i];
				borrowBookTitle = bookTitle[i];
				borrowBookAuthor = bookAuthor[i];
				borrowBookPublisher = bookPublisher[i];
				bookAvailability[i] = "No";
				break;
			}
		}
	}
	if (patron == 0){
		cout << "=============================================================================" << endl;
		cout << "\t\t\t\tEMPTY RECORD" << endl << endl;
		cout << "=============================================================================" << endl;
	}
	
	if (patron == 1 && book == 1){
		checkPatronID.push_back(borrowID);
		checkPatronName.push_back(borrowName);
		checkPatronCP.push_back(borrowCP);
		checkPatronAvail.push_back(borrowAvail);
		checkBookID.push_back(borrowBookID);
		checkBookTitle.push_back(borrowBookTitle);
		checkBookAuthor.push_back(borrowBookAuthor);
		checkBookPublisher.push_back(borrowBookPublisher);
		checkBookAvailability.push_back(borrowBookAvailability);
		cout << "\nSuccessfully Check Out" << endl << endl;
		saveFile(1);
		saveFile(2);
		saveFile(3);
	}
	checkPatronID.clear(); checkPatronName.clear(); checkPatronCP.clear(); checkPatronAvail.clear(); checkBookID.clear();
	checkBookTitle.clear(); checkBookAuthor.clear(); checkBookPublisher.clear(); checkBookAvailability.clear();
}

void returnBooks(){
	cout << "\t\t\t   RETURN BOOKS" << endl;
	openFile(1);
	openFile(2);
	openFile(3);
	int n = checkBookID.size();
	int counter = 0;
	int select;
	string search;
	cout << "\n(enter id not exist to exit)";
	cout << "\nEnter Book ID: ";
	cin >> search;
	cout << "\t\t\t\tCURRENT RECORD" << endl;
	cout << "=============================================================================" << endl;
	for (int i = 0;i<n;i++){
		if (checkBookID[i] == search){
			counter++;
			cout << "|| BOOK ID: " << checkBookID[i] << endl;
			cout << "|| TITLE: " << checkBookTitle[i] << endl;
			cout << "|| AUTHOR: " << checkBookAuthor[i] << endl;
			cout << "|| PUBLISHER: " << checkBookPublisher[i] << endl;
			cout << "|| PATRON ID: " << checkPatronID[i] << endl;
			cout << "|| PATRON NAME: " << checkPatronName[i] << endl;
			cout << "|| PATRON CONTACT #: " << checkPatronCP[i] << endl;
			cout << "=============================================================================" << endl;
			cout << "Are You Sure You Want to Return this book?" << endl << endl;
			cout << "This Data will delete once the you return the book" << endl << endl;
			cout << "Yes[1] or [0]: ";
			break;
		}
	}
		if (counter == 0){
				cout << "\n\t\t\t   Book ID Number not exist!" << endl << endl;
				cout << "=============================================================================" << endl;
		}
		else{
			while(!(cin >> select) || select >1 || select<0){
				cin.clear();
				cin.ignore(99999,'\n');
				cout << "Invalid Input" << endl;
				cout << "Yes[1] or [0]: ";
			}
			for (int i = 0;i<n;i++){		
				if (select == 1){
					if (checkBookID[i] == search){
						checkBookID.erase(checkBookID.begin()+i);
						checkBookTitle.erase(checkBookTitle.begin()+i);
						checkBookAuthor.erase(checkBookAuthor.begin()+i);
						checkBookPublisher.erase(checkBookPublisher.begin()+i);
						checkBookAvailability.erase(checkBookAvailability.begin()+i);
						checkPatronID.erase(checkPatronID.begin()+i);
						checkPatronName.erase(checkPatronName.begin()+i);
						checkPatronCP.erase(checkPatronCP.begin()+i);
						checkPatronAvail.erase(checkPatronAvail.begin()+i);
						saveFile(3);
					}
					if (checkBookID[i] == bookID[i]){
						bookAvailability[i] = "Yes";
						saveFile(1);
					}
					if (checkPatronID[i] == patreonID[i]){
						patreonAvail[i] = "No";
						saveFile(2);
						cout << "\nSuccesfully Deleted" << endl << endl;
					}
					
			}
				else if (select == 0){
					cout << "\nTransaction Cancelled" << endl;
					cout << "\nReturn to Main Menu" << endl << endl;
					break;
				}
			}
		}
}

void displayCheckOut(){
	openFile(3);
	int counter = 0;
	int n = checkBookID.size();
	cout << "\t\t\tALL RECORDS OF CHECK OUT BOOK" << endl;
	cout << "=============================================================================" << endl;
	for (int i = 0; i<n;i++){	
			counter++;
			cout << "|| BOOK ID: " << checkBookID[i] << endl;
			cout << "|| TITLE: " << checkBookTitle[i] << endl;
			cout << "|| AUTHOR: " << checkBookAuthor[i] << endl;
			cout << "|| PUBLISHER: " << checkBookPublisher[i] << endl;
			cout << "|| PATRON ID: " << checkPatronID[i] << endl;
			cout << "|| PATRON NAME: " << checkPatronName[i] << endl;
			cout << "|| PATRON ID: " << checkPatronCP[i] << endl;
			cout << "=============================================================================" << endl;
	}
			
	if (counter == 0){
		cout << "\t\t\t\tEMPTY RECORD" << endl << endl;
		cout << "=============================================================================" << endl;
	}
	cout << "                                                           Total Records: " << counter << endl;
}
	
int main(){
	
	int option;
	string bookID;
	string patreonID;
	header();
	logIN();
do{
	system("cls");
	header2();
	cout << "[1]\tAdd a new book\t\t\t\t[6]\tAdd a new patron" << endl << endl;
	cout << "[2]\tSearch for a book\t\t\t[7]\tSearch Patron Info" << endl << endl;
	cout << "[3]\tUpdate a book\t\t\t\t[8]\tUpdate Patron Info" << endl << endl;
	cout << "[4]\tDelete a book\t\t\t\t[9]\tDelete Patron Info" << endl << endl;
	cout << "[5]\tDisplay all books\t\t\t[10]\tDisplay all Patron Info" << endl << endl;
	cout << "[11]\tCheck Out Books\t\t\t\t[12]\tReturn Books" << endl << endl;
	cout << "[13]\tDisplay Check Out\t\t\t[0]\tExit" << endl << endl << endl;
	cout << "\tSelect: ";
	while(!(cin>>option)|| option >13 || option <0){
		cin.clear();
		cin.ignore(99999,'\n');
		cout << "\tInvalid Input" << endl;
		cout << "\tSelect: ";
	} 
	switch (option){
		
		case 1: 
				addBookData();
				system("pause");
				system("cls");
				break;
		case 2: 
				cin.ignore();
				system("cls");
				header2();
				searchBooks();
				system("pause");
				system("cls");
				break;
		
		case 3: 
				cin.ignore();
				system("cls");
				header2();
				cout << "\t\t\t   UPDATE BOOK INFORMATION" << endl;
				cout << "Search by Book ID No.: ";
				updateBookData(bookID);
				system("pause");
				system("cls");
				break;
				
		case 4:
				cin.ignore();
				system("cls");
				header2();
				cout << "\t\t\t   DELETE BOOK INFORMATION" << endl;
				cout << "Search by Book ID No.: ";
				getline(cin, bookID);
				deleteBookData(bookID);
				system("pause");
				system("cls");
				break;
				
		case 5: system("cls");
				header2();
				displayBookList();
				system("pause");
				system("cls");
				break;
		
		case 6:
				addPatron();
				system("pause");
				system("cls");
				break;
				
		case 7:
				cin.ignore();
				system("cls");
				header2();
				searchPatron();
				system("pause");
				system("cls");
				break;
		
		case 8:	
				cin.ignore();
				system("cls");
				header2();
				cout << "\t\t\t   UPDATE PATREON INFORMATION" << endl;
				cout << "Search by Patreon ID No.: ";
				updatePatronData(patreonID);
				system("pause");
				system("cls");
				break;
		
		case 9:
				cin.ignore();
				system("cls");
				header2();
				cout << "\t\t\t   DELETE PATREON INFORMATION" << endl;
				cout << "Search by Patreon ID No.: ";
				getline(cin, patreonID);
				deletePatronData(patreonID);
				system("pause");
				system("cls");
				break;
				
		case 10:
				system("cls");
				header2();
				displayPatronList();
				system("pause");
				system("cls");
				break;
				
		case 11: 
				system("cls");
				header2();
				checkOut();
				system("pause");
				system("cls");
				break;
				
		case 12: 
				system("cls");
				header2();
				returnBooks();
				system("pause");
				system("cls");
				break;
				
		case 13:
				system("cls");
				header2();
				displayCheckOut();
				system("pause");
				system("cls");
				break;
	
	}
}while (option!=0);
}
