//
// PROJECT:         Aspia Remote Desktop
// FILE:            ui/base/window.h
// LICENSE:         See top-level directory
// PROGRAMMERS:     Dmitry Chapyshev (dmitry@aspia.ru)
//

#ifndef _ASPIA_UI__BASE__WINDOW_H
#define _ASPIA_UI__BASE__WINDOW_H

#include "base/message_loop/message_loop.h"
#include "base/scoped_user_object.h"
#include "desktop_capture/desktop_size.h"

namespace aspia {

class Window
{
public:
    Window() = default;
    Window(HWND hwnd) : hwnd_(hwnd) { }
    virtual ~Window() = default;

    void Attach(HWND hwnd) { hwnd_ = hwnd; }
    HWND hwnd() { return hwnd_; }
    operator HWND() { return hwnd(); }

    bool CenterWindow(HWND hwnd_center = nullptr);
    bool ModifyStyle(LONG_PTR remove, LONG_PTR add);
    bool ModifyStyleEx(LONG_PTR remove, LONG_PTR add);

private:
    HWND hwnd_ = nullptr;

    DISALLOW_COPY_AND_ASSIGN(Window);
};

} // namespace aspia

#endif // _ASPIA_UI__BASE__WINDOW_H
