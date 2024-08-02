/*

add new person with min accound balance
add to the person account
remove from the person account
show there transacation history
and  that's it


lets breakdown this project into further small pieces
intitally no person is there in the bank
we would first add a person with minimum amount to be 1000 rs with that
then we have to make a data structure in which we have to store the amount and the transaction history
along with that we are going to give each transaction an transaction id and with this
so we are going to break this into more smaller pieces that is

step by step

each time we will show them the options to
one add the person with the intial amount


second deposit the amount into the persons account

third withdraw the amount if possible and the minimum balance should be maintained

fourth if they want the show the transaction amount

fifth exit the option


make a id of a person by system default give them a name and the minimum amount using the user input also make
them to check if the minimum amount should be atleast the amount which have been dedicated to the user

in the next step we are going to  deposit the amount
and add it to the just previous transaction


in the next step we are going to  withdraw the amount from the last transaction we can authenticate the person
as we as the system is doing this so no need to autheticate it


in the last step we are going to show the entire transaction history of the person


so we are going to decide the data structure for the entire things mostly it will be vector only


*/
#include <iostream>
using namespace std;
vector<pair<string,int>> persons;

struct person{
	string name;
	int age;
	int initial_amount;
	void add(string name,int initial_amount){
		cout<<"the name of the person is " <<name<<endl;
		cout <<"the initial amount of the person is "<<initial_amount<<endl;
		persons.push_back({name,initial_amount});
	}
};
void display(){
		cout<<"press 1 for adding user"<<endl;
		cout<<"press 2 for showing bank balance"<<endl;
		cout<<"press 3 for depositing money "<<endl;
                cout<<"press 4 for  withdrawing the money"<<endl;
                cout<<"press 5 for exiting"<<endl;
}
int main(){
	while(true){
		display();
		int n;
		cin>>n;
		if(n==1){
			//adding user here
			string name;int i_amount;
			cin>>name<<i_amount;
			person p1;
			p1.name = name;
			p1.initial_amount = i_amount;

		}else if(n==2){
			//showing bank balance
		}else if(n==3){
			//depositing money in the account
		}else if(n==4){
	}
	//cout<<"hello world";
}
