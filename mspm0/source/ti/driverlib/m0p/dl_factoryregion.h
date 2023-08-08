/*
 * Copyright (c) 2020, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/*!****************************************************************************
 *  @file       dl_factoryregion.h
 *  @brief      Factory Region Driver Library
 *  @defgroup   FACTORYREGION Factory Region (FACTORYREGION)
 *
 *  @anchor ti_dl_dl_factoryregion_Overview
 *  # Overview
 *
 *  <hr>
 ******************************************************************************
 */
/** @addtogroup FACTORYREGION
 * @{
 */
#ifndef ti_dl_dl_factoryregion__include
#define ti_dl_dl_factoryregion__include

#include <stdbool.h>
#include <stdint.h>

#include <ti/devices/msp/msp.h>
#include <ti/driverlib/dl_common.h>

#ifdef __cplusplus
extern "C" {
#endif

/* clang-format off */

/* clang-format on */

/**
 *  @brief   Get the size of the MAIN Flash region
 *
 *  @return  The size of the MAIN Flash region in number of kB.
 */
__STATIC_INLINE uint32_t DL_FactoryRegion_getMAINFlashSize(void)
{
    return (
        FACTORYREGION->SRAMFLASH & FACTORYREGION_SRAMFLASH_MAINFLASH_SZ_MASK);
}

/**
 *  @brief   Get the size of the DATA Flash region
 *
 *  @return  The size of the DATA Flash region in number of kB.
 */
__STATIC_INLINE uint32_t DL_FactoryRegion_getDATAFlashSize(void)
{
    return ((FACTORYREGION->SRAMFLASH &
                FACTORYREGION_SRAMFLASH_DATAFLASH_SZ_MASK) >>
            FACTORYREGION_SRAMFLASH_DATAFLASH_SZ_OFS);
}

/**
 *  @brief   Get the number of Flash banks on the device
 *
 *  @return  The number of flash banks. A value between [1, 4].
 */
__STATIC_INLINE uint8_t DL_FactoryRegion_getNumBanks(void)
{
    return (((FACTORYREGION->SRAMFLASH &
                 FACTORYREGION_SRAMFLASH_MAINNUMBANKS_MASK) >>
                FACTORYREGION_SRAMFLASH_MAINNUMBANKS_OFS) +
            (uint8_t) 1);
}

#ifdef __cplusplus
}
#endif

#endif /* ti_dl_dl_factoryregion__include */
/** @}*/
