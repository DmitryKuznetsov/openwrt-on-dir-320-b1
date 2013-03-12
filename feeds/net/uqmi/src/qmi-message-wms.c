/* generated by uqmi gen-code.pl */
#include <stdio.h>
#include <string.h>
#include "qmi-message.h"

#define get_next(_size) ({ void *_buf = &tlv->data[ofs]; ofs += _size; if (ofs > cur_tlv_len) goto error_len; _buf; })
#define copy_tlv(_val, _size) \
	do { \
		int __size = _size; \
		if (__size > 0) \
			memcpy(__qmi_alloc_static(__size), _val, __size); \
	} while (0);

#define put_tlv_var(_type, _val, _size) \
	do { \
		_type __var = _val; \
		copy_tlv(&__var, _size); \
	} while(0)

int qmi_set_wms_reset_request(struct qmi_msg *msg)
{
	qmi_init_request_message(msg, QMI_SERVICE_WMS);
	msg->svc.message = cpu_to_le16(0x0000);

	return 0;
}

int qmi_parse_wms_reset_response(struct qmi_msg *msg)
{
	void *tlv_buf = &msg->svc.tlv;
	int tlv_len = le16_to_cpu(msg->svc.tlv_len);

	return qmi_check_message_status(tlv_buf, tlv_len);
}

int qmi_set_wms_set_event_report_request(struct qmi_msg *msg, struct qmi_wms_set_event_report_request *req)
{
	qmi_init_request_message(msg, QMI_SERVICE_WMS);
	msg->svc.message = cpu_to_le16(0x0001);

	if (req->set.new_mt_message_indicator) {
		void *buf;
		int ofs;

		__qmi_alloc_reset();
		put_tlv_var(uint8_t, req->data.new_mt_message_indicator.report, 1);

		buf = __qmi_get_buf(&ofs);
		tlv_new(msg, 0x10, ofs, buf);
	}

	return 0;
}

int qmi_parse_wms_set_event_report_response(struct qmi_msg *msg)
{
	void *tlv_buf = &msg->svc.tlv;
	int tlv_len = le16_to_cpu(msg->svc.tlv_len);

	return qmi_check_message_status(tlv_buf, tlv_len);
}

int qmi_set_wms_raw_send_request(struct qmi_msg *msg, struct qmi_wms_raw_send_request *req)
{
	qmi_init_request_message(msg, QMI_SERVICE_WMS);
	msg->svc.message = cpu_to_le16(0x0020);

	if (req->set.raw_message_data) {
		void *buf;
		int ofs;
		int i;

		__qmi_alloc_reset();
		put_tlv_var(uint8_t, req->data.raw_message_data.format, 1);
		put_tlv_var(uint16_t, cpu_to_le16(req->data.raw_message_data.raw_data_n), 2);
		for (i = 0; i < req->data.raw_message_data.raw_data_n; i++) {
			put_tlv_var(uint8_t, req->data.raw_message_data.raw_data[i], 1);
		}

		buf = __qmi_get_buf(&ofs);
		tlv_new(msg, 0x01, ofs, buf);
	}

	if (req->set.cdma_force_on_dc) {
		void *buf;
		int ofs;

		__qmi_alloc_reset();
		put_tlv_var(uint8_t, req->data.cdma_force_on_dc.force, 1);
		put_tlv_var(uint8_t, req->data.cdma_force_on_dc.service_option, 1);

		buf = __qmi_get_buf(&ofs);
		tlv_new(msg, 0x10, ofs, buf);
	}

	if (req->set.cdma_follow_on_dc) {
		void *buf;
		int ofs;

		__qmi_alloc_reset();
		put_tlv_var(uint8_t, req->data.cdma_follow_on_dc.follow, 1);

		buf = __qmi_get_buf(&ofs);
		tlv_new(msg, 0x11, ofs, buf);
	}

	if (req->set.gsm_wcdma_link_timer) {
		void *buf;
		int ofs;

		__qmi_alloc_reset();
		put_tlv_var(uint8_t, req->data.gsm_wcdma_link_timer, 1);

		buf = __qmi_get_buf(&ofs);
		tlv_new(msg, 0x12, ofs, buf);
	}

	if (req->set.sms_on_ims) {
		void *buf;
		int ofs;

		__qmi_alloc_reset();
		put_tlv_var(uint8_t, req->data.sms_on_ims, 1);

		buf = __qmi_get_buf(&ofs);
		tlv_new(msg, 0x13, ofs, buf);
	}

	return 0;
}

