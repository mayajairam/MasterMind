//Maya Jairam
//Mastermind
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int findspot(string ans,string guess,int length);
int finddigit(string ans,string guess,int length);
bool is_valid(string guess,int length);

int main(){
	srand(time(0));
	string ans = "";
	string guess = "";
	string numbers = "123456789";
	int length,range,count=0,movesleft;
	bool is_digit;
	//Displaying the welcome screen
	cout<< "\t\t\t\t  Welcome to Mastermind!"<<endl;
	cout<<"Here are the rules: "<<endl;
	cout<<"The computer will randomly generate a number. You have to guess what that number is based on the number of correct \ndigits and spots."<<endl;
	//bonus #3
	cout<<"You only have twelve tries."<<endl;
	//starting the game
	//bonus #1 and #2
	cout<<"How many digits would you like to guess? ";
	cin>>length;
	cout<<"What range would you like?(enter a digit) ";
	cin>>range;
	//creating the random number and preventing repeats
	for(int i = 0; i<length; i++){
		ans += numbers[rand()%range];
	}
	//bonus#5 preventing repeats by making sure the numbers before and after a certain element are different
	for(int i = 0; i<length; i++){
		for(int z = i+1 ; z<length; z++){
			do{
				if(ans[i]==ans[z])
					ans[z]= numbers[rand()%range];			
			}while(ans[i]==ans[z]);
		}
		for(int z= i-1 ; z>=0; z--){
			do{
				if(ans[i]==ans[z])
					ans[z]= numbers[rand()%range];			
			}while(ans[i]==ans[z]);
		}
	}
	//cout<<ans<<endl;
	//bonus #3	using a do while loop to limit the number of tries to allow the player to exit the game when they win
	do{
		cout<< "Enter your guess: ";
		cin>> guess;
		//bonus #4 using isalpha to check for letters and comparing lengths to see if the guess is valid
		do{
			if(guess.length()!=length){
				cout<<"Enter in a guess with the correct number of digits: ";
				cin>>guess;				
			}
		}while(guess.length()!=length);
		do{
			if(is_valid(guess,length)==false){
				cout<<"Enter in a valid guess: ";
				cin>>guess;
			}
		}while(is_valid(guess,length)==false);
		count+=1;
		movesleft=12-count;
		cout<< "Correct spots: "<<findspot(ans,guess,length)<<"\t";
		cout<< "Correct digits: "<<finddigit(ans,guess,length)<<"\t";
		cout<< "You have "<<movesleft<<" moves left.\n";
		if(ans==guess){
			cout<<"You won! :)";
		}
		}while(ans!=guess and count<12);
		if(count==12 and ans!=guess){
		cout<<"You lost! :(";			
		}	
}
int findspot(string ans,string guess,int length){
		int spots = 0;	
	for(int i = 0; i < length; i++){
		if(ans[i]==guess[i]){
			spots+=1;
		}
	}
	return spots;
}
int finddigit(string ans,string guess,int length){
	int digits = 0;
	for(int i = 0; i< length; i++){
		for(int y = 0; y< length; y++){
			if(ans[i] == guess[y]){
				digits+=1;
			}
		}
	}
	return digits;
}
bool is_valid(string guess, int length){
	for(int i = 0; i<length; i++){
		if(isalpha(guess[i])){
			return false;
		}
	}
	return true;
}