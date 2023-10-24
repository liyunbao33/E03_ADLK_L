/*
 * File: ADLK_private.h
 *
 * Code generated for Simulink model 'ADLK'.
 *
 * Model version                  : 1.25
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Tue Oct 24 11:14:34 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_ADLK_private_h_
#define RTW_HEADER_ADLK_private_h_
#include "rtwtypes.h"
#include "Rte_Type.h"
#include "ADLK.h"

extern void ADLK_FLDoorRlsDriver_Init(uint8_T *rty_SO_e_MotorCmd, uint8_T
  *rty_SO_e_MotStateMachine, uint8_T *rty_SO_e_MotorPwm, boolean_T
  *rty_SO_b_Error, boolean_T *rty_SO_b_DoorUnlockCmd, boolean_T
  *rty_SO_b_DoorLockCmd, boolean_T *rty_SO_b_ClkUnlockCmd, boolean_T
  *rty_SO_b_ClkLockCmd);
extern void ADLK_FLDoorRlsDriver(uint8_T rtu_SI_e_Volt100mV, Boolean
  rtu_SO_b_DoorRlsReq, Boolean rtu_SI_b_DoorAjar, Boolean rtu_SI_b_DoorOpen,
  boolean_T rtu_SI_b_CinchHome, boolean_T rtu_SI_b_ElecDoorCfg, uint8_T
  rtu_SI_e_DoorRlsDelayTime, Boolean rtu_SI_b_DoorUnlockFlg, Boolean
  rtu_SI_b_DoorLockFlg, boolean_T rtu_SI_b_ClkUnlockFlg, boolean_T
  rtu_SI_b_ClkLockFlg, uint8_T *rty_SO_e_MotorCmd, uint8_T
  *rty_SO_e_MotStateMachine, uint8_T *rty_SO_e_MotorPwm, boolean_T
  *rty_SO_b_Error, boolean_T *rty_SO_b_DoorUnlockCmd, boolean_T
  *rty_SO_b_DoorLockCmd, boolean_T *rty_SO_b_ClkUnlockCmd, boolean_T
  *rty_SO_b_ClkLockCmd, DW_FLDoorRlsDriver_ADLK_T *localDW);

#endif                                 /* RTW_HEADER_ADLK_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