int qmi_parse_wms_raw_send_response(struct qmi_msg *msg, struct qmi_wms_raw_send_response *res)
{
	void *tlv_buf = &msg->svc.tlv;
	int tlv_len = le16_to_cpu(msg->svc.tlv_len);
	struct tlv *tlv;
	int i;

	memset(res, 0, sizeof(*res));

	__qmi_alloc_reset();
	while ((tlv = tlv_get_next(&tlv_buf, &tlv_len)) != NULL) {
		unsigned int cur_tlv_len = le16_to_cpu(tlv->len);
		unsigned int ofs = 0;

		switch(tlv->type) {
		case 0x01:
			qmi_set(res, message_id, le16_to_cpu(*(uint16_t *) get_next(2)));
			break;

		case 0x10:
			qmi_set(res, cdma_cause_code, le16_to_cpu(*(uint16_t *) get_next(2)));
			break;

		case 0x11:
			qmi_set(res, cdma_error_class, *(uint8_t *) get_next(1));
			break;

		case 0x12:
			res->set.gsm_wcdma_cause_info = 1;
			res->data.gsm_wcdma_cause_info.rp_cause = le16_to_cpu(*(uint16_t *) get_next(2));
			res->data.gsm_wcdma_cause_info.tp_cause = *(uint8_t *) get_next(1);
			break;

		case 0x13:
			qmi_set(res, message_delivery_failure_type, *(uint8_t *) get_next(1));
			break;

		default:
			break;
		}
	}

	return 0;

error_len:
	fprintf(stderr, "%s: Invalid TLV length in message, tlv=0x%02x, len=%d\n",
	        __func__, tlv->type, le16_to_cpu(tlv->len));
	return QMI_ERROR_INVALID_DATA;
}

int qmi_set_wms_raw_write_request(struct qmi_msg *msg, struct qmi_wms_raw_write_request *req)
{
	qmi_init_request_message(msg, QMI_SERVICE_WMS);
	msg->svc.message = cpu_to_le16(0x0021);

	if (req->set.raw_message_data) {
		void *buf;
		int ofs;
		int i;

		__qmi_alloc_reset();
		put_tlv_var(uint8_t, req->data.raw_message_data.storage_type, 1);
		put_tlv_var(uint8_t, req->data.raw_message_data.format, 1);
		put_tlv_var(uint16_t, cpu_to_le16(req->data.raw_message_data.raw_data_n), 2);
		for (i = 0; i < req->data.raw_message_data.raw_data_n; i++) {
			put_tlv_var(uint8_t, req->data.raw_message_data.raw_data[i], 1);
		}

		buf = __qmi_get_buf(&ofs);
		tlv_new(msg, 0x01, ofs, buf);
	}

	return 0;
}

int qmi_parse_wms_raw_write_response(struct qmi_msg *msg, struct qmi_wms_raw_write_response *res)
{
	void *tlv_buf = &msg->svc.tlv;
	int tlv_len = le16_to_cpu(msg->svc.tlv_len);
	struct tlv *tlv;
	int i;

	memset(res, 0, sizeof(*res));

	__qmi_alloc_reset();
	while ((tlv = tlv_get_next(&tlv_buf, &tlv_len)) != NULL) {
		unsigned int cur_tlv_len = le16_to_cpu(tlv->len);
		unsigned int ofs = 0;

		switch(tlv->type) {
		case 0x01:
			qmi_set(res, memory_index, le32_to_cpu(*(uint32_t *) get_next(4)));
			break;

		default:
			break;
		}
	}

	return 0;

error_len:
	fprintf(stderr, "%s: Invalid TLV length in message, tlv=0x%02x, len=%d\n",
	        __func__, tlv->type, le16_to_cpu(tlv->len));
	return QMI_ERROR_INVALID_DATA;
}

