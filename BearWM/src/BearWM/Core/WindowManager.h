#pragma once

#include <xcb/xcb.h>

namespace BearWM
{
    class WindowManager
    {
    public:
        WindowManager();
        ~WindowManager();

    private:
        xcb_connection_t* m_Connection = nullptr;
        int m_Screen = 0;
    };
}
