EESchema Schematic File Version 4
LIBS:Electronic_Calendar-cache
EELAYER 29 0
EELAYER END
$Descr A 11000 8500
encoding utf-8
Sheet 14 15
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
L Custom_Library:FT234XD U?
U 1 1 5BAEAC0F
P 3520 3340
F 0 "U?" H 4070 2940 60  0000 R CNN
F 1 "FT234XD" H 3520 3340 60  0000 C CNN
F 2 "Housings_DFN_QFN:DFN-12-1EP_3x3mm_Pitch0.45mm" H 3520 3740 60  0001 C CNN
F 3 "http://www.ftdichip.com/Support/Documents/DataSheets/ICs/DS_FT234XD.pdf" H 3520 3740 60  0001 C CNN
F 4 "768-1178-1-ND" H 4170 3040 60  0001 C CNN "Digi-Key PN"
	1    3520 3340
	-1   0    0    -1  
$EndComp
$Comp
L Custom_Library:GND_USB #PWR?
U 1 1 5BAEB69F
P 3620 3790
F 0 "#PWR?" H 3620 3540 50  0001 C CNN
F 1 "GND_USB" H 3740 3640 50  0000 C CNN
F 2 "" H 3620 3790 50  0001 C CNN
F 3 "" H 3620 3790 50  0001 C CNN
	1    3620 3790
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:GND_USB #PWR?
U 1 1 5BAEB6B5
P 3420 3790
F 0 "#PWR?" H 3420 3540 50  0001 C CNN
F 1 "GND_USB" H 3180 3650 50  0000 C CNN
F 2 "" H 3420 3790 50  0001 C CNN
F 3 "" H 3420 3790 50  0001 C CNN
	1    3420 3790
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:GND_USB #PWR?
U 1 1 5BAEB774
P 8910 3690
F 0 "#PWR?" H 8910 3440 50  0001 C CNN
F 1 "GND_USB" H 8910 3540 50  0000 C CNN
F 2 "" H 8910 3690 50  0001 C CNN
F 3 "" H 8910 3690 50  0001 C CNN
	1    8910 3690
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:+5V_USB #PWR?
U 1 1 5BAEE5F8
P 3420 2890
F 0 "#PWR?" H 3420 2740 50  0001 C CNN
F 1 "+5V_USB" H 3330 3030 50  0000 C CNN
F 2 "" H 3420 2890 50  0001 C CNN
F 3 "" H 3420 2890 50  0001 C CNN
	1    3420 2890
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:+5V_USB #PWR?
U 1 1 5BAEE620
P 3620 2890
F 0 "#PWR?" H 3620 2740 50  0001 C CNN
F 1 "+5V_USB" H 3710 3030 50  0000 C CNN
F 2 "" H 3620 2890 50  0001 C CNN
F 3 "" H 3620 2890 50  0001 C CNN
	1    3620 2890
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:C_Custom C?
U 1 1 5BAEE754
P 6150 3720
F 0 "C?" H 6175 3820 50  0000 L CNN
F 1 "47pF" H 6175 3620 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 6188 3570 50  0001 C CNN
F 3 "" H 6175 3820 50  0001 C CNN
F 4 "0603" H 6000 3820 50  0000 R CNN "display_footprint"
F 5 "50V" H 6000 3720 50  0000 R CNN "Voltage"
F 6 "NP0" H 6000 3620 50  0000 R CNN "Dielectric"
F 7 "478-1171-1-ND" H 6575 4220 60  0001 C CNN "Digi-Key PN"
	1    6150 3720
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:C_Custom C?
U 1 1 5BAEE8C5
P 3970 4840
F 0 "C?" H 3995 4940 50  0000 L CNN
F 1 "0.1uF" H 3995 4740 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 4008 4690 50  0001 C CNN
F 3 "" H 3995 4940 50  0001 C CNN
F 4 "0603" H 3820 4940 50  0000 R CNN "display_footprint"
F 5 "50V" H 3820 4840 50  0000 R CNN "Voltage"
F 6 "X7R" H 3820 4740 50  0000 R CNN "Dielectric"
F 7 "311-1344-1-ND" H 4395 5340 60  0001 C CNN "Digi-Key PN"
	1    3970 4840
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:C_Custom C?
U 1 1 5BAF11F6
P 4650 4840
F 0 "C?" H 4675 4940 50  0000 L CNN
F 1 "4.7uF" H 4675 4740 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 4688 4690 50  0001 C CNN
F 3 "" H 4675 4940 50  0001 C CNN
F 4 "0805" H 4500 4940 50  0000 R CNN "display_footprint"
F 5 "10V" H 4500 4840 50  0000 R CNN "Voltage"
F 6 "X7R" H 4500 4740 50  0000 R CNN "Dielectric"
F 7 "1276-2972-1-ND" H 5075 5340 60  0001 C CNN "Digi-Key PN"
	1    4650 4840
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:GND_USB #PWR?
U 1 1 5BAF15F7
P 6150 3870
F 0 "#PWR?" H 6150 3620 50  0001 C CNN
F 1 "GND_USB" H 6150 3720 50  0000 C CNN
F 2 "" H 6150 3870 50  0001 C CNN
F 3 "" H 6150 3870 50  0001 C CNN
	1    6150 3870
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:GND_USB #PWR?
U 1 1 5BAF168D
P 3970 4990
F 0 "#PWR?" H 3970 4740 50  0001 C CNN
F 1 "GND_USB" H 3970 4840 50  0000 C CNN
F 2 "" H 3970 4990 50  0001 C CNN
F 3 "" H 3970 4990 50  0001 C CNN
	1    3970 4990
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:GND_USB #PWR?
U 1 1 5BAF16A2
P 4650 4990
F 0 "#PWR?" H 4650 4740 50  0001 C CNN
F 1 "GND_USB" H 4650 4840 50  0000 C CNN
F 2 "" H 4650 4990 50  0001 C CNN
F 3 "" H 4650 4990 50  0001 C CNN
	1    4650 4990
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:+5V_USB #PWR?
U 1 1 5BAF170B
P 3280 4690
F 0 "#PWR?" H 3280 4540 50  0001 C CNN
F 1 "+5V_USB" H 3280 4830 50  0000 C CNN
F 2 "" H 3280 4690 50  0001 C CNN
F 3 "" H 3280 4690 50  0001 C CNN
	1    3280 4690
	-1   0    0    -1  
