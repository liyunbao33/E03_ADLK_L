/*
 * File: ADLK_private.h
 *
 * Code generated for Simulink model 'ADLK'.
 *
 * Model version                  : 1.27
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Wed Oct 25 11:40:47 2023
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_ADLK_private_h_
#define RTW_HEADER_ADLK_private_h_
#include "rtwtypes.h"
#include "Rte_Type.h"
#include "ADLK.h"

extern void ADLK_FLADLKDriver_Init(uint8 *rty_SO_e_MotorCmd, uint8
  *rty_SO_e_MotStateMachine, uint8 *rty_SO_e_MotorPwm, boolean *rty_SO_b_Error,
  boolean *rty_SO_b_DoorUnlockCmd, boolean *rty_SO_b_DoorLockCmd, boolean
  *rty_SO_b_ClkUnlockCmd, boolean *rty_SO_b_ClkLockCmd);
extern void ADLK_FLADLKDriver(uint8 rtu_SI_e_Volt100mV, Boolean
  rtu_SO_b_DoorRlsReq, Boolean rtu_SI_b_DoorAjar, Boolean rtu_SI_b_DoorOpen,
  uint8 rtu_SI_e_DoorRlsDelayTime, Boolean rtu_SI_b_DoorUnlockFlg, Boolean
  rtu_SI_b_DoorLockFlg, boolean rtu_SI_b_ClkUnlockFlg, boolean
  rtu_SI_b_ClkLockFlg, uint8 *rty_SO_e_MotorCmd, uint8 *rty_SO_e_MotStateMachine,
  uint8 *rty_SO_e_MotorPwm, boolean *rty_SO_b_Error, boolean
  *rty_SO_b_DoorUnlockCmd, boolean *rty_SO_b_DoorLockCmd, boolean
  *rty_SO_b_ClkUnlockCmd, boolean *rty_SO_b_ClkLockCmd, DW_FLADLKDriver_ADLK_T
  *localDW);

#endif                                 /* RTW_HEADER_ADLK_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
