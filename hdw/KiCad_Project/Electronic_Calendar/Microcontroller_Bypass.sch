EESchema Schematic File Version 4
LIBS:Electronic_Calendar-cache
EELAYER 29 0
EELAYER END
$Descr A 11000 8500
encoding utf-8
Sheet 8 17
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
L power:GND #PWR0802
U 1 1 5CB29D2D
P 2790 3000
F 0 "#PWR0802" H 2790 2750 50  0001 C CNN
F 1 "GND" H 2790 2850 50  0000 C CNN
F 2 "" H 2790 3000 50  0000 C CNN
F 3 "" H 2790 3000 50  0000 C CNN
	1    2790 3000
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:C_Custom C801
U 1 1 5CB29D37
P 2470 2770
F 0 "C801" H 2495 2870 50  0000 L CNN
F 1 "0.1uF" H 2495 2670 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 2508 2620 50  0001 C CNN
F 3 "" H 2495 2870 50  0001 C CNN
F 4 "0603" H 2320 2870 50  0000 R CNN "display_footprint"
F 5 "50V" H 2320 2770 50  0000 R CNN "Voltage"
F 6 "X7R" H 2320 2670 50  0000 R CNN "Dielectric"
F 7 "399-6856-1-ND" H -1440 -4110 50  0001 C CNN "Digi-Key PN"
	1    2470 2770
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:C_Custom C805
U 1 1 5CB29D41
P 3110 2770
F 0 "C805" H 3135 2870 50  0000 L CNN
F 1 "1nF" H 3135 2670 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 3148 2620 50  0001 C CNN
F 3 "" H 3135 2870 50  0001 C CNN
F 4 "0603" H 2960 2870 50  0001 R CNN "display_footprint"
F 5 "50V" H 2960 2770 50  0001 R CNN "Voltage"
F 6 "X7R" H 2960 2670 50  0001 R CNN "Dielectric"
F 7 "399-1083-1-ND" H -1440 -4110 50  0001 C CNN "Digi-Key PN"
	1    3110 2770
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:C_Custom C803
U 1 1 5CB29D4B
P 2790 2770
F 0 "C803" H 2815 2870 50  0000 L CNN
F 1 "10nF" H 2815 2670 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 2828 2620 50  0001 C CNN
F 3 "" H 2815 2870 50  0001 C CNN
F 4 "0603" H 2640 2870 50  0001 R CNN "display_footprint"
F 5 "50V" H 2640 2770 50  0001 R CNN "Voltage"
F 6 "X7R" H 2640 2670 50  0001 R CNN "Dielectric"
F 7 "399-1092-1-ND" H -1440 -4110 50  0001 C CNN "Digi-Key PN"
	1    2790 2770
	1    0    0    -1  
$EndComp
Wire Wire Line
	2470 2580 2470 2620
Connection ~ 2790 2580
Wire Wire Line
	3110 2580 3110 2620
Wire Wire Line
	2470 2580 2790 2580
Wire Wire Line
	2790 2540 2790 2580
Wire Wire Line
	2470 2960 2470 2920
Connection ~ 2790 2960
Wire Wire Line
	3110 2960 3110 2920
Wire Wire Line
	2470 2960 2790 2960
Wire Wire Line
	2790 2920 2790 2960
Wire Wire Line
	2790 2580 3110 2580
Wire Wire Line
	2790 2580 2790 2620
Wire Wire Line
	2790 2960 3110 2960
Wire Wire Line
	2790 2960 2790 3000
