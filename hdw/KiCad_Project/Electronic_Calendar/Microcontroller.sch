EESchema Schematic File Version 4
LIBS:Electronic_Calendar-cache
EELAYER 29 0
EELAYER END
$Descr A 11000 8500
encoding utf-8
Sheet 6 16
Title "Electronic Calendar"
Date "2019-07-25"
Rev "A"
Comp "Drew Maatman"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Custom_Library:PIC32MZ2048EFG100_IPT U701
U 1 1 5CAFD57E
P 5220 3830
F 0 "U701" H 7020 1330 50  0000 R CNN
F 1 "PIC32MZ2048EFG100_IPT" H 5220 4430 50  0000 C CNN
F 2 "Housings_QFP:TQFP-100_14x14mm_Pitch0.5mm" H 5220 3830 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/60001320E.pdf" H 5220 3830 50  0001 C CNN
F 4 "PIC32MZ2048EFG100-I/PT-ND" H 5220 3830 50  0001 C CNN "Digi-Key PN"
	1    5220 3830
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:+3.3V_BCKP #PWR0704
U 1 1 5CB01078
P 5070 1150
F 0 "#PWR0704" H 5070 1000 50  0001 C CNN
F 1 "+3.3V_BCKP" H 5070 1290 50  0000 C CNN
F 2 "" H 5070 1150 50  0000 C CNN
F 3 "" H 5070 1150 50  0000 C CNN
	1    5070 1150
	1    0    0    -1  
$EndComp
Wire Wire Line
	5070 1150 5070 1190
Wire Wire Line
	5370 1230 5370 1190
Wire Wire Line
	5370 1190 5270 1190
Connection ~ 5070 1190
Wire Wire Line
	5070 1190 5070 1230
Wire Wire Line
	5070 1190 4970 1190
Wire Wire Line
	4770 1190 4770 1230
Wire Wire Line
	4870 1230 4870 1190
Connection ~ 4870 1190
Wire Wire Line
	4870 1190 4770 1190
Wire Wire Line
	4970 1230 4970 1190
Connection ~ 4970 1190
Wire Wire Line
	4970 1190 4870 1190
Wire Wire Line
	5170 1230 5170 1190
Connection ~ 5170 1190
Wire Wire Line
	5170 1190 5070 1190
Wire Wire Line
	5270 1230 5270 1190
Connection ~ 5270 1190
Wire Wire Line
	5270 1190 5170 1190
$Comp
L power:GND #PWR0705
U 1 1 5CB03EF2
P 5220 6510
F 0 "#PWR0705" H 5220 6260 50  0001 C CNN
F 1 "GND" H 5220 6360 50  0000 C CNN
F 2 "" H 5220 6510 50  0001 C CNN
F 3 "" H 5220 6510 50  0001 C CNN
	1    5220 6510
	1    0    0    -1  
$EndComp
Wire Wire Line
	5220 6510 5220 6470
Wire Wire Line
	5220 6470 5170 6470
Wire Wire Line
	4870 6470 4870 6430
Wire Wire Line
	5220 6470 5270 6470
Wire Wire Line
	5570 6470 5570 6430
Connection ~ 5220 6470
Wire Wire Line
	4970 6430 4970 6470
Connection ~ 4970 6470
Wire Wire Line
	4970 6470 4870 6470
Wire Wire Line
	5070 6430 5070 6470
Connection ~ 5070 6470
Wire Wire Line
	5070 6470 4970 6470
Wire Wire Line
	5170 6430 5170 6470
Connection ~ 5170 6470
Wire Wire Line
	5170 6470 5070 6470
Wire Wire Line
	5270 6430 5270 6470
Connection ~ 5270 6470
Wire Wire Line
	5270 6470 5370 6470
Wire Wire Line
	5370 6430 5370 6470
Connection ~ 5370 6470
Wire Wire Line
	5370 6470 5470 6470
Wire Wire Line
	5470 6430 5470 6470
Connection ~ 5470 6470
Wire Wire Line
	5470 6470 5570 6470
