/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

/* This file is designed for use with ISim build 0x7708f090 */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "F:/ISE/Lab5JrX/pipeline_MIPS/register.v";
static const char *ng1 = "register";
static unsigned int ng2[] = {0U, 0U};
static int ng3[] = {0, 0};
static unsigned int ng4[] = {1U, 0U};



static void Initial_34_0(char *t0)
{
    char *t1;
    char *t2;

LAB0:    xsi_set_current_line(35, ng0);

LAB2:    xsi_set_current_line(36, ng0);
    t1 = (t0 + 2568);
    t2 = ((char*)((ng2)));
    xsi_vlogfile_readmemh(ng1, 0, t1, 1, *((unsigned int *)t2), 0, 0);

LAB1:    return;
}

static void Always_40_1(char *t0)
{
    char t4[8];
    char t5[8];
    char t8[8];
    char t38[8];
    char *t1;
    char *t2;
    char *t3;
    char *t6;
    char *t7;
    char *t9;
    char *t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    char *t23;
    char *t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    char *t30;
    char *t31;
    unsigned int t32;
    unsigned int t33;
    unsigned int t34;
    char *t35;
    char *t36;
    char *t37;
    char *t39;
    char *t40;
    char *t41;
    char *t42;
    char *t43;
    char *t44;
    char *t45;
    char *t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    unsigned int t50;
    char *t51;
    int t52;
    int t53;
    int t54;
    int t55;
    int t56;

LAB0:    t1 = (t0 + 3736U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(40, ng0);
    t2 = (t0 + 4056);
    *((int *)t2) = 1;
    t3 = (t0 + 3768);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(41, ng0);

LAB5:    xsi_set_current_line(42, ng0);
    t6 = (t0 + 1208U);
    t7 = *((char **)t6);
    t6 = ((char*)((ng3)));
    memset(t8, 0, 8);
    t9 = (t7 + 4);
    t10 = (t6 + 4);
    t11 = *((unsigned int *)t7);
    t12 = *((unsigned int *)t6);
    t13 = (t11 ^ t12);
    t14 = *((unsigned int *)t9);
    t15 = *((unsigned int *)t10);
    t16 = (t14 ^ t15);
    t17 = (t13 | t16);
    t18 = *((unsigned int *)t9);
    t19 = *((unsigned int *)t10);
    t20 = (t18 | t19);
    t21 = (~(t20));
    t22 = (t17 & t21);
    if (t22 != 0)
        goto LAB7;

LAB6:    if (t20 != 0)
        goto LAB8;

LAB9:    memset(t5, 0, 8);
    t24 = (t8 + 4);
    t25 = *((unsigned int *)t24);
    t26 = (~(t25));
    t27 = *((unsigned int *)t8);
    t28 = (t27 & t26);
    t29 = (t28 & 1U);
    if (t29 != 0)
        goto LAB10;

LAB11:    if (*((unsigned int *)t24) != 0)
        goto LAB12;

LAB13:    t31 = (t5 + 4);
    t32 = *((unsigned int *)t5);
    t33 = *((unsigned int *)t31);
    t34 = (t32 || t33);
    if (t34 > 0)
        goto LAB14;

LAB15:    t47 = *((unsigned int *)t5);
    t48 = (~(t47));
    t49 = *((unsigned int *)t31);
    t50 = (t48 || t49);
    if (t50 > 0)
        goto LAB16;

LAB17:    if (*((unsigned int *)t31) > 0)
        goto LAB18;

LAB19:    if (*((unsigned int *)t5) > 0)
        goto LAB20;

LAB21:    memcpy(t4, t45, 8);

LAB22:    t51 = (t0 + 2248);
    xsi_vlogvar_wait_assign_value(t51, t4, 0, 0, 32, 0LL);
    xsi_set_current_line(43, ng0);
    t2 = (t0 + 1368U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng3)));
    memset(t8, 0, 8);
    t6 = (t3 + 4);
    t7 = (t2 + 4);
    t11 = *((unsigned int *)t3);
    t12 = *((unsigned int *)t2);
    t13 = (t11 ^ t12);
    t14 = *((unsigned int *)t6);
    t15 = *((unsigned int *)t7);
    t16 = (t14 ^ t15);
    t17 = (t13 | t16);
    t18 = *((unsigned int *)t6);
    t19 = *((unsigned int *)t7);
    t20 = (t18 | t19);
    t21 = (~(t20));
    t22 = (t17 & t21);
    if (t22 != 0)
        goto LAB24;

LAB23:    if (t20 != 0)
        goto LAB25;

LAB26:    memset(t5, 0, 8);
    t10 = (t8 + 4);
    t25 = *((unsigned int *)t10);
    t26 = (~(t25));
    t27 = *((unsigned int *)t8);
    t28 = (t27 & t26);
    t29 = (t28 & 1U);
    if (t29 != 0)
        goto LAB27;

LAB28:    if (*((unsigned int *)t10) != 0)
        goto LAB29;

LAB30:    t24 = (t5 + 4);
    t32 = *((unsigned int *)t5);
    t33 = *((unsigned int *)t24);
    t34 = (t32 || t33);
    if (t34 > 0)
        goto LAB31;

LAB32:    t47 = *((unsigned int *)t5);
    t48 = (~(t47));
    t49 = *((unsigned int *)t24);
    t50 = (t48 || t49);
    if (t50 > 0)
        goto LAB33;

LAB34:    if (*((unsigned int *)t24) > 0)
        goto LAB35;

LAB36:    if (*((unsigned int *)t5) > 0)
        goto LAB37;

LAB38:    memcpy(t4, t43, 8);

