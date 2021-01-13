/* This file was generated by generate-wire.py */
/* Do not modify this file! Modify the .csv file it was generated from. */
/* Original template can be found at tools/gen/impl_template */

#include <wire/onion_wiregen.h>
#include <assert.h>
#include <ccan/array_size/array_size.h>
#include <ccan/mem/mem.h>
#include <ccan/tal/str/str.h>
#include <common/utils.h>
#include <stdio.h>

#ifndef SUPERVERBOSE
#define SUPERVERBOSE(...)
#endif


const char *onion_wire_name(int e)
{
	static char invalidbuf[sizeof("INVALID ") + STR_MAX_CHARS(e)];

	switch ((enum onion_wire)e) {
	case WIRE_INVALID_REALM: return "WIRE_INVALID_REALM";
	case WIRE_TEMPORARY_NODE_FAILURE: return "WIRE_TEMPORARY_NODE_FAILURE";
	case WIRE_PERMANENT_NODE_FAILURE: return "WIRE_PERMANENT_NODE_FAILURE";
	case WIRE_REQUIRED_NODE_FEATURE_MISSING: return "WIRE_REQUIRED_NODE_FEATURE_MISSING";
	case WIRE_INVALID_ONION_VERSION: return "WIRE_INVALID_ONION_VERSION";
	case WIRE_INVALID_ONION_HMAC: return "WIRE_INVALID_ONION_HMAC";
	case WIRE_INVALID_ONION_KEY: return "WIRE_INVALID_ONION_KEY";
	case WIRE_TEMPORARY_CHANNEL_FAILURE: return "WIRE_TEMPORARY_CHANNEL_FAILURE";
	case WIRE_PERMANENT_CHANNEL_FAILURE: return "WIRE_PERMANENT_CHANNEL_FAILURE";
	case WIRE_REQUIRED_CHANNEL_FEATURE_MISSING: return "WIRE_REQUIRED_CHANNEL_FEATURE_MISSING";
	case WIRE_UNKNOWN_NEXT_PEER: return "WIRE_UNKNOWN_NEXT_PEER";
	case WIRE_AMOUNT_BELOW_MINIMUM: return "WIRE_AMOUNT_BELOW_MINIMUM";
	case WIRE_FEE_INSUFFICIENT: return "WIRE_FEE_INSUFFICIENT";
	case WIRE_INCORRECT_CLTV_EXPIRY: return "WIRE_INCORRECT_CLTV_EXPIRY";
	case WIRE_EXPIRY_TOO_SOON: return "WIRE_EXPIRY_TOO_SOON";
	case WIRE_INCORRECT_OR_UNKNOWN_PAYMENT_DETAILS: return "WIRE_INCORRECT_OR_UNKNOWN_PAYMENT_DETAILS";
	case WIRE_FINAL_INCORRECT_CLTV_EXPIRY: return "WIRE_FINAL_INCORRECT_CLTV_EXPIRY";
	case WIRE_FINAL_INCORRECT_HTLC_AMOUNT: return "WIRE_FINAL_INCORRECT_HTLC_AMOUNT";
	case WIRE_CHANNEL_DISABLED: return "WIRE_CHANNEL_DISABLED";
	case WIRE_EXPIRY_TOO_FAR: return "WIRE_EXPIRY_TOO_FAR";
	case WIRE_INVALID_ONION_PAYLOAD: return "WIRE_INVALID_ONION_PAYLOAD";
	case WIRE_MPP_TIMEOUT: return "WIRE_MPP_TIMEOUT";
	}

	snprintf(invalidbuf, sizeof(invalidbuf), "INVALID %i", e);
	return invalidbuf;
}

bool onion_wire_is_defined(u16 type)
{
	switch ((enum onion_wire)type) {
	case WIRE_INVALID_REALM:;
	case WIRE_TEMPORARY_NODE_FAILURE:;
	case WIRE_PERMANENT_NODE_FAILURE:;
	case WIRE_REQUIRED_NODE_FEATURE_MISSING:;
	case WIRE_INVALID_ONION_VERSION:;
	case WIRE_INVALID_ONION_HMAC:;
	case WIRE_INVALID_ONION_KEY:;
	case WIRE_TEMPORARY_CHANNEL_FAILURE:;
	case WIRE_PERMANENT_CHANNEL_FAILURE:;
	case WIRE_REQUIRED_CHANNEL_FEATURE_MISSING:;
	case WIRE_UNKNOWN_NEXT_PEER:;
	case WIRE_AMOUNT_BELOW_MINIMUM:;
	case WIRE_FEE_INSUFFICIENT:;
	case WIRE_INCORRECT_CLTV_EXPIRY:;
	case WIRE_EXPIRY_TOO_SOON:;
	case WIRE_INCORRECT_OR_UNKNOWN_PAYMENT_DETAILS:;
	case WIRE_FINAL_INCORRECT_CLTV_EXPIRY:;
	case WIRE_FINAL_INCORRECT_HTLC_AMOUNT:;
	case WIRE_CHANNEL_DISABLED:;
	case WIRE_EXPIRY_TOO_FAR:;
	case WIRE_INVALID_ONION_PAYLOAD:;
	case WIRE_MPP_TIMEOUT:;
	      return true;
	}
	return false;
}




