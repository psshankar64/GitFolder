/**
 ******************************************************************************
 * @file        Dcm_DIDHandlers.h
 * @brief       DCM ReadDataByIdentifier / WriteDataByIdentifier Callback
 *              Interface — Powertrain / EMS ECU
 *
 * @details     This file declares all DID read/write callback functions
 *              registered in the DCM configuration (DaVinci Configurator Pro)
 *              under DcmDspDid → DcmDspDidData → DcmDspDidDataReadFnc /
 *              DcmDspDidDataWriteFnc containers.
 *
 *              Naming convention (Vector MICROSAR DCM):
 *                Read  : Dcm_ReadData_<DID_hex>(Data)
 *                Write : Dcm_WriteData_<DID_hex>(Data, ErrorCode)
 *
 *              All functions follow AUTOSAR DCM SWS interface signatures.
 *              Actual signal sourcing is done via Rte_Read / Rte_Write or
 *              direct NvM block access where applicable.
 *
 * @version     1.0.0
 * @date        2026-05-03
 *
 * @note        MISRA C:2012 compliant intent.
 *              All parameters are per AUTOSAR DCM SWS R4.3.
 ******************************************************************************
 */

#ifndef DCM_DID_HANDLERS_H
#define DCM_DID_HANDLERS_H

/*============================================================================
  INCLUDES
============================================================================*/
#include "Std_Types.h"          /* AUTOSAR standard types                    */
#include "Dcm_Types.h"          /* DCM-specific types (Dcm_NegativeResponseCodeType) */
#include "Rte_Dcm.h"            /* RTE-generated port interfaces for DCM SWC */

/*============================================================================
  MACRO DEFINITIONS
============================================================================*/

/** @brief DID identifiers — must match DcmDspDidIdentifier in ARXML config  */
#define DCM_DID_F186_ACTIVE_SESSION         (0xF186U)
#define DCM_DID_F190_VIN                    (0xF190U)
#define DCM_DID_F18C_ECU_SERIAL_NUMBER      (0xF18CU)
#define DCM_DID_F180_BOOT_SW_ID             (0xF180U)
#define DCM_DID_F181_APP_SW_ID              (0xF181U)
#define DCM_DID_F182_APP_DATA_ID            (0xF182U)
#define DCM_DID_F183_BOOT_SW_FP             (0xF183U)
#define DCM_DID_F184_APP_SW_FP              (0xF184U)
#define DCM_DID_F185_APP_DATA_FP            (0xF185U)
#define DCM_DID_F187_SPARE_PART_NUMBER      (0xF187U)
#define DCM_DID_F188_ECU_SW_NUMBER          (0xF188U)
#define DCM_DID_F189_ECU_SW_VERSION         (0xF189U)
#define DCM_DID_F18A_SUPPLIER_ID            (0xF18AU)
#define DCM_DID_F18B_MFG_DATE               (0xF18BU)
#define DCM_DID_F18E_FUNCTIONAL_UNITS       (0xF18EU)
#define DCM_DID_F191_ECU_HW_NUMBER          (0xF191U)
#define DCM_DID_F192_SUPPLIER_HW_NUMBER     (0xF192U)
#define DCM_DID_F193_SUPPLIER_HW_VERSION    (0xF193U)
#define DCM_DID_F194_SUPPLIER_SW_NUMBER     (0xF194U)
#define DCM_DID_F195_SUPPLIER_SW_VERSION    (0xF195U)
#define DCM_DID_F197_SYSTEM_NAME            (0xF197U)
#define DCM_DID_F1A0_CAL_DATASET_VERSION    (0xF1A0U)
#define DCM_DID_F1A2_PROG_DATE              (0xF1A2U)

/* Powertrain live data DIDs */
#define DCM_DID_2001_ENGINE_RPM             (0x2001U)
#define DCM_DID_2002_COOLANT_TEMP           (0x2002U)
#define DCM_DID_2003_INTAKE_AIR_TEMP        (0x2003U)
#define DCM_DID_2004_THROTTLE_POS           (0x2004U)
#define DCM_DID_2005_MAP                    (0x2005U)
#define DCM_DID_2006_BATTERY_VOLTAGE        (0x2006U)
#define DCM_DID_2007_VEHICLE_SPEED          (0x2007U)
#define DCM_DID_2008_ACCEL_PEDAL_POS        (0x2008U)
#define DCM_DID_2009_INJECTION_QTY          (0x2009U)
#define DCM_DID_200A_IGN_TIMING_ADV         (0x200AU)
#define DCM_DID_200B_LAMBDA_VALUE           (0x200BU)
#define DCM_DID_200C_INJECTION_MODE         (0x200CU)
#define DCM_DID_200D_GEAR_POSITION          (0x200DU)
#define DCM_DID_200E_TORQUE_REQ_ACT         (0x200EU)
#define DCM_DID_200F_ENGINE_RUN_TIME        (0x200FU)

