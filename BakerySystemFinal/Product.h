#pragma once

using namespace std;

class Product
{
private:
	string _productName;
	int _stock;
	float _price;
	int _sold;
	float _totalSales;
	int _productID;

public:
	Product(string productName, int stock, float price);
	
	//Properties
	string GetProductName();

	float GetTotalSales();
	float GetProductPrice();

	int GetProductStock();
	int GetTotalSold();
	int GetProductID();

	void SetProductPrice(float price);
	void SetProductID(int productID);
	void SetProductStock(int stock);
	void SetTotalSold(int sold);

	void AddTotalSales(float sale);
	void RemoveTotalSales(float sale);
};