/* SUBTYPE: ONIONMSG_PATH */
void towire_onionmsg_path(u8 **p, const struct onionmsg_path *onionmsg_path)
{
	u16 enclen = tal_count(onionmsg_path->enctlv);

	towire_pubkey(p, &onionmsg_path->node_id);
	towire_u16(p, enclen);
	towire_u8_array(p, onionmsg_path->enctlv, enclen);
}
struct onionmsg_path *
fromwire_onionmsg_path(const tal_t *ctx, const u8 **cursor, size_t *plen)
{
	struct onionmsg_path *onionmsg_path = tal(ctx, struct onionmsg_path);
	u16 enclen;

 	fromwire_pubkey(cursor, plen, &onionmsg_path->node_id);
 	enclen = fromwire_u16(cursor, plen);
 	onionmsg_path->enctlv = enclen ? tal_arr(onionmsg_path, u8, enclen) : NULL;
fromwire_u8_array(cursor, plen, onionmsg_path->enctlv, enclen);

	return onionmsg_path;
}


struct tlv_tlv_payload *tlv_tlv_payload_new(const tal_t *ctx)
{
	/* Initialize everything to NULL. (Quiet, C pedants!) */
	struct tlv_tlv_payload *inst = talz(ctx, struct tlv_tlv_payload);

	/* Initialized the fields to an empty array. */
	inst->fields = tal_arr(inst, struct tlv_field, 0);
	return inst;
}

/* TLV_PAYLOAD MSG: amt_to_forward */
static u8 *towire_tlv_tlv_payload_amt_to_forward(const tal_t *ctx, const void *vrecord)
{
	const struct tlv_tlv_payload *r = vrecord;
	u8 *ptr;

	if (!r->amt_to_forward)
		return NULL;


	ptr = tal_arr(ctx, u8, 0);

	towire_tu64(&ptr, *r->amt_to_forward);
	return ptr;
}
static void fromwire_tlv_tlv_payload_amt_to_forward(const u8 **cursor, size_t *plen, void *vrecord)
{
	struct tlv_tlv_payload *r = vrecord;

	    r->amt_to_forward = tal(r, u64);

*r->amt_to_forward = fromwire_tu64(cursor, plen);
}
/* TLV_PAYLOAD MSG: outgoing_cltv_value */
static u8 *towire_tlv_tlv_payload_outgoing_cltv_value(const tal_t *ctx, const void *vrecord)
{
	const struct tlv_tlv_payload *r = vrecord;
	u8 *ptr;

	if (!r->outgoing_cltv_value)
		return NULL;


	ptr = tal_arr(ctx, u8, 0);

	towire_tu32(&ptr, *r->outgoing_cltv_value);
	return ptr;
}
static void fromwire_tlv_tlv_payload_outgoing_cltv_value(const u8 **cursor, size_t *plen, void *vrecord)
{
	struct tlv_tlv_payload *r = vrecord;

	    r->outgoing_cltv_value = tal(r, u32);

*r->outgoing_cltv_value = fromwire_tu32(cursor, plen);
}
/* TLV_PAYLOAD MSG: short_channel_id */
static u8 *towire_tlv_tlv_payload_short_channel_id(const tal_t *ctx, const void *vrecord)
{
	const struct tlv_tlv_payload *r = vrecord;
	u8 *ptr;

	if (!r->short_channel_id)
		return NULL;


	ptr = tal_arr(ctx, u8, 0);

	towire_short_channel_id(&ptr, r->short_channel_id);
	return ptr;
}
static void fromwire_tlv_tlv_payload_short_channel_id(const u8 **cursor, size_t *plen, void *vrecord)
{
	struct tlv_tlv_payload *r = vrecord;

	    r->short_channel_id = tal(r, struct short_channel_id);

fromwire_short_channel_id(cursor, plen, &*r->short_channel_id);
}
/* TLV_PAYLOAD MSG: payment_data */
static u8 *towire_tlv_tlv_payload_payment_data(const tal_t *ctx, const void *vrecord)
{
	const struct tlv_tlv_payload *r = vrecord;
	u8 *ptr;

	if (!r->payment_data)
		return NULL;


	ptr = tal_arr(ctx, u8, 0);

	towire_secret(&ptr, &r->payment_data->payment_secret);

	towire_tu64(&ptr, r->payment_data->total_msat);
	return ptr;
}
static void fromwire_tlv_tlv_payload_payment_data(const u8 **cursor, size_t *plen, void *vrecord)
{
	struct tlv_tlv_payload *r = vrecord;

	r->payment_data = tal(r, struct tlv_tlv_payload_payment_data);
	fromwire_secret(cursor, plen, &r->payment_data->payment_secret);
	r->payment_data->total_msat = fromwire_tu64(cursor, plen);
}

const struct tlv_record_type tlvs_tlv_payload[] = {
	{ 2, towire_tlv_tlv_payload_amt_to_forward, fromwire_tlv_tlv_payload_amt_to_forward },
	{ 4, towire_tlv_tlv_payload_outgoing_cltv_value, fromwire_tlv_tlv_payload_outgoing_cltv_value },
	{ 6, towire_tlv_tlv_payload_short_channel_id, fromwire_tlv_tlv_payload_short_channel_id },
	{ 8, towire_tlv_tlv_payload_payment_data, fromwire_tlv_tlv_payload_payment_data },
};

