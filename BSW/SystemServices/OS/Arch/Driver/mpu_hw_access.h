/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
 *
 * THIS SOFTWARE IS PROVIDED BY NXP "AS IS" AND ANY EXPRESSED OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL NXP OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */

/*!
 * @file mpu_hw_access.h
 */

#ifndef MPU_HW_ACCESS_H
#define MPU_HW_ACCESS_H

#include "mpu_driver.h"


/*!
 * @brief Memory Protection Unit Hardware Access layer.
 * @{
 */

/*******************************************************************************
 * API
 *******************************************************************************/
#if defined(__cplusplus)
extern "C"
{
#endif

    /*!
     * @brief Gets the error status of a specified slave port.
     *
     * @param[in] base The MPU peripheral base address.
     * @param[in] slaveNum The slave port number.
     * @return The slave ports error status:
     *            - true  : error happens in this slave port.
     *            - false : error didn't happen in this slave port.
     */
    static inline boolean Mpu_GetErrorRegisters(uint32* pMmfsr, uint32* pAddress)
    {
    }

    /*! @} */

#if defined(__cplusplus)
}
#endif

/*! @} */

#endif /* MPU_HW_ACCESS_H */
/*******************************************************************************
 * EOF
 *******************************************************************************/
