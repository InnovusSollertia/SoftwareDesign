
�
I%sTime (s): cpu = %s ; elapsed = %s . Memory (MB): peak = %s ; gain = %s
268*common2
create_project: 2

00:00:072

00:00:072	
631.0472	
200.332Z17-268h px� 
�
Command: %s
1870*	planAhead2�
�read_checkpoint -auto_incremental -incremental D:/Projects/SoftwareDesign/fpga/ADCtoDACRLPsystem/ADCtoDACRLPsystem.srcs/utils_1/imports/synth_1/main.dcpZ12-2866h px� 
�
;Read reference checkpoint from %s for incremental synthesis3154*	planAhead2k
iD:/Projects/SoftwareDesign/fpga/ADCtoDACRLPsystem/ADCtoDACRLPsystem.srcs/utils_1/imports/synth_1/main.dcpZ12-5825h px� 
T
-Please ensure there are no constraint changes3725*	planAheadZ12-7989h px� 
t
Command: %s
53*	vivadotcl2C
Asynth_design -top radar_processing_tb -part xczu21dr-ffvd1156-2-eZ4-113h px� 
:
Starting synth_design
149*	vivadotclZ4-321h px� 
{
@Attempting to get a license for feature '%s' and/or device '%s'
308*common2
	Synthesis2

xczu21drZ17-347h px� 
k
0Got license for feature '%s' and/or device '%s'
310*common2
	Synthesis2

xczu21drZ17-349h px� 
o
HMultithreading enabled for synth_design using a maximum of %s processes.4828*oasys2
2Z8-7079h px� 
a
?Launching helper process for spawning children vivado processes4827*oasysZ8-7078h px� 
N
#Helper process launched with PID %s4824*oasys2
17156Z8-7075h px� 
�
%s*synth2v
tStarting Synthesize : Time (s): cpu = 00:00:06 ; elapsed = 00:00:06 . Memory (MB): peak = 1030.344 ; gain = 388.332
h px� 
�
synthesizing module '%s'%s4497*oasys2
radar_processing_tb2
 2a
]D:/Projects/SoftwareDesign/fpga/ADCtoDACRLPsystem/ADCtoDACRLPsystem.srcs/sources_1/new/main.v2
18@Z8-6157h px� 
�
!system %s call '%s' not supported38048*oasys2
task2

dumpfile2a
]D:/Projects/SoftwareDesign/fpga/ADCtoDACRLPsystem/ADCtoDACRLPsystem.srcs/sources_1/new/main.v2
238@Z8-11581h px� 
�
!system %s call '%s' not supported38048*oasys2
task2

dumpvars2a
]D:/Projects/SoftwareDesign/fpga/ADCtoDACRLPsystem/ADCtoDACRLPsystem.srcs/sources_1/new/main.v2
248@Z8-11581h px� 
�
display: %s251*oasys2 
ADC Input: X=512, Y=256, Z=1282a
]D:/Projects/SoftwareDesign/fpga/ADCtoDACRLPsystem/ADCtoDACRLPsystem.srcs/sources_1/new/main.v2
368@Z8-251h px� 
�
display: %s251*oasys2 
ADC Input: X=600, Y=300, Z=1502a
]D:/Projects/SoftwareDesign/fpga/ADCtoDACRLPsystem/ADCtoDACRLPsystem.srcs/sources_1/new/main.v2
398@Z8-251h px� 
�
display: %s251*oasys2 
ADC Input: X=700, Y=400, Z=2002a
]D:/Projects/SoftwareDesign/fpga/ADCtoDACRLPsystem/ADCtoDACRLPsystem.srcs/sources_1/new/main.v2
428@Z8-251h px� 
�
display: %s251*oasys2 
ADC Input: X=800, Y=500, Z=2502a
]D:/Projects/SoftwareDesign/fpga/ADCtoDACRLPsystem/ADCtoDACRLPsystem.srcs/sources_1/new/main.v2
458@Z8-251h px� 
�
display: %s251*oasys2 
ADC Input: X=900, Y=600, Z=3002a
]D:/Projects/SoftwareDesign/fpga/ADCtoDACRLPsystem/ADCtoDACRLPsystem.srcs/sources_1/new/main.v2
488@Z8-251h px� 
�
display: %s251*oasys2
Checksum: x2a
]D:/Projects/SoftwareDesign/fpga/ADCtoDACRLPsystem/ADCtoDACRLPsystem.srcs/sources_1/new/main.v2
518@Z8-251h px� 
�
display: %s251*oasys2]
[Encrypted Data (AES-2048): xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx2a
]D:/Projects/SoftwareDesign/fpga/ADCtoDACRLPsystem/ADCtoDACRLPsystem.srcs/sources_1/new/main.v2
528@Z8-251h px� 
�
display: %s251*oasys2$
"Final Data Sent to PCI-E Buffer: x2a
]D:/Projects/SoftwareDesign/fpga/ADCtoDACRLPsystem/ADCtoDACRLPsystem.srcs/sources_1/new/main.v2
548@Z8-251h px� 
�
!system %s call '%s' not supported38048*oasys2
task2
finish2a
]D:/Projects/SoftwareDesign/fpga/ADCtoDACRLPsystem/ADCtoDACRLPsystem.srcs/sources_1/new/main.v2
558@Z8-11581h px� 
�
module '%s' not found439*oasys2
radar_processing2a
]D:/Projects/SoftwareDesign/fpga/ADCtoDACRLPsystem/ADCtoDACRLPsystem.srcs/sources_1/new/main.v2
98@Z8-439h px� 
�
!failed synthesizing module '%s'%s4496*oasys2
radar_processing_tb2
 2a
]D:/Projects/SoftwareDesign/fpga/ADCtoDACRLPsystem/ADCtoDACRLPsystem.srcs/sources_1/new/main.v2
18@Z8-6156h px� 
�
%s*synth2v
tFinished Synthesize : Time (s): cpu = 00:00:07 ; elapsed = 00:00:07 . Memory (MB): peak = 1115.887 ; gain = 473.875
h px� 
C
Releasing license: %s
83*common2
	SynthesisZ17-83h px� 
~
G%s Infos, %s Warnings, %s Critical Warnings and %s Errors encountered.
28*	vivadotcl2
162
32
02
3Z4-41h px� 
<

%s failed
30*	vivadotcl2
synth_designZ4-43h px� 
N
Command failed: %s
69*common2
Vivado Synthesis failedZ17-69h px� 
\
Exiting %s at %s...
206*common2
Vivado2
Thu Feb 20 23:37:01 2025Z17-206h px� 


End Record