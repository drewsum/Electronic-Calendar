EESchema Schematic File Version 4
LIBS:Electronic_Calendar-cache
EELAYER 29 0
EELAYER END
$Descr A 11000 8500
encoding utf-8
Sheet 7 13
Title "QI Charger"
Date "2019-01-03"
Rev "A"
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Sensor_Touch:AT42QT1010-TSHR U?
U 1 1 5C275253
P 5370 3630
F 0 "U?" H 5270 3955 50  0000 R CNN
F 1 "AT42QT1010-TSHR" H 5270 3880 50  0000 R CNN
F 2 "TO_SOT_Packages_SMD:SOT-23-6" H 5420 3380 50  0001 L CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-9541-AT42-QTouch-BSW-AT42QT1010_Datasheet.pdf" H 5640 4180 50  0001 C CNN
F 4 "AT42QT1010-TSHRCT-ND" H 5370 3630 50  0001 C CNN "Digi-Key PN"
	1    5370 3630
	-1   0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5C27607B
P 5370 3930
F 0 "#PWR?" H 5370 3680 50  0001 C CNN
F 1 "GND" H 5370 3780 50  0000 C CNN
F 2 "" H 5370 3930 50  0001 C CNN
F 3 "" H 5370 3930 50  0001 C CNN
	1    5370 3930
	-1   0    0    -1  
$EndComp
$Comp
L Custom_Library:C_Custom C?
U 1 1 5C276FA4
P 5050 4710
AR Path="/5C1D5CD8/5C276FA4" Ref="C?"  Part="1" 
AR Path="/5C1D5CCA/5C276FA4" Ref="C?"  Part="1" 
AR Path="/5C26E09A/5C276FA4" Ref="C?"  Part="1" 
AR Path="/5CE10A38/5C276FA4" Ref="C?"  Part="1" 
F 0 "C?" H 5075 4810 50  0000 L CNN
F 1 "0.1uF" H 5075 4610 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 5088 4560 50  0001 C CNN
F 3 "" H 5075 4810 50  0001 C CNN
F 4 "311-1344-1-ND" H 5475 5210 60  0001 C CNN "Digi-Key PN"
F 5 "0603" H 4900 4810 50  0000 R CNN "display_footprint"
F 6 "50V" H 4900 4710 50  0000 R CNN "Voltage"
F 7 "X7R" H 4900 4610 50  0000 R CNN "Dielectric"
	1    5050 4710
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:C_Custom C?
U 1 1 5C276FAE
P 5370 4710
AR Path="/5C1D5CD8/5C276FAE" Ref="C?"  Part="1" 
AR Path="/5C1D5CCA/5C276FAE" Ref="C?"  Part="1" 
AR Path="/5C26E09A/5C276FAE" Ref="C?"  Part="1" 
AR Path="/5CE10A38/5C276FAE" Ref="C?"  Part="1" 
F 0 "C?" H 5395 4810 50  0000 L CNN
F 1 "10nF" H 5395 4610 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 5408 4560 50  0001 C CNN
F 3 "" H 5395 4810 50  0001 C CNN
F 4 "1276-1921-1-ND" H -10 1540 50  0001 C CNN "Digi-Key PN"
F 5 "0603" H 5220 4810 50  0001 R CNN "display_footprint"
F 6 "50V" H 5220 4710 50  0001 R CNN "Voltage"
F 7 "X7R" H 5220 4610 50  0001 R CNN "Dielectric"
	1    5370 4710
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:C_Custom C?
U 1 1 5C276FB8
P 5690 4710
AR Path="/5C1D5CD8/5C276FB8" Ref="C?"  Part="1" 
AR Path="/5C1D5CCA/5C276FB8" Ref="C?"  Part="1" 
AR Path="/5C26E09A/5C276FB8" Ref="C?"  Part="1" 
AR Path="/5CE10A38/5C276FB8" Ref="C?"  Part="1" 
F 0 "C?" H 5715 4810 50  0000 L CNN
F 1 "1nF" H 5715 4610 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 5728 4560 50  0001 C CNN
F 3 "" H 5715 4810 50  0001 C CNN
F 4 "1276-1018-1-ND" H 630 1540 50  0001 C CNN "Digi-Key PN"
F 5 "0603" H 5540 4810 50  0001 R CNN "display_footprint"
F 6 "50V" H 5540 4710 50  0001 R CNN "Voltage"
F 7 "X7R" H 5540 4610 50  0001 R CNN "Dielectric"
	1    5690 4710
	1    0    0    -1  
