EESchema Schematic File Version 4
LIBS:Electronic_Calendar-cache
EELAYER 29 0
EELAYER END
$Descr A 11000 8500
encoding utf-8
Sheet 4 17
Title "Electronic Calendar"
Date "2019-07-25"
Rev "A"
Comp "Drew Maatman"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text Notes 540  690  0    100  ~ 20
04. Supercap Backup Circuit
$Comp
L Custom_Library:LTC4041UFD U401
U 1 1 5CA288A5
P 5500 4060
F 0 "U401" H 6300 2610 50  0000 R CNN
F 1 "LTC4041UFD" H 5500 4060 50  0000 C CNN
F 2 "Housings_DFN_QFN:QFN-24-1EP_4x5mm_Pitch0.5mm" H 5450 4060 50  0001 C CNN
F 3 "https://www.analog.com/media/en/technical-documentation/data-sheets/LTC4041.pdf" H 5450 4060 50  0001 C CNN
F 4 "LTC4041IUFD#PBF-ND" H -240 360 50  0001 C CNN "Digi-Key PN"
	1    5500 4060
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:L_Custom L401
U 1 1 5CA28FC7
P 6810 3760
F 0 "L401" V 6760 3760 50  0000 C CNN
F 1 "2.2uH" V 6885 3760 50  0000 C CNN
F 2 "Inductors_SMD:L_Vishay_IHLP-2020" H 6810 3760 50  0001 C CNN
F 3 "" H 6810 3760 50  0001 C CNN
F 4 "IHLP2020" V 6960 3760 50  0000 C CNN "display_footprint"
F 5 "6.75" V 7060 3760 50  0000 C CNN "Ampacity"
F 6 "20%" V 7160 3760 50  0000 C CNN "Tolerance"
F 7 "541-1236-1-ND" H 6810 3760 50  0001 C CNN "Digi-Key PN"
	1    6810 3760
	0    -1   -1   0   
$EndComp
Wire Wire Line
	6660 3760 6580 3760
Wire Wire Line
	6500 3860 6580 3860
Wire Wire Line
	6580 3860 6580 3760
Connection ~ 6580 3760
Wire Wire Line
	6580 3760 6500 3760
Wire Wire Line
	6500 4060 7040 4060
Wire Wire Line
	7040 4060 7040 3760
Wire Wire Line
	7040 3760 6960 3760
NoConn ~ 6500 4360
$Comp
L power:GND #PWR0410
U 1 1 5CA2A2D5
P 4420 5440
F 0 "#PWR0410" H 4420 5190 50  0001 C CNN
F 1 "GND" H 4420 5290 50  0000 C CNN
F 2 "" H 4420 5440 50  0001 C CNN
F 3 "" H 4420 5440 50  0001 C CNN
	1    4420 5440
	1    0    0    -1  
$EndComp
Wire Wire Line
	4420 5440 4420 5360
Wire Wire Line
	4420 5360 4500 5360
$Comp
L power:GND #PWR0412
U 1 1 5CA2A905
P 5500 5610
F 0 "#PWR0412" H 5500 5360 50  0001 C CNN
F 1 "GND" H 5500 5460 50  0000 C CNN
F 2 "" H 5500 5610 50  0001 C CNN
F 3 "" H 5500 5610 50  0001 C CNN
	1    5500 5610
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:C_Custom C402
U 1 1 5CA2AE96
P 5100 5840
F 0 "C402" H 5125 5940 50  0000 L CNN
F 1 "2.2nF" H 5125 5740 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 5138 5690 50  0001 C CNN
F 3 "" H 5125 5940 50  0001 C CNN
F 4 "0603" H 4950 5940 50  0000 R CNN "display_footprint"
F 5 "50V" H 4950 5840 50  0000 R CNN "Voltage"
F 6 "X7R" H 4950 5740 50  0000 R CNN "Dielectric"
F 7 "399-1280-1-ND" H 5525 6340 60  0001 C CNN "Digi-Key PN"
	1    5100 5840
	1    0    0    -1  
$EndComp
Wire Wire Line
	5100 5690 5100 5610
$Comp
L Custom_Library:R_Custom R411
U 1 1 5CA2E930
P 5900 5840
F 0 "R411" H 5970 5970 50  0000 L CNN
F 1 "1k" V 5900 5840 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" H 5900 5840 50  0001 C CNN
F 3 "" H 5900 5840 50  0001 C CNN
F 4 "0603" H 5970 5890 50  0000 L CNN "display_footprint"
F 5 "1%" H 5970 5800 50  0000 L CNN "Tolerance"
F 6 "1/10W" H 5970 5710 50  0000 L CNN "Wattage"
F 7 "RMCF0603FT1K00CT-ND" H 6200 6240 60  0001 C CNN "Digi-Key PN"
	1    5900 5840
	1    0    0    -1  
