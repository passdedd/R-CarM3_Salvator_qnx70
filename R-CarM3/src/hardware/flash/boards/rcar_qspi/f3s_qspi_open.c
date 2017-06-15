/*
 * $QNXLicenseC:
 * Copyright 2016, QNX Software Systems.
 *
 * Licensed under the Apache License, Version 2.0 (the "License"). You
 * may not reproduce, modify or distribute this software except in
 * compliance with the License. You may obtain a copy of the License
 * at: http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTIES OF ANY KIND, either express or implied.
 *
 * This file may contain contributions from others, either as
 * contributors under the License or as licensors under other terms.
 * Please review this entire file for other proprietary rights or license
 * notices, as well as the QNX Development Suite License Guide at
 * http://licensing.qnx.com/license-guide/ for other information.
 * $
 */

#include "f3s_spi.h"

extern void* rpc_init(void *args);

/*
 * This is the open callout for the SPI serial NOR flash driver.
 */
int32_t f3s_qspi_open(f3s_socket_t *socket, uint32_t flags)
{
    /* check if not initialized */
    if (socket->socket_handle != NULL)
        return (EOK);

    socket->name = (unsigned char *)"R-Car HyperFlash";

    if ((socket->socket_handle = rpc_init("")) == NULL)
        return (ENODEV);

    return (EOK);
}

#if defined(__QNXNTO__) && defined(__USESRCVERSION)
#include <sys/srcversion.h>
__SRCVERSION("$URL: http://svn.ott.qnx.com/product/branches/7.0.0/beta/hardware/flash/boards/rcar_qspi/f3s_qspi_open.c $ $Rev: 811059 $")
#endif