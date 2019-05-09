EESchema Schematic File Version 4
LIBS:Electronic_Calendar-cache
EELAYER 29 0
EELAYER END
$Descr A 11000 8500
encoding utf-8
Sheet 3 13
Title "Electronic Display Logic Board"
Date "2018-12-15"
Rev "A"
Comp "Marquette University Senior Design 2018/2019 Group E44"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text Notes 550  700  0    100  ~ 20
03. +3.3V Power Supply
$Comp
L Custom_Library:C_Custom C?
U 1 1 5C0A8457
P 5100 3100
AR Path="/5BAAE16C/5C0A8457" Ref="C?"  Part="1" 
AR Path="/5BB181D8/5C0A8457" Ref="C?"  Part="1" 
AR Path="/5BB2595E/5C0A8457" Ref="C?"  Part="1" 
AR Path="/5BAAE0FA/5C0A8457" Ref="C?"  Part="1" 
AR Path="/5BB86F23/5C0A8457" Ref="C?"  Part="1" 
AR Path="/5BAAE10E/5C0A8457" Ref="C?"  Part="1" 
AR Path="/5CD35FCB/5C0A8457" Ref="C?"  Part="1" 
F 0 "C?" H 5125 3200 50  0000 L CNN
F 1 "0.1uF" H 5125 3000 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 5138 2950 50  0001 C CNN
F 3 "" H 5125 3200 50  0001 C CNN
F 4 "0603" H 4950 3200 50  0000 R CNN "display_footprint"
F 5 "50V" H 4950 3100 50  0000 R CNN "Voltage"
F 6 "X7R" H 4950 3000 50  0000 R CNN "Dielectric"
F 7 "311-1344-1-ND" H 5525 3600 60  0001 C CNN "Digi-Key PN"
	1    5100 3100
	1    0    0    -1  
$EndComp
Wire Wire Line
	5100 2950 5100 2910
Wire Wire Line
	5100 2910 4750 2910
Wire Wire Line
	4750 3310 4830 3310
Wire Wire Line
	5100 3310 5100 3250
$Comp
L Diode:MBR0530 D?
U 1 1 5C0A84DD
P 5100 2700
F 0 "D?" V 5146 2621 50  0000 R CNN
F 1 "MBR0530" V 5055 2621 50  0000 R CNN
F 2 "Diodes_SMD:D_SOD-123" H 5100 2525 50  0001 C CNN
F 3 "http://www.mccsemi.com/up_pdf/MBR0520~MBR0580(SOD123).pdf" H 5100 2700 50  0001 C CNN
F 4 "MBR0530T1GOSCT-ND" H -590 10  50  0001 C CNN "Digi-Key PN"
	1    5100 2700
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5100 2850 5100 2910
Connection ~ 5100 2910
Wire Wire Line
	5100 2550 5100 2510
Wire Wire Line
	5100 2510 4830 2510
$Comp
L Custom_Library:C_Custom C?
U 1 1 5C0AA7FF
P 6010 2740
AR Path="/5BE5222A/5C0AA7FF" Ref="C?"  Part="1" 
AR Path="/5BAAE10E/5C0AA7FF" Ref="C?"  Part="1" 
AR Path="/5CD35FCB/5C0AA7FF" Ref="C?"  Part="1" 
F 0 "C?" H 6035 2840 50  0000 L CNN
F 1 "2.2uF" H 6035 2640 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 6048 2590 50  0001 C CNN
F 3 "" H 6035 2840 50  0001 C CNN
F 4 "0805" H 5860 2840 50  0000 R CNN "display_footprint"
F 5 "16V" H 5860 2740 50  0000 R CNN "Voltage"
F 6 "X7R" H 5860 2640 50  0000 R CNN "Dielectric"
F 7 "445-5691-1-ND" H 6435 3240 60  0001 C CNN "Digi-Key PN"
	1    6010 2740
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5C0AA85D
P 6010 2890
F 0 "#PWR?" H 6010 2640 50  0001 C CNN
F 1 "GND" H 6010 2740 50  0000 C CNN
F 2 "" H 6010 2890 50  0001 C CNN
F 3 "" H 6010 2890 50  0001 C CNN
	1    6010 2890
	1    0    0    -1  
$EndComp
Wire Wire Line
	6010 2590 6010 2510
Wire Wire Line
	6010 2510 5100 2510
Connection ~ 5100 2510
Wire Wire Line
	4750 3410 4830 3410
Wire Wire Line
	4830 3410 4830 3310
Connection ~ 4830 3310
Wire Wire Line
	4830 3310 5100 3310
Wire Wire Line
	4750 3810 4830 3810
Wire Wire Line
	4830 3810 4830 3710
Connection ~ 4830 3410
Wire Wire Line
	4750 3510 4830 3510
Connection ~ 4830 3510
Wire Wire Line
	4830 3510 4830 3410
Wire Wire Line
	4750 3610 4830 3610
Connection ~ 4830 3610
Wire Wire Line
	4830 3610 4830 3510
Connection ~ 4830 3710
Wire Wire Line
	4750 3710 4830 3710
Wire Wire Line
	4830 3710 4830 3610
$Comp
L Custom_Library:L_Custom L?
U 1 1 5C0AF027
P 5620 3310
F 0 "L?" V 5570 3310 50  0000 C CNN
F 1 "0.47uH" V 5695 3310 50  0000 C CNN
F 2 "Inductors_SMD:L_Vishay_IHLP-2020" H 5620 3310 50  0001 C CNN
F 3 "" H 5620 3310 50  0001 C CNN
F 4 "541-1231-1-ND" H 5620 3310 50  0001 C CNN "Digi-Key PN"
F 5 "IHLP2020" V 5770 3310 50  0000 C CNN "display_footprint"
F 6 "14A" V 5870 3310 50  0000 C CNN "Ampacity"
F 7 "20%" V 5970 3310 50  0000 C CNN "Tolerance"
	1    5620 3310
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5470 3310 5100 3310
Connection ~ 5100 3310
Wire Wire Line
	7110 4400 7110 4210
$Comp
L Custom_Library:R_Custom R?
U 1 1 5C0AFC22
P 7110 4550
AR Path="/5BE5222A/5C0AFC22" Ref="R?"  Part="1" 
AR Path="/5BAAE10E/5C0AFC22" Ref="R?"  Part="1" 
AR Path="/5CD35FCB/5C0AFC22" Ref="R?"  Part="1" 
F 0 "R?" H 7050 4550 50  0000 R CNN
F 1 "22.1k" V 7110 4550 40  0000 C CNN
F 2 "Resistors_SMD:R_0603" H 7110 4550 50  0001 C CNN
F 3 "" H 7110 4550 50  0001 C CNN
F 4 "P22.1KHCT-ND" H 7110 4550 50  0001 C CNN "Digi-Key PN"
F 5 "0603" H 7180 4640 50  0000 L CNN "display_footprint"
F 6 "1%" H 7180 4550 50  0000 L CNN "Tolerance"
F 7 "1/10W" H 7180 4470 50  0000 L CNN "Wattage"
	1    7110 4550
	-1   0    0    -1  