$EndComp
Wire Wire Line
	5900 5690 5900 5610
$Comp
L power:GND #PWR0411
U 1 1 5CA2FE4F
P 5100 5990
F 0 "#PWR0411" H 5100 5740 50  0001 C CNN
F 1 "GND" H 5100 5840 50  0000 C CNN
F 2 "" H 5100 5990 50  0001 C CNN
F 3 "" H 5100 5990 50  0001 C CNN
	1    5100 5990
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0413
U 1 1 5CA30100
P 5900 5990
F 0 "#PWR0413" H 5900 5740 50  0001 C CNN
F 1 "GND" H 5900 5840 50  0000 C CNN
F 2 "" H 5900 5990 50  0001 C CNN
F 3 "" H 5900 5990 50  0001 C CNN
	1    5900 5990
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:R_Custom R414
U 1 1 5CA306F5
P 7270 4630
F 0 "R414" H 7340 4760 50  0000 L CNN
F 1 "931k" V 7270 4630 40  0000 C CNN
F 2 "Resistors_SMD:R_0603" H 7270 4630 50  0001 C CNN
F 3 "" H 7270 4630 50  0001 C CNN
F 4 "0603" H 7340 4680 50  0000 L CNN "display_footprint"
F 5 "1%" H 7340 4590 50  0000 L CNN "Tolerance"
F 6 "1/10W" H 7340 4500 50  0000 L CNN "Wattage"
F 7 "P931KHCT-ND" H 7570 5030 60  0001 C CNN "Digi-Key PN"
	1    7270 4630
	1    0    0    -1  
$EndComp
Wire Wire Line
	6500 4860 7270 4860
Wire Wire Line
	7270 4860 7270 4780
$Comp
L Custom_Library:R_Custom R415
U 1 1 5CA31370
P 7270 5090
F 0 "R415" H 7340 5220 50  0000 L CNN
F 1 "392k" V 7270 5090 40  0000 C CNN
F 2 "Resistors_SMD:R_0603" H 7270 5090 50  0001 C CNN
F 3 "" H 7270 5090 50  0001 C CNN
F 4 "0603" H 7340 5140 50  0000 L CNN "display_footprint"
F 5 "1%" H 7340 5050 50  0000 L CNN "Tolerance"
F 6 "1/10W" H 7340 4960 50  0000 L CNN "Wattage"
F 7 "RMCF0603FT392KCT-ND" H 7570 5490 60  0001 C CNN "Digi-Key PN"
	1    7270 5090
	1    0    0    -1  
$EndComp
Wire Wire Line
	7270 4480 7270 3760
Wire Wire Line
	7270 3760 7040 3760
Connection ~ 7040 3760
Wire Wire Line
	7270 4940 7270 4860
Connection ~ 7270 4860
$Comp
L power:GND #PWR0415
U 1 1 5CA35D25
P 7270 5240
F 0 "#PWR0415" H 7270 4990 50  0001 C CNN
F 1 "GND" H 7270 5090 50  0000 C CNN
F 2 "" H 7270 5240 50  0001 C CNN
F 3 "" H 7270 5240 50  0001 C CNN
	1    7270 5240
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:CP1_Alum_Custom C404
U 1 1 5CA36742
P 7730 4060
F 0 "C404" H 7755 4160 50  0000 L CNN
F 1 "10F" H 7755 3960 50  0000 L CNN
F 2 "Custom Footprints Library:SCCS30B106PRB" H 7730 4060 50  0001 C CNN
F 3 "" H 7755 4160 50  0001 C CNN
F 4 "SCC" H 7580 3960 50  0000 R CNN "display_footprint"
F 5 "2.7V" H 7580 4160 50  0000 R CNN "Voltage"
F 6 "478-10015-ND" H 7730 4060 50  0001 C CNN "Digi-Key PN"
	1    7730 4060
	1    0    0    -1  
$EndComp
Wire Wire Line
	7730 3910 7730 3760
Wire Wire Line
	7730 3760 7270 3760
Connection ~ 7270 3760
$Comp
L power:GND #PWR0418
U 1 1 5CA36C0E
P 7730 4210
F 0 "#PWR0418" H 7730 3960 50  0001 C CNN
F 1 "GND" H 7730 4060 50  0000 C CNN
F 2 "" H 7730 4210 50  0001 C CNN
F 3 "" H 7730 4210 50  0001 C CNN
	1    7730 4210
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:R_Custom R412
U 1 1 5CA37283
P 7270 2730
F 0 "R412" H 7340 2860 50  0000 L CNN
F 1 "1.07M" V 7270 2730 40  0000 C CNN
F 2 "Resistors_SMD:R_0603" H 7270 2730 50  0001 C CNN
F 3 "" H 7270 2730 50  0001 C CNN
F 4 "0603" H 7340 2780 50  0000 L CNN "display_footprint"
F 5 "1%" H 7340 2690 50  0000 L CNN "Tolerance"
F 6 "1/10W" H 7340 2600 50  0000 L CNN "Wattage"
F 7 "RMCF0603FT1M07CT-ND" H 7570 3130 60  0001 C CNN "Digi-Key PN"
	1    7270 2730
	1    0    0    -1  
