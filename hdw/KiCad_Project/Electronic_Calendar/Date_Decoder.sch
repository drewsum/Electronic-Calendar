EESchema Schematic File Version 4
LIBS:Electronic_Calendar-cache
EELAYER 29 0
EELAYER END
$Descr A 11000 8500
encoding utf-8
Sheet 17 17
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text GLabel 7450 3920 2    40   Output ~ 0
~Date31_LED
Text GLabel 7450 3820 2    40   Output ~ 0
~Date30_LED
Text GLabel 7450 3720 2    40   Output ~ 0
~Date29_LED
Text GLabel 7450 3620 2    40   Output ~ 0
~Date28_LED
Text GLabel 7450 3520 2    40   Output ~ 0
~Date27_LED
Text GLabel 7450 3420 2    40   Output ~ 0
~Date26_LED
Text GLabel 7450 3320 2    40   Output ~ 0
~Date25_LED
Text GLabel 7450 3220 2    40   Output ~ 0
~Date24_LED
Text GLabel 7450 3120 2    40   Output ~ 0
~Date23_LED
Text GLabel 7450 3020 2    40   Output ~ 0
~Date22_LED
Text GLabel 7450 2920 2    40   Output ~ 0
~Date21_LED
Text GLabel 7450 2820 2    40   Output ~ 0
~Date20_LED
Text GLabel 7450 2720 2    40   Output ~ 0
~Date19_LED
Text GLabel 7450 2620 2    40   Output ~ 0
~Date18_LED
Text GLabel 7450 2520 2    40   Output ~ 0
~Date17_LED
Text GLabel 7450 2420 2    40   Output ~ 0
~Date16_LED
Text GLabel 7450 2320 2    40   Output ~ 0
~Date15_LED
Text GLabel 7450 2220 2    40   Output ~ 0
~Date14_LED
Text GLabel 7450 2120 2    40   Output ~ 0
~Date13_LED
Text GLabel 7450 2020 2    40   Output ~ 0
~Date12_LED
Text GLabel 7450 1920 2    40   Output ~ 0
~Date11_LED
Text GLabel 7450 1820 2    40   Output ~ 0
~Date10_LED
Text GLabel 7450 1720 2    40   Output ~ 0
~Date9_LED
Text GLabel 7450 1620 2    40   Output ~ 0
~Date8_LED
Text GLabel 7450 1520 2    40   Output ~ 0
~Date7_LED
Text GLabel 7450 1420 2    40   Output ~ 0
~Date6_LED
Text GLabel 7450 1320 2    40   Output ~ 0
~Date5_LED
Text GLabel 7450 1220 2    40   Output ~ 0
~Date4_LED
Text GLabel 7450 1120 2    40   Output ~ 0
~Date3_LED
Text GLabel 7450 1020 2    40   Output ~ 0
~Date2_LED
Text GLabel 7450 920  2    40   Output ~ 0
~Date1_LED
Text GLabel 3310 2330 0    50   Input ~ 0
Date_B0
Text GLabel 3310 2430 0    50   Input ~ 0
Date_B1
Text GLabel 3310 2530 0    50   Input ~ 0
Date_B2
Text GLabel 3310 2630 0    50   Input ~ 0
Date_B3
Text GLabel 3310 2730 0    50   Input ~ 0
Date_B4
Text GLabel 5490 6820 2    40   Output ~ 0
~Year2026_LED
Text GLabel 5490 6720 2    40   Output ~ 0
~Year2025_LED
Text GLabel 5490 6620 2    40   Output ~ 0
~Year2024_LED
Text GLabel 5490 6520 2    40   Output ~ 0
~Year2023_LED
Text GLabel 5490 6420 2    40   Output ~ 0
~Year2022_LED
Text GLabel 5490 6320 2    40   Output ~ 0
~Year2021_LED
Text GLabel 5490 6220 2    40   Output ~ 0
~Year2020_LED
Text GLabel 5490 6120 2    40   Output ~ 0
~Year2019_LED
$Comp
L 74xx:74LS138 U?
U 1 1 5D291D0C
P 4990 6420
F 0 "U?" H 4690 6870 50  0000 C CNN
F 1 "74LS138" H 4690 5870 50  0000 C CNN
F 2 "" H 4990 6420 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS138" H 4990 6420 50  0001 C CNN
	1    4990 6420
	1    0    0    -1  