$EndComp
Wire Wire Line
	5370 4480 5370 4520
Wire Wire Line
	5370 4520 5050 4520
Wire Wire Line
	5050 4520 5050 4560
Connection ~ 5370 4520
Wire Wire Line
	5370 4520 5370 4560
Wire Wire Line
	5370 4520 5690 4520
Wire Wire Line
	5690 4520 5690 4560
Wire Wire Line
	5370 4940 5370 4900
Wire Wire Line
	5370 4900 5050 4900
Wire Wire Line
	5050 4900 5050 4860
Connection ~ 5370 4900
Wire Wire Line
	5370 4900 5370 4860
Wire Wire Line
	5370 4900 5690 4900
Wire Wire Line
	5690 4900 5690 4860
$Comp
L power:GND #PWR?
U 1 1 5C276FD3
P 5370 4940
AR Path="/5C1D5CCA/5C276FD3" Ref="#PWR?"  Part="1" 
AR Path="/5C26E09A/5C276FD3" Ref="#PWR?"  Part="1" 
AR Path="/5CE10A38/5C276FD3" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 5370 4690 50  0001 C CNN
F 1 "GND" H 5370 4790 50  0000 C CNN
F 2 "" H 5370 4940 50  0001 C CNN
F 3 "" H 5370 4940 50  0001 C CNN
	1    5370 4940
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:C_Custom C?
U 1 1 5C27FEA3
P 4650 3730
AR Path="/5C1D5CD8/5C27FEA3" Ref="C?"  Part="1" 
AR Path="/5C1D5CCA/5C27FEA3" Ref="C?"  Part="1" 
AR Path="/5C1E3A0B/5C27FEA3" Ref="C?"  Part="1" 
AR Path="/5C26E09A/5C27FEA3" Ref="C?"  Part="1" 
AR Path="/5CE10A38/5C27FEA3" Ref="C?"  Part="1" 
F 0 "C?" V 4126 3730 50  0000 C CNN
F 1 "10nF" V 4217 3730 50  0000 C CNN
F 2 "Capacitors_SMD:C_0603" H 4688 3580 50  0001 C CNN
F 3 "" H 4675 3830 50  0001 C CNN
F 4 "1276-1921-1-ND" H -140 1510 50  0001 C CNN "Digi-Key PN"
F 5 "0603" V 4308 3730 50  0000 C CNN "display_footprint"
F 6 "50V" V 4399 3730 50  0000 C CNN "Voltage"
F 7 "X7R" V 4490 3730 50  0000 C CNN "Dielectric"
	1    4650 3730
	0    1    -1   0   
$EndComp
Wire Wire Line
	4800 3730 4970 3730
$Comp
L Custom_Library:R_Custom R?
U 1 1 5C283E0E
P 3850 3530
AR Path="/5C3165D8/5C283E0E" Ref="R?"  Part="1" 
AR Path="/5C26E09A/5C283E0E" Ref="R?"  Part="1" 
AR Path="/5CE10A38/5C283E0E" Ref="R?"  Part="1" 
F 0 "R?" V 3750 3530 50  0000 C CNN
F 1 "499" V 3850 3530 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" H 3850 3530 50  0001 C CNN
F 3 "" H 3850 3530 50  0001 C CNN
F 4 "P499HCT-ND" H 4150 3930 60  0001 C CNN "Digi-Key PN"
F 5 "0603" V 3950 3530 50  0000 C CNN "display_footprint"
F 6 "1%" V 4050 3530 50  0000 C CNN "Tolerance"
F 7 "1/10W" V 4150 3530 50  0000 C CNN "Wattage"
	1    3850 3530
	0    -1   1    0   
