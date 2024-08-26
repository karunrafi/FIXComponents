#ifndef FIX50SP2_MARKETDATAACK_H
#define FIX50SP2_MARKETDATAACK_H

#include "Message.h"

namespace FIX50SP2
{

  class MarketDataAck : public Message
  {
  public:
    MarketDataAck() : Message(MsgType()) {}
    MarketDataAck(const FIX::Message& m) : Message(m) {}
    MarketDataAck(const Message& m) : Message(m) {}
    MarketDataAck(const MarketDataAck& m) : Message(m) {}
    static FIX::MsgType MsgType() { return FIX::MsgType("UMDA"); }

    MarketDataAck(
      const FIX::MDReportID& aMDReportID )
    : Message(MsgType())
    {
      set(aMDReportID);
    }

    FIELD_SET(*this, FIX::MDReportID);
  };

}

#endif
