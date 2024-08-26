#ifndef FIX50SP2_SETUPMONITORREQUEST_H
#define FIX50SP2_SETUPMONITORREQUEST_H

#include "Message.h"

namespace FIX50SP2
{

  class SetupMonitorRequest : public Message
  {
  public:
    SetupMonitorRequest() : Message(MsgType()) {}
    SetupMonitorRequest(const FIX::Message& m) : Message(m) {}
    SetupMonitorRequest(const Message& m) : Message(m) {}
    SetupMonitorRequest(const SetupMonitorRequest& m) : Message(m) {}
    static FIX::MsgType MsgType() { return FIX::MsgType("USMQ"); }

    SetupMonitorRequest(
      const FIX::MonitorRequestID& aMonitorRequestID,
      const FIX::MDFeedType& aMDFeedType,
      const FIX::TransactTime& aTransactTime )
    : Message(MsgType())
    {
      set(aMonitorRequestID);
      set(aMDFeedType);
      set(aTransactTime);
    }

    FIELD_SET(*this, FIX::MonitorRequestID);
    FIELD_SET(*this, FIX::MDFeedType);
    FIELD_SET(*this, FIX::MDStreamID);
    FIELD_SET(*this, FIX::TransactTime);
    FIELD_SET(*this, FIX::NoMonitorIDs);
    class NoMonitorIDs: public FIX::Group
    {
    public:
    NoMonitorIDs() : FIX::Group(22057,22058,FIX::message_order(22058,22060,22061,22059,22062,22063,0)) {}
      FIELD_SET(*this, FIX::MonitorID);
      FIELD_SET(*this, FIX::MonitorSortOption);
      FIELD_SET(*this, FIX::MonitorNumber);
      FIELD_SET(*this, FIX::ClearMonitorIndicator);
      FIELD_SET(*this, FIX::MonitorPageNumber);
      FIELD_SET(*this, FIX::NoMonitorRows);
      class NoMonitorRows: public FIX::Group
      {
      public:
      NoMonitorRows() : FIX::Group(22063,22064,FIX::message_order(22064,22065,22066,48,22,460,107,699,761,6632,22067,22068,58,0)) {}
        FIELD_SET(*this, FIX::RowNumber);
        FIELD_SET(*this, FIX::RowLoadAction);
        FIELD_SET(*this, FIX::RowForegroundColor);
        FIELD_SET(*this, FIX::SecurityID);
        FIELD_SET(*this, FIX::SecurityIDSource);
        FIELD_SET(*this, FIX::Product);
        FIELD_SET(*this, FIX::SecurityDesc);
        FIELD_SET(*this, FIX::NoInstrumentParties);
        class NoInstrumentParties: public FIX::Group
        {
        public:
        NoInstrumentParties() : FIX::Group(1018,1019,FIX::message_order(1019,1050,1051,1052,0)) {}
          FIELD_SET(*this, FIX::InstrumentPartyID);
          FIELD_SET(*this, FIX::InstrumentPartyIDSource);
          FIELD_SET(*this, FIX::InstrumentPartyRole);
          FIELD_SET(*this, FIX::NoInstrumentPartySubIDs);
          class NoInstrumentPartySubIDs: public FIX::Group
          {
          public:
          NoInstrumentPartySubIDs() : FIX::Group(1052,1053,FIX::message_order(1053,1054,0)) {}
            FIELD_SET(*this, FIX::InstrumentPartySubID);
            FIELD_SET(*this, FIX::InstrumentPartySubIDType);
          };
        };
        FIELD_SET(*this, FIX::BenchmarkSecurityID);
        FIELD_SET(*this, FIX::BenchmarkSecurityIDSource);
        FIELD_SET(*this, FIX::BenchmarkSecurityDesc);
        FIELD_SET(*this, FIX::SecurityIDSourceOverride);
        FIELD_SET(*this, FIX::SuppressPricesIndicator);
        FIELD_SET(*this, FIX::Text);
      };
    };
  };

}

#endif