$EndComp
$Comp
L Graphic:SYM_ESD_Large #SYM?
U 1 1 5C0AFC29
P 5770 4960
AR Path="/5BAAE0FA/5C0AFC29" Ref="#SYM?"  Part="1" 
AR Path="/5BB182B1/5C0AFC29" Ref="#SYM?"  Part="1" 
AR Path="/5BE5222A/5C0AFC29" Ref="#SYM?"  Part="1" 
AR Path="/5BAAE10E/5C0AFC29" Ref="#SYM?"  Part="1" 
AR Path="/5CD35FCB/5C0AFC29" Ref="#SYM?"  Part="1" 
F 0 "#SYM?" H 5770 5160 50  0001 C CNN
F 1 "SYM_ESD_Large" H 5770 4710 50  0001 C CNN
F 2 "" H 5765 4930 50  0001 C CNN
F 3 "~" H 5765 4930 50  0001 C CNN
	1    5770 4960
	1    0    0    -1  
$EndComp
Wire Wire Line
	4750 4110 6010 4110
Wire Wire Line
	6010 4110 6010 3310
Connection ~ 6010 3310
Wire Wire Line
	6010 3310 5770 3310
$Comp
L power:GND #PWR?
U 1 1 5C0B6118
P 3510 4650
AR Path="/5BE5222A/5C0B6118" Ref="#PWR?"  Part="1" 
AR Path="/5BAAE10E/5C0B6118" Ref="#PWR?"  Part="1" 
AR Path="/5CD35FCB/5C0B6118" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 3510 4400 50  0001 C CNN
F 1 "GND" H 3510 4500 50  0000 C CNN
F 2 "" H 3510 4650 50  0001 C CNN
F 3 "" H 3510 4650 50  0001 C CNN
	1    3510 4650
	1    0    0    -1  
$EndComp
Wire Wire Line
	3510 4650 3510 4610
Wire Wire Line
	3510 4610 3550 4610
$Comp
L Custom_Library:C_Custom C?
U 1 1 5C0BAECB
P 3260 3130
AR Path="/5BAAE16C/5C0BAECB" Ref="C?"  Part="1" 
AR Path="/5BB181D8/5C0BAECB" Ref="C?"  Part="1" 
AR Path="/5BB2595E/5C0BAECB" Ref="C?"  Part="1" 
AR Path="/5BE5222A/5C0BAECB" Ref="C?"  Part="1" 
AR Path="/5BAAE10E/5C0BAECB" Ref="C?"  Part="1" 
AR Path="/5CD35FCB/5C0BAECB" Ref="C?"  Part="1" 
F 0 "C?" H 3285 3230 50  0000 L CNN
F 1 "0.1uF" H 3285 3030 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 3298 2980 50  0001 C CNN
F 3 "" H 3285 3230 50  0001 C CNN
F 4 "0603" H 3110 3230 50  0000 R CNN "display_footprint"
F 5 "50V" H 3110 3130 50  0000 R CNN "Voltage"
F 6 "X7R" H 3110 3030 50  0000 R CNN "Dielectric"
F 7 "311-1344-1-ND" H 3685 3630 60  0001 C CNN "Digi-Key PN"
	1    3260 3130
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:C_Custom C?
U 1 1 5C0BAED6
P 2260 2740
AR Path="/5BAAE10E/5C0BAED6" Ref="C?"  Part="1" 
AR Path="/5BE5222A/5C0BAED6" Ref="C?"  Part="1" 
AR Path="/5CD35FCB/5C0BAED6" Ref="C?"  Part="1" 
F 0 "C?" H 2285 2840 50  0000 L CNN
F 1 "22uF" H 2285 2640 50  0000 L CNN
F 2 "Capacitors_SMD:C_2220" H 2298 2590 50  0001 C CNN
F 3 "" H 2285 2840 50  0001 C CNN
F 4 "445-1453-1-ND" H 2685 3240 60  0001 C CNN "Digi-Key PN"
F 5 "2220" H 2110 2840 50  0000 R CNN "display_footprint"
F 6 "25V" H 2110 2740 50  0000 R CNN "Voltage"
F 7 "X7R" H 2110 2640 50  0000 R CNN "Dielectric"
	1    2260 2740
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:R_Custom R?
U 1 1 5C0BDA59
P 3470 5640
AR Path="/5BE5222A/5C0BDA59" Ref="R?"  Part="1" 
AR Path="/5BAAE10E/5C0BDA59" Ref="R?"  Part="1" 
AR Path="/5CD35FCB/5C0BDA59" Ref="R?"  Part="1" 
F 0 "R?" H 3410 5640 50  0000 R CNN
F 1 "63.4k" V 3470 5640 40  0000 C CNN
F 2 "Resistors_SMD:R_0603" H 3470 5640 50  0001 C CNN
F 3 "" H 3470 5640 50  0001 C CNN
F 4 "541-63.4KHCT-ND" H 3470 5640 50  0001 C CNN "Digi-Key PN"
F 5 "0603" H 3540 5730 50  0000 L CNN "display_footprint"
F 6 "1%" H 3540 5640 50  0000 L CNN "Tolerance"
F 7 "1/10W" H 3540 5560 50  0000 L CNN "Wattage"
	1    3470 5640
	-1   0    0    -1  
$EndComp
Wire Wire Line
	3550 5410 3470 5410
Wire Wire Line
	3470 5410 3470 5490
Wire Wire Line
	2840 5490 2840 5010
Wire Wire Line
	2840 5010 3550 5010
$Comp
L Custom_Library:R_Custom R?
U 1 1 5C0C441F
P 4910 5720
AR Path="/5BE5222A/5C0C441F" Ref="R?"  Part="1" 
AR Path="/5BAAE10E/5C0C441F" Ref="R?"  Part="1" 
AR Path="/5CD35FCB/5C0C441F" Ref="R?"  Part="1" 
F 0 "R?" H 4850 5720 50  0000 R CNN
F 1 "13.3k" V 4910 5720 40  0000 C CNN
F 2 "Resistors_SMD:R_0603" H 4910 5720 50  0001 C CNN
F 3 "" H 4910 5720 50  0001 C CNN
F 4 "P13.3KHCT-ND" H 4910 5720 50  0001 C CNN "Digi-Key PN"
F 5 "0603" H 4980 5810 50  0000 L CNN "display_footprint"
F 6 "1%" H 4980 5720 50  0000 L CNN "Tolerance"
F 7 "1/10W" H 4980 5640 50  0000 L CNN "Wattage"
	1    4910 5720
	-1   0    0    -1  
