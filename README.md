[Check out other Blueprint projects!](https://blueprint.hackclub.com/explore)
# PicoPad
A simple macropad with a screen, controlled by a Raspberry Pi Pico microcontroller. Made for Hack Club Blueprint!

The reason I built it is because I am really new to microcontrollers and electronics overall, and I thought this would be a fun, simple(but not too simple) project to build. Also, this was a handy upgrade for my setup, because I use creative applications often, and those have a lot of weird shortcuts that I can simply map to one key now!
# What does it have?
- keys(epic)
- Custom firmware written in C++, using the Arduino framework and keyboard library
- Custom housing made in Fusion 360
- 1.8inch 128x160 SPI screen(ST7735 driver)
- Displays keys that are currently pressed(I just realized this is really useless)
# How to build one for yourself!

Clone the repo, then open the [code_with_pio_config](code_with_pio_config) folder in VSCode with the PlatformIO extension installed!

Wait for it to download necessary files, modify the variables according to your wiring (adjust pin numbers, or edit the bindings), plug in the pico and then hit the vertical arrow at the bottom of your window to upload the code!

Grab the .step file from the [CAD](cad) folder and slice it with your favorite slicer, then print it. (It doesn't have to be super sturdy, I used 5% gyroid infill with 2 walls)

Assemble the screen holder and the key housing part by gluing them together(there is a small little bump on one side of the screen holder part that has an insert for it on the key housing, make sure that is aligned!).

Solder the connections (place the switches in the case, and then solder the wires onto them), and mount the pico and the screen using something (I just glue gunned most of it, the design doesn't have a proper way to mount, I couldn't figure out something that would not affect the outside of the macropad), then slide the bottom part into the key housing.

Plug in your macropad and enjoy!



# The original idea
I wanted to make a custom PCB with a custom RP2040(the Pico runs on this) - based devboard for the macropad, and I tried, but it was really challenging, so I decided to scrap it, but my attempt is included in the repo in the [pcb_attempt](pcb_attempt) folder. 

A slider module was planned as well, but I couldn't implement volume control(that would have been the purpose of it) without requiring additional software on the PC, so that is not on the final version as well.
# Resources used 
- [Inspiration for the project and wiring of the switches](https://www.hackster.io/1NextPCB/how-to-build-a-pico-macro-pad-3638e6)
- [Guide for the PCB](https://www.youtube.com/watch?v=RNH-CL8GrF8)
- AI for some help(wiring up the screen, fixing floating inputs)(about 90% of the firmware was written by me, the drawing on the screen, the input handling was done by me)
# Some pics!
![The macropad in its full beauty](https://github.com/user-attachments/assets/417ac4e1-91de-4ea7-b627-157b55a4f8df)
![Screenshot of the 3D model](https://github.com/user-attachments/assets/65dd73c0-0b47-42a3-9797-24c999b1a190)
![Wiring diagram](https://github.com/user-attachments/assets/080157df-233e-455e-b600-af16053615fa)
