#ifndef FIX50SP2_UPDATEMONITORPAGEREQUEST_H
#define FIX50SP2_UPDATEMONITORPAGEREQUEST_H

#include "Message.h"

namespace FIX50SP2
{

  class UpdateMonitorPageRequest : public Message
  {
  public:
    UpdateMonitorPageRequest() : Message(MsgType()) {}
    UpdateMonitorPageRequest(const FIX::Message& m) : Message(m) {}
    UpdateMonitorPageRequest(const Message& m) : Message(m) {}
    UpdateMonitorPageRequest(const UpdateMonitorPageRequest& m) : Message(m) {}
    static FIX::MsgType MsgType() { return FIX::MsgType("UMPQ"); }

    UpdateMonitorPageRequest(
      const FIX::MonitorRequestID& aMonitorRequestID,
      const FIX::TransactTime& aTransactTime )
    : Message(MsgType())
    {
      set(aMonitorRequestID);
      set(aTransactTime);
    }

    FIELD_SET(*this, FIX::MonitorRequestID);
    FIELD_SET(*this, FIX::TransactTime);
    FIELD_SET(*this, FIX::NoMonitorIDs);
    class NoMonitorIDs: public FIX::Group
    {
    public:
    NoMonitorIDs() : FIX::Group(22057,22058,FIX::message_order(22058,22061,22062,22302,22303,22304,22063,0)) {}
      FIELD_SET(*this, FIX::MonitorID);
      FIELD_SET(*this, FIX::MonitorNumber);
      FIELD_SET(*this, FIX::MonitorPageNumber);
      FIELD_SET(*this, FIX::ClearPageIndicator);
      FIELD_SET(*this, FIX::MonitorPageNumRows);
      FIELD_SET(*this, FIX::MonitorPageNumColumns);
      FIELD_SET(*this, FIX::NoMonitorRows);
      class NoMonitorRows: public FIX::Group
      {
      public:
      NoMonitorRows() : FIX::Group(22063,22064,FIX::message_order(22064,22339,22340,22341,22342,58,0)) {}
        FIELD_SET(*this, FIX::RowNumber);
        FIELD_SET(*this, FIX::RowSpanStartColumn);
        FIELD_SET(*this, FIX::RowSpanLength);
        FIELD_SET(*this, FIX::RowSpanText);
        FIELD_SET(*this, FIX::RowSpanAttribute);
        FIELD_SET(*this, FIX::Text);
      };
    };
  };

}

#endif
