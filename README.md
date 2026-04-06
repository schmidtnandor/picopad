# PicoPad
A simple macropad with an ST7735 screen, controled by a Raspberry Pi Pico microcontroller.
The reason I built it is because I am really new to microcontrollers and electronics overall, and I thought this would be a fun, simple(but not too simple) project to build.
# What does it have?
- keys(epic)
- Custom firmware written in C++, using the Arduino framework and keyboard library
- Custom housing made in Fusion 360
- ST7735 display
- Displays keys that are currently pressed

# The original idea
I wanted to make a custom PCB with a custom RP2040(the Pico runs on this) - based devboard for the macropad, and I tried, but it was really challenging, and I was running low on time, so I decided to scrap it, but my attempt is included in the repo in the pcb_attempt folder. Also a slider would have been on it, but I couldn't implement volume control(that would have been the purpose of it) without requiring additional software on the PC, so that is not on the final version as well.
# Resources used 
- [Inspiration for the project and wiring of the switches](https://www.hackster.io/1NextPCB/how-to-build-a-pico-macro-pad-3638e6)
- [Guide for the PCB](https://www.youtube.com/watch?v=RNH-CL8GrF8)
- AI for some help(wiring up the screen, fixing floating inputs)(about 90% of the firmware was written by me, the drawing on the screen, the input handling was done by me)
# Gallery
![1000018659](https://github.com/user-attachments/assets/417ac4e1-91de-4ea7-b627-157b55a4f8df)
![1000018666](https://github.com/user-attachments/assets/65dd73c0-0b47-42a3-9797-24c999b1a190)

