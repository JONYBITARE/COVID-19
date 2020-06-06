#include <iostream>
#include <string>
#include <fstream>
#include<algorithm>
using namespace std;
int c = 0;

void changePass()//1
{
	string newu, newp;
	cout << "Give the new user: ";
	cin >> newu;
	cout << "Give the new pass: ";
	cin >> newp;
	ofstream ofs("E:\\projet programmationnn\\projet programmation 2\\english\\WHO_login.txt");
	ofs << newu << " " << newp;
	ofs.close();

}
struct pourcentage
{
	int nbc, nbd, nbr;//nbc=confirmer,nbd=deces,nbr=retour;	
	string nompays;
};
struct pays
{
	string username;
	string password;
	int nb;
	pourcentage per[50];
};
bool Searchcountry(string name)
{
	ifstream ifs("E:\\projet programmationnn\\projet programmation 2\\english\\Pays_login.txt");
	pays p;
	while (ifs >> p.username >> p.password)
	{
		if (p.username == name)
		{
			ifs.close();
			return true;
		}
	}
	ifs.close();
	return false;
}

void SaveNewcountry()
{
	pays p;
	cout << "Enter new country information:\nname: ";
	cin >> p.username;
	cout << "password: ";
	cin >> p.password;

	cout << "enter country name :";
	cin >> p.per[c].nompays;
	cout << "enter the total number of comfirmed cases :";
	cin >> p.per[c].nbc;
	cout << "enter the total number of deaths : ";
	cin >> p.per[c].nbd;
	cout << "enter the number of total recoveries: ";
	cin >> p.per[c].nbr;

	bool found;
	found = Searchcountry(p.per[c].nompays);
	if (!found)
	{
		ofstream ofs("E:\\projet programmationnn\\projet programmation 2\\english\\Pays_login.txt", ios::app);
		ofs << p.per[c].nompays << " " << p.per[c].nbc << " " << p.per[c].nbd << " " << p.per[c].nbr << " ";

		cout << "Country is saved. " << endl;
		ofs << endl;
		ofs.close();
	}

	else
	{
		ifstream ifs("E:\\projet programmationnn\\projet programmation 2\\english\\Pays_login.txt");
		ofstream ofs("E:\\projet programmationnn\\projet programmation 2\\english\\temp.txt", ios::app);
		pourcentage per;
		string pa_name;
		if (ifs.is_open())// >>p.per[0].nbc>>p.per[0].nbd>>p.per[0].nbr>>p.per[1].nbc>>p.per[1].nbd>>p.per[1].nbr>>p.per[2].nbc>>p.per[2].nbd>>p.per[2].nbr>>p.per[3].nbc>>p.per[3].nbd>>p.per[3].nbr>>p.per[4].nbc>>p.per[4].nbd>>p.per[4].nbr )         
		{
			int x;
			int count = 0;
			string tempo;
			while (getline(ifs, pa_name, '\n')) {
				tempo = pa_name.substr(0, pa_name.find(' '));
				if (tempo == p.per[c].nompays) {
					ofs << p.per[c].nompays << " " << p.per[c].nbc << " " << p.per[c].nbd << " " << p.per[c].nbr << endl;
				}
				else
					ofs << pa_name << endl;
			}
		}
		ifs.close();
		ofs.close();
		remove("E:\\projet programmationnn\\projet programmation 2\\english\\Pays_login.txt");
		rename("E:\\projet programmationnn\\projet programmation 2\\english\\temp.txt", "E:\\projet programmationnn\\projet programmation 2\\english\\Pays_login.txt");
		cout << "Country already exist and has been updated " << endl;
		c++;
	}
}