$EndComp
Text GLabel 1690 6320 0    50   Input ~ 0
Year_B2
Text GLabel 1690 6220 0    50   Input ~ 0
Year_B1
Text GLabel 1690 6120 0    50   Input ~ 0
Year_B0
Text Notes 5730 5810 0    50   ~ 0
Switch to CMOS version, SMALL PACKAGE
$Comp
L Custom_Library:+3.3V #PWR?
U 1 1 5D295293
P 4990 5820
F 0 "#PWR?" H 4990 5670 50  0001 C CNN
F 1 "+3.3V" H 4990 5960 50  0000 C CNN
F 2 "" H 4990 5820 50  0001 C CNN
F 3 "" H 4990 5820 50  0001 C CNN
	1    4990 5820
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5D295667
P 4990 7120
F 0 "#PWR?" H 4990 6870 50  0001 C CNN
F 1 "GND" H 4990 6970 50  0000 C CNN
F 2 "" H 4990 7120 50  0001 C CNN
F 3 "" H 4990 7120 50  0001 C CNN
	1    4990 7120
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5D296E4D
P 4410 6900
F 0 "#PWR?" H 4410 6650 50  0001 C CNN
F 1 "GND" H 4410 6750 50  0000 C CNN
F 2 "" H 4410 6900 50  0001 C CNN
F 3 "" H 4410 6900 50  0001 C CNN
	1    4410 6900
	1    0    0    -1  
$EndComp
Wire Wire Line
	4410 6900 4410 6820
Wire Wire Line
	4410 6720 4490 6720
Wire Wire Line
	4490 6820 4410 6820
Connection ~ 4410 6820
Wire Wire Line
	4410 6820 4410 6720
$Comp
L Custom_Library:R_Custom R?
U 1 1 5D29A753
P 3920 6940
AR Path="/5BAAE1F3/5D29A753" Ref="R?"  Part="1" 
AR Path="/5BAAE1DC/5D29A753" Ref="R?"  Part="1" 
AR Path="/5CAD2DA3/5D29A753" Ref="R?"  Part="1" 
AR Path="/5B3E071A/5D29A753" Ref="R?"  Part="1" 
AR Path="/5CD3BBF8/5D29A753" Ref="R?"  Part="1" 
AR Path="/5D265DF8/5D29A753" Ref="R?"  Part="1" 
F 0 "R?" H 3860 6940 50  0000 R CNN
F 1 "10k" V 3920 6940 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" H 3920 6940 50  0001 C CNN
F 3 "" H 3920 6940 50  0001 C CNN
F 4 "0603" H 4110 7020 50  0000 C CNN "display_footprint"
F 5 "1%" H 4100 6940 50  0000 C CNN "Tolerance"
F 6 "1/10W" H 4130 6870 50  0000 C CNN "Wattage"
F 7 "RMCF0603FT10K0CT-ND" H 4220 7340 60  0001 C CNN "Digi-Key PN"
	1    3920 6940
	-1   0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5D29C51D
