/**
 ******************************************************************************
 * @file        test_Dcm_DIDHandlers.cpp
 * @brief       Google Test unit tests for Dcm_DIDHandlers.c
 *
 * @details     Tests all DID read/write callbacks declared in Dcm_DIDHandlers.h.
 *              All AUTOSAR platform dependencies (RTE, NvM, DCM, DET) are
 *              replaced by controllable stubs defined in this file.
 *
 *              Build (example):
 *                g++ -std=c++17 -I. \
 *                    test_Dcm_DIDHandlers.cpp Dcm_DIDHandlers.c \
 *                    -lgtest -lgtest_main -lpthread -o test_Dcm_DIDHandlers
 *
 * @note        Dcm_DIDHandlers.c includes platform headers via its own
 *              #include directives. Stub headers placed in the same directory
 *              (or on the include path) shadow the real AUTOSAR headers.
 ******************************************************************************
 */

/* ============================================================================
   STUB HEADERS — placed before any production includes so the compiler uses
   these definitions instead of the missing AUTOSAR platform files.
   =========================================================================== */

/* --------------------------------------------------------------------------
   Std_Types.h stub
   -------------------------------------------------------------------------- */
#ifndef STD_TYPES_H
#define STD_TYPES_H

#include <stdint.h>
#include <string.h>

typedef uint8_t  uint8;
typedef uint16_t uint16;
typedef uint32_t uint32;
typedef int8_t   sint8;
typedef int16_t  sint16;
typedef int32_t  sint32;
typedef uint8_t  boolean;

#define TRUE   ((boolean)1U)
#define FALSE  ((boolean)0U)

typedef uint8  Std_ReturnType;
#define E_OK        ((Std_ReturnType)0x00U)
#define E_NOT_OK    ((Std_ReturnType)0x01U)

#define NULL_PTR    ((void*)0)

#define STD_HIGH    (1U)
#define STD_LOW     (0U)

#endif /* STD_TYPES_H */

/* --------------------------------------------------------------------------
   Dcm_Types.h stub
   -------------------------------------------------------------------------- */
#ifndef DCM_TYPES_H
#define DCM_TYPES_H

typedef uint8 Dcm_SesCtrlType;
#define DCM_DEFAULT_SESSION     ((Dcm_SesCtrlType)0x01U)
#define DCM_PROGRAMMING_SESSION ((Dcm_SesCtrlType)0x02U)
#define DCM_EXTENDED_SESSION    ((Dcm_SesCtrlType)0x03U)

typedef uint8 Dcm_NegativeResponseCodeType;
#define DCM_E_REQUEST_OUT_OF_RANGE      ((Dcm_NegativeResponseCodeType)0x31U)
#define DCM_E_CONDITIONS_NOT_CORRECT    ((Dcm_NegativeResponseCodeType)0x22U)
#define DCM_E_SECURITY_ACCESS_DENIED    ((Dcm_NegativeResponseCodeType)0x33U)

#define DCM_MODULE_ID   (0x35U)
#define DCM_E_PARAM_POINTER (0x01U)

#endif /* DCM_TYPES_H */

/* --------------------------------------------------------------------------
   Rte_Dcm.h stub
   -------------------------------------------------------------------------- */
#ifndef RTE_DCM_H
#define RTE_DCM_H
/* Included only for type completeness — Dcm_GetSesCtrlType stubbed below */
#endif

/* --------------------------------------------------------------------------
   Rte_DcmDIDHandlers.h stub  (Rte_Read_* port calls)
   -------------------------------------------------------------------------- */
#ifndef RTE_DCMDIDHANDLERS_H
#define RTE_DCMDIDHANDLERS_H

/* Stub control block — test cases set these before calling the DUT */
struct RteStubs {
    Std_ReturnType engSpeed_ret;        uint16  engSpeed_val;
    Std_ReturnType coolantTemp_ret;     sint16  coolantTemp_val;
    Std_ReturnType intakeAirTemp_ret;   sint16  intakeAirTemp_val;
    Std_ReturnType throttlePos_ret;     uint8   throttlePos_val;
    Std_ReturnType map_ret;             uint16  map_val;
    Std_ReturnType battVoltage_ret;     uint16  battVoltage_val;
    Std_ReturnType vehicleSpeed_ret;    uint16  vehicleSpeed_val;
    Std_ReturnType accelPedal_ret;      uint8   accelPedal_val;
    Std_ReturnType injQty_ret;          uint16  injQty_val;
    Std_ReturnType ignTiming_ret;       sint16  ignTiming_val;
    Std_ReturnType lambda_ret;          uint16  lambda_val;
    Std_ReturnType injMode_ret;         uint8   injMode_val;
    Std_ReturnType gearPos_ret;         uint8   gearPos_val;
    Std_ReturnType torqueReq_ret;       uint16  torqueReq_val;
    Std_ReturnType torqueAct_ret;       uint16  torqueAct_val;
    Std_ReturnType engRunTime_ret;      uint16  engRunTime_val;
    Std_ReturnType ecuTemp_ret;         sint16  ecuTemp_val;
    Std_ReturnType supplyVoltage_ret;   uint16  supplyVoltage_val;
};

extern RteStubs g_rte;

inline Std_ReturnType Rte_Read_EngSpeed_val(uint16 *v)
    { *v = g_rte.engSpeed_val;      return g_rte.engSpeed_ret; }
inline Std_ReturnType Rte_Read_CoolantTemp_val(sint16 *v)
    { *v = g_rte.coolantTemp_val;   return g_rte.coolantTemp_ret; }
inline Std_ReturnType Rte_Read_IntakeAirTemp_val(sint16 *v)
    { *v = g_rte.intakeAirTemp_val; return g_rte.intakeAirTemp_ret; }
