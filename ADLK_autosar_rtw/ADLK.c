/*
 * File: ADLK.c
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

#include "ADLK.h"
#include "rtwtypes.h"
#include "Rte_Type.h"
#include "ADLK_private.h"

/* Named constants for Chart: '<S3>/FLADLKDriver' */
#define ADLK_IN_Check                  ((uint8)1U)
#define ADLK_IN_Delay                  ((uint8)2U)
#define ADLK_IN_Idle                   ((uint8)1U)
#define ADLK_IN_LastCheck              ((uint8)2U)
#define ADLK_IN_Lock                   ((uint8)2U)
#define ADLK_IN_LockAct                ((uint8)3U)
#define ADLK_IN_NO_ACTIVE_CHILD        ((uint8)0U)
#define ADLK_IN_Normal                 ((uint8)1U)
#define ADLK_IN_PowerOn                ((uint8)2U)
#define ADLK_IN_Release                ((uint8)2U)
#define ADLK_IN_Reset                  ((uint8)3U)
#define ADLK_IN_Stall_Handle           ((uint8)4U)
#define ADLK_IN_Step1_Ajar             ((uint8)5U)
#define ADLK_IN_Step2_Open             ((uint8)6U)
#define ADLK_IN_Unlock                 ((uint8)4U)
#define ADLK_IN_UnlockAct              ((uint8)5U)
#define ADLK_IN_Wait                   ((uint8)3U)

/* Block signals (default storage) */
B_ADLK_T ADLK_B;

/* Block states (default storage) */
DW_ADLK_T ADLK_DW;

/* Forward declaration for local functions */
static float64 ADLK_GetPwm(float64 x, uint8 rtu_SI_e_Volt100mV);
static void ADLK_Rls(uint8 rtu_SI_e_Volt100mV, Boolean rtu_SI_b_DoorAjar,
                     Boolean rtu_SI_b_DoorOpen, uint8 rtu_SI_e_DoorRlsDelayTime,
                     uint8 *rty_SO_e_MotorCmd, uint8 *rty_SO_e_MotStateMachine,
                     uint8 *rty_SO_e_MotorPwm, boolean *rty_SO_b_Error,
                     DW_FLADLKDriver_ADLK_T *localDW);

/* Function for Chart: '<S3>/FLADLKDriver' */
static float64 ADLK_GetPwm(float64 x, uint8 rtu_SI_e_Volt100mV)
{
  float64 y;
  y = x * 100.0 / (float64)rtu_SI_e_Volt100mV;

  /*  ����100��������ת����  */
  if ((y > 100.0) || (rtu_SI_e_Volt100mV == 0)) {
    y = 100.0;
  }

  return y;
}