$EndComp
$Comp
L Custom_Library:+5V_USB #PWR?
U 1 1 5BAF1727
P 3970 4690
F 0 "#PWR?" H 3970 4540 50  0001 C CNN
F 1 "+5V_USB" H 3970 4830 50  0000 C CNN
F 2 "" H 3970 4690 50  0001 C CNN
F 3 "" H 3970 4690 50  0001 C CNN
	1    3970 4690
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:+5V_USB #PWR?
U 1 1 5BAF173C
P 4650 4690
F 0 "#PWR?" H 4650 4540 50  0001 C CNN
F 1 "+5V_USB" H 4650 4830 50  0000 C CNN
F 2 "" H 4650 4690 50  0001 C CNN
F 3 "" H 4650 4690 50  0001 C CNN
	1    4650 4690
	1    0    0    -1  
$EndComp
Text GLabel 2870 3090 0    50   Output ~ 0
USB_UART_RX_ISO
Text GLabel 2870 3190 0    50   Input ~ 0
USB_UART_TX_ISO
NoConn ~ 2870 3290
NoConn ~ 2870 3390
NoConn ~ 8610 3490
$Comp
L Custom_Library:C_Custom C?
U 1 1 5BAF24FB
P 1510 3830
F 0 "C?" H 1535 3930 50  0000 L CNN
F 1 "0.1uF" H 1535 3730 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 1548 3680 50  0001 C CNN
F 3 "" H 1535 3930 50  0001 C CNN
F 4 "0603" H 1360 3930 50  0000 R CNN "display_footprint"
F 5 "50V" H 1360 3830 50  0000 R CNN "Voltage"
F 6 "X7R" H 1360 3730 50  0000 R CNN "Dielectric"
F 7 "311-1344-1-ND" H 1935 4330 60  0001 C CNN "Digi-Key PN"
	1    1510 3830
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:R_Custom R?
U 1 1 5BAF2627
P 1510 3400
F 0 "R?" H 1450 3400 50  0000 R CNN
F 1 "10k" V 1510 3400 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" H 1510 3400 50  0001 C CNN
F 3 "" H 1510 3400 50  0001 C CNN
F 4 "0603" H 1610 3490 50  0000 L CNN "display_footprint"
F 5 "1%" H 1610 3400 50  0000 L CNN "Tolerance"
F 6 "1/10W" H 1620 3320 50  0000 L CNN "Wattage"
F 7 "RMCF0603FT10K0CT-ND" H 1810 3800 60  0001 C CNN "Digi-Key PN"
	1    1510 3400
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:GND_USB #PWR?
U 1 1 5BAF2C9F
P 1510 3980
F 0 "#PWR?" H 1510 3730 50  0001 C CNN
F 1 "GND_USB" H 1510 3830 50  0000 C CNN
F 2 "" H 1510 3980 50  0001 C CNN
F 3 "" H 1510 3980 50  0001 C CNN
	1    1510 3980
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:+5V_USB #PWR?
U 1 1 5BAF2EC2
P 1510 3250
F 0 "#PWR?" H 1510 3100 50  0001 C CNN
F 1 "+5V_USB" H 1510 3390 50  0000 C CNN
F 2 "" H 1510 3250 50  0001 C CNN
F 3 "" H 1510 3250 50  0001 C CNN
	1    1510 3250
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:C_Custom C?
U 1 1 5BAFEC78
P 6980 3720
F 0 "C?" H 7005 3820 50  0000 L CNN
F 1 "47pF" H 7005 3620 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 7018 3570 50  0001 C CNN
F 3 "" H 7005 3820 50  0001 C CNN
F 4 "0603" H 6830 3820 50  0000 R CNN "display_footprint"
F 5 "50V" H 6830 3720 50  0000 R CNN "Voltage"
F 6 "NP0" H 6830 3620 50  0000 R CNN "Dielectric"
F 7 "478-1171-1-ND" H 7405 4220 60  0001 C CNN "Digi-Key PN"
	1    6980 3720
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:GND_USB #PWR?
U 1 1 5BAFEC7F
P 6980 3870
F 0 "#PWR?" H 6980 3620 50  0001 C CNN
F 1 "GND_USB" H 6980 3720 50  0000 C CNN
F 2 "" H 6980 3870 50  0001 C CNN
F 3 "" H 6980 3870 50  0001 C CNN
	1    6980 3870
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:C_Custom C?
U 1 1 5BAFEEB4
P 3280 4840
F 0 "C?" H 3305 4940 50  0000 L CNN
F 1 "0.1uF" H 3305 4740 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 3318 4690 50  0001 C CNN
F 3 "" H 3305 4940 50  0001 C CNN
F 4 "0603" H 3130 4940 50  0000 R CNN "display_footprint"
F 5 "50V" H 3130 4840 50  0000 R CNN "Voltage"
F 6 "X7R" H 3130 4740 50  0000 R CNN "Dielectric"
F 7 "311-1344-1-ND" H 3705 5340 60  0001 C CNN "Digi-Key PN"
	1    3280 4840
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:GND_USB #PWR?
U 1 1 5BAFEEBB
P 3280 4990
F 0 "#PWR?" H 3280 4740 50  0001 C CNN
F 1 "GND_USB" H 3280 4840 50  0000 C CNN
F 2 "" H 3280 4990 50  0001 C CNN
F 3 "" H 3280 4990 50  0001 C CNN
	1    3280 4990
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:C_Custom C?
U 1 1 5BB0046F
P 4880 3940
F 0 "C?" H 4905 4040 50  0000 L CNN
F 1 "0.1uF" H 4905 3840 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 4918 3790 50  0001 C CNN
F 3 "" H 4905 4040 50  0001 C CNN
F 4 "0603" H 4730 4040 50  0000 R CNN "display_footprint"
F 5 "50V" H 4730 3940 50  0000 R CNN "Voltage"
F 6 "X7R" H 4730 3840 50  0000 R CNN "Dielectric"
F 7 "311-1344-1-ND" H 5305 4440 60  0001 C CNN "Digi-Key PN"
	1    4880 3940
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:GND_USB #PWR?
U 1 1 5BB00476
P 4880 4090
F 0 "#PWR?" H 4880 3840 50  0001 C CNN
F 1 "GND_USB" H 4880 3940 50  0000 C CNN
F 2 "" H 4880 4090 50  0001 C CNN
F 3 "" H 4880 4090 50  0001 C CNN
	1    4880 4090
	1    0    0    -1  