P 3920 7090
F 0 "#PWR?" H 3920 6840 50  0001 C CNN
F 1 "GND" H 3920 6940 50  0000 C CNN
F 2 "" H 3920 7090 50  0001 C CNN
F 3 "" H 3920 7090 50  0001 C CNN
	1    3920 7090
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:R_Custom R?
U 1 1 5D29C933
P 3270 6940
AR Path="/5BAAE1F3/5D29C933" Ref="R?"  Part="1" 
AR Path="/5BAAE1DC/5D29C933" Ref="R?"  Part="1" 
AR Path="/5CAD2DA3/5D29C933" Ref="R?"  Part="1" 
AR Path="/5B3E071A/5D29C933" Ref="R?"  Part="1" 
AR Path="/5CD3BBF8/5D29C933" Ref="R?"  Part="1" 
AR Path="/5D265DF8/5D29C933" Ref="R?"  Part="1" 
F 0 "R?" H 3210 6940 50  0000 R CNN
F 1 "10k" V 3270 6940 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" H 3270 6940 50  0001 C CNN
F 3 "" H 3270 6940 50  0001 C CNN
F 4 "0603" H 3460 7020 50  0000 C CNN "display_footprint"
F 5 "1%" H 3450 6940 50  0000 C CNN "Tolerance"
F 6 "1/10W" H 3480 6870 50  0000 C CNN "Wattage"
F 7 "RMCF0603FT10K0CT-ND" H 3570 7340 60  0001 C CNN "Digi-Key PN"
	1    3270 6940
	-1   0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5D29C93D
P 3270 7090
F 0 "#PWR?" H 3270 6840 50  0001 C CNN
F 1 "GND" H 3270 6940 50  0000 C CNN
F 2 "" H 3270 7090 50  0001 C CNN
F 3 "" H 3270 7090 50  0001 C CNN
	1    3270 7090
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:R_Custom R?
U 1 1 5D29DEBD
P 2620 6940
AR Path="/5BAAE1F3/5D29DEBD" Ref="R?"  Part="1" 
AR Path="/5BAAE1DC/5D29DEBD" Ref="R?"  Part="1" 
AR Path="/5CAD2DA3/5D29DEBD" Ref="R?"  Part="1" 
AR Path="/5B3E071A/5D29DEBD" Ref="R?"  Part="1" 
AR Path="/5CD3BBF8/5D29DEBD" Ref="R?"  Part="1" 
AR Path="/5D265DF8/5D29DEBD" Ref="R?"  Part="1" 
F 0 "R?" H 2560 6940 50  0000 R CNN
F 1 "10k" V 2620 6940 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" H 2620 6940 50  0001 C CNN
F 3 "" H 2620 6940 50  0001 C CNN
F 4 "0603" H 2810 7020 50  0000 C CNN "display_footprint"
F 5 "1%" H 2800 6940 50  0000 C CNN "Tolerance"
F 6 "1/10W" H 2830 6870 50  0000 C CNN "Wattage"
F 7 "RMCF0603FT10K0CT-ND" H 2920 7340 60  0001 C CNN "Digi-Key PN"
	1    2620 6940
	-1   0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5D29DEC7
P 2620 7090
F 0 "#PWR?" H 2620 6840 50  0001 C CNN
F 1 "GND" H 2620 6940 50  0000 C CNN
F 2 "" H 2620 7090 50  0001 C CNN
F 3 "" H 2620 7090 50  0001 C CNN
	1    2620 7090
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:R_Custom R?
U 1 1 5D29DED5
P 1970 6940
AR Path="/5BAAE1F3/5D29DED5" Ref="R?"  Part="1" 
AR Path="/5BAAE1DC/5D29DED5" Ref="R?"  Part="1" 
AR Path="/5CAD2DA3/5D29DED5" Ref="R?"  Part="1" 
AR Path="/5B3E071A/5D29DED5" Ref="R?"  Part="1" 
AR Path="/5CD3BBF8/5D29DED5" Ref="R?"  Part="1" 
AR Path="/5D265DF8/5D29DED5" Ref="R?"  Part="1" 
F 0 "R?" H 1910 6940 50  0000 R CNN
F 1 "10k" V 1970 6940 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" H 1970 6940 50  0001 C CNN
F 3 "" H 1970 6940 50  0001 C CNN
F 4 "0603" H 2160 7020 50  0000 C CNN "display_footprint"
F 5 "1%" H 2150 6940 50  0000 C CNN "Tolerance"
F 6 "1/10W" H 2180 6870 50  0000 C CNN "Wattage"
F 7 "RMCF0603FT10K0CT-ND" H 2270 7340 60  0001 C CNN "Digi-Key PN"
	1    1970 6940
	-1   0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5D29DEDF
