lightning-listforwards -- Command showing all htlcs and their information
=========================================================================

SYNOPSIS
--------

**listforwards** [*status*] [*in_channel*] [*out_channel*]

DESCRIPTION
-----------

The **listforwards** RPC command displays all htlcs that have been
attempted to be forwarded by the Core Lightning node.

If *status* is specified, then only the forwards with the given status are returned.
*status* can be either *offered* or *settled* or *failed* or *local_failed*

If *in_channel* or *out_channel* is specified, then only the matching forwards
on the given in/out channel are returned.

RETURN VALUE
------------

[comment]: # (GENERATE-FROM-SCHEMA-START)
On success, an object containing **forwards** is returned.  It is an array of objects, where each object contains:

- **in\_channel** (short\_channel\_id): the channel that received the HTLC
- **in\_htlc\_id** (u64): the unique HTLC id the sender gave this
- **in\_msat** (msat): the value of the incoming HTLC
- **status** (string): still ongoing, completed, failed locally, or failed after forwarding (one of "offered", "settled", "local_failed", "failed")
- **received\_time** (number): the UNIX timestamp when this was received
- **out\_channel** (short\_channel\_id, optional): the channel that the HTLC (trying to) forward to
- **out\_htlc\_id** (u64, optional): the unique HTLC id we gave this when sending
- **style** (string, optional): Either a legacy onion format or a modern tlv format (one of "legacy", "tlv")

If **out\_msat** is present:

  - **fee\_msat** (msat): the amount this paid in fees
  - **out\_msat** (msat): the amount we sent out the *out_channel*

If **status** is "settled" or "failed":

  - **resolved\_time** (number): the UNIX timestamp when this was resolved

If **status** is "local_failed" or "failed":

  - **failcode** (u32, optional): the numeric onion code returned
  - **failreason** (string, optional): the name of the onion code returned

[comment]: # (GENERATE-FROM-SCHEMA-END)

AUTHOR
------

Rene Pickhardt <<r.pickhardt@gmail.com>> is mainly responsible.

SEE ALSO
--------

lightning-autoclean-status(7), lightning-getinfo(7)

RESOURCES
---------

Main web site: <https://github.com/ElementsProject/lightning>

[comment]: # ( SHA256STAMP:5b2da52b7f3a28563d0103d3853b9d8f717dc41a9e9c6b395ff19f1b975ca5fd)