$EndComp
Wire Wire Line
	4000 3530 4330 3530
Wire Wire Line
	4500 3730 4330 3730
Wire Wire Line
	4330 3730 4330 3530
Connection ~ 4330 3530
Wire Wire Line
	4330 3530 4970 3530
$Comp
L Custom_Library:R_Custom R?
U 1 1 5C28ACBD
P 5370 2650
AR Path="/5C3165D8/5C28ACBD" Ref="R?"  Part="1" 
AR Path="/5C26E09A/5C28ACBD" Ref="R?"  Part="1" 
AR Path="/5CE10A38/5C28ACBD" Ref="R?"  Part="1" 
F 0 "R?" V 5270 2650 50  0000 C CNN
F 1 "0" V 5370 2650 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" H 5370 2650 50  0001 C CNN
F 3 "" H 5370 2650 50  0001 C CNN
F 4 "DNP" V 5190 2650 50  0000 C CNN "Config"
F 5 "P0.0GCT-ND" H 5670 3050 60  0001 C CNN "Digi-Key PN"
F 6 "0603" V 5470 2650 50  0000 C CNN "display_footprint"
F 7 "1%" V 5570 2650 50  0000 C CNN "Tolerance"
F 8 "1/10W" V 5670 2650 50  0000 C CNN "Wattage"
	1    5370 2650
	0    -1   1    0   
$EndComp
Wire Wire Line
	5220 2650 4330 2650
Wire Wire Line
	4330 2650 4330 3530
Wire Wire Line
	5520 2650 6370 2650
Wire Wire Line
	6370 2650 6370 3730
Wire Wire Line
	6370 3730 5770 3730
$Comp
L Custom_Library:Cap_Touch SW?
U 1 1 5C29240E
P 3390 3530
F 0 "SW?" V 3390 3680 50  0000 L CNN
F 1 "Cap_Touch" H 3390 3680 50  0001 C CNN
F 2 "Custom Footprints Library:Capacitive_Touch_Pad" H 3390 3530 60  0001 C CNN
F 3 "" H 3390 3530 60  0000 C CNN
	1    3390 3530
	0    -1   1    0   
$EndComp
Wire Wire Line
	3390 3530 3700 3530
Text GLabel 6450 3730 2    50   Output ~ 0
Cap_Touch_Power
Wire Wire Line
	6450 3730 6370 3730
Connection ~ 6370 3730
Text Notes 540  690  0    100  ~ 20
08. Capacitive Touch Sensors
$Comp
L Custom_Library:+3.3V #PWR?
U 1 1 5CE7112D
P 5370 4480
F 0 "#PWR?" H 5370 4330 50  0001 C CNN
F 1 "+3.3V" H 5370 4620 50  0000 C CNN
F 2 "" H 5370 4480 50  0001 C CNN
F 3 "" H 5370 4480 50  0001 C CNN
	1    5370 4480
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:+3.3V #PWR?
U 1 1 5CE714E1
P 5370 3330
F 0 "#PWR?" H 5370 3180 50  0001 C CNN
F 1 "+3.3V" H 5370 3470 50  0000 C CNN
F 2 "" H 5370 3330 50  0001 C CNN
F 3 "" H 5370 3330 50  0001 C CNN
	1    5370 3330
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:+3.3V #PWR?
U 1 1 5CE71CFB
P 5770 3530
F 0 "#PWR?" H 5770 3380 50  0001 C CNN
F 1 "+3.3V" V 5770 3670 50  0000 L CNN
F 2 "" H 5770 3530 50  0001 C CNN
F 3 "" H 5770 3530 50  0001 C CNN
	1    5770 3530
	0    1    1    0   
$EndComp
$EndSCHEMATC