inline Std_ReturnType Rte_Read_ThrottlePos_val(uint8 *v)
    { *v = g_rte.throttlePos_val;   return g_rte.throttlePos_ret; }
inline Std_ReturnType Rte_Read_MAP_val(uint16 *v)
    { *v = g_rte.map_val;           return g_rte.map_ret; }
inline Std_ReturnType Rte_Read_BattVoltage_val(uint16 *v)
    { *v = g_rte.battVoltage_val;   return g_rte.battVoltage_ret; }
inline Std_ReturnType Rte_Read_VehicleSpeed_val(uint16 *v)
    { *v = g_rte.vehicleSpeed_val;  return g_rte.vehicleSpeed_ret; }
inline Std_ReturnType Rte_Read_AccelPedalPos_val(uint8 *v)
    { *v = g_rte.accelPedal_val;    return g_rte.accelPedal_ret; }
inline Std_ReturnType Rte_Read_InjectionQty_val(uint16 *v)
    { *v = g_rte.injQty_val;        return g_rte.injQty_ret; }
inline Std_ReturnType Rte_Read_IgnTimingAdv_val(sint16 *v)
    { *v = g_rte.ignTiming_val;     return g_rte.ignTiming_ret; }
inline Std_ReturnType Rte_Read_LambdaValue_val(uint16 *v)
    { *v = g_rte.lambda_val;        return g_rte.lambda_ret; }
inline Std_ReturnType Rte_Read_InjectionMode_val(uint8 *v)
    { *v = g_rte.injMode_val;       return g_rte.injMode_ret; }
inline Std_ReturnType Rte_Read_GearPosition_val(uint8 *v)
    { *v = g_rte.gearPos_val;       return g_rte.gearPos_ret; }
inline Std_ReturnType Rte_Read_TorqueReq_val(uint16 *v)
    { *v = g_rte.torqueReq_val;     return g_rte.torqueReq_ret; }
inline Std_ReturnType Rte_Read_TorqueActual_val(uint16 *v)
    { *v = g_rte.torqueAct_val;     return g_rte.torqueAct_ret; }
inline Std_ReturnType Rte_Read_EngRunTime_val(uint16 *v)
    { *v = g_rte.engRunTime_val;    return g_rte.engRunTime_ret; }
inline Std_ReturnType Rte_Read_EcuInternalTemp_val(sint16 *v)
    { *v = g_rte.ecuTemp_val;       return g_rte.ecuTemp_ret; }
inline Std_ReturnType Rte_Read_SupplyVoltagePin_val(uint16 *v)
    { *v = g_rte.supplyVoltage_val; return g_rte.supplyVoltage_ret; }

#endif /* RTE_DCMDIDHANDLERS_H */

/* --------------------------------------------------------------------------
   NvM.h stub
   -------------------------------------------------------------------------- */
#ifndef NVM_H
#define NVM_H

typedef uint16 NvM_BlockIdType;

extern Std_ReturnType g_nvmWriteBlock_ret;
extern NvM_BlockIdType g_nvmWriteBlock_lastBlockId;

inline Std_ReturnType NvM_WriteBlock(NvM_BlockIdType blockId, const void* /*buf*/)
{
    g_nvmWriteBlock_lastBlockId = blockId;
    return g_nvmWriteBlock_ret;
}

inline Std_ReturnType NvM_ReadBlock(NvM_BlockIdType /*blockId*/, void* /*buf*/)
{
    return E_OK;
}

#endif /* NVM_H */

/* --------------------------------------------------------------------------
   Dcm.h stub
   -------------------------------------------------------------------------- */
#ifndef DCM_H
#define DCM_H

extern Std_ReturnType  g_dcmGetSes_ret;
extern Dcm_SesCtrlType g_dcmGetSes_session;

inline Std_ReturnType Dcm_GetSesCtrlType(Dcm_SesCtrlType *sesType)
{
    *sesType = g_dcmGetSes_session;
    return g_dcmGetSes_ret;
}

#endif /* DCM_H */

/* --------------------------------------------------------------------------
   Det.h stub
   -------------------------------------------------------------------------- */
#ifndef DET_H
#define DET_H

extern uint32 g_det_callCount;

inline Std_ReturnType Det_ReportError(uint16 /*ModuleId*/, uint8 /*InstanceId*/,
                                      uint8 /*ApiId*/, uint8 /*ErrorId*/)
{
    g_det_callCount++;
    return E_OK;
}

#endif /* DET_H */

/* ============================================================================
   GTest includes and stub global definitions
   =========================================================================== */
#include <gtest/gtest.h>

/* Globals backing the stubs */
RteStubs        g_rte{};
Std_ReturnType  g_nvmWriteBlock_ret          = E_OK;
NvM_BlockIdType g_nvmWriteBlock_lastBlockId  = 0U;
Std_ReturnType  g_dcmGetSes_ret              = E_OK;
Dcm_SesCtrlType g_dcmGetSes_session          = DCM_DEFAULT_SESSION;
uint32          g_det_callCount              = 0U;

/* NvM block placeholder data referenced by the .c file as extern */
const uint8 NvM_VIN_Block[17]          = {0};
const uint8 NvM_EcuSerial_Block[10]    = {0};
const uint8 NvM_BootSwFp_Block[10]     = {0};
const uint8 NvM_AppSwFp_Block[10]      = {0};
const uint8 NvM_AppDataFp_Block[10]    = {0};
const uint8 NvM_MfgDate_Block[3]       = {0};
const uint8 NvM_ProgDate_Block[3]      = {0};
const uint8 NvM_ResetCounter_Block[2]  = {0};
const uint8 NvM_ResetCause_Block[1]    = {0};
const uint8 NvM_NvmWriteCounter_Block[4] = {0};