$EndComp
$Comp
L Custom_Library:C_Custom C?
U 1 1 5C0C44A7
P 4910 6100
AR Path="/5BE5222A/5C0C44A7" Ref="C?"  Part="1" 
AR Path="/5BAAE10E/5C0C44A7" Ref="C?"  Part="1" 
AR Path="/5CD35FCB/5C0C44A7" Ref="C?"  Part="1" 
F 0 "C?" H 4935 6200 50  0000 L CNN
F 1 "62pF" H 4935 6000 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 4948 5950 50  0001 C CNN
F 3 "" H 4935 6200 50  0001 C CNN
F 4 "1276-2320-1-ND" H 4910 6100 50  0001 C CNN "Digi-Key PN"
F 5 "0603" H 4760 6200 50  0000 R CNN "display_footprint"
F 6 "50V" H 4760 6100 50  0000 R CNN "Voltage"
F 7 "NP0" H 4760 6000 50  0000 R CNN "Dielectric"
	1    4910 6100
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:C_Custom C?
U 1 1 5C0C4503
P 5770 5860
AR Path="/5BE5222A/5C0C4503" Ref="C?"  Part="1" 
AR Path="/5BAAE10E/5C0C4503" Ref="C?"  Part="1" 
AR Path="/5CD35FCB/5C0C4503" Ref="C?"  Part="1" 
F 0 "C?" H 5795 5960 50  0000 L CNN
F 1 "15pF" H 5795 5760 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 5808 5710 50  0001 C CNN
F 3 "" H 5795 5960 50  0001 C CNN
F 4 "478-10289-1-ND" H 5770 5860 50  0001 C CNN "Digi-Key PN"
F 5 "0603" H 5620 5960 50  0000 R CNN "display_footprint"
F 6 "50V" H 5620 5860 50  0000 R CNN "Voltage"
F 7 "NP0" H 5620 5760 50  0000 R CNN "Dielectric"
	1    5770 5860
	1    0    0    -1  
$EndComp
Wire Wire Line
	5770 5710 5770 5410
Wire Wire Line
	4910 5570 4910 5410
Wire Wire Line
	4910 5410 4750 5410
Wire Wire Line
	4750 2610 4830 2610
Wire Wire Line
	4830 2610 4830 2510
Connection ~ 4830 2510
Wire Wire Line
	4830 2510 4750 2510
$Comp
L Custom_Library:R_Custom R?
U 1 1 5C0D1A40
P 3260 2690
AR Path="/5BE5222A/5C0D1A40" Ref="R?"  Part="1" 
AR Path="/5BAAE10E/5C0D1A40" Ref="R?"  Part="1" 
AR Path="/5CD35FCB/5C0D1A40" Ref="R?"  Part="1" 
F 0 "R?" H 3200 2690 50  0000 R CNN
F 1 "10" V 3260 2690 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" H 3260 2690 50  0001 C CNN
F 3 "" H 3260 2690 50  0001 C CNN
F 4 "YAG3351CT-ND" H 3260 2690 50  0001 C CNN "Digi-Key PN"
F 5 "0603" H 3330 2780 50  0000 L CNN "display_footprint"
F 6 "1%" H 3330 2690 50  0000 L CNN "Tolerance"
F 7 "1/10W" H 3330 2610 50  0000 L CNN "Wattage"
	1    3260 2690
	-1   0    0    -1  
$EndComp
Wire Wire Line
	3550 2910 3260 2910
Wire Wire Line
	3260 2910 3260 2840
Wire Wire Line
	3260 2910 3260 2980
Connection ~ 3260 2910
Wire Wire Line
	3550 2510 3470 2510
Wire Wire Line
	3260 2510 3260 2540
Wire Wire Line
	3550 2610 3470 2610
Wire Wire Line
	3470 2610 3470 2510
Connection ~ 3470 2510
Wire Wire Line
	3470 2510 3260 2510
Wire Wire Line
	3550 3610 2690 3610
Wire Wire Line
	2690 3610 2690 3490
Wire Wire Line
	2690 3610 2690 3680
Connection ~ 2690 3610
Wire Wire Line
	2690 3190 2690 2510
Wire Wire Line
	2690 2510 3260 2510
Connection ~ 3260 2510
$Comp
L power:GND #PWR?
U 1 1 5C0E2267
P 2260 2890
F 0 "#PWR?" H 2260 2640 50  0001 C CNN
F 1 "GND" H 2260 2740 50  0000 C CNN
F 2 "" H 2260 2890 50  0001 C CNN
F 3 "" H 2260 2890 50  0001 C CNN
	1    2260 2890
	1    0    0    -1  
$EndComp
Wire Wire Line
	2260 2590 2260 2510
Wire Wire Line
	2260 2510 2690 2510
Connection ~ 2690 2510
$Comp
L Custom_Library:C_Custom C?
U 1 1 5C0E6281
P 1580 2740
AR Path="/5BAAE10E/5C0E6281" Ref="C?"  Part="1" 
AR Path="/5BE5222A/5C0E6281" Ref="C?"  Part="1" 
AR Path="/5CD35FCB/5C0E6281" Ref="C?"  Part="1" 
F 0 "C?" H 1605 2840 50  0000 L CNN
F 1 "22uF" H 1605 2640 50  0000 L CNN
F 2 "Capacitors_SMD:C_2220" H 1618 2590 50  0001 C CNN
F 3 "" H 1605 2840 50  0001 C CNN
F 4 "445-1453-1-ND" H 2005 3240 60  0001 C CNN "Digi-Key PN"
F 5 "2220" H 1430 2840 50  0000 R CNN "display_footprint"
F 6 "25V" H 1430 2740 50  0000 R CNN "Voltage"
F 7 "X7R" H 1430 2640 50  0000 R CNN "Dielectric"
	1    1580 2740
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5C0E6288
P 1580 2890
F 0 "#PWR?" H 1580 2640 50  0001 C CNN
F 1 "GND" H 1580 2740 50  0000 C CNN
F 2 "" H 1580 2890 50  0001 C CNN
F 3 "" H 1580 2890 50  0001 C CNN
	1    1580 2890
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:C_Custom C?
U 1 1 5C0E7913
P 900 2740
AR Path="/5BAAE10E/5C0E7913" Ref="C?"  Part="1" 
AR Path="/5BE5222A/5C0E7913" Ref="C?"  Part="1" 
AR Path="/5CD35FCB/5C0E7913" Ref="C?"  Part="1" 
F 0 "C?" H 925 2840 50  0000 L CNN
F 1 "22uF" H 925 2640 50  0000 L CNN
F 2 "Capacitors_SMD:C_2220" H 938 2590 50  0001 C CNN
F 3 "" H 925 2840 50  0001 C CNN
F 4 "445-1453-1-ND" H 1325 3240 60  0001 C CNN "Digi-Key PN"
F 5 "2220" H 750 2840 50  0000 R CNN "display_footprint"
F 6 "25V" H 750 2740 50  0000 R CNN "Voltage"
F 7 "X7R" H 750 2640 50  0000 R CNN "Dielectric"
	1    900  2740
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5C0E791A
P 900 2890
F 0 "#PWR?" H 900 2640 50  0001 C CNN
F 1 "GND" H 900 2740 50  0000 C CNN
F 2 "" H 900 2890 50  0001 C CNN
F 3 "" H 900 2890 50  0001 C CNN
	1    900  2890
	1    0    0    -1  
$EndComp
Wire Wire Line
	900  2590 900  2510
Wire Wire Line
	900  2510 1580 2510
