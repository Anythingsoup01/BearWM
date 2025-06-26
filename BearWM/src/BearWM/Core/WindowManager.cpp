#include "WindowManager.h"

#include <stdlib.h>
#include <stdio.h>

namespace BearWM
{
    WindowManager::WindowManager()
    {
        m_Connection = xcb_connect(nullptr, &m_Screen);
        if (xcb_connection_has_error(m_Connection))
        {
            printf("Failed to establish connection with X11 server!");
            xcb_disconnect(m_Connection);
            exit(EXIT_FAILURE);
        }
    }

    WindowManager::~WindowManager()
    {
        xcb_disconnect(m_Connection);
    }
}
