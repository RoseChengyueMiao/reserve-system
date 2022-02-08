#pragma once
#include<iostream>
#include<map>
#include<unordered_map>
#include"global_file.h"
#include<string>
using namespace std;

class OrderFile
{
public:
	OrderFile();
	void updateOrder();

	unordered_map<int, unordered_map<string, string>>orderData;

	int Size;
};