Connection ~ 2260 2510
Wire Wire Line
	1580 2590 1580 2510
Connection ~ 1580 2510
Wire Wire Line
	1580 2510 2260 2510
$Comp
L power:+12V #PWR?
U 1 1 5C0EC008
P 900 2430
F 0 "#PWR?" H 900 2280 50  0001 C CNN
F 1 "+12V" H 900 2570 50  0000 C CNN
F 2 "" H 900 2430 50  0001 C CNN
F 3 "" H 900 2430 50  0001 C CNN
	1    900  2430
	1    0    0    -1  
$EndComp
Wire Wire Line
	900  2430 900  2510
Connection ~ 900  2510
$Comp
L power:+3.3V #PWR?
U 1 1 5C0F2448
P 1890 3680
F 0 "#PWR?" H 1890 3530 50  0001 C CNN
F 1 "+3.3V" H 1890 3820 50  0000 C CNN
F 2 "" H 1890 3680 50  0001 C CNN
F 3 "" H 1890 3680 50  0001 C CNN
	1    1890 3680
	1    0    0    -1  
$EndComp
Wire Wire Line
	3550 4210 1890 4210
Wire Wire Line
	1890 4210 1890 3980
Text GLabel 1810 4210 0    50   Output ~ 0
POS3P3_PGOOD
Wire Wire Line
	1810 4210 1890 4210
Connection ~ 1890 4210
NoConn ~ 4750 4610
Wire Wire Line
	4750 2710 4830 2710
Wire Wire Line
	4830 2710 4830 2610
Connection ~ 4830 2610
Wire Wire Line
	4910 5410 5770 5410
Connection ~ 4910 5410
Wire Wire Line
	4910 5950 4910 5870
$Comp
L Custom_Library:R_Custom R?
U 1 1 5C137B21
P 1890 3830
AR Path="/5BB2595E/5C137B21" Ref="R?"  Part="1" 
AR Path="/5BAAE0FA/5C137B21" Ref="R?"  Part="1" 
AR Path="/5BB86F23/5C137B21" Ref="R?"  Part="1" 
AR Path="/5BAAE10E/5C137B21" Ref="R?"  Part="1" 
AR Path="/5CD35FCB/5C137B21" Ref="R?"  Part="1" 
F 0 "R?" H 1830 3830 50  0000 R CNN
F 1 "10k" V 1890 3830 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" H 1890 3830 50  0001 C CNN
F 3 "" H 1890 3830 50  0001 C CNN
F 4 "RMCF0603FT10K0CT-ND" H 2190 4230 60  0001 C CNN "Digi-Key PN"
F 5 "0603" H 1970 3910 50  0000 L CNN "display_footprint"
F 6 "1%" H 1970 3830 50  0000 L CNN "Tolerance"
F 7 "1/10W" H 1970 3750 50  0000 L CNN "Wattage"
	1    1890 3830
	-1   0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR?
U 1 1 5C14B3F7
P 9750 3230
F 0 "#PWR?" H 9750 3080 50  0001 C CNN
F 1 "+3.3V" H 9750 3370 50  0000 C CNN
F 2 "" H 9750 3230 50  0001 C CNN
F 3 "" H 9750 3230 50  0001 C CNN
	1    9750 3230
	1    0    0    -1  
$EndComp
$Comp
L power:PWR_FLAG #FLG?
U 1 1 5C151BA4
P 9570 2810
F 0 "#FLG?" H 9570 2885 50  0001 C CNN
F 1 "PWR_FLAG" H 9570 2960 50  0000 C CNN
F 2 "" H 9570 2810 50  0001 C CNN
F 3 "~" H 9570 2810 50  0001 C CNN
	1    9570 2810
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR?
U 1 1 5C151C3E
P 9570 2810
F 0 "#PWR?" H 9570 2660 50  0001 C CNN
F 1 "+3.3V" H 9570 2950 50  0000 C CNN
F 2 "" H 9570 2810 50  0001 C CNN
F 3 "" H 9570 2810 50  0001 C CNN
	1    9570 2810
	-1   0    0    1   
$EndComp
$Comp
L Custom_Library:R_Custom R?
U 1 1 5C15A8BF
P 2690 3340
AR Path="/5BB2595E/5C15A8BF" Ref="R?"  Part="1" 
AR Path="/5BAAE0FA/5C15A8BF" Ref="R?"  Part="1" 
AR Path="/5BB86F23/5C15A8BF" Ref="R?"  Part="1" 
AR Path="/5BAAE10E/5C15A8BF" Ref="R?"  Part="1" 
AR Path="/5CD35FCB/5C15A8BF" Ref="R?"  Part="1" 
F 0 "R?" H 2630 3340 50  0000 R CNN
F 1 "100k" V 2690 3340 40  0000 C CNN
F 2 "Resistors_SMD:R_0603" H 2690 3340 50  0001 C CNN
F 3 "" H 2690 3340 50  0001 C CNN
F 4 "A106046CT-ND" H 2990 3740 60  0001 C CNN "Digi-Key PN"
F 5 "0603" H 2770 3420 50  0000 L CNN "display_footprint"
F 6 "1%" H 2770 3340 50  0000 L CNN "Tolerance"
F 7 "1/10W" H 2770 3260 50  0000 L CNN "Wattage"
	1    2690 3340
	-1   0    0    -1  
$EndComp
Text Notes 7410 4290 0    50   ~ 0
Designed for 5A Max Iout
Text Notes 1160 3280 0    50   ~ 0
Turn on threshold set to 6.6V
$Comp
L Custom_Library:R_Custom R?
U 1 1 5C1764BB
P 2690 3830
AR Path="/5BE5222A/5C1764BB" Ref="R?"  Part="1" 
AR Path="/5BAAE10E/5C1764BB" Ref="R?"  Part="1" 
AR Path="/5CD35FCB/5C1764BB" Ref="R?"  Part="1" 
F 0 "R?" H 2630 3830 50  0000 R CNN
F 1 "22.1k" V 2690 3830 40  0000 C CNN
F 2 "Resistors_SMD:R_0603" H 2690 3830 50  0001 C CNN
F 3 "" H 2690 3830 50  0001 C CNN
F 4 "P22.1KHCT-ND" H 2690 3830 50  0001 C CNN "Digi-Key PN"
F 5 "0603" H 2760 3920 50  0000 L CNN "display_footprint"
F 6 "1%" H 2760 3830 50  0000 L CNN "Tolerance"
F 7 "1/10W" H 2760 3750 50  0000 L CNN "Wattage"
	1    2690 3830
	-1   0    0    -1  