/* ============================================================================
   Now include the production header (which pulls in our stubs via the same
   names above) and let Dcm_DIDHandlers.c be compiled as a translation unit.
   =========================================================================== */
extern "C" {
#include "Dcm_DIDHandlers.h"

/* Forward-declare the Init function (declared in the .c file, not the .h) */
void Dcm_DIDHandlers_Init(void);
}

/* ============================================================================
   HELPER UTILITIES
   =========================================================================== */

/** Reset all stub state before each test */
static void ResetStubs()
{
    g_rte                       = RteStubs{};
    g_nvmWriteBlock_ret         = E_OK;
    g_nvmWriteBlock_lastBlockId = 0U;
    g_dcmGetSes_ret             = E_OK;
    g_dcmGetSes_session         = DCM_DEFAULT_SESSION;
    g_det_callCount             = 0U;
}

/** Read uint16 from big-endian byte buffer */
static uint16 ReadBE16(const uint8 *buf, uint8 offset = 0)
{
    return static_cast<uint16>((static_cast<uint16>(buf[offset]) << 8U) |
                                static_cast<uint16>(buf[offset + 1U]));
}

/* ============================================================================
   TEST FIXTURE
   =========================================================================== */

class DcmDIDHandlersTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        ResetStubs();
        Dcm_DIDHandlers_Init();   /* zero-fill all static RAM buffers */
    }
};

/* ============================================================================
   SECTION 1 — NULL POINTER GUARD TESTS
   Verify that every DID handler returns E_NOT_OK when passed a NULL buffer
   and that DET is notified exactly once.
   =========================================================================== */

TEST_F(DcmDIDHandlersTest, NullPointer_F186_ReturnsENotOk)
{
    EXPECT_EQ(E_NOT_OK, Dcm_ReadData_F186(nullptr));
    EXPECT_EQ(1U, g_det_callCount);
}

TEST_F(DcmDIDHandlersTest, NullPointer_F190_ReturnsENotOk)
{
    EXPECT_EQ(E_NOT_OK, Dcm_ReadData_F190(nullptr));
    EXPECT_EQ(1U, g_det_callCount);
}

TEST_F(DcmDIDHandlersTest, NullPointer_F180_ReturnsENotOk)
{
    EXPECT_EQ(E_NOT_OK, Dcm_ReadData_F180(nullptr));
}

TEST_F(DcmDIDHandlersTest, NullPointer_2001_ReturnsENotOk)
{
    EXPECT_EQ(E_NOT_OK, Dcm_ReadData_2001(nullptr));
}

TEST_F(DcmDIDHandlersTest, NullPointer_2002_ReturnsENotOk)
{
    EXPECT_EQ(E_NOT_OK, Dcm_ReadData_2002(nullptr));
}

TEST_F(DcmDIDHandlersTest, NullPointer_2004_ReturnsENotOk)
{
    EXPECT_EQ(E_NOT_OK, Dcm_ReadData_2004(nullptr));
}

TEST_F(DcmDIDHandlersTest, NullPointer_200A_ReturnsENotOk)
{
    EXPECT_EQ(E_NOT_OK, Dcm_ReadData_200A(nullptr));
}

TEST_F(DcmDIDHandlersTest, NullPointer_200E_ReturnsENotOk)
{
    EXPECT_EQ(E_NOT_OK, Dcm_ReadData_200E(nullptr));
}

TEST_F(DcmDIDHandlersTest, NullPointer_WriteF190_DataNull_ReturnsENotOk)
{
    Dcm_NegativeResponseCodeType nrc = 0U;
    EXPECT_EQ(E_NOT_OK, Dcm_WriteData_F190(nullptr, &nrc));
}

TEST_F(DcmDIDHandlersTest, NullPointer_WriteF190_ErrorCodeNull_ReturnsENotOk)
{
    uint8 vin[17] = {'1','2','3','4','5','6','7','8','9',
                     'A','B','C','D','E','F','G','H'};
    EXPECT_EQ(E_NOT_OK, Dcm_WriteData_F190(vin, nullptr));
}

/* ============================================================================
   SECTION 2 — DID 0xF186: Active Diagnostic Session
   =========================================================================== */

TEST_F(DcmDIDHandlersTest, F186_ReturnsCurrentSession_WhenGetSesOk)
{
    g_dcmGetSes_ret     = E_OK;
    g_dcmGetSes_session = DCM_EXTENDED_SESSION;

    uint8 data[1] = {0};
    EXPECT_EQ(E_OK, Dcm_ReadData_F186(data));
    EXPECT_EQ(DCM_EXTENDED_SESSION, data[0]);
}

TEST_F(DcmDIDHandlersTest, F186_ReturnsDefaultSession_WhenGetSesFails)
{
    g_dcmGetSes_ret     = E_NOT_OK;
    g_dcmGetSes_session = DCM_PROGRAMMING_SESSION;  /* should be ignored */

    uint8 data[1] = {0xAAU};
    EXPECT_EQ(E_NOT_OK, Dcm_ReadData_F186(data));
    EXPECT_EQ(DCM_DEFAULT_SESSION, data[0]);
}

/* ============================================================================
   SECTION 3 — DID 0xF190: VIN (Read)
   =========================================================================== */

TEST_F(DcmDIDHandlersTest, F190_Read_ReturnsSpaceFilledBuffer_AfterInit)
{
    /* Init zero-fills with 0x20 (ASCII space) */
    uint8 data[17] = {0};
    EXPECT_EQ(E_OK, Dcm_ReadData_F190(data));
    for (int i = 0; i < 17; i++)
    {
        EXPECT_EQ(0x20U, data[i]) << "byte " << i;
    }
}

