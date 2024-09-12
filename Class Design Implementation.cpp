#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

	int counter = 0, total, Ans;
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

class shoppingCart{
	
	private:
		
		int itemQuantity, itemPrice;
		string cartID, itemName;
		
	
	public:
		
		void setQuantity(int b){
			
			itemQuantity = b;
			
		}
	
		void setPrice(int c){
			itemPrice = c;
		}
		
		void setID(string a){
			
			cartID = a;
			
		}
		
		void setName(string b){
			itemName = b;
		}

		int getQuantity(){
			return itemQuantity;
		}
		
		int getPrice(){
			return itemPrice;
		}
		
		string getID(){
			return cartID;
		}
		
		string getName(){
			return itemName;
		}
};

class cartHolder{
	
	public:
		shoppingCart Items[10];
	
	friend void viewProduct(cartHolder& cart);
	friend void viewCart(cartHolder& cart);	
};
	


void Menu(){
	
	cout<<"Options";
	cout<<"\n1. View Products";
	cout<<"\n2. View Shopping Cart";
	cout<<"\n3. View Orders";
	cout<<"\n4. Exit";
	cout<<"\nEnter choice: ";
	cin>>Ans;
		
}

void viewProduct(cartHolder& cart){
	
	int quantity, Price;
	string Name;
	char choice;
	
	for(int i = 0; i<10; i++){
	
	cout<<"\n====================================================="<<endl;
	cout << left << setw(nameWidth) << setfill(separator) << "Product ID";
	cout << left << setw(nameWidth) << setfill(separator) << "Name";
	cout << left << setw(nameWidth) << setfill(separator) << "Price";
	cout<<"\n";
	cout << left << setw(nameWidth) << setfill(separator) << "ABC";
	cout << left << setw(nameWidth) << setfill(separator) << "Rope";
	cout << left << setw(nameWidth) << setfill(separator) << "150php";
	cout<<"\n";
	cout << left << setw(nameWidth) << setfill(separator) << "DEF";
	cout << left << setw(nameWidth) << setfill(separator) << "Toaster";
	cout << left << setw(nameWidth) << setfill(separator) << "500php";
	cout<<"\n";
	cout << left << setw(nameWidth) << setfill(separator) << "GHI";
	cout << left << setw(nameWidth) << setfill(separator) << "Alcohol";
	cout << left << setw(nameWidth) << setfill(separator) << "350php";
	cout<<"\n====================================================="<<endl;
	
	cout<<"\nEnter the ID of the product you want to add in the shopping cart: ";
	cin>>ans;
	transform(ans.begin(), ans.end(), ans.begin(), ::toupper);
	
	cart.Items[i].setID(ans);
	
	cout<<"\nEnter Quantity: ";
	cin>>quantity;
	cin.ignore();
	cart.Items[i].setQuantity(quantity);
	
	if(ans == "ABC"){
		
		Name = "Rope";
		total += quantity*150;
		Price = 150;
	
	}
	
	else if(ans == "DEF"){
		
		Name = "Toaster";
		total += quantity*500;
		Price = 500;
		
	}
	
	else if(ans == "GHI"){
		
		Name = "Alcohol";
		total += quantity*350;
		Price = 350;
		
	}
	
	cart.Items[i].setName(Name);
	cart.Items[i].setPrice(Price*quantity);
	
	if(ans != "ABC" && ans != "DEF" && ans != "GHI"){
		
		cout<<"\nInvalid Input."<<endl;
		i--;
		counter--;
	}
	else{
		cout<<"\nItem Added to Cart Successfully!"<<endl;
	}
	
	counter++;	
	
	cout<<"Do you want to add another product? (Y/N): ";
	cin>>choice;
	cout<<"\n";
	
	if(choice == 'n' || choice == 'N'){
		break;
	}
	
}
	Menu();
}

void viewCart(cartHolder& cart){
	
//	for(int j = 0; j<counter; j++){
	cout<<"\n====================================================="<<endl;
//	cout<<"Order No."<<j<<":"<<endl;
	cout<<"Total Amount: "<<total<<endl;
	cout<<"Order Details: "<<endl;
	cout << left << setw(nameWidth) << setfill(separator) << "Product ID";
	cout << left << setw(nameWidth) << setfill(separator) << "Name";
	cout << left << setw(nameWidth) << setfill(separator) << "Price";
	cout << left << setw(nameWidth) << setfill(separator) << "Quantity";	
		
	for(int i = 0; i<counter; i++){
		
	cout<<"\n";
	cout << left << setw(nameWidth) << setfill(separator) << cart.Items[i].getID();
	cout << left << setw(nameWidth) << setfill(separator) << cart.Items[i].getName();
	cout << left << setw(nameWidth) << setfill(separator) << cart.Items[i].getPrice();
	cout << left << setw(nameWidth) << setfill(separator) << cart.Items[i].getQuantity();
		
}
	cout<<"\n====================================================="<<endl;
//}
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
	
		if (accName.compare(Account.getName()) == 0 && accPass.compare(Account.getPass()) == 0){
		
		cout<<"\nLogin Successful!\n"<<endl;
		isLoggedIn = true;
		}
		
		else if (accPass.compare(Account.getPass()) == 1){
		
			cout<<"\nWrong Username or Password.\n"<<endl;	
	}
	 	
	}
	 
	else if (ans=="2"){
	 	
	 	cout<<"\nEnter Username: ";
		cin>>accName;
		Account.setName(accName);
	
		cout<<"Enter Password: ";
		cin>>accPass;
		Account.setPass(accPass);

		cout<<"\nRegistration Successful!\n"<<endl;
	 	
	 }

}while(isLoggedIn != true);
}




int main(){
	
	cartHolder cart;
	Account();
	Menu();
	
//	while(true){
	
	if (Ans == 1){
		viewProduct(cart);
	}
 	if (Ans == 2){
		viewCart(cart);
	}
//	if (ans == '3'){
//		viewOrder();
//	}
	if(Ans == 4){
		cout<<"\nTerminating program...";
//		break;
	}
//};

return 0;	
}