$EndComp
Text Notes 2320 6200 0    50   ~ 0
Switching frequency set to 2.5 MHz
$Comp
L Custom_Library:C_Custom C?
U 1 1 5C1865FA
P 2840 5640
AR Path="/5BAAE16C/5C1865FA" Ref="C?"  Part="1" 
AR Path="/5BB181D8/5C1865FA" Ref="C?"  Part="1" 
AR Path="/5BB2595E/5C1865FA" Ref="C?"  Part="1" 
AR Path="/5BAAE0FA/5C1865FA" Ref="C?"  Part="1" 
AR Path="/5BB86F23/5C1865FA" Ref="C?"  Part="1" 
AR Path="/5BAAE10E/5C1865FA" Ref="C?"  Part="1" 
AR Path="/5CD35FCB/5C1865FA" Ref="C?"  Part="1" 
F 0 "C?" H 2865 5740 50  0000 L CNN
F 1 "10nF" H 2865 5540 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 2878 5490 50  0001 C CNN
F 3 "" H 2865 5740 50  0001 C CNN
F 4 "1276-1921-1-ND" H 3265 6140 60  0001 C CNN "Digi-Key PN"
F 5 "0603" H 2690 5740 50  0000 R CNN "display_footprint"
F 6 "50V" H 2690 5640 50  0000 R CNN "Voltage"
F 7 "X7R" H 2690 5540 50  0000 R CNN "Dielectric"
	1    2840 5640
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5C1C8D3D
P 4200 5740
F 0 "#PWR?" H 4200 5490 50  0001 C CNN
F 1 "GND" H 4240 5590 50  0000 C CNN
F 2 "" H 4200 5740 50  0001 C CNN
F 3 "" H 4200 5740 50  0001 C CNN
	1    4200 5740
	1    0    0    -1  
$EndComp
Wire Wire Line
	4200 5740 4200 5700
Wire Wire Line
	4200 5700 4150 5700
Wire Wire Line
	4150 5700 4150 5660
Wire Wire Line
	4200 5700 4250 5700
Wire Wire Line
	4250 5700 4250 5660
Connection ~ 4200 5700
$Comp
L power:GNDS #PWR?
U 1 1 5C1D0755
P 4050 5740
F 0 "#PWR?" H 4050 5490 50  0001 C CNN
F 1 "GNDS" H 4010 5590 50  0000 C CNN
F 2 "" H 4050 5740 50  0001 C CNN
F 3 "" H 4050 5740 50  0001 C CNN
	1    4050 5740
	1    0    0    -1  
$EndComp
Wire Wire Line
	4050 5740 4050 5660
$Comp
L power:GNDS #PWR?
U 1 1 5C1D4F35
P 3470 5790
F 0 "#PWR?" H 3470 5540 50  0001 C CNN
F 1 "GNDS" H 3470 5640 50  0000 C CNN
F 2 "" H 3470 5790 50  0001 C CNN
F 3 "" H 3470 5790 50  0001 C CNN
	1    3470 5790
	1    0    0    -1  
$EndComp
$Comp
L power:GNDS #PWR?
U 1 1 5C1D4FF8
P 2840 5790
F 0 "#PWR?" H 2840 5540 50  0001 C CNN
F 1 "GNDS" H 2840 5640 50  0000 C CNN
F 2 "" H 2840 5790 50  0001 C CNN
F 3 "" H 2840 5790 50  0001 C CNN
	1    2840 5790
	1    0    0    -1  
$EndComp
$Comp
L power:GNDS #PWR?
U 1 1 5C1D508D
P 4910 6250
F 0 "#PWR?" H 4910 6000 50  0001 C CNN
F 1 "GNDS" H 4910 6100 50  0000 C CNN
F 2 "" H 4910 6250 50  0001 C CNN
F 3 "" H 4910 6250 50  0001 C CNN
	1    4910 6250
	1    0    0    -1  
$EndComp
$Comp
L power:GNDS #PWR?
U 1 1 5C1D5208
P 5770 6010
F 0 "#PWR?" H 5770 5760 50  0001 C CNN
F 1 "GNDS" H 5770 5860 50  0000 C CNN
F 2 "" H 5770 6010 50  0001 C CNN
F 3 "" H 5770 6010 50  0001 C CNN
	1    5770 6010
	1    0    0    -1  
$EndComp
$Comp
L power:GNDS #PWR?
U 1 1 5C1D5327
P 7110 4700
F 0 "#PWR?" H 7110 4450 50  0001 C CNN
F 1 "GNDS" H 7110 4550 50  0000 C CNN
F 2 "" H 7110 4700 50  0001 C CNN
F 3 "" H 7110 4700 50  0001 C CNN
	1    7110 4700
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5C1DE0AA
P 3260 3280
F 0 "#PWR?" H 3260 3030 50  0001 C CNN
F 1 "GND" H 3260 3130 50  0000 C CNN
F 2 "" H 3260 3280 50  0001 C CNN
F 3 "" H 3260 3280 50  0001 C CNN
	1    3260 3280
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5C1DE16D
P 2690 3980
F 0 "#PWR?" H 2690 3730 50  0001 C CNN
F 1 "GND" H 2690 3830 50  0000 C CNN
F 2 "" H 2690 3980 50  0001 C CNN
F 3 "" H 2690 3980 50  0001 C CNN
	1    2690 3980
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5C1E2D96
P 4200 6140
F 0 "#PWR?" H 4200 5890 50  0001 C CNN
F 1 "GND" H 4240 5990 50  0000 C CNN
F 2 "" H 4200 6140 50  0001 C CNN
F 3 "" H 4200 6140 50  0001 C CNN
	1    4200 6140
	1    0    0    -1  
$EndComp
$Comp
L power:GNDS #PWR?
U 1 1 5C1E2D9C
P 4050 6140
F 0 "#PWR?" H 4050 5890 50  0001 C CNN
F 1 "GNDS" H 4010 5990 50  0000 C CNN
F 2 "" H 4050 6140 50  0001 C CNN
F 3 "" H 4050 6140 50  0001 C CNN
	1    4050 6140
	1    0    0    -1  
$EndComp
Wire Wire Line
	4050 6140 4050 6100
Wire Wire Line
	4050 6100 4200 6100
Wire Wire Line
	4200 6100 4200 6140
$Comp
L Custom_Library:LTC3605A_UF U?
U 1 1 5CD45276
P 4150 3960
F 0 "U?" H 4150 5560 50  0000 C CNN
F 1 "LTC3605A_UF" H 4150 3960 50  0000 C CNN
F 2 "Housings_DFN_QFN:QFN-24-1EP_4x4mm_Pitch0.5mm" H 4150 3960 50  0001 C CNN
F 3 "https://www.analog.com/media/en/technical-documentation/data-sheets/3605afg.pdf" H 4150 3960 50  0001 C CNN
F 4 "LTC3605AIUF#TRPBFCT-ND" H 4150 3960 50  0001 C CNN "Digi-Key PN"
	1    4150 3960
	1    0    0    -1  
$EndComp
$Comp
L Amplifier_Current:INA138 U?
U 1 1 5CD6E2B5
P 9060 5400
F 0 "U?" V 9180 5530 50  0000 L CNN
F 1 "INA138" V 9260 5530 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-23-5" H 9060 5400 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/ina138.pdf" H 9060 5405 50  0001 C CNN
F 4 "INA138NACT-ND" H 9060 5400 50  0001 C CNN "Digi-Key PN"
	1    9060 5400
	0    -1   1    0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5CD6E2BB
