/* -*- Mode: C; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

/*
 * libmbim-glib -- GLib/GIO based library to control MBIM devices
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301 USA.
 *
 * Copyright (C) 2013 Aleksander Morgado <aleksander@gnu.org>
 */

#ifndef _LIBMBIM_GLIB_MBIM_UUID_H_
#define _LIBMBIM_GLIB_MBIM_UUID_H_

#if !defined (__LIBMBIM_GLIB_H_INSIDE__) && !defined (LIBMBIM_GLIB_COMPILATION)
#error "Only <libmbim-glib.h> can be included directly."
#endif

#include <glib.h>

G_BEGIN_DECLS

/**
 * MbimUuid:
 *
 * A UUID as defined in MBIM.
 */
typedef struct _MbimUuid MbimUuid;
struct _MbimUuid {
    guint8 a[4];
    guint8 b[2];
    guint8 c[2];
    guint8 d[2];
    guint8 e[6];
} __attribute__((packed));

/**
 * MbimService:
 * @MBIM_SERVICE_INVALID: Invalid service.
 * @MBIM_SERVICE_BASIC_CONNECT: Basic connectivity service.
 * @MBIM_SERVICE_SMS: SMS messaging service.
 * @MBIM_SERVICE_USSD: USSD service.
 * @MBIM_SERVICE_PHONEBOOK: Phonebook service.
 * @MBIM_SERVICE_STK: SIM toolkit service.
 * @MBIM_SERVICE_AUTH: Authentication service.
 * @MBIM_SERVICE_DSS: Device Service Stream service.
 *
 * Enumeration of the generic MBIM services.
 */
typedef enum {
    MBIM_SERVICE_INVALID       = 0,
    MBIM_SERVICE_BASIC_CONNECT = 1,
    MBIM_SERVICE_SMS           = 2,
    MBIM_SERVICE_USSD          = 3,
    MBIM_SERVICE_PHONEBOOK     = 4,
    MBIM_SERVICE_STK           = 5,
    MBIM_SERVICE_AUTH          = 6,
    MBIM_SERVICE_DSS           = 7,
} MbimService;

/**
 * MBIM_UUID_INVALID:
 *
 * Get the UUID of the %MBIM_SERVICE_INVALID service.
 *
 * Returns: (transfer none): a #MbimUuid.
 */
#define MBIM_UUID_INVALID mbim_uuid_get (MBIM_SERVICE_INVALID)

/**
 * MBIM_UUID_BASIC_CONNECT:
 *
 * Get the UUID of the %MBIM_SERVICE_BASIC_CONNECT service.
 *
 * Returns: (transfer none): a #MbimUuid.
 */
#define MBIM_UUID_BASIC_CONNECT mbim_uuid_get (MBIM_SERVICE_BASIC_CONNECT)

/**
 * MBIM_UUID_SMS:
 *
 * Get the UUID of the %MBIM_SERVICE_SMS service.
 *
 * Returns: (transfer none): a #MbimUuid.
 */
#define MBIM_UUID_SMS mbim_uuid_get (MBIM_SERVICE_SMS)

/**
 * MBIM_UUID_USSD:
 *
 * Get the UUID of the %MBIM_SERVICE_USSD service.
 *
 * Returns: (transfer none): a #MbimUuid.
 */
#define MBIM_UUID_USSD mbim_uuid_get (MBIM_SERVICE_USSD)

/**
 * MBIM_UUID_PHONEBOOK:
 *
 * Get the UUID of the %MBIM_SERVICE_PHONEBOOK service.
 *
 * Returns: (transfer none): a #MbimUuid.
 */
#define MBIM_UUID_PHONEBOOK mbim_uuid_get (MBIM_SERVICE_PHONEBOOK)

/**
 * MBIM_UUID_STK:
 *
 * Get the UUID of the %MBIM_SERVICE_STK service.
 *
 * Returns: (transfer none): a #MbimUuid.
 */
#define MBIM_UUID_STK mbim_uuid_get (MBIM_SERVICE_STK)

/**
 * MBIM_UUID_AUTH:
 *
 * Get the UUID of the %MBIM_SERVICE_AUTH service.
 *
 * Returns: (transfer none): a #MbimUuid.
 */
#define MBIM_UUID_AUTH mbim_uuid_get (MBIM_SERVICE_AUTH)

/**
 * MBIM_UUID_DSS:
 *
 * Get the UUID of the %MBIM_SERVICE_DSS service.
 *
 * Returns: (transfer none): a #MbimUuid.
 */
#define MBIM_UUID_DSS mbim_uuid_get (MBIM_SERVICE_DSS)

const MbimUuid *mbim_uuid_get           (MbimService     service);
gboolean        mbim_uuid_cmp           (const MbimUuid *a,
                                         const MbimUuid *b);
gchar          *mbim_uuid_get_printable (const MbimUuid *uuid);
MbimService     mbim_uuid_to_service    (const MbimUuid *uuid);

G_END_DECLS

#endif /* _LIBMBIM_GLIB_MBIM_UUID_H_ */