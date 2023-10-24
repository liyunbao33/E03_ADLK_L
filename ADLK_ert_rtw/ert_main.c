/*
 * File: ert_main.c
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

#include <stdio.h>
#include "ADLK.h"                      /* Model header file */

/* Example use case for call to exported function: ADLK_Step */
extern void sample_usage_ADLK_Step(void);
void sample_usage_ADLK_Step(void)
{
  /* Set task inputs here */

  /* Call to exported function */
  ADLK_Step();

  /* Read function outputs here */
}

/*
 * The example main function illustrates what is required by your
 * application code to initialize, execute, and terminate the generated code.
 * Attaching exported functions to a real-time clock is target specific.
 */
int_T main(int_T argc, const char *argv[])
{
  /* Unused arguments */
  (void)(argc);
  (void)(argv);

  /* Initialize model */
  ADLK_initialize();
  while (rtmGetErrorStatus(ADLK_M) == (NULL)) {
    /*  Perform application tasks here. */
  }

  /* Terminate model */
  ADLK_terminate();
  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