P 9360 5300
F 0 "#PWR?" H 9360 5050 50  0001 C CNN
F 1 "GND" V 9360 5150 50  0000 R CNN
F 2 "" H 9360 5300 50  0001 C CNN
F 3 "" H 9360 5300 50  0001 C CNN
	1    9360 5300
	0    -1   1    0   
$EndComp
$Comp
L Custom_Library:C_Custom C?
U 1 1 5CD6E2C5
P 7660 5770
AR Path="/5BAAE16C/5CD6E2C5" Ref="C?"  Part="1" 
AR Path="/5BB181D8/5CD6E2C5" Ref="C?"  Part="1" 
AR Path="/5BB2595E/5CD6E2C5" Ref="C?"  Part="1" 
AR Path="/5BAAE0FA/5CD6E2C5" Ref="C?"  Part="1" 
AR Path="/5BB86F23/5CD6E2C5" Ref="C?"  Part="1" 
AR Path="/5C1D5C9E/5CD6E2C5" Ref="C?"  Part="1" 
AR Path="/5CB6F1ED/5CD6E2C5" Ref="C?"  Part="1" 
AR Path="/5CD35FB7/5CD6E2C5" Ref="C?"  Part="1" 
AR Path="/5CD35FCB/5CD6E2C5" Ref="C?"  Part="1" 
F 0 "C?" H 7685 5870 50  0000 L CNN
F 1 "0.1uF" H 7685 5670 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 7698 5620 50  0001 C CNN
F 3 "" H 7685 5870 50  0001 C CNN
F 4 "0603" H 7510 5870 50  0000 R CNN "display_footprint"
F 5 "50V" H 7510 5770 50  0000 R CNN "Voltage"
F 6 "X7R" H 7510 5670 50  0000 R CNN "Dielectric"
F 7 "311-1344-1-ND" H 8085 6270 60  0001 C CNN "Digi-Key PN"
	1    7660 5770
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:C_Custom C?
U 1 1 5CD6E2CF
P 7960 5770
AR Path="/5BAAE16C/5CD6E2CF" Ref="C?"  Part="1" 
AR Path="/5BB181D8/5CD6E2CF" Ref="C?"  Part="1" 
AR Path="/5BB2595E/5CD6E2CF" Ref="C?"  Part="1" 
AR Path="/5BAAE0FA/5CD6E2CF" Ref="C?"  Part="1" 
AR Path="/5BB86F23/5CD6E2CF" Ref="C?"  Part="1" 
AR Path="/5C1D5C9E/5CD6E2CF" Ref="C?"  Part="1" 
AR Path="/5CB6F1ED/5CD6E2CF" Ref="C?"  Part="1" 
AR Path="/5CD35FB7/5CD6E2CF" Ref="C?"  Part="1" 
AR Path="/5CD35FCB/5CD6E2CF" Ref="C?"  Part="1" 
F 0 "C?" H 7985 5870 50  0000 L CNN
F 1 "10nF" H 7985 5670 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 7998 5620 50  0001 C CNN
F 3 "" H 7985 5870 50  0001 C CNN
F 4 "0603" H 7810 5870 50  0001 R CNN "display_footprint"
F 5 "50V" H 7810 5770 50  0001 R CNN "Voltage"
F 6 "X7R" H 7810 5670 50  0001 R CNN "Dielectric"
F 7 "1276-1921-1-ND" H 8385 6270 60  0001 C CNN "Digi-Key PN"
	1    7960 5770
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:C_Custom C?
U 1 1 5CD6E2D9
P 8260 5770
AR Path="/5BAAE16C/5CD6E2D9" Ref="C?"  Part="1" 
AR Path="/5BB181D8/5CD6E2D9" Ref="C?"  Part="1" 
AR Path="/5BB2595E/5CD6E2D9" Ref="C?"  Part="1" 
AR Path="/5BAAE0FA/5CD6E2D9" Ref="C?"  Part="1" 
AR Path="/5BB86F23/5CD6E2D9" Ref="C?"  Part="1" 
AR Path="/5C1D5C9E/5CD6E2D9" Ref="C?"  Part="1" 
AR Path="/5CB6F1ED/5CD6E2D9" Ref="C?"  Part="1" 
AR Path="/5CD35FB7/5CD6E2D9" Ref="C?"  Part="1" 
AR Path="/5CD35FCB/5CD6E2D9" Ref="C?"  Part="1" 
F 0 "C?" H 8285 5870 50  0000 L CNN
F 1 "1nF" H 8285 5670 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 8298 5620 50  0001 C CNN
F 3 "" H 8285 5870 50  0001 C CNN
F 4 "0603" H 8110 5870 50  0001 R CNN "display_footprint"
F 5 "50V" H 8110 5770 50  0001 R CNN "Voltage"
F 6 "X7R" H 8110 5670 50  0001 R CNN "Dielectric"
F 7 "1276-1018-1-ND" H 8685 6270 60  0001 C CNN "Digi-Key PN"
	1    8260 5770
	1    0    0    -1  
$EndComp
Wire Wire Line
	7960 6000 7960 5960
Wire Wire Line
	7960 5960 7660 5960
Wire Wire Line
	7660 5960 7660 5920
Connection ~ 7960 5960
Wire Wire Line
	7960 5960 7960 5920
Wire Wire Line
	7960 5960 8260 5960
Wire Wire Line
	8260 5960 8260 5920
Wire Wire Line
	7960 5540 7960 5580
Wire Wire Line
	7660 5620 7660 5580
Wire Wire Line
	7660 5580 7960 5580
Wire Wire Line
	8260 5580 8260 5620
Connection ~ 7960 5580
Wire Wire Line
	7960 5580 7960 5620
Wire Wire Line
	7960 5580 8260 5580
$Comp
L power:GND #PWR?
U 1 1 5CD6E2ED
P 7960 6000
F 0 "#PWR?" H 7960 5750 50  0001 C CNN
F 1 "GND" H 7960 5850 50  0000 C CNN
F 2 "" H 7960 6000 50  0001 C CNN
F 3 "" H 7960 6000 50  0001 C CNN
	1    7960 6000
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:R_Custom R?
U 1 1 5CD6E2F7
P 9060 3310
AR Path="/5CD35FB7/5CD6E2F7" Ref="R?"  Part="1" 
AR Path="/5CD35FCB/5CD6E2F7" Ref="R?"  Part="1" 
F 0 "R?" V 8960 3310 50  0000 C CNN
F 1 "0.02" V 9060 3310 40  0000 C CNN
F 2 "Resistors_SMD:R_0612" H 9060 3310 50  0001 C CNN
F 3 "" H 9060 3310 50  0001 C CNN
F 4 "P16010CT-ND" H 9360 3710 60  0001 C CNN "Digi-Key PN"
F 5 "0612" V 9160 3310 50  0000 C CNN "display_footprint"
F 6 "1%" V 9260 3310 50  0000 C CNN "Tolerance"
F 7 "1W" V 9360 3310 50  0000 C CNN "Wattage"
	1    9060 3310
	0    -1   -1   0   
