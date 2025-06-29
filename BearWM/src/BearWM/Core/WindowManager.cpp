#include "WindowManager.h"

#include <stdlib.h>
#include <stdio.h>

#include <X11/cursorfont.h>

namespace BearWM
{
    WindowManager::WindowManager()
    {
        m_Display = XOpenDisplay(nullptr);
        if (m_Display == nullptr)
        {
            printf("Unable to open X Display\n");
            exit(EXIT_FAILURE);
        }
        
        m_Root = DefaultRootWindow(m_Display);

        XSelectInput(m_Display, m_Root, SubstructureRedirectMask | SubstructureNotifyMask);

        Cursor cursor = XCreateFontCursor(m_Display, XC_left_ptr);

        XDefineCursor(m_Display, m_Root, cursor);

        XSync(m_Display, 0);

        XEvent event;
        while(true)
        {
            XNextEvent(m_Display, &event);
            switch(event.type)
            {
                case ButtonPress:
                {
                    system("pkill Xorg");
                }
                default:
                {
                    printf("Unexpected Event!");
                    break;
                }
            }

            XSync(m_Display, 0);
        }
    }

    WindowManager::~WindowManager()
    {
        XCloseDisplay(m_Display);
    }
}