int qmi_set_wms_raw_read_request(struct qmi_msg *msg, struct qmi_wms_raw_read_request *req)
{
	qmi_init_request_message(msg, QMI_SERVICE_WMS);
	msg->svc.message = cpu_to_le16(0x0022);

	if (req->set.message_memory_storage_id) {
		void *buf;
		int ofs;

		__qmi_alloc_reset();
		put_tlv_var(uint8_t, req->data.message_memory_storage_id.storage_type, 1);
		put_tlv_var(uint32_t, cpu_to_le32(req->data.message_memory_storage_id.memory_index), 4);

		buf = __qmi_get_buf(&ofs);
		tlv_new(msg, 0x01, ofs, buf);
	}

	if (req->set.message_mode) {
		void *buf;
		int ofs;

		__qmi_alloc_reset();
		put_tlv_var(uint8_t, req->data.message_mode, 1);

		buf = __qmi_get_buf(&ofs);
		tlv_new(msg, 0x10, ofs, buf);
	}

	if (req->set.sms_on_ims) {
		void *buf;
		int ofs;

		__qmi_alloc_reset();
		put_tlv_var(uint8_t, req->data.sms_on_ims, 1);

		buf = __qmi_get_buf(&ofs);
		tlv_new(msg, 0x11, ofs, buf);
	}

	return 0;
}

int qmi_parse_wms_raw_read_response(struct qmi_msg *msg, struct qmi_wms_raw_read_response *res)
{
	void *tlv_buf = &msg->svc.tlv;
	int tlv_len = le16_to_cpu(msg->svc.tlv_len);
	struct tlv *tlv;
	int i;

	memset(res, 0, sizeof(*res));

	__qmi_alloc_reset();
	while ((tlv = tlv_get_next(&tlv_buf, &tlv_len)) != NULL) {
		unsigned int cur_tlv_len = le16_to_cpu(tlv->len);
		unsigned int ofs = 0;

		switch(tlv->type) {
		case 0x01:
			res->set.raw_message_data = 1;
			res->data.raw_message_data.message_tag = *(uint8_t *) get_next(1);
			res->data.raw_message_data.format = *(uint8_t *) get_next(1);
			i = le16_to_cpu(*(uint16_t *) get_next(2));
			res->data.raw_message_data.raw_data = __qmi_alloc_static(i);
			while(i-- > 0) {
				res->data.raw_message_data.raw_data[res->data.raw_message_data.raw_data_n] = *(uint8_t *) get_next(1);
				res->data.raw_message_data.raw_data_n++;
			}
			break;

		default:
			break;
		}
	}

	return 0;

error_len:
	fprintf(stderr, "%s: Invalid TLV length in message, tlv=0x%02x, len=%d\n",
	        __func__, tlv->type, le16_to_cpu(tlv->len));
	return QMI_ERROR_INVALID_DATA;
}

int qmi_set_wms_modify_tag_request(struct qmi_msg *msg, struct qmi_wms_modify_tag_request *req)
{
	qmi_init_request_message(msg, QMI_SERVICE_WMS);
	msg->svc.message = cpu_to_le16(0x0023);

	if (req->set.message_tag) {
		void *buf;
		int ofs;

		__qmi_alloc_reset();
		put_tlv_var(uint8_t, req->data.message_tag.storage_type, 1);
		put_tlv_var(uint32_t, cpu_to_le32(req->data.message_tag.memory_index), 4);
		put_tlv_var(uint8_t, req->data.message_tag.message_tag, 1);

		buf = __qmi_get_buf(&ofs);
		tlv_new(msg, 0x01, ofs, buf);
	}

	if (req->set.message_mode) {
		void *buf;
		int ofs;

		__qmi_alloc_reset();
		put_tlv_var(uint8_t, req->data.message_mode, 1);

		buf = __qmi_get_buf(&ofs);
		tlv_new(msg, 0x10, ofs, buf);
	}

	return 0;
}

