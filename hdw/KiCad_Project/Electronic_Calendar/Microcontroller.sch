EESchema Schematic File Version 4
LIBS:Electronic_Calendar-cache
EELAYER 29 0
EELAYER END
$Descr A 11000 8500
encoding utf-8
Sheet 5 15
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
$EndSCHEMATC