$EndComp
Wire Wire Line
	4170 3090 4880 3090
Wire Wire Line
	4880 3090 4880 3790
$Comp
L Custom_Library:GND_USB #PWR?
U 1 1 5BB00D72
P 6730 2620
F 0 "#PWR?" H 6730 2370 50  0001 C CNN
F 1 "GND_USB" H 6700 2470 50  0000 C CNN
F 2 "" H 6730 2620 50  0001 C CNN
F 3 "" H 6730 2620 50  0001 C CNN
	1    6730 2620
	1    0    0    -1  
$EndComp
Wire Wire Line
	7280 2220 7420 2220
Wire Wire Line
	7420 2020 7420 2220
Connection ~ 7420 2220
Wire Wire Line
	7280 2020 7420 2020
$Comp
L Custom_Library:C_Custom C?
U 1 1 5BB03D51
P 7900 2370
F 0 "C?" H 7925 2470 50  0000 L CNN
F 1 "0.1uF" H 7925 2270 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 7938 2220 50  0001 C CNN
F 3 "" H 7925 2470 50  0001 C CNN
F 4 "0603" H 7750 2470 50  0000 R CNN "display_footprint"
F 5 "50V" H 7750 2370 50  0000 R CNN "Voltage"
F 6 "X7R" H 7750 2270 50  0000 R CNN "Dielectric"
F 7 "311-1344-1-ND" H 8325 2870 60  0001 C CNN "Digi-Key PN"
	1    7900 2370
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:GND_USB #PWR?
U 1 1 5BB03D58
P 7900 2520
F 0 "#PWR?" H 7900 2270 50  0001 C CNN
F 1 "GND_USB" H 7900 2370 50  0000 C CNN
F 2 "" H 7900 2520 50  0001 C CNN
F 3 "" H 7900 2520 50  0001 C CNN
	1    7900 2520
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:C_Custom C?
U 1 1 5BB040A2
P 5760 2420
F 0 "C?" H 5785 2520 50  0000 L CNN
F 1 "0.1uF" H 5785 2320 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 5798 2270 50  0001 C CNN
F 3 "" H 5785 2520 50  0001 C CNN
F 4 "0603" H 5610 2520 50  0000 R CNN "display_footprint"
F 5 "50V" H 5610 2420 50  0000 R CNN "Voltage"
F 6 "X7R" H 5610 2320 50  0000 R CNN "Dielectric"
F 7 "311-1344-1-ND" H 6185 2920 60  0001 C CNN "Digi-Key PN"
	1    5760 2420
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:GND_USB #PWR?
U 1 1 5BB040A9
P 5760 2570
F 0 "#PWR?" H 5760 2320 50  0001 C CNN
F 1 "GND_USB" H 5760 2420 50  0000 C CNN
F 2 "" H 5760 2570 50  0001 C CNN
F 3 "" H 5760 2570 50  0001 C CNN
	1    5760 2570
	1    0    0    -1  
$EndComp
Wire Wire Line
	6180 2220 5760 2220
Wire Wire Line
	5760 2220 5760 2270
Wire Wire Line
	7900 2220 7420 2220
