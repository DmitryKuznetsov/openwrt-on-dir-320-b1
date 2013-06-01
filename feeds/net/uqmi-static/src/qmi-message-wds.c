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

int qmi_set_wds_reset_request(struct qmi_msg *msg)
{
	qmi_init_request_message(msg, QMI_SERVICE_WDS);
	msg->svc.message = cpu_to_le16(0x0000);

	return 0;
}

int qmi_parse_wds_reset_response(struct qmi_msg *msg)
{
	void *tlv_buf = &msg->svc.tlv;
	int tlv_len = le16_to_cpu(msg->svc.tlv_len);

	return qmi_check_message_status(tlv_buf, tlv_len);
}

int qmi_set_wds_abort_request(struct qmi_msg *msg, struct qmi_wds_abort_request *req)
{
	qmi_init_request_message(msg, QMI_SERVICE_WDS);
	msg->svc.message = cpu_to_le16(0x0002);

	if (req->set.transaction_id) {
		void *buf;
		int ofs;

		__qmi_alloc_reset();
		put_tlv_var(uint16_t, cpu_to_le16(req->data.transaction_id), 2);

		buf = __qmi_get_buf(&ofs);
		tlv_new(msg, 0x01, ofs, buf);
	}

	return 0;
}

int qmi_parse_wds_abort_response(struct qmi_msg *msg)
{
	void *tlv_buf = &msg->svc.tlv;
	int tlv_len = le16_to_cpu(msg->svc.tlv_len);

	return qmi_check_message_status(tlv_buf, tlv_len);
}

int qmi_set_wds_start_network_request(struct qmi_msg *msg, struct qmi_wds_start_network_request *req)
{
	qmi_init_request_message(msg, QMI_SERVICE_WDS);
	msg->svc.message = cpu_to_le16(0x0020);

	if (req->set.primary_dns_address_preference) {
		void *buf;
		int ofs;

		__qmi_alloc_reset();
		put_tlv_var(uint32_t, cpu_to_le32(req->data.primary_dns_address_preference), 4);

		buf = __qmi_get_buf(&ofs);
		tlv_new(msg, 0x10, ofs, buf);
	}

	if (req->set.secondary_dns_address_preference) {
		void *buf;
		int ofs;

		__qmi_alloc_reset();
		put_tlv_var(uint32_t, cpu_to_le32(req->data.secondary_dns_address_preference), 4);

		buf = __qmi_get_buf(&ofs);
		tlv_new(msg, 0x11, ofs, buf);
	}

	if (req->set.primary_nbns_address_preference) {
		void *buf;
		int ofs;

		__qmi_alloc_reset();
		put_tlv_var(uint32_t, cpu_to_le32(req->data.primary_nbns_address_preference), 4);

		buf = __qmi_get_buf(&ofs);
		tlv_new(msg, 0x12, ofs, buf);
	}

	if (req->set.secondary_nbns_address_preference) {
		void *buf;
		int ofs;

		__qmi_alloc_reset();
		put_tlv_var(uint32_t, cpu_to_le32(req->data.secondary_nbns_address_preference), 4);

		buf = __qmi_get_buf(&ofs);
		tlv_new(msg, 0x13, ofs, buf);
	}

	if (req->data.apn) {
		void *buf;
		int ofs;
		int i;

		__qmi_alloc_reset();
		i = strlen(req->data.apn);
		strncpy(__qmi_alloc_static(i), req->data.apn, i);

		buf = __qmi_get_buf(&ofs);
		tlv_new(msg, 0x14, ofs, buf);
	}

	if (req->set.ipv4_address_preference) {
		void *buf;
		int ofs;

		__qmi_alloc_reset();
		put_tlv_var(uint32_t, cpu_to_le32(req->data.ipv4_address_preference), 4);

		buf = __qmi_get_buf(&ofs);
		tlv_new(msg, 0x15, ofs, buf);
	}

	if (req->set.authentication_preference) {
		void *buf;
		int ofs;

		__qmi_alloc_reset();
		put_tlv_var(uint8_t, req->data.authentication_preference, 1);

		buf = __qmi_get_buf(&ofs);
		tlv_new(msg, 0x16, ofs, buf);
	}

	if (req->data.username) {
		void *buf;
		int ofs;
		int i;

		__qmi_alloc_reset();
		i = strlen(req->data.username);
		strncpy(__qmi_alloc_static(i), req->data.username, i);

		buf = __qmi_get_buf(&ofs);
		tlv_new(msg, 0x17, ofs, buf);
	}

	if (req->data.password) {
		void *buf;
		int ofs;
		int i;

		__qmi_alloc_reset();
		i = strlen(req->data.password);
		strncpy(__qmi_alloc_static(i), req->data.password, i);

		buf = __qmi_get_buf(&ofs);
		tlv_new(msg, 0x18, ofs, buf);
	}

	if (req->set.ip_family_preference) {
		void *buf;
		int ofs;

		__qmi_alloc_reset();
		put_tlv_var(uint8_t, req->data.ip_family_preference, 1);

		buf = __qmi_get_buf(&ofs);
		tlv_new(msg, 0x19, ofs, buf);
	}

	if (req->set.technology_preference) {
		void *buf;
		int ofs;

		__qmi_alloc_reset();
		put_tlv_var(uint8_t, req->data.technology_preference, 1);

		buf = __qmi_get_buf(&ofs);
		tlv_new(msg, 0x30, ofs, buf);
	}

	if (req->set.profile_index_3gpp) {
		void *buf;
		int ofs;

		__qmi_alloc_reset();
		put_tlv_var(uint8_t, req->data.profile_index_3gpp, 1);

		buf = __qmi_get_buf(&ofs);
		tlv_new(msg, 0x31, ofs, buf);
	}

	if (req->set.profile_index_3gpp2) {
		void *buf;
		int ofs;

		__qmi_alloc_reset();
		put_tlv_var(uint8_t, req->data.profile_index_3gpp2, 1);

		buf = __qmi_get_buf(&ofs);
		tlv_new(msg, 0x32, ofs, buf);
	}

	if (req->set.enable_autoconnect) {
		void *buf;
		int ofs;

		__qmi_alloc_reset();
		put_tlv_var(uint8_t, req->data.enable_autoconnect, 1);

		buf = __qmi_get_buf(&ofs);
		tlv_new(msg, 0x33, ofs, buf);
	}

	if (req->set.extended_technology_preference) {
		void *buf;
		int ofs;

		__qmi_alloc_reset();
		put_tlv_var(uint16_t, cpu_to_le16(req->data.extended_technology_preference), 2);

		buf = __qmi_get_buf(&ofs);
		tlv_new(msg, 0x34, ofs, buf);
	}

	if (req->set.call_type) {
		void *buf;
		int ofs;

		__qmi_alloc_reset();
		put_tlv_var(uint8_t, req->data.call_type, 1);

		buf = __qmi_get_buf(&ofs);
		tlv_new(msg, 0x35, ofs, buf);
	}

	return 0;
}

