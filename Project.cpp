#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <conio.h>

using namespace std;


	vector<string>bookID;
	vector<string>bookTitle;
	vector<string>bookAuthor;
	vector<string>bookPublisher;
	vector<string>bookAvailability;
	vector<string>userName;
	vector<string>passWord;
	vector<string>patreonID;
	vector<string>patreonName;
	vector<string>patreonCP;
	
void openFile(int n){
	string word;
	int pos = 0;
	ifstream myfile;
	if(n==1) myfile.open("bookData.txt");
	if(n==2) myfile.open("patronData.txt");
	if(n==3) myfile.open("checkoutData.txt");
	if(myfile.is_open()){
		if(n==1){bookID.clear(); bookTitle.clear(); bookAuthor.clear(); bookPublisher.clear(); bookAvailability.clear();}
		if(n==2){patreonID.clear(); patreonName.clear(); patreonCP.clear();}
		while(getline(myfile,word)){
			if(n==1){
				if(pos == 0 and word.size()!=0) bookID.push_back(word);
				if(pos == 1 and word.size()!=0) bookTitle.push_back(word);
				if(pos == 2 and word.size()!=0) bookAuthor.push_back(word);
				if(pos == 3 and word.size()!=0) bookPublisher.push_back(word);
				if(pos == 4 and word.size()!=0) bookAvailability.push_back(word);
			}
			if(n==2){
				if(pos == 0 and word.size()!=0) patreonID.push_back(word);
				if(pos == 1 and word.size()!=0) patreonName.push_back(word);
				if(pos == 2 and word.size()!=0) patreonCP.push_back(word);
			}
//			if(n==3){
//				
//			}
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
				mf << patreonCP[i] << "\n\n";
			}
		}
//		if(n==3){
//			for (int i = 0; i<bookID.size();i++){
//				fstream mf("bookData.txt", ios::app);
//				mf << bookID[i] << "\n";
//				mf << bookTitle[i] << "\n";
//				mf << bookAuthor[i] << "\n";
//				mf << bookPublisher[i] << "\n";
//				mf << bookAvailability[i] << "\n\n";
//			}
//		}
		myfile.close();
	}
}


//for(int i = 0; i < v.size(); i++){
//	for(int j = 0; j < v.size()-1;j++){
//		if(patronAge[j] > patronAge[j+1]){
//			swap(patronAge[j],patronAge[j+1]);
//			swap(patronName[j],patronName[j+1]);
//			swap
//		}
//	}
//}


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
	
	
	char id[5];//char variable for bookID with limit of 5 char
	char title[100];//char variable for bookTitle with limit of 100 char
	char author[100];//char variable for bookAuthor with limit of 100 char
	char publisher[100];//char variable for bookPublisher with limit of 100 char
	string avail = "Yes";
	cin.ignore();
	Input:
	system("cls");
	header2();
	openFile(1);
	cout << "\t\t\t\tADDING A NEW BOOK" << endl;
	cout << "Book ID: ";
	cin.getline(id, 5);
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
	cout << "\t\t\t\tSEARCHING A BOOK" << endl;
	string search;
	int n = bookID.size();
	int counter = 0;
	int select;
	cout << "\n\t\t\t\t  Search by: " << endl << endl;;
	cout << "\t\t[1] Book ID\t\t\t[2] Book Tittle" << endl << endl;;
	cout << "\t\t[3] Boook Author\t\t[4] Book Publisher" << endl << endl;;
	cout << "\t\t[5] Book Availability\t\t[0] Return to Main Menu" << endl << endl;;
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
	
	char title[100];//char variable for bookTitle with limit of 100 char
	char author[100];//char variable for bookAuthor with limit of 100 char
	char publisher[100];//char variable for bookPublisher with limit of 100 char
	string avail = "Yes";
	int select;
	int n = bookID.size();
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
			while(!(cin >> select) || select >1 || select <0){
				cin.clear();
				cin.ignore(99999,'\n');
				cout << "Invalid Input" << endl;
				cout << "Yes[1] or No[0]: "; 
			}
		}
		if (counter == 0){
			cout << "\n\t\t\t   Book ID Number not exist!" << endl << endl;
			cout << "=============================================================================" << endl;
			break;
		}
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
				bookAvailability[i] = avail;
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
			cout << "                                                           Total Records: " << counter << endl;
	if (counter == 0){
		cout << "\t\t\t\tEMPTY RECORD" << endl << endl;
	}
	
}

void addPatron(){
	char id[5];//char variable for bookID with limit of 5 char
	char name[100];//char variable for bookTitle with limit of 100 char
	char contact[100];//char variable for bookAuthor with limit of 100 char
	cin.ignore();
	Input:
	system("cls");
	header2();
	openFile(2);
	cout << "\t\t\t\tADDING A NEW PATREON" << endl;
	cout << "Patreon ID: ";
	cin.getline(id, 5);
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
		cout << "\nAdded Succesful!" << endl << endl;
		saveFile(2);
		patreonID.clear(); patreonName.clear(); patreonCP.clear();
}

