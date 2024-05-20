#pragma once
#ifndef DYNAMIC_STRUCTURES_H
#define DYNAMIC_STRUCTURES_H

#include <iostream>
#include <regex>

struct Node {
	int data;
	Node* next;
};

Node* createList();
void addElement(Node*& head, int value);
void deleteElement(Node*& head, int value);
void swapMinMax(Node* head);

#endif