$EndComp
$Comp
L Custom_Library:R_Custom R?
U 1 1 5CD6E30C
P 9060 6010
AR Path="/5BB2595E/5CD6E30C" Ref="R?"  Part="1" 
AR Path="/5BAAE0FA/5CD6E30C" Ref="R?"  Part="1" 
AR Path="/5BB86F23/5CD6E30C" Ref="R?"  Part="1" 
AR Path="/5C1D5C9E/5CD6E30C" Ref="R?"  Part="1" 
AR Path="/5CB6F1ED/5CD6E30C" Ref="R?"  Part="1" 
AR Path="/5CD35FB7/5CD6E30C" Ref="R?"  Part="1" 
AR Path="/5CD35FCB/5CD6E30C" Ref="R?"  Part="1" 
F 0 "R?" H 9000 6010 50  0000 R CNN
F 1 "499k" V 9060 6010 40  0000 C CNN
F 2 "Resistors_SMD:R_0603" H 9060 6010 50  0001 C CNN
F 3 "" H 9060 6010 50  0001 C CNN
F 4 "0603" H 9140 6090 50  0000 L CNN "display_footprint"
F 5 "1%" H 9140 6010 50  0000 L CNN "Tolerance"
F 6 "1/10W" H 9140 5930 50  0000 L CNN "Wattage"
F 7 "RMCF0603FT499KCT-ND" H 770 2360 50  0001 C CNN "Digi-Key PN"
	1    9060 6010
	-1   0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5CD6E312
P 9060 6160
F 0 "#PWR?" H 9060 5910 50  0001 C CNN
F 1 "GND" H 9060 6010 50  0000 C CNN
F 2 "" H 9060 6160 50  0001 C CNN
F 3 "" H 9060 6160 50  0001 C CNN
	1    9060 6160
	1    0    0    -1  
$EndComp
Wire Wire Line
	9060 5780 9060 5860
Wire Wire Line
	9060 5700 9060 5780
Connection ~ 9060 5780
Wire Wire Line
	9800 5780 9060 5780
Wire Wire Line
	9800 5860 9800 5780
$Comp
L power:GND #PWR?
U 1 1 5CD6E325
P 9800 6160
F 0 "#PWR?" H 9800 5910 50  0001 C CNN
F 1 "GND" H 9800 6010 50  0000 C CNN
F 2 "" H 9800 6160 50  0001 C CNN
F 3 "" H 9800 6160 50  0001 C CNN
	1    9800 6160
	1    0    0    -1  
$EndComp
Text GLabel 9880 5780 2    50   Output ~ 0
POS3P3_ISNS
Wire Wire Line
	9880 5780 9800 5780
Connection ~ 9800 5780
Text Notes 8790 6640 0    50   ~ 0
1.996 V/A
$Comp
L Custom_Library:C_Custom C?
U 1 1 5CD6E333
P 9800 6010
AR Path="/5BAAE16C/5CD6E333" Ref="C?"  Part="1" 
AR Path="/5BB181D8/5CD6E333" Ref="C?"  Part="1" 
AR Path="/5BB2595E/5CD6E333" Ref="C?"  Part="1" 
AR Path="/5BAAE0FA/5CD6E333" Ref="C?"  Part="1" 
AR Path="/5BB86F23/5CD6E333" Ref="C?"  Part="1" 
AR Path="/5C1D5C9E/5CD6E333" Ref="C?"  Part="1" 
AR Path="/5CB6F1ED/5CD6E333" Ref="C?"  Part="1" 
AR Path="/5CD35FB7/5CD6E333" Ref="C?"  Part="1" 
AR Path="/5CD35FCB/5CD6E333" Ref="C?"  Part="1" 
F 0 "C?" H 9825 6110 50  0000 L CNN
F 1 "1nF" H 9825 5910 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 9838 5860 50  0001 C CNN
F 3 "" H 9825 6110 50  0001 C CNN
F 4 "1276-1018-1-ND" H 10225 6510 60  0001 C CNN "Digi-Key PN"
F 5 "0603" H 9650 6110 50  0000 R CNN "display_footprint"
F 6 "50V" H 9650 6010 50  0000 R CNN "Voltage"
F 7 "X7R" H 9650 5910 50  0000 R CNN "Dielectric"
	1    9800 6010
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR?
U 1 1 5CD6E34F
P 7960 5540
F 0 "#PWR?" H 7960 5390 50  0001 C CNN
F 1 "+3.3V" H 7960 5680 50  0000 C CNN
F 2 "" H 7960 5540 50  0001 C CNN
F 3 "" H 7960 5540 50  0001 C CNN
	1    7960 5540
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR?
U 1 1 5CD6E355
P 8760 5300
F 0 "#PWR?" H 8760 5150 50  0001 C CNN
F 1 "+3.3V" V 8760 5440 50  0000 L CNN
F 2 "" H 8760 5300 50  0001 C CNN
F 3 "" H 8760 5300 50  0001 C CNN
	1    8760 5300
	0    -1   -1   0   
$EndComp
Wire Wire Line
	8910 3310 8840 3310
$Comp
L Custom_Library:C_Custom C?
U 1 1 5CD829DD
P 9750 3550
AR Path="/5BAAE16C/5CD829DD" Ref="C?"  Part="1" 
AR Path="/5BB181D8/5CD829DD" Ref="C?"  Part="1" 
AR Path="/5BB2595E/5CD829DD" Ref="C?"  Part="1" 
AR Path="/5BAAE0FA/5CD829DD" Ref="C?"  Part="1" 
AR Path="/5BB86F23/5CD829DD" Ref="C?"  Part="1" 
AR Path="/5BAAE10E/5CD829DD" Ref="C?"  Part="1" 
AR Path="/5CD35FCB/5CD829DD" Ref="C?"  Part="1" 
F 0 "C?" H 9775 3650 50  0000 L CNN
F 1 "0.1uF" H 9775 3450 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 9788 3400 50  0001 C CNN
F 3 "" H 9775 3650 50  0001 C CNN
F 4 "0603" H 9600 3650 50  0000 R CNN "display_footprint"
F 5 "50V" H 9600 3550 50  0000 R CNN "Voltage"
F 6 "X7R" H 9600 3450 50  0000 R CNN "Dielectric"
F 7 "311-1344-1-ND" H 10175 4050 60  0001 C CNN "Digi-Key PN"
	1    9750 3550
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5CD83F1F
P 9750 3700
F 0 "#PWR?" H 9750 3450 50  0001 C CNN
F 1 "GND" H 9750 3550 50  0000 C CNN
F 2 "" H 9750 3700 50  0001 C CNN
F 3 "" H 9750 3700 50  0001 C CNN
	1    9750 3700
	1    0    0    -1  
$EndComp
Wire Wire Line
	9750 3400 9750 3310
Wire Wire Line
	9750 3230 9750 3310
