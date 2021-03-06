//
// PROJECT:         Aspia Remote Desktop
// FILE:            base/message_loop/message_pump_ui.h
// LICENSE:         See top-level directory
// PROGRAMMERS:     Dmitry Chapyshev (dmitry@aspia.ru)
//

#ifndef _ASPIA_BASE__MESSAGE_LOOP__MESSAGE_PUMP_UI_H
#define _ASPIA_BASE__MESSAGE_LOOP__MESSAGE_PUMP_UI_H

#include "base/macros.h"
#include "base/message_window.h"
#include "base/message_loop/message_pump_win.h"

namespace aspia {

class MessagePumpForUI : public MessagePumpWin
{
public:
    MessagePumpForUI();
    ~MessagePumpForUI() = default;

    // MessagePump methods:
    virtual void ScheduleWork() override;

private:
    bool OnMessage(UINT message, WPARAM wparam, LPARAM lparam, LRESULT* result);
    void DoRunLoop() override;
    void WaitForWork();
    void HandleWorkMessage();
    bool ProcessNextWindowsMessage();
    bool ProcessMessageHelper(const MSG& msg);
    bool ProcessPumpReplacementMessage();

    MessageWindow message_window_;

    DISALLOW_COPY_AND_ASSIGN(MessagePumpForUI);
};

} // namespace aspia

#endif // _ASPIA_BASE__MESSAGE_LOOP__MESSAGE_PUMP_UI_H
