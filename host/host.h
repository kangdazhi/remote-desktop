//
// PROJECT:         Aspia Remote Desktop
// FILE:            host/host.h
// LICENSE:         See top-level directory
// PROGRAMMERS:     Dmitry Chapyshev (dmitry@aspia.ru)
//

#ifndef _ASPIA_HOST__HOST_H
#define _ASPIA_HOST__HOST_H

#include "network/network_channel.h"
#include "network/network_channel_proxy.h"
#include "host/host_session.h"
#include "host/host_session_proxy.h"
#include "proto/auth_session.pb.h"

namespace aspia {

class Host :
    private HostSession::Delegate,
    private NetworkChannel::Listener
{
public:
    class Delegate
    {
    public:
        virtual void OnSessionTerminate() = 0;
    };

    Host(std::unique_ptr<NetworkChannel> channel, Delegate* delegate);
    ~Host();

    bool IsAliveSession() const;

private:
    // HostSession::Delegate implementation.
    void OnSessionMessage(const IOBuffer& buffer) override;
    void OnSessionTerminate() override;

    // NetworkChannel::Listener implementation.
    void OnNetworkChannelMessage(const IOBuffer& buffer) override;
    void OnNetworkChannelDisconnect() override;

    bool SendAuthResult(const IOBuffer& request_buffer);

    std::unique_ptr<NetworkChannel> channel_;
    std::shared_ptr<NetworkChannelProxy> channel_proxy_;

    std::unique_ptr<HostSession> session_;
    std::shared_ptr<HostSessionProxy> session_proxy_;

    Delegate* delegate_;

    bool is_auth_failed_ = false;

    DISALLOW_COPY_AND_ASSIGN(Host);
};

} // namespace aspia

#endif // _ASPIA_HOST__HOST_H