TEST_F(DcmDIDHandlersTest, F190_Read_ReturnsPreviouslyWrittenVIN)
{
    /* Write a valid VIN first, then read it back */
    const uint8 vin[17] = {
        '1','G','1','A','F','1','F','5','7','A','7','1','9','2','3','4','5'
    };
    Dcm_NegativeResponseCodeType nrc = 0U;
    ASSERT_EQ(E_OK, Dcm_WriteData_F190(vin, &nrc));

    uint8 readBack[17] = {0};
    EXPECT_EQ(E_OK, Dcm_ReadData_F190(readBack));
    EXPECT_EQ(0, memcmp(vin, readBack, 17));
}

/* ============================================================================
   SECTION 4 — Const-Flash Identification DIDs
   All copy from compile-time constants — always return E_OK.
   =========================================================================== */

TEST_F(DcmDIDHandlersTest, F180_BootSwIdent_ReturnsEOkAndNonZeroData)
{
    uint8 data[16] = {0};
    EXPECT_EQ(E_OK, Dcm_ReadData_F180(data));
    /* First byte of "BOOT_EMS1_V1.00 " is 'B' = 0x42 */
    EXPECT_EQ(0x42U, data[0]);
}

TEST_F(DcmDIDHandlersTest, F181_AppSwIdent_ReturnsEOkAndCorrectFirstByte)
{
    uint8 data[16] = {0};
    EXPECT_EQ(E_OK, Dcm_ReadData_F181(data));
    /* "APPL_..." → 'A' = 0x41 */
    EXPECT_EQ(0x41U, data[0]);
}

TEST_F(DcmDIDHandlersTest, F189_EcuSwVersion_ReturnsMajor1Minor0)
{
    uint8 data[4] = {0};
    EXPECT_EQ(E_OK, Dcm_ReadData_F189(data));
    EXPECT_EQ(0x01U, data[0]);  /* Major */
    EXPECT_EQ(0x00U, data[1]);  /* Minor */
    EXPECT_EQ(0x00U, data[2]);  /* Patch */
    EXPECT_EQ(0x00U, data[3]);  /* Build */
}

TEST_F(DcmDIDHandlersTest, F18A_SupplierID_Returns3ByteCAGE)
{
    uint8 data[3] = {0};
    EXPECT_EQ(E_OK, Dcm_ReadData_F18A(data));
    EXPECT_EQ(0x53U, data[0]);  /* 'S' */
    EXPECT_EQ(0x55U, data[1]);  /* 'U' */
    EXPECT_EQ(0x50U, data[2]);  /* 'P' */
}

TEST_F(DcmDIDHandlersTest, F18E_FunctionalUnits_ReturnsCorrectBitmask)
{
    uint8 data[4] = {0};
    EXPECT_EQ(E_OK, Dcm_ReadData_F18E(data));
    EXPECT_EQ(0x00U, data[0]);
    EXPECT_EQ(0x00U, data[1]);
    EXPECT_EQ(0x03U, data[2]);
    EXPECT_EQ(0xFFU, data[3]);
}

TEST_F(DcmDIDHandlersTest, F197_SystemName_ReturnsEMS1)
{
    uint8 data[4] = {0};
    EXPECT_EQ(E_OK, Dcm_ReadData_F197(data));
    EXPECT_EQ('E', data[0]);
    EXPECT_EQ('M', data[1]);
    EXPECT_EQ('S', data[2]);
    EXPECT_EQ('1', data[3]);
}

TEST_F(DcmDIDHandlersTest, F193_SupplierHwVersion_Returns1_0)
{
    uint8 data[2] = {0};
    EXPECT_EQ(E_OK, Dcm_ReadData_F193(data));
    EXPECT_EQ(0x01U, data[0]);
    EXPECT_EQ(0x00U, data[1]);
}

/* ============================================================================
   SECTION 5 — DID 0x2001: Engine RPM (uint16 big-endian, 0.25 rpm/bit)
   =========================================================================== */

TEST_F(DcmDIDHandlersTest, DID2001_EngineRPM_EncodesCorrectly_WhenOk)
{
    /* Raw value 4000 → Physical = 4000 × 0.25 = 1000 rpm */
    g_rte.engSpeed_ret = E_OK;
    g_rte.engSpeed_val = 4000U;

    uint8 data[2] = {0};
    EXPECT_EQ(E_OK, Dcm_ReadData_2001(data));
    EXPECT_EQ(4000U, ReadBE16(data));
}

TEST_F(DcmDIDHandlersTest, DID2001_EngineRPM_WritesInvalidMarker_WhenRteFails)
{
    g_rte.engSpeed_ret = E_NOT_OK;

    uint8 data[2] = {0};
    EXPECT_EQ(E_NOT_OK, Dcm_ReadData_2001(data));
    EXPECT_EQ(0xFFFFU, ReadBE16(data));
}

TEST_F(DcmDIDHandlersTest, DID2001_EngineRPM_ZeroRpm_EncodesZero)
{
    g_rte.engSpeed_ret = E_OK;
    g_rte.engSpeed_val = 0U;

    uint8 data[2] = {0xAA, 0xAA};
    EXPECT_EQ(E_OK, Dcm_ReadData_2001(data));
    EXPECT_EQ(0U, ReadBE16(data));
}