Wire Wire Line
	1510 3550 1510 3590
Connection ~ 1510 3590
Wire Wire Line
	1510 3590 1510 3680
Text GLabel 4170 3590 2    50   UnSpc ~ 0
~USB_ACTIVE
Text GLabel 6640 5270 3    50   UnSpc ~ 0
~USB_ACTIVE
$Comp
L Custom_Library:R_Custom R?
U 1 1 5BB07016
P 6640 4820
F 0 "R?" H 6580 4820 50  0000 R CNN
F 1 "1k" V 6640 4820 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" H 6640 4820 50  0001 C CNN
F 3 "" H 6640 4820 50  0001 C CNN
F 4 "0603" H 6710 4900 50  0000 L CNN "display_footprint"
F 5 "1%" H 6710 4820 50  0000 L CNN "Tolerance"
F 6 "1/10W" H 6710 4750 50  0000 L CNN "Wattage"
F 7 "RMCF0603FT1K00CT-ND" H 6940 5220 60  0001 C CNN "Digi-Key PN"
	1    6640 4820
	1    0    0    -1  
$EndComp
$Comp
L Device:Ferrite_Bead L?
U 1 1 5BB0BDEE
P 8190 3090
F 0 "L?" V 8040 3115 50  0000 C CNN
F 1 "600R 0.5A" V 8340 3090 50  0000 C CNN
F 2 "Inductors_SMD:L_0603" V 8120 3090 50  0001 C CNN
F 3 "~" H 8190 3090 50  0001 C CNN
F 4 "732-2389-1-ND" H 0   0   50  0001 C CNN "Digi-Key PN"
	1    8190 3090
	0    1    1    0   
$EndComp
$Comp
L power:PWR_FLAG #FLG?
U 1 1 5BB0EBE2
P 5180 2160
F 0 "#FLG?" H 5180 2235 50  0001 C CNN
F 1 "PWR_FLAG" H 5180 2310 50  0000 C CNN
F 2 "" H 5180 2160 50  0001 C CNN
F 3 "~" H 5180 2160 50  0001 C CNN
	1    5180 2160
	1    0    0    -1  
$EndComp
Connection ~ 5760 2220
Wire Wire Line
	5180 2160 5180 2220
$Comp
L power:PWR_FLAG #FLG?
U 1 1 5BB10D97
P 7900 2130
F 0 "#FLG?" H 7900 2205 50  0001 C CNN
F 1 "PWR_FLAG" H 7900 2280 50  0000 C CNN
F 2 "" H 7900 2130 50  0001 C CNN
F 3 "~" H 7900 2130 50  0001 C CNN
	1    7900 2130
	1    0    0    -1  
$EndComp
Wire Wire Line
	7900 2130 7900 2220
$Comp
L Custom_Library:+5V_USB #PWR?
U 1 1 5BB118AB
P 6640 4670
F 0 "#PWR?" H 6640 4520 50  0001 C CNN
F 1 "+5V_USB" H 6640 4810 50  0000 C CNN
F 2 "" H 6640 4670 50  0001 C CNN
F 3 "" H 6640 4670 50  0001 C CNN
	1    6640 4670
	1    0    0    -1  
$EndComp
Text Label 4270 3290 0    50   ~ 0
BRIDGE_USB+
Text Label 4270 3390 0    50   ~ 0
BRIDGE_USB-
Text Label 7280 3290 0    50   ~ 0
CONN_USB+
Text Label 7280 3390 0    50   ~ 0
CONN_USB-
Wire Wire Line
	4170 3290 5430 3290
Wire Wire Line
	4170 3390 5430 3390
Wire Wire Line
	5730 3290 6150 3290
$Comp
L Custom_Library:TPD3S014DBVR U?
U 1 1 5BBEE4ED
P 6730 2220
F 0 "U?" H 7030 1870 50  0000 L CNN
F 1 "TPD3S014DBVR" H 6730 2570 50  0000 C CNN
F 2 "TO_SOT_Packages_SMD:SOT-23-6" H 6880 1670 50  0001 L CNN
F 3 "http://www.ti.com/lit/ds/symlink/tpd3s014.pdf" H 6880 1470 50  0001 L CNN
F 4 "296-38835-1-ND" H 6880 1570 50  0001 L CNN "Digi-Key PN"
	1    6730 2220
	-1   0    0    -1  
$EndComp
$Comp
L Custom_Library:+5V_USB #PWR?
U 1 1 5BBEEF4D
P 5760 2140
F 0 "#PWR?" H 5760 1990 50  0001 C CNN
F 1 "+5V_USB" H 5760 2280 50  0000 C CNN
F 2 "" H 5760 2140 50  0001 C CNN
F 3 "" H 5760 2140 50  0001 C CNN
	1    5760 2140
	1    0    0    -1  
$EndComp
Wire Wire Line
	5760 2140 5760 2220
Wire Wire Line
	6980 2620 6980 3390
Wire Wire Line
	7080 2620 7080 3290
