EESchema Schematic File Version 4
LIBS:Electronic_Calendar-cache
EELAYER 29 0
EELAYER END
$Descr A 11000 8500
encoding utf-8
Sheet 14 17
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Custom_Library:74LVC1G17_Power U?
U 1 1 5D15264A
P 4340 3520
F 0 "U?" H 4440 3670 50  0000 L CNN
F 1 "74LVC1G17" H 4440 3370 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-353_SC-70-5" H 4340 3520 50  0001 C CNN
F 3 "http://www.ti.com/lit/sg/scyt129e/scyt129e.pdf" H 4440 3670 50  0001 C CNN
F 4 "296-11934-1-ND" H 4340 3520 50  0001 C CNN "Digi-Key PN"
	1    4340 3520
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5D154376
P 4340 3620
F 0 "#PWR?" H 4340 3370 50  0001 C CNN
F 1 "GND" H 4340 3470 50  0000 C CNN
F 2 "" H 4340 3620 50  0001 C CNN
F 3 "" H 4340 3620 50  0001 C CNN
	1    4340 3620
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:+3.3V_BCKP #PWR?
U 1 1 5D1547C1
P 4340 3420
F 0 "#PWR?" H 4340 3270 50  0001 C CNN
F 1 "+3.3V_BCKP" H 4340 3560 50  0000 C CNN
F 2 "" H 4340 3420 50  0000 C CNN
F 3 "" H 4340 3420 50  0000 C CNN
	1    4340 3420
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:C_Custom C?
U 1 1 5D156DC3
P 4070 4070
AR Path="/5BAAE1F3/5D156DC3" Ref="C?"  Part="1" 
AR Path="/5BAAE1CB/5D156DC3" Ref="C?"  Part="1" 
AR Path="/5BE48F98/5D156DC3" Ref="C?"  Part="1" 
AR Path="/5CAD2D97/5D156DC3" Ref="C?"  Part="1" 
AR Path="/5CB7A8BC/5D156DC3" Ref="C?"  Part="1" 
AR Path="/5CB7A8C3/5D156DC3" Ref="C?"  Part="1" 
AR Path="/5CE10A3F/5D156DC3" Ref="C?"  Part="1" 
AR Path="/5D14F1F6/5D156DC3" Ref="C?"  Part="1" 
F 0 "C?" H 4095 4170 50  0000 L CNN
F 1 "0.1uF" H 4095 3970 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 4108 3920 50  0001 C CNN
F 3 "" H 4095 4170 50  0001 C CNN
F 4 "311-1344-1-ND" H 4495 4570 60  0001 C CNN "Digi-Key PN"
F 5 "0603" H 3920 4170 50  0000 R CNN "display_footprint"
F 6 "50V" H 3920 4070 50  0000 R CNN "Voltage"
F 7 "X7R" H 3920 3970 50  0000 R CNN "Dielectric"
	1    4070 4070
	-1   0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR?
U 1 1 5D156DC9
P 4070 3920
AR Path="/5CB7A8BC/5D156DC9" Ref="#PWR?"  Part="1" 
AR Path="/5CB7A8C3/5D156DC9" Ref="#PWR?"  Part="1" 
AR Path="/5CE10A3F/5D156DC9" Ref="#PWR?"  Part="1" 
AR Path="/5D14F1F6/5D156DC9" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 4070 3770 50  0001 C CNN
F 1 "+3.3V" H 4070 4060 50  0000 C CNN
F 2 "" H 4070 3920 50  0001 C CNN
F 3 "" H 4070 3920 50  0001 C CNN
	1    4070 3920
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5D156DCF
P 4070 4220
AR Path="/5CB7A8BC/5D156DCF" Ref="#PWR?"  Part="1" 
AR Path="/5CB7A8C3/5D156DCF" Ref="#PWR?"  Part="1" 
AR Path="/5CE10A3F/5D156DCF" Ref="#PWR?"  Part="1" 
AR Path="/5D14F1F6/5D156DCF" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 4070 3970 50  0001 C CNN
F 1 "GND" H 4070 4070 50  0000 C CNN
F 2 "" H 4070 4220 50  0001 C CNN
F 3 "" H 4070 4220 50  0001 C CNN
	1    4070 4220
	1    0    0    -1  