/* Function for Chart: '<S3>/FLADLKDriver' */
static void ADLK_Rls(uint8 rtu_SI_e_Volt100mV, Boolean rtu_SI_b_DoorAjar,
                     Boolean rtu_SI_b_DoorOpen, uint8 rtu_SI_e_DoorRlsDelayTime,
                     uint8 *rty_SO_e_MotorCmd, uint8 *rty_SO_e_MotStateMachine,
                     uint8 *rty_SO_e_MotorPwm, boolean *rty_SO_b_Error,
                     DW_FLADLKDriver_ADLK_T *localDW)
{
  switch (localDW->is_Rls) {
   case ADLK_IN_Normal:
    {
      if (localDW->is_MainProgress == ADLK_IN_Idle) {
        if ((localDW->SO_b_DoorRlsReq_prev != localDW->SO_b_DoorRlsReq_start) &&
            localDW->SO_b_DoorRlsReq_start) {
          localDW->SL_e_DoorRlsDelayTime = rtu_SI_e_DoorRlsDelayTime;
          *rty_SO_e_MotStateMachine = 1U;
          localDW->is_MainProgress = ADLK_IN_Release;
          localDW->SL_e_CycleCount = 0U;
          localDW->is_Release = ADLK_IN_Delay;
          localDW->temporalCounter_i2 = 0U;

          /*  �޿��ŵ��ͷ���ʱ  */
        }
      } else {
        /* case IN_Release: */
        switch (localDW->is_Release) {
         case ADLK_IN_Check:
          {
            if ((localDW->temporalCounter_i2 >= 5) && rtu_SI_b_DoorAjar) {
              localDW->is_Release = ADLK_IN_Step2_Open;
              localDW->is_Step2_Open = ADLK_IN_Idle;
              localDW->temporalCounter_i2 = 0U;
              *rty_SO_e_MotorCmd = 0U;
              *rty_SO_e_MotorPwm = 0U;
              localDW->SL_b_MotorMutexFlg = false;
              *rty_SO_e_MotStateMachine = 2U;
            } else {
              Boolean tmp_0;
              boolean tmp_1;
              tmp_0 = !rtu_SI_b_DoorAjar;
              tmp_1 = !localDW->SL_b_MotorMutexFlg;
              if ((localDW->temporalCounter_i2 >= 5) && tmp_0 &&
                  (localDW->SL_e_CycleCount < 3) && tmp_1) {
                localDW->is_Release = ADLK_IN_Stall_Handle;
                localDW->temporalCounter_i2 = 0U;
                *rty_SO_e_MotorCmd = 1U;
                *rty_SO_e_MotorPwm = 100U;
                localDW->SL_e_CycleCount++;
                localDW->SL_b_MotorMutexFlg = true;
              } else if ((localDW->temporalCounter_i2 >= 5) && tmp_0 &&
                         (localDW->SL_e_CycleCount >= 3) && tmp_1) {
                float64 tmp;
                *rty_SO_b_Error = true;
                localDW->is_Release = ADLK_IN_Reset;
                localDW->temporalCounter_i2 = 0U;
                *rty_SO_e_MotorCmd = 2U;
                tmp = ADLK_GetPwm(70.0, rtu_SI_e_Volt100mV);
                if (tmp < 256.0) {
                  if (tmp >= 0.0) {
                    *rty_SO_e_MotorPwm = (uint8)tmp;
                  } else {
                    *rty_SO_e_MotorPwm = 0U;
                  }
                } else {
                  *rty_SO_e_MotorPwm = MAX_uint8_T;
                }

                localDW->SL_b_MotorMutexFlg = true;
                *rty_SO_e_MotStateMachine = 3U;
              }
            }
          }
          break;

         case ADLK_IN_Delay:
          {
            if ((localDW->temporalCounter_i2 >= localDW->SL_e_DoorRlsDelayTime) &&
                (!localDW->SL_b_MotorMutexFlg)) {
              float64 tmp;
              localDW->is_Release = ADLK_IN_Step1_Ajar;
              localDW->temporalCounter_i2 = 0U;
              *rty_SO_e_MotorCmd = 1U;
              tmp = ADLK_GetPwm(105.0, rtu_SI_e_Volt100mV);
              if (tmp < 256.0) {
                if (tmp >= 0.0) {
                  *rty_SO_e_MotorPwm = (uint8)tmp;
                } else {
                  *rty_SO_e_MotorPwm = 0U;
                }
              } else {
                *rty_SO_e_MotorPwm = MAX_uint8_T;
              }

              localDW->SL_b_MotorMutexFlg = true;
            }
          }
          break;

         case ADLK_IN_Reset:
          if (localDW->temporalCounter_i2 >= 30) {
            localDW->SL_b_MotorMutexFlg = false;
            *rty_SO_e_MotStateMachine = 4U;
            localDW->is_Release = ADLK_IN_NO_ACTIVE_CHILD;
            localDW->is_MainProgress = ADLK_IN_Idle;
            *rty_SO_e_MotorCmd = 0U;
            *rty_SO_e_MotorPwm = 0U;
          }
          break;

         case ADLK_IN_Stall_Handle:
          if (localDW->temporalCounter_i2 >= 30) {
            localDW->is_Release = ADLK_IN_Check;
            localDW->temporalCounter_i2 = 0U;
            *rty_SO_e_MotorCmd = 0U;
            *rty_SO_e_MotorPwm = 0U;
            localDW->SL_b_MotorMutexFlg = false;
          }
          break;

         case ADLK_IN_Step1_Ajar:
          if (localDW->temporalCounter_i2 >= 30) {
            localDW->is_Release = ADLK_IN_Check;
            localDW->temporalCounter_i2 = 0U;
            *rty_SO_e_MotorCmd = 0U;
            *rty_SO_e_MotorPwm = 0U;
            localDW->SL_b_MotorMutexFlg = false;
          }
          break;

         default:
          {
            /* case IN_Step2_Open: */
            if (localDW->is_Step2_Open == ADLK_IN_Idle) {
              if ((localDW->temporalCounter_i2 < 270) && rtu_SI_b_DoorOpen) {
                float64 tmp;
                *rty_SO_b_Error = false;
                localDW->is_Step2_Open = ADLK_IN_NO_ACTIVE_CHILD;
                localDW->is_Release = ADLK_IN_Reset;
                localDW->temporalCounter_i2 = 0U;
                *rty_SO_e_MotorCmd = 2U;
                tmp = ADLK_GetPwm(70.0, rtu_SI_e_Volt100mV);
                if (tmp < 256.0) {
                  if (tmp >= 0.0) {
                    *rty_SO_e_MotorPwm = (uint8)tmp;
                  } else {
                    *rty_SO_e_MotorPwm = 0U;
                  }
                } else {
                  *rty_SO_e_MotorPwm = MAX_uint8_T;
                }

                localDW->SL_b_MotorMutexFlg = true;
                *rty_SO_e_MotStateMachine = 3U;
              } else if (localDW->temporalCounter_i2 >= 300) {
                localDW->is_Step2_Open = ADLK_IN_LastCheck;
              }
            } else {
              float64 tmp;

              /* case IN_LastCheck: */
              localDW->is_Step2_Open = ADLK_IN_NO_ACTIVE_CHILD;
              localDW->is_Release = ADLK_IN_Reset;
              localDW->temporalCounter_i2 = 0U;
              *rty_SO_e_MotorCmd = 2U;
              tmp = ADLK_GetPwm(70.0, rtu_SI_e_Volt100mV);
              if (tmp < 256.0) {
                if (tmp >= 0.0) {
                  *rty_SO_e_MotorPwm = (uint8)tmp;
                } else {
                  *rty_SO_e_MotorPwm = 0U;
                }
              } else {
                *rty_SO_e_MotorPwm = MAX_uint8_T;
              }

              localDW->SL_b_MotorMutexFlg = true;
              *rty_SO_e_MotStateMachine = 3U;
            }
          }
          break;
        }
      }
    }
    break;

   case ADLK_IN_PowerOn:
    if (localDW->temporalCounter_i2 >= 30) {
      localDW->SL_b_MotorMutexFlg = false;
      *rty_SO_e_MotStateMachine = 4U;
      localDW->is_Rls = ADLK_IN_Normal;

      /*  �ǵ綯��  */
      localDW->is_MainProgress = ADLK_IN_Idle;
      *rty_SO_e_MotorCmd = 0U;
      *rty_SO_e_MotorPwm = 0U;
    }
    break;

   default:
    {
      /* case IN_Wait: */
      if (!localDW->SL_b_MotorMutexFlg) {
        float64 tmp;
        localDW->is_Rls = ADLK_IN_PowerOn;
        localDW->temporalCounter_i2 = 0U;

        /*  �ϵ��ͷŵ��ִ��һ�θ�λ  */
        *rty_SO_e_MotorCmd = 2U;
        tmp = ADLK_GetPwm(70.0, rtu_SI_e_Volt100mV);
        if (tmp < 256.0) {
          if (tmp >= 0.0) {
            *rty_SO_e_MotorPwm = (uint8)tmp;
          } else {
            *rty_SO_e_MotorPwm = 0U;
          }
        } else {
          *rty_SO_e_MotorPwm = MAX_uint8_T;
        }

        localDW->SL_b_MotorMutexFlg = true;
        *rty_SO_e_MotStateMachine = 3U;
      }
    }
    break;
  }
}