$EndComp
Wire Wire Line
	6500 2960 6580 2960
Wire Wire Line
	7270 2960 7270 2880
$Comp
L Custom_Library:R_Custom R413
U 1 1 5CA37293
P 7270 3190
F 0 "R413" H 7340 3320 50  0000 L CNN
F 1 "340k" V 7270 3190 40  0000 C CNN
F 2 "Resistors_SMD:R_0603" H 7270 3190 50  0001 C CNN
F 3 "" H 7270 3190 50  0001 C CNN
F 4 "0603" H 7340 3240 50  0000 L CNN "display_footprint"
F 5 "1%" H 7340 3150 50  0000 L CNN "Tolerance"
F 6 "1/10W" H 7340 3060 50  0000 L CNN "Wattage"
F 7 "P340KHCT-ND" H 7570 3590 60  0001 C CNN "Digi-Key PN"
	1    7270 3190
	1    0    0    -1  
$EndComp
Wire Wire Line
	7270 3040 7270 2960
Connection ~ 7270 2960
$Comp
L power:GND #PWR0414
U 1 1 5CA372A0
P 7270 3340
F 0 "#PWR0414" H 7270 3090 50  0001 C CNN
F 1 "GND" H 7270 3190 50  0000 C CNN
F 2 "" H 7270 3340 50  0001 C CNN
F 3 "" H 7270 3340 50  0001 C CNN
	1    7270 3340
	1    0    0    -1  
$EndComp
Wire Wire Line
	6500 3060 6580 3060
Wire Wire Line
	6580 3060 6580 2960
Connection ~ 6580 2960
Wire Wire Line
	6580 2960 7270 2960
Wire Wire Line
	5750 2430 5750 2510
Wire Wire Line
	6150 2510 6150 2130
Wire Wire Line
	6150 2130 5950 2130
Wire Wire Line
	6250 2510 6250 2130
Wire Wire Line
	6250 2130 6150 2130
Connection ~ 6150 2130
Wire Wire Line
	6250 2130 7270 2130
Wire Wire Line
	7270 2130 7270 2580
Connection ~ 6250 2130
$Comp
L power:GND #PWR0416
U 1 1 5CA3EFD9
P 7730 2510
F 0 "#PWR0416" H 7730 2260 50  0001 C CNN
F 1 "GND" H 7730 2360 50  0000 C CNN
F 2 "" H 7730 2510 50  0001 C CNN
F 3 "" H 7730 2510 50  0001 C CNN
	1    7730 2510
	1    0    0    -1  
$EndComp
Wire Wire Line
	7730 2210 7730 2130
Wire Wire Line
	7730 2130 7270 2130
Connection ~ 7270 2130
Wire Wire Line
	5550 2130 5250 2130
Wire Wire Line
	5250 2130 5250 2510
$Comp
L Custom_Library:R_Custom R409
U 1 1 5CA40562
P 5000 2130
F 0 "R409" V 4900 2130 50  0000 C CNN
F 1 "12m" V 5000 2130 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 5000 2130 50  0001 C CNN
F 3 "" H 5000 2130 50  0001 C CNN
F 4 "0805" V 5100 2130 50  0000 C CNN "display_footprint"
F 5 "1%" V 5200 2130 50  0000 C CNN "Tolerance"
F 6 "1/2W" V 5300 2130 50  0000 C CNN "Wattage"
F 7 "408-1545-1-ND" H 5300 2530 60  0001 C CNN "Digi-Key PN"
	1    5000 2130
	0    1    -1   0   
$EndComp
Wire Wire Line
	5150 2130 5250 2130
Connection ~ 5250 2130
Wire Wire Line
	4850 2130 4750 2130
Wire Wire Line
	4750 2130 4750 2510
Wire Wire Line
	4750 2130 4420 2130
Wire Wire Line
	3770 2130 3770 2210
Connection ~ 4750 2130
$Comp
L power:GND #PWR0408
U 1 1 5CA45142
P 3770 2510
F 0 "#PWR0408" H 3770 2260 50  0001 C CNN
F 1 "GND" H 3770 2360 50  0000 C CNN
F 2 "" H 3770 2510 50  0001 C CNN
F 3 "" H 3770 2510 50  0001 C CNN
	1    3770 2510
	1    0    0    -1  
$EndComp
Wire Wire Line
	4500 2960 4420 2960
Wire Wire Line
	4420 2960 4420 2130
Connection ~ 4420 2130
Wire Wire Line
	4420 2130 4170 2130