Connection ~ 9750 3310
$Comp
L Graphic:SYM_Hot_Large #SYM?
U 1 1 5C0AFC2F
P 6340 4960
AR Path="/5BE5222A/5C0AFC2F" Ref="#SYM?"  Part="1" 
AR Path="/5BAAE10E/5C0AFC2F" Ref="#SYM?"  Part="1" 
AR Path="/5CD35FCB/5C0AFC2F" Ref="#SYM?"  Part="1" 
F 0 "#SYM?" H 6340 5160 50  0001 C CNN
F 1 "SYM_Hot_Large" H 6340 4710 50  0001 C CNN
F 2 "" H 6340 4760 50  0001 C CNN
F 3 "~" H 6370 4760 50  0001 C CNN
	1    6340 4960
	1    0    0    -1  
$EndComp
Wire Wire Line
	8960 5100 8960 5020
Wire Wire Line
	8960 5020 9010 5020
Wire Wire Line
	9010 5020 9010 3490
Wire Wire Line
	8840 3490 8840 3310
Connection ~ 8840 3310
Wire Wire Line
	9160 5100 9160 5020
Wire Wire Line
	9160 5020 9110 5020
Wire Wire Line
	9110 5020 9110 3490
Wire Wire Line
	9270 3490 9270 3310
Wire Wire Line
	9270 3310 9210 3310
Connection ~ 9270 3310
Wire Wire Line
	9110 3490 9270 3490
Wire Wire Line
	9010 3490 8840 3490
Wire Wire Line
	9270 3310 9750 3310
$Comp
L Custom_Library:C_Custom C?
U 1 1 5C1584F8
P 8430 3550
AR Path="/5BAAE10E/5C1584F8" Ref="C?"  Part="1" 
AR Path="/5BE5222A/5C1584F8" Ref="C?"  Part="1" 
AR Path="/5CD35FCB/5C1584F8" Ref="C?"  Part="1" 
F 0 "C?" H 8455 3650 50  0000 L CNN
F 1 "47uF" H 8455 3450 50  0000 L CNN
F 2 "Capacitors_SMD:C_1210" H 8468 3400 50  0001 C CNN
F 3 "" H 8455 3650 50  0001 C CNN
F 4 "490-4844-1-ND" H 8430 3550 50  0001 C CNN "Digi-Key PN"
F 5 "1210" H 8280 3650 50  0000 R CNN "display_footprint"
F 6 "6.3V" H 8280 3550 50  0000 R CNN "Voltage"
F 7 "X7R" H 8280 3450 50  0000 R CNN "Dielectric"
	1    8430 3550
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5C114957
P 7770 3700
F 0 "#PWR?" H 7770 3450 50  0001 C CNN
F 1 "GND" H 7770 3550 50  0000 C CNN
F 2 "" H 7770 3700 50  0001 C CNN
F 3 "" H 7770 3700 50  0001 C CNN
	1    7770 3700
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:C_Custom C?
U 1 1 5C114950
P 7770 3550
AR Path="/5BAAE10E/5C114950" Ref="C?"  Part="1" 
AR Path="/5BE5222A/5C114950" Ref="C?"  Part="1" 
AR Path="/5CD35FCB/5C114950" Ref="C?"  Part="1" 
F 0 "C?" H 7795 3650 50  0000 L CNN
F 1 "47uF" H 7795 3450 50  0000 L CNN
F 2 "Capacitors_SMD:C_1210" H 7808 3400 50  0001 C CNN
F 3 "" H 7795 3650 50  0001 C CNN
F 4 "490-4844-1-ND" H 7770 3550 50  0001 C CNN "Digi-Key PN"
F 5 "1210" H 7620 3650 50  0000 R CNN "display_footprint"
F 6 "6.3V" H 7620 3550 50  0000 R CNN "Voltage"
F 7 "X7R" H 7620 3450 50  0000 R CNN "Dielectric"
	1    7770 3550
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5C114946
P 8430 3700
F 0 "#PWR?" H 8430 3450 50  0001 C CNN
F 1 "GND" H 8430 3550 50  0000 C CNN
F 2 "" H 8430 3700 50  0001 C CNN
F 3 "" H 8430 3700 50  0001 C CNN
	1    8430 3700
	1    0    0    -1  
$EndComp
Connection ~ 7770 3310
Wire Wire Line
	7770 3400 7770 3310
Wire Wire Line
	8430 3310 8840 3310
Wire Wire Line
	8430 3310 7770 3310
Connection ~ 8430 3310
Wire Wire Line
	8430 3400 8430 3310
$Comp
L Custom_Library:R_Custom R?
U 1 1 5C11ED08
P 7110 3740
AR Path="/5BB2595E/5C11ED08" Ref="R?"  Part="1" 
AR Path="/5BAAE0FA/5C11ED08" Ref="R?"  Part="1" 
AR Path="/5BB86F23/5C11ED08" Ref="R?"  Part="1" 
AR Path="/5BAAE10E/5C11ED08" Ref="R?"  Part="1" 
AR Path="/5CD35FCB/5C11ED08" Ref="R?"  Part="1" 
F 0 "R?" H 7050 3740 50  0000 R CNN
F 1 "100k" V 7110 3740 40  0000 C CNN
F 2 "Resistors_SMD:R_0603" H 7110 3740 50  0001 C CNN
F 3 "" H 7110 3740 50  0001 C CNN
F 4 "A106046CT-ND" H 7410 4140 60  0001 C CNN "Digi-Key PN"
F 5 "0603" H 7190 3820 50  0000 L CNN "display_footprint"
F 6 "1%" H 7190 3740 50  0000 L CNN "Tolerance"
F 7 "1/10W" H 7190 3660 50  0000 L CNN "Wattage"
	1    7110 3740
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:C_Custom C?
U 1 1 5C0AFBFD
P 6500 3740
AR Path="/5BE5222A/5C0AFBFD" Ref="C?"  Part="1" 
AR Path="/5BAAE10E/5C0AFBFD" Ref="C?"  Part="1" 
AR Path="/5CD35FCB/5C0AFBFD" Ref="C?"  Part="1" 
F 0 "C?" H 6525 3840 50  0000 L CNN
F 1 "15pF" H 6525 3640 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 6538 3590 50  0001 C CNN
F 3 "" H 6525 3840 50  0001 C CNN
F 4 "478-10289-1-ND" H 6500 3740 50  0001 C CNN "Digi-Key PN"
F 5 "0603" H 6350 3840 50  0000 R CNN "display_footprint"
F 6 "50V" H 6350 3740 50  0000 R CNN "Voltage"
F 7 "NP0" H 6350 3640 50  0000 R CNN "Dielectric"
	1    6500 3740
	1    0    0    -1  
$EndComp
Wire Wire Line
	6500 4210 7110 4210
Wire Wire Line
	4750 4210 6500 4210
Connection ~ 6500 4210
Wire Wire Line
	6500 3890 6500 4210
Connection ~ 7110 4210
Wire Wire Line
	7110 4210 7110 3890
Wire Wire Line
	6010 3310 7770 3310
Wire Wire Line
	7110 3590 7110 2890
Wire Wire Line
	7110 2890 9270 2890
Wire Wire Line
	9270 2890 9270 3310
Wire Wire Line
	6500 3590 6500 2890
Wire Wire Line
	6500 2890 7110 2890
Connection ~ 7110 2890
$EndSCHEMATC
