//****************************************************************************************************
//
//         File:                        Stock.cpp
//
//         Student:                     Allison Coil
//
//         Assignment:                  Assignment  #9
//
//         Course Name:                 Data Structures   II
//
//         Course Number:               COSC 3100 - 01
//
//         Due:                         Nov 12, 2021
//
//
//         This file implements a Stock class, which includes a company name, a stock
//		   symbol, and a stock price.
//
//****************************************************************************************************

#include "Stock.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//****************************************************************************************************

Stock::Stock (const string & stockName, const string & stockSymbol, double stockPrice)
{
	name = stockName;
	symbol = stockSymbol;
	price = stockPrice;
}

//****************************************************************************************************

Stock::Stock (const Stock & s)
{
	name = s.name;
	symbol = s.symbol;
	price = s.price;
}

//****************************************************************************************************

ostream & operator << (ostream & out, const Stock & data)
{
	out << left << setw (25) << data.name << setw (10) << data.symbol << "$" << data.price << endl;

	return out;
}

//****************************************************************************************************

void Stock::display () const
{
	cout << left << setw (25) << name << setw (10) << symbol << "$" << price << endl;
}

//****************************************************************************************************