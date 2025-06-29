#include "WindowManager.h"

#include <stdlib.h>
#include <stdio.h>

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
        XSync(m_Display, 0);

        XEvent event;
        while(true)
        {
            XNextEvent(m_Display, &event);
            switch(event.type)
            {
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