int qmi_parse_wds_start_network_response(struct qmi_msg *msg, struct qmi_wds_start_network_response *res)
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
			qmi_set(res, packet_data_handle, le32_to_cpu(*(uint32_t *) get_next(4)));
			break;

		case 0x10:
			qmi_set(res, call_end_reason, le16_to_cpu(*(uint16_t *) get_next(2)));
			break;

		case 0x11:
			res->set.verbose_call_end_reason = 1;
			res->data.verbose_call_end_reason.type = le16_to_cpu(*(uint16_t *) get_next(2));
			res->data.verbose_call_end_reason.reason = le16_to_cpu(*(uint16_t *) get_next(2));
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

int qmi_set_wds_stop_network_request(struct qmi_msg *msg, struct qmi_wds_stop_network_request *req)
{
	qmi_init_request_message(msg, QMI_SERVICE_WDS);
	msg->svc.message = cpu_to_le16(0x0021);

	if (req->set.packet_data_handle) {
		void *buf;
		int ofs;

		__qmi_alloc_reset();
		put_tlv_var(uint32_t, cpu_to_le32(req->data.packet_data_handle), 4);

		buf = __qmi_get_buf(&ofs);
		tlv_new(msg, 0x01, ofs, buf);
	}

	if (req->set.disable_autoconnect) {
		void *buf;
		int ofs;

		__qmi_alloc_reset();
		put_tlv_var(uint8_t, req->data.disable_autoconnect, 1);

		buf = __qmi_get_buf(&ofs);
		tlv_new(msg, 0x10, ofs, buf);
	}

	return 0;
}

int qmi_parse_wds_stop_network_response(struct qmi_msg *msg)
{
	void *tlv_buf = &msg->svc.tlv;
	int tlv_len = le16_to_cpu(msg->svc.tlv_len);

	return qmi_check_message_status(tlv_buf, tlv_len);
}