$Comp
L power:GND #PWR0409
U 1 1 5CA47A97
P 4170 3740
F 0 "#PWR0409" H 4170 3490 50  0001 C CNN
F 1 "GND" H 4170 3590 50  0000 C CNN
F 2 "" H 4170 3740 50  0001 C CNN
F 3 "" H 4170 3740 50  0001 C CNN
	1    4170 3740
	-1   0    0    -1  
$EndComp
Connection ~ 4170 3360
Wire Wire Line
	4170 3440 4170 3360
$Comp
L Custom_Library:R_Custom R408
U 1 1 5CA47A8A
P 4170 3590
F 0 "R408" H 4240 3720 50  0000 L CNN
F 1 "75k" V 4170 3590 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" H 4170 3590 50  0001 C CNN
F 3 "" H 4170 3590 50  0001 C CNN
F 4 "0603" H 4240 3640 50  0000 L CNN "display_footprint"
F 5 "1%" H 4240 3550 50  0000 L CNN "Tolerance"
F 6 "1/10W" H 4240 3460 50  0000 L CNN "Wattage"
F 7 "RMCF0603FT75K0CT-ND" H 4470 3990 60  0001 C CNN "Digi-Key PN"
	1    4170 3590
	-1   0    0    -1  
$EndComp
Wire Wire Line
	4170 3360 4170 3280
Wire Wire Line
	4500 3360 4170 3360
Wire Wire Line
	4170 2130 4170 2980
Connection ~ 4170 2130
Wire Wire Line
	4170 2130 3770 2130
$Comp
L Custom_Library:+3.3V_BCKP #PWR0421
U 1 1 5CA5DF8A
P 9710 2050
F 0 "#PWR0421" H 9710 1900 50  0001 C CNN
F 1 "+3.3V_BCKP" H 9710 2190 50  0000 C CNN
F 2 "" H 9710 2050 50  0000 C CNN
F 3 "" H 9710 2050 50  0000 C CNN
	1    9710 2050
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0407
U 1 1 5CA5FB0E
P 3770 2050
F 0 "#PWR0407" H 3770 1900 50  0001 C CNN
F 1 "+3.3V" H 3770 2190 50  0000 C CNN
F 2 "" H 3770 2050 50  0001 C CNN
F 3 "" H 3770 2050 50  0001 C CNN
	1    3770 2050
	1    0    0    -1  
$EndComp
Wire Wire Line
	3770 2050 3770 2130
Connection ~ 3770 2130
$Comp
L Custom_Library:R_Custom R406
U 1 1 5CA6EFB0
P 3610 4830
F 0 "R406" H 3680 4960 50  0000 L CNN
F 1 "2M" V 3610 4830 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" H 3610 4830 50  0001 C CNN
F 3 "" H 3610 4830 50  0001 C CNN
F 4 "0603" H 3680 4880 50  0000 L CNN "display_footprint"
F 5 "1%" H 3680 4790 50  0000 L CNN "Tolerance"
F 6 "1/10W" H 3680 4700 50  0000 L CNN "Wattage"
F 7 "311-2.00MHRCT-ND" H 3610 4830 50  0001 C CNN "Digi-Key PN"
	1    3610 4830
	-1   0    0    -1  
$EndComp
$Comp
L Custom_Library:+3.3V_BCKP #PWR0405
U 1 1 5CA766EA
P 3610 3680
F 0 "#PWR0405" H 3610 3530 50  0001 C CNN
F 1 "+3.3V_BCKP" H 3610 3820 50  0000 C CNN
F 2 "" H 3610 3680 50  0000 C CNN
F 3 "" H 3610 3680 50  0000 C CNN
	1    3610 3680
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:+3.3V_BCKP #PWR0403
U 1 1 5CA766F4
P 3130 3680
F 0 "#PWR0403" H 3130 3530 50  0001 C CNN
F 1 "+3.3V_BCKP" H 3130 3820 50  0000 C CNN
F 2 "" H 3130 3680 50  0000 C CNN
F 3 "" H 3130 3680 50  0000 C CNN
	1    3130 3680
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:+3.3V_BCKP #PWR0402
U 1 1 5CA7A712
P 2650 3680
F 0 "#PWR0402" H 2650 3530 50  0001 C CNN
F 1 "+3.3V_BCKP" H 2650 3820 50  0000 C CNN
F 2 "" H 2650 3680 50  0000 C CNN
F 3 "" H 2650 3680 50  0000 C CNN
	1    2650 3680
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:+3.3V_BCKP #PWR0401
U 1 1 5CA7A71C
P 2170 3680
F 0 "#PWR0401" H 2170 3530 50  0001 C CNN
F 1 "+3.3V_BCKP" H 2170 3820 50  0000 C CNN
F 2 "" H 2170 3680 50  0000 C CNN
F 3 "" H 2170 3680 50  0000 C CNN
	1    2170 3680
	1    0    0    -1  