$Comp
L Custom_Library:R_Custom R?
U 1 1 5BBF0F91
P 5580 3290
F 0 "R?" V 5960 3290 50  0000 C CNN
F 1 "27" V 5580 3290 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" H 5580 3290 50  0001 C CNN
F 3 "" H 5580 3290 50  0001 C CNN
F 4 "0603" V 5877 3290 50  0000 C CNN "display_footprint"
F 5 "1%" V 5786 3290 50  0000 C CNN "Tolerance"
F 6 "1/10W" V 5695 3290 50  0000 C CNN "Wattage"
F 7 "RMCF0603FT27R0CT-ND" H 5880 3690 60  0001 C CNN "Digi-Key PN"
	1    5580 3290
	0    1    -1   0   
$EndComp
Wire Wire Line
	6150 3570 6150 3290
Connection ~ 6150 3290
Wire Wire Line
	6150 3290 7080 3290
Wire Wire Line
	6980 3570 6980 3390
$Comp
L Device:LED D?
U 1 1 5BBF2083
P 6640 5120
F 0 "D?" V 6678 5003 50  0000 R CNN
F 1 "Yellow" V 6587 5003 50  0000 R CNN
F 2 "LEDs:LED_0603" H 6640 5120 50  0001 C CNN
F 3 "~" H 6640 5120 50  0001 C CNN
F 4 "160-1448-1-ND" H 0   0   50  0001 C CNN "Digi-Key PN"
	1    6640 5120
	0    -1   -1   0   
$EndComp
$Comp
L Connector:USB_B_Mini J?
U 1 1 5BAEA883
P 8910 3290
F 0 "J?" H 8681 3281 50  0000 R CNN
F 1 "USB_B_Mini" H 8681 3190 50  0000 R CNN
F 2 "Connectors:USB_Mini-B" H 9060 3240 50  0001 C CNN
F 3 "~" H 9060 3240 50  0001 C CNN
F 4 "732-2109-1-ND" H 0   0   50  0001 C CNN "Digi-Key PN"
	1    8910 3290
	-1   0    0    -1  
$EndComp
$Comp
L Device:Ferrite_Bead L?
U 1 1 5BBF2600
P 9530 3760
F 0 "L?" V 9380 3785 50  0000 C CNN
F 1 "600R 0.5A" V 9680 3760 50  0000 C CNN
F 2 "Inductors_SMD:L_0603" V 9460 3760 50  0001 C CNN
F 3 "~" H 9530 3760 50  0001 C CNN
F 4 "732-2389-1-ND" H 0   0   50  0001 C CNN "Digi-Key PN"
	1    9530 3760
	0    1    1    0   
$EndComp
Wire Wire Line
	9380 3760 9010 3760
Wire Wire Line
	9010 3760 9010 3690
$Comp
L Custom_Library:GND_USB #PWR?
U 1 1 5BBF2AE3
P 9980 3830
F 0 "#PWR?" H 9980 3580 50  0001 C CNN
F 1 "GND_USB" H 9980 3680 50  0000 C CNN
F 2 "" H 9980 3830 50  0001 C CNN
F 3 "" H 9980 3830 50  0001 C CNN
	1    9980 3830
	1    0    0    -1  
$EndComp
Wire Wire Line
	9980 3830 9980 3760
Wire Wire Line
	9980 3760 9680 3760
Wire Wire Line
	7080 3290 8610 3290
Connection ~ 7080 3290
Wire Wire Line
	6980 3390 8610 3390
Connection ~ 6980 3390
Wire Wire Line
	8340 3090 8610 3090
Wire Wire Line
	8040 3090 7420 3090
Wire Wire Line
	7420 2220 7420 3090
Wire Wire Line
	5180 2220 5760 2220
Wire Wire Line
	1510 3590 2870 3590
$Comp
L Custom_Library:COM_Port_Settings DOC?
U 1 1 5BF874C4
P 8920 5470
F 0 "DOC?" H 8920 5870 60  0001 C CNN
F 1 "COM_Port_Settings" H 8920 5970 60  0001 C CNN
F 2 "" H 8920 5970 60  0001 C CNN
F 3 "" H 8920 5970 60  0001 C CNN
F 4 "115200 bps" H 9670 5620 60  0000 R CNN "Baud_Rate"
F 5 "8 bit" H 9670 5520 60  0000 R CNN "Data_Length"
F 6 "None" H 9670 5420 60  0000 R CNN "Parity"
F 7 "1" H 9670 5320 60  0000 R CNN "Stop_Bits"
F 8 "None" H 9670 5220 60  0000 R CNN "Flow_Control"
	1    8920 5470
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:LT6700-1-S6 U?
U 1 1 5BF9D1D8
P 2790 6840
F 0 "U?" H 3090 6340 50  0000 C CNN
F 1 "LT6700-1-S6" H 2790 6840 50  0000 C CNN
F 2 "TO_SOT_Packages_SMD:TSOT-23-6" H 2790 6840 60  0001 C CNN
F 3 "http://www.analog.com/media/en/technical-documentation/data-sheets/6700123fh.pdf" H 2790 6840 60  0001 C CNN
F 4 "LT6700CS6-1#TRMPBFCT-ND" H 2790 6840 50  0001 C CNN "Digi-Key PN"
	1    2790 6840
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:R_Custom R?
U 1 1 5BF9D312
P 1840 6830
F 0 "R?" H 1780 6830 50  0000 R CNN
F 1 "6.04k" V 1840 6830 40  0000 C CNN
F 2 "Resistors_SMD:R_0603" H 1840 6830 50  0001 C CNN
F 3 "" H 1840 6830 50  0001 C CNN
F 4 "0603" H 1940 6920 50  0000 L CNN "display_footprint"
F 5 "1%" H 1940 6830 50  0000 L CNN "Tolerance"
F 6 "1/10W" H 1950 6750 50  0000 L CNN "Wattage"
F 7 "RMCF0603FT6K04CT-ND" H 2140 7230 60  0001 C CNN "Digi-Key PN"
	1    1840 6830
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:R_Custom R?
U 1 1 5BF9D416
P 1840 7320
F 0 "R?" H 1780 7320 50  0000 R CNN
F 1 "40.2k" V 1840 7320 40  0000 C CNN
F 2 "Resistors_SMD:R_0603" H 1840 7320 50  0001 C CNN
F 3 "" H 1840 7320 50  0001 C CNN
F 4 "0603" H 1940 7410 50  0000 L CNN "display_footprint"
F 5 "1%" H 1940 7320 50  0000 L CNN "Tolerance"
F 6 "1/10W" H 1950 7240 50  0000 L CNN "Wattage"
F 7 "311-40.2KHRCT-ND" H 2140 7720 60  0001 C CNN "Digi-Key PN"
	1    1840 7320
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:R_Custom R?
U 1 1 5BF9D46E
P 1840 6290
F 0 "R?" H 1780 6290 50  0000 R CNN
F 1 "487k" V 1840 6290 40  0000 C CNN
F 2 "Resistors_SMD:R_0603" H 1840 6290 50  0001 C CNN
F 3 "" H 1840 6290 50  0001 C CNN
F 4 "0603" H 1940 6380 50  0000 L CNN "display_footprint"
F 5 "1%" H 1940 6290 50  0000 L CNN "Tolerance"
F 6 "1/10W" H 1950 6210 50  0000 L CNN "Wattage"
F 7 "311-487KHRCT-ND" H 2140 6690 60  0001 C CNN "Digi-Key PN"
	1    1840 6290
	1    0    0    -1  