int qmi_set_wds_get_packet_service_status_request(struct qmi_msg *msg)
{
	qmi_init_request_message(msg, QMI_SERVICE_WDS);
	msg->svc.message = cpu_to_le16(0x0022);

	return 0;
}

int qmi_parse_wds_get_packet_service_status_response(struct qmi_msg *msg, struct qmi_wds_get_packet_service_status_response *res)
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
			qmi_set(res, connection_status, *(uint8_t *) get_next(1));
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

int qmi_set_wds_get_current_settings_request(struct qmi_msg *msg, struct qmi_wds_get_current_settings_request *req)
{
	qmi_init_request_message(msg, QMI_SERVICE_WDS);
	msg->svc.message = cpu_to_le16(0x002D);

	if (req->set.requested_settings) {
		void *buf;
		int ofs;

		__qmi_alloc_reset();
		put_tlv_var(uint32_t, cpu_to_le32(req->data.requested_settings), 4);

		buf = __qmi_get_buf(&ofs);
		tlv_new(msg, 0x10, ofs, buf);
	}

	return 0;
}

int qmi_parse_wds_get_current_settings_response(struct qmi_msg *msg, struct qmi_wds_get_current_settings_response *res)
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
			i = cur_tlv_len - ofs;
			res->data.profile_name = __qmi_copy_string(get_next(i), i);
			break;

		case 0x11:
			qmi_set(res, pdp_type, *(uint8_t *) get_next(1));
			break;

		case 0x14:
			i = cur_tlv_len - ofs;
			res->data.apn_name = __qmi_copy_string(get_next(i), i);
			break;

		case 0x15:
			qmi_set(res, primary_ipv4_dns_address, le32_to_cpu(*(uint32_t *) get_next(4)));
			break;

		case 0x16:
			qmi_set(res, secondary_ipv4_dns_address, le32_to_cpu(*(uint32_t *) get_next(4)));
			break;

		case 0x19:
			res->set.gprs_granted_qos = 1;
			res->data.gprs_granted_qos.precedence_class = le32_to_cpu(*(uint32_t *) get_next(4));
			res->data.gprs_granted_qos.delay_class = le32_to_cpu(*(uint32_t *) get_next(4));
			res->data.gprs_granted_qos.reliability_class = le32_to_cpu(*(uint32_t *) get_next(4));
			res->data.gprs_granted_qos.peak_throughput_class = le32_to_cpu(*(uint32_t *) get_next(4));
			res->data.gprs_granted_qos.mean_throughput_class = le32_to_cpu(*(uint32_t *) get_next(4));
			break;

		case 0x1B:
			i = cur_tlv_len - ofs;
			res->data.username = __qmi_copy_string(get_next(i), i);
			break;

		case 0x1D:
			qmi_set(res, authentication, *(uint8_t *) get_next(1));
			break;

		case 0x1E:
			qmi_set(res, ipv4_address, le32_to_cpu(*(uint32_t *) get_next(4)));
			break;

		case 0x1F:
			res->set.profile_id = 1;
			res->data.profile_id.profile_type = *(uint8_t *) get_next(1);
			res->data.profile_id.profile_index = *(uint8_t *) get_next(1);
			break;

		case 0x20:
			qmi_set(res, ipv4_gateway_address, le32_to_cpu(*(uint32_t *) get_next(4)));
			break;

		case 0x21:
			qmi_set(res, ipv4_gateway_subnet_mask, le32_to_cpu(*(uint32_t *) get_next(4)));
			break;

		case 0x22:
			qmi_set(res, pcscf_address_using_pco, *(uint8_t *) get_next(1));
			break;

		case 0x23:
			i = *(uint8_t *) get_next(1);
			res->data.pcscf_server_address_list = __qmi_alloc_static(i);
			while(i-- > 0) {
				res->data.pcscf_server_address_list[res->data.pcscf_server_address_list_n] = le32_to_cpu(*(uint32_t *) get_next(4));
				res->data.pcscf_server_address_list_n++;
			}

			break;

		case 0x24:
			i = *(uint8_t *) get_next(1);
			res->data.pcscf_domain_name_list = __qmi_alloc_static(i);
			while(i-- > 0) {
				int ii;
				ii = le16_to_cpu(*(uint16_t *) get_next(2));
				res->data.pcscf_domain_name_list[res->data.pcscf_domain_name_list_n] = __qmi_copy_string(get_next(ii), ii);
				res->data.pcscf_domain_name_list_n++;
			}

			break;

		case 0x25:
			res->set.ipv6_address = 1;
			for (i = 0; i < 8; i++) {
				res->data.ipv6_address.address[i] = be16_to_cpu(*(uint16_t *) get_next(2));
			}
			res->data.ipv6_address.prefix_length = *(uint8_t *) get_next(1);
			break;

		case 0x26:
			res->set.ipv6_gateway_address = 1;
			for (i = 0; i < 8; i++) {
				res->data.ipv6_gateway_address.address[i] = be16_to_cpu(*(uint16_t *) get_next(2));
			}
			res->data.ipv6_gateway_address.prefix_length = *(uint8_t *) get_next(1);
			break;

		case 0x27:
			res->set.ipv6_primary_dns_address = 1;
			for (i = 0; i < 8; i++) {
				res->data.ipv6_primary_dns_address[i] = be16_to_cpu(*(uint16_t *) get_next(2));
			}

			break;

		case 0x28:
			res->set.ipv6_secondary_dns_address = 1;
			for (i = 0; i < 8; i++) {
				res->data.ipv6_secondary_dns_address[i] = be16_to_cpu(*(uint16_t *) get_next(2));
			}

			break;

		case 0x29:
			qmi_set(res, mtu, le32_to_cpu(*(uint32_t *) get_next(4)));
			break;

		case 0x2A:
			i = *(uint8_t *) get_next(1);
			res->data.domain_name_list = __qmi_alloc_static(i);
			while(i-- > 0) {
				int ii;
				ii = le16_to_cpu(*(uint16_t *) get_next(2));
				res->data.domain_name_list[res->data.domain_name_list_n] = __qmi_copy_string(get_next(ii), ii);
				res->data.domain_name_list_n++;
			}

			break;

		case 0x2B:
			qmi_set(res, ip_family, *(uint8_t *) get_next(1));
			break;

		case 0x2C:
			qmi_set(res, imcn_flag, *(int8_t *) get_next(1));
			break;

		case 0x2D:
			qmi_set(res, extended_technology_preference, le16_to_cpu(*(uint16_t *) get_next(2)));
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