$EndComp
Wire Wire Line
	4500 4060 2170 4060
Wire Wire Line
	4500 4160 2650 4160
Wire Wire Line
	4500 4260 3130 4260
Wire Wire Line
	4500 4360 3610 4360
Wire Wire Line
	4500 4460 1910 4460
Wire Wire Line
	2170 3980 2170 4060
Connection ~ 2170 4060
Wire Wire Line
	2170 4060 1910 4060
Wire Wire Line
	2650 3980 2650 4160
Connection ~ 2650 4160
Wire Wire Line
	2650 4160 1910 4160
Wire Wire Line
	3130 3980 3130 4260
Connection ~ 3130 4260
Wire Wire Line
	3130 4260 1910 4260
Wire Wire Line
	3610 3980 3610 4360
Connection ~ 3610 4360
Wire Wire Line
	3610 4360 1910 4360
Wire Wire Line
	3130 4980 3130 5060
Wire Wire Line
	3130 5060 4500 5060
Wire Wire Line
	3610 4980 3610 5160
Wire Wire Line
	3610 5160 4500 5160
Text GLabel 1910 4060 0    40   Output ~ 0
~BCKP_PFO
Text GLabel 1910 4160 0    50   Output ~ 0
BCKP_SYSGD
Text GLabel 1910 4260 0    50   Output ~ 0
BCKP_CAPGD
Text GLabel 1910 4360 0    40   Output ~ 0
~BCKP_CAPFLT
Text GLabel 1910 4460 0    50   Output ~ 0
BCKP_IMON
$Comp
L Custom_Library:R_Custom R407
U 1 1 5CA47A7A
P 4170 3130
F 0 "R407" H 4240 3260 50  0000 L CNN
F 1 "121k" V 4170 3130 40  0000 C CNN
F 2 "Resistors_SMD:R_0603" H 4170 3130 50  0001 C CNN
F 3 "" H 4170 3130 50  0001 C CNN
F 4 "0603" H 4240 3180 50  0000 L CNN "display_footprint"
F 5 "1%" H 4240 3090 50  0000 L CNN "Tolerance"
F 6 "1/10W" H 4240 3000 50  0000 L CNN "Wattage"
F 7 "RMCF0603FT121KCT-ND" H 4470 3530 60  0001 C CNN "Digi-Key PN"
	1    4170 3130
	-1   0    0    -1  
$EndComp
$Comp
L Custom_Library:CP_Tant_Custom C?
U 1 1 5CAC184B
P 9710 2360
AR Path="/5C81AEEA/5CAC184B" Ref="C?"  Part="1" 
AR Path="/5C81AEFF/5CAC184B" Ref="C?"  Part="1" 
AR Path="/5A557C58/5CAC184B" Ref="C?"  Part="1" 
AR Path="/5CE11002/5CAC184B" Ref="C407"  Part="1" 
F 0 "C407" H 9735 2460 50  0000 L CNN
F 1 "100uF" H 9735 2260 50  0000 L CNN
F 2 "Capacitors_Tantalum_SMD:CP_Tantalum_Case-D_EIA-7343-31_Reflow" H 9748 2210 50  0001 C CNN
F 3 "" H 9735 2460 50  0001 C CNN
F 4 "478-3919-1-ND" H 9710 2360 50  0001 C CNN "Digi-Key PN"
F 5 "7343" H 9560 2460 50  0000 R CNN "display_footprint"
F 6 "16V" H 9560 2360 50  0000 R CNN "Voltage"
F 7 "20%" H 9560 2260 50  0000 R CNN "Tolerance"
	1    9710 2360
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5CAC1851
P 9710 2510
AR Path="/5C81AEEA/5CAC1851" Ref="#PWR?"  Part="1" 
AR Path="/5C81AEFF/5CAC1851" Ref="#PWR?"  Part="1" 
AR Path="/5A557C58/5CAC1851" Ref="#PWR?"  Part="1" 
AR Path="/5CE11002/5CAC1851" Ref="#PWR0422"  Part="1" 
F 0 "#PWR0422" H 9710 2260 50  0001 C CNN
F 1 "GND" H 9710 2360 50  0000 C CNN
F 2 "" H 9710 2510 50  0001 C CNN
F 3 "" H 9710 2510 50  0001 C CNN
	1    9710 2510
	1    0    0    -1  
$EndComp
Wire Wire Line
	9710 2050 9710 2130
Connection ~ 9710 2130
Wire Wire Line
	9710 2130 9710 2210