/* ECU health DIDs */
#define DCM_DID_D001_ECU_INTERNAL_TEMP      (0xD001U)
#define DCM_DID_D002_SUPPLY_VOLTAGE_PIN     (0xD002U)
#define DCM_DID_D003_RESET_COUNTER          (0xD003U)
#define DCM_DID_D004_LAST_RESET_CAUSE       (0xD004U)
#define DCM_DID_D005_NVM_WRITE_COUNTER      (0xD005U)

/** @brief DID data lengths in bytes — must match DcmDspDidDataByteSize       */
#define DCM_DID_LEN_F186    (1U)
#define DCM_DID_LEN_F190    (17U)
#define DCM_DID_LEN_F18C    (10U)
#define DCM_DID_LEN_F180    (16U)
#define DCM_DID_LEN_F181    (16U)
#define DCM_DID_LEN_F182    (16U)
#define DCM_DID_LEN_F183    (10U)
#define DCM_DID_LEN_F184    (10U)
#define DCM_DID_LEN_F185    (10U)
#define DCM_DID_LEN_F187    (13U)
#define DCM_DID_LEN_F188    (11U)
#define DCM_DID_LEN_F189    (4U)
#define DCM_DID_LEN_F18A    (3U)
#define DCM_DID_LEN_F18B    (3U)
#define DCM_DID_LEN_F18E    (4U)
#define DCM_DID_LEN_F191    (11U)
#define DCM_DID_LEN_F192    (11U)
#define DCM_DID_LEN_F193    (2U)
#define DCM_DID_LEN_F194    (11U)
#define DCM_DID_LEN_F195    (4U)
#define DCM_DID_LEN_F197    (4U)
#define DCM_DID_LEN_F1A0    (4U)
#define DCM_DID_LEN_F1A2    (3U)
#define DCM_DID_LEN_2001    (2U)
#define DCM_DID_LEN_2002    (1U)
#define DCM_DID_LEN_2003    (1U)
#define DCM_DID_LEN_2004    (1U)
#define DCM_DID_LEN_2005    (2U)
#define DCM_DID_LEN_2006    (1U)
#define DCM_DID_LEN_2007    (2U)
#define DCM_DID_LEN_2008    (1U)
#define DCM_DID_LEN_2009    (2U)
#define DCM_DID_LEN_200A    (2U)
#define DCM_DID_LEN_200B    (2U)
#define DCM_DID_LEN_200C    (1U)
#define DCM_DID_LEN_200D    (1U)
#define DCM_DID_LEN_200E    (4U)
#define DCM_DID_LEN_200F    (2U)
#define DCM_DID_LEN_D001    (2U)
#define DCM_DID_LEN_D002    (2U)
#define DCM_DID_LEN_D003    (2U)
#define DCM_DID_LEN_D004    (1U)
#define DCM_DID_LEN_D005    (4U)

/** @brief Injection mode enumeration — matches DID 0x200C encoding          */
#define DCM_INJECTION_MODE_NORMAL           (0x00U)
#define DCM_INJECTION_MODE_FUEL_CUT         (0x01U)
#define DCM_INJECTION_MODE_LIMP             (0x02U)
#define DCM_INJECTION_MODE_CRANKING         (0x03U)
#define DCM_INJECTION_MODE_INVALID          (0xFFU)

/** @brief Reset cause enumeration — DID 0xD004                              */
#define DCM_RESET_CAUSE_POWER_ON            (0x01U)
#define DCM_RESET_CAUSE_WATCHDOG            (0x02U)
#define DCM_RESET_CAUSE_SW_RESET            (0x03U)
#define DCM_RESET_CAUSE_EXTERNAL            (0x04U)
#define DCM_RESET_CAUSE_LVD                 (0x05U)
#define DCM_RESET_CAUSE_UNKNOWN             (0xFFU)

/** @brief Gear position encoding — DID 0x200D                               */
#define DCM_GEAR_NEUTRAL                    (0x00U)
#define DCM_GEAR_REVERSE                    (0x09U)
#define DCM_GEAR_INVALID                    (0xFFU)

/*============================================================================
  TYPE DEFINITIONS
============================================================================*/

/**
 * @brief   Return type for asynchronous DID read callbacks.
 *          Maps to Dcm_ReturnReadMemoryType / Std_ReturnType in MICROSAR.
 */
