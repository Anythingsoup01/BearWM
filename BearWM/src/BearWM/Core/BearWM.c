#include <stdio.h>
#include <stdlib.h>

#include <X11/Xlib.h>
#include <X11/cursorfont.h>

Display* display;
Window window;

void grabKey(char* key, unsigned int mod)
{
    KeySym sym = XStringToKeysym(key);
    KeyCode code = XKeysymToKeycode(display, sym);
    XGrabKey(display, code, mod, window, False, GrabModeAsync, GrabModeAsync);
    XSync(display, False);
}

unsigned int GetKeyCode(char* key, unsigned int mod)
{
    KeySym sym = XStringToKeysym(key);
    return XKeysymToKeycode(display, sym);
}

int main(int argc, char* argv[])
{
    display = XOpenDisplay(NULL);
    if (display == NULL)
    {
        printf("Failed to open X Display");
        return EXIT_FAILURE;
    }

    window = DefaultRootWindow(display);

    XSelectInput(display, window, SubstructureRedirectMask | SubstructureNotifyMask);

    Cursor cursor = XCreateFontCursor(display, XC_left_ptr);

    XDefineCursor(display, window, cursor);

    XGrabButton(display, Button1, 0, window, 0, ButtonPressMask, GrabModeSync, GrabModeAsync, NULL, NULL);

    grabKey("a", ShiftMask | ControlMask);
    grabKey("s", ShiftMask | ControlMask);

    XSync(display, False);

    XEvent e;
    for(;;)
    {
        XNextEvent(display, &e);
        switch(e.type)
        {
            case ButtonPress:
            {
                XAllowEvents(display, ReplayPointer, CurrentTime);
                XSync(display, 0);
                break;
            }
            case KeyPress:
            {
                if (e.xkey.keycode == GetKeyCode("a", ShiftMask | ControlMask))
                {
                    return EXIT_SUCCESS;
                }
                break;
            }
            default:
            {
                break;
            }
        }

        XSync(display, 0);
    }


    XCloseDisplay(display);

    return EXIT_SUCCESS;
}