Connection ~ 7730 2130
$Comp
L Custom_Library:C_Custom C403
U 1 1 5CAC7591
P 7730 2360
F 0 "C403" H 7755 2460 50  0000 L CNN
F 1 "10uF" H 7755 2260 50  0000 L CNN
F 2 "Capacitors_SMD:C_1206" H 7730 2360 50  0001 C CNN
F 3 "" H 7755 2460 50  0001 C CNN
F 4 "1206" H 7580 2260 50  0000 R CNN "display_footprint"
F 5 "10V" H 7580 2460 50  0000 R CNN "Voltage"
F 6 "X7R" H 7510 2360 50  0000 C CNN "Dielectric"
F 7 "1276-6641-1-ND" H 7730 2360 50  0001 C CNN "Digi-Key PN"
	1    7730 2360
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:C_Custom C401
U 1 1 5CAC83FA
P 3770 2360
F 0 "C401" H 3795 2460 50  0000 L CNN
F 1 "10uF" H 3795 2260 50  0000 L CNN
F 2 "Capacitors_SMD:C_1206" H 3770 2360 50  0001 C CNN
F 3 "" H 3795 2460 50  0001 C CNN
F 4 "1206" H 3620 2260 50  0000 R CNN "display_footprint"
F 5 "10V" H 3620 2460 50  0000 R CNN "Voltage"
F 6 "X7R" H 3550 2360 50  0000 C CNN "Dielectric"
F 7 "1276-6641-1-ND" H 3770 2360 50  0001 C CNN "Digi-Key PN"
	1    3770 2360
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:TP TP?
U 1 1 5CAD50A3
P 8080 3680
AR Path="/5C81AEFF/5CAD50A3" Ref="TP?"  Part="1" 
AR Path="/5C81AEEA/5CAD50A3" Ref="TP?"  Part="1" 
AR Path="/5A557C58/5CAD50A3" Ref="TP?"  Part="1" 
AR Path="/5CE11002/5CAD50A3" Ref="TP402"  Part="1" 
F 0 "TP402" H 8080 3830 50  0000 C CNN
F 1 "TP" H 8080 3830 50  0001 C CNN
F 2 "Custom Footprints Library:Test_Point" H 8080 3680 60  0001 C CNN
F 3 "" H 8080 3680 60  0000 C CNN
	1    8080 3680
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:VTANK #PWR0417
U 1 1 5CAD8742
P 7730 3680
F 0 "#PWR0417" H 7730 3530 50  0001 C CNN
F 1 "VTANK" H 7730 3830 50  0000 C CNN
F 2 "" H 7730 3680 50  0001 C CNN
F 3 "" H 7730 3680 50  0001 C CNN
	1    7730 3680
	1    0    0    -1  
$EndComp
Wire Wire Line
	7730 3680 7730 3760
Connection ~ 7730 3760
Wire Wire Line
	8080 3680 8080 3760
Wire Wire Line
	8080 3760 7730 3760
$Comp
L Custom_Library:TP TP?
U 1 1 5CADD5C5
P 7730 2050
AR Path="/5C81AEFF/5CADD5C5" Ref="TP?"  Part="1" 
AR Path="/5C81AEEA/5CADD5C5" Ref="TP?"  Part="1" 
AR Path="/5A557C58/5CADD5C5" Ref="TP?"  Part="1" 
AR Path="/5CE11002/5CADD5C5" Ref="TP401"  Part="1" 
F 0 "TP401" H 7730 2200 50  0000 C CNN
F 1 "TP" H 7730 2200 50  0001 C CNN
F 2 "Custom Footprints Library:Test_Point" H 7730 2050 60  0001 C CNN
F 3 "" H 7730 2050 60  0000 C CNN
	1    7730 2050
	1    0    0    -1  
$EndComp
Wire Wire Line
	7730 2130 7730 2050
$Comp
L Custom_Library:+3.3V_BCKP #PWR0406
U 1 1 5CBD14F4
P 3610 4680
F 0 "#PWR0406" H 3610 4530 50  0001 C CNN
F 1 "+3.3V_BCKP" H 3610 4820 50  0000 C CNN
F 2 "" H 3610 4680 50  0000 C CNN
F 3 "" H 3610 4680 50  0000 C CNN
	1    3610 4680
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:+3.3V_BCKP #PWR0404
U 1 1 5CBD1A99
P 3130 4680
F 0 "#PWR0404" H 3130 4530 50  0001 C CNN
F 1 "+3.3V_BCKP" H 3130 4820 50  0000 C CNN
F 2 "" H 3130 4680 50  0000 C CNN
F 3 "" H 3130 4680 50  0000 C CNN
	1    3130 4680
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:R_Custom R404
U 1 1 5CB7B8C5
P 3130 4830
F 0 "R404" H 3200 4960 50  0000 L CNN
F 1 "2M" V 3130 4830 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" H 3130 4830 50  0001 C CNN
F 3 "" H 3130 4830 50  0001 C CNN
F 4 "0603" H 3200 4880 50  0000 L CNN "display_footprint"
F 5 "1%" H 3200 4790 50  0000 L CNN "Tolerance"
F 6 "1/10W" H 3200 4700 50  0000 L CNN "Wattage"
F 7 "311-2.00MHRCT-ND" H 3130 4830 50  0001 C CNN "Digi-Key PN"
	1    3130 4830
	-1   0    0    -1  
