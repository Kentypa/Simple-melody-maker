#ifndef INTERFACE_H
#define INTERFACE_H

#include <iostream>
#include "TrackList.h"

#define print(text) cout << text

#pragma once
class Interface {
public:
	void Init(); // Ініціалізує інтерфейс у консолі

	void TypeCommand(); // Приймач команд

	void PrintHelpCommands(); // Виводить список доступних команд
private:
	string currectCommand; // Команда яка введена зараз
};

#endif