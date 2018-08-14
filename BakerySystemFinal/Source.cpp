#include <iostream>
#include <Windows.h>

#include "Product.h"
#include "Bakery.h"

void MainMenu(Bakery* Shop);
void BuyProductMenu(Bakery* Shop);
void CheckSalesMenu(Bakery* Shop);
void ProductPriceMenu(Bakery* Shop);
void ProductStockMenu(Bakery* Shop);

int GetUserInputInteger();
float GetUserInputFloat();

int main()
{
	Bakery* Shop = new Bakery();
	Product* BreadProduct = new Product("Bread", 5, 1.10);
	Product* Doughnut = new Product("Doughnut", 5, 0.50);
	Product* Scone = new Product("Scone", 5, 0.30);
	Product* Croissant = new Product("Croissant", 5, 0.60);
	Product* Cake = new Product("Cake", 5, 0);
	Product* Sausages = new Product("Sausages", 5, 8.00);

	Shop->AddProduct(BreadProduct);
	Shop->AddProduct(Doughnut);
	Shop->AddProduct(Scone);
	Shop->AddProduct(Croissant);
	Shop->AddProduct(Cake);
	Shop->AddProduct(Sausages);

	MainMenu(Shop);
}

void MainMenu(Bakery* Shop)
{
	int userSelection = NULL;
	cout << "Please select an option" << endl;
	cout << "1: Buy a Product" << endl;
	cout << "2: Check Sales" << endl;
	cout << "3: Edit Product Price" << endl;
	cout << "4: Edit Current Stock" << endl;
	cout << "5: Request Statistics Check" << endl;
	
	userSelection = GetUserInputInteger();

	switch (userSelection)
	{
	case 1:
		BuyProductMenu(Shop);
		break;
	case 2:
		CheckSalesMenu(Shop);
		break;
	case 3:
		ProductPriceMenu(Shop);
		break;
	case 4:
		ProductStockMenu(Shop);
		break;
	case 5:
		Shop->PrintAllProductStats();
		MainMenu(Shop);
		break;
	default:
		cout << "Incorrect Value!" << endl;
		MainMenu(Shop);
		break;
	}

}

int GetUserInputInteger()
{
	int userInput = NULL;
	cin.clear();
	cin >> userInput;

	while(cin.fail())
	{
		cout << "The entered value was incorrect" << endl;
		cin.clear();
		cin.ignore(256, '\n');
		cin >> userInput;
	}
	return userInput;
}

float GetUserInputFloat()
{
	float userInput = NULL;
	cin.clear();
	cin >> userInput;

	while (cin.fail())
	{
		cout << "The entered value was incorrect" << endl;
		cin.clear();
		cin.ignore(256, '\n');
		cin >> userInput;
	}
	return userInput;
}

void BuyProductMenu(Bakery* Shop)
{
	cout << "Please choose a product to buy:" << endl;
	Shop->ListAllProducts();

	int userSeletion = GetUserInputInteger();

	cout << "How many of items of this product would you like to buy?" << endl;

	int productsToBuy = GetUserInputInteger();
	system("CLS");
	bool boughtProduct = Shop->BuyProduct(userSeletion - 1, productsToBuy);

	Sleep(7500);
	system("CLS");
	MainMenu(Shop);
}

void CheckSalesMenu(Bakery* Shop)
{
	system("CLS");
	cout << "1: Check a product sales" << endl;
	cout << "2: Check all product sales" << endl;

	int userSelection = GetUserInputInteger();

	switch (userSelection)
	{
	case 1:
		system("CLS");
		Shop->ListAllProducts();
		userSelection = GetUserInputInteger();
		Shop->GetSalesSingleProduct(userSelection - 1);
		break;
	case 2:
		Shop->GetSalesAllProducts();
	default:
		break;
	}
	cout << endl;
	MainMenu(Shop);
}

void ProductPriceMenu(Bakery* Shop)
{
	system("CLS");
	cout << "Choose a product to change price." << endl;
	Shop->ListAllProducts();
	
	int userSelection = GetUserInputInteger();

	cout << endl;
	cout << "What price would you like to set it as: \x9C";

	float productPrice = GetUserInputFloat();
	Shop->SetProductPrice(userSelection - 1, productPrice);
	cout << endl;
	MainMenu(Shop);
}

void ProductStockMenu(Bakery* Shop)
{
	system("CLS");
	cout << "Choose a product to change stock." << endl;
	Shop->ListAllProducts();

	int userSelection = GetUserInputInteger();

	cout << endl;
	cout << "What stock would you like to set the product to: ";
	int productStock = GetUserInputInteger();

	Shop->SetProductStock(userSelection - 1, productStock);
	Sleep(3000);
	system("CLS");
	MainMenu(Shop);
}