void towire_tlv_payload(u8 **pptr, const struct tlv_tlv_payload *record)
{
	towire_tlv(pptr, tlvs_tlv_payload, 4, record);
}


bool fromwire_tlv_payload(const u8 **cursor, size_t *max, struct tlv_tlv_payload *record)
{
	return fromwire_tlv(cursor, max, tlvs_tlv_payload, 4, record, &record->fields);
}

bool tlv_payload_is_valid(const struct tlv_tlv_payload *record, size_t *err_index)
{
	return tlv_fields_valid(record->fields, err_index);
}


struct tlv_onionmsg_payload *tlv_onionmsg_payload_new(const tal_t *ctx)
{
	/* Initialize everything to NULL. (Quiet, C pedants!) */
	struct tlv_onionmsg_payload *inst = talz(ctx, struct tlv_onionmsg_payload);

	/* Initialized the fields to an empty array. */
	inst->fields = tal_arr(inst, struct tlv_field, 0);
	return inst;
}

/* ONIONMSG_PAYLOAD MSG: next_node_id */
static u8 *towire_tlv_onionmsg_payload_next_node_id(const tal_t *ctx, const void *vrecord)
{
	const struct tlv_onionmsg_payload *r = vrecord;
	u8 *ptr;

	if (!r->next_node_id)
		return NULL;


	ptr = tal_arr(ctx, u8, 0);

	towire_pubkey(&ptr, r->next_node_id);
	return ptr;
}
static void fromwire_tlv_onionmsg_payload_next_node_id(const u8 **cursor, size_t *plen, void *vrecord)
{
	struct tlv_onionmsg_payload *r = vrecord;

	    r->next_node_id = tal(r, struct pubkey);

fromwire_pubkey(cursor, plen, &*r->next_node_id);
}
/* ONIONMSG_PAYLOAD MSG: next_short_channel_id */
static u8 *towire_tlv_onionmsg_payload_next_short_channel_id(const tal_t *ctx, const void *vrecord)
{
	const struct tlv_onionmsg_payload *r = vrecord;
	u8 *ptr;

	if (!r->next_short_channel_id)
		return NULL;


	ptr = tal_arr(ctx, u8, 0);

	towire_short_channel_id(&ptr, r->next_short_channel_id);
	return ptr;
}
static void fromwire_tlv_onionmsg_payload_next_short_channel_id(const u8 **cursor, size_t *plen, void *vrecord)
{
	struct tlv_onionmsg_payload *r = vrecord;

	    r->next_short_channel_id = tal(r, struct short_channel_id);

fromwire_short_channel_id(cursor, plen, &*r->next_short_channel_id);
}
/* ONIONMSG_PAYLOAD MSG: reply_path */
static u8 *towire_tlv_onionmsg_payload_reply_path(const tal_t *ctx, const void *vrecord)
{
	const struct tlv_onionmsg_payload *r = vrecord;
	u8 *ptr;

	if (!r->reply_path)
		return NULL;


	ptr = tal_arr(ctx, u8, 0);

	towire_pubkey(&ptr, &r->reply_path->blinding);

		for (size_t i = 0; i < tal_count(r->reply_path->path); i++)
		towire_onionmsg_path(&ptr, r->reply_path->path[i]);
	return ptr;
}
static void fromwire_tlv_onionmsg_payload_reply_path(const u8 **cursor, size_t *plen, void *vrecord)
{
	struct tlv_onionmsg_payload *r = vrecord;

	r->reply_path = tal(r, struct tlv_onionmsg_payload_reply_path);
	fromwire_pubkey(cursor, plen, &r->reply_path->blinding);
	r->reply_path->path = *plen ? tal_arr(r->reply_path, struct onionmsg_path *, 0) : NULL;
	for (size_t i = 0; *plen != 0; i++) {
		struct onionmsg_path * tmp;
		tmp = fromwire_onionmsg_path(r->reply_path, cursor, plen);
		tal_arr_expand(&r->reply_path->path, tmp);
	}
}
/* ONIONMSG_PAYLOAD MSG: enctlv */
static u8 *towire_tlv_onionmsg_payload_enctlv(const tal_t *ctx, const void *vrecord)
{
	const struct tlv_onionmsg_payload *r = vrecord;
	u8 *ptr;

	if (!r->enctlv)
		return NULL;


	ptr = tal_arr(ctx, u8, 0);

	towire_u8_array(&ptr, r->enctlv, tal_count(r->enctlv));
	return ptr;
}
static void fromwire_tlv_onionmsg_payload_enctlv(const u8 **cursor, size_t *plen, void *vrecord)
{
	struct tlv_onionmsg_payload *r = vrecord;

	r->enctlv = *plen ? tal_arr(r, u8, *plen) : NULL;
fromwire_u8_array(cursor, plen, r->enctlv, *plen);
}
/* ONIONMSG_PAYLOAD MSG: blinding */
static u8 *towire_tlv_onionmsg_payload_blinding(const tal_t *ctx, const void *vrecord)
{
	const struct tlv_onionmsg_payload *r = vrecord;
	u8 *ptr;

	if (!r->blinding)
		return NULL;


	ptr = tal_arr(ctx, u8, 0);

	towire_pubkey(&ptr, r->blinding);
	return ptr;
}
static void fromwire_tlv_onionmsg_payload_blinding(const u8 **cursor, size_t *plen, void *vrecord)
{
	struct tlv_onionmsg_payload *r = vrecord;

	    r->blinding = tal(r, struct pubkey);

fromwire_pubkey(cursor, plen, &*r->blinding);
}
/* ONIONMSG_PAYLOAD MSG: invoice_request */
static u8 *towire_tlv_onionmsg_payload_invoice_request(const tal_t *ctx, const void *vrecord)
{
	const struct tlv_onionmsg_payload *r = vrecord;
	u8 *ptr;

	if (!r->invoice_request)
		return NULL;


	ptr = tal_arr(ctx, u8, 0);

	towire_u8_array(&ptr, r->invoice_request, tal_count(r->invoice_request));
	return ptr;
}
static void fromwire_tlv_onionmsg_payload_invoice_request(const u8 **cursor, size_t *plen, void *vrecord)
{
	struct tlv_onionmsg_payload *r = vrecord;

	r->invoice_request = *plen ? tal_arr(r, u8, *plen) : NULL;
fromwire_u8_array(cursor, plen, r->invoice_request, *plen);
}
/* ONIONMSG_PAYLOAD MSG: invoice */
static u8 *towire_tlv_onionmsg_payload_invoice(const tal_t *ctx, const void *vrecord)
{
	const struct tlv_onionmsg_payload *r = vrecord;
	u8 *ptr;

	if (!r->invoice)
		return NULL;


	ptr = tal_arr(ctx, u8, 0);

	towire_u8_array(&ptr, r->invoice, tal_count(r->invoice));
	return ptr;
}
static void fromwire_tlv_onionmsg_payload_invoice(const u8 **cursor, size_t *plen, void *vrecord)
{
	struct tlv_onionmsg_payload *r = vrecord;

	r->invoice = *plen ? tal_arr(r, u8, *plen) : NULL;
fromwire_u8_array(cursor, plen, r->invoice, *plen);
}
/* ONIONMSG_PAYLOAD MSG: invoice_error */
static u8 *towire_tlv_onionmsg_payload_invoice_error(const tal_t *ctx, const void *vrecord)
{
	const struct tlv_onionmsg_payload *r = vrecord;
	u8 *ptr;

	if (!r->invoice_error)
		return NULL;


	ptr = tal_arr(ctx, u8, 0);

	towire_u8_array(&ptr, r->invoice_error, tal_count(r->invoice_error));
	return ptr;
}
static void fromwire_tlv_onionmsg_payload_invoice_error(const u8 **cursor, size_t *plen, void *vrecord)
{
	struct tlv_onionmsg_payload *r = vrecord;

	r->invoice_error = *plen ? tal_arr(r, u8, *plen) : NULL;
fromwire_u8_array(cursor, plen, r->invoice_error, *plen);
}