$Comp
L power:GND #PWR0806
U 1 1 5CB1558B
P 4090 3000
F 0 "#PWR0806" H 4090 2750 50  0001 C CNN
F 1 "GND" H 4090 2850 50  0000 C CNN
F 2 "" H 4090 3000 50  0000 C CNN
F 3 "" H 4090 3000 50  0000 C CNN
	1    4090 3000
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:C_Custom C807
U 1 1 5CB15599
P 3770 2770
F 0 "C807" H 3795 2870 50  0000 L CNN
F 1 "0.1uF" H 3795 2670 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 3808 2620 50  0001 C CNN
F 3 "" H 3795 2870 50  0001 C CNN
F 4 "0603" H 3620 2870 50  0000 R CNN "display_footprint"
F 5 "50V" H 3620 2770 50  0000 R CNN "Voltage"
F 6 "X7R" H 3620 2670 50  0000 R CNN "Dielectric"
F 7 "399-6856-1-ND" H -140 -4110 50  0001 C CNN "Digi-Key PN"
	1    3770 2770
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:C_Custom C811
U 1 1 5CB155A7
P 4410 2770
F 0 "C811" H 4435 2870 50  0000 L CNN
F 1 "1nF" H 4435 2670 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 4448 2620 50  0001 C CNN
F 3 "" H 4435 2870 50  0001 C CNN
F 4 "0603" H 4260 2870 50  0001 R CNN "display_footprint"
F 5 "50V" H 4260 2770 50  0001 R CNN "Voltage"
F 6 "X7R" H 4260 2670 50  0001 R CNN "Dielectric"
F 7 "399-1083-1-ND" H -140 -4110 50  0001 C CNN "Digi-Key PN"
	1    4410 2770
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:C_Custom C809
U 1 1 5CB155B5
P 4090 2770
F 0 "C809" H 4115 2870 50  0000 L CNN
F 1 "10nF" H 4115 2670 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 4128 2620 50  0001 C CNN
F 3 "" H 4115 2870 50  0001 C CNN
F 4 "0603" H 3940 2870 50  0001 R CNN "display_footprint"
F 5 "50V" H 3940 2770 50  0001 R CNN "Voltage"
F 6 "X7R" H 3940 2670 50  0001 R CNN "Dielectric"
F 7 "399-1092-1-ND" H -140 -4110 50  0001 C CNN "Digi-Key PN"
	1    4090 2770
	1    0    0    -1  
$EndComp
Wire Wire Line
	3770 2580 3770 2620
Connection ~ 4090 2580
Wire Wire Line
	4410 2580 4410 2620
Wire Wire Line
	3770 2580 4090 2580
Wire Wire Line
	4090 2540 4090 2580
Wire Wire Line
	3770 2960 3770 2920
Connection ~ 4090 2960
Wire Wire Line
	4410 2960 4410 2920
Wire Wire Line
	3770 2960 4090 2960
Wire Wire Line
	4090 2920 4090 2960
Wire Wire Line
	4090 2580 4410 2580
Wire Wire Line
	4090 2580 4090 2620
Wire Wire Line
	4090 2960 4410 2960
Wire Wire Line
	4090 2960 4090 3000
$Comp
L power:GND #PWR0810
U 1 1 5CB1993B
P 5390 3000
F 0 "#PWR0810" H 5390 2750 50  0001 C CNN
F 1 "GND" H 5390 2850 50  0000 C CNN
F 2 "" H 5390 3000 50  0000 C CNN
F 3 "" H 5390 3000 50  0000 C CNN
	1    5390 3000
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:C_Custom C813
U 1 1 5CB19945
P 5070 2770
F 0 "C813" H 5095 2870 50  0000 L CNN
F 1 "0.1uF" H 5095 2670 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 5108 2620 50  0001 C CNN
F 3 "" H 5095 2870 50  0001 C CNN
F 4 "0603" H 4920 2870 50  0000 R CNN "display_footprint"
F 5 "50V" H 4920 2770 50  0000 R CNN "Voltage"
F 6 "X7R" H 4920 2670 50  0000 R CNN "Dielectric"
F 7 "399-6856-1-ND" H 1160 -4110 50  0001 C CNN "Digi-Key PN"
	1    5070 2770
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:C_Custom C817
U 1 1 5CB1994F
P 5710 2770
F 0 "C817" H 5735 2870 50  0000 L CNN
F 1 "1nF" H 5735 2670 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 5748 2620 50  0001 C CNN
F 3 "" H 5735 2870 50  0001 C CNN
F 4 "0603" H 5560 2870 50  0001 R CNN "display_footprint"
F 5 "50V" H 5560 2770 50  0001 R CNN "Voltage"
F 6 "X7R" H 5560 2670 50  0001 R CNN "Dielectric"
F 7 "399-1083-1-ND" H 1160 -4110 50  0001 C CNN "Digi-Key PN"
	1    5710 2770
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:C_Custom C815
U 1 1 5CB19959
P 5390 2770
F 0 "C815" H 5415 2870 50  0000 L CNN
F 1 "10nF" H 5415 2670 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 5428 2620 50  0001 C CNN
F 3 "" H 5415 2870 50  0001 C CNN
F 4 "0603" H 5240 2870 50  0001 R CNN "display_footprint"
F 5 "50V" H 5240 2770 50  0001 R CNN "Voltage"
F 6 "X7R" H 5240 2670 50  0001 R CNN "Dielectric"
F 7 "399-1092-1-ND" H 1160 -4110 50  0001 C CNN "Digi-Key PN"
	1    5390 2770
	1    0    0    -1  