$EndComp
$Comp
L Custom_Library:R_Custom R405
U 1 1 5CB7BC6A
P 3610 3830
F 0 "R405" H 3680 3960 50  0000 L CNN
F 1 "2M" V 3610 3830 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" H 3610 3830 50  0001 C CNN
F 3 "" H 3610 3830 50  0001 C CNN
F 4 "0603" H 3680 3880 50  0000 L CNN "display_footprint"
F 5 "1%" H 3680 3790 50  0000 L CNN "Tolerance"
F 6 "1/10W" H 3680 3700 50  0000 L CNN "Wattage"
F 7 "311-2.00MHRCT-ND" H 3610 3830 50  0001 C CNN "Digi-Key PN"
	1    3610 3830
	-1   0    0    -1  
$EndComp
$Comp
L Custom_Library:R_Custom R403
U 1 1 5CB7C2B7
P 3130 3830
F 0 "R403" H 3200 3960 50  0000 L CNN
F 1 "2M" V 3130 3830 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" H 3130 3830 50  0001 C CNN
F 3 "" H 3130 3830 50  0001 C CNN
F 4 "0603" H 3200 3880 50  0000 L CNN "display_footprint"
F 5 "1%" H 3200 3790 50  0000 L CNN "Tolerance"
F 6 "1/10W" H 3200 3700 50  0000 L CNN "Wattage"
F 7 "311-2.00MHRCT-ND" H 3130 3830 50  0001 C CNN "Digi-Key PN"
	1    3130 3830
	-1   0    0    -1  
$EndComp
$Comp
L Custom_Library:R_Custom R402
U 1 1 5CB7C7DC
P 2650 3830
F 0 "R402" H 2720 3960 50  0000 L CNN
F 1 "2M" V 2650 3830 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" H 2650 3830 50  0001 C CNN
F 3 "" H 2650 3830 50  0001 C CNN
F 4 "0603" H 2720 3880 50  0000 L CNN "display_footprint"
F 5 "1%" H 2720 3790 50  0000 L CNN "Tolerance"
F 6 "1/10W" H 2720 3700 50  0000 L CNN "Wattage"
F 7 "311-2.00MHRCT-ND" H 2650 3830 50  0001 C CNN "Digi-Key PN"
	1    2650 3830
	-1   0    0    -1  
$EndComp
$Comp
L Custom_Library:R_Custom R401
U 1 1 5CB7CBA1
P 2170 3830
F 0 "R401" H 2240 3960 50  0000 L CNN
F 1 "2M" V 2170 3830 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" H 2170 3830 50  0001 C CNN
F 3 "" H 2170 3830 50  0001 C CNN
F 4 "0603" H 2240 3880 50  0000 L CNN "display_footprint"
F 5 "1%" H 2240 3790 50  0000 L CNN "Tolerance"
F 6 "1/10W" H 2240 3700 50  0000 L CNN "Wattage"
F 7 "311-2.00MHRCT-ND" H 2170 3830 50  0001 C CNN "Digi-Key PN"
	1    2170 3830
	-1   0    0    -1  
$EndComp
$Comp
L Custom_Library:R_Custom R410
U 1 1 5CBD88CC
P 5660 1510
F 0 "R410" V 5560 1510 50  0000 C CNN
F 1 "0" V 5660 1510 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 5660 1510 50  0001 C CNN
F 3 "" H 5660 1510 50  0001 C CNN
F 4 "2512" V 5760 1510 50  0000 C CNN "display_footprint"
F 5 "1%" V 5860 1510 50  0000 C CNN "Tolerance"
F 6 "1W" V 5960 1510 50  0000 C CNN "Wattage"
F 7 "DNP" V 5480 1510 50  0000 C CNN "Config"
	1    5660 1510
	0    1    -1   0   
$EndComp
Wire Wire Line
	5810 1510 6250 1510
Wire Wire Line
	6250 1510 6250 2130
Wire Wire Line
	5510 1510 4750 1510
Wire Wire Line
	4750 1510 4750 2130
Text GLabel 1910 5060 0    40   Input ~ 0
~BCKP_CHGEN
Text GLabel 1910 5160 0    40   Input ~ 0
~BCKP_BSTEN
Wire Wire Line
	1910 5060 3130 5060
Connection ~ 3130 5060
Wire Wire Line
	1910 5160 3610 5160