static const struct tlv_record_type tlvs_onionmsg_payload[] = {
	{ 4, towire_tlv_onionmsg_payload_next_node_id, fromwire_tlv_onionmsg_payload_next_node_id },
	{ 6, towire_tlv_onionmsg_payload_next_short_channel_id, fromwire_tlv_onionmsg_payload_next_short_channel_id },
	{ 8, towire_tlv_onionmsg_payload_reply_path, fromwire_tlv_onionmsg_payload_reply_path },
	{ 10, towire_tlv_onionmsg_payload_enctlv, fromwire_tlv_onionmsg_payload_enctlv },
	{ 12, towire_tlv_onionmsg_payload_blinding, fromwire_tlv_onionmsg_payload_blinding },
	{ 64, towire_tlv_onionmsg_payload_invoice_request, fromwire_tlv_onionmsg_payload_invoice_request },
	{ 66, towire_tlv_onionmsg_payload_invoice, fromwire_tlv_onionmsg_payload_invoice },
	{ 68, towire_tlv_onionmsg_payload_invoice_error, fromwire_tlv_onionmsg_payload_invoice_error },
};

void towire_onionmsg_payload(u8 **pptr, const struct tlv_onionmsg_payload *record)
{
	towire_tlv(pptr, tlvs_onionmsg_payload, 8, record);
}


bool fromwire_onionmsg_payload(const u8 **cursor, size_t *max, struct tlv_onionmsg_payload *record)
{
	return fromwire_tlv(cursor, max, tlvs_onionmsg_payload, 8, record, &record->fields);
}

bool onionmsg_payload_is_valid(const struct tlv_onionmsg_payload *record, size_t *err_index)
{
	return tlv_fields_valid(record->fields, err_index);
}


struct tlv_encmsg_tlvs *tlv_encmsg_tlvs_new(const tal_t *ctx)
{
	/* Initialize everything to NULL. (Quiet, C pedants!) */
	struct tlv_encmsg_tlvs *inst = talz(ctx, struct tlv_encmsg_tlvs);

	/* Initialized the fields to an empty array. */
	inst->fields = tal_arr(inst, struct tlv_field, 0);
	return inst;
}