int qmi_set_wds_get_data_bearer_technology_request(struct qmi_msg *msg)
{
	qmi_init_request_message(msg, QMI_SERVICE_WDS);
	msg->svc.message = cpu_to_le16(0x0037);

	return 0;
}

int qmi_parse_wds_get_data_bearer_technology_response(struct qmi_msg *msg, struct qmi_wds_get_data_bearer_technology_response *res)
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
			qmi_set(res, current, *(int8_t *) get_next(1));
			break;

		case 0x10:
			qmi_set(res, last, *(int8_t *) get_next(1));
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

int qmi_set_wds_get_current_data_bearer_technology_request(struct qmi_msg *msg)
{
	qmi_init_request_message(msg, QMI_SERVICE_WDS);
	msg->svc.message = cpu_to_le16(0x0044);

	return 0;
}

int qmi_parse_wds_get_current_data_bearer_technology_response(struct qmi_msg *msg, struct qmi_wds_get_current_data_bearer_technology_response *res)
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
			res->set.current = 1;
			res->data.current.network_type = *(uint8_t *) get_next(1);
			res->data.current.rat_mask = le32_to_cpu(*(uint32_t *) get_next(4));
			res->data.current.so_mask = le32_to_cpu(*(uint32_t *) get_next(4));
			break;

		case 0x10:
			res->set.last = 1;
			res->data.last.network_type = *(uint8_t *) get_next(1);
			res->data.last.rat_mask = le32_to_cpu(*(uint32_t *) get_next(4));
			res->data.last.so_mask = le32_to_cpu(*(uint32_t *) get_next(4));
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

int qmi_set_wds_set_ip_family_request(struct qmi_msg *msg, struct qmi_wds_set_ip_family_request *req)
{
	qmi_init_request_message(msg, QMI_SERVICE_WDS);
	msg->svc.message = cpu_to_le16(0x004D);

	if (req->set.preference) {
		void *buf;
		int ofs;

		__qmi_alloc_reset();
		put_tlv_var(uint8_t, req->data.preference, 1);

		buf = __qmi_get_buf(&ofs);
		tlv_new(msg, 0x01, ofs, buf);
	}

	return 0;
}

int qmi_parse_wds_set_ip_family_response(struct qmi_msg *msg)
{
	void *tlv_buf = &msg->svc.tlv;
	int tlv_len = le16_to_cpu(msg->svc.tlv_len);

	return qmi_check_message_status(tlv_buf, tlv_len);
}