void searchcovid(string name)
{
	bool found = Searchcountry(name);
	if (!found)
	{
		cout << "country does not exist." << endl;
	}
	else
	{
		pays p;
		pourcentage per;
		float totc=0, totd=0, totr=0;
		
		if (found)
		{

			ifstream ifs("Pays_login.txt");

			while (ifs.read((char*)&per, sizeof(per)))
			{
				if (name == p.per[c].nompays) {
					totd += p.per[c].nbd;
					totc += p.per[c].nbc;
					totr += p.per[c].nbr;
					cout << "the number of comfirmed cases for" << p.per[c].nompays << "is" << totd;
					cout << "the number of deaths for" << p.per[c].nompays << "is" << totd;
					cout << "the number of recoveries for" << p.per[c].nompays << "is" << totr;
				}

			}
			ifs.close();
		}
	}
}
void Deletecovid(string name)
{
	float found = Searchcountry(name);
	if (!found)
	{
		cout << "country does not exist." << endl;
	}
	else
	{
		ifstream ifs("Pays_login.txt");
		ofstream ofs("temp.txt", ios::app);
		pays p;
		pourcentage per;
		while (ifs.read((char*)&per, sizeof(per)))
		{
			if (p.username != name)
			{
				ofs.write((char*)&per, sizeof(per));
			}
		}
		ifs.close();
		ofs.close();
		remove("Pays_login.txt");
		rename("temp.txt", "Pays_login.txt");
		cout << "country has been deleted." << endl;
	}
}

/*void average()
{
	courses c;
	double sum[5]={0,0,0,0,0};
	int count=0;
	student p;
	ifstream ifs("student.txt");
	while(ifs>>p.username>>p.password>>p.fullname>>p.c[0].namec>>p.c[0].grade>>p.c[1].namec>>p.c[1].grade>>p.c[2].namec>>p.c[2].grade>>p.c[3].namec>>p.c[3].grade>>p.c[4].namec>>p.c[4].grade)
	{
		count++;
		for(int i=0;i<5;i++)
		{
			sum[i]+=p.c[i].grade;
		}
}
ifs.close();
	for(int i=0;i<5;i++)
	{
	   cout<<"average of course "<<(i+1)<<" : "<<sum[i]/count<<" ";
	}
}
*/
/*float ordergpa()
{
	student p;
	courses c;
	int n=0;
	float tot;
	ifstream ifs("student.txt");
	while(ifs>>p.username>>p.password>>p.fullname>>p.c[0].namec>>p.c[0].grade>>p.c[1].namec>>p.c[1].grade>>p.c[2].namec>>p.c[2].grade>>p.c[3].namec>>p.c[3].grade>>p.c[4].namec>>p.c[4].grade)
			 {
				n++;//nbr of student
			 }
			 ifs.close();

	ifstream ifs1("student.txt");
			 float t[n];
			 int k=0;
	while(ifs1>>p.username>>p.password>>p.fullname>>p.c[0].namec>>p.c[0].grade>>p.c[1].namec>>p.c[1].grade>>p.c[2].namec>>p.c[2].grade>>p.c[3].namec>>p.c[3].grade>>p.c[4].namec>>p.c[4].grade)
			 {
				tot=0;
				for(int i=0;i<5;i++)
					{
					  tot+=p.c[i].grade;
					}
					t[k]=tot/5;
					k++;

			  }
			  ifs1.close();
		float temp;
	for(int i=0; i<n-1; i++)
	  for(int j=0; j < n-i-1; j++)
		 if(t[j] < t[j+1]){
			temp = t[j];
			t[j] = t[j+1];
			t[j+1] = temp;
		}
		cout<<endl<<" decreasing order by is gpa : ";
		for(int i=0;i<n;i++)
		cout<<t[i]<<"  ";
	}
 */