$EndComp
Wire Wire Line
	5070 2580 5070 2620
Connection ~ 5390 2580
Wire Wire Line
	5710 2580 5710 2620
Wire Wire Line
	5070 2580 5390 2580
Wire Wire Line
	5390 2540 5390 2580
Wire Wire Line
	5070 2960 5070 2920
Connection ~ 5390 2960
Wire Wire Line
	5710 2960 5710 2920
Wire Wire Line
	5070 2960 5390 2960
Wire Wire Line
	5390 2920 5390 2960
Wire Wire Line
	5390 2580 5710 2580
Wire Wire Line
	5390 2580 5390 2620
Wire Wire Line
	5390 2960 5710 2960
Wire Wire Line
	5390 2960 5390 3000
$Comp
L power:GND #PWR0814
U 1 1 5CB219B2
P 6690 3000
F 0 "#PWR0814" H 6690 2750 50  0001 C CNN
F 1 "GND" H 6690 2850 50  0000 C CNN
F 2 "" H 6690 3000 50  0000 C CNN
F 3 "" H 6690 3000 50  0000 C CNN
	1    6690 3000
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:C_Custom C819
U 1 1 5CB219C0
P 6370 2770
F 0 "C819" H 6395 2870 50  0000 L CNN
F 1 "0.1uF" H 6395 2670 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 6408 2620 50  0001 C CNN
F 3 "" H 6395 2870 50  0001 C CNN
F 4 "0603" H 6220 2870 50  0000 R CNN "display_footprint"
F 5 "50V" H 6220 2770 50  0000 R CNN "Voltage"
F 6 "X7R" H 6220 2670 50  0000 R CNN "Dielectric"
F 7 "399-6856-1-ND" H 2460 -4110 50  0001 C CNN "Digi-Key PN"
	1    6370 2770
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:C_Custom C823
U 1 1 5CB219CE
P 7010 2770
F 0 "C823" H 7035 2870 50  0000 L CNN
F 1 "1nF" H 7035 2670 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 7048 2620 50  0001 C CNN
F 3 "" H 7035 2870 50  0001 C CNN
F 4 "0603" H 6860 2870 50  0001 R CNN "display_footprint"
F 5 "50V" H 6860 2770 50  0001 R CNN "Voltage"
F 6 "X7R" H 6860 2670 50  0001 R CNN "Dielectric"
F 7 "399-1083-1-ND" H 2460 -4110 50  0001 C CNN "Digi-Key PN"
	1    7010 2770
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:C_Custom C821
U 1 1 5CB219DC
P 6690 2770
F 0 "C821" H 6715 2870 50  0000 L CNN
F 1 "10nF" H 6715 2670 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 6728 2620 50  0001 C CNN
F 3 "" H 6715 2870 50  0001 C CNN
F 4 "0603" H 6540 2870 50  0001 R CNN "display_footprint"
F 5 "50V" H 6540 2770 50  0001 R CNN "Voltage"
F 6 "X7R" H 6540 2670 50  0001 R CNN "Dielectric"
F 7 "399-1092-1-ND" H 2460 -4110 50  0001 C CNN "Digi-Key PN"
	1    6690 2770
	1    0    0    -1  