TEST_F(DcmDIDHandlersTest, DID2001_EngineRPM_MaxRaw_EncodesFFFF)
{
    g_rte.engSpeed_ret = E_OK;
    g_rte.engSpeed_val = 0xFFFFU;

    uint8 data[2] = {0};
    EXPECT_EQ(E_OK, Dcm_ReadData_2001(data));
    EXPECT_EQ(0xFFFFU, ReadBE16(data));
}

/* ============================================================================
   SECTION 6 — DID 0x2002: Engine Coolant Temperature (Raw = Physical + 40)
   =========================================================================== */

TEST_F(DcmDIDHandlersTest, DID2002_CoolantTemp_NominalEncoding)
{
    /* 80°C → raw = 80 + 40 = 120 = 0x78 */
    g_rte.coolantTemp_ret = E_OK;
    g_rte.coolantTemp_val = 80;

    uint8 data[1] = {0};
    EXPECT_EQ(E_OK, Dcm_ReadData_2002(data));
    EXPECT_EQ(120U, data[0]);
}

TEST_F(DcmDIDHandlersTest, DID2002_CoolantTemp_MinusForty_EncodesZero)
{
    g_rte.coolantTemp_ret = E_OK;
    g_rte.coolantTemp_val = -40;

    uint8 data[1] = {0xAAU};
    EXPECT_EQ(E_OK, Dcm_ReadData_2002(data));
    EXPECT_EQ(0U, data[0]);
}

TEST_F(DcmDIDHandlersTest, DID2002_CoolantTemp_BelowMin_ClampsToZero)
{
    /* -50°C → raw = -10 → clamped to 0 */
    g_rte.coolantTemp_ret = E_OK;
    g_rte.coolantTemp_val = -50;

    uint8 data[1] = {0xAAU};
    EXPECT_EQ(E_OK, Dcm_ReadData_2002(data));
    EXPECT_EQ(0U, data[0]);
}

TEST_F(DcmDIDHandlersTest, DID2002_CoolantTemp_AboveMax_ClampsTo255)
{
    /* 220°C → raw = 260 → clamped to 255 */
    g_rte.coolantTemp_ret = E_OK;
    g_rte.coolantTemp_val = 220;

    uint8 data[1] = {0};
    EXPECT_EQ(E_OK, Dcm_ReadData_2002(data));
    EXPECT_EQ(255U, data[0]);
}

TEST_F(DcmDIDHandlersTest, DID2002_CoolantTemp_WritesFFMarker_WhenRteFails)
{
    g_rte.coolantTemp_ret = E_NOT_OK;

    uint8 data[1] = {0};
    EXPECT_EQ(E_NOT_OK, Dcm_ReadData_2002(data));
    EXPECT_EQ(0xFFU, data[0]);
}

/* ============================================================================
   SECTION 7 — DID 0x2003: Intake Air Temperature (same encoding as 0x2002)
   =========================================================================== */

TEST_F(DcmDIDHandlersTest, DID2003_IntakeAirTemp_NominalEncoding)
{
    g_rte.intakeAirTemp_ret = E_OK;
    g_rte.intakeAirTemp_val = 25;  /* 25°C → raw = 65 = 0x41 */

    uint8 data[1] = {0};
    EXPECT_EQ(E_OK, Dcm_ReadData_2003(data));
    EXPECT_EQ(65U, data[0]);
}

TEST_F(DcmDIDHandlersTest, DID2003_IntakeAirTemp_WritesFFMarker_WhenRteFails)
{
    g_rte.intakeAirTemp_ret = E_NOT_OK;

    uint8 data[1] = {0};
    EXPECT_EQ(E_NOT_OK, Dcm_ReadData_2003(data));
    EXPECT_EQ(0xFFU, data[0]);
}

/* ============================================================================
   SECTION 8 — DID 0x2004: Throttle Position (Raw = Physical × 2.5 = ×5/2)
   =========================================================================== */

TEST_F(DcmDIDHandlersTest, DID2004_ThrottlePos_FullThrottle_EncodesFA)
{
    /* 100% → raw = 100×5/2 = 250 = 0xFA */
    g_rte.throttlePos_ret = E_OK;
    g_rte.throttlePos_val = 100U;

    uint8 data[1] = {0};
    EXPECT_EQ(E_OK, Dcm_ReadData_2004(data));
    EXPECT_EQ(250U, data[0]);
}

TEST_F(DcmDIDHandlersTest, DID2004_ThrottlePos_ZeroThrottle_EncodesZero)
{
    g_rte.throttlePos_ret = E_OK;
    g_rte.throttlePos_val = 0U;

    uint8 data[1] = {0xAAU};
    EXPECT_EQ(E_OK, Dcm_ReadData_2004(data));
    EXPECT_EQ(0U, data[0]);
}

TEST_F(DcmDIDHandlersTest, DID2004_ThrottlePos_WritesFFMarker_WhenRteFails)
{
    g_rte.throttlePos_ret = E_NOT_OK;

    uint8 data[1] = {0};
    EXPECT_EQ(E_NOT_OK, Dcm_ReadData_2004(data));
    EXPECT_EQ(0xFFU, data[0]);
}

/* ============================================================================
   SECTION 9 — DID 0x2006: Battery Voltage (Raw = mV / 100, i.e. V × 10)
   =========================================================================== */

TEST_F(DcmDIDHandlersTest, DID2006_BattVoltage_12V_EncodesCorrectly)
{
    /* 12V = 12000mV → raw = 12000/100 = 120 = 0x78 */
    g_rte.battVoltage_ret = E_OK;
    g_rte.battVoltage_val = 12000U;

    uint8 data[1] = {0};
    EXPECT_EQ(E_OK, Dcm_ReadData_2006(data));
    EXPECT_EQ(120U, data[0]);
}