void Showcovid_decroissant(int n)
{
	ifstream ifs("Pays_login.txt");
	pays p;
	pourcentage per;
	int temp;
	cout << "Pays\t\t|\tDeces\n------------------------------------" << endl;

	while (ifs.read((char*)&per, sizeof(per)))//p.per[0].nbd>>p.nompays[0]>>p.per[1].nbd>>p.nompays[1]>>p.per[2].nbd>>p.nompays[2]>>p.per[3].nbd>>p.nompays[3]>>p.per[4].nbd>>p.nompays[4] )     
	{

		for (int i = 0; i <= n; i++)
			for (int j = i + 1; j <= n; j++)
				if (p.per[i].nbd < p.per[j].nbd) {
					temp = p.per[i].nbd;
					p.per[i].nbd = p.per[j].nbd;
					p.per[j].nbd = temp;
				}
	}


	ifs.close();
}
void Showcovid_croissant(int n)
{
	ifstream ifs("Pays_login.txt");
	int temp;
	pays p;
	cout << "Pays\t\t|\tRetour a Domicile\n------------------------------------" << endl;
	pourcentage per;
	while (ifs.read((char*)&per, sizeof(per)))
	{
		for (int i = 0; i <= n - 1; i++)
			for (int j = 0; j <= n - i - 1; j++)
				if (p.per[i].nbr < p.per[j].nbr) {
					temp = p.per[i].nbr;
					p.per[i].nbr = p.per[j].nbr;
					p.per[j].nbr = temp;
				}
	}

	ifs.close();
}

void showcovid(int n)
{
	ifstream ifs("Pays_login.txt");
	float totd, totc, totr;
	pourcentage per;
	pays p;
	while (ifs.read((char*)&per, sizeof(per)))
	{

		for (int i = 0; i <= n; i++)
		{
			totd = 0, totc = 0, totr = 0;
			totd += p.per[i].nbd;
			totc += p.per[i].nbc;
			totr += p.per[i].nbr;
			cout << "The number of comfirmed cases for" << p.per[i].nompays << "is" << totc << endl;
			cout << "The number of deaths for" << p.per[i].nompays << "is" << totd << endl;
			cout << "The number of recoveries at home" << p.per[i].nompays << "is" << totr << endl;
		}
	}
	ifs.close();

}
void percentage(int n) {
	pays p;
	pourcentage per;
	float *totd = new float[n];
	float *totc = new float[n];
	float *tot = new float[n];
	ifstream ifs1("Pays_login.txt");
	cout << "Pays\t\t|\tPourcentage de deces\n------------------------------------" << endl;
	while (ifs1.read((char*)&per, sizeof(per)))
	{
		for (int i = 0; i <= n; i++)
		{
			totd[i] = 0, totc[i] = 0;
			totd[i] += p.per[i].nbd;
			totc[i] += p.per[i].nbc;
			tot[i] = (totd[i] / totc[i]) * 100;
			cout << p.per[i].nompays << "\t\t|\t" << tot << endl;
		}

	}
	ifs1.close();
}

void showcovidall(int n)
{

	ifstream ifs("Pays_login.txt");
	float totd, totc, totr;
	pourcentage per;
	pays p;
	while (ifs.read((char*)&per, sizeof(per)))

		for (int i = 0; i <= n; i++)
		{
			totd = 0, totc = 0, totr = 0;
			totd += p.per[i].nbd;
			totc += p.per[i].nbc;
			totr += p.per[i].nbr;
		}
	cout << "The number of comfirmed cases for all countries is " << totc << endl;
	cout << "The number of deaths for all country is " << totd << endl;
	cout << "The number of recoveries at home for all country is " << totr << endl;

	ifs.close();
}

void ordrepays(int n)
{
	ifstream ifs("Pays_login.txt");
	int temp;
	pays p;
	cout << "Pays\t\t|\tRetour a Domicile\n------------------------------------" << endl;
	pourcentage per;
	while (ifs.read((char*)&per, sizeof(per)))
	{
		for (int i = 0; i <= n - 1; i++)
			for (int j = 0; j <= n - i - 1; j++)
				if (p.per[i].nbc < p.per[j].nbc) {
					temp = p.per[i].nbc;
					p.per[i].nbc = p.per[j].nbc;
					p.per[j].nbc = temp;
				}
	}

	ifs.close();

}