void searchPatron(){
	cout << "\t\t\t\tSEARCHING A PATREON INFO" << endl;
	string search;
	int n = patreonID.size();
	int counter = 0;
	int select;
	cout << "\n\t\t\t\t  Search by: " << endl << endl;;
	cout << "\t\t[1] Patreon ID" << endl << endl;;
	cout << "\t\t[2] Patreon Name" << endl << endl;;
	cout << "\t\t[0] Return to Main Menu" << endl << endl;;
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
	
	char name[100];//char variable for bookTitle with limit of 100 char
	char contact[100];//char variable for bookAuthor with limit of 100 char
	int select;
	int n = patreonID.size();
	int counter = 0;
	cout << "\n\t\t\t\tCURRENT RECORD" << endl;
	cout << "=============================================================================" << endl;
	for (int i = 0; i<n;i++){
		if (patreonID[i] == search){
			counter++;
			cout << "|| PATREON ID: " << patreonID[i] << endl;
			cout << "|| NAME: " << patreonName[i] << endl;
			cout << "|| CONTACT #: " << patreonCP[i] << endl;
			cout << "=============================================================================" << endl;
			cout << "\nAre You Sure You Want to update this Data?" << endl << endl;
			cout << "Yes[1] or No[0]: ";
			while(!(cin >> select) || select >1 || select <0){
				cin.clear();
				cin.ignore(99999,'\n');
				cout << "Invalid Input" << endl;
				cout << "Yes[1] or No[0]: "; 
			}
		}
		if (counter == 0){
			cout << "\n\t\t\t   Book ID Number not exist!" << endl << endl;
			cout << "=============================================================================" << endl;
			break;
		}
	}
	
	if (select == 1){
		system("cls");
		header2();
		cout << "\t\t\t   UPDATE PATREON INFORMATION" << endl;
		for (int i = 0; i<n;i++){
			if (patreonID[i] == search){
				counter++;
				cout << "=============================================================================" << endl;
				cout << "|| PATREON ID: " << bookID[i] << endl;
				cin.ignore();
				cout << "|| NEW PATREON NAME: ";
				cin.getline(name, 100);
				bookTitle.push_back(name);
				cout << "|| NEW PATREON CONTACT #: ";
				cin.getline(contact, 100);
				bookAuthor.push_back(contact);
				cout << "=============================================================================" << endl;
				patreonName[i] = name;
				patreonCP[i] = contact;
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
			cout << "=============================================================================" << endl;
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
			cout << "=============================================================================" << endl;
			
	}
			cout << "                                                           Total Records: " << counter << endl;
	if (counter == 0){
		cout << "\t\t\t\tEMPTY RECORD" << endl << endl;
	}
	
}

void checkOut(){
		system("cls");
		header2();
		string patSearch;
		string bookSearch;
		int n = patreonID.size();
		int m = bookID.size();
		int counter = 0;
		cout << "\t\t\t\tCHECK OUT BOOKS" << endl;
		Input:
		cout << "\nPatreon ID: ";
		cin >> patSearch;
		cout << "=============================================================================" << endl;
		for (int i = 0; i<n;i++){
			if (patreonID[i] == patSearch){
				counter++;
				cout << "|| PATREON ID: " << patreonID[i] << endl;
				cout << "|| NAME: " << patreonName[i] << endl;
				cout << "|| CONTACT #: " << patreonCP[i] << endl;
				cout << "=============================================================================" << endl;
			}
			if (counter == 0){
				cout << "\n\t\t\t\tNO RECORD FOUND" << endl << endl;
				cout << "=============================================================================" << endl;
				goto Input;
			}
		}
				
		Input2:
		counter = 0;
		cout << "Enter Book ID: ";
		cin >> bookSearch;
		cout << "=============================================================================" << endl;
		for (int i = 0; i<m;i++){
			if (bookID[i] == bookSearch){
				counter++;
				cout << "|| BOOK ID: " << bookID[i] << endl;
				cout << "|| TITLE: " << bookTitle[i] << endl;
				cout << "|| AUTHOR: " << bookAuthor[i] << endl;
				cout << "|| PUBLISHER: " << bookPublisher[i] << endl;
				cout << "|| AVAILABILITY: " << bookAvailability[i] << endl;
				cout << "=============================================================================" << endl;
			}
			if (counter == 0){
				cout << "\n\t\t\t\tNO RECORD FOUND" << endl << endl;
				cout << "=============================================================================" << endl;
				goto Input2;
			}
		}
		
		for (int i = 0; i<m;i++){
			if (bookAvailability[i] == "No"){
				cout << "This Boook is already Checked Out" << endl;
				break;
			}
			else{
				cout << "Check Out Successful" << endl;
				bookAvailability[i] = "No";
				break;
			}
		}

}


	
int main(){
	
	int option;
	string bookID;
	string patreonID;
//	header();
//	logIN();
do{
	system("cls");
	header2();
	cout << "[1]\tAdd a new book\t\t\t\t[6]\tAdd a new patron" << endl << endl;
	cout << "[2]\tSearch for a book\t\t\t[7]\tSearch Patron Info" << endl << endl;
	cout << "[3]\tUpdate a book\t\t\t\t[8]\tUpdate Patron Info" << endl << endl;
	cout << "[4]\tDelete a book\t\t\t\t[9]\tDelete Patron Info" << endl << endl;
	cout << "[5]\tDisplay all books\t\t\t[10]\tDisplay all Patron Info" << endl << endl;
	cout << "[11]\tCheck Out Books\t\t\t\t[12]\tReturn Books" << endl << endl << endl;
	cout << "\tSelect: ";
	while(!(cin>>option)|| option >12 || option <0){
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
				getline(cin, bookID);
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
				getline(cin, patreonID);
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
				checkOut();
				system("pause");
				system("cls");
				break;
		
	}
}while (option!=0);
//	saveFile();
}