P 1970 7090
F 0 "#PWR?" H 1970 6840 50  0001 C CNN
F 1 "GND" H 1970 6940 50  0000 C CNN
F 2 "" H 1970 7090 50  0001 C CNN
F 3 "" H 1970 7090 50  0001 C CNN
	1    1970 7090
	1    0    0    -1  
$EndComp
Wire Wire Line
	4490 6120 1970 6120
Wire Wire Line
	4490 6220 2620 6220
Wire Wire Line
	4490 6320 3270 6320
Text GLabel 1690 6620 0    50   Input ~ 0
Date_Decode_Enable
Wire Wire Line
	1690 6620 3920 6620
Wire Wire Line
	1970 6790 1970 6120
Connection ~ 1970 6120
Wire Wire Line
	1970 6120 1690 6120
Wire Wire Line
	2620 6790 2620 6220
Connection ~ 2620 6220
Wire Wire Line
	2620 6220 1690 6220
Wire Wire Line
	3270 6790 3270 6320
Connection ~ 3270 6320
Wire Wire Line
	3270 6320 1690 6320
Wire Wire Line
	3920 6790 3920 6620
Connection ~ 3920 6620
Wire Wire Line
	3920 6620 4490 6620
$Comp
L power:GND #PWR?
U 1 1 5D2A7B0E
P 5600 7630
AR Path="/5CD35FB7/5D2A7B0E" Ref="#PWR?"  Part="1" 
AR Path="/5D265DF8/5D2A7B0E" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 5600 7380 50  0001 C CNN
F 1 "GND" H 5600 7480 50  0000 C CNN
F 2 "" H 5600 7630 50  0001 C CNN
F 3 "" H 5600 7630 50  0001 C CNN
	1    5600 7630
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:C_Custom C?
U 1 1 5D2A7B18
P 5600 7480
AR Path="/5BAAE16C/5D2A7B18" Ref="C?"  Part="1" 
AR Path="/5BB181D8/5D2A7B18" Ref="C?"  Part="1" 
AR Path="/5BB2595E/5D2A7B18" Ref="C?"  Part="1" 
AR Path="/5BAAE0FA/5D2A7B18" Ref="C?"  Part="1" 
AR Path="/5BB86F23/5D2A7B18" Ref="C?"  Part="1" 
AR Path="/5C1D5C9E/5D2A7B18" Ref="C?"  Part="1" 
AR Path="/5CB6F1ED/5D2A7B18" Ref="C?"  Part="1" 
AR Path="/5CD35FB7/5D2A7B18" Ref="C?"  Part="1" 
AR Path="/5D265DF8/5D2A7B18" Ref="C?"  Part="1" 
F 0 "C?" H 5625 7580 50  0000 L CNN
F 1 "0.1uF" H 5625 7380 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 5638 7330 50  0001 C CNN
F 3 "" H 5625 7580 50  0001 C CNN
F 4 "0603" H 5450 7580 50  0000 R CNN "display_footprint"
F 5 "50V" H 5450 7480 50  0000 R CNN "Voltage"
F 6 "X7R" H 5450 7380 50  0000 R CNN "Dielectric"
F 7 "311-1344-1-ND" H 6025 7980 60  0001 C CNN "Digi-Key PN"
	1    5600 7480
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:+3.3V #PWR?
U 1 1 5D2A7C4D
P 5600 7330
F 0 "#PWR?" H 5600 7180 50  0001 C CNN
F 1 "+3.3V" H 5600 7470 50  0000 C CNN
F 2 "" H 5600 7330 50  0001 C CNN
F 3 "" H 5600 7330 50  0001 C CNN
	1    5600 7330
	1    0    0    -1  
$EndComp
$EndSCHEMATC
