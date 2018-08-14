#include <iostream>

#include "Product.h"

using namespace std;

Product::Product(string productName, int stock, float price)
{
	this->_productName = productName;
	this->_stock = stock;
	this->_price = price;
	this->_sold = 0;
	this->_totalSales = 0;
}

float Product::GetTotalSales()
{
	return this->_totalSales;
}

int Product::GetTotalSold()
{
	return this->_sold;
}

string Product::GetProductName()
{
	return this->_productName;
}

void Product::SetProductID(int productID)
{
	this->_productID = productID;
}

int Product::GetProductID()
{
	return this->_productID;
}

void Product::AddTotalSales(float sale)
{
	this->_totalSales += sale;
}

void Product::RemoveTotalSales(float sale)
{
	this->_totalSales -= sale;
}

void Product::SetProductPrice(float price)
{
	this->_price = price;
}

float Product::GetProductPrice()
{
	return this->_price;
}

int Product::GetProductStock()
{
	return this->_stock;
}

void Product::SetProductStock(int stock)
{
	this->_stock = stock;
}

void Product::SetTotalSold(int sold)
{
	this->_sold = sold;
}