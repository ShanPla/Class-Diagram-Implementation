#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

	int counter;
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
		
		int total, i, itemQuantity, itemPrice;
		string cartID, itemName;
		
	
	public:
		
		void setTotal(int a){
			
			total += a;
	}
	
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
		shoppingCart Items[33];
	
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
	cin>>ans;
		
}

void viewProduct(cartHolder& cart){
	
	int quantity, Price;
	string Name;
	
	for(int i = 0; i<3; i++){
	
	cout<<"\n====================================================="<<endl;
	cout << left << setw(nameWidth) << setfill(separator) << "Order ID";
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
	cart.Items[i].setQuantity(quantity);
	
	if(ans == "ABC"){
		
		Name = "Rope";
		cart.Items[i].setName(Name);
		quantity*150;
		Price = 150;
	
	}
	
	else if(ans == "DEF"){
		
		Name = "Toaster";
		cart.Items[i].setName(Name);
		quantity*500;
		Price = 500;
		
	}
	
	else if(ans == "GHI"){
		
		Name = "Alcohol";
		cart.Items[i].setName(Name);
		quantity*350;
		Price = 350;
		
	}
	
	else{
		cout<<"\nInvalid Input.";
		i--;
	}
	
	cart.Items[i].setPrice(Price);
	cart.Items[i].setTotal(quantity);
	cin.ignore();
	
	cout<<"\nItem Added to Cart Successfully!"<<endl;	
	
counter++;
}
}

void viewCart(cartHolder& cart){
	
	cout<<"\n====================================================="<<endl;
	cout << left << setw(nameWidth) << setfill(separator) << "Order ID";
	cout << left << setw(nameWidth) << setfill(separator) << "Name";
	cout << left << setw(nameWidth) << setfill(separator) << "Price";
	cout << left << setw(nameWidth) << setfill(separator) << "Quantity";	
		
	for(int i = 0; i<counter; i++){
		
	cout<<"\n";
	cout << left << setw(nameWidth) << setfill(separator) << cart.Items[i].getID();
	cout << left << setw(nameWidth) << setfill(separator) << cart.Items[i].getName();
	cout << left << setw(nameWidth) << setfill(separator) << cart.Items[i].getPrice();
	cout << left << setw(nameWidth) << setfill(separator) << cart.Items[i].getQuantity();
	cout<<"\n====================================================="<<endl;
		
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
	cartHolder cart;
	Account();
	Menu();
	
	if (ans == "1"){
		viewProduct(cart);
	}
	if (ans == "2"){
			viewCart(cart);
		
	}
//	if (ans == '3'){
//		viewOrder();
//	}
viewCart(cart);
return 0;	
}
