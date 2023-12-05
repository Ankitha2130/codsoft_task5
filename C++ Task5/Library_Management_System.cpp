#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
void booksList();
void search_book();
void issue_book();
void return_book();
struct book{
	char title[50];
	char author[50];
	int ISBN;
	bool issue;
}b[10];

int main(){
	strcpy(b[0].title,"Making India Awesome");
	strcpy(b[0].author," Chetan Bhagat     ");
	b[0].ISBN=13546;
	strcpy(b[1].title,"Circle of Silence");
	strcpy(b[1].author,"    Preeti Singh      ");
	b[1].ISBN=54378;
	strcpy(b[2].title,"History of India");
	strcpy(b[2].author,"     Romila Thapar     ");
	b[2].ISBN=69471;
	strcpy(b[3].title,"Indian Philosophy");
	strcpy(b[3].author,"    Dr.S.Radhakrishnan");
	b[3].ISBN=98572;
	strcpy(b[4].title,"Life Divine");
	strcpy(b[4].author,"          Sri Aurbindo Ghosh");
	b[4].ISBN=36854;
	strcpy(b[5].title,"Panchatantra");
	strcpy(b[5].author,"         Vishnu Sharma     ");
	b[5].ISBN=14985;
	strcpy(b[6].title,"The Golden Gate");
	strcpy(b[6].author,"      Vikram Seth       ");
	b[6].ISBN=65768;
	strcpy(b[7].title,"The Songs of India");
	strcpy(b[7].author,"   Sarojini Naidu    ");
	b[7].ISBN=81290;
	strcpy(b[8].title,"The Way of the Wizard");
	strcpy(b[8].author,"Deepak Chopra     ");
	b[8].ISBN=16530;
	strcpy(b[9].title,"Wake Up India");
	strcpy(b[9].author,"       Annie Besant      ");
	b[9].ISBN=49128;
	for(int z=0;z<10;z++){
		b[z].issue=false;
	}
	cout<<endl;
	cout<<"***************************** LIBRARY MANAGEMENT SYSTEM *****************************"<<endl;
	cout<<endl;
	int choice;
	while(choice!=5){
		cout<<endl;
		cout<<"1.Book List"<<endl;
		cout<<"2.Search book"<<endl;
		cout<<"3.Book checkout"<<endl;
		cout<<"4.Book Return"<<endl;
		cout<<"5.Exit application"<<endl;
		cout<<endl;
		cout<<"Enter your choice : ";
		cin>>choice;
		cout<<endl;
		switch(choice){
			case 1: booksList();
					break;
			case 2: search_book();
					break;
			case 3: issue_book();
					break;
			case 4: return_book();
					break;
			case 5: break;
			default:cout<<"Invalid choice"<<endl;
		}
	}
	return 0;
}

