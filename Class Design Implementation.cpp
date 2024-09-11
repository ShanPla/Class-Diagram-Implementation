#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

	string accName, accPass, ans;
	bool isLoggedIn = false;
	const char separator    = ' ';
    const int nameWidth     = 15;


class Customer{
	
	private:
		string name, password;
	
	public:
		
		void setName(string a){
			name = a;
		}
		void setPass(string b){
			password = b;
		}
		
		string getName(){
			return name;
		}
		string getPass(){
			return password;
		}
};

class Product{
	
	private:

		int ropeQuantity, toasterQuantity, alcoholQuantity;
	
	public:
		void setRope(int a){
			ropeQuantity = a;
		}
		
		void setToaster(int b){
			toasterQuantity = b;
		}
		
		void setAlcohol(int c){
			alcoholQuantity = c;
		}
		
		int getRope(){
			return ropeQuantity;
		}
		
		int getToaster(){
			return toasterQuantity;
		}
		
		int getAlcohol(){
			return alcoholQuantity;
		}
};

//class Order{
//	
//	private:
//		int 
//	
//	
//	
//};


void Menu(){
	
	cout<<"Options";
	cout<<"\n1. View Products";
	cout<<"\n2. View Shopping Cart";
	cout<<"\n3. View Orders";
	cout<<"\n4. Exit";
	cout<<"\nEnter choice: ";
	cin>>ans;
		
}

void viewProduct(){
	
	Product Quantity;
//	Order Quantity;
	
	int quantity, rope = 15, toaster = 8, alcohol = 10;
	Quantity.setRope(rope);
	Quantity.setToaster(toaster);
	Quantity.setAlcohol(alcohol);
	
	
	cout<<"\n";
	cout << left << setw(nameWidth) << setfill(separator) << "Order ID";
	cout << left << setw(nameWidth) << setfill(separator) << "Name";
	cout << left << setw(nameWidth) << setfill(separator) << "Price";
	cout << left << setw(nameWidth) << setfill(separator) << "Quantity";
	cout<<"\n";
	cout << left << setw(nameWidth) << setfill(separator) << "ABC";
	cout << left << setw(nameWidth) << setfill(separator) << "Rope";
	cout << left << setw(nameWidth) << setfill(separator) << "150php";
	cout << left << setw(nameWidth) << setfill(separator) << Quantity.getRope();
	cout<<"\n";
	cout << left << setw(nameWidth) << setfill(separator) << "DEF";
	cout << left << setw(nameWidth) << setfill(separator) << "Toaster";
	cout << left << setw(nameWidth) << setfill(separator) << "500php";
	cout << left << setw(nameWidth) << setfill(separator) << Quantity.getToaster();
	cout<<"\n";
	cout << left << setw(nameWidth) << setfill(separator) << "GHI";
	cout << left << setw(nameWidth) << setfill(separator) << "Alcohol";
	cout << left << setw(nameWidth) << setfill(separator) << "350php";
	cout << left << setw(nameWidth) << setfill(separator) << Quantity.getAlcohol();
	cout<<"\n";
	
	cout<<"Enter the ID of the product you want to add in the shopping cart: ";
	cin>>ans;
	transform(ans.begin(), ans.end(), ans.begin(), ::tolower);

	if(ans == "abc"){
		cout<<"\nEnter Quantity: ";
		cin>>quantity;
		
		cout<<"\nItem Added to Cart Successfully!";
		
	}
	

	
}


void Account(){
	
	Customer Account;
	
	do{
	
	cout<<"1. Login";
	cout<<"\n2. Register";
	cout<<"\nPlease Sign in/Sign up to enter: ";
	cin>>ans;
	 
	 if (ans=="1"){
	 	
	 	cout<<"\nUsername: ";
		cin>>accName;
	
		cout<<"Password: ";
		cin>>accPass;
	
		if (accName.compare(Account.getName()) == 0){
		
		cout<<"Login Successful!"<<endl;
		isLoggedIn = true;
		}
		else if (accName.compare(Account.getName()) == 1){
		
		cout<<"\nWrong Username or Password."<<endl;
		
	}
	 	
	}
	 
	else if (ans=="2"){
	 	
	 	cout<<"\nEnter Username: ";
		cin>>accName;
		Account.setName(accName);
	
		cout<<"Enter Password: ";
		cin>>accPass;
		Account.setPass(accPass);

		cout<<"\nRegistration Successful!"<<endl;
	 	
	 }

}while(isLoggedIn != true);
}




int main(){
	
	Account();
	Menu();
	
	if (ans == "1"){
		viewProduct();
	}
//	if (ans == '2'){
//		viewCart();
//	}
//	if (ans == '3'){
//		viewOrder();
//	}

		
return 0;	
}