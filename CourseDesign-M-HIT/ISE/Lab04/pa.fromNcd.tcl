
# PlanAhead Launch Script for Post PAR Floorplanning, created by Project Navigator

create_project -name SimpleCycle_MIPS -dir "F:/ISE/Lab04/planAhead_run_5" -part xc6slx16csg324-3
set srcset [get_property srcset [current_run -impl]]
set_property design_mode GateLvl $srcset
set_property edif_top_file "F:/ISE/Lab04/Top_cs.ngc" [ get_property srcset [ current_run ] ]
add_files -norecurse { {F:/ISE/Lab04} {ipcore_dir} }
set_property target_constrs_file "nexys3.ucf" [current_fileset -constrset]
add_files [list {nexys3.ucf}] -fileset [get_property constrset [current_run]]
link_design
read_xdl -file "F:/ISE/Lab04/Top.ncd"
if {[catch {read_twx -name results_1 -file "F:/ISE/Lab04/Top.twx"} eInfo]} {
   puts "WARNING: there was a problem importing \"F:/ISE/Lab04/Top.twx\": $eInfo"
}
