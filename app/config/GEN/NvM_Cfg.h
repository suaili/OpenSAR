/*
* Configuration of module: NvM
*
* Created by:   parai          
* Copyright:    (C)parai@foxmail.com  
*
* Configured for (MCU):    MinGW ...
*
* Module vendor:           ArcCore
* Generator version:       2.0.34
*
* Generated by easySAR Studio (https://github.com/parai/OpenSAR)
* Current only for NvM+Fee.
*/

#ifndef NVM_CFG_H_
#define NVM_CFG_H_

#include "NvM_Types.h"
#include "NvM_ConfigTypes.h"

#define NVM_DEV_ERROR_DETECT            STD_ON
#define NVM_VERSION_INFO_API            STD_ON
#define NVM_SET_RAM_BLOCK_STATUS_API    STD_OFF

#define NVM_API_CONFIG_CLASS            NVM_API_CONFIG_CLASS_2     // Class 1-3
#define NVM_COMPILED_CONFIG_ID          0                          // 0..65535
#define NVM_CRC_NUM_OF_BYTES            0                          // 1..65535
#define NVM_DATASET_SELECTION_BITS      0                          // 0..8
#define NVM_DRV_MODE_SWITCH             STD_OFF                    // OFF = SLOW, ON = FAST
#define NVM_DYNAMIC_CONFIGURATION       STD_OFF                    // OFF..ON
#define NVM_JOB_PRIORIZATION            STD_OFF                    // OFF..ON
#define NVM_MAX_NUMBER_OF_WRITE_RETRIES 2                          // 0..7
#define NVM_POLLING_MODE                STD_OFF                    // OFF..ON
#define NVM_SIZE_IMMEDIATE_JOB_QUEUE    8                          // 1..255
#define NVM_SIZE_STANDARD_JOB_QUEUE     8                          // 1..255

#define NVM_MAX_BLOCK_LENGTH 256

#define NVM_NUM_OF_NVRAM_BLOCKS 5

#define NVM_BLOCK_ID_Time 1
#define NVM_BLOCK_ID_Config 2
#define NVM_BLOCK_ID_FingerPrint 3
#define NVM_BLOCK_ID_EaTest1 4
#define NVM_BLOCK_ID_EaTest2 5

typedef struct{
	uint16 _Year;
	uint8 _Month;
	uint8 _Day;
	uint8 _Hour;
	uint8 _Minute;
	uint8 _Second;
}NvM_BlockTime_DataGroupType;


typedef struct{
	uint8 _Byte[32];
}NvM_BlockConfig_DataGroupType;


typedef struct{
	uint32 _Data[64];
}NvM_BlockFingerPrint_DataGroupType;


typedef struct{
	uint32 _Data0;
	uint32 _Data1;
	uint32 _Data2;
	uint32 _Data3;
}NvM_BlockEaTest1_DataGroupType;


typedef struct{
	uint32 _Data1;
	uint32 _Data2;
	uint32 _Data3;
	uint32 _Data4;
}NvM_BlockEaTest2_DataGroupType;


extern NvM_BlockTime_DataGroupType NvM_BlockTime_DataGroup_RAM;
extern const NvM_BlockTime_DataGroupType NvM_BlockTime_DataGroup_ROM;

extern NvM_BlockConfig_DataGroupType NvM_BlockConfig_DataGroup_RAM;
extern const NvM_BlockConfig_DataGroupType NvM_BlockConfig_DataGroup_ROM;

extern NvM_BlockFingerPrint_DataGroupType NvM_BlockFingerPrint_DataGroup_RAM;
extern const NvM_BlockFingerPrint_DataGroupType NvM_BlockFingerPrint_DataGroup_ROM;

extern NvM_BlockEaTest1_DataGroupType NvM_BlockEaTest1_DataGroup_RAM;
extern const NvM_BlockEaTest1_DataGroupType NvM_BlockEaTest1_DataGroup_ROM;

extern NvM_BlockEaTest2_DataGroupType NvM_BlockEaTest2_DataGroup_RAM;
extern const NvM_BlockEaTest2_DataGroupType NvM_BlockEaTest2_DataGroup_ROM;

#define Rte_NvMReadBuffer(GroupName)    ((uint8*)&NvM_Block##GroupName##_DataGroup_RAM)    
#define Rte_NvMRead(GroupName,DataName) (NvM_Block##GroupName##_DataGroup_RAM._##DataName)
#define Rte_NvMReadArrayBuffer(GroupName,DataName) ((uint8*)NvM_Block##GroupName##_DataGroup_RAM._##DataName)
#define Rte_NvMReadArray(GroupName,DataName,Index) (NvM_Block##GroupName##_DataGroup_RAM._##DataName[Index])

#define Rte_NvMReadBufferConst(GroupName)    ((uint8*)&NvM_Block##GroupName##_DataGroup_ROM) 
#define Rte_NvMReadConst(GroupName,DataName) (NvM_Block##GroupName##_DataGroup_ROM._##DataName)
#define Rte_NvMReadArrayBufferConst(GroupName,DataName) ((uint8*)NvM_Block##GroupName##_DataGroup_ROM._##DataName)
#define Rte_NvMReadArrayConst(GroupName,DataName,Index) (NvM_Block##GroupName##_DataGroup_ROM._##DataName[Index])

#define Rte_NvMWrite(GroupName,DataName,Value) (NvM_Block##GroupName##_DataGroup_RAM._##DataName = Value)
#define Rte_NvMWriteArray(GroupName,DataName,Index,Value) (NvM_Block##GroupName##_DataGroup_RAM._##DataName[Index] = Value)

#define Rte_NvmWriteBlock(GroupName) NvM_WriteBlock(NVM_BLOCK_ID_##GroupName,(uint8*)&NvM_Block##GroupName##_DataGroup_RAM)
#define Rte_NvmReadBlock(GroupName)  NvM_ReadBlock(NVM_BLOCK_ID_##GroupName,(uint8*)&NvM_Block##GroupName##_DataGroup_RAM)      



#endif /*NVM_CFG_H_*/