int qmi_parse_wms_modify_tag_response(struct qmi_msg *msg)
{
	void *tlv_buf = &msg->svc.tlv;
	int tlv_len = le16_to_cpu(msg->svc.tlv_len);

	return qmi_check_message_status(tlv_buf, tlv_len);
}

int qmi_set_wms_delete_request(struct qmi_msg *msg, struct qmi_wms_delete_request *req)
{
	qmi_init_request_message(msg, QMI_SERVICE_WMS);
	msg->svc.message = cpu_to_le16(0x0024);

	if (req->set.memory_storage) {
		void *buf;
		int ofs;

		__qmi_alloc_reset();
		put_tlv_var(uint8_t, req->data.memory_storage, 1);

		buf = __qmi_get_buf(&ofs);
		tlv_new(msg, 0x01, ofs, buf);
	}

	if (req->set.memory_index) {
		void *buf;
		int ofs;

		__qmi_alloc_reset();
		put_tlv_var(uint32_t, cpu_to_le32(req->data.memory_index), 4);

		buf = __qmi_get_buf(&ofs);
		tlv_new(msg, 0x10, ofs, buf);
	}

	if (req->set.message_tag) {
		void *buf;
		int ofs;

		__qmi_alloc_reset();
		put_tlv_var(uint8_t, req->data.message_tag, 1);

		buf = __qmi_get_buf(&ofs);
		tlv_new(msg, 0x11, ofs, buf);
	}

	if (req->set.message_mode) {
		void *buf;
		int ofs;

		__qmi_alloc_reset();
		put_tlv_var(uint8_t, req->data.message_mode, 1);

		buf = __qmi_get_buf(&ofs);
		tlv_new(msg, 0x12, ofs, buf);
	}

	return 0;
}

int qmi_parse_wms_delete_response(struct qmi_msg *msg)
{
	void *tlv_buf = &msg->svc.tlv;
	int tlv_len = le16_to_cpu(msg->svc.tlv_len);

	return qmi_check_message_status(tlv_buf, tlv_len);
}

int qmi_set_wms_get_message_protocol_request(struct qmi_msg *msg)
{
	qmi_init_request_message(msg, QMI_SERVICE_WMS);
	msg->svc.message = cpu_to_le16(0x0030);

	return 0;
}

int qmi_parse_wms_get_message_protocol_response(struct qmi_msg *msg, struct qmi_wms_get_message_protocol_response *res)
{
	void *tlv_buf = &msg->svc.tlv;
	int tlv_len = le16_to_cpu(msg->svc.tlv_len);
	struct tlv *tlv;
	int i;

	memset(res, 0, sizeof(*res));

	__qmi_alloc_reset();
	while ((tlv = tlv_get_next(&tlv_buf, &tlv_len)) != NULL) {
		unsigned int cur_tlv_len = le16_to_cpu(tlv->len);
		unsigned int ofs = 0;

		switch(tlv->type) {
		case 0x01:
			qmi_set(res, message_protocol, *(uint8_t *) get_next(1));
			break;

		default:
			break;
		}
	}

	return 0;

error_len:
	fprintf(stderr, "%s: Invalid TLV length in message, tlv=0x%02x, len=%d\n",
	        __func__, tlv->type, le16_to_cpu(tlv->len));
	return QMI_ERROR_INVALID_DATA;
}

int qmi_set_wms_list_messages_request(struct qmi_msg *msg, struct qmi_wms_list_messages_request *req)
{
	qmi_init_request_message(msg, QMI_SERVICE_WMS);
	msg->svc.message = cpu_to_le16(0x0031);

	if (req->set.storage_type) {
		void *buf;
		int ofs;

		__qmi_alloc_reset();
		put_tlv_var(uint8_t, req->data.storage_type, 1);

		buf = __qmi_get_buf(&ofs);
		tlv_new(msg, 0x01, ofs, buf);
	}

	if (req->set.message_tag) {
		void *buf;
		int ofs;

		__qmi_alloc_reset();
		put_tlv_var(uint8_t, req->data.message_tag, 1);

		buf = __qmi_get_buf(&ofs);
		tlv_new(msg, 0x11, ofs, buf);
	}

	if (req->set.message_mode) {
		void *buf;
		int ofs;

		__qmi_alloc_reset();
		put_tlv_var(uint8_t, req->data.message_mode, 1);

		buf = __qmi_get_buf(&ofs);
		tlv_new(msg, 0x12, ofs, buf);
	}

	return 0;
}