$Comp
L power:GNDA #PWR0703
U 1 1 5CB07CEA
P 4570 6510
F 0 "#PWR0703" H 4570 6260 50  0001 C CNN
F 1 "GNDA" H 4570 6360 50  0000 C CNN
F 2 "" H 4570 6510 50  0001 C CNN
F 3 "" H 4570 6510 50  0001 C CNN
	1    4570 6510
	1    0    0    -1  
$EndComp
Wire Wire Line
	4570 6430 4570 6510
$Comp
L power:+3.3VA #PWR0702
U 1 1 5CB087D9
P 4570 1150
F 0 "#PWR0702" H 4570 1000 50  0001 C CNN
F 1 "+3.3VA" H 4570 1290 50  0000 C CNN
F 2 "" H 4570 1150 50  0001 C CNN
F 3 "" H 4570 1150 50  0001 C CNN
	1    4570 1150
	1    0    0    -1  
$EndComp
Wire Wire Line
	4570 1150 4570 1230
Text GLabel 3220 6180 0    40   Input ~ 8
~MCLR
NoConn ~ 3220 5780
NoConn ~ 3220 5880
NoConn ~ 3220 5580
$Comp
L power:GND #PWR0701
U 1 1 5CB14B21
P 3050 5760
F 0 "#PWR0701" H 3050 5510 50  0001 C CNN
F 1 "GND" H 3050 5610 50  0000 C CNN
F 2 "" H 3050 5760 50  0001 C CNN
F 3 "" H 3050 5760 50  0001 C CNN
	1    3050 5760
	1    0    0    -1  
$EndComp
Wire Wire Line
	3050 5760 3050 5680
Wire Wire Line
	3050 5680 3220 5680
