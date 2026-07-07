#pragma once

#include <cerrno>
#include <fstream>
#include <iostream>
#include <map>
#include <cstdlib>

typedef std::map<std::string, double> btcmap;

int ret_err(const char *msg, int linect);
int parse_data(std::ifstream &data, btcmap &mdata);
void	parse_input(std::ifstream &input, btcmap &mdata);