int qmi_parse_wms_list_messages_response(struct qmi_msg *msg, struct qmi_wms_list_messages_response *res)
{
	void *tlv_buf = &msg->svc.tlv;
	int tlv_len = le16_to_cpu(msg->svc.tlv_len);
	struct tlv *tlv;
	int i;

	memset(res, 0, sizeof(*res));

	__qmi_alloc_reset();
	while ((tlv = tlv_get_next(&tlv_buf, &tlv_len)) != NULL) {
		unsigned int cur_tlv_len = le16_to_cpu(tlv->len);
		unsigned int ofs = 0;

		switch(tlv->type) {
		case 0x01:
			i = le32_to_cpu(*(uint32_t *) get_next(4));
			res->data.message_list = __qmi_alloc_static(i);
			while(i-- > 0) {
				res->data.message_list[res->data.message_list_n].memory_index = le32_to_cpu(*(uint32_t *) get_next(4));
				res->data.message_list[res->data.message_list_n].message_tag = *(uint8_t *) get_next(1);
				res->data.message_list_n++;
			}

			break;

		default:
			break;
		}
	}

	return 0;

error_len:
	fprintf(stderr, "%s: Invalid TLV length in message, tlv=0x%02x, len=%d\n",
	        __func__, tlv->type, le16_to_cpu(tlv->len));
	return QMI_ERROR_INVALID_DATA;
}

int qmi_set_wms_set_routes_request(struct qmi_msg *msg, struct qmi_wms_set_routes_request *req)
{
	qmi_init_request_message(msg, QMI_SERVICE_WMS);
	msg->svc.message = cpu_to_le16(0x0032);

	if (req->data.route_list) {
		void *buf;
		int ofs;
		int i;

		__qmi_alloc_reset();
		put_tlv_var(uint16_t, cpu_to_le16(req->data.route_list_n), 2);
		for (i = 0; i < req->data.route_list_n; i++) {
			put_tlv_var(uint8_t, req->data.route_list[i].message_type, 1);
			put_tlv_var(uint8_t, req->data.route_list[i].message_class, 1);
			put_tlv_var(uint8_t, req->data.route_list[i].storage, 1);
			put_tlv_var(uint8_t, req->data.route_list[i].receipt_action, 1);
		}

		buf = __qmi_get_buf(&ofs);
		tlv_new(msg, 0x01, ofs, buf);
	}

	if (req->set.transfer_status_report) {
		void *buf;
		int ofs;

		__qmi_alloc_reset();
		put_tlv_var(uint8_t, req->data.transfer_status_report, 1);

		buf = __qmi_get_buf(&ofs);
		tlv_new(msg, 0x10, ofs, buf);
	}

	return 0;
}

int qmi_parse_wms_set_routes_response(struct qmi_msg *msg)
{
	void *tlv_buf = &msg->svc.tlv;
	int tlv_len = le16_to_cpu(msg->svc.tlv_len);

	return qmi_check_message_status(tlv_buf, tlv_len);
}

int qmi_set_wms_get_routes_request(struct qmi_msg *msg)
{
	qmi_init_request_message(msg, QMI_SERVICE_WMS);
	msg->svc.message = cpu_to_le16(0x0033);

	return 0;
}

