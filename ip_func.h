// Funzioni del progetto IP-Analyzr C++

/*
 * LISTA DELLE FUNZIONI:
 * =====================
 * 
 * VALID_IP -> verify if IP address (or subnet) is a valid IPv4 format
*/

// package
#include<string>
#include<sstream>
#include<iostream>
#include<cstring> // == string.h (nome originale nella libreria di C)
#include<stdlib.h> // per usare rand e srand
#include<ctime> // == time.h (nome originale nella libreria di C) => necessario a srand
#include<cmath> // == math.h (nome originale nella libreria di C)
#include<ctype.h> // == cctype (per C++)
#include<iomanip> // per usare setw e setfill

#include <vector> // to use vector (to deepen...)


using namespace std;


// BORROWED (Rewrite as soon as possible)
// Verify if given string is a number
bool isNumber(const string& str)
{
	// std::find_first_not_of searches the string for the first character 
	// that does not match any of the characters specified in its arguments
	return !str.empty() && 
		(str.find_first_not_of("[0123456789]") == std::string::npos);
}

// BORROWED (Rewrite as soon as possible)
// Function to split string str using given delimiter
vector<string> split(const string& str, char delim)
{
	auto i = 0;
	vector<string> list;

	auto pos = str.find(delim);
	
	while (pos != string::npos) 
	{
		list.push_back(str.substr(i, pos - i));
		i = ++pos;
		pos = str.find(delim, pos);
	}
	
	list.push_back(str.substr(i, str.length()));
	
	return list;
}


// BORROWED (Rewrite as soon as possible)
// Verify ip is valid -> use split() & isNumber()
bool valid_ip(string ip) {

    // split the string into tokens
	vector<string> list = split(ip, '.');

	// if token size is not equal to four
	if (list.size() != 4)
		return false;

	// validate each token
	for (string str : list) 
	{
		// verify that string is number or not and the numbers 
		// are in the valid range
		if (!isNumber(str) || stoi(str) > 255 || stoi(str) < 0)
			return false;
	}

	return true;
}