//****************************************************************************************************
//
//         File:                        Stock.h
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
//         This file defines a Stock class, which includes a company name, a stock
//		   symbol, and a stock price.
//
//****************************************************************************************************

#ifndef STOCK_H
#define STOCK_H

//****************************************************************************************************

#include <iostream>
#include <iomanip>
#include <string>

//****************************************************************************************************

class Stock
{
	private:
	std::string name;
	std::string symbol;
	double price;

	public:
	Stock (const std::string & stockName = "", const std::string & stockSymbol = "", double stockPrice = 0);
	Stock (const Stock & s);
	void display () const;
	std::string getName () const;
	std::string getSymbol () const;
	double getPrice () const;
	bool operator == (const Stock & rhs) const;
	bool operator != (const Stock & rhs) const;
	bool operator > (const Stock & rhs) const;
	bool operator < (const Stock & rhs) const;
	bool operator >= (const Stock & rhs) const;
	bool operator <= (const Stock & rhs) const;
	friend std::ostream & operator << (std::ostream & out, const Stock & data);
	void setName (const std::string & n);
	void setSymbol (const std::string & s);
	void setPrice (double p);
};

//****************************************************************************************************

inline
std::string Stock::getName () const
{
	return name;
}

//****************************************************************************************************

inline
std::string Stock::getSymbol () const
{
	return symbol;
}

//****************************************************************************************************

inline
double Stock::getPrice () const
{
	return price;
}

//****************************************************************************************************

inline
bool Stock :: operator == (const Stock & rhs) const
{
	return ( this->symbol == rhs.symbol );
}

//****************************************************************************************************

inline
bool Stock :: operator != (const Stock & rhs) const
{
	return ( this->symbol != rhs.symbol );
}

//****************************************************************************************************

inline
bool Stock :: operator > (const Stock & rhs) const
{
	return ( this->symbol > rhs.symbol );
}

//****************************************************************************************************

inline
bool Stock :: operator < (const Stock & rhs) const
{
	return ( this->symbol < rhs.symbol );
}

//****************************************************************************************************

inline
bool Stock :: operator >= (const Stock & rhs) const
{
	return ( this->symbol >= rhs.symbol );
}

//****************************************************************************************************

inline
bool Stock :: operator <= (const Stock & rhs) const
{
	return ( this->symbol <= rhs.symbol );
}

//****************************************************************************************************

inline
void Stock :: setName (const std::string & n)
{
	name = n;
}

//****************************************************************************************************

inline
void Stock :: setSymbol (const std::string & s)
{
	symbol = s;
}

//****************************************************************************************************

inline
void Stock :: setPrice (double p)
{
	price = p;
}

//****************************************************************************************************

#endif