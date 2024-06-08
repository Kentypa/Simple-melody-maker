#ifndef INTERFACE_H
#define INTERFACE_H

#include <iostream>
#include "TrackList.h"

#define print(text) cout << text

#pragma once
class Interface {
public:
	void Init(); // 

	void TypeCommand();

	void PrintHelpCommands();
private:
	string currectCommand;
};

#endif