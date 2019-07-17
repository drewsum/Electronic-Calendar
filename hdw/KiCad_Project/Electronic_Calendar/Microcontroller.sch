EESchema Schematic File Version 4
LIBS:Electronic_Calendar-cache
EELAYER 29 0
EELAYER END
$Descr A 11000 8500
encoding utf-8
Sheet 5 17
Title ""
Date "2019-04-11"
Rev "A"
Comp "Drew Maatman"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Custom_Library:PIC32MZ2048EFG100_IPT U?
U 1 1 5CAFD57E
P 5460 3560
F 0 "U?" H 7260 1060 50  0000 R CNN
F 1 "PIC32MZ2048EFG100_IPT" H 5460 4160 50  0000 C CNN
F 2 "Housings_QFP:TQFP-100_14x14mm_Pitch0.5mm" H 5460 3560 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/60001320E.pdf" H 5460 3560 50  0001 C CNN
F 4 "ALL" H 5460 3560 50  0001 C CNN "Config"
F 5 "PIC32MZ2048EFG100-I/PT-ND" H 5460 3560 50  0001 C CNN "Digi-Key PN"
	1    5460 3560
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:+3.3V_BCKP #PWR?
U 1 1 5CB01078
P 5310 880
F 0 "#PWR?" H 5310 730 50  0001 C CNN
F 1 "+3.3V_BCKP" H 5310 1020 50  0000 C CNN
F 2 "" H 5310 880 50  0000 C CNN
F 3 "" H 5310 880 50  0000 C CNN
	1    5310 880 
	1    0    0    -1  
$EndComp
Wire Wire Line
	5310 880  5310 920 
Wire Wire Line
	5610 960  5610 920 
Wire Wire Line
	5610 920  5510 920 
Connection ~ 5310 920 
Wire Wire Line
	5310 920  5310 960 
Wire Wire Line
	5310 920  5210 920 
Wire Wire Line
	5010 920  5010 960 
Wire Wire Line
	5110 960  5110 920 
Connection ~ 5110 920 
Wire Wire Line
	5110 920  5010 920 
Wire Wire Line
	5210 960  5210 920 
Connection ~ 5210 920 
Wire Wire Line
	5210 920  5110 920 
Wire Wire Line
	5410 960  5410 920 
Connection ~ 5410 920 
Wire Wire Line
	5410 920  5310 920 
Wire Wire Line
	5510 960  5510 920 
Connection ~ 5510 920 
Wire Wire Line
	5510 920  5410 920 
$Comp
L power:GND #PWR?
U 1 1 5CB03EF2
P 5460 6240
F 0 "#PWR?" H 5460 5990 50  0001 C CNN
F 1 "GND" H 5460 6090 50  0000 C CNN
F 2 "" H 5460 6240 50  0001 C CNN
F 3 "" H 5460 6240 50  0001 C CNN
	1    5460 6240
	1    0    0    -1  
$EndComp
Wire Wire Line
	5460 6240 5460 6200
Wire Wire Line
	5460 6200 5410 6200
Wire Wire Line
	5110 6200 5110 6160
Wire Wire Line
	5460 6200 5510 6200
Wire Wire Line
	5810 6200 5810 6160
Connection ~ 5460 6200
Wire Wire Line
	5210 6160 5210 6200
Connection ~ 5210 6200
Wire Wire Line
	5210 6200 5110 6200
Wire Wire Line
	5310 6160 5310 6200
Connection ~ 5310 6200
Wire Wire Line
	5310 6200 5210 6200
Wire Wire Line
	5410 6160 5410 6200
Connection ~ 5410 6200
Wire Wire Line
	5410 6200 5310 6200
Wire Wire Line
	5510 6160 5510 6200
Connection ~ 5510 6200
Wire Wire Line
	5510 6200 5610 6200
Wire Wire Line
	5610 6160 5610 6200
Connection ~ 5610 6200
Wire Wire Line
	5610 6200 5710 6200
Wire Wire Line
	5710 6160 5710 6200
Connection ~ 5710 6200
Wire Wire Line
	5710 6200 5810 6200
