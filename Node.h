//****************************************************************************************************
//
//         File:                        Node.h
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
//         This structure creates a single node for use in an AVL tree. It holds data of
//		   an unknown type as well as the frequency, the address of its right child
//		   node, and the address of its left child node.
// 
//****************************************************************************************************

#ifndef NODE_H
#define NODE_H

//****************************************************************************************************

#include <iostream>

//****************************************************************************************************

template <typename TYPE>
struct Node
{
	TYPE value;
	double frequency;
	Node <TYPE> * left;
	Node <TYPE> * right;

	Node ();
	Node (double f, Node <TYPE> * l = nullptr, Node <TYPE> * r = nullptr);
};

//****************************************************************************************************

template <typename TYPE>
Node <TYPE> ::Node ()
{
	frequency = 0;
	left = nullptr;
	right = nullptr;
}

//****************************************************************************************************

template <typename TYPE>
Node <TYPE> ::Node (double f, Node <TYPE> * l, Node <TYPE> * r)
{
	frequency = f;
	left = l;
	right = r;
}

//****************************************************************************************************

#endif