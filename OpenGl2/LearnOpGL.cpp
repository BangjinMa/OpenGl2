#include "AppDeBugger.h"
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main() {
	AppDebugger * appDebugger = AppDebugger::getInstance();
	appDebugger->SetWindows(SCR_WIDTH, SCR_HEIGHT);
	appDebugger->ShowWindows();
	int x;
	std::cin >> x;
	return 0;
}