$EndComp
Text GLabel 4040 3520 0    50   Input ~ 0
POS3P3_PGOOD
Text GLabel 6590 3520 2    40   Output ~ 0
~BCKP_CHGEN
Text GLabel 4590 3520 2    40   Output ~ 0
~BCKP_BSTEN
$Comp
L power:GND #PWR?
U 1 1 5D15ACD5
P 6340 3620
F 0 "#PWR?" H 6340 3370 50  0001 C CNN
F 1 "GND" H 6340 3470 50  0000 C CNN
F 2 "" H 6340 3620 50  0001 C CNN
F 3 "" H 6340 3620 50  0001 C CNN
	1    6340 3620
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:+3.3V_BCKP #PWR?
U 1 1 5D15ACDF
P 6340 3420
F 0 "#PWR?" H 6340 3270 50  0001 C CNN
F 1 "+3.3V_BCKP" H 6340 3560 50  0000 C CNN
F 2 "" H 6340 3420 50  0000 C CNN
F 3 "" H 6340 3420 50  0000 C CNN
	1    6340 3420
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:C_Custom C?
U 1 1 5D15ACED
P 6070 4070
AR Path="/5BAAE1F3/5D15ACED" Ref="C?"  Part="1" 
AR Path="/5BAAE1CB/5D15ACED" Ref="C?"  Part="1" 
AR Path="/5BE48F98/5D15ACED" Ref="C?"  Part="1" 
AR Path="/5CAD2D97/5D15ACED" Ref="C?"  Part="1" 
AR Path="/5CB7A8BC/5D15ACED" Ref="C?"  Part="1" 
AR Path="/5CB7A8C3/5D15ACED" Ref="C?"  Part="1" 
AR Path="/5CE10A3F/5D15ACED" Ref="C?"  Part="1" 
AR Path="/5D14F1F6/5D15ACED" Ref="C?"  Part="1" 
F 0 "C?" H 6095 4170 50  0000 L CNN
F 1 "0.1uF" H 6095 3970 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 6108 3920 50  0001 C CNN
F 3 "" H 6095 4170 50  0001 C CNN
F 4 "311-1344-1-ND" H 6495 4570 60  0001 C CNN "Digi-Key PN"
F 5 "0603" H 5920 4170 50  0000 R CNN "display_footprint"
F 6 "50V" H 5920 4070 50  0000 R CNN "Voltage"
F 7 "X7R" H 5920 3970 50  0000 R CNN "Dielectric"
	1    6070 4070
	-1   0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR?
U 1 1 5D15ACF7
P 6070 3920
AR Path="/5CB7A8BC/5D15ACF7" Ref="#PWR?"  Part="1" 
AR Path="/5CB7A8C3/5D15ACF7" Ref="#PWR?"  Part="1" 
AR Path="/5CE10A3F/5D15ACF7" Ref="#PWR?"  Part="1" 
AR Path="/5D14F1F6/5D15ACF7" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 6070 3770 50  0001 C CNN
F 1 "+3.3V" H 6070 4060 50  0000 C CNN
F 2 "" H 6070 3920 50  0001 C CNN
F 3 "" H 6070 3920 50  0001 C CNN
	1    6070 3920
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5D15AD01
P 6070 4220
AR Path="/5CB7A8BC/5D15AD01" Ref="#PWR?"  Part="1" 
AR Path="/5CB7A8C3/5D15AD01" Ref="#PWR?"  Part="1" 
AR Path="/5CE10A3F/5D15AD01" Ref="#PWR?"  Part="1" 
AR Path="/5D14F1F6/5D15AD01" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 6070 3970 50  0001 C CNN
F 1 "GND" H 6070 4070 50  0000 C CNN
F 2 "" H 6070 4220 50  0001 C CNN
F 3 "" H 6070 4220 50  0001 C CNN
	1    6070 4220
	1    0    0    -1  
$EndComp
Text GLabel 6040 3520 0    50   Input ~ 0
POS3P3_PGOOD
$Comp
L Custom_Library:74LVC1G14_Power U?
U 1 1 5D15D9F1
P 6340 3520
F 0 "U?" H 6440 3670 50  0000 L CNN
F 1 "74LVC1G14" H 6440 3370 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-353_SC-70-5" H 6340 3570 50  0001 C CNN
F 3 "http://www.ti.com/lit/sg/scyt129e/scyt129e.pdf" H 6340 3520 50  0001 C CNN
F 4 "296-11608-1-ND" H 6640 3870 50  0001 C CNN "Digi-Key PN"
	1    6340 3520
	1    0    0    -1  
$EndComp
$EndSCHEMATC