$EndComp
Wire Wire Line
	2240 6590 1840 6590
Wire Wire Line
	1840 6590 1840 6440
Wire Wire Line
	1840 6590 1840 6680
Connection ~ 1840 6590
Wire Wire Line
	2240 7090 1840 7090
Wire Wire Line
	1840 7090 1840 6980
Wire Wire Line
	1840 7090 1840 7170
Connection ~ 1840 7090
$Comp
L Custom_Library:+5V_USB #PWR?
U 1 1 5BFA0DB6
P 2790 6240
F 0 "#PWR?" H 2790 6090 50  0001 C CNN
F 1 "+5V_USB" H 2790 6380 50  0000 C CNN
F 2 "" H 2790 6240 50  0001 C CNN
F 3 "" H 2790 6240 50  0001 C CNN
	1    2790 6240
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:+5V_USB #PWR?
U 1 1 5BFA0E0D
P 1840 6140
F 0 "#PWR?" H 1840 5990 50  0001 C CNN
F 1 "+5V_USB" H 1840 6280 50  0000 C CNN
F 2 "" H 1840 6140 50  0001 C CNN
F 3 "" H 1840 6140 50  0001 C CNN
	1    1840 6140
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:R_Custom R?
U 1 1 5BFA54D6
P 3470 6240
F 0 "R?" H 3410 6240 50  0000 R CNN
F 1 "10k" V 3470 6240 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" H 3470 6240 50  0001 C CNN
F 3 "" H 3470 6240 50  0001 C CNN
F 4 "0603" H 3570 6330 50  0000 L CNN "display_footprint"
F 5 "1%" H 3570 6240 50  0000 L CNN "Tolerance"
F 6 "1/10W" H 3580 6160 50  0000 L CNN "Wattage"
F 7 "RMCF0603FT10K0CT-ND" H 3770 6640 60  0001 C CNN "Digi-Key PN"
	1    3470 6240
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:+5V_USB #PWR?
U 1 1 5BFA54DD
P 3470 6090
F 0 "#PWR?" H 3470 5940 50  0001 C CNN
F 1 "+5V_USB" H 3470 6230 50  0000 C CNN
F 2 "" H 3470 6090 50  0001 C CNN
F 3 "" H 3470 6090 50  0001 C CNN
	1    3470 6090
	1    0    0    -1  
$EndComp
Wire Wire Line
	3340 7090 3470 7090
Wire Wire Line
	3470 7090 3470 6590
Wire Wire Line
	3340 6590 3470 6590
Connection ~ 3470 6590
Wire Wire Line
	3470 6590 3470 6390
$Comp
L Custom_Library:C_Custom C?
U 1 1 5BFA8DF9
P 4440 7310
AR Path="/5BAAE1F3/5BFA8DF9" Ref="C?"  Part="1" 
AR Path="/5BAAE1CB/5BFA8DF9" Ref="C?"  Part="1" 
AR Path="/5BE48F98/5BFA8DF9" Ref="C?"  Part="1" 
AR Path="/5C1D5CD8/5BFA8DF9" Ref="C?"  Part="1" 
AR Path="/5CD9EF7E/5BFA8DF9" Ref="C?"  Part="1" 
F 0 "C?" H 4465 7410 50  0000 L CNN
F 1 "0.1uF" H 4465 7210 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 4478 7160 50  0001 C CNN
F 3 "" H 4465 7410 50  0001 C CNN
F 4 "311-1344-1-ND" H 4865 7810 60  0001 C CNN "Digi-Key PN"
F 5 "0603" H 4290 7410 50  0000 R CNN "display_footprint"
F 6 "50V" H 4290 7310 50  0000 R CNN "Voltage"
F 7 "X7R" H 4290 7210 50  0000 R CNN "Dielectric"
	1    4440 7310
	-1   0    0    -1  
