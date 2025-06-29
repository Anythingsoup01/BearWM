#pragma once

#include <X11/Xlib.h>

namespace BearWM
{
    class WindowManager
    {
    public:
        WindowManager();
        ~WindowManager();

    private:

        Display* m_Display;
        Window m_Root;

        
    };
}