/*
 * System initialize for atomic system:
 *    '<S3>/FLADLKDriver'
 *    '<S3>/RLADLKDriver'
 */
void ADLK_FLADLKDriver_Init(uint8 *rty_SO_e_MotorCmd, uint8
  *rty_SO_e_MotStateMachine, uint8 *rty_SO_e_MotorPwm, boolean *rty_SO_b_Error,
  boolean *rty_SO_b_DoorUnlockCmd, boolean *rty_SO_b_DoorLockCmd, boolean
  *rty_SO_b_ClkUnlockCmd, boolean *rty_SO_b_ClkLockCmd)
{
  *rty_SO_e_MotorCmd = 0U;
  *rty_SO_e_MotStateMachine = 0U;
  *rty_SO_e_MotorPwm = 0U;
  *rty_SO_b_Error = false;
  *rty_SO_b_DoorUnlockCmd = false;
  *rty_SO_b_DoorLockCmd = false;
  *rty_SO_b_ClkUnlockCmd = false;
  *rty_SO_b_ClkLockCmd = false;
}

/*
 * Output and update for atomic system:
 *    '<S3>/FLADLKDriver'
 *    '<S3>/RLADLKDriver'
 */
void ADLK_FLADLKDriver(uint8 rtu_SI_e_Volt100mV, Boolean rtu_SO_b_DoorRlsReq,
  Boolean rtu_SI_b_DoorAjar, Boolean rtu_SI_b_DoorOpen, uint8
  rtu_SI_e_DoorRlsDelayTime, Boolean rtu_SI_b_DoorUnlockFlg, Boolean
  rtu_SI_b_DoorLockFlg, boolean rtu_SI_b_ClkUnlockFlg, boolean
  rtu_SI_b_ClkLockFlg, uint8 *rty_SO_e_MotorCmd, uint8 *rty_SO_e_MotStateMachine,
  uint8 *rty_SO_e_MotorPwm, boolean *rty_SO_b_Error, boolean
  *rty_SO_b_DoorUnlockCmd, boolean *rty_SO_b_DoorLockCmd, boolean
  *rty_SO_b_ClkUnlockCmd, boolean *rty_SO_b_ClkLockCmd, DW_FLADLKDriver_ADLK_T
  *localDW)
{
  if (localDW->temporalCounter_i1 < 31U) {
    localDW->temporalCounter_i1++;
  }

  if (localDW->temporalCounter_i2 < 511U) {
    localDW->temporalCounter_i2++;
  }

  if (localDW->temporalCounter_i3 < 31U) {
    localDW->temporalCounter_i3++;
  }

  localDW->SI_b_DoorUnlockFlg_prev = localDW->SI_b_DoorUnlockFlg_start;
  localDW->SI_b_DoorUnlockFlg_start = rtu_SI_b_DoorUnlockFlg;
  localDW->SI_b_DoorLockFlg_prev = localDW->SI_b_DoorLockFlg_start;
  localDW->SI_b_DoorLockFlg_start = rtu_SI_b_DoorLockFlg;
  localDW->SO_b_DoorRlsReq_prev = localDW->SO_b_DoorRlsReq_start;
  localDW->SO_b_DoorRlsReq_start = rtu_SO_b_DoorRlsReq;
  localDW->SI_b_ClkUnlockFlg_prev = localDW->SI_b_ClkUnlockFlg_start;
  localDW->SI_b_ClkUnlockFlg_start = rtu_SI_b_ClkUnlockFlg;
  localDW->SI_b_ClkLockFlg_prev = localDW->SI_b_ClkLockFlg_start;
  localDW->SI_b_ClkLockFlg_start = rtu_SI_b_ClkLockFlg;

  /* Chart: '<S3>/FLADLKDriver' */
  if (localDW->is_active_c19_ADLKDriver == 0U) {
    localDW->SI_b_DoorUnlockFlg_prev = rtu_SI_b_DoorUnlockFlg;
    localDW->SI_b_DoorLockFlg_prev = rtu_SI_b_DoorLockFlg;
    localDW->SO_b_DoorRlsReq_prev = rtu_SO_b_DoorRlsReq;
    localDW->SI_b_ClkUnlockFlg_prev = rtu_SI_b_ClkUnlockFlg;
    localDW->SI_b_ClkLockFlg_prev = rtu_SI_b_ClkLockFlg;
    localDW->is_active_c19_ADLKDriver = 1U;
    localDW->is_DLK = ADLK_IN_Idle;
    localDW->is_CLK = ADLK_IN_Idle;
    localDW->is_Rls = ADLK_IN_Wait;

    /*  �ȴ������Դ����  */
  } else {
    switch (localDW->is_DLK) {
     case ADLK_IN_Idle:
      if ((localDW->SI_b_DoorUnlockFlg_prev != localDW->SI_b_DoorUnlockFlg_start)
          && localDW->SI_b_DoorUnlockFlg_start) {
        localDW->is_DLK = ADLK_IN_Unlock;
      } else if ((localDW->SI_b_DoorLockFlg_prev !=
                  localDW->SI_b_DoorLockFlg_start) &&
                 localDW->SI_b_DoorLockFlg_start) {
        localDW->is_DLK = ADLK_IN_Lock;
      }
      break;

     case ADLK_IN_Lock:
      if (!localDW->SL_b_MotorMutexFlg) {
        localDW->is_DLK = ADLK_IN_LockAct;
        localDW->temporalCounter_i1 = 0U;
        *rty_SO_b_DoorLockCmd = true;
        localDW->SL_b_MotorMutexFlg = true;
      }
      break;

     case ADLK_IN_LockAct:
      if (localDW->temporalCounter_i1 >= 20) {
        *rty_SO_b_DoorLockCmd = false;
        localDW->SL_b_MotorMutexFlg = false;
        localDW->is_DLK = ADLK_IN_Idle;
      }
      break;

     case ADLK_IN_Unlock:
      if (!localDW->SL_b_MotorMutexFlg) {
        localDW->is_DLK = ADLK_IN_UnlockAct;
        localDW->temporalCounter_i1 = 0U;
        *rty_SO_b_DoorUnlockCmd = true;
        localDW->SL_b_MotorMutexFlg = true;
      }
      break;

     default:
      /* case IN_UnlockAct: */
      if (localDW->temporalCounter_i1 >= 20) {
        *rty_SO_b_DoorUnlockCmd = false;
        localDW->SL_b_MotorMutexFlg = false;
        localDW->is_DLK = ADLK_IN_Idle;
      }
      break;
    }

    switch (localDW->is_CLK) {
     case ADLK_IN_Idle:
      if ((localDW->SI_b_ClkUnlockFlg_prev != localDW->SI_b_ClkUnlockFlg_start) &&
          localDW->SI_b_ClkUnlockFlg_start) {
        localDW->is_CLK = ADLK_IN_Unlock;
      } else if ((localDW->SI_b_ClkLockFlg_prev !=
                  localDW->SI_b_ClkLockFlg_start) &&
                 localDW->SI_b_ClkLockFlg_start) {
        localDW->is_CLK = ADLK_IN_Lock;
      }
      break;

     case ADLK_IN_Lock:
      if (!localDW->SL_b_MotorMutexFlg) {
        localDW->is_CLK = ADLK_IN_LockAct;
        localDW->temporalCounter_i3 = 0U;
        *rty_SO_b_ClkLockCmd = true;
        localDW->SL_b_MotorMutexFlg = true;
      }
      break;

     case ADLK_IN_LockAct:
      if (localDW->temporalCounter_i3 >= 20) {
        *rty_SO_b_ClkLockCmd = false;
        localDW->SL_b_MotorMutexFlg = false;
        localDW->is_CLK = ADLK_IN_Idle;
      }
      break;

     case ADLK_IN_Unlock:
      if (!localDW->SL_b_MotorMutexFlg) {
        localDW->is_CLK = ADLK_IN_UnlockAct;
        localDW->temporalCounter_i3 = 0U;
        *rty_SO_b_ClkUnlockCmd = true;
        localDW->SL_b_MotorMutexFlg = true;
      }
      break;

     default:
      /* case IN_UnlockAct: */
      if (localDW->temporalCounter_i3 >= 20) {
        *rty_SO_b_ClkUnlockCmd = false;
        localDW->SL_b_MotorMutexFlg = false;
        localDW->is_CLK = ADLK_IN_Idle;
      }
      break;
    }

    ADLK_Rls(rtu_SI_e_Volt100mV, rtu_SI_b_DoorAjar, rtu_SI_b_DoorOpen,
             rtu_SI_e_DoorRlsDelayTime, rty_SO_e_MotorCmd,
             rty_SO_e_MotStateMachine, rty_SO_e_MotorPwm, rty_SO_b_Error,
             localDW);
  }

  /* End of Chart: '<S3>/FLADLKDriver' */
}