$Comp
L power:GNDA #PWR?
U 1 1 5CB07CEA
P 4810 6240
F 0 "#PWR?" H 4810 5990 50  0001 C CNN
F 1 "GNDA" H 4810 6090 50  0000 C CNN
F 2 "" H 4810 6240 50  0001 C CNN
F 3 "" H 4810 6240 50  0001 C CNN
	1    4810 6240
	1    0    0    -1  
$EndComp
Wire Wire Line
	4810 6160 4810 6240
$Comp
L power:+3.3VA #PWR?
U 1 1 5CB087D9
P 4810 880
F 0 "#PWR?" H 4810 730 50  0001 C CNN
F 1 "+3.3VA" H 4810 1020 50  0000 C CNN
F 2 "" H 4810 880 50  0001 C CNN
F 3 "" H 4810 880 50  0001 C CNN
	1    4810 880 
	1    0    0    -1  
$EndComp
Wire Wire Line
	4810 880  4810 960 
Text GLabel 3460 5910 0    40   Input ~ 8
~MCLR
NoConn ~ 3460 5510
NoConn ~ 3460 5610
NoConn ~ 3460 5310
$Comp
L power:GND #PWR?
U 1 1 5CB14B21
P 3290 5490
F 0 "#PWR?" H 3290 5240 50  0001 C CNN
F 1 "GND" H 3290 5340 50  0000 C CNN
F 2 "" H 3290 5490 50  0001 C CNN
F 3 "" H 3290 5490 50  0001 C CNN
	1    3290 5490
	1    0    0    -1  
$EndComp
Wire Wire Line
	3290 5490 3290 5410
Wire Wire Line
	3290 5410 3460 5410