int main()
{
	struct pourcentage
	{
		int nbc, nbd, nbr;//nbc=confirmer,nbd=deces,nbr=retour;	
		string nompays;
	};
	struct pays
	{
		string username;
		string password;
		int nb;
		pourcentage per[50];
	};
	int nb;
	cout << "login as :" << endl;
	cout << "1- WHO" << endl << "2- Pays" << endl;
	cin >> nb;
	if (nb == 1)
	{
		string userName;
		string userPassword;
		bool loop = true;
		int loginAttempt = 0;
		string user;
		string pass;
		while (loginAttempt < 5)
		{
			cout << "Please enter your user name: ";
			cin >> userName;
			cout << "Please enter your user password: ";
			cin >> userPassword;
			ifstream ifs("E:\\projet programmationnn\\projet programmation 2\\english\\WHO_login.txt");
			ifs >> user >> pass;
			cout << user << endl;
			if (user == userName && pass == userPassword)
			{
				cout << "Welcome " << user << "!\n";
				break;
			}

			else
			{
				cout << "Invalid login attempt. Please try again.\n";
				loginAttempt++;
			}
		}
		if (loginAttempt == 5)
		{
			cout << "Too many login attempts! The program will now terminate. ";
			return 0;
		}

		cout << "Thank you for logging in.\n";
		loop = true;
		while (loop)
		{
			cout << endl << "now you have a list of option :" << endl << "1- change username and pass" << endl << "2- register country" << endl << "3-show number of deaths" << endl << "4-show number of persons returned at home" << endl << "5- show countries affected by COVID-19" << endl << "6-show total numbers of deaths,comfirmed cases and return at home" << endl << "7-show total numbers of deaths,comfirmed cases and return at home by name" << endl << "8-Delete a country affected by COVID-19 by name" << endl;
			char choice1;
			cin >> choice1;
			string kelme;


			switch (choice1)
			{
			case '1': changePass();

				break;
			case '2':  SaveNewcountry();
				break;
			case '3': {
				pays p;
				pourcentage per;
				Showcovid_decroissant(c);
				for (int i = 0; i <= c; i++)
					cout << p.per[i].nompays << "\t\t|\t\n" << p.per[i].nbd;
			}
					break;
			case '4': {
				pays p;
				pourcentage per;
				Showcovid_croissant(c);
				for (int i = 0; i <= c; i++)
					cout << p.per[i].nompays << "\t\t|\t\n" << p.per[i].nbr;
				break;
			}
			case '5':
				percentage(c);
				break;
			case '6':
				showcovidall(c);
				break;
			case '7':cout << "country name you want to search for: ";
				cin >> kelme;
				searchcovid(kelme);
				break;
			case '8':cout << "delete country : ";
				cin >> kelme;
				Deletecovid(kelme);
				break;
			default: loop = false;
			}
		}
	}
	else if (nb == 2)
	{

		string users, passs;
		pays p;
		int loginAttempts = 0;
		while (loginAttempts < 5) {
			cout << "Please enter your user name: ";
			cin >> users;
			cout << "Please enter your user password: ";
			cin >> passs;

			ifstream ifs1("Pays_login.txt");
			while (ifs1.read((char*)&p, sizeof(p)))
			{
				if (p.username == users && p.password == passs)
				{
					cout << "welcome " << users << " !" << endl;
					loginAttempts = +6;
				}
				else
				{
					cout << "Invalid login attempt. Please try again.\n";
					loginAttempts++;
				}
			}
			ifs1.close();
		}
		if (loginAttempts == 5)
		{
			cout << "Too many login attempts! The program will now terminate. ";
			return 0;
		}
		bool looop = true;
		while (looop)
		{
			cout << endl << "now you have a list of option :" << endl << "1- Show total number of comfirmed cases,deaths and recoveries" << endl << "2-Update number of comfirmed cases,deaths and recoveries " << endl << "3-Show number of affected persons in each country" << endl;
			int ra2em;
			cin >> ra2em;
			switch (ra2em)
			{
			case '1': 	showcovid(c);

				break;
			case '2': SaveNewcountry();
				break;
			case '3': {
				pays p;
				pourcentage per;
				Showcovid_croissant(c);
				for (int i = 0; i <= c; i++) {
					if (users == p.per[i].nompays)
						cout << "Dear" << p.per[i].nompays << " Your rank in term of comfirmed cases is " << i;
				}
				break;
			}
			default:looop = false;

			}

		}
	}
}