/* ENCMSG_TLVS MSG: next_node_id */
static u8 *towire_tlv_encmsg_tlvs_next_node_id(const tal_t *ctx, const void *vrecord)
{
	const struct tlv_encmsg_tlvs *r = vrecord;
	u8 *ptr;

	if (!r->next_node_id)
		return NULL;


	ptr = tal_arr(ctx, u8, 0);

	towire_pubkey(&ptr, r->next_node_id);
	return ptr;
}
static void fromwire_tlv_encmsg_tlvs_next_node_id(const u8 **cursor, size_t *plen, void *vrecord)
{
	struct tlv_encmsg_tlvs *r = vrecord;

	    r->next_node_id = tal(r, struct pubkey);

fromwire_pubkey(cursor, plen, &*r->next_node_id);
}
/* ENCMSG_TLVS MSG: next_short_channel_id */
static u8 *towire_tlv_encmsg_tlvs_next_short_channel_id(const tal_t *ctx, const void *vrecord)
{
	const struct tlv_encmsg_tlvs *r = vrecord;
	u8 *ptr;

	if (!r->next_short_channel_id)
		return NULL;


	ptr = tal_arr(ctx, u8, 0);

	towire_short_channel_id(&ptr, r->next_short_channel_id);
	return ptr;
}
static void fromwire_tlv_encmsg_tlvs_next_short_channel_id(const u8 **cursor, size_t *plen, void *vrecord)
{
	struct tlv_encmsg_tlvs *r = vrecord;

	    r->next_short_channel_id = tal(r, struct short_channel_id);

fromwire_short_channel_id(cursor, plen, &*r->next_short_channel_id);
}

static const struct tlv_record_type tlvs_encmsg_tlvs[] = {
	{ 4, towire_tlv_encmsg_tlvs_next_node_id, fromwire_tlv_encmsg_tlvs_next_node_id },
	{ 6, towire_tlv_encmsg_tlvs_next_short_channel_id, fromwire_tlv_encmsg_tlvs_next_short_channel_id },
};

void towire_encmsg_tlvs(u8 **pptr, const struct tlv_encmsg_tlvs *record)
{
	towire_tlv(pptr, tlvs_encmsg_tlvs, 2, record);
}


bool fromwire_encmsg_tlvs(const u8 **cursor, size_t *max, struct tlv_encmsg_tlvs *record)
{
	return fromwire_tlv(cursor, max, tlvs_encmsg_tlvs, 2, record, &record->fields);
}

bool encmsg_tlvs_is_valid(const struct tlv_encmsg_tlvs *record, size_t *err_index)
{
	return tlv_fields_valid(record->fields, err_index);
}


/* WIRE: INVALID_REALM */
u8 *towire_invalid_realm(const tal_t *ctx)
{
	u8 *p = tal_arr(ctx, u8, 0);

	towire_u16(&p, WIRE_INVALID_REALM);

	return memcheck(p, tal_count(p));
}
bool fromwire_invalid_realm(const void *p)
{
	const u8 *cursor = p;
	size_t plen = tal_count(p);

	if (fromwire_u16(&cursor, &plen) != WIRE_INVALID_REALM)
		return false;
	return cursor != NULL;
}

/* WIRE: TEMPORARY_NODE_FAILURE */
u8 *towire_temporary_node_failure(const tal_t *ctx)
{
	u8 *p = tal_arr(ctx, u8, 0);

	towire_u16(&p, WIRE_TEMPORARY_NODE_FAILURE);

	return memcheck(p, tal_count(p));
}
bool fromwire_temporary_node_failure(const void *p)
{
	const u8 *cursor = p;
	size_t plen = tal_count(p);

	if (fromwire_u16(&cursor, &plen) != WIRE_TEMPORARY_NODE_FAILURE)
		return false;
	return cursor != NULL;
}

/* WIRE: PERMANENT_NODE_FAILURE */
u8 *towire_permanent_node_failure(const tal_t *ctx)
{
	u8 *p = tal_arr(ctx, u8, 0);

	towire_u16(&p, WIRE_PERMANENT_NODE_FAILURE);

	return memcheck(p, tal_count(p));
}
bool fromwire_permanent_node_failure(const void *p)
{
	const u8 *cursor = p;
	size_t plen = tal_count(p);

	if (fromwire_u16(&cursor, &plen) != WIRE_PERMANENT_NODE_FAILURE)
		return false;
	return cursor != NULL;
}

/* WIRE: REQUIRED_NODE_FEATURE_MISSING */
u8 *towire_required_node_feature_missing(const tal_t *ctx)
{
	u8 *p = tal_arr(ctx, u8, 0);

	towire_u16(&p, WIRE_REQUIRED_NODE_FEATURE_MISSING);

	return memcheck(p, tal_count(p));
}
bool fromwire_required_node_feature_missing(const void *p)
{
	const u8 *cursor = p;
	size_t plen = tal_count(p);

	if (fromwire_u16(&cursor, &plen) != WIRE_REQUIRED_NODE_FEATURE_MISSING)
		return false;
	return cursor != NULL;
}

