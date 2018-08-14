#include <iostream>
#include <list>

#include "Bakery.h"

Bakery::Bakery()
{
}

bool Bakery::AddProduct(Product* currentProduct)
{
	currentProduct->SetProductID(this->latestProductID);
	this->allProducts.push_back(currentProduct);
	this->latestProductID++;
	return true;
}

bool Bakery::RemoveProduct(int productID)
{
	for (list<Product*>::iterator iter = allProducts.begin(); iter != allProducts.end(); iter++)
	{
		if ((*iter)->GetProductID() == productID)
		{
			allProducts.remove(*iter);
		}
	}
	return true;
}

void Bakery::ShowAllProducts()
{
	int productID = 0;
	for (list<Product*>::iterator iter = allProducts.begin(); iter != allProducts.end(); iter++)
	{
		cout << "ID: " << productID << endl;
		cout << "Product Name: " << (*iter)->GetProductName().c_str() << endl;
		productID++;
	}
}

void Bakery::ListAllProducts()
{
	for (list<Product*>::iterator iter = allProducts.begin(); iter != allProducts.end(); iter++)
	{
		cout << (*iter)->GetProductID() + 1 << " : " << (*iter)->GetProductName().c_str() << endl;
	}
}

void Bakery::GetSalesSingleProduct(int productID)
{
	for (list<Product*>::iterator iter = allProducts.begin(); iter != allProducts.end(); iter++)
	{
		if ((*iter)->GetProductID() == productID)
		{
			system("CLS");
			cout << "Product Name: " << (*iter)->GetProductName().c_str() << endl;
			cout << "Total Sales: \x9C" << (*iter)->GetTotalSales() << endl;
		}
	}
}

void Bakery::GetSalesAllProducts()
{
	float finalSales = 0;
	system("CLS");
	for (list<Product*>::iterator iter = allProducts.begin(); iter != allProducts.end(); iter++)
	{
		float currentProductSales = (*iter)->GetTotalSales();
		finalSales += currentProductSales;
		cout << (*iter)->GetProductName().c_str() << ": \x9C" << (*iter)->GetTotalSales() << endl;
	}
	cout << "Final Total Sales: \x9C" << finalSales << endl;
}

void Bakery::BestSoldProduct()
{
	string bestSellingProduct = "";
	int productSales = 0;
	for (list<Product*>::iterator iter = allProducts.begin(); iter != allProducts.end(); iter++)
	{
		if ((*iter)->GetTotalSales() > productSales)
		{
			bestSellingProduct = (*iter)->GetProductName();
			productSales = (*iter)->GetTotalSales();
		}
	}

	cout << "Best Sold Product: " << bestSellingProduct.c_str() << endl;
	cout << "Sold: " << productSales << endl;
}

void Bakery::MostProfitableProduct()
{
	string productName = "";
	float mostProfitProduct = 0;
	for (list<Product*>::iterator iter = allProducts.begin(); iter != allProducts.end(); iter++)
	{
		if ((*iter)->GetTotalSales() > mostProfitProduct)
		{
			mostProfitProduct = (*iter)->GetTotalSales();
			productName = (*iter)->GetProductName();
		}
	}

	cout << "Most profitable product: " << productName.c_str() << endl;
	cout << "Earnings: " << mostProfitProduct << endl;
}


bool Bakery::SetProductPrice(int productID, float productPrice)
{
	if (productPrice < 0 || productID >= 0)
	{
		for (list<Product*>::iterator iter = allProducts.begin(); iter != allProducts.end(); iter++)
		{
			if ((*iter)->GetProductID() == productID)
			{
				(*iter)->SetProductPrice(productPrice);
				cout << "Succesfully set the price of " << (*iter)->GetProductName().c_str() << " to \x9C" << productPrice << endl;
				return true;
			}
		}
		return false;
	}
	else
		return false;
}

bool Bakery::SetProductStock(int productID, int stocknum)
{
	if (stocknum < 0 || productID >= 0)
	{
		for (list<Product*>::iterator iter = allProducts.begin(); iter != allProducts.end(); iter++)
		{
			if ((*iter)->GetProductID() == productID)
			{
				(*iter)->SetProductStock(stocknum);
				cout << "Succesfully set the stock of " << (*iter)->GetProductName().c_str() << " to " << stocknum << endl;
				return true;
			}
		}
		return false;
	}
	else
		return false;
}

void Bakery::PrintAllProductStats()
{
	system("CLS");
	for (list<Product*>::iterator iter = allProducts.begin(); iter != allProducts.end(); iter++)
	{
		cout << "Product Name: " << (*iter)->GetProductName().c_str() << endl;
		cout << "Product ID: " << (*iter)->GetProductID() << endl;
		cout << "Product Price: \x9c" << (*iter)->GetProductPrice() << endl;
		cout << "Product Stock: " << (*iter)->GetProductStock() << endl;
		cout << "Product Sold: " << (*iter)->GetTotalSold() << endl;
		cout << "Product Total Sales: \x9c" << (*iter)->GetTotalSales() << endl;
		cout << endl;
		cout << endl;
	}
}

bool Bakery::BuyProduct(int productID, int productsBought)
{
	if (productsBought >= 1 || productID >= 0)
	{
		for (list<Product*>::iterator iter = allProducts.begin(); iter != allProducts.end(); iter++)
		{
			if ((*iter)->GetProductID() == productID)
			{
				if ((*iter)->GetProductStock() > 0)
				{
					//If user types more products than we have in stock
					if ((*iter)->GetProductStock() < productsBought)
					{
						productsBought = (*iter)->GetProductStock();
						cout << "There wasn't enough stock available to buy the amount you wanted!" << endl;
						cout << "We added the rest of the stock we had to your cart instead." << endl;
						cout << endl;
					}
					//Set the product stock after customer buys product
					(*iter)->SetProductStock((*iter)->GetProductStock() - productsBought);
					//Set the total sold after customer buys product
					(*iter)->AddTotalSales((*iter)->GetProductPrice() * productsBought);
					(*iter)->SetTotalSold((*iter)->GetTotalSold() + productsBought);
					cout << "You have successfully bought " << productsBought << " " << (*iter)->GetProductName().c_str() << endl;
					cout << "Reciept Details: " << endl;
					cout << "Price: \x9c" << (*iter)->GetProductPrice() << endl;
					cout << "Total: \x9c" << (*iter)->GetProductPrice() * productsBought << endl;
					return true;
				}
				else
				{
					cout << "There is currently no stock avaiable for this item!" << endl;
					return false;
				}
			}
		}
	}
	else
	{
		cout << "That product does not exist!" << endl;
		return false;
	}
}