$EndComp
Wire Wire Line
	6370 2580 6370 2620
Connection ~ 6690 2580
Wire Wire Line
	7010 2580 7010 2620
Wire Wire Line
	6370 2580 6690 2580
Wire Wire Line
	6690 2540 6690 2580
Wire Wire Line
	6370 2960 6370 2920
Connection ~ 6690 2960
Wire Wire Line
	7010 2960 7010 2920
Wire Wire Line
	6370 2960 6690 2960
Wire Wire Line
	6690 2920 6690 2960
Wire Wire Line
	6690 2580 7010 2580
Wire Wire Line
	6690 2580 6690 2620
Wire Wire Line
	6690 2960 7010 2960
Wire Wire Line
	6690 2960 6690 3000
$Comp
L power:GND #PWR0804
U 1 1 5CB24EB8
P 2790 4000
F 0 "#PWR0804" H 2790 3750 50  0001 C CNN
F 1 "GND" H 2790 3850 50  0000 C CNN
F 2 "" H 2790 4000 50  0000 C CNN
F 3 "" H 2790 4000 50  0000 C CNN
	1    2790 4000
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:C_Custom C802
U 1 1 5CB24EC6
P 2470 3770
F 0 "C802" H 2495 3870 50  0000 L CNN
F 1 "0.1uF" H 2495 3670 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 2508 3620 50  0001 C CNN
F 3 "" H 2495 3870 50  0001 C CNN
F 4 "0603" H 2320 3870 50  0000 R CNN "display_footprint"
F 5 "50V" H 2320 3770 50  0000 R CNN "Voltage"
F 6 "X7R" H 2320 3670 50  0000 R CNN "Dielectric"
F 7 "399-6856-1-ND" H -1440 -3110 50  0001 C CNN "Digi-Key PN"
	1    2470 3770
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:C_Custom C806
U 1 1 5CB24ED4
P 3110 3770
F 0 "C806" H 3135 3870 50  0000 L CNN
F 1 "1nF" H 3135 3670 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 3148 3620 50  0001 C CNN
F 3 "" H 3135 3870 50  0001 C CNN
F 4 "0603" H 2960 3870 50  0001 R CNN "display_footprint"
F 5 "50V" H 2960 3770 50  0001 R CNN "Voltage"
F 6 "X7R" H 2960 3670 50  0001 R CNN "Dielectric"
F 7 "399-1083-1-ND" H -1440 -3110 50  0001 C CNN "Digi-Key PN"
	1    3110 3770
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:C_Custom C804
U 1 1 5CB24EE2
P 2790 3770
F 0 "C804" H 2815 3870 50  0000 L CNN
F 1 "10nF" H 2815 3670 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 2828 3620 50  0001 C CNN
F 3 "" H 2815 3870 50  0001 C CNN
F 4 "0603" H 2640 3870 50  0001 R CNN "display_footprint"
F 5 "50V" H 2640 3770 50  0001 R CNN "Voltage"
F 6 "X7R" H 2640 3670 50  0001 R CNN "Dielectric"
F 7 "399-1092-1-ND" H -1440 -3110 50  0001 C CNN "Digi-Key PN"
	1    2790 3770
	1    0    0    -1  
$EndComp
Wire Wire Line
	2470 3580 2470 3620
Connection ~ 2790 3580
Wire Wire Line
	3110 3580 3110 3620
Wire Wire Line
	2470 3580 2790 3580
Wire Wire Line
	2790 3540 2790 3580
Wire Wire Line
	2470 3960 2470 3920
Connection ~ 2790 3960
Wire Wire Line
	3110 3960 3110 3920
Wire Wire Line
	2470 3960 2790 3960
Wire Wire Line
	2790 3920 2790 3960
Wire Wire Line
	2790 3580 3110 3580
Wire Wire Line
	2790 3580 2790 3620
Wire Wire Line
	2790 3960 3110 3960
Wire Wire Line
	2790 3960 2790 4000