/* Model step function for TID1 */
void ADLK_Step(void)                   /* Explicit Task: ADLK_Step */
{
  uint8 SO_e_MotorPwm_a;
  Boolean tmpRead;
  Boolean tmpRead_0;
  Boolean tmpRead_1;
  Boolean tmpRead_2;
  Boolean tmpRead_3;
  Boolean tmpRead_4;
  Boolean tmpRead_5;
  boolean SO_b_ClkLockCmd;
  boolean SO_b_ClkLockCmd_d;
  boolean SO_b_ClkUnlockCmd;
  boolean SO_b_ClkUnlockCmd_o;
  boolean SO_b_Error;
  boolean SO_b_Error_o;

  /* Inport: '<Root>/VbOUT_HWA_RLDoorFullOpen_flg_VbOUT_HWA_RLDoorFullOpen_flg' */
  (void)Rte_Read_VbOUT_HWA_RLDoorFullOpen_flg_VbOUT_HWA_RLDoorFullOpen_flg
    (&tmpRead_5);

  /* Inport: '<Root>/VbOUT_HWA_FLDoorFullOpen_flg_VbOUT_HWA_FLDoorFullOpen_flg' */
  (void)Rte_Read_VbOUT_HWA_FLDoorFullOpen_flg_VbOUT_HWA_FLDoorFullOpen_flg
    (&SO_b_Error);

  /* Inport: '<Root>/VbOUT_SP_RLDoorAjarSts_flg_VbOUT_SP_RLDoorAjarSts_flg' */
  (void)Rte_Read_VbOUT_SP_RLDoorAjarSts_flg_VbOUT_SP_RLDoorAjarSts_flg
    (&tmpRead_4);

  /* Inport: '<Root>/VbOUT_SP_FLDoorAjarSts_flg_VbOUT_SP_FLDoorAjarSts_flg' */
  (void)Rte_Read_VbOUT_SP_FLDoorAjarSts_flg_VbOUT_SP_FLDoorAjarSts_flg
    (&SO_b_ClkUnlockCmd);

  /* Inport: '<Root>/VbOUT_REL_RLDoorRlsReq_flg_VbOUT_REL_RLDoorRlsReq_flg' */
  (void)Rte_Read_VbOUT_REL_RLDoorRlsReq_flg_VbOUT_REL_RLDoorRlsReq_flg
    (&tmpRead_3);

  /* Inport: '<Root>/VbOUT_REL_FLDoorRlsReq_flg_VbOUT_REL_FLDoorRlsReq_flg' */
  (void)Rte_Read_VbOUT_REL_FLDoorRlsReq_flg_VbOUT_REL_FLDoorRlsReq_flg
    (&SO_b_ClkLockCmd);

  /* Inport: '<Root>/VbOUT_DLK_RLLock_flg_VbOUT_DLK_RLLock_flg' */
  (void)Rte_Read_VbOUT_DLK_RLLock_flg_VbOUT_DLK_RLLock_flg(&tmpRead_2);

  /* Inport: '<Root>/VbOUT_DLK_FLLock_flg_VbOUT_DLK_FLLock_flg' */
  (void)Rte_Read_VbOUT_DLK_FLLock_flg_VbOUT_DLK_FLLock_flg(&tmpRead_1);

  /* Inport: '<Root>/VbOUT_DLK_RLUnlock_flg_VbOUT_DLK_RLUnlock_flg' */
  (void)Rte_Read_VbOUT_DLK_RLUnlock_flg_VbOUT_DLK_RLUnlock_flg(&tmpRead_0);

  /* Inport: '<Root>/VbOUT_DLK_FLUnlock_flg_VbOUT_DLK_FLUnlock_flg' */
  (void)Rte_Read_VbOUT_DLK_FLUnlock_flg_VbOUT_DLK_FLUnlock_flg(&tmpRead);

  /* RootInportFunctionCallGenerator generated from: '<Root>/ADLK_Step' incorporates:
   *  SubSystem: '<Root>/ADLK_Step_sys'
   */
  /* DataStoreWrite: '<S3>/Data Store Write' incorporates:
   *  Constant: '<S3>/Constant'
   */
  ADLK_DW.E03_ADLK_L = 0U;

  /* Chart: '<S3>/FLADLKDriver' incorporates:
   *  Constant: '<S3>/Constant1'
   */
  ADLK_FLADLKDriver(0U, SO_b_ClkLockCmd, SO_b_ClkUnlockCmd, SO_b_Error, 20,
                    tmpRead, tmpRead_1, false, false, &ADLK_B.SO_e_MotorCmd_k,
                    &ADLK_B.SO_e_MotStateMachine_h, &SO_e_MotorPwm_a,
                    &SO_b_Error_o, &ADLK_B.SO_b_DoorUnlockCmd_h,
                    &ADLK_B.SO_b_DoorLockCmd_i, &SO_b_ClkUnlockCmd_o,
                    &SO_b_ClkLockCmd_d, &ADLK_DW.sf_FLADLKDriver);

  /* Chart: '<S3>/RLADLKDriver' incorporates:
   *  Constant: '<S3>/Constant1'
   */
  ADLK_FLADLKDriver(0U, tmpRead_3, tmpRead_4, tmpRead_5, 20, tmpRead_0,
                    tmpRead_2, false, false, &ADLK_B.SO_e_MotorCmd,
                    &ADLK_B.SO_e_MotStateMachine, &SO_e_MotorPwm_a, &SO_b_Error,
                    &ADLK_B.SO_b_DoorUnlockCmd, &ADLK_B.SO_b_DoorLockCmd,
                    &SO_b_ClkUnlockCmd, &SO_b_ClkLockCmd,
                    &ADLK_DW.sf_RLADLKDriver);

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/ADLK_Step' */

  /* Outport: '<Root>/VbOUT_ADLK_FLUnlock_flg_VbOUT_ADLK_FLUnlock_flg' */
  (void)Rte_Write_VbOUT_ADLK_FLUnlock_flg_VbOUT_ADLK_FLUnlock_flg
    (ADLK_B.SO_b_DoorUnlockCmd_h);

  /* Outport: '<Root>/VbOUT_ADLK_RLUnlock_flg_VbOUT_ADLK_RLUnlock_flg' */
  (void)Rte_Write_VbOUT_ADLK_RLUnlock_flg_VbOUT_ADLK_RLUnlock_flg
    (ADLK_B.SO_b_DoorUnlockCmd);

  /* Outport: '<Root>/VbOUT_ADLK_FLLock_flg_VbOUT_ADLK_FLLock_flg' */
  (void)Rte_Write_VbOUT_ADLK_FLLock_flg_VbOUT_ADLK_FLLock_flg
    (ADLK_B.SO_b_DoorLockCmd_i);

  /* Outport: '<Root>/VbOUT_ADLK_RLLock_flg_VbOUT_ADLK_RLLock_flg' */
  (void)Rte_Write_VbOUT_ADLK_RLLock_flg_VbOUT_ADLK_RLLock_flg
    (ADLK_B.SO_b_DoorLockCmd);

  /* RootInportFunctionCallGenerator generated from: '<Root>/ADLK_Step' incorporates:
   *  SubSystem: '<Root>/ADLK_Step_sys'
   */
  /* Outport: '<Root>/VbOUT_ADLK_FLDoorMotorA_flg_VbOUT_ADLK_FLDoorMotorA_flg' incorporates:
   *  Constant: '<S4>/Constant'
   *  RelationalOperator: '<S4>/Compare'
   */
  (void)Rte_Write_VbOUT_ADLK_FLDoorMotorA_flg_VbOUT_ADLK_FLDoorMotorA_flg
    (ADLK_B.SO_e_MotorCmd_k == 1);

  /* Outport: '<Root>/VbOUT_ADLK_FLDoorMotorB_flg_VbOUT_ADLK_FLDoorMotorB_flg' incorporates:
   *  Constant: '<S5>/Constant'
   *  RelationalOperator: '<S5>/Compare'
   */
  (void)Rte_Write_VbOUT_ADLK_FLDoorMotorB_flg_VbOUT_ADLK_FLDoorMotorB_flg
    (ADLK_B.SO_e_MotorCmd_k == 2);

  /* Outport: '<Root>/VbOUT_ADLK_RLDoorMotorA_flg_VbOUT_ADLK_RLDoorMotorA_flg' incorporates:
   *  Constant: '<S6>/Constant'
   *  RelationalOperator: '<S6>/Compare'
   */
  (void)Rte_Write_VbOUT_ADLK_RLDoorMotorA_flg_VbOUT_ADLK_RLDoorMotorA_flg
    (ADLK_B.SO_e_MotorCmd == 1);

  /* Outport: '<Root>/VbOUT_ADLK_RLDoorMotorB_flg_VbOUT_ADLK_RLDoorMotorB_flg' incorporates:
   *  Constant: '<S7>/Constant'
   *  RelationalOperator: '<S7>/Compare'
   */
  (void)Rte_Write_VbOUT_ADLK_RLDoorMotorB_flg_VbOUT_ADLK_RLDoorMotorB_flg
    (ADLK_B.SO_e_MotorCmd == 2);

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/ADLK_Step' */

  /* Outport: '<Root>/VeOUT_ADLK_FLReleaseLatchStatus_sig_VeOUT_ADLK_FLReleaseLatchStatus_sig' */
  (void)
    Rte_Write_VeOUT_ADLK_FLReleaseLatchStatus_sig_VeOUT_ADLK_FLReleaseLatchStatus_sig
    (ADLK_B.SO_e_MotStateMachine_h);

  /* Outport: '<Root>/VeOUT_ADLK_RLReleaseLatchStatus_sig_VeOUT_ADLK_RLReleaseLatchStatus_sig' */
  (void)
    Rte_Write_VeOUT_ADLK_RLReleaseLatchStatus_sig_VeOUT_ADLK_RLReleaseLatchStatus_sig
    (ADLK_B.SO_e_MotStateMachine);
}