Text GLabel 3220 2580 0    50   BiDi ~ 0
TEMP_I2C_SDA
Text GLabel 3220 2480 0    50   Output ~ 0
TEMP_I2C_SCL
Text GLabel 7220 5580 2    50   Input ~ 0
POS12_PGOOD
Text GLabel 2230 4930 0    50   Input ~ 0
POS3P3_PGOOD
Text GLabel 7220 5480 2    50   Input ~ 0
Cap_Touch_Power
Text GLabel 8010 3900 2    50   Output ~ 0
Heartbeat_LED
Text GLabel 7220 2680 2    50   Output ~ 0
Reset_LED
Text GLabel 8240 4390 2    50   Output ~ 0
USB_Error_LED
Text GLabel 1840 1670 0    50   Input ~ 0
POS3P3_ADC
Text GLabel 8920 2420 2    50   Input ~ 0
POS12_ISNS_ADC
Text GLabel 3220 1580 0    50   Input ~ 0
POS3P3_ISNS_ADC
Text GLabel 3220 1480 0    50   Input ~ 0
POS12_ADC
Text GLabel 1430 1830 2    50   Input ~ 0
POS5_USB_ADC
Text GLabel 3220 1780 0    40   Output ~ 0
~FRI_LED
Text GLabel 3220 1680 0    40   Output ~ 0
~THR_LED
Text GLabel 7220 4780 2    40   Output ~ 0
~WED_LED
Text GLabel 7220 4380 2    40   Output ~ 0
~TUE_LED
Text GLabel 7220 4480 2    40   Output ~ 0
~MON_LED
Text GLabel 3220 5280 0    40   Output ~ 0
~SUN_LED
Text GLabel 3220 3230 0    40   Output ~ 0
~Hours1_LED
Text GLabel 3220 3130 0    40   Output ~ 0
~Hours3_LED
Text GLabel 3220 3030 0    40   Output ~ 0
~Hours5_LED
Text GLabel 7220 3380 2    40   Output ~ 0
~Minutes6_LED
Text GLabel 7220 3480 2    40   Output ~ 0
~Minutes5_LED
Text GLabel 7220 3280 2    40   Output ~ 0
~Minutes4_LED
Text GLabel 3220 1980 0    40   Output ~ 0
~Minutes3_LED
Text GLabel 7220 3180 2    40   Output ~ 0
~Minutes2_LED
Text GLabel 7220 6180 2    40   Output ~ 0
~Minutes1_LED
Text GLabel 7220 5980 2    40   Output ~ 0
~Minutes0_LED
Text GLabel 7220 4280 2    40   Output ~ 0
~Seconds0_LED
Text GLabel 7220 3080 2    40   Output ~ 0
~Seconds1_LED
Text GLabel 3220 2080 0    40   Output ~ 0
~Seconds2_LED
Text GLabel 7220 6080 2    40   Output ~ 0
~Seconds3_LED
Text GLabel 3220 2180 0    40   Output ~ 0
~Seconds4_LED
Text GLabel 7220 5880 2    40   Output ~ 0
~Seconds5_LED
Text GLabel 7220 2980 2    40   Output ~ 0
~Seconds6_LED
Text GLabel 7220 5380 2    50   Output ~ 0
USB_UART_TX
Text GLabel 7220 5280 2    50   Input ~ 0
USB_UART_RX
Text GLabel 7220 5780 2    50   Output ~ 0
Date_B0
Text GLabel 8030 6000 2    50   Output ~ 0
Date_B1
Text GLabel 8210 5830 2    50   Output ~ 0
Date_B2
Text GLabel 7220 3680 2    50   Output ~ 0
Year_B0
Text GLabel 7220 3780 2    50   Output ~ 0
Year_B1
Text GLabel 7220 3880 2    50   Output ~ 0
Year_B2
Text GLabel 8340 2920 2    50   Output ~ 0
Other_Error_LED
Text GLabel 7220 4580 2    50   Output ~ 0
Exception_LED
Text GLabel 8600 3200 2    50   Output ~ 0
Analog_Error_LED
Text GLabel 3220 2380 0    50   Output ~ 0
Date_Decode_Enable
Text GLabel 3220 2830 0    50   BiDi ~ 0
ICSPDAT
Text GLabel 3220 2930 0    50   Input ~ 0
ICSPCLK
Text GLabel 8040 6150 2    40   Output ~ 0
~Date_Decode_1
Text GLabel 8310 6570 2    40   Output ~ 0
~Date_Decode_2
Text GLabel 1910 2030 0    40   Output ~ 0
~Date_Decode_3
Text GLabel 1910 2130 0    40   Output ~ 0
~Date_Decode_4
Text Notes 540  690  0    100  ~ 20
07. Microcontroller
Text GLabel 7220 5680 2    50   Input ~ 0
POS12_PGOOD
Text GLabel 3220 2280 0    50   Input ~ 0
VBAT_ADC
Text GLabel 7220 4980 2    40   Input ~ 0
~DIODE_FAULT
Text GLabel 7220 4880 2    50   Output ~ 0
VBAT_ADC_EN
Text GLabel 8890 3530 2    50   Output ~ 0
STATUS_LED_ENABLE
Text GLabel 7220 4680 2    40   Output ~ 0
~VBAT_ISOLATE
Text GLabel 7220 1880 2    40   Output ~ 0
~OCT_LED
Text GLabel 7220 2280 2    40   Output ~ 0
~SEP_LED
Text GLabel 7220 2180 2    40   Output ~ 0
~AUG_LED
Text GLabel 7220 2080 2    40   Output ~ 0
~JUL_LED
Text GLabel 7220 2480 2    40   Output ~ 0
~JUN_LED
Text GLabel 7220 2380 2    40   Output ~ 0
~MAY_LED
Text GLabel 7220 1780 2    40   Output ~ 0
~APR_LED
Text GLabel 7220 1680 2    40   Output ~ 0
~MAR_LED
Text GLabel 7220 1580 2    40   Output ~ 0
~FEB_LED
Text GLabel 7220 1480 2    40   Output ~ 0
~JAN_LED
Text GLabel 7220 1980 2    40   Output ~ 0
~NOV_LED
Text GLabel 7220 4180 2    40   Output ~ 0
~DEC_LED
Text GLabel 3220 1880 0    40   Output ~ 0
~SAT_LED
Text GLabel 3220 4580 0    40   Output ~ 0
~Hours0_LED
Text GLabel 3220 4680 0    40   Output ~ 0
~Hours2_LED
Text GLabel 3220 4780 0    40   Output ~ 0
~Hours4_LED
Text GLabel 3220 4880 0    40   Output ~ 0
~Hours6_LED
$EndSCHEMATC