$Comp
L power:GND #PWR0808
U 1 1 5CB24F04
P 4090 4000
F 0 "#PWR0808" H 4090 3750 50  0001 C CNN
F 1 "GND" H 4090 3850 50  0000 C CNN
F 2 "" H 4090 4000 50  0000 C CNN
F 3 "" H 4090 4000 50  0000 C CNN
	1    4090 4000
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:C_Custom C808
U 1 1 5CB24F12
P 3770 3770
F 0 "C808" H 3795 3870 50  0000 L CNN
F 1 "0.1uF" H 3795 3670 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 3808 3620 50  0001 C CNN
F 3 "" H 3795 3870 50  0001 C CNN
F 4 "0603" H 3620 3870 50  0000 R CNN "display_footprint"
F 5 "50V" H 3620 3770 50  0000 R CNN "Voltage"
F 6 "X7R" H 3620 3670 50  0000 R CNN "Dielectric"
F 7 "399-6856-1-ND" H -140 -3110 50  0001 C CNN "Digi-Key PN"
	1    3770 3770
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:C_Custom C812
U 1 1 5CB24F20
P 4410 3770
F 0 "C812" H 4435 3870 50  0000 L CNN
F 1 "1nF" H 4435 3670 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 4448 3620 50  0001 C CNN
F 3 "" H 4435 3870 50  0001 C CNN
F 4 "0603" H 4260 3870 50  0001 R CNN "display_footprint"
F 5 "50V" H 4260 3770 50  0001 R CNN "Voltage"
F 6 "X7R" H 4260 3670 50  0001 R CNN "Dielectric"
F 7 "399-1083-1-ND" H -140 -3110 50  0001 C CNN "Digi-Key PN"
	1    4410 3770
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:C_Custom C810
U 1 1 5CB24F2E
P 4090 3770
F 0 "C810" H 4115 3870 50  0000 L CNN
F 1 "10nF" H 4115 3670 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 4128 3620 50  0001 C CNN
F 3 "" H 4115 3870 50  0001 C CNN
F 4 "0603" H 3940 3870 50  0001 R CNN "display_footprint"
F 5 "50V" H 3940 3770 50  0001 R CNN "Voltage"
F 6 "X7R" H 3940 3670 50  0001 R CNN "Dielectric"
F 7 "399-1092-1-ND" H -140 -3110 50  0001 C CNN "Digi-Key PN"
	1    4090 3770
	1    0    0    -1  
$EndComp
Wire Wire Line
	3770 3580 3770 3620
Connection ~ 4090 3580
Wire Wire Line
	4410 3580 4410 3620
Wire Wire Line
	3770 3580 4090 3580
Wire Wire Line
	4090 3540 4090 3580
Wire Wire Line
	3770 3960 3770 3920
Connection ~ 4090 3960
Wire Wire Line
	4410 3960 4410 3920
Wire Wire Line
	3770 3960 4090 3960
Wire Wire Line
	4090 3920 4090 3960
Wire Wire Line
	4090 3580 4410 3580
Wire Wire Line
	4090 3580 4090 3620
Wire Wire Line
	4090 3960 4410 3960
Wire Wire Line
	4090 3960 4090 4000
