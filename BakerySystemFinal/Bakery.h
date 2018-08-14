#include <iostream>
#include <list>

#include "Product.h"

using namespace std;

class Bakery
{
private:
	//Attributes
	string _bakeryName;
	list<Product*> allProducts;
	int latestProductID = 0;

public:
	//Constructors
	Bakery();
	
	//Properties

	//Methods
	void ShowAllProducts();
	void ListAllProducts();
	//void ListAllProducts();
	void BestSoldProduct();
	void MostProfitableProduct();
	void PrintAllProductStats();


	void GetSalesAllProducts();
	void GetSalesSingleProduct(int productID);

	void GetAllProductPrices();

	bool AddProduct(Product* currentProduct);
	bool RemoveProduct(int productID);
	bool BuyProduct(int productID, int productsBought);
	bool SetProductPrice(int productID, float productPrice);
	bool SetProductStock(int productID, int stocknum);
};