TEST_F(DcmDIDHandlersTest, DID2006_BattVoltage_Overflow_ClampsToFF)
{
    /* 30V = 30000mV → raw = 300 → clamped to 0xFF */
    g_rte.battVoltage_ret = E_OK;
    g_rte.battVoltage_val = 30000U;

    uint8 data[1] = {0};
    EXPECT_EQ(E_OK, Dcm_ReadData_2006(data));
    EXPECT_EQ(0xFFU, data[0]);
}

/* ============================================================================
   SECTION 10 — DID 0x2007: Vehicle Speed (uint16 BE, 0.01 km/h per bit)
   =========================================================================== */

TEST_F(DcmDIDHandlersTest, DID2007_VehicleSpeed_100kmh_EncodesCorrectly)
{
    /* Physical = 100 km/h → raw = 10000 (0x2710) */
    g_rte.vehicleSpeed_ret = E_OK;
    g_rte.vehicleSpeed_val = 10000U;

    uint8 data[2] = {0};
    EXPECT_EQ(E_OK, Dcm_ReadData_2007(data));
    EXPECT_EQ(10000U, ReadBE16(data));
    EXPECT_EQ(0x27U, data[0]);
    EXPECT_EQ(0x10U, data[1]);
}

TEST_F(DcmDIDHandlersTest, DID2007_VehicleSpeed_WritesFFFFMarker_WhenRteFails)
{
    g_rte.vehicleSpeed_ret = E_NOT_OK;

    uint8 data[2] = {0};
    EXPECT_EQ(E_NOT_OK, Dcm_ReadData_2007(data));
    EXPECT_EQ(0xFFFFU, ReadBE16(data));
}

/* ============================================================================
   SECTION 11 — DID 0x200A: Ignition Timing Advance
   Raw = ignTimingDeg_x10 + 1000 (100° offset × 10)
   =========================================================================== */

TEST_F(DcmDIDHandlersTest, DID200A_IgnTiming_ZeroDeg_EncodesOffset1000)
{
    /* 0° BTDC → ignTimingDeg_x10 = 0 → raw = 1000 = 0x03E8 */
    g_rte.ignTiming_ret = E_OK;
    g_rte.ignTiming_val = 0;

    uint8 data[2] = {0};
    EXPECT_EQ(E_OK, Dcm_ReadData_200A(data));
    EXPECT_EQ(1000U, ReadBE16(data));
    EXPECT_EQ(0x03U, data[0]);
    EXPECT_EQ(0xE8U, data[1]);
}

TEST_F(DcmDIDHandlersTest, DID200A_IgnTiming_Plus35Deg_EncodesCorrectly)
{
    /* 35° BTDC → ignTimingDeg_x10 = 350 → raw = 350 + 1000 = 1350 = 0x0546 */
    g_rte.ignTiming_ret = E_OK;
    g_rte.ignTiming_val = 350;

    uint8 data[2] = {0};
    EXPECT_EQ(E_OK, Dcm_ReadData_200A(data));
    EXPECT_EQ(1350U, ReadBE16(data));
}

TEST_F(DcmDIDHandlersTest, DID200A_IgnTiming_Minus100Deg_ClampsToZero)
{
    /* -100° → ignTimingDeg_x10 = -1000 → raw = 0 (clamped from negative) */
    g_rte.ignTiming_ret = E_OK;
    g_rte.ignTiming_val = -1000;

    uint8 data[2] = {0xAAU, 0xAAU};
    EXPECT_EQ(E_OK, Dcm_ReadData_200A(data));
    EXPECT_EQ(0U, ReadBE16(data));
}

TEST_F(DcmDIDHandlersTest, DID200A_IgnTiming_WritesFFFFMarker_WhenRteFails)
{
    g_rte.ignTiming_ret = E_NOT_OK;

    uint8 data[2] = {0};
    EXPECT_EQ(E_NOT_OK, Dcm_ReadData_200A(data));
    EXPECT_EQ(0xFFFFU, ReadBE16(data));
}

/* ============================================================================
   SECTION 12 — DID 0x200C: Injection Mode (enum, 1 byte)
   =========================================================================== */

TEST_F(DcmDIDHandlersTest, DID200C_InjectionMode_Normal_EncodesZero)
{
    g_rte.injMode_ret = E_OK;
    g_rte.injMode_val = DCM_INJECTION_MODE_NORMAL;

    uint8 data[1] = {0xAAU};
    EXPECT_EQ(E_OK, Dcm_ReadData_200C(data));
    EXPECT_EQ(DCM_INJECTION_MODE_NORMAL, data[0]);
}

TEST_F(DcmDIDHandlersTest, DID200C_InjectionMode_WritesFFMarker_WhenRteFails)
{
    g_rte.injMode_ret = E_NOT_OK;

    uint8 data[1] = {0};
    EXPECT_EQ(E_NOT_OK, Dcm_ReadData_200C(data));
    EXPECT_EQ(DCM_INJECTION_MODE_INVALID, data[0]);
}

/* ============================================================================
   SECTION 13 — DID 0x200D: Gear Position (enum, 1 byte)
   =========================================================================== */

TEST_F(DcmDIDHandlersTest, DID200D_GearPosition_Gear3_EncodesProperly)
{
    g_rte.gearPos_ret = E_OK;
    g_rte.gearPos_val = 3U;

    uint8 data[1] = {0xAAU};
    EXPECT_EQ(E_OK, Dcm_ReadData_200D(data));
    EXPECT_EQ(3U, data[0]);
}

