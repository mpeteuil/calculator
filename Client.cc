#include "UserInterface.h"
//#include

int main()
{
	UserInterface *UI = new UserInterface(130,270,355,400,"IT-38 Sulp (Calculator)");
	UI->show();
	return Fl::run();
}
