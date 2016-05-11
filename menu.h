#ifndef __MENU_CLASS__
#define __MENU_CLASS__

#include <iostream>
#include "command.h"

using namespace std;

class Menu {
	private:
		unsigned int history_index;
		vector<Command*> history;
		
	public:
		Menu() {
			//Base constructor to set up all necessary members
			history_index = 0;
			
		};
		void execute() {
			//Prints the current commands value (based on history_index), if no commands exist
			//print 0 by default
			
			if (history_index > 0) {
			cout << history.at(history_index -1)->execute() << endl;
			}
			else {
				cout << "0" << endl;
			}
		};
		bool initialized() {
			//Return true if the history has been primed with a single op instruciton
			//This is necessary because that is the base of a calculation
			if (history.size() == 0) {
				return false;
			}
			else {
				return true;
			}
		};
		void add_command(Command* cmd) {
			//Adds a command to history in the appropriate posiiton (based on history_index)
			
			if (history.size() == history_index) {
				history.push_back(cmd);
			}
			else {
				history.at(history_index) = cmd;
			}
			history_index++;
			
		};
		Command* get_command() {
			//Returns the command in history we are currently referring to (based on history_index)
			return history.at(history_index - 1);
		};
		void undo() {
			//Moves to the last command in history (if possible)
			
			if (history_index > 0) {
				history_index--;
			}

		};
		void redo() {
			//Moves to the next command in history (if possible)
			
			if (history_index < history.size()) {
				history_index++;
			}

		};
};

#endif //__MENU_CLASS__