/* Model initialize function */
void ADLK_Init(void)
{
  {
    uint8 SO_e_MotorPwm_a;
    boolean SO_b_ClkLockCmd_d;
    boolean SO_b_ClkUnlockCmd_o;
    boolean SO_b_Error_o;

    /* SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/ADLK_Step' incorporates:
     *  SubSystem: '<Root>/ADLK_Step_sys'
     */

    /* SystemInitialize for Chart: '<S3>/FLADLKDriver' */
    ADLK_FLADLKDriver_Init(&ADLK_B.SO_e_MotorCmd_k,
      &ADLK_B.SO_e_MotStateMachine_h, &SO_e_MotorPwm_a, &SO_b_Error_o,
      &ADLK_B.SO_b_DoorUnlockCmd_h, &ADLK_B.SO_b_DoorLockCmd_i,
      &SO_b_ClkUnlockCmd_o, &SO_b_ClkLockCmd_d);

    /* SystemInitialize for Chart: '<S3>/RLADLKDriver' */
    ADLK_FLADLKDriver_Init(&ADLK_B.SO_e_MotorCmd, &ADLK_B.SO_e_MotStateMachine,
      &SO_e_MotorPwm_a, &SO_b_Error_o, &ADLK_B.SO_b_DoorUnlockCmd,
      &ADLK_B.SO_b_DoorLockCmd, &SO_b_ClkUnlockCmd_o, &SO_b_ClkLockCmd_d);

    /* End of SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/ADLK_Step' */

    /* SystemInitialize for Outport: '<Root>/VbOUT_ADLK_FLUnlock_flg_VbOUT_ADLK_FLUnlock_flg' */
    (void)Rte_Write_VbOUT_ADLK_FLUnlock_flg_VbOUT_ADLK_FLUnlock_flg
      (ADLK_B.SO_b_DoorUnlockCmd_h);

    /* SystemInitialize for Outport: '<Root>/VbOUT_ADLK_RLUnlock_flg_VbOUT_ADLK_RLUnlock_flg' */
    (void)Rte_Write_VbOUT_ADLK_RLUnlock_flg_VbOUT_ADLK_RLUnlock_flg
      (ADLK_B.SO_b_DoorUnlockCmd);

    /* SystemInitialize for Outport: '<Root>/VbOUT_ADLK_FLLock_flg_VbOUT_ADLK_FLLock_flg' */
    (void)Rte_Write_VbOUT_ADLK_FLLock_flg_VbOUT_ADLK_FLLock_flg
      (ADLK_B.SO_b_DoorLockCmd_i);

    /* SystemInitialize for Outport: '<Root>/VbOUT_ADLK_RLLock_flg_VbOUT_ADLK_RLLock_flg' */
    (void)Rte_Write_VbOUT_ADLK_RLLock_flg_VbOUT_ADLK_RLLock_flg
      (ADLK_B.SO_b_DoorLockCmd);

    /* SystemInitialize for Outport: '<Root>/VeOUT_ADLK_FLReleaseLatchStatus_sig_VeOUT_ADLK_FLReleaseLatchStatus_sig' */
    (void)
      Rte_Write_VeOUT_ADLK_FLReleaseLatchStatus_sig_VeOUT_ADLK_FLReleaseLatchStatus_sig
      (ADLK_B.SO_e_MotStateMachine_h);

    /* SystemInitialize for Outport: '<Root>/VeOUT_ADLK_RLReleaseLatchStatus_sig_VeOUT_ADLK_RLReleaseLatchStatus_sig' */
    (void)
      Rte_Write_VeOUT_ADLK_RLReleaseLatchStatus_sig_VeOUT_ADLK_RLReleaseLatchStatus_sig
      (ADLK_B.SO_e_MotStateMachine);
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */