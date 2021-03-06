//
// PROJECT:         Aspia Remote Desktop
// FILE:            ui/users_dialog.h
// LICENSE:         See top-level directory
// PROGRAMMERS:     Dmitry Chapyshev (dmitry@aspia.ru)
//

#ifndef _ASPIA_UI__USERS_DIALOG_H
#define _ASPIA_UI__USERS_DIALOG_H

#include "ui/base/modal_dialog.h"
#include "ui/base/imagelist.h"
#include "proto/host_user.pb.h"

namespace aspia {

class UsersDialog : public ModalDialog
{
public:
    UsersDialog() = default;

    INT_PTR DoModal(HWND parent) override;

private:
    INT_PTR OnMessage(UINT msg, WPARAM wparam, LPARAM lparam) override;

    void OnInitDialog();
    void OnAddButton();
    void OnEditButton();
    void OnDeleteButton();
    void OnOkButton();

    void UpdateUserList();
    int GetSelectedUserIndex();
    void ShowUserPopupMenu();
    void OnUserListClicked();
    void SetUserListModified();

    proto::HostUserList user_list_;
    ImageList imagelist_;

    DISALLOW_COPY_AND_ASSIGN(UsersDialog);
};

} // namespace aspia

#endif // _ASPIA_UI__USERS_DIALOG_H
