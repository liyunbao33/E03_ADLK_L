/*
 * File: ADLK.h
 *
 * Code generated for Simulink model 'ADLK'.
 *
 * Model version                  : 1.15
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Wed Dec  6 17:54:31 2023
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_ADLK_h_
#define RTW_HEADER_ADLK_h_
#ifndef ADLK_COMMON_INCLUDES_
#define ADLK_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Rte_ADLK.h"
#endif                                 /* ADLK_COMMON_INCLUDES_ */

#include "ADLK_types.h"
#include "Rte_Type.h"

/* Block states (default storage) for system '<S3>/FLADLKDriver' */
typedef struct {
  uint16 temporalCounter_i2;           /* '<S3>/FLADLKDriver' */
  uint8 is_active_c19_ADLKDriver;      /* '<S3>/FLADLKDriver' */
  uint8 is_CLK;                        /* '<S3>/FLADLKDriver' */
  uint8 is_Rls;                        /* '<S3>/FLADLKDriver' */
  uint8 is_MainProgress;               /* '<S3>/FLADLKDriver' */
  uint8 is_Release;                    /* '<S3>/FLADLKDriver' */
  uint8 is_Step2_Open;                 /* '<S3>/FLADLKDriver' */
  uint8 is_DLK;                        /* '<S3>/FLADLKDriver' */
  uint8 SL_e_CycleCount;               /* '<S3>/FLADLKDriver' */
  uint8 SL_e_DoorRlsDelayTime;         /* '<S3>/FLADLKDriver' */
  uint8 temporalCounter_i1;            /* '<S3>/FLADLKDriver' */
  uint8 temporalCounter_i3;            /* '<S3>/FLADLKDriver' */
  boolean SL_b_MotorMutexFlg;          /* '<S3>/FLADLKDriver' */
  boolean SI_b_ClkUnlockFlg_prev;      /* '<S3>/FLADLKDriver' */
  boolean SI_b_ClkUnlockFlg_start;     /* '<S3>/FLADLKDriver' */
  boolean SI_b_ClkLockFlg_prev;        /* '<S3>/FLADLKDriver' */
  boolean SI_b_ClkLockFlg_start;       /* '<S3>/FLADLKDriver' */
  boolean SO_b_DoorRlsReq_prev;        /* '<S3>/FLADLKDriver' */
  boolean SO_b_DoorRlsReq_start;       /* '<S3>/FLADLKDriver' */
  boolean SI_b_DoorUnlockFlg_prev;     /* '<S3>/FLADLKDriver' */
  boolean SI_b_DoorUnlockFlg_start;    /* '<S3>/FLADLKDriver' */
  boolean SI_b_DoorLockFlg_prev;       /* '<S3>/FLADLKDriver' */
  boolean SI_b_DoorLockFlg_start;      /* '<S3>/FLADLKDriver' */
} DW_FLADLKDriver_ADLK_T;

/* Block signals (default storage) */
typedef struct tag_B_ADLK_T {
  uint8 SO_e_MotorCmd;                 /* '<S3>/RLADLKDriver' */
  uint8 SO_e_MotStateMachine;          /* '<S3>/RLADLKDriver' */
  uint8 SO_e_MotorPwm;                 /* '<S3>/RLADLKDriver' */
  uint8 SO_e_DoorLockCmd;              /* '<S3>/RLADLKDriver' */
  uint8 SO_e_MotorCmd_p;               /* '<S3>/FLADLKDriver' */
  uint8 SO_e_MotStateMachine_c;        /* '<S3>/FLADLKDriver' */
  uint8 SO_e_MotorPwm_b;               /* '<S3>/FLADLKDriver' */
  uint8 SO_e_DoorLockCmd_f;            /* '<S3>/FLADLKDriver' */
} B_ADLK_T;

/* Block states (default storage) for system '<Root>' */
typedef struct tag_DW_ADLK_T {
  uint8 E03_ADLK_L;                    /* '<S3>/Data Store Memory' */
  DW_FLADLKDriver_ADLK_T sf_RLADLKDriver;/* '<S3>/RLADLKDriver' */
  DW_FLADLKDriver_ADLK_T sf_FLADLKDriver;/* '<S3>/FLADLKDriver' */
} DW_ADLK_T;

/* Block signals (default storage) */
extern B_ADLK_T ADLK_B;

/* Block states (default storage) */
extern DW_ADLK_T ADLK_DW;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'ADLK'
 * '<S1>'   : 'ADLK/ADLK_Init'
 * '<S2>'   : 'ADLK/ADLK_Step_sys'
 * '<S3>'   : 'ADLK/ADLK_Step_sys/REL'
 * '<S4>'   : 'ADLK/ADLK_Step_sys/REL/FLADLKDriver'
 * '<S5>'   : 'ADLK/ADLK_Step_sys/REL/RLADLKDriver'
 * '<S6>'   : 'ADLK/ADLK_Step_sys/REL/Recycle Bin'
 */
#endif                                 /* RTW_HEADER_ADLK_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