LAB39:    t45 = (t0 + 2408);
    xsi_vlogvar_wait_assign_value(t45, t4, 0, 0, 32, 0LL);
    xsi_set_current_line(44, ng0);
    t2 = (t0 + 1848U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng4)));
    memset(t4, 0, 8);
    t6 = (t3 + 4);
    t7 = (t2 + 4);
    t11 = *((unsigned int *)t3);
    t12 = *((unsigned int *)t2);
    t13 = (t11 ^ t12);
    t14 = *((unsigned int *)t6);
    t15 = *((unsigned int *)t7);
    t16 = (t14 ^ t15);
    t17 = (t13 | t16);
    t18 = *((unsigned int *)t6);
    t19 = *((unsigned int *)t7);
    t20 = (t18 | t19);
    t21 = (~(t20));
    t22 = (t17 & t21);
    if (t22 != 0)
        goto LAB43;

LAB40:    if (t20 != 0)
        goto LAB42;

LAB41:    *((unsigned int *)t4) = 1;

LAB43:    t10 = (t4 + 4);
    t25 = *((unsigned int *)t10);
    t26 = (~(t25));
    t27 = *((unsigned int *)t4);
    t28 = (t27 & t26);
    t29 = (t28 != 0);
    if (t29 > 0)
        goto LAB44;

LAB45:
LAB46:    goto LAB2;

LAB7:    *((unsigned int *)t8) = 1;
    goto LAB9;

LAB8:    t23 = (t8 + 4);
    *((unsigned int *)t8) = 1;
    *((unsigned int *)t23) = 1;
    goto LAB9;

LAB10:    *((unsigned int *)t5) = 1;
    goto LAB13;

LAB12:    t30 = (t5 + 4);
    *((unsigned int *)t5) = 1;
    *((unsigned int *)t30) = 1;
    goto LAB13;

LAB14:    t35 = (t0 + 2568);
    t36 = (t35 + 56U);
    t37 = *((char **)t36);
    t39 = (t0 + 2568);
    t40 = (t39 + 72U);
    t41 = *((char **)t40);
    t42 = (t0 + 2568);
    t43 = (t42 + 64U);
    t44 = *((char **)t43);
    t45 = (t0 + 1208U);
    t46 = *((char **)t45);
    xsi_vlog_generic_get_array_select_value(t38, 32, t37, t41, t44, 2, 1, t46, 5, 2);
    goto LAB15;

LAB16:    t45 = ((char*)((ng3)));
    goto LAB17;

LAB18:    xsi_vlog_unsigned_bit_combine(t4, 32, t38, 32, t45, 32);
    goto LAB22;

LAB20:    memcpy(t4, t38, 8);
    goto LAB22;

LAB24:    *((unsigned int *)t8) = 1;
    goto LAB26;

LAB25:    t9 = (t8 + 4);
    *((unsigned int *)t8) = 1;
    *((unsigned int *)t9) = 1;
    goto LAB26;

LAB27:    *((unsigned int *)t5) = 1;
    goto LAB30;

LAB29:    t23 = (t5 + 4);
    *((unsigned int *)t5) = 1;
    *((unsigned int *)t23) = 1;
    goto LAB30;

LAB31:    t30 = (t0 + 2568);
    t31 = (t30 + 56U);
    t35 = *((char **)t31);
    t36 = (t0 + 2568);
    t37 = (t36 + 72U);
    t39 = *((char **)t37);
    t40 = (t0 + 2568);
    t41 = (t40 + 64U);
    t42 = *((char **)t41);
    t43 = (t0 + 1368U);
    t44 = *((char **)t43);
    xsi_vlog_generic_get_array_select_value(t38, 32, t35, t39, t42, 2, 1, t44, 5, 2);
    goto LAB32;

LAB33:    t43 = ((char*)((ng3)));
    goto LAB34;

LAB35:    xsi_vlog_unsigned_bit_combine(t4, 32, t38, 32, t43, 32);
    goto LAB39;

LAB37:    memcpy(t4, t38, 8);
    goto LAB39;

LAB42:    t9 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t9) = 1;
    goto LAB43;

LAB44:    xsi_set_current_line(45, ng0);
    t23 = (t0 + 1688U);
    t24 = *((char **)t23);
    t23 = (t0 + 2568);
    t30 = (t0 + 2568);
    t31 = (t30 + 72U);
    t35 = *((char **)t31);
    t36 = (t0 + 2568);
    t37 = (t36 + 64U);
    t39 = *((char **)t37);
    t40 = (t0 + 1528U);
    t41 = *((char **)t40);
    xsi_vlog_generic_convert_array_indices(t5, t8, t35, t39, 2, 1, t41, 5, 2);
    t40 = (t5 + 4);
    t32 = *((unsigned int *)t40);
    t52 = (!(t32));
    t42 = (t8 + 4);
    t33 = *((unsigned int *)t42);
    t53 = (!(t33));
    t54 = (t52 && t53);
    if (t54 == 1)
        goto LAB47;

LAB48:    goto LAB46;

LAB47:    t34 = *((unsigned int *)t5);
    t47 = *((unsigned int *)t8);
    t55 = (t34 - t47);
    t56 = (t55 + 1);
    xsi_vlogvar_wait_assign_value(t23, t24, 0, *((unsigned int *)t8), t56, 0LL);
    goto LAB48;

}


extern void work_m_00000000001229350481_3913188552_init()
{
	static char *pe[] = {(void *)Initial_34_0,(void *)Always_40_1};
	xsi_register_didat("work_m_00000000001229350481_3913188552", "isim/Top_tb_isim_beh.exe.sim/work/m_00000000001229350481_3913188552.didat");
	xsi_register_executes(pe);
}
