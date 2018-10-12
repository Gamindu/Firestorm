///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  ArgParser
//
//  Parses command line arguments.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//  Copyright (c) Project Elflord 2018
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef LIBCORE_ARGPARSER_H_
#define LIBCORE_ARGPARSER_H_
#pragma once

OPEN_NAMESPACE(Firestorm);

class ArgParser final
{
public:
	ArgParser(int ac, char** av);
	
	string Get(const string& key, const string& def="");
	string Get(const string& key, const char* def = "");
	bool Get(const string& key, bool def = false);
	bool Has(const string& key) const;

private:
	unordered_map<string, string> _args;
};

CLOSE_NAMESPACE(Firestorm);

#endif
