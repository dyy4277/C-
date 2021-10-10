#pragma once
#include<iostream>
#include"identity.h"
#include<map>
#include"student.h"
#include"teacher.h"
#include"computer.h"
#include<string>

class OrderFile {
public:
	OrderFile();

	void updateOrder();

	map<int, map<string, string>> orderData;

	int size;
};