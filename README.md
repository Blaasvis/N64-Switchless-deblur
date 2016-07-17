# N64-Switchless-deblur

This MPLabX project for a pic12f629, the programming only support common annode led.<br><br>

pin configuration: [PIF NUS / CPU]<br>
                              ,------_-----.<br>
    Vcc/3.3V [p1 N64RGB]      |1          8| Vss/GND [p2 N64RGB] <br>
    Reset out [PIF-NUS Pad 27]|2  GP5 GP0 7| LED-color 0 out (red)<br>
    RGB deBlur [Altera P100]  |3  GP4 GP1 6| LED-color 1 out (green) <br>
    GND                       |4  GP3 GP2 5| Reset in [PIF-NUS Pad 27]<br>
                              `------------'<br>