$EndComp
$Comp
L Custom_Library:GND_USB #PWR?
U 1 1 5BFAE111
P 1840 7470
F 0 "#PWR?" H 1840 7220 50  0001 C CNN
F 1 "GND_USB" H 1840 7320 50  0000 C CNN
F 2 "" H 1840 7470 50  0001 C CNN
F 3 "" H 1840 7470 50  0001 C CNN
	1    1840 7470
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:GND_USB #PWR?
U 1 1 5BFAE1A5
P 2790 7440
F 0 "#PWR?" H 2790 7190 50  0001 C CNN
F 1 "GND_USB" H 2790 7290 50  0000 C CNN
F 2 "" H 2790 7440 50  0001 C CNN
F 3 "" H 2790 7440 50  0001 C CNN
	1    2790 7440
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:GND_USB #PWR?
U 1 1 5BFAE29A
P 4440 7460
F 0 "#PWR?" H 4440 7210 50  0001 C CNN
F 1 "GND_USB" H 4440 7310 50  0000 C CNN
F 2 "" H 4440 7460 50  0001 C CNN
F 3 "" H 4440 7460 50  0001 C CNN
	1    4440 7460
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:GND_USB #PWR?
U 1 1 5BFAE3A9
P 4590 6690
F 0 "#PWR?" H 4590 6440 50  0001 C CNN
F 1 "GND_USB" H 4590 6540 50  0000 C CNN
F 2 "" H 4590 6690 50  0001 C CNN
F 3 "" H 4590 6690 50  0001 C CNN
	1    4590 6690
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:+5V_USB #PWR?
U 1 1 5BFAE4B8
P 4590 6490
F 0 "#PWR?" H 4590 6340 50  0001 C CNN
F 1 "+5V_USB" H 4590 6630 50  0000 C CNN
F 2 "" H 4590 6490 50  0001 C CNN
F 3 "" H 4590 6490 50  0001 C CNN
	1    4590 6490
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:+5V_USB #PWR?
U 1 1 5BFAE545
P 4440 7160
F 0 "#PWR?" H 4440 7010 50  0001 C CNN
F 1 "+5V_USB" H 4440 7300 50  0000 C CNN
F 2 "" H 4440 7160 50  0001 C CNN
F 3 "" H 4440 7160 50  0001 C CNN
	1    4440 7160
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:74LVC1G06_Power U?
U 1 1 5BFB06FB
P 4590 6590
F 0 "U?" H 4690 6740 50  0000 L CNN
F 1 "74LVC1G06" H 4690 6490 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-353_SC-70-5" H 4590 6640 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/sn74lvc1g06.pdf" H 4590 6590 50  0001 C CNN
F 4 "296-8484-1-ND" H 4590 6590 50  0001 C CNN "Digi-Key PN"
	1    4590 6590
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D?
U 1 1 5BFB28AA
P 5160 6320
AR Path="/5BB844FD/5BFB28AA" Ref="D?"  Part="1" 
AR Path="/5BF346B3/5BFB28AA" Ref="D?"  Part="1" 
AR Path="/5BAAE1F3/5BFB28AA" Ref="D?"  Part="1" 
AR Path="/5C1D5CD8/5BFB28AA" Ref="D?"  Part="1" 
AR Path="/5CD9EF7E/5BFB28AA" Ref="D?"  Part="1" 
F 0 "D?" V 5198 6203 50  0000 R CNN
F 1 "Green" V 5107 6203 50  0000 R CNN
F 2 "LEDs:LED_0603" H 5160 6320 50  0001 C CNN
F 3 "~" H 5160 6320 50  0001 C CNN
F 4 "160-1446-1-ND" H 0   0   50  0001 C CNN "Digi-Key PN"
	1    5160 6320
	0    -1   -1   0   
$EndComp
$Comp
L Custom_Library:R_Custom R?
U 1 1 5BFB28B5
P 5160 6020
AR Path="/5BAAE1F3/5BFB28B5" Ref="R?"  Part="1" 
AR Path="/5BAAE1DC/5BFB28B5" Ref="R?"  Part="1" 
AR Path="/5BAAE16C/5BFB28B5" Ref="R?"  Part="1" 
AR Path="/5BB844FD/5BFB28B5" Ref="R?"  Part="1" 
AR Path="/5BF346B3/5BFB28B5" Ref="R?"  Part="1" 
AR Path="/5C1D5CD8/5BFB28B5" Ref="R?"  Part="1" 
AR Path="/5CD9EF7E/5BFB28B5" Ref="R?"  Part="1" 
F 0 "R?" H 5100 6020 50  0000 R CNN
F 1 "1k" V 5160 6020 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" H 5160 6020 50  0001 C CNN
F 3 "" H 5160 6020 50  0001 C CNN
F 4 "0603" H 5230 6100 50  0000 L CNN "display_footprint"
F 5 "1%" H 5230 6020 50  0000 L CNN "Tolerance"
F 6 "1/10W" H 5240 5950 50  0000 L CNN "Wattage"
F 7 "RMCF0603FT1K00CT-ND" H 5460 6420 60  0001 C CNN "Digi-Key PN"
	1    5160 6020
	-1   0    0    -1  
