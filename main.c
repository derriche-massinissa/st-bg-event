#include <stdio.h>
#include <string.h>
#include <X11/Xlib.h>
#include <X11/Xatom.h>
#include <X11/Xutil.h>

void findWindows(const char *name);
void findWindowsSearch(Display* display, Window current, char const *needle);
void sendEvent(Display* display, Window w);

int main()
{
    findWindows("st");

    return 0;
}

void findWindows(const char *name)
{
    Display *display = XOpenDisplay(NULL);

    Window w = XDefaultRootWindow(display);

    findWindowsSearch(display, w, name);

    XCloseDisplay(display);
}

void findWindowsSearch(Display* display, Window current, char const *needle)
{
    Window root, parent, *children;
    unsigned childrenCount;

    // Check all windows recursively
    if (XQueryTree(display, current, &root, &parent, &children, &childrenCount) != 0)
	{
        XTextProperty wmName;

        if (XGetWMName(display, current, &wmName) > 0)
		{
            int r = strcmp(needle, (const char*) wmName.value);

            if (r == 0)
			{
                sendEvent(display, current);
            }
        }

        for(int i = 0; i < childrenCount; i++)
            findWindowsSearch(display, children[i], needle);
    }

    XFree(children);
}

void sendEvent(Display* display, Window w)
{
    XEvent event;
    Atom dump;
    const char* eventName = "_NEW_BG";
    event.xclient.type = ClientMessage;
    event.xclient.message_type = XInternAtoms(display, (char**) &eventName, 1, False, &dump);
    event.xclient.format = 32;

    XSendEvent(display, w, False, NoEventMask, &event);
}