int qmi_parse_wms_get_routes_response(struct qmi_msg *msg, struct qmi_wms_get_routes_response *res)
{
	void *tlv_buf = &msg->svc.tlv;
	int tlv_len = le16_to_cpu(msg->svc.tlv_len);
	struct tlv *tlv;
	int i;

	memset(res, 0, sizeof(*res));

	__qmi_alloc_reset();
	while ((tlv = tlv_get_next(&tlv_buf, &tlv_len)) != NULL) {
		unsigned int cur_tlv_len = le16_to_cpu(tlv->len);
		unsigned int ofs = 0;

		switch(tlv->type) {
		case 0x01:
			i = le16_to_cpu(*(uint16_t *) get_next(2));
			res->data.route_list = __qmi_alloc_static(i);
			while(i-- > 0) {
				res->data.route_list[res->data.route_list_n].message_type = *(uint8_t *) get_next(1);
				res->data.route_list[res->data.route_list_n].message_class = *(uint8_t *) get_next(1);
				res->data.route_list[res->data.route_list_n].storage = *(uint8_t *) get_next(1);
				res->data.route_list[res->data.route_list_n].receipt_action = *(uint8_t *) get_next(1);
				res->data.route_list_n++;
			}

			break;

		case 0x10:
			qmi_set(res, transfer_status_report, *(uint8_t *) get_next(1));
			break;

		default:
			break;
		}
	}

	return 0;

error_len:
	fprintf(stderr, "%s: Invalid TLV length in message, tlv=0x%02x, len=%d\n",
	        __func__, tlv->type, le16_to_cpu(tlv->len));
	return QMI_ERROR_INVALID_DATA;
}

int qmi_set_wms_send_from_memory_storage_request(struct qmi_msg *msg, struct qmi_wms_send_from_memory_storage_request *req)
{
	qmi_init_request_message(msg, QMI_SERVICE_WMS);
	msg->svc.message = cpu_to_le16(0x0042);

	if (req->set.information) {
		void *buf;
		int ofs;

		__qmi_alloc_reset();
		put_tlv_var(uint8_t, req->data.information.storage_type, 1);
		put_tlv_var(uint32_t, cpu_to_le32(req->data.information.memory_index), 4);
		put_tlv_var(uint8_t, req->data.information.message_mode, 1);

		buf = __qmi_get_buf(&ofs);
		tlv_new(msg, 0x01, ofs, buf);
	}

	if (req->set.sms_on_ims) {
		void *buf;
		int ofs;

		__qmi_alloc_reset();
		put_tlv_var(uint8_t, req->data.sms_on_ims, 1);

		buf = __qmi_get_buf(&ofs);
		tlv_new(msg, 0x10, ofs, buf);
	}

	return 0;
}

int qmi_parse_wms_send_from_memory_storage_response(struct qmi_msg *msg, struct qmi_wms_send_from_memory_storage_response *res)
{
	void *tlv_buf = &msg->svc.tlv;
	int tlv_len = le16_to_cpu(msg->svc.tlv_len);
	struct tlv *tlv;
	int i;

	memset(res, 0, sizeof(*res));

	__qmi_alloc_reset();
	while ((tlv = tlv_get_next(&tlv_buf, &tlv_len)) != NULL) {
		unsigned int cur_tlv_len = le16_to_cpu(tlv->len);
		unsigned int ofs = 0;

		switch(tlv->type) {
		case 0x10:
			qmi_set(res, message_id, le16_to_cpu(*(uint16_t *) get_next(2)));
			break;

		case 0x11:
			qmi_set(res, cdma_cause_code, le16_to_cpu(*(uint16_t *) get_next(2)));
			break;

		case 0x12:
			qmi_set(res, cdma_error_class, *(uint8_t *) get_next(1));
			break;

		case 0x13:
			res->set.gsm_wcdma_cause_info = 1;
			res->data.gsm_wcdma_cause_info.rp_cause = le16_to_cpu(*(uint16_t *) get_next(2));
			res->data.gsm_wcdma_cause_info.tp_cause = *(uint8_t *) get_next(1);
			break;

		case 0x14:
			qmi_set(res, message_delivery_failure_type, *(uint8_t *) get_next(1));
			break;

		default:
			break;
		}
	}

	return 0;

error_len:
	fprintf(stderr, "%s: Invalid TLV length in message, tlv=0x%02x, len=%d\n",
	        __func__, tlv->type, le16_to_cpu(tlv->len));
	return QMI_ERROR_INVALID_DATA;
}
