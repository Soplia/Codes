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

#include "xsi.h"

struct XSI_INFO xsi_info;



int main(int argc, char **argv)
{
    xsi_init_design(argc, argv);
    xsi_register_info(&xsi_info);

    xsi_register_min_prec_unit(-12);
    work_m_00000000003756717486_2244092194_init();
    xilinxcorelib_ver_m_00000000001358910285_2708713321_init();
    xilinxcorelib_ver_m_00000000001687936702_2843080771_init();
    xilinxcorelib_ver_m_00000000000277421008_1794530517_init();
    xilinxcorelib_ver_m_00000000001603977570_2048578852_init();
    work_m_00000000000403262735_2856477370_init();
    work_m_00000000002629890179_2032185554_init();
    work_m_00000000001229350481_3913188552_init();
    work_m_00000000001638485174_0886308060_init();
    work_m_00000000002980552824_0967167703_init();
    work_m_00000000000948816527_3683860065_init();
    work_m_00000000004057747688_3188997367_init();
    work_m_00000000004134447467_2073120511_init();


    xsi_register_tops("work_m_00000000004057747688_3188997367");
    xsi_register_tops("work_m_00000000004134447467_2073120511");


    return xsi_run_simulation(argc, argv);

}