TEST_F(DcmDIDHandlersTest, DID200D_GearPosition_WritesFFMarker_WhenRteFails)
{
    g_rte.gearPos_ret = E_NOT_OK;

    uint8 data[1] = {0};
    EXPECT_EQ(E_NOT_OK, Dcm_ReadData_200D(data));
    EXPECT_EQ(DCM_GEAR_INVALID, data[0]);
}

/* ============================================================================
   SECTION 14 — DID 0x200E: Torque Request vs Actual (4 bytes, dual RTE read)
   =========================================================================== */

TEST_F(DcmDIDHandlersTest, DID200E_Torque_BothOk_Encodes4BytesCorrectly)
{
    /* torqueReq = 3000 (=300Nm), torqueAct = 2800 (=280Nm) */
    g_rte.torqueReq_ret = E_OK;  g_rte.torqueReq_val = 3000U;
    g_rte.torqueAct_ret = E_OK;  g_rte.torqueAct_val = 2800U;

    uint8 data[4] = {0};
    EXPECT_EQ(E_OK, Dcm_ReadData_200E(data));
    EXPECT_EQ(3000U, ReadBE16(data, 0));
    EXPECT_EQ(2800U, ReadBE16(data, 2));
}

TEST_F(DcmDIDHandlersTest, DID200E_Torque_ReqFails_WritesFFFF_ReturnsENotOk)
{
    g_rte.torqueReq_ret = E_NOT_OK; g_rte.torqueReq_val = 999U;
    g_rte.torqueAct_ret = E_OK;     g_rte.torqueAct_val = 2800U;

    uint8 data[4] = {0};
    EXPECT_EQ(E_NOT_OK, Dcm_ReadData_200E(data));
    EXPECT_EQ(0xFFFFU, ReadBE16(data, 0));   /* req → 0xFFFF */
    EXPECT_EQ(2800U,   ReadBE16(data, 2));   /* act → valid  */
}

TEST_F(DcmDIDHandlersTest, DID200E_Torque_BothFail_WritesFFFF_ReturnsENotOk)
{
    g_rte.torqueReq_ret = E_NOT_OK;
    g_rte.torqueAct_ret = E_NOT_OK;

    uint8 data[4] = {0};
    EXPECT_EQ(E_NOT_OK, Dcm_ReadData_200E(data));
    EXPECT_EQ(0xFFFFU, ReadBE16(data, 0));
    EXPECT_EQ(0xFFFFU, ReadBE16(data, 2));
}

/* ============================================================================
   SECTION 15 — DID 0xD001: ECU Internal Temperature (sint16, MSB first)
   =========================================================================== */

TEST_F(DcmDIDHandlersTest, DID_D001_EcuTemp_Positive_EncodesTwosComplement)
{
    /* 85.50°C → raw = 8550 = 0x2166 */
    g_rte.ecuTemp_ret = E_OK;
    g_rte.ecuTemp_val = 8550;

    uint8 data[2] = {0};
    EXPECT_EQ(E_OK, Dcm_ReadData_D001(data));
    EXPECT_EQ(0x21U, data[0]);
    EXPECT_EQ(0x66U, data[1]);
}

TEST_F(DcmDIDHandlersTest, DID_D001_EcuTemp_Negative_EncodesTwosComplement)
{
    /* -10.00°C → raw = -1000 = 0xFC18 in two's complement */
    g_rte.ecuTemp_ret = E_OK;
    g_rte.ecuTemp_val = -1000;

    uint8 data[2] = {0};
    EXPECT_EQ(E_OK, Dcm_ReadData_D001(data));
    uint16 raw = ReadBE16(data);
    EXPECT_EQ(static_cast<uint16>(-1000), raw);
}

TEST_F(DcmDIDHandlersTest, DID_D001_EcuTemp_WritesInvalidMarker_WhenRteFails)
{
    g_rte.ecuTemp_ret = E_NOT_OK;

    uint8 data[2] = {0};
    EXPECT_EQ(E_NOT_OK, Dcm_ReadData_D001(data));
    EXPECT_EQ(0x8000U, ReadBE16(data));  /* sint16 min = invalid marker */
}

/* ============================================================================
   SECTION 16 — DID 0xD003: Reset Counter (NvM buffer read-back)
   =========================================================================== */

TEST_F(DcmDIDHandlersTest, DID_D003_ResetCounter_ZeroAfterInit)
{
    /* Init fills buffer with 0x00 */
    uint8 data[2] = {0xAAU, 0xAAU};
    EXPECT_EQ(E_OK, Dcm_ReadData_D003(data));
    EXPECT_EQ(0x00U, data[0]);
    EXPECT_EQ(0x00U, data[1]);
}

/* ============================================================================
   SECTION 17 — DID 0xD004: Last Reset Cause (NvM buffer, 1 byte)
   =========================================================================== */

TEST_F(DcmDIDHandlersTest, DID_D004_ResetCause_UnknownAfterInit)
{
    /* Init fills with DCM_RESET_CAUSE_UNKNOWN = 0xFF */
    uint8 data[1] = {0};
    EXPECT_EQ(E_OK, Dcm_ReadData_D004(data));
    EXPECT_EQ(DCM_RESET_CAUSE_UNKNOWN, data[0]);
}

/* ============================================================================
   SECTION 18 — DID 0xD005: NvM Write Counter (4 bytes, NvM buffer read-back)
   =========================================================================== */

TEST_F(DcmDIDHandlersTest, DID_D005_NvmWriteCounter_ZeroAfterInit)
{
    uint8 data[4] = {0xAAU, 0xAAU, 0xAAU, 0xAAU};
    EXPECT_EQ(E_OK, Dcm_ReadData_D005(data));
    EXPECT_EQ(0x00U, data[0]);
    EXPECT_EQ(0x00U, data[1]);
    EXPECT_EQ(0x00U, data[2]);
    EXPECT_EQ(0x00U, data[3]);
}

