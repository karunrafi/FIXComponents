#ifndef FIX50SP2_MONITORREQUESTACK_H
#define FIX50SP2_MONITORREQUESTACK_H

#include "Message.h"

namespace FIX50SP2
{

  class MonitorRequestAck : public Message
  {
  public:
    MonitorRequestAck() : Message(MsgType()) {}
    MonitorRequestAck(const FIX::Message& m) : Message(m) {}
    MonitorRequestAck(const Message& m) : Message(m) {}
    MonitorRequestAck(const MonitorRequestAck& m) : Message(m) {}
    static FIX::MsgType MsgType() { return FIX::MsgType("USMQK"); }

    MonitorRequestAck(
      const FIX::MonitorRequestID& aMonitorRequestID,
      const FIX::RefMsgType& aRefMsgType,
      const FIX::MonitorRequestStatus& aMonitorRequestStatus )
    : Message(MsgType())
    {
      set(aMonitorRequestID);
      set(aRefMsgType);
      set(aMonitorRequestStatus);
    }

    FIELD_SET(*this, FIX::MonitorRequestID);
    FIELD_SET(*this, FIX::MDFeedType);
    FIELD_SET(*this, FIX::RefMsgType);
    FIELD_SET(*this, FIX::MonitorRequestStatus);
    FIELD_SET(*this, FIX::Text);
  };

}

#endif