$EndComp
Wire Wire Line
	4840 6590 5160 6590
Wire Wire Line
	5160 6590 5160 6470
$Comp
L Custom_Library:+5V_USB #PWR?
U 1 1 5BFB3CC8
P 5160 5870
F 0 "#PWR?" H 5160 5720 50  0001 C CNN
F 1 "+5V_USB" H 5160 6010 50  0000 C CNN
F 2 "" H 5160 5870 50  0001 C CNN
F 3 "" H 5160 5870 50  0001 C CNN
	1    5160 5870
	1    0    0    -1  
$EndComp
Text Label 3510 6590 0    50   ~ 0
POS5_USB_PGOOD
Wire Wire Line
	3470 6590 4290 6590
$Comp
L Custom_Library:C_Custom C?
U 1 1 5C037C42
P 3540 7550
AR Path="/5BAAE1F3/5C037C42" Ref="C?"  Part="1" 
AR Path="/5BAAE1CB/5C037C42" Ref="C?"  Part="1" 
AR Path="/5BE48F98/5C037C42" Ref="C?"  Part="1" 
AR Path="/5C1D5CD8/5C037C42" Ref="C?"  Part="1" 
AR Path="/5CD9EF7E/5C037C42" Ref="C?"  Part="1" 
F 0 "C?" H 3565 7650 50  0000 L CNN
F 1 "0.1uF" H 3565 7450 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 3578 7400 50  0001 C CNN
F 3 "" H 3565 7650 50  0001 C CNN
F 4 "311-1344-1-ND" H 3965 8050 60  0001 C CNN "Digi-Key PN"
F 5 "0603" H 3390 7650 50  0000 R CNN "display_footprint"
F 6 "50V" H 3390 7550 50  0000 R CNN "Voltage"
F 7 "X7R" H 3390 7450 50  0000 R CNN "Dielectric"
	1    3540 7550
	-1   0    0    -1  
$EndComp
$Comp
L Custom_Library:GND_USB #PWR?
U 1 1 5C037C49
P 3540 7700
F 0 "#PWR?" H 3540 7450 50  0001 C CNN
F 1 "GND_USB" H 3540 7550 50  0000 C CNN
F 2 "" H 3540 7700 50  0001 C CNN
F 3 "" H 3540 7700 50  0001 C CNN
	1    3540 7700
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:+5V_USB #PWR?
U 1 1 5C037C4F
P 3540 7400
F 0 "#PWR?" H 3540 7250 50  0001 C CNN
F 1 "+5V_USB" H 3540 7540 50  0000 C CNN
F 2 "" H 3540 7400 50  0001 C CNN
F 3 "" H 3540 7400 50  0001 C CNN
	1    3540 7400
	1    0    0    -1  
$EndComp
Wire Wire Line
	5730 3390 6980 3390
$Comp
L Custom_Library:R_Custom R?
U 1 1 5C04BC29
P 5580 3390
F 0 "R?" V 5960 3390 50  0000 C CNN
F 1 "27" V 5580 3390 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" H 5580 3390 50  0001 C CNN
F 3 "" H 5580 3390 50  0001 C CNN
F 4 "0603" V 5877 3390 50  0000 C CNN "display_footprint"
F 5 "1%" V 5786 3390 50  0000 C CNN "Tolerance"
F 6 "1/10W" V 5695 3390 50  0000 C CNN "Wattage"
F 7 "RMCF0603FT27R0CT-ND" H 5880 3790 60  0001 C CNN "Digi-Key PN"
	1    5580 3390
	0    1    1    0   
$EndComp
$Comp
L Custom_Library:TP TP?
U 1 1 5C3525E4
P 4640 2160
F 0 "TP?" H 4640 2310 50  0000 C CNN
F 1 "TP" H 4640 2310 50  0001 C CNN
F 2 "Custom Footprints Library:Test_Point" H 4640 2160 60  0001 C CNN
F 3 "" H 4640 2160 60  0000 C CNN
	1    4640 2160
	1    0    0    -1  
$EndComp
Wire Wire Line
	4640 2160 4640 2220
Wire Wire Line
	4640 2220 5180 2220
Connection ~ 5180 2220
$Comp
L Custom_Library:GND_USB #PWR?
U 1 1 5C355357
P 9880 4440
F 0 "#PWR?" H 9880 4190 50  0001 C CNN
F 1 "GND_USB" H 9880 4290 50  0000 C CNN
F 2 "" H 9880 4440 50  0001 C CNN
F 3 "" H 9880 4440 50  0001 C CNN
	1    9880 4440
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:TP TP?
U 1 1 5C3553C3
P 9880 4440
F 0 "TP?" H 9880 4590 50  0000 C CNN
F 1 "TP" H 9880 4590 50  0001 C CNN
F 2 "Pin_Headers:Pin_Header_Angled_1x01_Pitch2.54mm" H 9880 4440 60  0001 C CNN
F 3 "" H 9880 4440 60  0000 C CNN
	1    9880 4440
	1    0    0    -1  
$EndComp
Text Notes 540  690  0    100  ~ 20
10. USB UART Bridge
$EndSCHEMATC