/* WIRE: INVALID_ONION_VERSION */
u8 *towire_invalid_onion_version(const tal_t *ctx, const struct sha256 *sha256_of_onion)
{
	u8 *p = tal_arr(ctx, u8, 0);

	towire_u16(&p, WIRE_INVALID_ONION_VERSION);
	towire_sha256(&p, sha256_of_onion);

	return memcheck(p, tal_count(p));
}
bool fromwire_invalid_onion_version(const void *p, struct sha256 *sha256_of_onion)
{
	const u8 *cursor = p;
	size_t plen = tal_count(p);

	if (fromwire_u16(&cursor, &plen) != WIRE_INVALID_ONION_VERSION)
		return false;
 	fromwire_sha256(&cursor, &plen, sha256_of_onion);
	return cursor != NULL;
}

/* WIRE: INVALID_ONION_HMAC */
u8 *towire_invalid_onion_hmac(const tal_t *ctx, const struct sha256 *sha256_of_onion)
{
	u8 *p = tal_arr(ctx, u8, 0);

	towire_u16(&p, WIRE_INVALID_ONION_HMAC);
	towire_sha256(&p, sha256_of_onion);

	return memcheck(p, tal_count(p));
}
bool fromwire_invalid_onion_hmac(const void *p, struct sha256 *sha256_of_onion)
{
	const u8 *cursor = p;
	size_t plen = tal_count(p);

	if (fromwire_u16(&cursor, &plen) != WIRE_INVALID_ONION_HMAC)
		return false;
 	fromwire_sha256(&cursor, &plen, sha256_of_onion);
	return cursor != NULL;
}

/* WIRE: INVALID_ONION_KEY */
u8 *towire_invalid_onion_key(const tal_t *ctx, const struct sha256 *sha256_of_onion)
{
	u8 *p = tal_arr(ctx, u8, 0);

	towire_u16(&p, WIRE_INVALID_ONION_KEY);
	towire_sha256(&p, sha256_of_onion);

	return memcheck(p, tal_count(p));
}
bool fromwire_invalid_onion_key(const void *p, struct sha256 *sha256_of_onion)
{
	const u8 *cursor = p;
	size_t plen = tal_count(p);

	if (fromwire_u16(&cursor, &plen) != WIRE_INVALID_ONION_KEY)
		return false;
 	fromwire_sha256(&cursor, &plen, sha256_of_onion);
	return cursor != NULL;
}

/* WIRE: TEMPORARY_CHANNEL_FAILURE */
u8 *towire_temporary_channel_failure(const tal_t *ctx, const u8 *channel_update)
{
	u16 len = tal_count(channel_update);
	u8 *p = tal_arr(ctx, u8, 0);

	towire_u16(&p, WIRE_TEMPORARY_CHANNEL_FAILURE);
	towire_u16(&p, len);
	towire_u8_array(&p, channel_update, len);

	return memcheck(p, tal_count(p));
}
bool fromwire_temporary_channel_failure(const tal_t *ctx, const void *p, u8 **channel_update)
{
	u16 len;

	const u8 *cursor = p;
	size_t plen = tal_count(p);

	if (fromwire_u16(&cursor, &plen) != WIRE_TEMPORARY_CHANNEL_FAILURE)
		return false;
 	len = fromwire_u16(&cursor, &plen);
 	// 2nd case channel_update
	*channel_update = len ? tal_arr(ctx, u8, len) : NULL;
	fromwire_u8_array(&cursor, &plen, *channel_update, len);
	return cursor != NULL;
}

/* WIRE: PERMANENT_CHANNEL_FAILURE */
u8 *towire_permanent_channel_failure(const tal_t *ctx)
{
	u8 *p = tal_arr(ctx, u8, 0);

	towire_u16(&p, WIRE_PERMANENT_CHANNEL_FAILURE);

	return memcheck(p, tal_count(p));
}
bool fromwire_permanent_channel_failure(const void *p)
{
	const u8 *cursor = p;
	size_t plen = tal_count(p);

	if (fromwire_u16(&cursor, &plen) != WIRE_PERMANENT_CHANNEL_FAILURE)
		return false;
	return cursor != NULL;
}

/* WIRE: REQUIRED_CHANNEL_FEATURE_MISSING */
u8 *towire_required_channel_feature_missing(const tal_t *ctx)
{
	u8 *p = tal_arr(ctx, u8, 0);

	towire_u16(&p, WIRE_REQUIRED_CHANNEL_FEATURE_MISSING);

	return memcheck(p, tal_count(p));
}
bool fromwire_required_channel_feature_missing(const void *p)
{
	const u8 *cursor = p;
	size_t plen = tal_count(p);

	if (fromwire_u16(&cursor, &plen) != WIRE_REQUIRED_CHANNEL_FEATURE_MISSING)
		return false;
	return cursor != NULL;
}

/* WIRE: UNKNOWN_NEXT_PEER */
u8 *towire_unknown_next_peer(const tal_t *ctx)
{
	u8 *p = tal_arr(ctx, u8, 0);

	towire_u16(&p, WIRE_UNKNOWN_NEXT_PEER);

	return memcheck(p, tal_count(p));
}
bool fromwire_unknown_next_peer(const void *p)
{
	const u8 *cursor = p;
	size_t plen = tal_count(p);

	if (fromwire_u16(&cursor, &plen) != WIRE_UNKNOWN_NEXT_PEER)
		return false;
	return cursor != NULL;
}