/* ============================================================================
   SECTION 19 — DID 0xF190 Write: VIN validation and NvM persistence
   =========================================================================== */

/** Build a 17-byte all-digit VIN */
static void MakeValidVIN(uint8 vin[17])
{
    const char *v = "1G1AF1F57A7192345";
    for (int i = 0; i < 17; i++) vin[i] = static_cast<uint8>(v[i]);
}

TEST_F(DcmDIDHandlersTest, WriteF190_ValidVIN_ReturnsEOkAndCallsNvM)
{
    uint8 vin[17];  MakeValidVIN(vin);
    Dcm_NegativeResponseCodeType nrc = 0U;

    EXPECT_EQ(E_OK, Dcm_WriteData_F190(vin, &nrc));
    EXPECT_EQ(2U, g_nvmWriteBlock_lastBlockId);  /* DCM_NVM_BLOCK_VIN = 2 */
}

TEST_F(DcmDIDHandlersTest, WriteF190_VIN_WithLetterI_ReturnsRequestOutOfRange)
{
    /* 'I' is forbidden per ISO 3779 */
    uint8 vin[17];  MakeValidVIN(vin);
    vin[3] = 'I';
    Dcm_NegativeResponseCodeType nrc = 0U;

    EXPECT_EQ(E_NOT_OK, Dcm_WriteData_F190(vin, &nrc));
    EXPECT_EQ(DCM_E_REQUEST_OUT_OF_RANGE, nrc);
}

TEST_F(DcmDIDHandlersTest, WriteF190_VIN_WithLetterO_ReturnsRequestOutOfRange)
{
    uint8 vin[17];  MakeValidVIN(vin);
    vin[5] = 'O';
    Dcm_NegativeResponseCodeType nrc = 0U;

    EXPECT_EQ(E_NOT_OK, Dcm_WriteData_F190(vin, &nrc));
    EXPECT_EQ(DCM_E_REQUEST_OUT_OF_RANGE, nrc);
}

TEST_F(DcmDIDHandlersTest, WriteF190_VIN_WithLetterQ_ReturnsRequestOutOfRange)
{
    uint8 vin[17];  MakeValidVIN(vin);
    vin[10] = 'Q';
    Dcm_NegativeResponseCodeType nrc = 0U;

    EXPECT_EQ(E_NOT_OK, Dcm_WriteData_F190(vin, &nrc));
    EXPECT_EQ(DCM_E_REQUEST_OUT_OF_RANGE, nrc);
}

TEST_F(DcmDIDHandlersTest, WriteF190_VIN_WithLowercaseChar_ReturnsRequestOutOfRange)
{
    uint8 vin[17];  MakeValidVIN(vin);
    vin[2] = 'a';   /* lowercase not in allowed set */
    Dcm_NegativeResponseCodeType nrc = 0U;

    EXPECT_EQ(E_NOT_OK, Dcm_WriteData_F190(vin, &nrc));
    EXPECT_EQ(DCM_E_REQUEST_OUT_OF_RANGE, nrc);
}

TEST_F(DcmDIDHandlersTest, WriteF190_VIN_NvMWriteFails_ReturnsConditionsNotCorrect)
{
    g_nvmWriteBlock_ret = E_NOT_OK;

    uint8 vin[17];  MakeValidVIN(vin);
    Dcm_NegativeResponseCodeType nrc = 0U;

    EXPECT_EQ(E_NOT_OK, Dcm_WriteData_F190(vin, &nrc));
    EXPECT_EQ(DCM_E_CONDITIONS_NOT_CORRECT, nrc);
}

TEST_F(DcmDIDHandlersTest, WriteF190_ValidVIN_IsReadableAfterWrite)
{
    uint8 vin[17];  MakeValidVIN(vin);
    Dcm_NegativeResponseCodeType nrc = 0U;
    ASSERT_EQ(E_OK, Dcm_WriteData_F190(vin, &nrc));

    uint8 readBack[17] = {0};
    ASSERT_EQ(E_OK, Dcm_ReadData_F190(readBack));
    EXPECT_EQ(0, memcmp(vin, readBack, 17));
}

/* ============================================================================
   SECTION 20 — Dcm_DIDHandlers_Init
   =========================================================================== */

TEST_F(DcmDIDHandlersTest, Init_SetsVinBufferToSpaces)
{
    Dcm_DIDHandlers_Init();

    uint8 data[17] = {0};
    ASSERT_EQ(E_OK, Dcm_ReadData_F190(data));
    for (int i = 0; i < 17; i++)
    {
        EXPECT_EQ(0x20U, data[i]) << "VIN byte " << i << " should be 0x20 (space)";
    }
}

TEST_F(DcmDIDHandlersTest, Init_SetsResetCauseToUnknown)
{
    Dcm_DIDHandlers_Init();

    uint8 data[1] = {0};
    ASSERT_EQ(E_OK, Dcm_ReadData_D004(data));
    EXPECT_EQ(DCM_RESET_CAUSE_UNKNOWN, data[0]);
}

TEST_F(DcmDIDHandlersTest, Init_ZeroesNvmWriteCounter)
{
    Dcm_DIDHandlers_Init();

    uint8 data[4] = {0xFFU, 0xFFU, 0xFFU, 0xFFU};
    ASSERT_EQ(E_OK, Dcm_ReadData_D005(data));
    EXPECT_EQ(0x00U, data[0]);
    EXPECT_EQ(0x00U, data[1]);
    EXPECT_EQ(0x00U, data[2]);
    EXPECT_EQ(0x00U, data[3]);
}
