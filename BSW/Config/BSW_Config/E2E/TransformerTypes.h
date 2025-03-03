/*******************************************************************************
**                                                                            **
** Copyright (C) iSOFT   (2022)                                               **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to iSOFT.         **
** Passing on and copying of this document, and communication                 **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME    : TransformerTypes.h                                          **
**                                                                            **
**  Created on  : 2024/04/10 11:04:11                                         **
**  Author      :                                                             **
**  Vendor      :                                                             **
**  DESCRIPTION :                                                             **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/
#ifndef TRANSFORMER_TYPES_H_
#define TRANSFORMER_TYPES_H_

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Std_Types.h"
/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
typedef enum
{
    ALL16BIT = 0u,
    ALTERNATING8BIT,
    LOWER12BIT,
    LOWER8BIT,
    NOTUSED
} DataIdModeType;

typedef enum
{
    CUSTOM = 0u,
    SAFETY,
    SECURITY,
    SERIALIZER
} TransformerClassType;

typedef enum
{
    PRE_R4_2 = 0u,
    R4_2
} ProfileBehaviorType;

typedef struct
{
    const uint16 counterOffset;
    const uint16 crcOffset;
    const DataIdModeType dataIdMode;
    const uint16 dataIdNibbleOffset;
    const uint8 maxDeltaCounter;
    const uint8 maxErrorStateInit;
    const uint8 maxErrorStateInvalid;
    const uint8 maxErrorStateValid;
    const uint8 maxNoNewOrRepeatedData;
    const uint8 minOkStateInit;
    const uint8 minOkStateInvalid;
    const uint8 minOkStateValid;
    const ProfileBehaviorType profileBehavior;
    const char *profileName;
    const uint8 syncCounterInit;
    const uint16 upperHeaderBitsToShift;
    const uint8 windowSizeInit;
    const uint8 windowSizeValid;
    const uint8 windowSizeInvalid;
    const boolean clearFromValidToInvalid;
} EndToEndTransformationDescriptionType_PROFILE_01;

typedef struct
{
    const uint16 dataId;
    const uint16 dataLength;
} EndToEndTransformationISignalPropsType_PROFILE_01;

typedef struct
{
    const boolean disabelEndToEndCheck;
    const uint32 maxDeltaCounter;
    const uint8 maxErrorStateInit;
    const uint8 maxErrorStateInvalid;
    const uint8 maxErrorStateValid;
    const uint8 maxNoNewOrRepeatedData;
    const uint8 minOkStateInit;
    const uint8 minOkStateInvalid;
    const uint8 minOkStateValid;
    const uint8 syncCounterInit;
    const uint8 windowSizeInit;
    const uint8 windowSizeValid;
    const uint8 windowSizeInvalid;
    const boolean clearFromValidToInvalid;
} EndToEndTransformationComSpecPropsType;

typedef struct
{
    const uint16 headerLength;
    const boolean inPlace;
} BufferProperytType;

typedef struct
{
    const BufferProperytType bufferProperty;
    const boolean needsOriginalData;
    const char *protocol;
    const EndToEndTransformationDescriptionType_PROFILE_01*E2EXfDescription;
    const TransformerClassType transformerClass;
    const char *version;
} TransformationTechnologyType_PROFILE_01;

typedef struct
{
    const TransformationTechnologyType_PROFILE_01 *E2EXfTechnology;
    const EndToEndTransformationISignalPropsType_PROFILE_01 *E2EXfISignalProps;
    const EndToEndTransformationComSpecPropsType *E2EXfComSpecProps;
} E2EXf_ConfigType_PROFILE_01;

typedef struct
{
    const E2EXf_ConfigType_PROFILE_01* E2EXf_Config_PROFILE_01;
}E2EXf_ConfigType;
/*******************************************************************************
**                      Global Data Declaration                               **
*******************************************************************************/
/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/
#endif/* TRANSFORMER_TYPES_H_ */