/* WIRE: AMOUNT_BELOW_MINIMUM */
u8 *towire_amount_below_minimum(const tal_t *ctx, struct amount_msat htlc_msat, const u8 *channel_update)
{
	u16 len = tal_count(channel_update);
	u8 *p = tal_arr(ctx, u8, 0);

	towire_u16(&p, WIRE_AMOUNT_BELOW_MINIMUM);
	towire_amount_msat(&p, htlc_msat);
	towire_u16(&p, len);
	towire_u8_array(&p, channel_update, len);

	return memcheck(p, tal_count(p));
}
bool fromwire_amount_below_minimum(const tal_t *ctx, const void *p, struct amount_msat *htlc_msat, u8 **channel_update)
{
	u16 len;

	const u8 *cursor = p;
	size_t plen = tal_count(p);

	if (fromwire_u16(&cursor, &plen) != WIRE_AMOUNT_BELOW_MINIMUM)
		return false;
 	*htlc_msat = fromwire_amount_msat(&cursor, &plen);
 	len = fromwire_u16(&cursor, &plen);
 	// 2nd case channel_update
	*channel_update = len ? tal_arr(ctx, u8, len) : NULL;
	fromwire_u8_array(&cursor, &plen, *channel_update, len);
	return cursor != NULL;
}

/* WIRE: FEE_INSUFFICIENT */
u8 *towire_fee_insufficient(const tal_t *ctx, struct amount_msat htlc_msat, const u8 *channel_update)
{
	u16 len = tal_count(channel_update);
	u8 *p = tal_arr(ctx, u8, 0);

	towire_u16(&p, WIRE_FEE_INSUFFICIENT);
	towire_amount_msat(&p, htlc_msat);
	towire_u16(&p, len);
	towire_u8_array(&p, channel_update, len);

	return memcheck(p, tal_count(p));
}
bool fromwire_fee_insufficient(const tal_t *ctx, const void *p, struct amount_msat *htlc_msat, u8 **channel_update)
{
	u16 len;

	const u8 *cursor = p;
	size_t plen = tal_count(p);

	if (fromwire_u16(&cursor, &plen) != WIRE_FEE_INSUFFICIENT)
		return false;
 	*htlc_msat = fromwire_amount_msat(&cursor, &plen);
 	len = fromwire_u16(&cursor, &plen);
 	// 2nd case channel_update
	*channel_update = len ? tal_arr(ctx, u8, len) : NULL;
	fromwire_u8_array(&cursor, &plen, *channel_update, len);
	return cursor != NULL;
}

/* WIRE: INCORRECT_CLTV_EXPIRY */
u8 *towire_incorrect_cltv_expiry(const tal_t *ctx, u32 cltv_expiry, const u8 *channel_update)
{
	u16 len = tal_count(channel_update);
	u8 *p = tal_arr(ctx, u8, 0);

	towire_u16(&p, WIRE_INCORRECT_CLTV_EXPIRY);
	towire_u32(&p, cltv_expiry);
	towire_u16(&p, len);
	towire_u8_array(&p, channel_update, len);

	return memcheck(p, tal_count(p));
}
bool fromwire_incorrect_cltv_expiry(const tal_t *ctx, const void *p, u32 *cltv_expiry, u8 **channel_update)
{
	u16 len;

	const u8 *cursor = p;
	size_t plen = tal_count(p);

	if (fromwire_u16(&cursor, &plen) != WIRE_INCORRECT_CLTV_EXPIRY)
		return false;
 	*cltv_expiry = fromwire_u32(&cursor, &plen);
 	len = fromwire_u16(&cursor, &plen);
 	// 2nd case channel_update
	*channel_update = len ? tal_arr(ctx, u8, len) : NULL;
	fromwire_u8_array(&cursor, &plen, *channel_update, len);
	return cursor != NULL;
}

/* WIRE: EXPIRY_TOO_SOON */
u8 *towire_expiry_too_soon(const tal_t *ctx, const u8 *channel_update)
{
	u16 len = tal_count(channel_update);
	u8 *p = tal_arr(ctx, u8, 0);

	towire_u16(&p, WIRE_EXPIRY_TOO_SOON);
	towire_u16(&p, len);
	towire_u8_array(&p, channel_update, len);

	return memcheck(p, tal_count(p));
}
bool fromwire_expiry_too_soon(const tal_t *ctx, const void *p, u8 **channel_update)
{
	u16 len;

	const u8 *cursor = p;
	size_t plen = tal_count(p);

	if (fromwire_u16(&cursor, &plen) != WIRE_EXPIRY_TOO_SOON)
		return false;
 	len = fromwire_u16(&cursor, &plen);
 	// 2nd case channel_update
	*channel_update = len ? tal_arr(ctx, u8, len) : NULL;
	fromwire_u8_array(&cursor, &plen, *channel_update, len);
	return cursor != NULL;
}

