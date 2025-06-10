//****************************************************************************************************
//
//         File:                        HuffmanCodes.cpp
//
//         Student:                     Allison Coil
//
//         Assignment:                  Assignment #9
//
//         Course Name:                 Data Structures   II
//
//         Course Number:               COSC 3100 - 01
//
//         Due:                         Nov 12, 2021
//
//
//         This program creates and displays Huffman Codes for a list of Stocks read from a file.
//		   
// 
//****************************************************************************************************

#include "Stock.h"
#include "Node.h"
#include <iostream>
#include <fstream>
#include <string>
#include <limits>
using namespace std;

//****************************************************************************************************

int readStocks (const string & fileName, Stock *& stocks, double *& freq);
Node <Stock> * createHuffmanTree (Stock stocks[], double freqs[], int size);
void printPathsToStocks (Node <Stock> * rootPtr, int size);
void printPaths (Node <Stock> * node, int paths[], int pathLen, int lr);
void displayStockList (Node <Stock> * rootPtr, const string & sentence);
int min (int first, int second);
int max (int first, int second);
void printArray (int paths[], int pathLen, Node <Stock> * leaf);

//****************************************************************************************************

int main ()
{
	Stock * stocks;
	double * freqs;
	int size = readStocks ("HuffmanStocks.txt", stocks, freqs);

	Node <Stock> * rootPtr = createHuffmanTree (stocks, freqs, size);

	printPathsToStocks (rootPtr, size);

	string sentence = "10010110000111010010111001101100010";
	displayStockList (rootPtr, sentence);

	return 0;
}

//****************************************************************************************************

int readStocks (const string & fileName, Stock *& stocks, double *& freq)
{
	ifstream file (fileName);
	int size;
	string name;
	string symbol;
	double price;
	Stock temp;
	double frequency;

	file >> size;
	stocks = new Stock [size];
	freq = new double [size];

	for ( int i = 0; i < size; i ++ )
	{
		file.ignore ();
		getline (file, name);
		temp.setName (name);
		file >> symbol;
		temp.setSymbol (symbol);
		file >> price;
		temp.setPrice (price);
		stocks [i] = temp;
		file >> frequency;
		freq [i] = frequency;
	}

	file.close ();
	return size;
}

//****************************************************************************************************

Node <Stock> * createHuffmanTree (Stock stocks[], double freqs[], int size)
{
	Node <Stock> ** elements = new Node <Stock> * [size];

	for ( int i = 0; i < size; i ++ )
	{
		elements [i] = new Node <Stock>;
		elements [i] -> value = stocks [i];
		elements [i] -> frequency = freqs [i];
	}

	int index1,
		index2;
	double freq1,
		freq2;

	while ( size > 1 )
	{
		index1 = index2 = 0;
		freq1 = freq2 = numeric_limits <double> :: max ();

		for ( int i = 0; i < size; i ++ )
		{
			if ( elements [i] -> frequency < freq1 )
			{
				freq2 = freq1;
				index2 = index1;
				freq1 = elements [i] -> frequency;
				index1 = i;
			}
			else if ( ( elements [i] -> frequency < freq2 ) && ( i != index1 ) )
			{
				freq2 = elements [i] -> frequency;
				index2 = i;
			}
		}

		Node <Stock> * newNode = new Node <Stock> (freq1 + freq2, elements [index1], elements [index2]);
		elements [min (index1, index2)] = newNode;

		for ( int i = max (index1, index2); i < size - 1; i ++ )
		{
			elements [i] = elements [i + 1];
		}

		size --;
	}

	return elements [0];
}

//****************************************************************************************************

void printPathsToStocks (Node <Stock> * rootPtr, int size)
{
	int * paths = new int [size];
	printPaths (rootPtr, paths, 0, -1);
}

//****************************************************************************************************

void printPaths (Node <Stock> * node, int paths[], int pathLen, int lr)
{
	if ( node )
	{
		if ( lr != -1 )
		{
			paths [pathLen] = lr;
			pathLen ++;
		}

		if ( ( ! node -> left ) && ( ! node -> right ) )
		{
			printArray (paths, pathLen, node);
		}
		else
		{
			printPaths (node -> left, paths, pathLen, 0);
			printPaths (node -> right, paths, pathLen, 1);
		}
	}
}

//****************************************************************************************************

void displayStockList (Node <Stock> * rootPtr, const string & sentence)
{
	Node <Stock> * current = rootPtr;

	for ( int i = 0; i < sentence.length (); i ++ )
	{
		if ( current )
		{
			if ( sentence [i] == '0' )
			{
				current = current -> left;
			}
			else
			{
				current = current -> right;
			}
		}

		if ( current )
		{
			if ( ( ! current -> left ) && ( ! current -> right ) )
			{
				cout << current -> value.getName () << endl;
				current = rootPtr;
			}
		}
	}
}

//****************************************************************************************************

int min (int first, int second)
{
	int result = first;

	if ( second < first )
	{
		result = second;
	}

	return result;
}

//****************************************************************************************************

int max (int first, int second)
{
	int result = first;

	if ( second > first )
	{
		result = second;
	}

	return result;
}

//****************************************************************************************************

void printArray (int paths[], int pathLen, Node <Stock> * leaf)
{
	cout << leaf -> value;

	for ( int i = 0; i < pathLen; i ++ )
	{
		cout << paths [i];
	}

	cout << endl << endl;
}

//****************************************************************************************************

/*
Home Depot Inc           HD        $279.57
00

Coca-Cola Co             KO        $53.85
010

Cisco Systems Inc        CSCO      $42.54
0110

Caterpillar Inc          CAT       $173.19
01110

Boeing Co                BA        $202.4
011110

Johnson & Johnson        JNJ       $150.85
011111

Goldman Sachs Group Inc  GS        $222.38
10

Apple Inc                AAPL      $120.3
110

Intel Corp               INTC      $46.19
1110

American Express Co      AXP       $118.67
1111

Goldman Sachs Group Inc
Coca-Cola Co
Apple Inc
Home Depot Inc
Caterpillar Inc
Goldman Sachs Group Inc
Coca-Cola Co
Intel Corp
Cisco Systems Inc
Apple Inc
Home Depot Inc
Goldman Sachs Group Inc
*/