void booksList(){
	cout<<"Available Books : "<<endl;
	cout<<endl;
	cout<<"      Book Title                                "<<"Book Author                                     "<<"ISBN"<<endl;
	cout<<endl;
	for(int i=0;i<10;i++){
		if(b[i].issue==false){
			cout<<(i+1)<<".    "<<b[i].title<<"                     "<<b[i].author<<"                              "<<b[i].ISBN<<"    [available]"<<endl;
		}
		else{
			cout<<(i+1)<<".    "<<b[i].title<<"                     "<<b[i].author<<"                              "<<b[i].ISBN<<"    [issued]"<<endl;
		}
	}
}
void search_book(){
	int search_choice;
	string search_key1;
	int search_key2;
	cout<<"Search by  1.Title    2.Author name    3.ISBN "<<endl;
	cin>>search_choice;
	if(search_choice==1) {
		cin.ignore();
		cout<<"Enter the book title  : ";
		getline(cin,search_key1);
		for(int k=0;k<10;k++){
			if(search_key1==b[k].title){
				cout<<endl;
				cout<<"      Book Title                                "<<"Book Author                                     "<<"ISBN"<<endl;
				if(b[k].issue==false){
					cout<<(k+1)<<".    "<<b[k].title<<"                     "<<b[k].author<<"                              "<<b[k].ISBN<<"    [available]"<<endl;
				}
				else{
					cout<<(k+1)<<".    "<<b[k].title<<"                     "<<b[k].author<<"                              "<<b[k].ISBN<<"    [issued]"<<endl;
				}
				cout<<endl;
				cout<<"Book found ."<<endl;
				cout<<endl;
				break;
			}
			else if(k==9 && (search_key2!=b[k].ISBN)){
				cout<<"No book found with this title"<<endl;
			}
		}
	}
	else if(search_choice==2) {
		cin.ignore();
		cout<<"Enter the author name  : ";
		getline(cin,search_key1);
		for(int n=0;n<10;n++){
			if(search_key1==b[n].author){
				cout<<endl;
				cout<<"      Book Title                                "<<"Book Author                                     "<<"ISBN"<<endl;
				if(b[n].issue==false){
					cout<<(n+1)<<".    "<<b[n].title<<"                     "<<b[n].author<<"                              "<<b[n].ISBN<<"    [available]"<<endl;
				}
				else{
					cout<<(n+1)<<".    "<<b[n].title<<"                     "<<b[n].author<<"                              "<<b[n].ISBN<<"    [issued]"<<endl;
				}
				cout<<endl;
				cout<<"Book found ."<<endl;
				cout<<endl;
				break;
			}
			else if(n==9 && (search_key2!=b[n].ISBN)){
				cout<<"No book found with this author name "<<endl;
			}
		}
	}
	else{
		cout<<"Enter the ISBN : ";
		cin>>search_key2;
		for(int j=0;j<10;j++){
			if(search_key2==b[j].ISBN){
				cout<<endl;
				cout<<"      Book Title                                "<<"Book Author                                     "<<"ISBN"<<endl;
				if(b[j].issue==false){
					cout<<(j+1)<<".    "<<b[j].title<<"                     "<<b[j].author<<"                              "<<b[j].ISBN<<"    [available]"<<endl;
				}
				else{
					cout<<(j+1)<<".    "<<b[j].title<<"                     "<<b[j].author<<"                              "<<b[j].ISBN<<"    [issued]"<<endl;
				}
				cout<<endl;
				cout<<"Book found ."<<endl;
				cout<<endl;
				break;
			}
			else if(j==9 && (search_key2!=b[j].ISBN)){
				cout<<"No book found with this ISBN"<<endl;
			}
		}
	}	
}
void issue_book(){
	int book_ISBN;
	cout<<"Enter the ISBN of the book to issue : ";
	cin>>book_ISBN;
	for(int i=0;i<10;i++){
		if(book_ISBN==b[i].ISBN){
			b[i].issue=true;
			cout<<"Book with "<<book_ISBN<<" is issued successfully";
			break;
		}
		else if(i==9 && (book_ISBN!=b[i].ISBN)){
			cout<<"No book found with this ISBN"<<endl;
		}
	}
}
void return_book(){
	int days,book_id;
	cout<<"Enter the number of days since you took the book : ";
	cin>>days;
	if(days<=15){
		cout<<"Thank you for returning the book within the permitted time ."<<endl;
	}
	else if((days>15)&&(days<=30)){
		cout<<"Rs.20 should be paid as a fine for late return of the book ."<<endl;
	}
	else if((days>30)&&(days<=45)){
		cout<<"Rs.30 should be paid as a fine for late return of the book ."<<endl;
	}
	else if((days>45)&&(days<=60)){
		cout<<"Rs.50 should be paid as a fine for late return of the book ."<<endl;
	}
	else{
		cout<<"Rs.100 should be paid as a fine for late return of the book ."<<endl;
	}
	cout<<"Enter the book ISBN of the book to be returned : ";
	cin>>book_id;
	for(int i=0;i<10;i++){
		if(book_id==b[i].ISBN){
			b[i].issue=false;
			cout<<"Book with "<<book_id<<" is returned successfully";
			break;
		}
		else if(i==9 && (book_id!=b[i].ISBN)){
			cout<<"No book found with this ISBN"<<endl;
		}
	}
}