typedef uint8 Dcm_ReadDataResultType;
#define DCM_READ_OK             (0x00U)   /**< Data read successfully         */
#define DCM_READ_PENDING        (0x10U)   /**< Operation pending (async only) */
#define DCM_READ_FAILED         (0x01U)   /**< Read failed — NRC will be set  */

/**
 * @brief   Return type for write DID callbacks.
 */
typedef uint8 Dcm_WriteDataResultType;
#define DCM_WRITE_OK            (0x00U)
#define DCM_WRITE_PENDING       (0x10U)
#define DCM_WRITE_FAILED        (0x01U)

/*============================================================================
  FUNCTION DECLARATIONS — IDENTIFICATION DIDs (0xFxxx) READ
============================================================================*/

extern Std_ReturnType Dcm_ReadData_F186(uint8 *Data);
extern Std_ReturnType Dcm_ReadData_F190(uint8 *Data);
extern Std_ReturnType Dcm_ReadData_F18C(uint8 *Data);
extern Std_ReturnType Dcm_ReadData_F180(uint8 *Data);
extern Std_ReturnType Dcm_ReadData_F181(uint8 *Data);
extern Std_ReturnType Dcm_ReadData_F182(uint8 *Data);
extern Std_ReturnType Dcm_ReadData_F183(uint8 *Data);
extern Std_ReturnType Dcm_ReadData_F184(uint8 *Data);
extern Std_ReturnType Dcm_ReadData_F185(uint8 *Data);
extern Std_ReturnType Dcm_ReadData_F187(uint8 *Data);
extern Std_ReturnType Dcm_ReadData_F188(uint8 *Data);
extern Std_ReturnType Dcm_ReadData_F189(uint8 *Data);
extern Std_ReturnType Dcm_ReadData_F18A(uint8 *Data);
extern Std_ReturnType Dcm_ReadData_F18B(uint8 *Data);
extern Std_ReturnType Dcm_ReadData_F18E(uint8 *Data);
extern Std_ReturnType Dcm_ReadData_F191(uint8 *Data);
extern Std_ReturnType Dcm_ReadData_F192(uint8 *Data);
extern Std_ReturnType Dcm_ReadData_F193(uint8 *Data);
extern Std_ReturnType Dcm_ReadData_F194(uint8 *Data);
extern Std_ReturnType Dcm_ReadData_F195(uint8 *Data);
extern Std_ReturnType Dcm_ReadData_F197(uint8 *Data);
extern Std_ReturnType Dcm_ReadData_F1A0(uint8 *Data);
extern Std_ReturnType Dcm_ReadData_F1A2(uint8 *Data);

/*============================================================================
  FUNCTION DECLARATIONS — POWERTRAIN LIVE DATA DIDs READ
============================================================================*/

extern Std_ReturnType Dcm_ReadData_2001(uint8 *Data);
extern Std_ReturnType Dcm_ReadData_2002(uint8 *Data);
extern Std_ReturnType Dcm_ReadData_2003(uint8 *Data);
extern Std_ReturnType Dcm_ReadData_2004(uint8 *Data);
extern Std_ReturnType Dcm_ReadData_2005(uint8 *Data);
extern Std_ReturnType Dcm_ReadData_2006(uint8 *Data);
extern Std_ReturnType Dcm_ReadData_2007(uint8 *Data);
extern Std_ReturnType Dcm_ReadData_2008(uint8 *Data);
extern Std_ReturnType Dcm_ReadData_2009(uint8 *Data);
extern Std_ReturnType Dcm_ReadData_200A(uint8 *Data);
extern Std_ReturnType Dcm_ReadData_200B(uint8 *Data);
extern Std_ReturnType Dcm_ReadData_200C(uint8 *Data);
extern Std_ReturnType Dcm_ReadData_200D(uint8 *Data);
extern Std_ReturnType Dcm_ReadData_200E(uint8 *Data);
extern Std_ReturnType Dcm_ReadData_200F(uint8 *Data);

/*============================================================================
  FUNCTION DECLARATIONS — ECU HEALTH DIDs READ
============================================================================*/

extern Std_ReturnType Dcm_ReadData_D001(uint8 *Data);
extern Std_ReturnType Dcm_ReadData_D002(uint8 *Data);
extern Std_ReturnType Dcm_ReadData_D003(uint8 *Data);
extern Std_ReturnType Dcm_ReadData_D004(uint8 *Data);
extern Std_ReturnType Dcm_ReadData_D005(uint8 *Data);

/*============================================================================
  FUNCTION DECLARATIONS — WRITE DIDs (0x2E WriteDataByIdentifier)
============================================================================*/

extern Std_ReturnType Dcm_WriteData_F190(
    const uint8                    *Data,
    Dcm_NegativeResponseCodeType   *ErrorCode);

#endif /* DCM_DID_HANDLERS_H */