/* WIRE: INCORRECT_OR_UNKNOWN_PAYMENT_DETAILS */
u8 *towire_incorrect_or_unknown_payment_details(const tal_t *ctx, struct amount_msat htlc_msat, u32 height)
{
	u8 *p = tal_arr(ctx, u8, 0);

	towire_u16(&p, WIRE_INCORRECT_OR_UNKNOWN_PAYMENT_DETAILS);
	towire_amount_msat(&p, htlc_msat);
	towire_u32(&p, height);

	return memcheck(p, tal_count(p));
}
bool fromwire_incorrect_or_unknown_payment_details(const void *p, struct amount_msat *htlc_msat, u32 *height)
{
	const u8 *cursor = p;
	size_t plen = tal_count(p);

	if (fromwire_u16(&cursor, &plen) != WIRE_INCORRECT_OR_UNKNOWN_PAYMENT_DETAILS)
		return false;
 	*htlc_msat = fromwire_amount_msat(&cursor, &plen);
 	*height = fromwire_u32(&cursor, &plen);
	return cursor != NULL;
}

/* WIRE: FINAL_INCORRECT_CLTV_EXPIRY */
u8 *towire_final_incorrect_cltv_expiry(const tal_t *ctx, u32 cltv_expiry)
{
	u8 *p = tal_arr(ctx, u8, 0);

	towire_u16(&p, WIRE_FINAL_INCORRECT_CLTV_EXPIRY);
	towire_u32(&p, cltv_expiry);

	return memcheck(p, tal_count(p));
}
bool fromwire_final_incorrect_cltv_expiry(const void *p, u32 *cltv_expiry)
{
	const u8 *cursor = p;
	size_t plen = tal_count(p);

	if (fromwire_u16(&cursor, &plen) != WIRE_FINAL_INCORRECT_CLTV_EXPIRY)
		return false;
 	*cltv_expiry = fromwire_u32(&cursor, &plen);
	return cursor != NULL;
}

/* WIRE: FINAL_INCORRECT_HTLC_AMOUNT */
u8 *towire_final_incorrect_htlc_amount(const tal_t *ctx, struct amount_msat incoming_htlc_amt)
{
	u8 *p = tal_arr(ctx, u8, 0);

	towire_u16(&p, WIRE_FINAL_INCORRECT_HTLC_AMOUNT);
	towire_amount_msat(&p, incoming_htlc_amt);

	return memcheck(p, tal_count(p));
}
bool fromwire_final_incorrect_htlc_amount(const void *p, struct amount_msat *incoming_htlc_amt)
{
	const u8 *cursor = p;
	size_t plen = tal_count(p);

	if (fromwire_u16(&cursor, &plen) != WIRE_FINAL_INCORRECT_HTLC_AMOUNT)
		return false;
 	*incoming_htlc_amt = fromwire_amount_msat(&cursor, &plen);
	return cursor != NULL;
}

/* WIRE: CHANNEL_DISABLED */
u8 *towire_channel_disabled(const tal_t *ctx)
{
	u8 *p = tal_arr(ctx, u8, 0);

	towire_u16(&p, WIRE_CHANNEL_DISABLED);

	return memcheck(p, tal_count(p));
}
bool fromwire_channel_disabled(const void *p)
{
	const u8 *cursor = p;
	size_t plen = tal_count(p);

	if (fromwire_u16(&cursor, &plen) != WIRE_CHANNEL_DISABLED)
		return false;
	return cursor != NULL;
}

/* WIRE: EXPIRY_TOO_FAR */
u8 *towire_expiry_too_far(const tal_t *ctx)
{
	u8 *p = tal_arr(ctx, u8, 0);

	towire_u16(&p, WIRE_EXPIRY_TOO_FAR);

	return memcheck(p, tal_count(p));
}
bool fromwire_expiry_too_far(const void *p)
{
	const u8 *cursor = p;
	size_t plen = tal_count(p);

	if (fromwire_u16(&cursor, &plen) != WIRE_EXPIRY_TOO_FAR)
		return false;
	return cursor != NULL;
}

/* WIRE: INVALID_ONION_PAYLOAD */
u8 *towire_invalid_onion_payload(const tal_t *ctx, bigsize type, u16 offset)
{
	u8 *p = tal_arr(ctx, u8, 0);

	towire_u16(&p, WIRE_INVALID_ONION_PAYLOAD);
	towire_bigsize(&p, type);
	towire_u16(&p, offset);

	return memcheck(p, tal_count(p));
}
bool fromwire_invalid_onion_payload(const void *p, bigsize *type, u16 *offset)
{
	const u8 *cursor = p;
	size_t plen = tal_count(p);

	if (fromwire_u16(&cursor, &plen) != WIRE_INVALID_ONION_PAYLOAD)
		return false;
 	*type = fromwire_bigsize(&cursor, &plen);
 	*offset = fromwire_u16(&cursor, &plen);
	return cursor != NULL;
}

/* WIRE: MPP_TIMEOUT */
u8 *towire_mpp_timeout(const tal_t *ctx)
{
	u8 *p = tal_arr(ctx, u8, 0);

	towire_u16(&p, WIRE_MPP_TIMEOUT);

	return memcheck(p, tal_count(p));
}
bool fromwire_mpp_timeout(const void *p)
{
	const u8 *cursor = p;
	size_t plen = tal_count(p);

	if (fromwire_u16(&cursor, &plen) != WIRE_MPP_TIMEOUT)
		return false;
	return cursor != NULL;
}
// SHA256STAMP:b6eb425ab1211e5f7a8413489527aea4565904f548e72f635e4ebce72e50cdd4