Text GLabel 3460 2310 0    50   BiDi ~ 0
TEMP_I2C_SDA
Text GLabel 3460 2210 0    50   Output ~ 0
TEMP_I2C_SCL
Text GLabel 3460 5010 0    50   Input ~ 0
POS12_PGOOD
Text GLabel 7460 5310 2    50   Input ~ 0
POS3P3_PGOOD
Text GLabel 7460 5210 2    50   Input ~ 0
Cap_Touch_Power
Text GLabel 7460 3910 2    50   Output ~ 0
Heartbeat_LED
Text GLabel 7460 2410 2    50   Output ~ 0
Reset_LED
Text GLabel 7460 4010 2    50   Output ~ 0
USB_Error_LED
Text GLabel 7460 1210 2    40   Output ~ 0
~JAN_LED
Text GLabel 7460 1310 2    40   Output ~ 0
~FEB_LED
Text GLabel 7460 1410 2    40   Output ~ 0
~MAR_LED
Text GLabel 7460 1510 2    40   Output ~ 0
~APR_LED
Text GLabel 7460 1610 2    40   Output ~ 0
~MAY_LED
Text GLabel 7460 1710 2    40   Output ~ 0
~JUN_LED
Text GLabel 7460 1810 2    40   Output ~ 0
~JUL_LED
Text GLabel 7460 1910 2    40   Output ~ 0
~AUG_LED
Text GLabel 7460 2010 2    40   Output ~ 0
~SEP_LED
Text GLabel 7460 2110 2    40   Output ~ 0
~OCT_LED
Text GLabel 7460 2210 2    40   Output ~ 0
~NOV_LED
Text GLabel 7460 2310 2    40   Output ~ 0
~DEC_LED
Text GLabel 7460 4410 2    40   Input ~ 0
~BCKP_PFO
Text GLabel 7460 4510 2    50   Input ~ 0
BCKP_SYSGD
Text GLabel 7460 4610 2    50   Input ~ 0
BCKP_CAPGD
Text GLabel 7460 4710 2    40   Input ~ 0
~BCKP_CAPFLT
Text GLabel 3460 1710 0    50   Input ~ 0
POS3P3_ADC
Text GLabel 3460 1410 0    50   Input ~ 0
POS12_ISNS_ADC
Text GLabel 3460 1310 0    50   Input ~ 0
POS3P3_ISNS_ADC
Text GLabel 3460 1610 0    50   Input ~ 0
BCKP_IMON_ADC
Text GLabel 3460 1210 0    50   Input ~ 0
POS12_ADC
Text GLabel 3460 1510 0    50   Input ~ 0
POS5_USB_ADC
Text GLabel 7460 5410 2    50   Input ~ 0
POS3P3_PGOOD
Text Notes 8250 5390 0    50   ~ 0
Intentionally Duplicated, using INT3 and INT4 for edge detection
Text GLabel 7460 3310 2    40   Output ~ 0
~SAT_LED
Text GLabel 7460 3210 2    40   Output ~ 0
~FRI_LED
Text GLabel 7460 3110 2    40   Output ~ 0
~THR_LED
Text GLabel 7460 3010 2    40   Output ~ 0
~WED_LED
Text GLabel 7460 2910 2    40   Output ~ 0
~TUE_LED
Text GLabel 7460 2810 2    40   Output ~ 0
~MON_LED
Text GLabel 7460 2710 2    40   Output ~ 0
~SUN_LED
Text GLabel 3460 2760 0    40   Output ~ 0
~Hours0_LED
Text GLabel 3460 2860 0    40   Output ~ 0
~Hours1_LED
Text GLabel 3460 2960 0    40   Output ~ 0
~Hours2_LED
Text GLabel 3460 3060 0    40   Output ~ 0
~Hours3_LED
Text GLabel 3460 3160 0    40   Output ~ 0
~Hours4_LED
Text GLabel 3460 3260 0    40   Output ~ 0
~Hours5_LED
Text GLabel 3460 3360 0    40   Output ~ 0
~Hours6_LED
Text GLabel 3460 4060 0    40   Output ~ 0
~Minutes6_LED
Text GLabel 3460 3960 0    40   Output ~ 0
~Minutes5_LED
Text GLabel 3460 3860 0    40   Output ~ 0
~Minutes4_LED
Text GLabel 3460 3760 0    40   Output ~ 0
~Minutes3_LED
Text GLabel 3460 3660 0    40   Output ~ 0
~Minutes2_LED
Text GLabel 3460 3560 0    40   Output ~ 0
~Minutes1_LED
Text GLabel 3460 3460 0    40   Output ~ 0
~Minutes0_LED
Text GLabel 3460 4310 0    40   Output ~ 0
~Seconds0_LED
Text GLabel 3460 4410 0    40   Output ~ 0
~Seconds1_LED
Text GLabel 3460 4510 0    40   Output ~ 0
~Seconds2_LED
Text GLabel 3460 4610 0    40   Output ~ 0
~Seconds3_LED
Text GLabel 3460 4710 0    40   Output ~ 0
~Seconds4_LED
Text GLabel 3460 4810 0    40   Output ~ 0
~Seconds5_LED
Text GLabel 3460 4910 0    40   Output ~ 0
~Seconds6_LED
Text GLabel 7460 5110 2    50   Output ~ 0
USB_UART_TX
Text GLabel 7460 5010 2    50   Input ~ 0
USB_UART_RX
Text GLabel 7460 5510 2    50   Output ~ 0
Date_B0
Text GLabel 7460 5610 2    50   Output ~ 0
Date_B1
Text GLabel 7460 5710 2    50   Output ~ 0
Date_B2
Text GLabel 7460 3410 2    50   Output ~ 0
Year_B0
Text GLabel 7460 3510 2    50   Output ~ 0
Year_B1
Text GLabel 7460 3610 2    50   Output ~ 0
Year_B2
Text GLabel 7460 4110 2    50   Output ~ 0
Other_Error_LED
Text GLabel 7460 4310 2    50   Output ~ 0
Exception_LED
Text GLabel 7460 4210 2    50   Output ~ 0
Analog_Error_LED
Text GLabel 3460 2110 0    50   Output ~ 0
Date_Decode_Enable
Text GLabel 3460 2560 0    50   BiDi ~ 0
ICSPDAT
Text GLabel 3460 2660 0    50   Input ~ 0
ICSPCLK
Text GLabel 7460 5810 2    40   Output ~ 0
~Date_Decode_1
Text GLabel 7460 5910 2    40   Output ~ 0
~Date_Decode_2
Text GLabel 3460 1810 0    40   Output ~ 0
~Date_Decode_3
Text GLabel 3460 1910 0    40   Output ~ 0
~Date_Decode_4
$EndSCHEMATC