$Comp
L power:GND #PWR0812
U 1 1 5CB24F50
P 5390 4000
F 0 "#PWR0812" H 5390 3750 50  0001 C CNN
F 1 "GND" H 5390 3850 50  0000 C CNN
F 2 "" H 5390 4000 50  0000 C CNN
F 3 "" H 5390 4000 50  0000 C CNN
	1    5390 4000
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:C_Custom C814
U 1 1 5CB24F5E
P 5070 3770
F 0 "C814" H 5095 3870 50  0000 L CNN
F 1 "0.1uF" H 5095 3670 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 5108 3620 50  0001 C CNN
F 3 "" H 5095 3870 50  0001 C CNN
F 4 "0603" H 4920 3870 50  0000 R CNN "display_footprint"
F 5 "50V" H 4920 3770 50  0000 R CNN "Voltage"
F 6 "X7R" H 4920 3670 50  0000 R CNN "Dielectric"
F 7 "399-6856-1-ND" H 1160 -3110 50  0001 C CNN "Digi-Key PN"
	1    5070 3770
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:C_Custom C818
U 1 1 5CB24F6C
P 5710 3770
F 0 "C818" H 5735 3870 50  0000 L CNN
F 1 "1nF" H 5735 3670 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 5748 3620 50  0001 C CNN
F 3 "" H 5735 3870 50  0001 C CNN
F 4 "0603" H 5560 3870 50  0001 R CNN "display_footprint"
F 5 "50V" H 5560 3770 50  0001 R CNN "Voltage"
F 6 "X7R" H 5560 3670 50  0001 R CNN "Dielectric"
F 7 "399-1083-1-ND" H 1160 -3110 50  0001 C CNN "Digi-Key PN"
	1    5710 3770
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:C_Custom C816
U 1 1 5CB24F7A
P 5390 3770
F 0 "C816" H 5415 3870 50  0000 L CNN
F 1 "10nF" H 5415 3670 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 5428 3620 50  0001 C CNN
F 3 "" H 5415 3870 50  0001 C CNN
F 4 "0603" H 5240 3870 50  0001 R CNN "display_footprint"
F 5 "50V" H 5240 3770 50  0001 R CNN "Voltage"
F 6 "X7R" H 5240 3670 50  0001 R CNN "Dielectric"
F 7 "399-1092-1-ND" H 1160 -3110 50  0001 C CNN "Digi-Key PN"
	1    5390 3770
	1    0    0    -1  
$EndComp
Wire Wire Line
	5070 3580 5070 3620
Connection ~ 5390 3580
Wire Wire Line
	5710 3580 5710 3620
Wire Wire Line
	5070 3580 5390 3580
Wire Wire Line
	5390 3540 5390 3580
Wire Wire Line
	5070 3960 5070 3920
Connection ~ 5390 3960
Wire Wire Line
	5710 3960 5710 3920
Wire Wire Line
	5070 3960 5390 3960
Wire Wire Line
	5390 3920 5390 3960
Wire Wire Line
	5390 3580 5710 3580
Wire Wire Line
	5390 3580 5390 3620
Wire Wire Line
	5390 3960 5710 3960
Wire Wire Line
	5390 3960 5390 4000