Connection ~ 3610 5160
$Comp
L Custom_Library:IPC100N04S51R7ATMA1 Q?
U 1 1 5CE30775
P 5750 2230
AR Path="/5CD35FB7/5CE30775" Ref="Q?"  Part="1" 
AR Path="/5CE11002/5CE30775" Ref="Q401"  Part="1" 
F 0 "Q401" V 6093 2230 50  0000 C CNN
F 1 "IPC100N04S51R2ATMA1" V 6002 2230 50  0000 C CNN
F 2 "TO_SOT_Packages_SMD:TDSON-8-1" H 5950 2155 50  0001 L CIN
F 3 "https://www.infineon.com/dgdl/Infineon-IPC100N04S5-1R7-DS-v01_02-EN.pdf?fileId=5546d46253f65057015419c2835252f3" H 5950 2305 50  0001 L CNN
F 4 "IPC100N04S51R2ATMA1CT-ND" H 6150 2505 60  0001 C CNN "Digi-Key PN"
	1    5750 2230
	0    1    -1   0   
$EndComp
$Comp
L Custom_Library:C_Custom C?
U 1 1 5CE3C6DF
P 9050 2360
AR Path="/5BAAE10E/5CE3C6DF" Ref="C?"  Part="1" 
AR Path="/5BE5222A/5CE3C6DF" Ref="C?"  Part="1" 
AR Path="/5CD35FCB/5CE3C6DF" Ref="C?"  Part="1" 
AR Path="/5CE11002/5CE3C6DF" Ref="C406"  Part="1" 
F 0 "C406" H 9075 2460 50  0000 L CNN
F 1 "47uF" H 9075 2260 50  0000 L CNN
F 2 "Capacitors_SMD:C_1210" H 9088 2210 50  0001 C CNN
F 3 "" H 9075 2460 50  0001 C CNN
F 4 "490-4844-1-ND" H 9050 2360 50  0001 C CNN "Digi-Key PN"
F 5 "1210" H 8900 2460 50  0000 R CNN "display_footprint"
F 6 "6.3V" H 8900 2360 50  0000 R CNN "Voltage"
F 7 "X7R" H 8900 2260 50  0000 R CNN "Dielectric"
	1    9050 2360
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0419
U 1 1 5CE3C6E5
P 8390 2510
F 0 "#PWR0419" H 8390 2260 50  0001 C CNN
F 1 "GND" H 8390 2360 50  0000 C CNN
F 2 "" H 8390 2510 50  0001 C CNN
F 3 "" H 8390 2510 50  0001 C CNN
	1    8390 2510
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:C_Custom C?
U 1 1 5CE3C6EF
P 8390 2360
AR Path="/5BAAE10E/5CE3C6EF" Ref="C?"  Part="1" 
AR Path="/5BE5222A/5CE3C6EF" Ref="C?"  Part="1" 
AR Path="/5CD35FCB/5CE3C6EF" Ref="C?"  Part="1" 
AR Path="/5CE11002/5CE3C6EF" Ref="C405"  Part="1" 
F 0 "C405" H 8415 2460 50  0000 L CNN
F 1 "47uF" H 8415 2260 50  0000 L CNN
F 2 "Capacitors_SMD:C_1210" H 8428 2210 50  0001 C CNN
F 3 "" H 8415 2460 50  0001 C CNN
F 4 "490-4844-1-ND" H 8390 2360 50  0001 C CNN "Digi-Key PN"
F 5 "1210" H 8240 2460 50  0000 R CNN "display_footprint"
F 6 "6.3V" H 8240 2360 50  0000 R CNN "Voltage"
F 7 "X7R" H 8240 2260 50  0000 R CNN "Dielectric"
	1    8390 2360
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0420
U 1 1 5CE3C6F5
P 9050 2510
F 0 "#PWR0420" H 9050 2260 50  0001 C CNN
F 1 "GND" H 9050 2360 50  0000 C CNN
F 2 "" H 9050 2510 50  0001 C CNN
F 3 "" H 9050 2510 50  0001 C CNN
	1    9050 2510
	1    0    0    -1  
$EndComp
Wire Wire Line
	7730 2130 8390 2130
Wire Wire Line
	9050 2210 9050 2130
Connection ~ 9050 2130
Wire Wire Line
	9050 2130 9710 2130
Wire Wire Line
	8390 2210 8390 2130
Connection ~ 8390 2130
Wire Wire Line
	8390 2130 9050 2130
$Comp
L power:PWR_FLAG #FLG0101
U 1 1 5D3F0B1A
P 8490 3680
F 0 "#FLG0101" H 8490 3755 50  0001 C CNN
F 1 "PWR_FLAG" H 8490 3830 50  0000 C CNN
F 2 "" H 8490 3680 50  0001 C CNN
F 3 "~" H 8490 3680 50  0001 C CNN
	1    8490 3680
	1    0    0    -1  
$EndComp
Wire Wire Line
	8490 3680 8490 3760
Wire Wire Line
	8490 3760 8080 3760
Connection ~ 8080 3760
$EndSCHEMATC