$Comp
L power:GNDA #PWR0816
U 1 1 5CB34347
P 6690 4000
F 0 "#PWR0816" H 6690 3750 50  0001 C CNN
F 1 "GNDA" H 6690 3850 50  0000 C CNN
F 2 "" H 6690 4000 50  0001 C CNN
F 3 "" H 6690 4000 50  0001 C CNN
	1    6690 4000
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3VA #PWR0815
U 1 1 5CB34889
P 6690 3540
F 0 "#PWR0815" H 6690 3390 50  0001 C CNN
F 1 "+3.3VA" H 6690 3680 50  0000 C CNN
F 2 "" H 6690 3540 50  0001 C CNN
F 3 "" H 6690 3540 50  0001 C CNN
	1    6690 3540
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:+3.3V_BCKP #PWR0801
U 1 1 5CB3AA96
P 2790 2540
F 0 "#PWR0801" H 2790 2390 50  0001 C CNN
F 1 "+3.3V_BCKP" H 2790 2680 50  0000 C CNN
F 2 "" H 2790 2540 50  0000 C CNN
F 3 "" H 2790 2540 50  0000 C CNN
	1    2790 2540
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:+3.3V_BCKP #PWR0805
U 1 1 5CB3B335
P 4090 2540
F 0 "#PWR0805" H 4090 2390 50  0001 C CNN
F 1 "+3.3V_BCKP" H 4090 2680 50  0000 C CNN
F 2 "" H 4090 2540 50  0000 C CNN
F 3 "" H 4090 2540 50  0000 C CNN
	1    4090 2540
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:+3.3V_BCKP #PWR0809
U 1 1 5CB3B75C
P 5390 2540
F 0 "#PWR0809" H 5390 2390 50  0001 C CNN
F 1 "+3.3V_BCKP" H 5390 2680 50  0000 C CNN
F 2 "" H 5390 2540 50  0000 C CNN
F 3 "" H 5390 2540 50  0000 C CNN
	1    5390 2540
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:+3.3V_BCKP #PWR0813
U 1 1 5CB3BE52
P 6690 2540
F 0 "#PWR0813" H 6690 2390 50  0001 C CNN
F 1 "+3.3V_BCKP" H 6690 2680 50  0000 C CNN
F 2 "" H 6690 2540 50  0000 C CNN
F 3 "" H 6690 2540 50  0000 C CNN
	1    6690 2540
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:+3.3V_BCKP #PWR0803
U 1 1 5CB3C9C1
P 2790 3540
F 0 "#PWR0803" H 2790 3390 50  0001 C CNN
F 1 "+3.3V_BCKP" H 2790 3680 50  0000 C CNN
F 2 "" H 2790 3540 50  0000 C CNN
F 3 "" H 2790 3540 50  0000 C CNN
	1    2790 3540
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:+3.3V_BCKP #PWR0807
U 1 1 5CB3C9CB
P 4090 3540
F 0 "#PWR0807" H 4090 3390 50  0001 C CNN
F 1 "+3.3V_BCKP" H 4090 3680 50  0000 C CNN
F 2 "" H 4090 3540 50  0000 C CNN
F 3 "" H 4090 3540 50  0000 C CNN
	1    4090 3540
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:+3.3V_BCKP #PWR0811
U 1 1 5CB3C9D5
P 5390 3540
F 0 "#PWR0811" H 5390 3390 50  0001 C CNN
F 1 "+3.3V_BCKP" H 5390 3680 50  0000 C CNN
F 2 "" H 5390 3540 50  0000 C CNN
F 3 "" H 5390 3540 50  0000 C CNN
	1    5390 3540
	1    0    0    -1  
$EndComp
Wire Wire Line
	6690 3960 6690 4000
Wire Wire Line
	6690 3580 6690 3620
Wire Wire Line
	6690 3920 6690 3960
Wire Wire Line
	7010 3960 7010 3920
Wire Wire Line
	6690 3960 7010 3960
Wire Wire Line
	6370 3960 6690 3960
Connection ~ 6690 3960
Wire Wire Line
	6370 3960 6370 3920
Wire Wire Line
	6690 3540 6690 3580
Wire Wire Line
	7010 3580 7010 3620
Wire Wire Line
	6690 3580 7010 3580
Wire Wire Line
	6370 3580 6690 3580
Connection ~ 6690 3580
Wire Wire Line
	6370 3580 6370 3620
$Comp
L Custom_Library:C_Custom C822
U 1 1 5CB24FC6
P 6690 3770
F 0 "C822" H 6715 3870 50  0000 L CNN
F 1 "10nF" H 6715 3670 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 6728 3620 50  0001 C CNN
F 3 "" H 6715 3870 50  0001 C CNN
F 4 "0603" H 6540 3870 50  0001 R CNN "display_footprint"
F 5 "50V" H 6540 3770 50  0001 R CNN "Voltage"
F 6 "X7R" H 6540 3670 50  0001 R CNN "Dielectric"
F 7 "399-1092-1-ND" H 2460 -3110 50  0001 C CNN "Digi-Key PN"
	1    6690 3770
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:C_Custom C824
U 1 1 5CB24FB8
P 7010 3770
F 0 "C824" H 7035 3870 50  0000 L CNN
F 1 "1nF" H 7035 3670 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 7048 3620 50  0001 C CNN
F 3 "" H 7035 3870 50  0001 C CNN
F 4 "0603" H 6860 3870 50  0001 R CNN "display_footprint"
F 5 "50V" H 6860 3770 50  0001 R CNN "Voltage"
F 6 "X7R" H 6860 3670 50  0001 R CNN "Dielectric"
F 7 "399-1083-1-ND" H 2460 -3110 50  0001 C CNN "Digi-Key PN"
	1    7010 3770
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:C_Custom C820
U 1 1 5CB24FAA
P 6370 3770
F 0 "C820" H 6395 3870 50  0000 L CNN
F 1 "0.1uF" H 6395 3670 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 6408 3620 50  0001 C CNN
F 3 "" H 6395 3870 50  0001 C CNN
F 4 "0603" H 6220 3870 50  0000 R CNN "display_footprint"
F 5 "50V" H 6220 3770 50  0000 R CNN "Voltage"
F 6 "X7R" H 6220 3670 50  0000 R CNN "Dielectric"
F 7 "399-6856-1-ND" H 2460 -3110 50  0001 C CNN "Digi-Key PN"
	1    6370 3770
	1    0    0    -1  
$EndComp
$Comp
L Device:Ferrite_Bead L?
U 1 1 5CB5F840
P 8130 3490
AR Path="/5CAD2D97/5CB5F840" Ref="L?"  Part="1" 
AR Path="/5CB25152/5CB5F840" Ref="L?"  Part="1" 
AR Path="/5CD36036/5CB5F840" Ref="L801"  Part="1" 
F 0 "L801" V 7980 3515 50  0000 C CNN
F 1 "600R 0.5A" V 8280 3490 50  0000 C CNN
F 2 "Inductors_SMD:L_0603" V 8060 3490 50  0001 C CNN
F 3 "~" H 8130 3490 50  0001 C CNN
F 4 "732-2389-1-ND" H -1400 -270 50  0001 C CNN "Digi-Key PN"
	1    8130 3490
	0    1    1    0   
$EndComp
$Comp
L Device:Ferrite_Bead L?
U 1 1 5CB61DC3
P 8130 4050
AR Path="/5CAD2D97/5CB61DC3" Ref="L?"  Part="1" 
AR Path="/5CB25152/5CB61DC3" Ref="L?"  Part="1" 
AR Path="/5CD36036/5CB61DC3" Ref="L802"  Part="1" 
F 0 "L802" V 7980 4075 50  0000 C CNN
F 1 "600R 0.5A" V 8280 4050 50  0000 C CNN
F 2 "Inductors_SMD:L_0603" V 8060 4050 50  0001 C CNN
F 3 "~" H 8130 4050 50  0001 C CNN
F 4 "732-2389-1-ND" H -1400 290 50  0001 C CNN "Digi-Key PN"
	1    8130 4050
	0    1    1    0   
$EndComp
$Comp
L power:+3.3VA #PWR0819
U 1 1 5CB622F1
P 8280 3490
F 0 "#PWR0819" H 8280 3340 50  0001 C CNN
F 1 "+3.3VA" V 8280 3630 50  0000 L CNN
F 2 "" H 8280 3490 50  0001 C CNN
F 3 "" H 8280 3490 50  0001 C CNN
	1    8280 3490
	0    1    1    0   
$EndComp
$Comp
L power:GNDA #PWR0820
U 1 1 5CB6287E
P 8280 4050
F 0 "#PWR0820" H 8280 3800 50  0001 C CNN
F 1 "GNDA" V 8280 3900 50  0000 R CNN
F 2 "" H 8280 4050 50  0001 C CNN
F 3 "" H 8280 4050 50  0001 C CNN
	1    8280 4050
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0818
U 1 1 5CB62D81
P 7980 4050
F 0 "#PWR0818" H 7980 3800 50  0001 C CNN
F 1 "GND" V 7980 3900 50  0000 R CNN
F 2 "" H 7980 4050 50  0001 C CNN
F 3 "" H 7980 4050 50  0001 C CNN
	1    7980 4050
	0    1    1    0   
$EndComp
$Comp
L Custom_Library:+3.3V_BCKP #PWR0817
U 1 1 5CB633AE
P 7980 3490
F 0 "#PWR0817" H 7980 3340 50  0001 C CNN
F 1 "+3.3V_BCKP" V 7980 3630 50  0000 L CNN
F 2 "" H 7980 3490 50  0000 C CNN
F 3 "" H 7980 3490 50  0000 C CNN
	1    7980 3490
	0    -1   -1   0   
$EndComp
$EndSCHEMATC
